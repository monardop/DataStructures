#include "dynamicList.h"

void newList(dsList *pList)
{
    *pList = NULL;
}

int isEmpty(dsList *pList)
{
    return *pList == NULL;
}

void clearList(dsList *plist)
{
    tNode *delNode = *plist;

    while (delNode)
    {
        *plist = delNode->next;
        free(delNode->data);
        free(delNode);
        delNode = *plist;
    }
}

int append(dsList *plist, void *data, unsigned dataSize)
{
    tNode *pointer, *newNode;

    if((newNode = (tNode *)malloc(sizeof(tNode))) == NULL ||
               (newNode->data = malloc(dataSize)) == NULL)
    {
        free(newNode);
        return NO_SPACE;
    }

    memoryCopy(newNode->data, data, dataSize);
    newNode->dataSize = dataSize;
    newNode->next = NULL;

    if (!*plist)
    {
        *plist = newNode;
        newNode->next = NULL;
        return OK;
    }

    pointer = *plist;
    while (pointer->next)
    {
        pointer = pointer->next;
    }

    pointer->next = newNode;

    return OK;
}

int sortedInsert(dsList *plist, void* data, unsigned dataSize, cmp cmp)
{
    tNode *newNode, *pointer;

    if((newNode = (tNode *)malloc(sizeof(tNode))) == NULL ||
               (newNode->data = malloc(dataSize)) == NULL)
    {
        free(newNode);
        return NO_SPACE;
    }

    memoryCopy(newNode->data, data, dataSize);
    newNode->dataSize = dataSize;

    if (!*plist)
    {
        *plist = newNode;
        newNode->next = NULL;
        return OK;
    }

    pointer = *plist;
    while (pointer->next)
    {
        tNode *auxNode = pointer->next;
        if(cmp(pointer->data, data) < 0 && cmp(auxNode->data, data) >= 0)
        {
            newNode->next = auxNode;
            pointer->next = newNode;
            return OK;

        }
        pointer = auxNode;
    }
    pointer->next = newNode;
    newNode->next = NULL;
    return OK;
}

int listLen(dsList *pList)
{
    tNode *pointer = *pList;
    int tam = 0;

    while (pointer)
    {
        tam++;
        pointer = pointer->next;
    }
    return tam;
}

void nodeSwap(tNode *a, tNode *b)
{
    void *auxData;
    unsigned dataSize;

    dataSize = a->dataSize;
    auxData = malloc(dataSize);
    memoryCopy(auxData,a->data,dataSize);

    free(a->data);

    a->data = malloc(b->dataSize);
    a->dataSize = b->dataSize;
    memoryCopy(a->data, b->data, b->dataSize);

    free(b->data);

    b->data = malloc(dataSize);
    b->dataSize = dataSize;
    memoryCopy(b->data, auxData, dataSize);
}

void sortList(dsList *pList, cmp cmp)
{
    tNode *actElement;
    int sizeList, swapped, i;

    sizeList = listLen(pList);
    i = 0;
    swapped = 1;

    if(sizeList < 2) // no need to sort
        return;

    while (i < sizeList - 1 && swapped)
    {
        swapped = 0;
        actElement = *pList;
        tNode *nextNode = actElement->next;
        for(int j = 0; j < sizeList - i - 1; j++)
        {
            if(cmp(actElement->data,nextNode->data) > 0)
            {
                nodeSwap(actElement, nextNode);
                swapped = 1;
            }
            actElement = nextNode;
            nextNode = actElement->next;
        }
        i++;
    }
    
    
}

void printList(dsList *plist, print printFunc)
{
    tNode *auxNode = *plist;
    if(!auxNode)
        return;

    while (auxNode)
    {
        printFunc(auxNode->data);
        auxNode = auxNode->next;
    }
}
