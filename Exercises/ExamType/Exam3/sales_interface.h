#ifndef SALES_INTERFACE_H
#define SALES_INTERFACE_H
    
    #include "utilities.h"
    #include "list_interface.h"
    
    typedef struct {
        char  codProd[6]; 
        char  descrip[25];
        int   lote;
        tDate fVto;
        int   stock;
    }tProduct;

    int productCMP(const void *, const void *);
    int determineList(dsList *, tDate );

#endif // SALES_INTERFACE_H
