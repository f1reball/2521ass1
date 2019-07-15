#include "invertedIndex.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char * normaliseWord(char *str){

//generates the length of the string
    int length = strlen(str);
    int i = 0;
    printf("%d\n", length);

//finds spaces before the word
    int shift_counter = 0;
    while(str[i] == ' '){
        shift_counter++;
        i++;
    }

//moves string to the front of the memory address
    memmove(str, str+shift_counter, length-shift_counter);
    str[length-shift_counter] = 0;

//loops through string and replaces position with lower case
    i = 0;
    while(str[i]){
        str[i] = tolower(str[i]);
        //forces the string to end the trailing spaces
        if(str[i+1] == ' '){
            str[i+1] = '\0';
        }
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
