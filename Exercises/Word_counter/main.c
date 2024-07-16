#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "system_interface.h"
#include "binary_tree.h"

int main()
{
    int selection;
    Tree wordTree;
    initializeTree(&wordTree);

    setlocale(LC_ALL,"spanish");

    while (1){
        selection = menu();
        switch (selection)
        {
        case 1:
            readFile(&wordTree);
            break;
        case 2:
            showWords(&wordTree);
            break;
        case 3:
            mostOccurrences(&wordTree);
            break;
        case 4:
            fewerOccurrences(&wordTree);
            break;
        case 5: 
            exitProgram(&wordTree);
            return 0;
        default:
            printf("Por favor ingrese un número del 1 al 5\n");
            break;
        }
        system("pause");
        system("cls");
    }
    cleanTree(&wordTree);
    return 0;
}
