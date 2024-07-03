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
    system("pause");
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

int createPlusFile()
{
    FILE *pf;
    plusStruct info[] = {{"Felipe", 67}, {"Marcos", 47}, {"David", 19}, {"Victor", 60}, {"Santiago", 32},
                         {"Beatriz", 37}, {"Teresa", 76}, {"Valeria", 3}, {"Natalia", 39}, {"Carlos", 3}, 
                        {"Gustavo", 56}, {"Gustavo", 78}, {"Marcos", 59},  {"Carlos", 97}, {"Teresa", 84},
                         {"Jorge", 35}, {"Oscar", 63}, {"Alejandro", 58}, {"Luis", 100}, {"Gabriel", 79}, 
                         {"Felipe", 63}, {"Victor", 43}, {"Victor", 61}, {"Irene", 96}, {"Hector", 48}, 
                         {"Marcos", 35}, {"Carlos", 20}, {"Felipe", 70}, {"Ricardo", 61}, {"Isabel", 13}};
    
    if((pf = fopen(PLUS_FILE, "wb")) == NULL)
        return FILE_FAIL;
    
    for (size_t i = 0; i < 30; i++)
    {
        fwrite((void *)&info[i], sizeof(plusStruct), 1, pf);
    }
    fclose(pf);
    return OK;
}