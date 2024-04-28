#include <stdio.h>

void *memoryCopy(void *dest, const void *src,  unsigned size)
{
    const unsigned char *source = (const unsigned char*)src;
    char unsigned *destination = (unsigned char*)dest;

    for(unsigned i = 0; i < size; i++) {
        destination[i]  = source[i];
    }
    return destination;
}

int memoryCompare(const char *elementA, const char *elementB, unsigned bytes)
 {
    const char *a = (const char *)elementA;
    const char *b = (const char *)elementB;

    for(unsigned i = 0; i < bytes; i++) {
        if(*a != *b){
            return 0;
        }
        a++;
        b++;
    }
    return 1;
}

int strLen(const char *str)
{
    const char *pStr = str;
    while (*pStr++);
    return pStr - str - 1;
}

int intCompare(void *elemenA, void *elementB)
{
    int *a = (int *)elemenA;
    int *b = (int *)elementB;

    return *a - *b;
}

int strCompare(void *elementA, void *elementB)
{
    char *a = (char *)elementA;
    char *b = (char *)elementB;

    int comparison = 0;

    while (*a)
    {
        comparison += *a;
        a++;
    }
    while (*b)
    {
        comparison -= *b;
        b++;
    }

    return comparison;
}

int floatCompare(void *elementA, void *elementB)
{
    float *a = (float *)elementA;
    float *b = (float *)elementB;
    return (int)(*a - *b);
}

void intPrint(void* number)
{
    int *x = (int *)number;
    printf("\t%d", *x);
}

void floatPrint(void* number)
{
    float *x = (float *)number;
    printf("\t%f", *x);
}

void strPrint(void* string)
{
    char *x = (char *)string;
    printf("\t%s", x);
}
