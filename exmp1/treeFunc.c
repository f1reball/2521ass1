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

InvertedIndexBST createNewNode(char *word){
    InvertedIndexBST node = malloc(sizeof(*node));

    char *letter = malloc(sizeof(char)*100);
    strcpy(letter, word);


    //printf("%s\n", letter);
    node->word = letter;
    node->right = NULL;
    node->left = NULL;
    node->fileList = NULL;
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



//fucntion derived off the lab 3 example
InvertedIndexBST addnew(InvertedIndexBST tree, char *data){

    if(tree == NULL){
        return createNewNode(data);
    } else {
        int var = alphabeticalOrder(tree->word, data);

        if (var == 0){

        } else if(var == -1){
            tree->right = addnew(tree->right, data);
        } else {
            tree->left = addnew(tree->left, data);
        }
    }
    return tree;
}

//function below used from the lab 3 examples
void showNode(InvertedIndexBST tree){
    if(tree == NULL){
        return;
    }
    printf("%s\n", tree->word);
}
