#include "DynamicQueue.h"

void newQueue(dsQueue *pQueue)
{
   pQueue->head = NULL;
}


int isEmpty(const dsQueue *pQueue)
{
    return pQueue->head == NULL;
}


int isFull(const dsQueue* pQueue, unsigned dataSize)
{
    return 0;
}


void clearQueue(dsQueue *pQueue)
{
    tNode *del = pQueue->head;
    pQueue->head = del->next;

    while (pQueue->head)
    {
        free(del->data);
        free(del);
        del = pQueue->head;
        pQueue->head = del->next;
    }
}


int enqueue(dsQueue *pQueue, const void *data, unsigned dataSize)
{
    tNode *new;
    
    if ((new = (tNode *)malloc(sizeof(tNode))) == NULL || 
        (new->data = malloc(dataSize)) == NULL)
    {
        free(new);
        return NO_SPACE;
    }

    memoryCopy(new->data, data, dataSize);
    new->dataSize = dataSize;

    pQueue->rear->next = new;
    pQueue->rear = new;

    return OK;
}


int dequeue(dsQueue *pQueue, void *data, unsigned dataSize)
{
    tNode *del;

    if(!pQueue->head)
        return EMPTY; 

    memoryCopy(data,pQueue->head->data, MIN(dataSize, pQueue->head->dataSize));

    del = pQueue->head;
    pQueue->head = del->next;

    free(del->data);
    free(del);

    return OK;
}


int peek(const dsQueue *pQueue, void *data, unsigned dataSize)
{
    if(!pQueue->head)
        return EMPTY;

    memoryCopy(data, pQueue->head->data, MIN(dataSize, pQueue->head->dataSize));
    
    return OK;
}
