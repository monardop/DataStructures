#include "utilities.h"
// reducefunctions gets returnData, newData

void redIntSum(void *vessel, void *data)
{
    int *returnData = (int *)vessel;
    int *element    = (int *)data;

    *returnData += *element; 
}

void redFloatSum(void *vessel, void *data)
{
    float *returnData = (float *)vessel;
    float *element    = (float *)data;

    *returnData += *element; 
}