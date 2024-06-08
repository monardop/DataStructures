#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

   #define MIN(X, Y) (((X)<(Y))?(X):(Y))
   #define MAX(X, Y) (((X)>(Y))?(X):(Y))
   #define MOD(X) (X < 0)?((-X):(X))
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
   typedef void (*reduceFunction)(void *, void *);
   typedef void (*print)(void *);
   typedef void (*lambda)(void *);
   typedef enum {False, True}bool;

   void *memoryCopy(void *dst, const void *src, unsigned dataSize);
   int memoryCompare(const void *a, const void *b, unsigned dataSize);
   int strLen(const char *str);

   //Comparing tools
   int intCompare(void *, void *);
   int intLessThan(void *, void *);
   int intBigger(void *, void *);
   int strCompare(void *, void *);
   int strBigger(void *, void *);
   int strLessThan(void *, void *);
   int floatCompare(void *, void *);
   int floatLessThan(void *, void *);
   int floatBigger(void *, void *);

   //print tools
   void intPrint(void*);
   void floatPrint(void*);
   void strPrint(void*);

   //lambda functions
   void toLower(void *);
   void toUpper(void *);
   void floatSquare(void *);
   void intSquare(void *);

   //reduce functions
   void redIntSum(void *vessel, void *data);
   void redFloatSum(void *vessel, void *data);

#endif // UTILITIES_H_INCLUDED
