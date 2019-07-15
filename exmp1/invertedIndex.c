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
    int shift_counter = 0;

//finds spaces before the word
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
//we should make the BST self balancing to allow for faster recollection


//for this, we need to include a couple of extra functions for a cool af AVL tree WEOWWW


//todo:
// AVL INSERT
// AVL DELETE
// AVL CHECK HEIGHT
// AVL PIVOT NODE DEFINITION

//we need to open the collection file to see what we need to open

// WE NEED A FUNCTION BLOCK FOR TREE COMMANDS


InvertedIndexBST T = createNewTree();

FILE * fp;
fp = fopen(collectionFilename, "r");
char name[100];
while(fscanf(fp, "%s", name) != EOF){

    printf("\n****%s****\n", name);
    //inside the double loop we now read each word and print it output
    FILE * fp;
    fp = fopen(name, "r");
    char word[100];
    while(fscanf(fp, "%s", word) != EOF){

        //normaliseWord

        //#########################################

        if(T == NULL){
            T = createNewNode(word);
        }

        /*
        T->word = "HELLO";
        test(T);
        if (T == NULL){
            printf("YES\n");
        } else {
            printf("%s\n", T->word);
        }

        printf("%s\n", normaliseWord(word));
        */
    }

}
fclose(fp);

// EACH TIME WE FOLLOW THIS LOOP STRUCTURE:

// 1. FIND WHAT TO ADD AND SCAN IT IN
// 2. PUT IT THROUGH THE FILTER
// 3. ADD TO THE AVL TREE
// 4. CHECK IF CONDITIONS ARE BROKEN
// 5. ROTATE IF NEEDED
// 6. REPEAT

printf("%s\n", T->word);

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
