#include "testing.h"
#include <stdio.h>

int test_recursiveInsert()
{
    tree test;
    int num[] = {100, 50, 200, 25, 75, 80, 50};

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

    clearTree(&test);

    return OK;
}



void mainTest(void)
{
    printf("Testing recursive insert: \n");
    test_recursiveInsert();

}