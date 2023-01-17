#include <stdio.h>
#include <stdlib.h>
#include "staticQueue.h"

int main()
{
    Queue new;
    new = initializeQueue();


    dequeue(&new);
    enqueue(&new, 19);
    enqueue(&new, 1);
    enqueue(&new, 9);
    enqueue(&new, 59);
    enqueue(&new, 79);
    enqueue(&new, 99);
    enqueue(&new, 13);
    enqueue(&new, 11);
    enqueue(&new, 17);
    enqueue(&new, 10);
    enqueue(&new, 1234);
    enqueue(&new, 489);
    enqueue(&new, 1123);
    enqueue(&new, 145);
    enqueue(&new, 1675);

    dequeue(&new);
    dequeue(&new);
    dequeue(&new);
    dequeue(&new);
    dequeue(&new);

    printf("%d in front, %d for back\n", new.front, new.back);

    for(int i = 0; i<new.back; i++)
    {
        printf("%d   ", new.vector[i]);
    }
    printf("\n");

    dequeue(&new);

    return 0;
}
