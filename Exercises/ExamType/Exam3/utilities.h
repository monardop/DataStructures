#ifndef UTILITIES_H
#define UTILITIES_H

    typedef struct
    {
        int day, month, year;
    } tDate;

    #define NOT_EXPIRED 3
    #define EXPIRED     2
    #define OK          1
    #define MEM_ERROR   0
    #define FILE_ERROR -1

    int  isValidDate(tDate date);
    void getExpireDate(tDate *date, int n);
    void menu();
    
#endif // UTILITIES_H
