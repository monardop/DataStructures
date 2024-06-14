#include "excersise1.h"

void showResults(info *vec, int vecSize)
{
    printf("--------------------------------------------------------------\n");
    for (size_t i = 0; i < vecSize; i++)
    {
        printf("%s - %f\n", vec[i].localidad, vec[i].sup);
    }
    printf("--------------------------------------------------------------\n");
}

void moveRight(info *vec, int changes)
{
    for (size_t i = 4; i > changes; i--)
    {
        vec[i] = vec[i - 1];
    }
}

void setVector(info *vec, int *vecSize, info *elem)
{
    int i = 0;

    while (i < 5 && i < *vecSize)
    {
        if(vec[i].sup < elem->sup)
        {
            moveRight(vec, i);
            vec[i] = *elem;
            if(*vecSize < 5)
                *vecSize += 1;
            return;
        }
        i++;

    }
    if(*vecSize < 5)
    {
        vec[*vecSize] = *elem;
        *vecSize += 1;
        return;
    }
}

int ex1Main(info *vec, char *fileName)
{
    FILE *reg;
    int   vecSize = 0;
    info  auxElem;
    char buffer[100];


    reg = fopen(fileName, "rb");

    if(!reg)
        return 0;

    while(fgets(buffer, sizeof(buffer), reg) != NULL)
    {

        sscanf(buffer,"%2d %50s %f %4d", &auxElem.prov, auxElem.localidad, &auxElem.sup, &auxElem.population);
        setVector(vec, &vecSize, &auxElem);
    }

    fclose(reg);

    return vecSize;
}
