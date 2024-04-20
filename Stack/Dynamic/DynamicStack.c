#include "DynamicStack.h"


void newStack(dsStack *pp){
    *pp = NULL;
}


int isFull(const dsStack *pp, unsigned sizeData){
    return 0;
}


int isEmpty(const dsStack *pp){
    return *pp == NULL;
}


int append(dsStack *pp, const void *data, unsigned dataSize){
    tNode *newNodo = (tNode *)malloc(sizeof(tNode));

    if(!newNodo)
        return EMPTY;
    
    newNodo->data = malloc(dataSize);
    if(!newNodo->data){
        free(newNodo);
        return EMPTY;
    }

    memoryCopy(newNodo->data, data, dataSize);
    newNodo->dataSize = dataSize;
    newNodo->next = *pp;
    *pp = newNodo;
    
    return OK;
}


int pop(dsStack *pp, void *data, unsigned dataSize){
    tNode *delNode = *pp;

    if(!*pp)
        return EMPTY;
    
    *pp = delNode->next;
    memoryCopy(data, delNode->data, MIN(dataSize, delNode->dataSize));
    
    free(delNode->data);
    free(delNode);   
    return OK;
}


void clear(dsStack *pp){
    tNode *delNode = *pp;
    *pp = delNode->next;

    while(*pp){
        free(delNode->data);
        free(delNode);
        delNode = *pp;
        *pp = delNode->next;
    }
}


int peek(const dsStack *pp, void *data, unsigned dataSize){
    if(!*pp)
        return EMPTY;
    
    memoryCopy(data, (*pp)->data, MIN(dataSize, (*pp)->dataSize));
    return OK;
}
