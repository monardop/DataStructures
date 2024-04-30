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
}