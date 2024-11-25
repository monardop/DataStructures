#ifndef IDEXCREATOR_H
#define IDEXCREATOR_H

    #include <stdio.h>

    #include "treeInterface.h"

    typedef int (*saveFunc)(const void *, FILE*);
    typedef int (*readFunc)(void **, void*, int, void* parameter);

    int createBinIndexFile(tree *tp, char *fileName, saveFunc saveFunc);


#endif // IDEXCREATOR_H
