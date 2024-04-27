#include "DynamicQueue.h"

void newQueue(dsQueue *pQueue)
{
   pQueue->head = NULL;
   pQueue->rear = NULL;
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
    while (pQueue->head)
    {
        tNode *del = pQueue->head;
        pQueue->head = del->next;
        free(del->data);
        free(del);
    }
    pQueue->rear = NULL;
}


int enqueue(dsQueue *pQueue, const void *data, unsigned dataSize)
{
    tNode *new;
    
    if ((new = (tNode *)malloc(sizeof(tNode)))== NULL || 
        (new->data = malloc(dataSize))== NULL)
    {
        free(new);
        return NO_SPACE;
    }

    memoryCopy(new->data, data, dataSize);
    new->dataSize = dataSize;
    new->next = NULL;

    if(pQueue->rear)
        pQueue->rear->next = new;
    else  
        pQueue->head = new;
    
    pQueue->rear = new; 

    return OK;
}


int dequeue(dsQueue *pQueue, void *data, unsigned dataSize)
{
    tNode *del = pQueue->head;

    if(!del)
        return EMPTY; 
    
    pQueue->head = del->next;
    memoryCopy(data,del->data, MIN(dataSize, del->dataSize));

    free(del->data);
    free(del);

    if(!pQueue->head)
        pQueue->rear = NULL;

    return OK;
}


int peek(const dsQueue *pQueue, void *data, unsigned dataSize)
{
    if(!pQueue->head)
        return EMPTY;

    memoryCopy(data, pQueue->head->data, MIN(dataSize, pQueue->head->dataSize));
    
    return OK;
}
