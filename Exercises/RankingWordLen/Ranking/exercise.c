#include "interface.h"

int esLetra(int letra) {
    return ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z') ) ? 1 : 0;
}

void anexarLetra(int letra, char *palabra) {
    while(*palabra) {
        palabra++;
    }
    *palabra = letra;
     palabra++;
    *palabra = '\0';
}

void borrarPalabra(char *palabra) {
    *palabra = '\0';
}

int menorPosicion(int *vec, int valActual, int ce) {
    //devuelve -1 si no existe
    for( int i = 0; i < ce; i++ ) {
        if(*vec < valActual) {
            return i;
        }
        vec++;
    }

    return -1;
}

int buscarMax(int *vec, int ce) {
    int max = -1, pos = -1;

    for(int i = 0; i < ce; i++) {
        if(*vec > max) {
            max = *vec;
            pos = i;
        }
        vec++;
    }

    return pos;
}

void ordenarVectores(char mat[][20], int *vectorPos, int ce) {
    char *elemAux = malloc(sizeof(char) * 20);
    int pos; 

    for (size_t i = 0; i < ce; i++) {
        pos = buscarMax(vectorPos, ce);
        if(pos != i) {
            memcpy(elemAux, mat[pos], 20);
            memcpy(mat[pos], mat[i], 20);
            memcpy(mat[i], elemAux, 20);
        } 
        vectorPos[pos] = 0;
    }

    free(elemAux);
}

void procesarPalabras(char rank[][20], char *path) {
    FILE *arch;
    char buffer[20], letra;
    int longPalabras[3] = {0, 0, 0}, 
        contador        =  0,
        posicion;

    if( ( arch = fopen(FILE_LOCATION, "r") ) == NULL ) {
        perror("Error al abrir el archivo.\n");
        exit(1);
    }

    while ( (letra = fgetc(arch)) != EOF ) {
        if(esLetra(letra)) {
            contador++;
            anexarLetra(letra, buffer);
        } else {
            posicion = menorPosicion(longPalabras, contador, 3);
            if( posicion != -1 ) {
                longPalabras[posicion] = contador;
                strcpy(rank[posicion], buffer);
            }
            contador = 0;
            borrarPalabra(buffer);
        }
    }
    fclose(arch);

    ordenarVectores(rank, longPalabras, 3);

}