#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

    #include <stdlib.h>
    #include "../../Utilities/utilities.h"

    typedef struct
    {
        tNode *head;
        tNode *rear;
    }dsQueue;

    void newQueue(dsQueue* );
    int isEmpty(const dsQueue*);
    int isFull(const dsQueue*, unsigned);
    void clear(dsQueue*);
    int enqueue(dsQueue*, const void*, unsigned);
    int dequeue(dsQueue*, void*, unsigned);
    int peek(const dsQueue*, void*, unsigned);
    
#endif