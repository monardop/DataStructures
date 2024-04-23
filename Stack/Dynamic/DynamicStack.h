#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

    #include <stdlib.h>
    #include "../../Utilities/Utilities.h"
    
    typedef tNode *dsStack;
    
    void newStack(dsStack *);
    int isFull(const dsStack *, unsigned );
    int isEmpty(const dsStack *);
    int append(dsStack *, const void*, unsigned);
    int pop(dsStack *, void *, unsigned);
    void clearStack(dsStack *);
    int peek(const dsStack *, void *, unsigned);
    
#endif 