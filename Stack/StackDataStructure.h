#ifndef STACKDATASTRUCTURE_H
#define STACKDATASTRUCTURE_H
    
    #ifdef USE_STATIC_STACK
        #include "Static/StaticStack.h"
    #else
        #include "Dynamic/DynamicStack.h"
    #endif

    void newStack(dsStack *);
    int isFull(const dsStack *, unsigned );
    int isEmpty(const dsStack *);
    int append(dsStack *, const void*, unsigned);
    int pop(dsStack *, void *, unsigned);
    void clear(dsStack *);
    int peek(const dsStack *, void *, unsigned);

#endif// STACKDATASTRUCTURE_H