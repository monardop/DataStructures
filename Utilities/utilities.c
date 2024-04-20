void *memoryCopy(void *dest, const void *src,  unsigned size) 
{
    const unsigned char *source = (const unsigned char*)src;
    char unsigned *destination = (unsigned char*)dest;

    for(unsigned i = 0; i < size; i++) {
        destination[i]  = source[i];
    }
    return destination;
}

int memoryCompare(const char *elementA, const char *elementB, unsigned bytes)
 {
    const char *a = (const char *)elementA;
    const char *b = (const char *)elementB;

    for(unsigned i = 0; i < bytes; i++) {
        if(*a != *b){
            return 0;
        }
        a++;
        b++;
    }
    return 1;
}

int strLen(const char *str) 
{
    const char *pStr = str;
    while (*pStr++);
    return pStr - str - 1;
}