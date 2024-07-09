#include "idexCreator.h"
#include "utilities.h"

#include <stdlib.h>

int inorderSave(tree *tp, saveFunc func, FILE* pf)
{
    if(*tp == NULL)
        return OK;
    
    inorderSave(&(*tp)->left, func, pf);
    if(func((*tp)->data, pf) != OK)
        return FILE_ERROR;
    inorderSave(&(*tp)->right, func, pf);

    return OK;
}

int createBinIndexFile(tree *tp, char *fileName, saveFunc saveFunc)
{
    FILE *index;
    int status;
    
    if((index = fopen(fileName, "wb")) == NULL)
        return FILE_ERROR;
    
    status = inorderSave(tp, saveFunc, index);

    fclose(index);
    return status;
}

int retrieveFromBin(tree *tp, void *filePointer, int start, int end, void *dataSize, readFunc read)
{
    int middle, r;
    tNode *newNode;

    middle = (start + end) / 2;
    if(start > end)
        return OK;

    if((newNode = (tNode *)malloc(sizeof(tNode))) == NULL || 
       !(newNode->dataSize = read(&(*tp)->data,filePointer,middle,dataSize)))
    {
        free(newNode);
        return MEM_FAIL;
    }

    (*tp)->left = (*tp)->right = NULL;

    if((r = retrieveFromBin(&(*tp)->left,filePointer,start,middle, dataSize,read)) != OK)
        return r;
    
    return retrieveFromBin(&(*tp)->right,filePointer,middle + 1,end, dataSize,read);
}

int readData(void **data, void* filePointer, int position, void *param)
{
    int *dataSize = (int *)param;

    if((*data = malloc(*dataSize)) == NULL)
        return MEM_FAIL;

    fseek((FILE *)filePointer, position, SEEK_SET);

    return fread(*data,*dataSize, 1, (FILE *)filePointer);
}

int loadData(tree *tp, const char *path, int dataSize)
{
    int numberRegister, r;

    FILE *pf;

    if (*tp == NULL)
        return 0;
    if((pf = fopen(path, "wb")) == NULL)
        return FILE_ERROR;
    
    fseek(pf, 0L, SEEK_END);
    numberRegister = ftell(pf) / dataSize;

    r = retrieveFromBin(tp, pf, 0, numberRegister - 1, &dataSize, readData);
    
    return r;
}