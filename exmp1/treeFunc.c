#include "invertedIndex.h"
#include <stdio.h>
#include "treeFunc.h"
#include <stdlib.h>

void test(InvertedIndexBST tree){
    printf("no\n");
}

InvertedIndexBST createNewTree(void){
    return NULL;
}

InvertedIndexBST createNewNode(char *word){
    InvertedIndexBST node = malloc(sizeof(*node));
    node->word = word;
    return node;
}

//TODO Functions
/*
    IS IN TREE
    HEIGHT OF TREE
    DELETE NODE
    ROTATE RIGHT
    ROTATE LEFT
    DOUBLE ROTATE LEFT
    DOUBLE ROTATE RIGHT
*/
