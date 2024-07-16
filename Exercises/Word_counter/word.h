#ifndef WORDS_H
#define WORDS_H

    #include <stdio.h>

    #include "binary_tree.h"

    typedef struct {
        char word[50];
        unsigned occurrences;
    }Word;

    #define BUFFER_LEN  100
    
    int  getWords(FILE *fp, Tree *tp) ;
    void printWord(void *data);
    int  compareOccurrences(const void *word1, const void *word2);


#endif