#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

   #define MIN(X, Y) (((X)<=(Y))?(X):(Y))
   #define STATIC_ELEMENTS 100

   #define EMPTY 0
   #define NO_SPACE 0
   #define NOT_FOUND 0
   #define OK 1
   #define ERROR 0
   #define SEPARATOR "\n\n\t-------------------------------------------------------\t\n"

   typedef struct sNodo{
        void *data;
        unsigned dataSize;
        struct sNodo *next;
   }tNode;

   typedef int (*cmp)(void *, void *);
   typedef void (*print)(void *);
   typedef void (*lambda)(tNode *);
   typedef enum {False, True}bool;

   void *memoryCopy(void *dst, const void *src, unsigned dataSize);
   int memoryCompare(const void *a, const void *b, unsigned dataSize);
   int strLen(const char *str);

   //Comparing tools
   int intCompare(void *, void *);
   int strCompare(void *, void *);
   int floatCompare(void *, void *);

   //print tools
   void intPrint(void*);
   void floatPrint(void*);
   void strPrint(void*);

#endif // UTILITIES_H_INCLUDED
