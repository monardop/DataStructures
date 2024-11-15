#ifndef DISTANCIAS_H
#define DISTANCIAS_H

typedef struct {
    double latActual,
           longActual,
           menorDist;
    char   nombre[15];
}tEmbarcacion;

typedef struct {
    tEmbarcacion enCurso[20];
    unsigned cantElementos;
}tEmbarcaciones;

#define PATH_ARCHIVO "./embarcaciones.csv"

void  inicializar(tEmbarcaciones *vec);
void *buscarElemento(tEmbarcaciones *vec, char *elemBuscado);
void  crearElemento(char *lat, char *lon, char *name, tEmbarcaciones *vec);
void  modificarElemento(char *lat, char *lon, tEmbarcacion *elem);
void  desglozarLinea(char *linea, char *lon, char *lat, char *name);

#endif