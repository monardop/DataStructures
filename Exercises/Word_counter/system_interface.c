#include <stdio.h>

#include "system_interface.h"
#include "word.h"

int menu() {
    int x;
    printf("[1] Cargar palabras\n[2] Mostrar palabras\n[3] Mostrar palabra más ocurrente\n[4] Mostrar palabra menos ocurrente\n[5] Salir\n");
    scanf("%d", &x);

    return x;
}

void readFile(Tree *tp) {
    FILE *fp;
    if((fp = fopen(BOOK_FILE, "rt")) == NULL) {
        perror("Hubo un error con el archivo.\n");
        return exitProgram(tp);
    }
    if (getWords(fp, tp) != OK) {
        perror("Hubo un error con el espacio disponible.\n");
        return exitProgram(tp);
    }
}

void showWords(Tree *tp) {
    int x; 

    if(emptyTree(tp)){
        printf("Por favor ejecutar 'Leer archivo' primero.\n");
        return;
    }

    do {
        printf("[1] Orden ascendente\n[2]Orden descendente\n");
        scanf("%d", &x);
    }while(x > 2 || x < 1);

    if(x == 1) {
        showAscendent(tp, printWord);
    }else {
        showDescendant(tp, printWord);
    }
}

void fewerOccurrences(Tree *tp) {
    Word lowerElem;
    if(emptyTree(tp)){
        printf("Por favor ejecutar 'Leer archivo' primero.\n");
        return;
    }
    printf("La palabra que menos veces apareció fue: \n\t");
    showMinMaxValue(tp, compareOccurrences, printWord, 1, (void *)&lowerElem);
}
void mostOccurrences(Tree *tp) {
    Word maxElem;
    if(emptyTree(tp)){
        printf("Por favor ejecutar 'Leer archivo' primero.\n");
        return;
    }
    printf("La palabra que más veces apareció fue: \n\t");
    showMinMaxValue(tp, compareOccurrences, printWord, 0, (void *)&maxElem);
}
void exitProgram(Tree *tp) {
    cleanTree(tp);
    printf("Gracias por usar el programa.\n");
}