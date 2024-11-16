#include <stdlib.h>
#include <string.h>

#include "funciones.h"

typedef int (*cmp)(const void*, const void*);

void slice(const char *line, char *cod, char *temperature, char *status) {
    char *ptr = strchr(line, '\n');
    strncpy(status, ptr - 12, 12l);
    strncpy(temperature, ptr - 18, 6l);
    strncpy(cod, ptr - 26, 8l);
}

void *search(tComponent *vector, char *code, unsigned vecSize) {
    for (size_t i = 0; i < vecSize; i++) {
        if(strcmp(vector->code, code) == 0)
            return vector;
        vector++;
    }

    return NULL;
}


void componentAppend(tComponent *vec, unsigned vecSize, char *temperature, char *code, int status) {
    tComponent tempComponent;

    strcpy(tempComponent.code, code);

    if(status) {
        tempComponent.temperature = atof(temperature);
        tempComponent.registers = 1;
    } else {
        tempComponent.temperature = 0;
        tempComponent.registers = 0;
    }

    vec[vecSize] = tempComponent;
}

int   isOK(char *status) {
    return ( strstr(status, "READY") ) ? 1 : 0;
}

void addRegister(tComponent *component, char *temperature) {
    double tempTemperature = atof(temperature);
    component->temperature += tempTemperature;
    component->registers++;
}

void setMedia(tComponent *vec, unsigned vecSize) {
    for (size_t i = 0; i < vecSize; i++) {
        if(vec->registers != 0) {
            vec->temperature /= (double)vec->registers;
        }
        vec++;
    }
}

void setSortedVector(void *vec, unsigned vecSize, size_t elemSize, cmp cmp) {
    short isSorted = 0;
    char *tempVec = (char *)vec;
    void *tempVar = malloc(elemSize);

    while( !isSorted ) {
        isSorted = 1;
        tempVec = (char *)vec;
        
        for(int i = 0; i < vecSize - 1; i++) {
            if( cmp((void *)tempVec, (void *)(tempVec + elemSize)) > 0 ) {
                memcpy(tempVar, (void*)tempVec, elemSize);
                memcpy((void*)tempVec, (void*)(tempVec + elemSize), elemSize);
                memcpy((void*)(tempVec + elemSize), tempVar, elemSize);
                isSorted = 0;
            }
            tempVec += elemSize;
        }
        vecSize--;
    }

    free(tempVar);
}

int codeCMP(const void *a, const void *b) {
    tComponent *first = (tComponent *)a,
               *second = (tComponent *)b;

    return strcmp(first->code, second->code);
}

void getSortedVector(tComponent *vec, unsigned vecSize, unsigned elemSize) {
    setSortedVector((void *)vec, vecSize, elemSize, codeCMP);
}
