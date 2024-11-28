#include <stdio.h>
#include <stdlib.h>

#include "examen.h"

typedef int (*cmp)(const void *, const void *);


int cmpINT(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int indiceParaIntercambio(const void *vec, const int ce, const void *nuevoIngreso, const int tamElem, cmp cmp) {
    char *ptrVec = (char *)vec;
    void *menorElem = malloc(tamElem);
    int pos = 0;

    memcpy(menorElem, ptrVec, tamElem);
    ptrVec += tamElem;

    for (int i = 1; i < ce; i++) {
        if( cmp(menorElem, (void *)ptrVec) > 0) {
            pos = i;
            memcpy(menorElem, ptrVec, tamElem);
        }
        ptrVec += tamElem;
    }

    if(cmp(menorElem, nuevoIngreso) > 0) pos = -1;
    free(menorElem);

    return pos;
}

void mostrarResultados(char mat[][MAXLENGHT], int ce) {
    for(int i = 0; i < ce; i++) {
        printf("Frase %d: %s\n", i + 1, mat[i]);
    }
}

void ordenarMatriz(char mat[][MAXLENGHT], int ce) {
    char *elemTempIntercambio = (char *)malloc(MAXLENGHT);
    int desordenado = 1;
    
    while( desordenado ) {
        desordenado = 0;
        for(int i= 0; i < ce - 1; i++) {
            if( strlen(mat[i]) < strlen(mat[i+1]) ) {
                strcpy(elemTempIntercambio, mat[i]);
                strcpy(mat[i], mat[i+1]);
                strcpy(mat[i+1], elemTempIntercambio);
                desordenado++;
            }
        }
        ce--;
    }

    free(elemTempIntercambio);
}

void obtener5FrasesMasLargas() {
    int  vecLongFrases[CANTFRASES] = {0},
         longFraseActual,
         pos,
         cantElem = -1;
    char frasesEncontradas[CANTFRASES][MAXLENGHT],
         fraseActual[MAXLENGHT];


    while ( obtenerFrase(fraseActual) ) {
        cantElem++;
        longFraseActual = strlen(fraseActual);
        pos = (cantElem < 5) ? cantElem : indiceParaIntercambio(vecLongFrases, CANTFRASES, &longFraseActual, sizeof(int), cmpINT);
        if( pos != -1 ) {
            strcpy(frasesEncontradas[pos], fraseActual);
            vecLongFrases[pos] = longFraseActual;
        }
    }

    ordenarMatriz(frasesEncontradas, CANTFRASES);
    mostrarResultados(frasesEncontradas, CANTFRASES);
}
