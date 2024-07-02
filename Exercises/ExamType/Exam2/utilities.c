#include "utilities.h"

void errorHandling(const int error)
{
    switch (error)
    {
        case MEM_FAIL:
            printf("Hubo un error al asignar memoria dinamica.\n");
            break;
        case FILE_FAIL:
            printf("Comprobar la integridad de los archivos necesarios.\n");
            break;
        case ALL_BUSY:
            printf("No hay trabajadores disponibles para atender, llamada perdida.\n");
            break;
    }
}

int validNumber(const int inf, const int sup)
{
    int ans; 
    do
    {
        printf("\tSelect: ");
        scanf("%d", &ans);
    } while (ans < inf || ans > sup);

    return ans;
}

