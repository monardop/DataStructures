#include "StaticQueue.h"

void newQueue(dsQueue* queue)
{
    queue->head=0;  
    queue->rear=0;
    queue->freeSpace= STATIC_ELEMENTS;
}


int isEmpty(dsQueue* queue)
{
    return queue->freeSpace == STATIC_ELEMENTS;
}


int isFull(const dsQueue* queue, unsigned dataSize)
{
    return queue->freeSpace  <= (dataSize + sizeof(unsigned));
}


void clear(dsQueue* queue)
{
    queue->head = queue->rear; 
    queue->freeSpace = STATIC_ELEMENTS;
}


int enqueue(dsQueue* pQueue, const void* data, unsigned dataSize)
{
    unsigned start, end;

    if(pQueue->freeSpace < dataSize + sizeof(unsigned))
        return NO_SPACE;
    
    pQueue->freeSpace -= dataSize + sizeof(unsigned);

    if((start = MIN(sizeof(unsigned), STATIC_ELEMENTS - pQueue->rear)))
        memoryCopy(&dataSize, pQueue->queue + pQueue->rear, start);
    
    if((end = sizeof(unsigned) - start))
        memoryCopy(((char *)&dataSize) + start, pQueue->queue, end);

    pQueue->rear = end? (end): (pQueue->rear + start); 
    if((start = MIN(dataSize, STATIC_ELEMENTS - pQueue->rear)))
        memoryCopy(data,pQueue->queue + pQueue->rear, start);

    if((end = dataSize - start))
        memoryCopy((char *)data + start, pQueue->queue, end);

    pQueue->rear = end? (end):( pQueue->rear + start);   

    return OK;
}


int dequeue(dsQueue* queue, void* buffer, unsigned dataSize)
{   
    unsigned infoSize, start, end;

    if(queue->freeSpace == STATIC_ELEMENTS)
    {
        return EMPTY;
    }
    infoSize = dataSize + sizeof(dataSize);

    if((start = MIN(sizeof(unsigned), STATIC_ELEMENTS - queue->head)))
        memoryCopy(queue->queue + queue->head, &dataSize, start);
    if ((end = sizeof(unsigned) - start))
        memoryCopy(queue->queue, ((char*)&dataSize) + start, end);
    
    queue->head = end? end: queue->head + start;
    queue->freeSpace += sizeof(unsigned) + dataSize;

    
    

   return OK;    
}

int peek(const dsQueue *queue, void *data, unsigned dataSize)
{
    if(queue->freeSpace == STATIC_ELEMENTS)
    {
        return EMPTY;
    }

    return OK;
}