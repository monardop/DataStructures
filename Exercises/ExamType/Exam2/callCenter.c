#include "callCenter.h"

int loadOperators(dsList *activeOperators)
{
    FILE *operators, *plus;
    Employee newEmployee;
    unsigned sizeOfEmployeePlus;

    if(*activeOperators != NULL)
    {
        clearList(activeOperators);
    }

    if((operators = fopen(OPERATORS_FILE, "r")) == NULL || (plus = fopen(PLUS_FILE, "rb")) == NULL)
    {
        fclose(operators);
        return FILE_FAIL;
    }
    sizeOfEmployeePlus = sizeof(newEmployee.name) + sizeof(newEmployee.numberCalls);

    while(!feof(operators) && fscanf(operators,"id nro.: %d", &newEmployee.idEmployee) != 0)
    {
        fscanf(operators,"id nro.: %d", &newEmployee.idEmployee);
        fseek(plus, (long)((newEmployee.idEmployee - 1) * sizeOfEmployeePlus), SEEK_SET);
        fread((void *)newEmployee.name, sizeof(newEmployee.name), 1, plus);
        fread((void *)&newEmployee.numberCalls, sizeof(int), 1, plus);
        newEmployee.isBusy = 'n';
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
    dsList *giveJob;
    Employee *auxEmployee;
    char isBusy = 'n';

    giveJob = nextElemCheck(freeWorkers, (void *)&isBusy, checkDisponibility);

    if (giveJob == NULL)
    {
        return ALL_BUSY;
    }
    freeWorkers = giveJob;

    auxEmployee = (Employee *)(*giveJob)->data;
    auxEmployee->isBusy = 'y';
    auxEmployee->numberCalls++;

    return OK;
}

int endCall(dsList *onCallWorkers)
{
    Employee *auxEmployee;

    auxEmployee = (Employee *)(*onCallWorkers)->data;

    if(auxEmployee->isBusy == 'n')
        return OK;

    auxEmployee->isBusy = 'n';

    onCallWorkers = nextElem(onCallWorkers);
    return OK;
}

void printOperator(void *operator)
{
    Employee *actOperator = (Employee *)operator;

    printf("%s", actOperator->name);
    printf("\tID: %d\n", actOperator->idEmployee);
    printf("\tNumber of calls: %d\n", actOperator->numberCalls);
    printf("\tStatus: ");
    if(actOperator->isBusy == 'y')
        printf("On a call\n\n");
    else
        printf("Free\n\n");
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
    int error;
    dsList activeOperators, working, freeWorkers;

    newList(&activeOperators);
    working = activeOperators;
    freeWorkers = activeOperators;
    do
    {
        printMenu();
        switch(validNumber(0, 5))
        {
            case 0:
                clearList(&activeOperators);
                printf("Dia finalizado. Adios!");
                return;
            case 1:
                error = loadOperators(&activeOperators);
                break;
            case 2:
                error = assignCall(&freeWorkers);
                endCall(&working);
                break;
            case 3:
                error = endCall(&working);
                break;
            case 4:
                error = showOperators(&activeOperators);
                endCall(&working);
                break;
            case 5:
                error = ceaseAttention(&activeOperators);
                break;
        }
        if(error != OK)
            errorHandling(error);
        
    } while (error != MEM_FAIL || error != FILE_FAIL);
    
    clearList(&activeOperators);
    printf("Dia finalizado. Adios!");
}