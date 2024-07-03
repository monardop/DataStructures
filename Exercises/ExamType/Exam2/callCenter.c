#include "callCenter.h"

int loadOperators(dsList *activeOperators)
{
    FILE *operators, *plus;
    Employee newEmployee;
    plusStruct aux;
    char buffer[30];

    if(*activeOperators != NULL)
    {
        clearList(activeOperators);
    }

    if((operators = fopen(OPERATORS_FILE, "r")) == NULL || (plus = fopen(PLUS_FILE, "rb")) == NULL)
    {
        fclose(operators);
        return FILE_FAIL;
    }

    while(fgets(buffer,30, operators) != 0)
    {
        sscanf(buffer, "id nro.: %d", &newEmployee.idEmployee);
        fseek(plus, (long)((newEmployee.idEmployee - 1) * sizeof(aux)), SEEK_SET);
        fread((void *)&aux, sizeof(aux),1,plus);
        
        strcpy(newEmployee.name, aux.name);
        newEmployee.numberCalls = aux.amountCalls;
        newEmployee.isBusy = 0;

        if(insertElement(activeOperators, (void *)&newEmployee, sizeof(newEmployee)) != OK)
            return MEM_FAIL;
    }    

    fclose(operators);
    fclose(plus);

    return OK;
}

int checkDisponibility(const void *element, const void *parameter)
{
    Employee *newEmployee = (Employee *)element;
    char *isBusy = (char *)parameter;

    return newEmployee->isBusy == *isBusy;
}

int assignCall(dsList *freeWorkers)
{
    Employee *auxEmployee;
    
    auxEmployee = (Employee *)(*freeWorkers)->data;

    if(auxEmployee->isBusy == 1)
        return ALL_BUSY;    
    
    auxEmployee->isBusy       = 1;
    auxEmployee->numberCalls += 1;

    return OK;
}

int endCall(dsList *onCallWorkers)
{
    Employee *auxEmployee;

    auxEmployee = (Employee *)(*onCallWorkers)->data;

    if(auxEmployee->isBusy == 0)
        return NOT_BUSY;

    auxEmployee->isBusy = 0;
    return OK;
}

void printOperator(void *operator)
{
    Employee *actOperator = (Employee *)operator;

    printf("%s", actOperator->name);
    printf("\tID: %d\n", actOperator->idEmployee);
    printf("\tNumber of calls: %d\n", actOperator->numberCalls);
    printf("Status: ");
    if (actOperator->isBusy == 0)
    {
        printf("Free.\n\n");
    }else
    {
        printf("On a Call.\n");
    }
    printf("-----------------------------------------------------------------\n");
}

int showOperators(dsList *activeOperators)
{
    mapList(activeOperators, printOperator);
    return OK;
}

void ceaseOperations(void *operator)
{
    Employee *actOperator = (Employee *)operator;
    actOperator->isBusy = 'n';
}

int ceaseAttention(dsList *activeOperators)
{
    mapList(activeOperators, ceaseOperations);
    mapList(activeOperators, printOperator);
    return OK;
}

void printMenu(void)
{
    system("cls");

    printf("[0] Finalizar.\n");
    printf("[1] Cargar operadores.\n");
    printf("[2] Asignar llamada.\n");
    printf("\tDe no haber disponibilidad, se dara un aviso.\n");
    printf("[3] Finalizar llamada.\n");
    printf("[4] Mostrar operadores activos.\n");
    printf("\tIncluye disponibles y ocupados.\n");
    printf("[5] Cese de operaciones.\n");
    printf("\tSe cierran todas las llamadas.\n");

}

void menu(void)
{
    int error, selection, counter = 0;
    dsList activeOperators;
    dsList *working, *freeWorkers;

    working = &activeOperators;
    freeWorkers = &activeOperators;

    if(createPlusFile() != OK)
    {
        perror("Error al crear el archivo plus.dat");
        return;
    }

    newList(&activeOperators);
    do
    {
        printMenu();
        selection= validNumber(0, 5);
        system("cls");
        switch(selection)
        {
            case 0:
                clearList(&activeOperators);
                printf("Dia finalizado. Adios!");
                return;
            case 1:
                error = loadOperators(&activeOperators);
                break;
            case 2:
                error = assignCall(freeWorkers);
                if(error != ALL_BUSY)
                {
                    freeWorkers = nextElem(freeWorkers);
                }
                break;
            case 3:
                error = endCall(working);
                if(error != NOT_BUSY)
                {
                    working = nextElem(working);
                }
                break;
            case 4:
                error = showOperators(&activeOperators);
                system("pause");
                break;
            case 5:
                error = ceaseAttention(&activeOperators);
                system("pause");
                break;
        }
        counter++;
        if(error != OK)
            errorHandling(error);

        if(counter == 3)
        {
            counter = 0;
            error = endCall(working);
            if(error != NOT_BUSY)
                working = nextElem(working);
        }
        
    } while (error != MEM_FAIL || error != FILE_FAIL);
    
    clearList(&activeOperators);
    printf("Dia finalizado. Adios!");
}