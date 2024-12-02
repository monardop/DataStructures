#ifndef RESOLUCION_H
#define RESOLUCION_H

typedef struct {
    char  dominio[8];
    float litrosConsumidos,
          kmRecorridos;
    int   reportesValidos;
}tReporte; 

typedef struct {
    char fechaHora[13],
         dominio[8],
         kmRecorridos[7],
         litrosConsumidos[7],
         estadoReporte[11];
}tVehiculo;

#define MAXVEHICULOS 50 
#define INFORME_PATH "./Telemetria.txt"

void desglosarLinea(tVehiculo *aux, char *linea);
void generarReporte(tVehiculo entrante, tReporte *vector, int *ce);
void ordenarVector(void *vec, unsigned tamElem, int cantElementos);

#endif