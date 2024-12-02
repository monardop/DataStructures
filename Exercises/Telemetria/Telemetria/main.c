#include <stdio.h>
#include <stdlib.h>

#include "resolucion.h"

int main() {
    FILE *informe;
    int cantidadReportes;
    tVehiculo vehiculoTemp;
    tReporte reportes[MAXVEHICULOS];
    char buffer[45];

    // ------

    if( (informe = fopen(INFORME_PATH, "rt")) == NULL ) {
        perror("Hubo un error en el archivo.");
        exit(1);
    }

    cantidadReportes = 0;

    while( fgets(buffer, 45, informe) ) {
        desglosarLinea(&vehiculoTemp, buffer);
        generarReporte(vehiculoTemp, reportes, &cantidadReportes);
    }

    fclose(informe);
    ordenarVector(reportes, sizeof(tReporte), cantidadReportes);

    for(int i = 0; i < cantidadReportes; i++) {
        if(reportes[i].reportesValidos > 0) {
            printf("%s\t%.2f\n", reportes[i].dominio,
                        reportes[i].kmRecorridos / reportes[i].litrosConsumidos);
        } else {
            printf("%s\t-Reportes no validos, requiere inspeccion manual-\n", reportes[i].dominio);
        }
    }

    return 0;
}
