#ifndef CHECK_FILE_H
#define CHECK_FILE_H
    #include "stack_structure.h"

    #define MOVEMENTS_FILE "movements.dat"
    #define ERROR_FILE     "wrong_input.txt"
    #define OK_FILE        "products.dat"

    typedef struct {
        char cod[6];
        char description[25];
        int  quantity;
        char operation; // I/O
    }Product;

    int analizeFile(void);
    int printBinaryFile(char *fileName);
    int printTextFile(char *fileName);

#endif // CHECK_FILE_H
