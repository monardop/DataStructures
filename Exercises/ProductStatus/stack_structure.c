#include <stdlib.h>
#include <string.h>

#include "stack_structure.h"

void initialize(dsStack *ps) {
    *ps = NULL;
}

int push(dsStack *sp, void *data, int dataSize) {
    Node *newNode; 
    if((newNode = (Node *)malloc(sizeof(Node))) == NULL || (newNode->data = malloc(dataSize)) == NULL) {
        free(newNode);
        return 0;
    }

    memcpy(newNode->data, data, dataSize);
    newNode->dataSize = dataSize;
    newNode->next = *sp;

    *sp = newNode;

    return 1;
}  

int pull(dsStack *sp, void *container) {
    Node *delNode;

    if(*sp == NULL)
        return FAIL; // list empty

    memcpy(container, (*sp)->data, (*sp)->dataSize);
    
    delNode = *sp;
    *sp = (*sp)->next;

    free(delNode->data);
    free(delNode);

    return 1;
}