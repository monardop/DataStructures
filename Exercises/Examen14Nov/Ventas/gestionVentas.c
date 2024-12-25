#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestionVentas.h"

int buscarIndiceProducto(const tProducto *vec, const int buscado, const int ce) {
    for(int i = 0; i < ce; i++) {
        if ( vec->idProducto == buscado )
        {
            return i;
        }
        vec++;
    }

    return -1;
}

int cargarProductos(tProducto *vec, char *nomArchivo) {
    FILE *archivo;
    tProducto aux;
    int cantProductos;

    if( (archivo = fopen(nomArchivo, "rb")) == NULL ) {
        perror("No pudo abrirse el archivo productos");
        exit(1);
    }

    cantProductos = 0;
    while (fread(&aux, sizeof(tProducto),1 ,archivo))
    {
        memcpy(vec, &aux, sizeof(tProducto));
        vec++;
        cantProductos++;
    }


    return cantProductos;
}

int buscarIndiceMayor(int *vec, int ce) {
    int mayor       = *vec,
        indiceMayor = 0;

    for (size_t i = 0; i < ce; i++) {
        if(mayor < *vec) {
            indiceMayor = i;
            mayor = *vec;
        }
        vec++;
    }

    return indiceMayor;
}

float ventasGeneradas(char *nombreArchivo, int *ventasTotales, const int ce) {
    float totalGenerado;
    int cantVentas[CANTPRODUCTOS],
        auxCod, auxCant;
    char buffer[20];
    FILE *archivo;

    if( (archivo = fopen(nombreArchivo, "r")) == NULL ) {
        perror("No pudo abrirse el archivo ventas");
        exit(1);
    }

    totalGenerado = 0;
    while( totalGenerado < 5 ) {
        fgets(buffer, 20, archivo);
        printf("%s\n", buffer);
        totalGenerado += 1;
    }
    fclose(archivo);

    return totalGenerado;
}
