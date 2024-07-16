#include <stdlib.h>
#include <string.h>

#include "binary_tree.h"

void initializeTree(Tree *tp) {
    *tp = NULL;
}

void cleanTree(Tree *tp) {
    if(*tp == NULL)
        return;
    
    cleanTree(&(*tp)->left);
    cleanTree(&(*tp)->right);

    free((*tp)->data);
    free(*tp);
    *tp = NULL;
}

/******************************************************************************
* This function will add a new node if it does not exist, 
* or apply a function to the corresponding element if it is duplicated.
* @param cmp is a function that compares 2 elements. 
* @param action reciebe the duplicated node and process it.
* @return OK or MEM_ERROR
******************************************************************************/
Node *createNode(void *newData, unsigned dataSize) {
    Node *newNode;
    
    if((newNode = (Node *)malloc(sizeof(Node))) == NULL || (newNode->data = malloc(dataSize)) == NULL) {
        free(newNode);
        return NULL;
    }
    memcpy(newNode->data, newData, dataSize);
    newNode->dataSize = dataSize;
    newNode->right    = newNode->left = NULL; 

    return newNode;
}

int  newElement(Tree *tp, void *newData, unsigned dataSize, cmp compare, action function) {
    Node *newNode;
    int comparison;

    if(*tp == NULL) {
        newNode = createNode(newData, dataSize);
        if(!newNode)
            return MEM_ERROR;
        *tp = newNode;
        return OK;
    }

    comparison = compare((*tp)->data, newData);

    if(comparison == 0) {
        function((*tp)->data);
        return OK;
    }else if(comparison > 0) {
        return newElement(&(*tp)->left, newData, dataSize,compare,function);
    }else {
        return newElement(&(*tp)->right, newData, dataSize,compare,function);
    }
}

void showAscendent(Tree *tp, action print) {
    if(*tp == NULL)
        return;

    showAscendent(&(*tp)->left, print);
    print((*tp)->data);
    showAscendent(&(*tp)->right, print);
}

void showDescendant(Tree *tp, action print) {
    if(*tp == NULL)
        return;

    showDescendant(&(*tp)->left, print);
    print((*tp)->data);
    showDescendant(&(*tp)->right, print);
}

void *minFunction(Tree *tp, cmp compare, void *currentMin) {
    if(*tp == NULL)
        return NULL;
    
    minFunction(&(*tp)->left,compare, currentMin);
    minFunction(&(*tp)->right,compare, currentMin);
    if(compare((*tp)->data, currentMin) <  0) {
        return (*tp)->data;
    }
    return currentMin;
}

void *maxFunction(Tree *tp, cmp compare, void *currentMax) {
    if(*tp == NULL)
        return NULL;
    
    maxFunction(&(*tp)->left,compare, currentMax);
    maxFunction(&(*tp)->right,compare, currentMax);
    if(compare((*tp)->data, currentMax) >  0) {
        return (*tp)->data;
    }
    return currentMax;
}

/******************************************************************************
* This function will print the lower or max element (not key) 
* @param cmp is the lower or max function. 
* @param print shows the obtained element.
* @param mode '1' for max, '0' for min.
* @return OK or EMPTY
******************************************************************************/

int  showMinMaxValue(Tree *tp, cmp compare, action print, char mode) {
    void *auxElement = (*tp)->data;

    if(*tp == NULL)
        return EMPTY;

    if(mode == '1') {
        auxElement = maxFunction(tp, compare, auxElement);
    }else {
        auxElement = minFunction(tp, compare, auxElement);
    }

    print(auxElement);
    
    return OK;
}