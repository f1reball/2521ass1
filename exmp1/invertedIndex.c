#include "invertedIndex.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char * normaliseWord(char *str){

    //first get length of the string
    //then we filter the string by removing each letter
    //we want it fast so if we can scan the string once its then gonna be better


//generates the length of the string
    int length = strlen(str);
    int i = 0;
    printf("%d\n", length);


//loops through string and replaces position with lower case
    while(str[i]){
        str[i] = tolower(str[i]);
        i++;
    }




    return(str);
}

InvertedIndexBST generateInvertedIndex(char *collectionFilename){
    return(0);
}

void printInvertedIndex(InvertedIndexBST tree){
}

TfIdfList calculateTfIdf(InvertedIndexBST tree, char *searchWord , int D){
    return(0);
}

TfIdfList retrieve(InvertedIndexBST tree, char* searchWords[] , int D){
    return(0);
}
