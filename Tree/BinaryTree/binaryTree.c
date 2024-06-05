#include "binaryTree.h"


void newTree(tree *new)
{
    *new = NULL;
}

bool isEmpty(tree *ptree)
{
    return *ptree == NULL;
}

int insert(tree *pTree, void* d, unsigned dataSize, cmp cmp)
{
    int comparacion;
    tTreeNode *new; 

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

    if((new = (tTreeNode *)malloc(sizeof(tTreeNode))) == NULL ||
       (new->data = malloc(dataSize)) == NULL)
    {
        free(new);
        return ERROR;
    }

    new->right = NULL;
    new->left = NULL;
    new->dataSize = dataSize;
    memoryCopy(new->data, d, dataSize);
    *pTree = new;

    return OK;
}

int recursiveInsert(tree *pTree, void* d, unsigned dataSize, cmp cmp)
{
    int comparacion;
    tTreeNode *new; 

    if (*pTree != NULL)
    {
        comparacion = cmp((*pTree)->data, d);
        
        if(comparacion == 0)
            return DUPLICATE;
        if(comparacion < 0)
            return recursiveInsert(&(*pTree)->left, d, dataSize, cmp);
        else
            return recursiveInsert(&(*pTree)->right, d, dataSize, cmp);
    }

    if((new = (tTreeNode *)malloc(sizeof(tTreeNode))) == NULL ||
       (new->data = malloc(dataSize)) == NULL)
    {
        free(new);
        return ERROR;
    }

    new->right = NULL;
    new->left = NULL;
    new->dataSize = dataSize;
    memoryCopy(new->data, d, dataSize);

    *pTree = new;

    return OK;
}

void clearTree(tree *ptree)
{
    if(*ptree == NULL)
        return;
    clearTree(&(*ptree)->left);
    clearTree(&(*ptree)->right);
    free((*ptree)->data);
    free(*ptree);
}

void printInOrder(tree *pTree, print print)
{
    if(*pTree == NULL)
        return;
    printInOrder(&(*pTree)->left, print);
    print((*pTree)->data);
    printInOrder(&(*pTree)->right, print);
}

void printPostOrder(tree *pTree, print print)
{
    if(*pTree == NULL)
        return;
    printInOrder(&(*pTree)->left, print);
    printInOrder(&(*pTree)->right, print);
    print((*pTree)->data);
}

void printPreOrder(tree *pTree, print print)
{
    if(*pTree == NULL)
        return;
    print((*pTree)->data);
    printInOrder(&(*pTree)->left, print);
    printInOrder(&(*pTree)->right, print);
}

void map(tree *ptree, lambda function)
{
    if (*ptree == NULL)
        return;
    
    function((*ptree)->data);
    map(&(*ptree)->left, function);
    map(&(*ptree)->right, function);
}