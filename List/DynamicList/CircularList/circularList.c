#include "circularList.h"

void newCircularStackList(tCircularStackList *pl)
{
    *pl = NULL;
}

int isEmpty(tCircularStackList *pl)
{
    return *pl == NULL;
}

int stackMode_NewNode(tCircularStackList *pl, void *data, unsigned dataSize)
{
    tNode *newNode;

    if((newNode       = (tNode *)malloc(sizeof(tNode))) == NULL ||
       (newNode->info = malloc(dataSize))               == NULL   )
    {
        free(newNode);
        return 0;
    }
    memcpy(newNode->info, data, dataSize);
    newNode->dataSize = dataSize;

    if(*pl == NULL)
    {
        *pl           = newNode;
        newNode->next = newNode; 
        return 1;
    }
    newNode->next = *pl;
    (*pl)->next = newNode;
    *pl = newNode;

    return 1;
}

void emptyList(tCircularStackList *pl)
{
    tNode *delNode;
    while(*pl)
    {

    }

}
