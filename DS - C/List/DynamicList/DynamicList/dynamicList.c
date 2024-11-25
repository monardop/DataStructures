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
    tNode *del;
    int len;

    while (*pll && cmp(elem, (*pll)->data) != 0)
    {
        pll = &(*pll)->next;
    }
    pll = &(*pll)->next;

    len = listLen(pll);
    if(n > len)
        return ERROR;

    for (int i = 0; i < n; i++)
    {
        del = *pll;
        *pll = del->next;

        free(del->data);
        free(del);
    }

    return OK;
}

int delnLast(dsList *pll, int n)
{
    tNode *del;
    int listSize;

    listSize = listLen(pll);

    if (listSize < n)
        return ERROR;

    listSize -= n;

    for (int i = 0; i < listSize; i++)
    {
        pll = &(*pll)->next;
    }

    while (*pll)
    {
        del = *pll;
        *pll = del->next;

        free(del->data);
        free(del);
    }

    return OK;
}

int insertAfterElem(dsList *pll, void *elem, unsigned dataSize, cmp cmp, int newElems)
{
    tNode *new;

    while (*pll && cmp(elem, (*pll)->data) != 0)
    {
        pll = &(*pll)->next;
    }

    if (*pll == NULL)
        return ERROR;
    else
        pll = &(*pll)->next;

    for (int i = 0; i < newElems; i++)
    {
        if((new = (tNode *)malloc(sizeof(tNode))) == NULL ||
        (new->data = malloc(dataSize)) == NULL)
        {
            free(new);
            return ERROR;
        }
        new->dataSize = dataSize;

        new->next = *pll;
        *pll = new;
        pll = &(*pll)->next;
    }

    return OK;
}

void mapC(dsList *pll, lambda function)
{
    while (*pll)
    {
        function((*pll)->data);
        pll = &(*pll)->next;
    }
}

void mapPython(dsList *original, dsList *secondList, lambda function)
{
    tNode *new;

    while (*original)
    {
        if((new = (tNode *)malloc(sizeof(tNode))) == NULL ||
        (new->data = malloc((*original)->dataSize)) == NULL)
        {
            free(new);
            return;
        }

        *secondList = new;
        new->next = NULL;
        new->dataSize = (*original)->dataSize;
        memoryCopy(new->data, (*original)->data, (*original)->dataSize);
        function((*secondList)->data);
        secondList = &(*secondList)->next;

        original = &(*original)->next;
    }


}

void filter(dsList *pll, void *cmpData, cmp cmp)
{
    tNode *del;
    while(*pll)
    {
        if(!cmp(cmpData, (*pll)->data))
        {
            del = *pll;
            *pll = del->next;
            free(del->data);
            free(del);
        }
        else
            pll = &(*pll)->next;
    }
}

void reduce(dsList *pll, void *result, reduceFunction func)
{
    while (*pll)
    {
        func(result, (*pll)->data);
        pll = &(*pll)->next;
    }
}

bool exists(dsList *pll, void *elem, cmp cmp)
{
    while (*pll)
    {
        if (cmp(elem, (*pll)->data) == 0)
            return True;
        
        pll = &(*pll)->next;
    }
    return False;
}

int count(dsList *pll, void *elem, cmp cmp)
{
    int count = 0;
    while (*pll)
    {
        if(cmp(elem, (*pll)->data) == 0)
            count++;
        pll = &(*pll)->next;
    }   
    return count;

}

void removeNonDuplicate(dsList *pll, lambda func, cmp cmp)
{
    dsList auxList;
    tNode *del;

    newList(&auxList);
    
    while (*pll)
    {
        if(exists(&auxList, (*pll)->data, cmp))
            pll = &(*pll)->next;
        else if(count(pll,(*pll)->data,cmp) > 1)
        {
            append(&auxList, (*pll)->data, (*pll)->dataSize);
            pll = &(*pll)->next;
        }
        else
        {
            del = *pll;
            *pll = del->next;
            free(del->data);
            free(del);
        }
    }
    
    clearList(&auxList);
}

int setType(dsList *plist, void *elem, unsigned dataSize, cmp cmp)
{
    // if I use this function it is because I do not want duplicate information

    tNode *newNode;

    while (*plist)
    {
        if(cmp(elem, (*plist)->data) == 0)
            return ERROR;
        plist = &(*plist)->next;
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

    *plist = newNode;

    return OK;

}


