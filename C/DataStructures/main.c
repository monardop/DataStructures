#include <stdio.h>
#include <stdlib.h>
#include "staticStack.h"

int main()
{
    STACK new;
    new = initialize();
    printf("%d\n", new.top);
    push(&new, 6);
    push(&new, 8);
    push(&new, 3);
    push(&new, 2);
    push(&new, 6);
    push(&new, 56);
    push(&new, 46);
    push(&new, 26);
    push(&new, 76);
    push(&new, 7);
    printf("%d \n", new.top);
    pop(&new);
    pop(&new);
    pop(&new);

    return 0;
}
