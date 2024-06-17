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

    
    void newTree(tree *);
    bool isEmpty(tree *ptree);
    void clearTree(tree *ptree);

    int insert(tree *pTree, void* d, unsigned dataSize, cmp cmp);
    int recursiveInsert(tree *pTree, void* d, unsigned dataSize, cmp cmp);
    
    void printInOrder(tree *pTree, print print);
    void printPostOrder(tree *pTree, print print);
    void printPreOrder(tree *pTree, print print);

    void returnMin(tree *ptree, void *data, unsigned dataSize);
    void returnMax(tree *ptree, void *data, unsigned dataSize);
    void map(tree *ptree, lambda function);

    int delLeaf(tree *ptree);
    int countLeaf(tree *ptree);
    int countNodes(tree *ptree);
    int leftChilds(tree *ptree);
    int clearTreeCount(tree *ptree);
    void getUpToLvl(const tree *ptree, int lvl, print print);
    void getLvl(const tree *ptree, int lvl, print print);
    int treeHeight(const tree *ptree);
    bool isComplete(tree *tp);
    bool avlTree(tree *tp);
    void delNode(tree *tp, void *elem, cmp cmp);

#endif