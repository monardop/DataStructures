#include <stdio.h>
#include "staticQueue.h"


Queue initialize()
{
    Queue new;
    new.front = 0, new.back = 0;
    return new;
}


int spaceAvailable(Queue *queue)
{
    /*
    I will use a circular queue to optimize the space used 
    in the vector. So, first I check that it is not full, 
    if it is, I check if the start is available. 
    :return: If it returns -1 it is because there is no space available.
    */
    if(queue->back + 1 == 20)
    {
        if(queue->front != 0)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else if (queue->back < queue->front)
    {
        if(queue->back + 1 < queue->front)
        {
            return queue->back + 1;
        }
        else
        {
            return -1;
        }
    }
    else if (queue->back > queue->front)
    {
        return queue->back + 1;
    }
}


void dequeue(Queue *queue)
{

}


void enqueue(Queue *queue, int number)
{

}
