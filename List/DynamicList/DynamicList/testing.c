#include <stdio.h>
#include "testing.h"

int test_append()
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
    return 1;
}

int test_sortedAppend()
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

int test_sort()
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
    return 1;
}

void mainTesting(void)
{
    printf("Testing Append:\n");
    test_append();
    printf("\nTesting sortedInsert:\n");
    test_sortedAppend();
    printf("\nTesting sort:\n");
    test_sort();
}