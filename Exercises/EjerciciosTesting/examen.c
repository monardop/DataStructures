#include <stdlib.h>
#include <string.h>

#include "examen.h"

void* _ordenarSeleccion(void* vec, int ce, unsigned tam, int cmp(const void*, const void*)) {
    void *memAux; // posición auxiliar para el intercambio en caso de desorden.
    char *punteroVector;
    int i, vectorOrdenado;

    vectorOrdenado = 0;
    if((memAux = malloc(tam)) == NULL ) {
        exit(1);
    }

    while (vectorOrdenado == 0) {
        vectorOrdenado = 1;
        punteroVector = (char *)vec; // creo un puntero al inicio del vector
        
        for (i = 0; i < ce - 1; i++) {
            if( cmp((void *)punteroVector, (void *)(punteroVector + tam)) > 0 ) {
                memcpy(memAux, (void *)punteroVector, tam);
                memcpy((void *)punteroVector, (void *)(punteroVector + tam), tam);
                memcpy((void *)(punteroVector + tam), memAux, tam);

                vectorOrdenado = 0;
            }

            punteroVector += tam;
        }
        ce--; // por cada vuelta, el último elemento está ordenado
    }
    
    return vec;
}

int _cmpEmpleadoNombre(const void *a, const void *b) {
    tEmpleado *empleadoA = (tEmpleado *)a,
              *empleadoB = (tEmpleado *)b;
    
    return strcmp(empleadoA->nomYAp, empleadoB->nomYAp);
}

int _cmp_enteros(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int _cmp_str(const void* a, const void* b) {
    return strcmp((char *)a, (char *)b);
}

char* _mstrstr(const char *s1, const char *s2) {
    const char *punteroPalabra, *inicioBuscado;

    if(*s2 == '\0') return (char *)s1;

    while (*s1) {
        punteroPalabra = s2;

        if(*s1 == *punteroPalabra){
            inicioBuscado = s1;
            while(*s1 == *punteroPalabra) {
                s1++;
                punteroPalabra++;
                if(*punteroPalabra == '\0') {
                    return (char *)inicioBuscado;
                }
            }
        }

        s1++;
    }

    return NULL;
}

int _contarCelulasVivasEnVecindario(int mat[][MAX_COL], int filas, int columnas, int fila, int columna) {
    int sumatoria    = 0, 
        hayDerecha   = 0, 
        hayIzquierda = 0; // estas últimas dos son para no sumar por duplicado.

    if (columna - 1 >= 0) {
            sumatoria += mat[fila][columna - 1];
            hayIzquierda = 1;
    }

    if (columna + 1 < columnas) {
            sumatoria += mat[fila][columna + 1];
            hayDerecha = 1;
    }

    if(fila - 1 >= 0) {
        sumatoria += mat[fila - 1][columna];

        if (hayIzquierda) sumatoria += mat[fila - 1][columna - 1];
        if (hayDerecha)   sumatoria += mat[fila - 1][columna + 1];
    }

    if(fila + 1 < filas) {
        sumatoria += mat[fila + 1][columna];

        if (hayIzquierda) sumatoria += mat[fila + 1][columna - 1];
        if (hayDerecha)   sumatoria += mat[fila + 1][columna + 1];
    }

    return sumatoria;
}  
