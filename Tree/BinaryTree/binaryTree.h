#ifndef BINARYTREE_H
#define BINARYTREE_H

    typedef struct sNode
    {
        void *data;
        unsigned dataSize;
        struct sNode *left, *right;
    }tNode; 

    typedef tNode *tree; 
    typedef int (*cmp)(void *, void *);
    
    #define OK 1
    #define ERROR 0
    #define DUPLICATE -1

    
    void newTree(tree *new);
    int insertarEnArbolRecursivo(tree *pTree, void* d, unsigned dataSize, cmp cmp);
    int insertarEnArbolIterativo(tree *pTree, void* d, unsigned dataSize, cmp cmp);

#endif