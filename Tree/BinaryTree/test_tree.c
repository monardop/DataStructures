#include "testing.h"
#include <stdio.h>

void testMessage(char *msg, int result, int expected)
{
    printf("\n%s\n", msg);
    if (result == expected)
    {
        printf("\t\t OK\n");
    }else
    {
        printf("\t\t ERROR\n");
    }
}

void intSquare(void *element)
{
    int *newElement = (int *)element;
    *newElement *= *newElement;
}

void test_recursiveInsert()
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
}

void new_test()
{
    tree testTree;
    int testing[] = {67, 52, 41,4, 13, 31, 38, 43,65,60,66,94,77,95,96};

    newTree(&testTree);
    for (int i = 0; i < 15; i++)
    {
        recursiveInsert(&testTree, testing + i, sizeof(int), intCompare);
    }
    printf("\n\n Inorder: \n\t");
    printInOrder(&testTree, intPrint);

    clearTree(&testTree);

}

void test_avl()
{
    tree testTree1;
    int testNum1[] = {50, 17, 76, 9, 23, 54, 72, 67, 14, 19, 12};
    int testNum2[] = {50, 17, 72, 12, 23, 54, 76, 9, 14, 19, 67};

    // test False
    newTree(&testTree1);
    for(int i = 0; i < 11; i++)
    {
        recursiveInsert(&testTree1, testNum1 + i, sizeof(int), intCompare);
    }
    testMessage("Testing AVL -> False",avlTree(&testTree1),False);
    clearTree(&testTree1);

    for(int i = 0; i < 11; i++)
    {
        recursiveInsert(&testTree1, testNum2 + i, sizeof(int), intCompare);
    }
    testMessage("Testing AVL -> True", avlTree(&testTree1), True);
    clearTree(&testTree1);
}

void test_complete()
{
    tree testTree1, testTree2;
    int testNum1[] = {50, 17, 72, 12, 23, 54, 76, 9, 14, 19, 67};
    int testNum2[] = {100, 50, 200, 30, 60, 150, 280};

    // test False
    newTree(&testTree1);
    printf("\nTesting complete -> false:\n");
    for(int i = 0; i < 11; i++)
    {
        recursiveInsert(&testTree1, testNum1 + i, sizeof(int), intCompare);
    }
    if (isComplete(&testTree1) == False)
    {
        printf("\t\t OK\n");
    }else
    {
        printf("\t\t ERROR\n");
    }
    clearTree(&testTree1);

    newTree(&testTree2);
    printf("\nTesting complete -> true:\n");
    for(int i = 0; i < 7; i++)
    {
        recursiveInsert(&testTree2, testNum2 + i, sizeof(int), intCompare);
    }
    if (isComplete(&testTree2) == True)
    {
        printf("\t\t OK\n");
    }else
    {
        printf("\t\t ERROR\n");
    }
    clearTree(&testTree2);
}

void test_balanced()
{
    tree testTree;
    int testNum1[] = {50, 17, 72, 12, 23, 54, 76, 9, 14, 19, 67};
    int nro;

    newTree(&testTree);

    for (int i = 0; i < 11; i++)
    {
        recursiveInsert(&testTree, testNum1 + i, sizeof(int), intCompare);
    }
    nro = 17;
    printInOrder(&testTree, intPrint);
    printf("\nDeleting 17:\n\n");
    delNode(&testTree, &nro, intCompare);
    printInOrder(&testTree, intPrint);
    nro = 72;
    printf("\nDeleting 72:\n\n");
    delNode(&testTree, &nro, intCompare);
    printInOrder(&testTree, intPrint);
    clearTree(&testTree);

}

void mainTest(void)
{

    test_recursiveInsert();
    printf(SEPARATOR);
    new_test();
    printf(SEPARATOR);
    test_avl();
    printf(SEPARATOR);
    test_complete();
    printf(SEPARATOR);
    test_balanced();

}
