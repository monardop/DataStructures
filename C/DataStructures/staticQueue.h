#ifndef STATICQUEUE_H_INCLUDED
#define STATICQUEUE_H_INCLUDED

typedef struct 
{
    int vector[20];
    int front, back;
}Queue;

Queue initialize();
int spaceAvailable(Queue *queue);
void dequeue(Queue *queue);
void enqueue(Queue *queue, int number);


#endif // STATICQUEUE_H_INCLUDED
