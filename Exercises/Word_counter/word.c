#include <stdlib.h>
#include <string.h>

#include "word.h"


void duplicatedWord(void *data) {
    Word *newWord = (Word *)data;
    newWord->occurrences++;
}

int compareWords(const void *word1, const void *word2) {
    Word *elem1 = (Word *)word1;
    Word *elem2 = (Word *)word2;

    return strcmpi(elem1->word, elem2->word);
}

int compareOccurrences(const void *word1, const void *word2) {
    Word *elem1 = (Word *)word1;
    Word *elem2 = (Word *)word2;

    return elem1->occurrences - elem2->occurrences;
}

void printWord(void *data) {
    Word *element = (Word *)data;
    printf("->%s - %u apariciones \n", element->word, element->occurrences);
}

void cleanWord(char *word) {
    char  specialChars[] = ").:;,?!-'\"";
    char *finalPointer   = strchr(word, '\0');
    int   change         = 1;

    while (finalPointer != word && change)
    {
        finalPointer--;
        change = 0;
        for (int i = 0; i < 10; i++)
        {
            if(*finalPointer == specialChars[i]) {
                *finalPointer = '\0';
                change        = 1;
                break;
            }
        }
    }
}

int isNotLetter(char *word) {
    unsigned char special[] = "¿¡!'-,.(";
    int count = 0, needChange = 1;

    while (needChange)
    {
        needChange = 0;
        for(int i = 0; i < 8; i++) {
            if(*word == special[i]) {
                needChange = 1;
                count++;
                break;
            }
        }
        word++;
    }
    return count;
}

int createWord(char *word, unsigned len, Tree *tp) {
    Word newWord;
    int movesFoward;

    newWord.occurrences = 1;

    movesFoward = isNotLetter(word);

    memcpy(newWord.word, word + movesFoward, len - movesFoward);
    cleanWord(newWord.word);
    return newElement(tp, (void *)&newWord, sizeof(Word), compareWords, duplicatedWord);
}

int parceWords(char *sentence, Tree *tp) {
    char *endp, *startp;

    startp = endp = strchr(sentence, '\n');
    *endp = '\0';

    while (startp != sentence){
        startp--;
        if(*startp == ' '){
            if (createWord(startp + 1, endp - startp, tp) != OK) {
                return MEM_ERROR;
            }
            endp = startp;
            *endp = '\0';
        }
    }
    if (createWord(startp, endp - startp, tp) != OK) {
        return MEM_ERROR;
    }
    return OK;
}

int getWords(FILE *fp, Tree *tp) {
    char buffer[BUFFER_LEN];

    while(fgets(buffer, BUFFER_LEN,fp)) {
        if(parceWords(buffer, tp) != OK) {
            return MEM_ERROR;
        }
    }

    return OK;
}
