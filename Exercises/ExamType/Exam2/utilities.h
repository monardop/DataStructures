#ifndef UTILITIES_H
#define UTILITIES_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define OPERATORS_FILE "operators.txt"
    #define PLUS_FILE      "plus.dat" 

    #define OK                  1
    #define MEM_FAIL            0
    #define FILE_FAIL          -1
    #define ALL_BUSY           -2
    #define NOT_BUSY           -3

    typedef int  (*cmp)(const void *, const void *);
    typedef void (*action)(void *);

    typedef struct
    {
        char name[31];
        int numberCalls;
        int idEmployee;
        int isBusy;
    }Employee;

    typedef struct
    {
        char name[31];
        int  amountCalls;
    }plusStruct;

    void errorHandling(const int error);
    int validNumber(const int inf, const int sup);
    int createPlusFile();
    
#endif // UTILITIES_H
