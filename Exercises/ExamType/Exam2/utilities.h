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

    typedef int  (*cmp)(const void *, const void *);
    typedef void (*action)(void *);

    typedef struct
    {
        char name[31];
        int numberCalls;
        int idEmployee;
        char isBusy;
    }Employee;

    void errorHandling(const int error);
    int validNumber(const int inf, const int sup);
    
#endif // UTILITIES_H
