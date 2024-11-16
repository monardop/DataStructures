#ifndef FUNCIONES_H
#define FUNCIONES_H

#define SENSOR_PATH "./Sensors.txt"

typedef struct {
    char       code[9];
    double     temperature;
    unsigned   registers;
}tComponent;

void  slice(const char *line, char *cod, char *temperature, char *status);
void *search(tComponent *vector, char *code, unsigned vecSize);
void  componentAppend(tComponent *vec, unsigned vecSize, char *temperature, char *code, int status);
int   isOK(char *status);
void  addRegister(tComponent *component, char *temperature);
void  getSortedVector(tComponent *vec, unsigned vecSize, unsigned elemSize);
void  setMedia(tComponent *vec, unsigned vecSize);

#endif