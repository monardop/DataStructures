#include <stdio.h>

#include "stackSorting.h"


void stackSorting(dsStack *final, char *fileName)
{
    dsStack auxStack;
    FILE *file = fopen(fileName, "rt");
    int current_number, top;

    if(!file)
    {
        printf("File name error.\n");
        return;
    }

    newStack(&auxStack);

    while (!feof(file))
    {
        fscanf(file,"%d", &current_number);
        peek(final, &top, sizeof(top));
        if(current_number > top)
        {
            append(final,&current_number, sizeof(int));
        }
        else
        {
            while (!isEmpty(final)  && current_number < top)
            {
                pop(final, &top, sizeof(top));
                append(&auxStack, &top, sizeof(top));
                peek(final, &top, sizeof(top));
            }
            append(final,&current_number, sizeof(int));
            while (!isEmpty(&auxStack))
            {
                pop(&auxStack, &top, sizeof(int));
                append(final, &top, sizeof(int));
                peek(&auxStack, &top, sizeof(top));
            }
        }  
    }
    fclose(file);
}


