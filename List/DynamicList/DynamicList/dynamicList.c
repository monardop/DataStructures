#include "dynamicList.h"

void newList(dsList *pList)
{
    *pList = NULL;
}

bool isEmpty(dsList *pList)
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

void delNode(dsList *pList, tNode *del)
{
    tNode *pointer = *pList;

    if (pointer == del)
    {
        *pList = pointer->next;
        free(pointer->data);
        free(pointer);
        return;
    }

    while(pointer->next != del)
    {
        pointer = pointer->next;
    }
    pointer->next = del->next;
    free(del->data);
    free(del);
}

int removeFirst(dsList *plist, void *data, unsigned dataSize)
{
    tNode *pointer = *plist;

    while (pointer)
    {
        if(pointer->dataSize == dataSize)
        {
            if (memoryCompare(data, pointer->data, dataSize) )
            {
                delNode(plist, pointer);
                return OK;
            }
        }
        pointer = pointer->next;
    }

    return 0;
}

int removeAllOccurrences(dsList *plist, void *data, unsigned dataSize)
{
    tNode *pointer = *plist;
    int occurrences = 0;

    while (pointer)
    {
        if(pointer->dataSize == dataSize)
        {
            if (memoryCompare(data, pointer->data, dataSize) )
            {
                delNode(plist, pointer);
                occurrences++;
            }
        }
        pointer = pointer->next;
    }

    return occurrences;
}

int removeLastOccurrence(dsList *plist, void *data, unsigned dataSize)
{
    tNode *pointer = *plist;
    tNode *del = NULL;

    while (pointer)
    {
        if(pointer->dataSize == dataSize)
        {
            if (memoryCompare(data, pointer->data, dataSize) )
            {
                del = pointer;
            }
        }
        pointer = pointer->next;
    }

    if(del)
    {
        delNode(plist, del);
    }

    return 0;
}

int removeIndex(dsList *pList, int index)
{
    tNode *pointer = *pList;
    int i = 0;

    while (pointer && i != index)
    {
        pointer = pointer->next;
        i++;
    }

    if(pointer && index == i)
    {
        delNode(pList, pointer);
    }
    return 0;
}

void removeDuplicates()
{

}

int indexedInsert(dsList *pll, void *data, unsigned dataSize, int pos)
{
    /*
        *if list[pos] exists => list[pos]=newElem,the previous list[pos] -> list[pos+1]
        *if len(list) = n and pos > n => error
    */
    int listSize;
    tNode *newElement, *auxPointer;
    

    listSize = listLen(pll);
    if(listSize == pos)
    {
        append(pll,data,dataSize);
        return OK;
    }else if (listSize < pos)
    {
        return ERROR;
    }
    
    if((newElement = (tNode *)malloc(sizeof(tNode)))== NULL ||
        (newElement->data = malloc(dataSize))== NULL)
    {
        free(newElement);
        return NO_SPACE;
    }

    memoryCopy(newElement->data,data, dataSize);
    newElement->dataSize = dataSize;

    auxPointer = *pll;
    for(int i = 0; i < pos - 1; i++)
    {
        auxPointer = auxPointer->next;
    }
    newElement->next = auxPointer->next;
    auxPointer->next = newElement;

    return OK;
}

int delnAfterElem(dsList *pll, void *elem, unsigned dataSize, cmp cmp, int n)
{
    tNode *listPointer, *auxDir, *lastElem;
    int listSize = listLen(pll); 

    listPointer = *pll;
    while (listPointer && cmp(listPointer->data, elem) != 0 && listSize > 0)
    {
        listPointer = listPointer->next;
        listSize--;
    }

    if(!listPointer)
        return NOT_FOUND;
    
    if(listSize - n < 0)
        return ERROR;

    auxDir = listPointer->next;
    listPointer->next = NULL;
    lastElem = listPointer;
    listPointer = auxDir;

    while (listPointer && n > 0)
    {
        auxDir = listPointer->next;
        free(listPointer->data);
        free(listPointer);
        listPointer = auxDir;
        n--;
    }

    lastElem->next = listPointer;
    
    return OK;
}   

int delnLast(dsList *pll, int n)
{
    tNode *listPointer, *auxDir;
    int listSize;

    if((listSize = listLen(pll)) < n)
        return ERROR;
    
    if(listSize == n)
    {
        clearList(pll);
        return OK;
    }

    listPointer = *pll;
    listSize -= n - 1;

    for (int i = 0; i < listSize; i++)
    {
        listPointer = listPointer->next;
    }
    
    auxDir = listPointer->next;
    listPointer->next = NULL;
    listPointer = auxDir;

    while (listPointer)
    {
        auxDir = listPointer->next;
        free(listPointer->data);
        free(listPointer);
        listPointer = auxDir;
    }
    
    
    return OK;
}

int insertAfterElem(dsList *pll, void *elem, unsigned dataSize, cmp cmp, int newElems)
{
    tNode *listPointer, *auxDir, *new;


    listPointer = *pll;
    while (listPointer && cmp(listPointer->data, elem) != 0)
    {
        listPointer = listPointer->next;
    }

    if(!listPointer)
        return NOT_FOUND;

    auxDir = listPointer->next; 

    for(int i = 0; i < newElems; i++)
    {
        if((new = (tNode *)malloc(sizeof(tNode)))== NULL ||
        (new->data = malloc(dataSize))== NULL)
        {
            free(new);
            return NO_SPACE;
        }
        new->dataSize = dataSize;

        listPointer->next = new;
        listPointer = new;
    }

    listPointer->next = auxDir;
    
    return OK;
}