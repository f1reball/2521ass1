#include "invertedIndex.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "treeFunc.h"
#include <stdlib.h>

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


void printInvertedIndex(InvertedIndexBST tree){
    if (tree == NULL){
        return;
    } else {
        printInvertedIndex(tree->left);
        showNode(tree);
        printlist(tree->fileList);
        printInvertedIndex(tree->right);
    }
}

TfIdfList calculateTfIdf(InvertedIndexBST tree, char *searchWord , int D){
    return(0);
}

TfIdfList retrieve(InvertedIndexBST tree, char* searchWords[] , int D){
    return(0);
}
