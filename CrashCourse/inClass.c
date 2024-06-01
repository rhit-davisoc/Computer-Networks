#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void function1(int n){
    printf("In function1, n=%d\n", n);
    n += 30;
}

void function2(int* n){
    printf("In function2, *n=%d\n", *n);
    *n += 100;
}

typedef struct{
    int length;
    char* word;
} Word_tracker;

int main(int argc, char* argv[]) {

    // Words and Files

    if(argc < 2){
        printf("Usage: ./program filename\n");
        return 1;
    }

    char* filename = argv[1];

    FILE* fp = fopen(filename, "r"); // "w" - write, "b" - binary mode, ex. "rb" read in binary (e.x. MP3, anything not .txt)

    if(fp == NULL){
        printf("File %s not found!\n", filename);
        return 1;
    }

    char curWord[100];
    Word_tracker longestWord;
    longestWord.length = 0;
    longestWord.word = NULL;

    while(fscanf(fp, "%s", curWord) == 1){ // Returns 1 if there's a string, not 1 if its EOF
        int curLength = strlen(curWord);

        if(curLength > longestWord.length){
            if(longestWord.word != NULL)
                free(longestWord.word);
            longestWord.length = curLength;
            longestWord.word = (char*) malloc(curLength*sizeof(char));
            strncpy(longestWord.word, curWord, curLength);
        }
    }

    printf("The longest word: \"%s\" is of size %d\n", longestWord.word, longestWord.length);

    fclose(fp); // Close file

    if(longestWord.word != NULL)
        free(longestWord.word);

    return 0;



    // Array Arithmetic
    // int a = 10;

    // int* p = &a;

    // int b[10] = {1,2,3,4,5,6,7,8,9,10};
    // int* bPtr = b;

    // printf("b[0] = %d; b[1] = %d; *bPtr = %d; *(bPtr + 1)=%d\n", b[0], b[1], *bPtr, *(bPtr + 1));


    // Some Fun with Pointers
    // printf("a = %d; *p = %d; p = %p; &a = %p\n", a, *p, p, &a);

    // function1(a);
    // function1(*p);
    // printf("a = %d; *p = %d; p = %p; &a = %p\n", a, *p, p, &a);

    // function2(p);
    // printf("a = %d; *p = %d; p = %p; &a = %p\n", a, *p, p, &a);
}
