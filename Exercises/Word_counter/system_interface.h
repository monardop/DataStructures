#ifndef SYSTEM_INTERFACE_H
#define SYSTEM_INTERFACE_H
    #include "binary_tree.h"

    #define BOOK_FILE "quijote-es.txt"

    int  menu();
    void readFile(Tree *tp);
    void showWords(Tree *tp);
    void fewerOccurrences(Tree *tp);
    void mostOccurrences(Tree *tp);
    void exitProgram(Tree *tp);

#endif