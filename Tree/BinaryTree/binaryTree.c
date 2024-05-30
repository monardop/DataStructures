#include "binaryTree.h"
#include <stdlib.h>
#include <string.h>


void newTree(tree *new)
{
    *new = NULL;
}

int insertarEnArbolIterativo(tree *pTree, void* d, unsigned dataSize, cmp cmp)
{
    int comparacion;
    tNode *new; 

    while(*pTree != NULL)
    {
        comparacion = cmp((*pTree)->data, d);
        if(comparacion == 0)
            return DUPLICATE;
        if(comparacion < 0)
            pTree = &(*pTree)->left;
        else
            pTree = &(*pTree)->right;
    }

    //pedir memoria
    if((new = (tNode *)malloc(sizeof(tNode))) == NULL ||
       (new->data = malloc(dataSize)) == NULL)
    {
        free(new);
        return ERROR;
    }

    new->right = NULL;
    new->left = NULL;
    new->dataSize = dataSize;
    memcpy(new->data, d, dataSize);
    //conectar
    *pTree = new;

    return OK;
}

int insertarEnArbolRecursivo(tree *pTree, void* d, unsigned dataSize, cmp cmp)
{
    int comparacion = cmp((*pTree)->data, d);
    tNode *new; 

    if (*pTree != NULL)
    {
        if(comparacion == 0)
            return DUPLICATE;
        if(comparacion < 0)
            return insertarEnArbolRecursivo(&(*pTree)->left, d, dataSize, cmp);
        else
            return insertarEnArbolRecursivo(&(*pTree)->right, d, dataSize, cmp);
    }

    if((new = (tNode *)malloc(sizeof(tNode))) == NULL ||
       (new->data = malloc(dataSize)) == NULL)
    {
        free(new);
        return ERROR;
    }

    new->right = NULL;
    new->left = NULL;
    new->dataSize = dataSize;
    memcpy(new->data, d, dataSize);

    *pTree = new;

    return OK;
}

