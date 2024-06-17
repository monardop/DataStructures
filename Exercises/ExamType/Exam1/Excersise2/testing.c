#include <stdio.h>
#include <string.h>
#include "excersise2.h"

typedef struct 
{
    int cod;
    char name[50];
}tProduct;


void print(void *data)
{
    int *d = (int *)data;
    printf(" %d ", *d);
}

int comparation(void *a, void *b)
{
    int *f = (int *)a; 
    int *l = (int *)b;
    return *f - *l; 
}

int cmpProduct(void *a, void *b)
{
    tProduct *f = (tProduct *)a; 
    tProduct *l = (tProduct *)b;
    return f->cod - l->cod; 
}

int cmpStrings(void *a, void *b)
{
    tProduct *f = (tProduct *)a; 
    char *l = (char *)b;
    return strcmp(f->name, l);
}

void printProduct(void *data)
{
    tProduct *d = (tProduct *)data;
    printf("%d - %s\n", d->cod, d->name);
}

void test_tree()
{
    tree test;
    int testNum[] = {8,3,10,1,6,14,4,7,13};
    newTree(&test);

    for(int i = 0; i < 8; i++)
    {
        addNode(&test,testNum + i, sizeof(int), comparation);
    }
    inorder(&test, print);
    clearTree(&test);
}

void test_products()
{
    tree test;
    tNode *foundProduct;
    char *strSearched = "Tijeras";
    tProduct testP[] = {{22, "Ultra"}, {32, "Peine"}, {78, "Microfono"},
                        {50, "Tijeras"}, {40, "Calculadora"}, {10,"Lapiz"}};
    newTree(&test);

    for(int i = 0; i < 5; i++)
    {
        addNode(&test,testP + i, sizeof(tProduct), cmpProduct);
    }
    inorder(&test, printProduct);
    foundProduct = searchNotKey(&test, strSearched, cmpStrings);
    if(foundProduct == NULL)
        printf("\n\tProduct not found");
    else
    {
        printf("Product found.\n");
    }
    
    clearTree(&test);
}

void ex2_testing() 
{
    printf("Testing tree: \n");
    test_tree();
    printf("\nTesting structs: \n");
    test_products();
}

