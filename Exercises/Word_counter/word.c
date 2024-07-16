#include "word.h"
#include "binary_tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void duplicatedWord(void *data) {
    Word *newWord = (Word *)data;
    newWord->occurrences++;
}

int compareWords(const void *word1, const void *word2) {
    Word *elem1 = (Word *)word1;
    Word *elem2 = (Word *)word2;

    return strcmp(elem1->word, elem2->word);
}

int compareOccurrences(const void *word1, const void *word2) {
    Word *elem1 = (Word *)word1;
    Word *elem2 = (Word *)word2;

    return elem1->occurrences - elem2->occurrences;
}

void printWord(void *data) {
    Word *element = (Word *)data;
    printf("Word: %s. Occurrences: %u ", element->word, element->occurrences);
}

