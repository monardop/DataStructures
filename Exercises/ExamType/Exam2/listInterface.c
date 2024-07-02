#include "listInterface.h"

void newList(dsList *list)
{
    *list = NULL;
}

int insertElement(dsList *list, const void *data, const int dataSize)
{
    tNode *newElement;

    if((newElement = (tNode *)malloc(sizeof(tNode))) == NULL ||
       (newElement->data = malloc(dataSize)) == NULL)
    {
        free(newElement);
        return MEM_FAIL;
    }
    memcpy(newElement->data, data, dataSize);
    newElement->dataSize = dataSize;
    
    if(*list == NULL)
    {
        *list = newElement;
        newElement->next = newElement;
        return OK;
    }

    newElement->next = (*list)->next;
    (*list)->next = newElement;
    *list = newElement;

    return OK;
}

void clearList(dsList *list)
{
    tNode *delNode, *auxElem;

    if(*list == NULL)
        return;

    auxElem = (*list)->next;

    do
    {
        delNode = auxElem;
        auxElem = auxElem->next;
        free(delNode->data);
        free(delNode);
    } while (auxElem != (*list)->next);
       
    free(auxElem->data);
    free(auxElem);
    *list = NULL;   
}

dsList *nextElemCheck(dsList *list, const void *data, cmp cmp)
{
    dsList *auxList;

    auxList = &(*list)->next;
    if(cmp((*auxList)->data, data) == 1)  
        return auxList;
        
    return NULL;
}

dsList *nextElem(dsList *list)
{
    return &(*list)->next;
}

void mapList(dsList *list, action function)
{
    tNode *aux;

    aux = (*list)->next;
    do
    {
        function(aux->data);
        aux = aux->next;
    } while (aux != (*list)->next);
}