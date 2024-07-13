#include <stdio.h>
#include <stdlib.h>

#include "check_file.h"

void menu(void);

int main()
{
    if(!test_batch()) exit(1);
    printf("Welcome.\n\n");
    menu();
    printf("Ending session");
    return 0;
}

int validation(void) {
    int x; 
    do {
        printf("Select: ");
        scanf("%d", &x);
    }while(x < 0 && x > 4);
    
    return x;
}

void menu(void) {
    int selection;
    do {
        printf("[0] Exit\n[1] View movements\n[2] View stock\n[3] View file of incorrectly entered products\n");
        printf("[4] Generate files\n");
        selection = validation();
        switch (selection) {
        case 1: // view Movements file
            printBinaryFile(MOVEMENTS_FILE);
            break;
        case 2: // view new stock
            printBinaryFile(OK_FILE);
            break;
        case 3:  // view wrong input file
            printTextFile(ERROR_FILE);
            break;
        case 4:
            analizeFile();
            break;
        default:
            return;
        }

        system("pause");
        system("cls");
    }while(selection != 0);
}