#include "bankSimulation.h"

#define MAX_TIME 480 // 8hs


int waitingTime()
{
    int randomNumber = rand() % 3;
    int vec[] = {1,3,5};
    return vec[randomNumber];
}

int nextCustomer()
{
    int randomNumber = rand() % 3;
    int vec[] = {1,5,9};
    return vec[randomNumber];
}

int simulation(dsQueue *queue, int *peopleServed)
{
    int nextPerson, onProcess;
    int minutes = 0, elapsedTime; 

    // first person arrived
    onProcess = waitingTime();
    enqueue(queue, &onProcess, sizeof(int));
    nextPerson = nextCustomer();

    while (minutes < MAX_TIME)
    {
        if(onProcess <= 0)
        {
            dequeue(queue, &onProcess, sizeof(int));
            (*peopleServed)++;
        }
        
        if(nextPerson <= 0)
        {
            nextPerson = waitingTime();
            enqueue(queue, &nextPerson, sizeof(int));
            nextPerson = nextCustomer();
        }

        peek(queue, &onProcess, sizeof(int));
        elapsedTime = MIN(onProcess, nextPerson);
        onProcess -= elapsedTime;
        nextPerson -= elapsedTime;
        minutes += elapsedTime;
    }
    return minutes;
}

void processLog()
{
    dsQueue queue;
    int peopleServed, totalServed, elapsedTime, totalTime; 

    totalServed = 0;
    peopleServed = 0;
    totalTime = 0;

    for(int i = 0; i < 5; i++)
    {
        elapsedTime = simulation(&queue, &peopleServed);
        printf("%d people were treated in %d minutes", peopleServed, elapsedTime);
        clearQueue(&queue);
        totalServed += peopleServed;
        peopleServed = 0;
        totalTime += elapsedTime;
    }

    printf("%d people were treated in %d minutes", totalServed, totalTime);

}



