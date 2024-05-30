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
    tNode *new; 

    while (*plist)
    {
        plist = &(*plist)->next;
    }

    if((new = (tNode *)malloc(sizeof(tNode))) == NULL || 
        (new->data = malloc(dataSize)) == NULL)
    {
        free(new);
        return ERROR;
    }

    memoryCopy(new->data, data, dataSize);
    new->dataSize = dataSize;
    new->next = NULL;

    *plist = new; 

    return OK;
}

int sortedInsert(dsList *plist, void* data, unsigned dataSize, cmp cmp)
{
    tNode *newNode;

    if((newNode = (tNode *)malloc(sizeof(tNode))) == NULL ||
               (newNode->data = malloc(dataSize)) == NULL)
    {
        free(newNode);
        return NO_SPACE;
    }
    memoryCopy(newNode->data, data, dataSize);
    newNode->dataSize = dataSize;

    while (*plist && cmp(data, (*plist)->data) > 0)
    {
        plist = &(*plist)->next;
    }
    
    newNode->next = *plist;
    *plist = newNode;

    return OK;
}

int listLen(dsList *pList)
{
    int tam = 0;

    while (*pList)
    {
        tam++;
        pList = &(*pList)->next;
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
    tNode *actElement, *nextNode;
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
        nextNode = actElement->next;
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
    if(!*plist)
        return;

    while (*plist)
    {
        printFunc((*plist)->data);
        plist = &(*plist)->next;
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

int removeFirst(dsList *plist, void *data, unsigned dataSize, cmp cmp)
{
    tNode *aux;
    while (*plist)
    {
        if(cmp(data, (*plist)->data) == 0){
            aux = (*plist)->next;
            *plist = aux->next;

            free(aux->data);
            free(aux);
            return OK;
        }
        plist = &(*plist)->next;
    }

    return NOT_FOUND;
}

int removeAllOccurrences(dsList *plist, void *data, unsigned dataSize, cmp cmp)
{
    tNode *aux;
    int deleted = 0; 

    while (*plist)
    {
        if(cmp(data, (*plist)->data) == 0){
            aux = (*plist)->next;
            *plist = aux->next;

            free(aux->data);
            free(aux);
            deleted++;
        }
        plist = &(*plist)->next;
    }

    return deleted;
}

int removeIndex(dsList *pList, int index)
{
    tNode *aux;

    while (*pList && index)
    {
        pList = &(*pList)->next;
        index--;
    }

    if(*pList && !index)
    {
        aux = *pList;
        *pList = aux->next;

        free(aux->data);
        free(aux);
        return 1;
    }
    return 0;
}

int removeLastOccurrence(dsList *plist, void *data, unsigned dataSize, cmp cmp)
{
    tNode *pointer, *del;
    
    pointer = *plist;

    while (pointer)  
    {
        if(cmp(data, pointer->data) == 0)
        {
            del = pointer;
        }   
        pointer = pointer->next;
    }

    if(del == NULL)
        return NOT_FOUND;

    while (*plist != del)
    {
        plist = &(*plist)->next;
    }
    
    *plist = del->next;
    free(del->data);
    free(del);

    return OK;
    
}

int indexedInsert(dsList *pll, void *data, unsigned dataSize, int pos)
{
    /*
        *if list[pos] exists => list[pos]=newElem,the previous list[pos] -> list[pos+1]
        *if len(list) = n and pos > n => error
    */
    int listSize;
    tNode *newElement, *aux;


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


    for(int i = 0; i < pos; i++)
    {
        pll = &(*pll)->next;
    }
    
    aux = *pll;
    *pll = newElement;
    newElement->next = aux;

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

void mapC(dsList *pll, lambda function)
{
    tNode *listPointer;

    listPointer = *pll;

    while (listPointer)
    {
        function(listPointer->data);
        listPointer = listPointer->next;
    }
}

void mapPython(dsList *original, dsList *secondList, lambda function)
{
    tNode *listPointer   = *original;

    while (listPointer)
    {
        append(secondList, listPointer->data, listPointer->dataSize);
        listPointer = listPointer->next;
    }

    mapC(secondList, function);
}

void filter(dsList *pll, void *cmpData, cmp cmp)
{
    tNode *list = *pll;

    while (list)
    {

        if (!cmp(cmpData, list->data))
        {
            delNode(pll,list);
            list = *pll;
        }
        else
        {
            list = list->next;
        }
    }
}

void reduce(dsList *pll, void *result, reduceFunction func)
{
    tNode *list = *pll;

    while (list)
    {
        func(result, list->data);
        list = list->next;
    }
}

//Required function for the course.
bool isDuplicated(dsList *pll, tNode* elem, cmp cmp)
{
    tNode *pointer = *pll;
    while (pointer)
    {
        if(cmp(elem->data, pointer->data) == 0 && pointer != elem)
        {
            return True;
        }
        pointer = pointer->next;
    }

    return False;
}

void removeNonDuplicate(dsList *pll, lambda func, cmp cmp)
{
    tNode *pointer, *aux;
    pointer = *pll;

    while (pointer)
    {
        if(!isDuplicated(pll,pointer,cmp))
        {
            aux = pointer->next;
            delNode(pll,pointer);
            pointer = aux;
        }
        else
        {
            pointer = pointer->next;
        }
    }
    mapC(pll,func);
}

int setType(dsList *plist, void *elem, unsigned dataSize, cmp cmp)
{
    // if I use this function it is because I do not want duplicate information

    tNode *pointer, *newNode;

    pointer = *plist;

    while (pointer)
    {
        if(!cmp(elem, pointer->data))
            return 0;
        
        pointer = pointer->next;
    }
    

    if((newNode = (tNode *)malloc(sizeof(tNode))) == NULL ||
               (newNode->data = malloc(dataSize)) == NULL)
    {
        free(newNode);
        return NO_SPACE;
    }

    memoryCopy(newNode->data, elem, dataSize);
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
