#include "interface.h"
#include <stdio.h>

#define TEXTO "Once upon a midnight dreary, while I pondered, weak and weary,\nOver many a quaint and curious volume of forgotten lore,\nWhile I nodded, nearly napping, suddenly there came a tapping,\nAs of some one gently rapping, rapping at my chamber door\n'Tis some visitor,' I muttered, 'tapping at my chamber door –\nOnly this and nothing more"

int crearLotePoe() {
    FILE *arch; 

    if( (arch = fopen(FILE_LOCATION, "wt")) == NULL ) {
        perror("Hubo un problema al crear el archivo");
        exit(1);
    }
    fputs(TEXTO, arch);
    fclose(arch);

    return OK;
}

int testearPoe() {
    char *respuestaEsperada =  "forgotten, pondered, suddenly";
    char resultados[3][20];

    printf("Esperado: %s\n", respuestaEsperada);
    procesarPalabras(resultados, FILE_LOCATION);
    printf("Recibido: %s, %s, %s\n", resultados[0],resultados[1],resultados[2]);
    
    return OK;
}