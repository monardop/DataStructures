#include <stdio.h>
#include <string.h>

#include "sales_interface.h"
#include "file_handler.h"



int testBatch() {
    FILE *pf;
    tProduct products[] = {{"AA", "Water", 1, {22,7,2024}, 30},
                           {"AA", "Water", 3, {22,9,2024}, 100},
                           {"AA", "Water", 1, {22,7,2024}, 40},
                           {"AA", "Water", 5, {22,7,2025}, 30},
                           {"AB", "Salt", 98, {20,10,2024}, 90},
                           {"AC", "Pipe", 5, {10,7,2030}, 30},
                           {"AC", "Pipe", 5, {10,7,2030}, 90},
                           {"AD", "Floor", 1, {22,7,2030}, 30}};

    if((pf = fopen(STOCK_FILE, "wb")) == NULL)
        return FILE_ERROR;

    for (size_t i = 0; i < 8; i++)
    {
        fwrite(&products[i], sizeof(tProduct), 1, pf);
    }

    fclose(pf);
    return OK;
}

void notExpiredFileHandle(FILE *pf, dsList *pl) {
    tProduct aux;
    while(*pl) {
        returnNdel(pl, &aux);
        fwrite(&aux, sizeof(tProduct), 1, pf);
    }
}

void expiredFileHandle(FILE *pf, dsList *pl) {
    tProduct aux;
    while(*pl) {
        returnNdel(pl, &aux);
        fprintf(pf, "%6s\t%25s\t%d\t%d/%d/%d\t%d\n", aux.codProd, aux.descrip,
            aux.lote, aux.fVto.day,aux.fVto.month,aux.fVto.year, aux.stock);
    }
}

int analyzeFile(tDate actDate, int n) {
    FILE *stockFile, *expired, *notExpired;
    tProduct aux;
    char auxCode[6];
    dsList products;

    if((stockFile = fopen(STOCK_FILE, "rb"))==NULL) {
        perror("'Stock File' not found.\n");
        return FILE_ERROR;
    }

    if((expired = fopen(EXPIRED_FILE, "w")) == NULL ||
    (notExpired = fopen(NOT_EXPIRED_FILE, "wb")) == NULL) {
        perror("Couldn't open files.\n");
        return FILE_ERROR;
    }

    newList(&products);
    getExpireDate(&actDate, n);

    fread(&aux,sizeof(tProduct), 1, stockFile);
    while(!feof(stockFile)) {
        strcpy(auxCode, aux.codProd);
        while (!feof(stockFile) && strcmp(auxCode, aux.codProd) == 0){
            sortedInsertion(&products, &aux, sizeof(tProduct), productCMP);
            fread(&aux,sizeof(tProduct), 1, stockFile);
        }

        if(determineList(&products, actDate) == EXPIRED) {
            expiredFileHandle(expired, &products);
        } else {
            notExpiredFileHandle(notExpired,&products);
        }

    }

    fclose(expired);
    fclose(notExpired);
    fclose(stockFile);

    return OK;
}

int showStock(char *fileName) {
    FILE *pf;
    tProduct aux;

    if((pf = fopen(fileName, "rb")) == NULL) {
        perror("'Stock File' not found.\n");
        return FILE_ERROR;
    }

    while(fread(&aux, sizeof(tProduct),1, pf)) {
        fprintf(stdout, "%6s\t%25s\t%d\t%d/%d/%d\t%d\n", aux.codProd, aux.descrip,
            aux.lote, aux.fVto.day,aux.fVto.month,aux.fVto.year, aux.stock);
    }

    fclose(pf);
    return OK;
}

int showExpired() {
    FILE *pf;
    char buffer[100];
    if((pf = fopen(EXPIRED_FILE, "r")) == NULL) {
        perror("'Prod_ok' not found.\n");
        return FILE_ERROR;
    }
    
    while(fgets(buffer, 100, pf)) {
        printf("%s", buffer);
    }
    fclose(pf);
    return OK;
}

