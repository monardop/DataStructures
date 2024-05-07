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
    printf("\n  List len: %d", listLen(&list));
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

    printf("  Elements: %d\n", listLen(&testList));
    printList(&testList, intPrint);

    printf("\n  Removing all 1's\n");
    delNumber = 1;
    removeAllOccurrences(&testList, &delNumber, sizeof(int));
    printList(&testList, intPrint);

    printf("\n  Removing the last 4\n");
    delNumber = 4;
    removeLastOccurrence(&testList, &delNumber, sizeof(int));
    printList(&testList, intPrint);

    printf("\n  Removing the first 9\n");
    delNumber = 9;
    removeFirst(&testList, &delNumber, sizeof(int));
    printList(&testList, intPrint);
    printf("\n  Removing the 3rd element\n");

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
    printf("\n  Index 10 = 10: \n");
    new = 10;
    indexedInsert(&list, &new, sizeof(int), 10);
    printList(&list, intPrint);

    printf("\n  Should not append, 15= 10 \n");
    new = 10;
    indexedInsert(&list, &new, sizeof(int), 15);
    printList(&list, intPrint);

    printf("\n  Index 3 = 10: \n");
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

bool test_map()
{
    int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    dsList list;

    newList(&list);

    for (int i = 0; i < 10; i++)
    {
        append(&list, num+i, sizeof(int));
    }
    printList(&list, intPrint);

    printf("\n  Now testing map:\n");
    mapC(&list, intSquare);
    printList(&list, intPrint);

    clearList(&list);

    return True;
}

bool test_reduce()
{
    int num[] = {0,1,2,3,4,5,6,7,8,9};
    int result = 0;
    dsList list;
    newList(&list);

    for (int i = 0; i < 10; i++)
    {
        append(&list, num+i, sizeof(int));
    }
    printList(&list, intPrint);

    reduce(&list, &result, redIntSum);
    printf("\n  The result was %d", result);

    clearList(&list);

    return True;
}

bool test_filter()
{
    int num[] = {220,35,99,340,423,511,60,70,98,93};
    int lessThan = 100;
    dsList list;
    newList(&list);

    for (int i = 0; i < 10; i++)
    {
        append(&list, num+i, sizeof(int));
    }
    printList(&list, intPrint);
    printf("\n  Using reduce:\n");

    filter(&list, &lessThan, intLessThan);
    printList(&list, intPrint);

    clearList(&list);
    return True;
}

bool test_map2()
{
    int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    dsList list, list2;

    newList(&list);
    newList(&list2);

    for (int i = 0; i < 10; i++)
    {
        append(&list, num+i, sizeof(int));
    }
    printList(&list, intPrint);

    printf("\n  Now testing map:\n");
    mapPython(&list, &list2, intSquare);
    printList(&list, intPrint);
    printf("\n");
    printList(&list2, intPrint);

    clearList(&list);
    clearList(&list2);

    return True;
}

bool test_duplicate()
{
    int num[] = {0,2,2,2,4,5,3,10,20,20,10,5,19,30,22};
    dsList list;

    newList(&list);

    for (int i = 0; i < 15; i++)
    {
        append(&list, num+i, sizeof(int));
    }
    printList(&list, intPrint);

    printf("\n  Now testing remove:\n");
    removeNonDuplicate(&list, intSquare, intCompare);
    printList(&list, intPrint);


    clearList(&list);

    return True;
}

bool test_set()
{
    int num[] = {0,2,2,2,4,5,3,10,20,20,10,5,19,30,22};
    dsList list;

    newList(&list);
    
    printf("  List:\n");
    for (int i = 0; i < 15; i++)
    {
        printf("\t %d", num[i]);
        setType(&list, num+i, sizeof(int), intCompare);
    }
    printf("\n  Result:\n");
    printList(&list, intPrint);

    clearList(&list);

    return True;
}

void mainTesting(void)
{
    printf("-Testing Append:\n");
    test_append();
    printf(SEPARATOR);
    printf("\n-Testing sortedInsert:\n");
    test_sortedAppend();
    printf(SEPARATOR);
    printf("\n-Testing sort:\n");
    test_sort();
    printf(SEPARATOR);
    printf("\n\n-Testing remove:\n");
    test_remove();
    printf(SEPARATOR);
    printf("\n\n-Testing index insert:\n");
    test_indexInsert();
    printf(SEPARATOR);
    printf("\n\n-Testing after n func:\n");
    test_afterN();
    printf(SEPARATOR);
    printf("\n\n-Testing reduce func:\n");
    test_reduce();
    printf(SEPARATOR);
    printf("\n\n-Testing filter func:\n");
    test_filter();
    printf(SEPARATOR);
    printf("\n\n-Testing mapC func:\n");
    test_map();
    printf(SEPARATOR);
    printf("\n\n-Testing mapPython func:\n");
    test_map2();
    printf(SEPARATOR);
    printf("\n\n-Testing duplicated func:\n");
    test_duplicate();
    printf(SEPARATOR);
    printf("\n\n-Testing set func:\n");
    test_set();
}
