#include "invertedIndex.h"
#include <stdio.h>
#include "treeFunc.h"
#include <stdlib.h>
#include <string.h>

void test(InvertedIndexBST tree){
}

InvertedIndexBST createNewTree(void){
    return NULL;
}




FileList createNewFileNode(char *filename){
    FileList node = malloc(sizeof(*node));

    char *name = malloc(sizeof(char)*100);
    strcpy(name, filename);

    node->filename = name;
    node->tf = 1;
    //printf("%lf\n", node->tf);
    node->next = NULL;
    return node;
}


InvertedIndexBST createNewNode(char *word, char *filename){
    InvertedIndexBST node = malloc(sizeof(*node));

    char *letter = malloc(sizeof(char)*100);
    strcpy(letter, word);

    //printf("%s\n", letter);
    node->word = letter;
    node->right = NULL;
    node->left = NULL;
    node->fileList = createNewFileNode(filename);
    return node;
}

//if its str1 is bigger than str2 == 1
//if its str2 is bigger than str1 == -1
int alphabeticalOrder(char *str1, char *str2){
    int i = 0;
    if(strcmp(str1, str2) == 0){
        return 0;
    }
    while(str1[i] == str2[i]){
        i++;
    }
    if(str1[i] > str2[i]){
        return 1;
    } else {
        return -1;
    }
}


//recursive bubble sort
FileList swap(FileList a, FileList b){
    a->next = b->next;
    b->next = a;
    return b;
}

FileList ordering(FileList list){
    if(list == NULL){
        return list;
    }
    if(list->next != NULL && alphabeticalOrder(list->filename, list->next->filename) == 1){
        list = swap(list, list->next);
    }
    list->next = ordering(list->next);

    if(list->next != NULL && alphabeticalOrder(list->filename, list->next->filename) == 1){
        list = swap(list, list->next);
        list->next = ordering(list->next);
    }
    return list;

}


FileList addnewfilelist(FileList list, char *filename){

    if(list == NULL){
        return createNewFileNode(filename);
    }

    if(strcmp(list->filename, filename) == 0){
        list->tf++;
        return list;
    }

    list->next = addnewfilelist(list->next, filename);

    //ordering the boi
    list = ordering(list);

    return list;
}


//fucntion derived off the lab 3 example
InvertedIndexBST addnew(InvertedIndexBST tree, char *data, char* filename){

    if(tree == NULL){
        return createNewNode(data, filename);

    } else {
        int var = alphabeticalOrder(tree->word, data);

        if (var == 0){
            tree->fileList = addnewfilelist(tree->fileList, filename);
        } else if(var == -1){
            tree->right = addnew(tree->right, data, filename);
        } else {
            tree->left = addnew(tree->left, data, filename);
        }
    }
    return tree;
}

//function below used from the lab 3 examples
void printlist(FileList link, FILE *fp){
    if(link == NULL){
        printf("\n");
        return;
    }
    printf("%s ", link->filename);
    printlist(link->next, fp);
}

//function below used from the lab 3 examples
void showNode(InvertedIndexBST tree, FILE *fp){
    if(tree == NULL){
        return;
    }
    printf("%s ", tree->word);

    //recursive print of the filelist

}


//count all nodes

InvertedIndexBST nodefind(InvertedIndexBST tree, char *word){
    if(tree == NULL || strcmp(tree->word, word) == 0){
        return tree;
    } else {
        if(alphabeticalOrder(tree->word, word) == -1){
            return nodefind(tree->right, word);
        } else {
            return nodefind(tree->left, word);
        }
    }
}


int wordcount(InvertedIndexBST tree, char *document){
    if(tree == NULL){
        return 0;
    } else {
        return wordcount(tree->left, document) + wordcount(tree->right, document);
    }
    return 0;
}

TfIdfList addnewtfNode(char* filename, double tf){
    TfIdfList node = malloc(sizeof(*node));

    char *name = malloc(sizeof(char)*100);
    strcpy(name, filename);

    node->filename = name;
    node->tfidf_sum = tf;
    node->next = NULL;
    return node;
}


TfIdfList addtolist(TfIdfList list, char *filename, double tf){
    if(list == NULL){
        return addnewtfNode(filename, tf);
    }
    list->next = addtolist(list->next, filename, tf);

    return list;
}



double scanforallwords(InvertedIndexBST tree, char * filename){
    double count = 0;
    if(tree == NULL){
        return count;
    } else {
        //scan section
        FileList ref = tree->fileList;

        while(ref != NULL){
            if(strcmp(ref->filename, filename) == 0){
                count = count + ref->tf;
            }
            ref=ref->next;
        }

        count += scanforallwords(tree->left, filename);
        count += scanforallwords(tree->right, filename);
        return count;
    }
}


TfIdfList swaptf(TfIdfList a, TfIdfList b){
    a->next = b->next;
    b->next = a;
    return b;
}

TfIdfList orderingtf(TfIdfList list){
    if(list == NULL){
        return list;
    }
    if(list->next != NULL && list->tfidf_sum < list->next->tfidf_sum){
        list = swaptf(list, list->next);
    }
    list->next = orderingtf(list->next);

    if(list->next != NULL && list->tfidf_sum < list->next->tfidf_sum){
        list = swaptf(list, list->next);
        list->next = orderingtf(list->next);
    }
    return list;

}


int findinlist(TfIdfList list, char *word){
    if(list == NULL){
        return 0;
    } else {
        if(strcmp(list->filename, word) == 0){
            return 1;
        }
        return findinlist(list->next, word);
    }
}


TfIdfList editlist(TfIdfList list, char * filename, double value){
    if(list == NULL){
        return list;
    }
    if(strcmp(list->filename, filename) == 0){
        list->tfidf_sum = list->tfidf_sum + value;
    }
    list->next = editlist(list->next, filename, value);

    return list;
}
