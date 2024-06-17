#include "excersise2.h"

void newTree(tree *tp)
{
    *tp = NULL;
}

int isEmpty(tree *tp)
{
    return *tp == NULL;
}

int addNode(tree *tp, void *info, unsigned dataSize, cmp cmp)
{
    tNode *newNode;
    int comparation; 

    if (*tp == NULL)
    {
        if((newNode = (tNode *)malloc(sizeof(tNode))) == NULL ||
            (newNode->info = malloc(dataSize)) == NULL )
        {
            free(newNode);
            return ERROR;
        }
        
        memcpy(newNode->info, info, dataSize);
        newNode->dataSize = dataSize;
        newNode->left     = NULL;
        newNode->right    = NULL;
        *tp               = newNode;

        return OK;
    }
    
    comparation = cmp((*tp)->info, info);
    if(comparation == 0)
        return DUPLICATE;
    else if(comparation < 0)
        return addNode(&(*tp)->right, info, dataSize, cmp);
    else
        return addNode(&(*tp)->left, info, dataSize, cmp);
}

void clearTree(tree *tp)
{
    if(*tp == NULL)
        return; 
    
    clearTree(&(*tp)->left);
    clearTree(&(*tp)->right);
    free((*tp)->info);
    free(*tp);
    *tp = NULL; 
}

void inorder(tree *tp, action func)
{
    if(*tp == NULL)
        return;
    inorder(&(*tp)->left, func);
    func((*tp)->info);
    inorder(&(*tp)->right, func);
}

tNode *searchNotKey(tree *tp, void *searchedValue, cmp cmp)
{
    tNode *leftValue;
    int comp; 

    if(*tp == NULL)
        return NULL;
    comp = cmp((*tp)->info, searchedValue);
    if(comp == 0)
        return *tp;
    leftValue = searchNotKey(&(*tp)->left, searchedValue, cmp);
    if(leftValue)
        return leftValue;
    return searchNotKey(&(*tp)->right, searchedValue, cmp);
}
