#include "StaticStack.h"

void newStack(dsStack *sStack) {
    sStack->top = STATIC_ELEMENTS;
}


int isFull(const dsStack *sStack, unsigned dataSize) {
    return  (sStack->top) < dataSize + sizeof(unsigned);
}


int isEmpty(const dsStack *sStack) {
    return sStack->top == STATIC_ELEMENTS;
}


int append(dsStack *sStack, const void* data, unsigned dataSize) {
    if((sStack->top) < dataSize + sizeof(unsigned)) {
        return 0;
    }

    sStack->top -= dataSize;
    char *top = sStack->stack + sStack->top;
    memoryCopy(top, data, dataSize);

    sStack->top -= sizeof(unsigned);
    top -= sizeof(unsigned);
    memoryCopy(top, &dataSize, sizeof(unsigned));

    return OK;
}


int pop(dsStack *sStack, void *data, unsigned dataSize){
    if(sStack->top == STATIC_ELEMENTS) {
        return EMPTY;
    }

    unsigned auxDataSize;
    char *top = sStack->stack + sStack->top;

    memoryCopy(&auxDataSize, top, sizeof(unsigned)); // busco el tam de la info

    top += sizeof(unsigned);
    memoryCopy(data, top, MIN(auxDataSize, dataSize));

    sStack->top += sizeof(unsigned) + dataSize; // muevo el top del stack

    return OK;
}


void clear(dsStack *sStack) {
    sStack->top = STATIC_ELEMENTS;
}


int peek(const dsStack *sStack, void *dest, unsigned dataSize) {
    if(sStack->top == STATIC_ELEMENTS) {
        return EMPTY;
    }

    unsigned element;
    char *top = (char *)(sStack->stack + sStack->top);

    memoryCopy(&element, top, sizeof(unsigned)); // busco el tam de la info

    top += sizeof(unsigned);

    memoryCopy(dest, top, MIN(dataSize, element));

    return OK;
}
