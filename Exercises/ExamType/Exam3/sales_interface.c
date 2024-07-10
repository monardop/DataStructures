#include "sales_interface.h"

int isExpired(const void *d1, const void *d2) {
    tDate    *expiredDate = (tDate *)d1;
    tProduct *product     = (tProduct *)d2;
    
    if (product->fVto.year > expiredDate->year)
        return 1;
    if(product->fVto.month > expiredDate->month)
        return 1;
    if(product->fVto.day > expiredDate->day)
        return 1;

    return 0;
}

int datecmp(tDate a, tDate b)
{
    if(a.year < b.year)
        return -1;
    else if(a.year > b.year)
        return 1;

    if(a.month < b.month)
        return -1;
    else if(a.month > b.month)
        return 1;
    
    if(a.day < b.day)
        return -1;
    else if(a.day > b.day)
        return 1;

    return 0;
}

void reduceList(void *dst, void *src) {
    tProduct *dest = (tProduct *)dst;
    tProduct *source = (tProduct *)src;

    if(datecmp(dest->fVto, source->fVto) == 1)
    {
        dest->fVto.day = source->fVto.day;
        dest->fVto.month = source->fVto.month;
        dest->fVto.year = source->fVto.year;
    }

    dest->stock += source->stock;
}

int batchcmp(const void *d1, const void *d2) {
    tProduct *p1 = (tProduct *)d1;
    tProduct *p2 = (tProduct *)d2;

    if(p1->lote == p2->lote)
        return 0;

    return 1;
}

void notExpiredReduceList(void *dst, void *src) {
    tProduct *dest = (tProduct *)dst;
    tProduct *source = (tProduct *)src;

    if(datecmp(dest->fVto, source->fVto) == 1)
    {
        dest->lote       = source->lote;
        dest->fVto.day   = source->fVto.day;
        dest->fVto.month = source->fVto.month;
        dest->fVto.year  = source->fVto.year;
    }

    dest->stock += source->stock;
}

int notExpiredBatchcmp(const void *d1, const void *d2) {
    return 0;
}

int determineList(dsList *pl, tDate expireDate) {
    if(find(pl, &expireDate, isExpired)) {
        simplifyList(pl, batchcmp, reduceList);
        return EXPIRED;
    }
    simplifyList(pl, notExpiredBatchcmp, notExpiredReduceList);
    return NOT_EXPIRED;
}

int productCMP(const void *p1, const void *p2) {
    tProduct *a = (tProduct *)p1;
    tProduct *b = (tProduct *)p2;

    return a->lote - b->lote;
}



