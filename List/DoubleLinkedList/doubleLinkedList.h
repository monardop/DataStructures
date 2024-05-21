#ifndef DOUBLELINKEDLIST_H
    #define DOUBLELINKEDLIST_H

    #include "../../Utilities/utilities.h"

    typedef struct sNode{
        void *data;
        unsigned dataSize;
        struct sNode *previous, *next;
    }tNodo;

    typedef tNodo *dsDLL;

    void newList(dsDLL *dll);
    bool isEmpty(dsDLL *dll);
    int append(dsDLL *dll, void *data, unsigned size);
    int sortedInsert(dsDLL *dll, void *data, unsigned size, cmp cmp);
    void printDLL(dsDLL *dll, print printFunc);
    tNodo* search(dsDLL *dll, void *data, unsigned size, cmp cmp);

#endif // DOUBLELINKEDLIST_H_INCLUDED
