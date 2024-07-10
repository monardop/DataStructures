#include <stdlib.h>
#include <string.h>

#include "list_interface.h"
#include "utilities.h"
 
 
void newList(dsList *pl) {
    *pl = NULL;
}

int  emptyList(dsList *pl) {
    return *pl == NULL;
}

int sortedInsertion(dsList *pl, void *data, unsigned dataSize, cmp cmp) {
    tNode *newNode, *aux;

    if((newNode = (tNode *)malloc(sizeof(tNode))) == NULL || (newNode->data = malloc(dataSize)) == NULL) {
        free(newNode);
        return MEM_ERROR;
    }
    memcpy(newNode->data, data, dataSize);
    newNode->dataSize = dataSize;
    
    
    while(*pl) {
        if(cmp(data, (*pl)->data) < 0) {
            aux = *pl;
            *pl = newNode;
            newNode->next = aux;
            return OK;
        }
        pl = &(*pl)->next;
    }
     
    *pl = newNode;
    newNode->next = NULL;
    return OK;
}

void delList(dsList *pl) {
    tNode *delNode;

    while (*pl)
    {
        delNode = *pl;
        *pl = delNode->next;
        free(delNode->data);
        free(delNode);
    }
    *pl = NULL;
}

int find(dsList *pl, void *key, cmp cmp) {
    
    while(*pl) {
        if(cmp(key, (*pl)->data) == 0)
            return 1;
        pl = &(*pl)->next;
    }
    
    return 0;
}

void returnNdel(dsList *pl, void *container) {
    tNode *delNode = *pl;

    *pl = delNode->next;
    memcpy(container, delNode->data, delNode->dataSize);
    free(delNode->data);
    free(delNode);
}

void simplifyList(dsList *pl, cmp cmp, reduceFunction fuse) {
    tNode *aux;

    aux = (*pl)->next;
    while(*pl && aux) {
        if(cmp(aux->data, (*pl)->data) == 0) {
            fuse((*pl)->data, aux->data);
            (*pl)->next = aux->next;
            free(aux->data);
            free(aux);
        }
        else{
            pl = &(*pl)->next;
        }
        aux = (*pl)->next;
    }

}
