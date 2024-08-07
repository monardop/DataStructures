#include <stdio.h>
#include <string.h>

#include "check_file.h"

FILE* checkIntegrity(char *fileName, char *mode) {
    FILE *fp;

    if((fp = fopen(fileName, mode)) == NULL) {
        printf("There was an error with '%s'", fileName);
        return NULL;
    }

    return fp;
}

void updateProblemFile(FILE *pf, dsStack *sp) {
    Product aux;

    while(pull(sp, &aux)) {
        fprintf(pf, "%s\t%s\t%d\t%c", aux.cod, aux.description, aux.quantity, aux.operation);
        fprintf(pf,"\n");
    }
}

void updateOkFile(FILE *pf, dsStack *sp, int final) {
    Product aux;
    pull(sp, &aux);

    aux.quantity = final;
    aux.operation = '-';
    fwrite(&aux, sizeof(Product), 1, pf);
    cleanStack(sp);

}

int analizeFile(void) {
    FILE *baseFile, *withProblem, *ok;
    dsStack stack;
    Product aux;
    char auxCod[6];
    int quantityOfProducts = 0;

    baseFile = checkIntegrity(MOVEMENTS_FILE, "rb");
    if(!baseFile) return FAIL;
    ok = checkIntegrity(OK_FILE, "wb");
    if(!ok) {
        fclose(baseFile);
        return FAIL;
    }
    withProblem = checkIntegrity(ERROR_FILE, "wt");
    if(!withProblem) {
        fclose(baseFile);
        fclose(ok);
        return FAIL;
    }

    initialize(&stack);
    fread(&aux, sizeof(Product), 1, baseFile);
    while (!feof(baseFile)) {
        quantityOfProducts = 0;
        strcpy(auxCod, aux.cod);
        do{
            if(aux.operation == 'I') quantityOfProducts += aux.quantity;
            else quantityOfProducts -= aux.quantity;

            push(&stack, &aux, sizeof(Product));
            fread(&aux, sizeof(Product), 1, baseFile);
        }while (strcmp(auxCod, aux.cod) == 0 && !feof(baseFile)); 
        if(quantityOfProducts >= 0) updateOkFile(ok, &stack, quantityOfProducts);
        else updateProblemFile(withProblem,&stack);
    }
    fclose(withProblem);
    fclose(baseFile);
    fclose(ok);
    return OK;
}

int printBinaryFile(char *fileName) {
    Product aux;
    FILE *pf;

    pf = checkIntegrity(fileName, "rb");
    if(!pf) return FAIL;

    while(fread(&aux, sizeof(Product), 1, pf)) {
        fprintf(stdout, "%s\t%s\t%d\t%c", aux.cod, aux.description, aux.quantity, aux.operation);
        fprintf(stdout,"\n");
    }
    fclose(pf);
    return OK;
}

int printTextFile(char *fileName) {
    char buffer[100];
    FILE *pf;

    pf = checkIntegrity(fileName, "rt");
    if(!pf) return FAIL;

    while(fgets(buffer,100, pf)) {
        printf("%s", buffer);
    }
    fclose(pf);
    return OK;
}

int test_batch(void) {
    Product batch[] = {{"AA", "WATER", 20, 'I'}, {"AA", "WATER", 20, 'I'}, {"AA", "WATER", 10, 'O'},
                       {"AA", "WATER", 15, 'O'}, {"AB", "SALT", 10, 'I'}, {"AB", "SALT", 10, 'I'}, 
                       {"AC", "COFFE", 15, 'O'}, {"AC", "COFFE", 10, 'I'}, {"AC", "COFFE", 10, 'O'}};
    FILE *pf = checkIntegrity(MOVEMENTS_FILE, "wb");
    if(!pf) return FAIL;

    for(int i = 0; i < 9; i++) {
        fwrite(&batch[i], sizeof(Product), 1, pf);
    }
    fclose(pf);
    return OK;
}