#include <stdlib.h>
#include <string.h>

#include "resolucion.h"

typedef int (*cmp)(const void *, const void *);

char *obtenerElementos(char *ptrLinea, int nroPos, char *dst) {
    ptrLinea -= nroPos;
    strcpy(dst, ptrLinea);
    *ptrLinea = '\0';
    return ptrLinea;
}

void desglosarLinea(tVehiculo *aux, char *linea) {
    char* ptrLinea; 

    ptrLinea = strchr(linea, '\n');
    *ptrLinea = '\0';
    ptrLinea = obtenerElementos(ptrLinea, 10, aux->estadoReporte);
    ptrLinea = obtenerElementos(ptrLinea, 6, aux->litrosConsumidos);
    ptrLinea = obtenerElementos(ptrLinea, 6, aux->kmRecorridos);
    ptrLinea = obtenerElementos(ptrLinea, 7, aux->dominio);
    ptrLinea = obtenerElementos(ptrLinea, 12, aux->fechaHora);
}

int cmpReportes(const void *a, const void *b) {
    tReporte *elemA = (tReporte *)a,
             *elemB = (tReporte *)b;

    return strcmp(elemA->dominio, elemB->dominio); 
}

void *buscarElemento(const void *vec, const void *elemBuscado, unsigned ce, unsigned tamElem,  cmp cmp) {
    char *ptrVector = (char *)vec;

    for(int i = 0; i < ce; i++) {
        if(cmp((void *)ptrVector, elemBuscado) == 0)
            return (void *)ptrVector;
        ptrVector += tamElem;
    }

    return NULL;
}

void generarReporte(tVehiculo entrante, tReporte *vector, int *ce) {
    tReporte *encontrado, nuevoAux; 
    int esReporteValido;

    encontrado = buscarElemento(vector, entrante.dominio, *ce, sizeof(tReporte), cmpReportes);

    esReporteValido = ( strstr(entrante.estadoReporte, "VALID") )? 1 : 0;

    nuevoAux.kmRecorridos     = atof(entrante.kmRecorridos);
    nuevoAux.litrosConsumidos = atof(entrante.litrosConsumidos);

    if( encontrado && esReporteValido ) {
        encontrado->kmRecorridos += nuevoAux.kmRecorridos;
        encontrado->litrosConsumidos += nuevoAux.litrosConsumidos;
        encontrado->reportesValidos += 1;
        return;
    }

    if(!encontrado) {
        strcpy(nuevoAux.dominio, entrante.dominio);
        nuevoAux.reportesValidos = 1;
        if( !esReporteValido ) {
            nuevoAux.kmRecorridos = 0;
            nuevoAux.litrosConsumidos = 0;
            nuevoAux.reportesValidos = 0;
        }
        *(vector + *ce) = nuevoAux;
        *ce += 1;
        return; 
    }
}

void ordenarVector(void *vec, unsigned int tamElem, int cantElementos) {
    qsort(vec,cantElementos,tamElem, cmpReportes);
}