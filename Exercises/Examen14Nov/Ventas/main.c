#include <stdio.h>
#include <stdlib.h>

#include "archivos.h"
#include "gestionVentas.h"

void inicializarPrueba();

int main(int argc, char *argv[])
{
    tProducto productos[CANTPRODUCTOS];
    float facturacion[5];
    int cantProdVendidos[CANTPRODUCTOS] = {0}, productosCargados;
    char archivos[5][15] = {"ventas_1.csv", "ventas_2.csv",
                            "ventas_3.csv", "ventas_4.csv",
                            "ventas_5.csv"};

    inicializarPrueba();
    productosCargados = cargarProductos(productos, PATH_ARCH_PRODUCTO);

    for (int i = 0; i < 5; i++)
    {
        facturacion[i] = ventasGeneradas("ventas_1.csv", cantProdVendidos, productosCargados);
    }




    return 0;
}


void inicializarPrueba() {
    crearArchivoProductos();
    crearArchivosVenta();
}
