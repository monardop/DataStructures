#include <stdio.h>
#include <stdlib.h>

#include "utilities.h"
#include "file_handler.h"

void errorHandling(int error) {

    switch (error)
    {
        case MEM_ERROR:
            printf("Hubo un problema con el almacenamiento.\n");
            break;
        case FILE_ERROR:
            printf("Hubo un problema con los archivos\n");
            break;
        default:
            break;
    }

}

int isLeap(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int isValidDate(tDate date) {
    int daysPerMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int leapBool; 
    
    if(1 > date.month && date.month > 12) 
        return 0; 
    if(date.month == 2) {
        leapBool = isLeap(date.year);
        if(leapBool && date.day > 29){
            return 0;
        }else if (!leapBool && date.day > 28){
            return 0;
        }
    }
    if(date.day < 1 || date.day > daysPerMonth[date.month])
        return 0;

    return OK;
}

void getExpireDate(tDate *date, int n) {
    int daysPerMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    date->month += n;

    while (date->month > 12)
    {
        date->month -= 12;
        date->year++;
    }

    if(date->day > daysPerMonth[date->month]) {
        date->day = 1;
        date->month++;
        if(date->month > 12){
            date->month = 1;
            date->year++;
        }
    }
}

int getSelection() {
    int x;
    do
    {
        scanf("%d", &x);
    } while (x < 0 || x > 4);
    return x;
}

tDate getDate() {
    tDate date;
    do
    {
        printf("Insertar con formato dd/mm/yyyy:\n");
        scanf("%d/%d/%d", &date.day, &date.month, &date.year);
    } while(!isValidDate(date));
    return date;
}

void menu() {
    int n;
    testBatch();

    while(1) {
        printf("[1] Generar archivos\n[2] Ver stock\n[3] Ver productos vencidos\n[4] Ver productos en condiciones\n");

        switch (getSelection())
        {
        case 1:
            printf("Insertar cuantos meses es el limite: ");
            scanf("%d", &n);
            errorHandling(analyzeFile(getDate(), n));
            break;
        case 2:
            errorHandling(showStock(STOCK_FILE));
            break;
        case 3:
            errorHandling(showExpired()); 
            break;
        case 4:
            errorHandling(showStock(NOT_EXPIRED_FILE));
            break;
        default:
            exit(1);
        }

    }
}