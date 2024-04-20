#ifndef STATICSTACK_H
#define STATICSTACK_H

    #include "../../Utilities/Utilities.h"

    typedef struct 
    {
        char stack[STATIC_ELEMENTS];
        int top;
    }dsStack;

#endif