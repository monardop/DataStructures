#ifndef STATICSTACK_H
#define STATICSTACK_H

    #include "../../Utilities/Utilities.h"

    typedef struct 
    {
        char stack[STATIC_ELEMENTS];
        int top;
    }dsStack;

    void newStack(dsStack *);
    int isFull(const dsStack *, unsigned );
    int isEmpty(const dsStack *);
    int append(dsStack *, const void*, unsigned);
    int pop(dsStack *, void *, unsigned);
    void clear(dsStack *);
    int peek(const dsStack *, void *, unsigned);
    
#endif