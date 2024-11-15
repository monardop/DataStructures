#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "distancias.h"


void *buscarElemento(tEmbarcaciones *vec, char *elemBuscado) {
    for(int i = 0; i < vec->cantElementos; i++) {
        if ( strcmp( elemBuscado, vec->enCurso[i].nombre ) == 0)
            return &(vec->enCurso[i]);
    }

    return NULL;
}

void crearElemento( char *lat, char *lon, char *name, tEmbarcaciones *vec ) {
    double latitud, longitud;
    tEmbarcacion nuevoElem;

    latitud = atof( lat );
    longitud = atof( lon );

    strcpy( nuevoElem.nombre, name );
    nuevoElem.latActual  = latitud;
    nuevoElem.longActual = longitud;
    nuevoElem.menorDist  = -1;

    vec->enCurso[vec->cantElementos] = nuevoElem;
}

void modificarElemento( char *lat, char *lon, tEmbarcacion *elem ) {
    double latitud, longitud, nuevaDistancia;

    latitud = atof( lat );
    longitud = atof( lon );
    nuevaDistancia = sqrt( pow( latitud, 2 ) + pow( longitud, 2 ) );

    if ( elem->menorDist == -1 ) 
        elem->menorDist = nuevaDistancia;
    else if( elem->menorDist > nuevaDistancia)
        elem->menorDist = nuevaDistancia;

    elem->latActual  = latitud;
    elem->longActual = longitud;
}

void  inicializar(tEmbarcaciones *vec) {
    vec->cantElementos = 0;
}

void  desglozarLinea( char *linea, char *lon, char *lat, char *name ) {
    char *ptr = strchr(linea, '\n');
    *ptr = '\0';

    ptr = strchr(linea, ',');
    *ptr = '\0';
    ptr++;
    strcpy(lat, linea);
    linea = ptr;
    
    ptr = strchr(linea, ',');
    *ptr = '\0';
    ptr++;
    strcpy(lon, linea);
    linea = ptr;
    
    strcpy(name, linea);
}
