#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

    #include "utilities.h"

    typedef struct sNode
    {
        void         *data;
        int           dataSize;
        struct sNode *next;
    }tNode;

    typedef tNode* dsList;

    void    newList(dsList *list);
    int     insertElement(dsList *list, const void *data, const int dataSize);
    void    clearList(dsList *list);
    dsList *nextElemCheck(dsList *list, const void *data, cmp cmp);
    dsList *nextElem(dsList *list);
    void    mapList(dsList *list, action function);
    
#endif