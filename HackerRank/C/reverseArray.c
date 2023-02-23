// Objetivo: invertir un array
#include <stdio.h>

void invertirArray(int *, int);

int main()
{
    int arrayPrueba[10] = {0,1,2,3,4,5,6,7,8,9};
    invertirArray(&arrayPrueba, sizeof(arrayPrueba)/sizeof(int));
    return 0;
}

void invertirArray(int* v, int n)
{
    int i = n - 1;
    for (i; i >= 0; i--)
    {
        printf("%d \t", *(v + i));
    }
}