#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

    #include "../../../Utilities/utilities.h"
    #include <stdlib.h>

    typedef tNode *dsList;

    bool isEmpty(dsList *);
    void newList(dsList *);
    void clearList(dsList *);
    void sortList(dsList *, cmp);
    void printList(dsList *, print);
    int append(dsList *, void *, unsigned);
    int listLen(dsList *);
    int sortedInsert(dsList *, void *, unsigned, cmp);
    int removeFirst(dsList *, void *, unsigned, cmp );
    int removeAllOccurrences(dsList *, void *, unsigned, cmp);
    int removeLastOccurrence(dsList *plist, void *data, unsigned dataSize, cmp);
    int removeIndex(dsList *pList, int index);
    int indexedInsert(dsList *pll, void *data, unsigned dataSize, int pos);
    int delnAfterElem(dsList *pll, void *elem, unsigned dataSize, cmp cmp, int n);
    int delnLast(dsList *pll, int n);
    int insertAfterElem(dsList *pll, void *elem, unsigned dataSize, cmp cmp, int newElems);
    void mapC(dsList *pll, lambda function);
    void mapPython(dsList *original, dsList *newList, lambda function);
    void filter(dsList *pll, void *cmpData, cmp cmp);
    void reduce(dsList *pll, void *result, reduceFunction func);
    void removeNonDuplicate(dsList *pll, lambda func, cmp cmp);
    int setType(dsList *pll, void *elem, unsigned dataSize, cmp cmp);

#endif // DYNAMICLIST_H
