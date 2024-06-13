#include "excersise1.h"

void showResults(info *vec)
{
    for (size_t i = 0; i < 5; i++)
    {
        printf("%s", vec->localidad);
        vec++;
    }
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
        if(vec->sup < elem->sup)
        {
            moveRight(vec, i);
            vec[i] = *elem;
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

info *ex1Main(info *vec, char *fileName)
{
    FILE *reg;
    int   vecSize = 0;
    info  auxElem;

    reg = fopen(fileName, "rb");

    if(!reg)
        return NULL;

    while(!feof(reg))
    {
        fscanf(reg, "%2d %50s %f %4d",
               &auxElem.prov, &auxElem.localidad, &auxElem.sup,
               &auxElem.population);

        setVector(vec, &vecSize, &auxElem);
    }

    fclose(reg);
    showResults(vec);

    return vec;
}
