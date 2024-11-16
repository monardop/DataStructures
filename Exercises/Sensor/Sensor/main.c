#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

int main()
{
    FILE *sensorFile;
    tComponent vector[20];
    char newRegister[40];
    // Aux vars
    char  status[13], temperature[7], code[9];
    unsigned numberOfElements = 0;

    if( (sensorFile = fopen(SENSOR_PATH, "rt")) == NULL ) {
        perror("Hubo un error al abir el archivo.");
        exit(1);
    }

    while( !feof(sensorFile) ) {
        tComponent *elemDir;
        fgets(newRegister, 40, sensorFile);
        slice(newRegister, code, temperature, status);
        elemDir = search(vector, code, numberOfElements);
        if( !elemDir ) {
            componentAppend(vector,numberOfElements, temperature, code, isOK(status));
            numberOfElements++;
        }else if( isOK(status) ) addRegister(elemDir, temperature);
    }

    fclose(sensorFile);

    getSortedVector(vector,numberOfElements, sizeof(tComponent));
    setMedia(vector, numberOfElements);

    for (size_t i = 0; i < numberOfElements; i++) {
        if(vector[i].registers > 0) printf("%s %.2f\n", vector[i].code, vector[i].temperature);
        else                        printf("%s -Sin informacion confiable-\n", vector[i].code);
    }

    return 0;
}
