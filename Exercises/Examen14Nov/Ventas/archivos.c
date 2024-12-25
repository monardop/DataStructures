#include <stdio.h>
#include <stdlib.h>

#include "archivos.h"

void crearArchivoProductos() {
    FILE *arch;
    tProducto vec[] = {
        {2, "Leche", "Lacteos", 0.99, 30},
        {5,"Yogurt", "Lacteos", 1.10, 10},
        {1, "Manzanas", "Frutas", 1.25,50},
        {4,"Jugo de Naranja", "Bebidas", 1.50, 25},
        {3, "Pan", "Panaderia",2.5,20}
    };

    if( (arch = fopen(PATH_ARCH_PRODUCTO, "wb")) == NULL ) {
        perror("No pudo abrirse el archivo");
        exit(1);
    }

    fwrite(vec, sizeof(tProducto), 5, arch);
    fclose(arch);
}

void crearVentaLocal(char *nomArchivo, int ventas[][2], int cElementos) {
    FILE *arch;
    if( (arch = fopen(nomArchivo, "wt")) == NULL ) {
        perror("No pudo abrirse el archivo ventas");
        exit(1);
    }
    for(int i = 0; i < cElementos; i++) {
        fprintf(arch, "%d, %d\n", ventas[i][0], ventas[i][1]);
    }
    fclose(arch);
}

void crearArchivosVenta() {
    char archivos[5][20] = {"ventas_1.csv", "ventas_2.csv",
    "ventas_3.csv", "ventas_4.csv", "ventas_5.csv"};
    int ventas1[4][2] = {{1,10},{2,5},{3,15},{5,2}},
        ventas2[4][2] = {{1,5},{3,10},{4,8},{5,3}},
        ventas3[4][2] = {{1,8},{2,10},{3,7},{4,5}},
        ventas4[4][2] = {{2,8},{3,6},{4,10},{5,4}},
        ventas5[4][2] = {{1,7},{2,12},{3,5},{4,2}};

    crearVentaLocal(archivos[0], ventas1, 4);
    crearVentaLocal(archivos[1], ventas2, 4);
    crearVentaLocal(archivos[2], ventas3, 4);
    crearVentaLocal(archivos[3], ventas4, 4);
    crearVentaLocal(archivos[4], ventas5, 4);
}

void mostrarArchivo() {
    FILE *arch;
    tProducto aux;

    if( (arch = fopen(PATH_ARCH_PRODUCTO, "rb")) == NULL ) {
        perror("No pudo abrirse el archivo");
        exit(1);
    }

    for(int i = 0; i < 5; i++) {
        fread(&aux, sizeof(tProducto), 1, arch);
        printf("%d %s\n", aux.idProducto, aux.nombreProducto);
    }
    fclose(arch);
}
