#ifndef STATICQUEUE_H
#define STATICQUEUE_H

    #include "../../Utilities/utilities.h"

    typedef struct
    {
        char queue[STATIC_ELEMENTS];
        unsigned head, rear, freeSpace;
    }dsQueue;

#endif // COLAESTATICA_H