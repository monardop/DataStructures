#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

    #include "../../../Utilities/utilities.h"
    #include <stdlib.h>

    typedef tNode *dsList;

    void newList(dsList *);
    int isEmpty(dsList *);
    void clearList(dsList *);
    int append(dsList *, void *, unsigned);
    int sortedInsert(dsList *, void *, unsigned, cmp);
    int listLen(dsList *);
    void sortList(dsList *, cmp);
    void printList(dsList *, print);

#endif // DYNAMICLIST_H
