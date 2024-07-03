#ifndef TREEINTERFACE_H
#define TREEINTERFACE_H

    typedef struct sNode
    {
        void         *data;
        int           dataSize;
        struct sNode *left,
                     *right;
    }tNode;

    typedef tNode *tree;
    typedef int (*cmp)(const void* original, const void* newOne);
    typedef void (*action)(void *);
    
    #define MIN(X, Y) (((X)<(Y))?(X):(Y))
    #define MAX(X, Y) (((X)>(Y))?(X):(Y))
    
    void initializeTree(tree *tp);
    int isEmpty(tree *tp);
    int addElement(tree *tp, const void *data, const int dataSize, cmp cmp);
    int addElementWDuplicated(tree *tp, void *data, const int dataSize, cmp cmp, action action);
    int treeHeight(tree *tp);
    int isAVL(tree *tp);

#endif // TREEINTERFACE_H
