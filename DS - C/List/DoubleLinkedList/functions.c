#include <stdlib.h>

#include "doubleLinkedList.h"


void newList(dsDLL *dll)
{
    *dll = NULL;
}

bool isEmpty(dsDLL *dll)
{
    return *dll == NULL;
}

int append(dsDLL *dll, void *data, unsigned size)
{
    tNodo *new;

    if( (new = (tNodo *)malloc(sizeof(tNodo))) == NULL || 
        (new->data = malloc(size)) == NULL )
    {
        free(new);
        return NO_SPACE;
    }

    memoryCopy(new->data, data, size);
    new->dataSize = size;

    if (*dll == NULL)
    {
        *dll = new;
        new->previous = NULL;
        new->next = NULL;
        return OK;
    }
    
    while ((*dll)->next)
    {
        *dll = (*dll)->next;
    }

    (*dll)->next = new;
    new->previous = *dll;
    new->next = NULL;

    return OK;
}

int sortedInsert(dsDLL *dll, void *data, unsigned size, cmp cmp)
{
    tNodo *new;

    if( (new = (tNodo *)malloc(sizeof(tNodo))) == NULL || 
        (new->data = malloc(size)) == NULL )
    {
        free(new);
        return NO_SPACE;
    }

    memoryCopy(new->data, data, size);
    new->dataSize = size;

    if (*dll == NULL)
    {
        *dll = new;
        new->previous = NULL;
        new->next = NULL;
        return OK;
    }

    while ((*dll)->next && cmp(data, (*dll)->data) > 0)
    {
        *dll = (*dll)->next;
    }

    while ((*dll)->previous && cmp(data, (*dll)->data) < 0)
    {
        *dll = (*dll)->previous;
    }

    new->next = (*dll)->next;
    (*dll)->next = new;
    new->previous = *dll;

    return OK;
}

void printDLL(dsDLL *dll, print printFunc)
{
    if(*dll == NULL)
    {
        return;
    }

    while ((*dll)->previous) 
    {
        *dll = (*dll)->previous;
    }

    while (*dll)
    {
        printFunc((*dll)->data);
        *dll = (*dll)->next;
    }
    
}

tNodo* search(dsDLL *dll, void *data, unsigned size, cmp cmp)
{
    
    while ((*dll)->next && cmp(data, (*dll)->data) > 0)
    {
        *dll = (*dll)->next;
    }

    while ((*dll)->previous && cmp(data, (*dll)->data) < 0)
    {
        *dll = (*dll)->previous;
    }

    if(cmp(data, (*dll)->data) == 0)
    {
        return *dll;
    }
    else
    {
        return NULL;
    }
}