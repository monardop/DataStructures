#include <stdio.h>

#include "utilities.h"

void errorHandling(int error) {

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

