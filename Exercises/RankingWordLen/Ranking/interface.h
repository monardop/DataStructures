#ifndef INTERFACE_H
    
    #define INTERFACE_H
    #define FILE_LOCATION  "poema.txt"
    #define OK   1
    #define FAIL 0

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>


    void procesarPalabras(char rank[][20], char *path);
    int crearLotePoe();
    int testearPoe();

#endif