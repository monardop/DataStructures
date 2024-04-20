#include "DynamicQueue.h"

void newQueue(dsQueue *pQueue)
{
   *pQueue = NULL;
}


int isEmpty(const dsQueue *pQueue)
{
    return *pQueue == NULL;
}


int isFull(const dsQueue* pQueue, unsigned dataSize)
{
    return 0;
}


void clear(dsQueue *pQueue)
{
    tNode *del = *pQueue;
    *pQueue = del->next;

    while (*pQueue)
    {
        free(del->data);
        free(del);
        del = *pQueue;
        *pQueue = del->next;
    }
}


int enqueue(dsQueue *pQueue, const void *data, unsigned dataSize)
{
    tNode *new, *auxNode;
    
    if ((new = (tNode *)malloc(sizeof(tNode))) == NULL || 
        (new->data = malloc(dataSize)) == NULL)
    {
        free(new);
        return NO_SPACE;
    }


    memoryCopy(new->data, data, dataSize);
    new->dataSize = dataSize;

    auxNode = *pQueue;

    while (auxNode->next)
    {
        auxNode = auxNode->next;
    }

    auxNode->next = new;

    return OK;
}


int dequeue(dsQueue *pQueue, void *data, unsigned dataSize)
{
    tNode *del;

    if(!*pQueue)
        return EMPTY; 

    memoryCopy(data,(*pQueue)->data, MIN(dataSize, (*pQueue)->dataSize));

    del = *pQueue;
    *pQueue = del->next;

    free(del->data);
    free(del);

    return OK;
}


int peek(const dsQueue *pQueue, void *data, unsigned dataSize)
{
    if(!*pQueue)
        return EMPTY;

    memoryCopy(data, (*pQueue)->data, MIN(dataSize, (*pQueue)->dataSize));

    return OK;
}
