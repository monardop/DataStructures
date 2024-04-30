#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

    #include "../../../Utilities/utilities.h"
    #include <stdlib.h>

    typedef tNode *dsList;

    void newList(dsList *);
    bool isEmpty(dsList *);
    void clearList(dsList *);
    int append(dsList *, void *, unsigned);
    int listLen(dsList *);
    int sortedInsert(dsList *, void *, unsigned, cmp);
    void sortList(dsList *, cmp);
    void printList(dsList *, print);
    int removeFirst(dsList *, void *, unsigned );
    int removeAllOccurrences(dsList *, void *, unsigned);
    int removeLastOccurrence(dsList *plist, void *data, unsigned dataSize);
    int removeIndex(dsList *pList, int index);


    
#endif // DYNAMICLIST_H
