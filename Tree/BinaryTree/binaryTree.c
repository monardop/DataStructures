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
        comparacion = cmp(d, (*pTree)->data);
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

int recursiveInsert(tree *pTree, void* data, unsigned dataSize, cmp cmp)
{
    int comparison;
    tTreeNode *new;

    if (*pTree != NULL)
    {
        comparison = cmp(data, (*pTree)->data);

        if(comparison == 0)
            return DUPLICATE;

        if(comparison < 0)
            return recursiveInsert(&(*pTree)->left, data, dataSize, cmp);
        else
            return recursiveInsert(&(*pTree)->right, data, dataSize, cmp);
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
    memoryCopy(new->data, data, dataSize);

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
    *ptree = NULL;
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

    printPostOrder(&(*pTree)->left, print);
    printPostOrder(&(*pTree)->right, print);
    print((*pTree)->data);
}

void printPreOrder(tree *pTree, print print)
{
    if(*pTree == NULL)
        return;
    print((*pTree)->data);
    printPreOrder(&(*pTree)->left, print);
    printPreOrder(&(*pTree)->right, print);
}

void map(tree *ptree, lambda function)
{
    if (*ptree == NULL)
        return;

    function((*ptree)->data);
    map(&(*ptree)->left, function);
    map(&(*ptree)->right, function);
}

void returnMax(tree *ptree, void *data, unsigned dataSize)
{
    if((*ptree)->right != NULL)
    {
        returnMax(&(*ptree)->right, data, dataSize);

    }else
    {
        memoryCopy(data, (*ptree)->data, MIN((*ptree)->dataSize, dataSize));
        return;
    }
}

void returnMin(tree *ptree, void *data, unsigned dataSize)
{
    if((*ptree)->left != NULL)
    {
        returnMin(&(*ptree)->left, data, dataSize);
    }else
    {
        memoryCopy(data, (*ptree)->data, MIN((*ptree)->dataSize, dataSize));
        return;
    }
}

int delLeaf(tree *ptree)
{
    if(*ptree == NULL)
        return;

    if((*ptree)->left == NULL && (*ptree)->right == NULL)
    {
        free((*ptree)->data);
        free(*ptree);
        *ptree = NULL;
        return 1; 
    }

    return delLeaf(&(*ptree)->left) + delLeaf(&(*ptree)->right);
}

int countLeaf(tree *ptree)
{
    if(*ptree == NULL)
        return 0;

    if((*ptree)->left == NULL && (*ptree)->right == NULL)
    {
        return 1;
    }

    return countLeaf(&(*ptree)->left) + countLeaf(&(*ptree)->right);
}

int countNodes(tree *ptree)
{
    if(*ptree == NULL)
        return 0;

    if((*ptree)->left == NULL && (*ptree)->right == NULL)
    {
        return 0;
    }

    return countNodes(&(*ptree)->left) + countNodes(&(*ptree)->right) + 1;
}

int leftChilds(tree *ptree)
{
    if(*ptree == NULL)
        return 0;

    return (leftChilds(&(*ptree)->left) + 1) - (leftChilds(&(*ptree)->right) + 1);
}

int clearTreeCount(tree *ptree)
{
    int cont;
    if(*ptree == NULL)
        return;
    cont = clearTreeCount(&(*ptree)->left) + clearTreeCount(&(*ptree)->right);
    free((*ptree)->data);
    free(*ptree);
    *ptree = NULL;

    return cont + 1;
}

void getUpToLvl(const tree *ptree, int lvl, print print)
{
    if(*ptree == NULL)
        return;

    if(lvl >= 0)
    {
        getUpToLvl(&(*ptree)->left, lvl - 1, print);
        print((*ptree)->data);
        getUpToLvl(&(*ptree)->right, lvl - 1, print);
    }
}

void getLvl(const tree *ptree, int lvl, print print)
{
    if(*ptree == NULL)
        return;

    if(lvl > 0)
    {
        getLvl(&(*ptree)->left, lvl - 1, print);
        getLvl(&(*ptree)->right, lvl - 1, print);
    }
    if(lvl == 0)
    {
        print((*ptree)->data);
    }
}

int treeHeight(const tree *ptree)
{
    int hLeft, hRight;
    if(*ptree == NULL)
        return 0;

    hLeft = treeHeight((*ptree)->left);
    hRight = treeHeight((*ptree)->right);

    return 1 + MAX(hLeft, hRight);
}

bool isComplete(tree *tp)
{
    if(*tp == NULL)
        return True;
    
    if(((*tp)->left == NULL && (*tp)->right == NULL) || 
       ((*tp)->left != NULL && (*tp)->right != NULL))
    {
        return isComplete(&(*tp)->left) && isComplete(&(*tp)->right);
    }
    else
    {
        return False;
    }
}

bool avlTree(tree *tp)
{
    int hLeft, hRight;

    if (*tp == NULL)
    {
        return True;
    }
    
    hLeft = treeHeight((*tp)->left);
    hRight = treeHeight((*tp)->right);

    if( mod(hLeft - hRight) <= 1)
    {
        return avlTree(&(*tp)->left) && avlTree(&(*tp)->right);
    }

    return False;
}
