#include <stdio.h>

#include "examen.h"

int mStrCmp(const char *a, const char *b) {
    int valor = 0;

    while(*a && *b) {
        valor = *a - *b;
        if(valor != 0) return valor;
        a++;
        b++;
    }

    // anticipo que entre la misma cadena con menos chars ej hola vs holaa
    if ( *a && !*b ) return 1;
    else if ( !*a && *b) return -1;
    else return 0;
}

int esLetra(const int letra) {
    return ( (letra <= 'z' && letra >= 'a') || (letra <= 'Z' && letra >= 'A') ) ? 1 : 0;
}

void strAppend(char *string, char letra ) {
    while(*string)  
        string++;
    
    *string = letra;
    *(string + 1) = '\0';
}

void limpiarPalabra(char *str) {
    *str = '\0';
}

void copiarPalabra(char *destino, const char *origen, int tam) {
    for(int i = 0; i < tam; i++) {
        *destino = *origen++;
        destino++;
    }

    *destino = '\0';
}

void* _bbinaria(const void *clave, const void *vec, size_t ce, size_t tam, int cmp(const void *, const void *)) {
    int medio, comparacion;
    char *ptrVec;

    medio = (int)(ce / 2);
    ptrVec = (char *)vec + (tam * medio);
    comparacion = cmp((void *)ptrVec, clave);

    if( !medio && comparacion ) return NULL;
    if( !comparacion ) return (void *)ptrVec;

    if(comparacion > 0) return _bbinaria(clave,vec, medio, tam, cmp);
    else return _bbinaria(clave,(void *)(ptrVec + tam), medio, tam, cmp);
}

int _contarPalabras(const char* nomArc, char* palMasLarga, int* cantVeces) {
    int   contadorPalabras, 
          contadorChars, 
          tamPalabraActual,
          esPalabra;
    char  auxPalabra[128], 
          letra;
    FILE *archivo;

    if( ( archivo = fopen(nomArc, "rt") ) == NULL ) {
        perror("Hubo un error al abrir el archivo.\n");
        return 0;
    }

    contadorPalabras = tamPalabraActual = contadorChars = esPalabra = 0;

    while( (letra = getc(archivo)) != EOF ) {
        if(esLetra(letra)) {
            esPalabra = 1;
            contadorChars++;
            strAppend(auxPalabra, letra);
        }else {
            if(contadorChars > tamPalabraActual) {
                tamPalabraActual = contadorChars;
                copiarPalabra(palMasLarga,auxPalabra, contadorChars);
                *cantVeces = 1;
            } else if (contadorChars == tamPalabraActual && mStrCmp(palMasLarga, auxPalabra) == 0) {
                *cantVeces += 1;
            }

            if(esPalabra) {
                contadorPalabras++;
                esPalabra = 0;
            }

            contadorChars = 0;
            limpiarPalabra(auxPalabra);
        }
    }

    fclose(archivo);

    return contadorPalabras;
}

int _sumTrianDerEntreDiag(int mat[][MAX_COL], int filas){
    int suma, medio, fila, columna;

    suma = 0;
    medio = (int) (filas / 2);
    columna = filas - 1; // coloco un puntero a la derecha
    fila = 1;
    filas -= 2;

    while(columna > medio) {
        for (int i = fila; i <= filas; i++) {
            suma += mat[fila][columna];
        }

        fila++;
        columna--;
        filas--;
    }
    return suma;
}

int _sumTrianInfEntreDiag(int mat[][MAX_COL], int filas){
    int suma, medio, fila, columna;

    suma = 0;
    medio = (int) (filas / 2);
    columna = 1; 
    fila = filas - 1; // coloco un puntero al final
    filas -= 2;
    
    while(fila > medio) {
        for (int i = columna; i <= filas; i++) {
            suma += mat[fila][columna];
        }

        fila--;
        columna++;
        filas--;
    }
    return suma;
}

int cmpEmpladoNombre(const void *a, const void *b) {
    tEmpleado *empleadoA = (tEmpleado *)a,
              *empleadoB = (tEmpleado *)b;

    return mStrCmp(empleadoA->nomYAp, empleadoB->nomYAp);
}

int cmp_enteros(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int cmp_str(const void* a, const void* b) {
    return mStrCmp((char *)a, (char *)b);
}
