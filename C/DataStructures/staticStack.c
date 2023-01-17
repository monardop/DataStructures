#include <stdio.h>
#include "staticStack.h"


STACK initializeStack()
{
    STACK new;
    new.top = 0;
    return new;
}


int is_full(STACK *stack)
{
    return stack->top + 1 == 10;
}


void push(STACK *stack, int number)
{
    if(!is_full(stack))
    {
        stack->top++;
        stack->vector[stack->top] = number;
    }
    else
    {
        printf("You can't push more elements, stack full.\n");
    }
}


void peack(STACK *stack)
{
    printf("%d\n", stack->vector[stack->top]);
}


void pop(STACK *stack)
{
    if(stack->top != 0)
    {
        peack(stack);
        stack->top--;
    }
    else
    {
        printf("Stack empty.\n");
    }
}
