#ifndef QUEUEDATASTRUCTURE_H
#define QUEUEDATASTRUCTURE_H

    #ifdef USE_STATIC_QUEUE
        #include "Static/StaticQueue.h"
    #else   
        #include "Dynamic/DynamicQueue.h"
    #endif

    void newQueue(dsQueue* );
    int isEmpty(const dsQueue*);
    int isFull(const dsQueue*, unsigned);
    void clear(dsQueue*);
    int enqueue(dsQueue*, const void*, unsigned);
    int dequeue(dsQueue*, void*, unsigned);
    int peek(const dsQueue*, void*, unsigned);

#endif// QUEUEDATASTRUCTURE_H