#include <stdio.h>
#include <stdlib.h>
#include "../Dynamic/DynamicQueue.h"

int test_enqueue(dsQueue *p);
int test_dequeue(dsQueue *p);



int main()
{
    dsQueue testingQueue; 
    newQueue(&testingQueue);
    test_enqueue(&testingQueue);
    test_dequeue(&testingQueue);

    return 0;
}

int test_enqueue(dsQueue *p)
{
    int vec[] = {0,1,2,3,4,5,6,7,8,9};

    for (size_t i = 0; i < 10; i++)
    {
        enqueue(p, vec + i, sizeof(int));
    }
    return 0; 
}

int test_dequeue(dsQueue *p)
{
    int nro;

    for (size_t i = 0; i < 10; i++)
    {
        peek(p, &nro, sizeof(int));
        printf("%d - ", nro);
        dequeue(p, &nro, sizeof(int));
    }
    printf("\n");
    return 0;
}