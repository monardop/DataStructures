#include <stdio.h>
#include "testing.h"

bool test_append()
{
    int num[] = {0,1,2,3,4,5,6,7,8,9};
    dsList list;
    newList(&list);

    for (int i = 0; i < 10; i++)
    {
        append(&list, num+i, sizeof(int));
    }
    printList(&list, intPrint);
    printf("\nList len: %d", listLen(&list));
    clearList(&list);
    return True;
}

bool test_sortedAppend()
{
    int numSorted[] = {0,4,8,12,16,20,24};
    int num[] = {6,3,2,5,7,9,1,8,10,23};
    dsList list;
    newList(&list);

    for (int i = 0; i < 7; i++)
    {
        append(&list, numSorted+i, sizeof(int));
    }
    printList(&list, intPrint);
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        sortedInsert(&list, num+i, sizeof(int), intCompare);
        printList(&list, intPrint);
        printf("\n");
    }

    clearList(&list);
    return 1;
}

bool test_sort()
{
    int num[] = {6,3,2,5,7,9,1,8,10,23};
    dsList list;
    newList(&list);

    for (int i = 0; i < 10; i++)
    {
        append(&list, num + i, sizeof(int));
    }

    printList(&list, intPrint);
    printf("\n");

    sortList(&list, intCompare);
    printList(&list, intPrint);

    clearList(&list);
    return True;
}

bool test_remove()
{
    int test[] = {4,5,3,1,9,1,2,1,3,7,2,9,4,0,4};
    dsList testList;
    int delNumber;

    newList(&testList);

    for (int i = 0; i < 15; i++)
    {
        append(&testList, test+i, sizeof(int));
    }
    
    printf("Elements: %d\n", listLen(&testList));
    printList(&testList, intPrint);

    printf("\nRemoving all 1's\n");
    delNumber = 1;
    removeAllOccurrences(&testList, &delNumber, sizeof(int));
    printList(&testList, intPrint);

    printf("\nRemoving the last 4\n");
    delNumber = 4;
    removeLastOccurrence(&testList, &delNumber, sizeof(int));
    printList(&testList, intPrint);

    printf("\nRemoving the first 9\n");
    delNumber = 9;
    removeFirst(&testList, &delNumber, sizeof(int));
    printList(&testList, intPrint);
    printf("\nRemoving the 3rd element\n");
 
    removeIndex(&testList, 3);
    printList(&testList, intPrint);

    clearList(&testList);
    
    return True;
}

bool test_indexInsert()
{
    int num[] = {0,1,2,3,4,5,6,7,8,9};
    dsList list;
    int new;

    newList(&list);

    for (int i = 0; i < 10; i++)
    {
        append(&list, num+i, sizeof(int));
    }
    printList(&list, intPrint);
    
    printf("\n Index 10 = 10: \n");
    new = 10;
    indexedInsert(&list, &new, sizeof(int), 10);
    printList(&list, intPrint);

    printf("\n Should not append, 15= 10 \n");
    new = 10;
    indexedInsert(&list, &new, sizeof(int), 15);
    printList(&list, intPrint);

    printf("\n Index 3 = 10: \n");
    new = 10;
    indexedInsert(&list, &new, sizeof(int), 3);
    printList(&list, intPrint);

    clearList(&list);

    return True;
}

bool test_afterN()
{
    int num[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    dsList list;
    int new;

    newList(&list);

    for (int i = 0; i < 10; i++)
    {
        append(&list, num+i, sizeof(int));
    }
    printList(&list, intPrint);

    printf("\n  Removing 3 elements after 4.\n");
    new = 4;
    delnAfterElem(&list, &new, sizeof(int), intCompare, 3);
    printList(&list, intPrint);

    printf("\n  Removing 3 last elements.\n");
    delnLast(&list, 3);
    printList(&list, intPrint);

    printf("\n  Total len: %d", listLen(&list));
    printf("\n  Adding 6 elements.\n");
    insertAfterElem(&list, &new, sizeof(int), intCompare, 6);
    printf("\n  New len: %d", listLen(&list));

    clearList(&list);

    return OK;

}


void mainTesting(void)
{
    printf("Testing Append:\n");
    test_append();
    printf(SEPARATOR);
    printf("\nTesting sortedInsert:\n");
    test_sortedAppend();
    printf(SEPARATOR);
    printf("\nTesting sort:\n");
    test_sort();
    printf(SEPARATOR);
    printf("\n\nTesting remove:\n");
    test_remove();
    printf(SEPARATOR);
    printf("\n\nTesting index insert:\n");
    test_indexInsert();
    printf(SEPARATOR);
    printf("\n\nTesting after n func:\n");
    test_afterN();
}