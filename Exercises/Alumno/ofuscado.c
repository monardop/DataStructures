#include "ofuscado.h"

int esLetra(const int letra) {
    return ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z'))? 1: 0;
}

const char *buscar(const char *vec, char buscado) {
    for (size_t i = 0; i < 15; i++) {
        if(*vec == buscado)
            return vec;
        vec++;
    }

    return NULL;
}

char devolverLetra(const char *guia, const char *ptrLetra, int contadorLetras) {
    int posicion = ptrLetra - guia;

    if(posicion + contadorLetras > 13) {
        return guia[(posicion + contadorLetras) - 14];
    }

    return guia[posicion + contadorLetras];
}


char* __desofuscar(char* linea){
    const char guia[]= "abcdghijkoqtuv";
    int contadorLetra;

    while(*linea) {
        contadorLetra = 0;

        while (esLetra((int)*linea))
        {

            contadorLetra++;
            const char *letra = buscar(guia,  *linea);

            if(letra) {
                char nuevaLetra = devolverLetra(guia, letra, contadorLetra);
                *linea = nuevaLetra;
            }

            linea++;
        }
        linea++;
    }

    return NULL;
}
