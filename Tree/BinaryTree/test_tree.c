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
    printf("\n\n Inorder: \n\t");
    printInOrder(&testTree, intPrint);
    
    clearTree(&testTree);

    return OK;
}

void test_avl()
{
    tree testTree1, testTree2;
    int testNum1[] = {50, 17, 76, 9, 23, 54, 72, 67, 14, 19, 12};
    int testNum2[] = {50, 17, 72, 12, 23, 54, 76, 9, 14, 19, 67};

    // test False
    newTree(&testTree1);
    printf("\nTesting AVL false:\n");
    for(int i = 0; i < 11; i++)
    {
        recursiveInsert(&testTree1, testNum1 + i, sizeof(int), intCompare);
    }
    if (avlTree(&testTree1) == False)
    {
        printf("\t\t OK\n");
    }else
    {
        printf("\t\t ERROR\n");
    }
    clearTree(&testTree1);
    
    newTree(&testTree2);
    printf("\nTesting AVL true:\n");
    for(int i = 0; i < 11; i++)
    {
        recursiveInsert(&testTree2, testNum2 + i, sizeof(int), intCompare);
    }
    if (avlTree(&testTree2) == True)
    {
        printf("\t\t OK\n");
    }else
    {
        printf("\t\t ERROR\n");
    }
    clearTree(&testTree2);
    
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
    if (avlTree(&testTree1) == False)
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
    if (avlTree(&testTree2) == True)
    {
        printf("\t\t OK\n");
    }else
    {
        printf("\t\t ERROR\n");
    }
    clearTree(&testTree2);
}

void mainTest(void)
{
    printf("Testing recursive insert: \n");
    test_recursiveInsert();
    new_test();
    test_avl();
    test_complete();
}