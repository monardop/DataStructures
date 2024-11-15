#include <stdio.h>
#include <stdlib.h>

#include "distancias.h"

int main()
{
    tEmbarcaciones lectura;
    FILE *archivo;
    //variables auxiliares
    char nombre[15], lat[20], lon[20], linea[50];
    tEmbarcacion *dirEncontrada;

    // inicializo lo necesario
    inicializar(&lectura);
    if ( ( archivo = fopen(PATH_ARCHIVO, "rt") ) == NULL ) {
        perror("Hubo un error al abrir el archivo.");
        exit(1);
    }

    while(!feof(archivo)) {
        if( fgets( linea, 50, archivo ) == NULL) {
            break;
        }

        desglozarLinea(linea, lon, lat, nombre);

        dirEncontrada = buscarElemento(&lectura, nombre);
        if( dirEncontrada ) modificarElemento(lat, lon, dirEncontrada);
        else {
            crearElemento(lat, lon, nombre, &lectura);
            lectura.cantElementos++;
        }
    }

    fclose(archivo);

    // muestro resultados.
    for(int i = 0; i < lectura.cantElementos; i++) {
        printf("Nombre de flota: %s. Menor distancia recorrida: %lf \n",
                lectura.enCurso[i].nombre, lectura.enCurso[i].menorDist);
    }

    return 0;
}
