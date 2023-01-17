#include <stdio.h>
#include "staticStack.h"


STACK initialize()
{
    STACK new;
    new.top = &new.vector[0];

    return new;
}



