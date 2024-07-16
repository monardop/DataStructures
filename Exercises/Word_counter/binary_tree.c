#include <stdlib.h>
#include <string.h>

#include "binary_tree.h"

void initializeTree(Tree *tp) {
    *tp = NULL;
}

int emptyTree(Tree *tp) {
    return *tp == NULL;
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

    showDescendant(&(*tp)->right, print);
    print((*tp)->data);
    showDescendant(&(*tp)->left, print);
}

const Tree *minElement(const Tree *tp, const Tree *lower, cmp cmp) {
    if(*tp == NULL)
        return lower;
    
    if(cmp((*tp)->data, (*lower)->data) > 0) {
        lower = tp;
    }

    lower = minElement(&(*tp)->left, lower, cmp);    
    lower = minElement(&(*tp)->right, lower, cmp);    

    return lower;
}

int minFunction(const Tree *tp, cmp compare, void *container) {
    const Tree *lower = tp;
    if(*tp == NULL)
        return 0;
    
    lower = minElement(&(*tp)->left, lower, compare);
    lower = minElement(&(*tp)->right, lower, compare);

    memcpy(container, (*lower)->data, (*lower)->dataSize);

    return 1;
}

const Tree *maxElement(const Tree *tp, const Tree *lower, cmp cmp) {
    if(*tp == NULL)
        return lower;
    
    if(cmp((*tp)->data, (*lower)->data) < 0) {
        lower = tp;
    }

    lower = maxElement(&(*tp)->left, lower, cmp);    
    lower = maxElement(&(*tp)->right, lower, cmp);    

    return lower;
}

int maxFunction(const Tree *tp, cmp compare, void *container) {
    const Tree *lower = tp;
    if(*tp == NULL)
        return 0;
    
    lower = maxElement(&(*tp)->left, lower, compare);
    lower = maxElement(&(*tp)->right, lower, compare);

    memcpy(container, (*lower)->data, (*lower)->dataSize);

    return 1;
}



/******************************************************************************
* This function will print the lower or max element (not key) 
* @param cmp is the lower or max function. 
* @param print shows the obtained element.
* @param mode '1' for max, '0' for min.
* @return OK or EMPTY
******************************************************************************/

int  showMinMaxValue(Tree *tp, cmp compare, action print, int mode, void *container) {
    
    if(*tp == NULL)
        return EMPTY;

    if(mode == 1) {
        maxFunction(tp, compare, container);
    }else {
        minFunction(tp, compare, container);
    }

    print(container);
    
    return OK;
}