#ifndef BINARYTREE_H
#define BINARYTREE_H

    #include <stdlib.h>
    #include "../../Utilities/utilities.h"

    typedef struct sNode
    {
        void *data;
        unsigned dataSize;
        struct sNode *left, *right;
    }tTreeNode; 

    typedef tTreeNode *tree; 
    
    #define DUPLICATE -1

    
    void newTree(tree *new);
    bool isEmpty(tree *ptree);
    void clearTree(tree *ptree);

    int insert(tree *pTree, void* d, unsigned dataSize, cmp cmp);
    int recursiveInsert(tree *pTree, void* d, unsigned dataSize, cmp cmp);
    
    void printInOrder(tree *pTree, print print);
    void printPostOrder(tree *pTree, print print);
    void printPreOrder(tree *pTree, print print);


#endif