#include <stdio.h>
#include <stdlib.h>
#include "stackSorting.h"

int testing(char *, char *);


int main()
{
    int errors = 0;
    printf("Executing testing:\n");
    errors += testing("txtFiles/Case1.txt", "Testing case1:\n");
    errors += testing("txtFiles/Case2.txt", "Testing case2:\n");
    printf("All cases done! %d errors", errors);
    return 0;
}

int testing(char* fileName, char *msj)
{
    dsStack sortedStack;
    int top, lastTop;

    newStack(&sortedStack);
    stackSorting(&sortedStack, fileName);

    pop(&sortedStack, &lastTop, sizeof(int));

    printf(msj);
    for (int i = 0; i < 20; i++)
    {
        pop(&sortedStack, &top, sizeof(int));
        if(top > lastTop)
        {
             printf("\t\t Not sorted.\n");
             clear(&sortedStack);
             return 1;
        }
        lastTop = top;
    }
    printf("\t\t OK\n");
    return 0;
}
