#ifndef STATICQUEUE_H_INCLUDED
#define STATICQUEUE_H_INCLUDED

typedef struct 
{
    int vector[20];
    int front, back;
}Queue;

Queue initialize();
void dequeue();
void enqueue();


#endif // STATICQUEUE_H_INCLUDED
