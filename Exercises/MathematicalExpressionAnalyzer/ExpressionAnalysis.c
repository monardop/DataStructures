#include "expressionAnalysis.h"
#include <stdio.h>

void expressionAnalysis(dsStack *stack, char *fileName)
{
    FILE *expression;
    char buffer, top;

    expression = fopen(fileName, "rt");

    while (!feof(expression))
    {
        buffer = fgetc(expression);

        if(buffer == '{' || buffer == '[' || buffer == '(')
        {
            append(stack, &buffer, sizeof(buffer));
            top = buffer;
        }

        if(buffer == '}' && top == '{')
        {
            pop(stack, &top, sizeof(top));
            peek(stack, &top, sizeof(top));
        }
        if(buffer == ']' && top == '[')
        {
            pop(stack, &top, sizeof(top));
            peek(stack, &top, sizeof(top));
        }
        if(buffer == ')' && top == '(')
        {
            pop(stack, &top, sizeof(top));
            peek(stack, &top, sizeof(top));
        }
    }
    
    fclose(expression);

}

int isCorrect(char *fileName)
{   
    dsStack myStack;
    newStack(&myStack);

    expressionAnalysis(&myStack, fileName);
    if(isEmpty(&myStack))
    {
        printf("Correct expression");
        return 1;
    }
    else
    {
        printf("The expression is incorrect");
        clearStack(&myStack);
        return 0;   
    }
}
