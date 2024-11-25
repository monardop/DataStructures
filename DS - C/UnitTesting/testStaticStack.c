#include <stdio.h>

#include "../Utilities/utilities.h"
#include "unitTesting.h"

#define USE_STATIC_STACK
#include "../Stack/StackDataStructure.h"


int test_isFull(dsStack *test) //2 test
{
    int fails = 0;
    printf("Testing isFull false...");
    if(!isFull(test,20))
    {
        PASS;
    }
    else
    {
        FAIL;
        fails++;
    }
    printf("Testing isFull true...");
    if(isFull(test,2000))
    {
        PASS;
    }
    else
    {
        FAIL;
        fails++;
    }
    return fails;
}


int test_isEmpty(dsStack *test, int expected) // 1 test x llamado
{
    int result = isEmpty(test);

    printf("Testing isEmpty...");
    if(result == expected)
    {
        PASS;
        return 0;
    }
    else
    {
        FAIL;
        return 1;
    }
}


int test_append(dsStack *test)
{
    int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
    int i=0;

    printf("Testing append...");
    for(i = 0; i < 10; i++)
    {
        if(!append(test, (numbers + i), sizeof(int)))
        {
            FAIL;
            return 1;
        }
    }

    PASS;
    return 0;
}


int test_peeknpop(dsStack *test)
{
    int numbers[] = {9,8,7,6,5,4,3,2,1,0};
    int i=0;
    int auxElement;

    printf("Testing pop...");
    for(i = 0; i < 10; i++)
    {
        if(!peek(test, &auxElement, sizeof(int))){
            FAIL;
            return 1;
        }
        if(!pop(test, &auxElement, sizeof(int))){
            FAIL;
            return 1;
        }
        if(auxElement != numbers[i])
        {
            FAIL;
            return 1;
        }
    }
    PASS;
    return 0;
}


void testStaticStack(void){
    dsStack test;
    int fails = 0, testCases = 0;

    printf("\nTesting static stack implementation.\n");
    newStack(&test);
    fails += test_isFull(&test);
    testCases +=2;
    fails += test_isEmpty(&test, 1);
    testCases++;

    if(test_append(&test))
    {
        printf("An error had ocurred. \n %d cases, %d fails", ++testCases, ++fails);
    }
    else
    {
        testCases++;
    }

    fails += test_isEmpty(&test, 0);
    testCases++;

    if(test_peeknpop(&test))
    {
        printf("An error had ocurred. \n %d cases, %d fails", ++testCases, ++fails);
    }
    else
    {
        testCases++;
    }

    clear(&test);

    fails += test_isEmpty(&test, 1);
    testCases++;

    printf("Executed test: %d. Errors: %d\n", testCases, fails);
}
