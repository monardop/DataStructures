#ifndef EXCERSISE1_H
#define EXCERSISE1_H

    #include <stdio.h>

    typedef struct 
    {
        int   prov;
        char  localidad[51];
        float sup;
        int   population;
    }info;
    
    int ex1Main(info *vec, char *fileName);
    void showResults(info *vec, int vecSize);
    void mainTest();


#endif // EXCERSISE1_H
