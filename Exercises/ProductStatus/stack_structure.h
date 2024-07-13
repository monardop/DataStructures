#ifndef STACK_STRUCTURE_H
#define STACK_STRUCTURE_H

    typedef struct sNode {
        void         *data;
        unsigned      dataSize;
        struct sNode *next;
    }Node;

    typedef Node *dsStack;

    #define OK   1
    #define FAIL 0
    
    void initialize(dsStack *ps);
    int push(dsStack *sp, void *data, int dataSize);

#endif // STACK_STRUCTURE_H
