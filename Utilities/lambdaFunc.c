#include "utilities.h"
#include <stdlib.h>

void intSquare(void *element)
{
    int *newElement = (int *)element;
    *newElement *= *newElement;
}
