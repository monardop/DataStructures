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

    giveJob = nextElem(freeWorkers, (void *)&isBusy, checkDisponibility);

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
    dsList *freeWorker;
    Employee *auxEmployee;
    char isBusy = 'y';

    freeWorker = nextElem(onCallWorkers, (void *)&isBusy, checkDisponibility);

    if (freeWorker == NULL)
    {
        return OK;
    }
    onCallWorkers = freeWorker;

    auxEmployee = (Employee *)(*freeWorker)->data;
    auxEmployee->isBusy = 'n';

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

void showOperators(dsList *activeOperators)
{
    mapList(activeOperators, printOperator);
}

void ceaseOperations(void *operator)
{
    Employee *actOperator = (Employee *)operator;
    actOperator->isBusy = 'n';
}

void ceaseAttention(dsList *activeOperators)
{
    mapList(activeOperators, ceaseOperations);
    mapList(activeOperators, printOperator);
}
