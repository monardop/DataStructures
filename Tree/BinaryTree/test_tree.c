#include "testing.h"
#include <stdio.h>

void intSquare(void *element)
{
    int *newElement = (int *)element;
    *newElement *= *newElement;
}

int test_recursiveInsert()
{
    tree test;
    int num[] = {100, 50, 200, 25, 75, 80, 50};
    int nro;

    newTree(&test);
    for (int i = 0; i < 7; i++)
    {
        recursiveInsert(&test, num + i, sizeof(int), intCompare);
    }
    printf("Inorder: \n\t");
    printInOrder(&test, intPrint);
    printf("\nPreorder: \n\t");
    printPreOrder(&test, intPrint);
    printf("\nPostorder: \n\t");
    printPostOrder(&test, intPrint);

    returnMax(&test, &nro, sizeof(int));
    printf("\nMax: %d", nro);
    returnMin(&test, &nro, sizeof(int));
    printf("\nMin: %d", nro);

    map(&test, intSquare);
    printInOrder(&test, intPrint);

    clearTree(&test);
    
    return OK;
}

int new_test()
{
    tree testTree;
    int testing[] = {67, 52, 41,4, 13, 31, 38, 43,65,60,66,94,77,95,96};

    newTree(&testTree);
    for (int i = 0; i < 15; i++)
    {
        recursiveInsert(&testTree, testing + i, sizeof(int), intCompare);
    }
    printf("\n\n PostOrder: \n\t");
    printInOrder(&testTree, intPrint);
    


    clearTree(&testTree);

    return OK;
}


void mainTest(void)
{
    printf("Testing recursive insert: \n");
    test_recursiveInsert();
    new_test();

}