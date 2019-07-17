#include "invertedIndex.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "treeFunc.h"
#include <stdlib.h>
#include <math.h>

char * normaliseWord(char *str){

//intialise vars and generate the length of the input string
    int length = strlen(str);
    int i = 0;

//loops through string and replaces position with lower case
    i = 0;
    while(str[i]){
        str[i] = tolower(str[i]);
        i++;
    }

//finally we strip the last letter if its not allowed
    length = strlen(str) -1;
    if(str[length] == '.' || str[length] == ',' || str[length] == ';' ||str[length] == '?'){
        str[length] = '\0';
    }

//returns edited string :D
    return(str);
}



InvertedIndexBST generateInvertedIndex(char *collectionFilename){

//make a tree
InvertedIndexBST L = createNewTree();

//hunt down that file name thing

FILE * ps;
ps = fopen("collection.txt", "r");
char filename[(sizeof(char)*100)];
while(fscanf(ps, "%s", filename) != EOF){

        FILE * fp;
        char word[(sizeof(char)*100)];
        fp = fopen(filename, "r");
        while(fscanf(fp, "%s", word) != EOF){

            L = addnew(L, normaliseWord(word), filename);

        }
        fclose(fp);
    }
    fclose(ps);
return L;
}


void printcontiner(InvertedIndexBST tree, FILE *fp){
        if (tree == NULL){
            return;
        } else {
            printInvertedIndex(tree->left);

            showNode(tree, fp);
            printlist(tree->fileList, fp);

            printInvertedIndex(tree->right);

        }
}

void printout(InvertedIndexBST tree, FILE *fp){
    if(tree != NULL){
        printout(tree->left, fp);
        fprintf(fp, "%s ", tree->word);
        while(tree->fileList != NULL){
            fprintf(fp, "%s ", tree->fileList->filename);
            tree->fileList = tree->fileList->next;
        }

        fprintf(fp, "%s", "\n");
        printout(tree->right, fp);
    }
}


void printInvertedIndex(InvertedIndexBST tree){
    FILE *fp;
    fp = fopen("invertedIndex.txt", "w+");
    printout(tree, fp);
    fclose(fp);
}



TfIdfList calculateTfIdf(InvertedIndexBST tree, char *searchWord , int D){


    TfIdfList list = NULL;



    double doc_count = 0;
    //double tf = 0;
    FileList ref = (nodefind(tree, searchWord))->fileList;

    FileList dub = ref;

    while(dub != NULL){
        doc_count++;
        dub = dub->next;
    }

    while(ref != NULL){
        double wordcount = scanforallwords(tree, ref->filename);

        double bigtf = (ref->tf / wordcount);
        double p = (D / doc_count);
        double logo = log10(p);
        bigtf = logo * bigtf;
        list = addtolist(list, ref->filename, bigtf);
        ref = ref->next;
    }


    return orderingtf(list);

    //we need to get:
    //first we need to return the files that have the word in it.
    //tf(t, d) = (frequency of term t in d) / (number of words in d)
    //the relative tf

}

TfIdfList retrieve(InvertedIndexBST tree, char* searchWords[] , int D){

    TfIdfList list = NULL;

    int i = 0;
    while(searchWords[i] != NULL){
        if(i == 0){
            list = calculateTfIdf(tree, searchWords[i], D);
        } else {

            for(TfIdfList addList=calculateTfIdf(tree, searchWords[i], D) ; addList != NULL; addList=addList->next){
                // now we go through the main list to see if we can add it or if we need to add  a new node
                int x = findinlist(list, addList->filename);
                if(x == 0){
                    list = addtolist(list, addList->filename, addList->tfidf_sum);
                } else {
                    list = editlist(list, addList->filename, addList->tfidf_sum);
                }
            }
            //for every point in the addlist, we want to add it to the list.
        }

        i++;
    }



    return orderingtf(list);
}
