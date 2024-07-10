#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H

    typedef struct sNode {
        void         *data;
        unsigned      dataSize;
        struct sNode *next;
    }tNode;

    typedef tNode *dsList;
    typedef int (*cmp)(const void *, const void*);
    typedef void (*reduceFunction)(void *dst, void *src);

    void newList(dsList *);
    void delList(dsList *pl);
    void simplifyList(dsList *pl, cmp cmp, reduceFunction fuse);
    void returnNdel(dsList *pl, void *container);
    int  emptyList(dsList *);
    int  find(dsList *pl, void *key, cmp cmp);
    int  sortedInsertion(dsList *pl, void *data, unsigned dataSize, cmp cmp);

#endif // LIST_INTERFACE_H_INCLUDED
