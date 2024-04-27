#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

    #include <stdlib.h>
    #include "../../Utilities/utilities.h"

    typedef struct
    {
        tNode *head, 
              *rear;
    }dsQueue;

    void newQueue(dsQueue* );
    int isEmpty(const dsQueue*);
    int isFull(const dsQueue*, unsigned);
    void clearQueue(dsQueue*);
    int enqueue(dsQueue*, const void*, unsigned);
    int dequeue(dsQueue*, void*, unsigned);
    int peek(const dsQueue*, void*, unsigned);
    
#endif