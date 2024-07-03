#include <stdlib.h>
#include <string.h>

#include "treeInterface.h"
#include "utilities.h"


void initializeTree(tree *tp)
{
    *tp = NULL;
}

int isEmpty(tree *tp)
{
    return *tp == NULL;
}

tNode *createNode(const void *data, const int dataSize)
{
    tNode *newNode;

    if((newNode = (tNode *)malloc(sizeof(tNode))) == NULL || 
       (newNode->data = malloc(dataSize))         == NULL)
    {
        free(newNode);
        return MEM_FAIL;
    }

    memcpy(newNode->data, data, dataSize);
    
    newNode->dataSize = dataSize;
    newNode->left     = NULL;
    newNode->right    = NULL;

    return newNode;
}

int addElement(tree *tp, const void *data, const int dataSize, cmp cmp)
{
    tNode *newNode;
    int comparison; 

    if(*tp == NULL)
    {
        newNode = createNode(data, dataSize);
        *tp = newNode;
        return OK;
    }

    comparison = cmp((*tp)->data, data);
    if(comparison == 0)
        return DUPLICATED;
    else if(comparison > 0)
        return addElement(&(*tp)->left, data, dataSize, cmp);
    else
        return addElement(&(*tp)->right, data, dataSize, cmp);

}

int addElementWDuplicated(tree *tp, void *data, const int dataSize, cmp cmp, action action)
{
    tNode *newNode;
    int comparison; 

    if(*tp == NULL)
    {
        newNode = createNode(data, dataSize);
        *tp = newNode;
        return OK;
    }

    comparison = cmp((*tp)->data, data);
    if(comparison == 0)
    {
        action(data);
        return DUPLICATED;
    }
    else if(comparison > 0)
        return addElement(&(*tp)->left, data, dataSize, cmp);
    else
        return addElement(&(*tp)->right, data, dataSize, cmp);

}

int treeHeight(tree *tp)
{
    int leftBranch, rightBranch;

    if (*tp == NULL)
    {
        return 0;
    }
    
    leftBranch  = treeHeight(&(*tp)->left);
    rightBranch = treeHeight(&(*tp)->right);

    return 1 + MAX(leftBranch, rightBranch);
}

int isAVL(tree *tp)
{
    int lBranch, rBranch, result;
    if(*tp == NULL)
        return True;
    
    lBranch = treeHeight(&(*tp)->left);
    rBranch = treeHeight(&(*tp)->right);

    result = lBranch - rBranch;
    if(result <= 1 || result >= -1)
        return (isAVL(&(*tp)->left) && isAVL(&(*tp)->right));

    return False;
}

