#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

    #include "list_interface.h"
    #include "utilities.h"

    #define STOCK_FILE        "stock.dat"
    #define NOT_EXPIRED_FILE  "prod_ok.dat"
    #define EXPIRED_FILE      "prod_a_vencer.txt"


    int testBatch();
    int showStock(char *);
    int analyzeFile(tDate actDate, int n);
    int showExpired();
    
#endif // FILE_HANDLER_H
