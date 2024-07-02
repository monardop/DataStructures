#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

    #include <stdlib.h>
    #include <string.h>

    #include "utilities.h"

    typedef struct sNode
    {
        void         *data;
        int           dataSize;
        struct sNode *next;
    }tNode;

    typedef tNode* dsList;

    void newList(dsList *list);
    int insertElement(dsList *list, const void *data, const int dataSize);
    void clearList(dsList *list);
    dsList *findElem(dsList *list, const void *data, cmp cmp);
    void mapList(dsList *list, action function);




#endif