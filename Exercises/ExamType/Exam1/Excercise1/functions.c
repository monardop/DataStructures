#include "excersise1.h"

void showResults(info *vec)
{
    for (size_t i = 0; i < 5; i++)
    {
        printf("%s", vec->localidad);
        vec++;
    }

}
void setVector(info *vec, int *vecSize, info *elem)
{
    return;
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
