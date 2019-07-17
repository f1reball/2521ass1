#include "invertedIndex.h"
#include <stdio.h>
#include "treeFunc.h"
#include <stdlib.h>
#include <string.h>

void test(InvertedIndexBST tree){
    printf("no\n");
}

InvertedIndexBST createNewTree(void){
    return NULL;
}


FileList createNewFileNode(char *filename){
    FileList node = malloc(sizeof(*node));

    char *name = malloc(sizeof(char)*100);
    strcpy(name, filename);

    node->filename = name;
    //node->tf = NULL;
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
void printlist(FileList link){
    if(link == NULL){
        printf("\n");
        return;
    }
    printf("%s ", link->filename);
    printlist(link->next);
}

//function below used from the lab 3 examples
void showNode(InvertedIndexBST tree){
    if(tree == NULL){
        return;
    }
    printf("%s ", tree->word);

    //recursive print of the filelist

}
