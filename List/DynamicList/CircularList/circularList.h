#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

    #include <string.h>
    #include <stdlib.h>

    typedef struct node
    {
        void *info;
        unsigned dataSize;
        struct node *next;
    }tNode;

    typedef tNode *tCircularStackList;

    void newCircularStackList(tCircularStackList *pl);
    int isEmpty(tCircularStackList *pl);
    int stackMode_NewNode(tCircularStackList *, void *, unsigned);
    void emptyList(tCircularStackList *);


#endif