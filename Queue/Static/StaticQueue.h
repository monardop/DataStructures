#ifndef STATICQUEUE_H
#define STATICQUEUE_H

    #include "../../Utilities/utilities.h"

    typedef struct
    {
        char queue[STATIC_ELEMENTS];
        unsigned head, rear, freeSpace;
    }dsQueue;

    void newQueue(dsQueue* );
    int isEmpty(const dsQueue*);
    int isFull(const dsQueue*, unsigned);
    void clear(dsQueue*);
    int enqueue(dsQueue*, const void*, unsigned);
    int dequeue(dsQueue*, void*, unsigned);
    int peek(const dsQueue*, void*, unsigned);
    
#endif // COLAESTATICA_H