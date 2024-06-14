#ifndef EXCERSISE2_H
#define EXCERSISE2_H

    #define NOT_FOUND -1
    #define DUPLICATE -1
    #define OK 1
    #define ERROR 0

    #include <stdlib.h>
    #include <string.h>

    typedef struct Node
    {
        void *info;
        unsigned dataSize;
        struct Node *left, *right;
    }tNode;

    typedef tNode *tree;
    typedef int (*cmp)(void *, void *);
    typedef void (*action)(void *);


    void newTree(tree *tp);
    int isEmpty(tree *tp);
    int addNode(tree *tp, void *info, unsigned dataSize, cmp cmp);
    void clearTree(tree *tp);
    void inorder(tree *tp, action func);
    tNode *searchNotKey(tree *tp, void *searchedValue,cmp cmp);


#endif // EXCERSISE2_H
