#ifndef BINARY_TREE_H
#define BINARY_TREE_H

    typedef struct sNode {
        void         *data;
        unsigned      dataSize;
        struct sNode *left, 
                     *right;
    }Node;

    typedef Node *Tree;
    typedef int (*cmp)(const void *, const void *);
    typedef void (*action)(void *);

    #define OK        1
    #define MEM_ERROR 0
    #define EMPTY    -1 

    void initializeTree(Tree *tp);
    void cleanTree(Tree *tp);
    void showAscendent(Tree *tp, action print);
    void showDescendant(Tree *tp, action print);
    int  newElement(Tree *tp, void *newData, unsigned dataSize, cmp compare, action function);
    int  showMinMaxValue(Tree *tp, cmp compare, action print, char mode);
    int  emptyTree(Tree *tp);

#endif