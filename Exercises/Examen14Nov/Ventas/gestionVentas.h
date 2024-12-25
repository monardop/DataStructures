#ifndef VENTAS_H
#define VENTAS_H

    #define CANTPRODUCTOS 5

    typedef struct {
        int idProducto;
        char nombreProducto[50],
             categoria[20];
        float precio;
        int stock;
    }tProducto;

    int cargarProductos(tProducto *vec, char *nomArchivo);
    float ventasGeneradas(char *nombreArchivo, int *ventasTotales, const int ce);

#endif 