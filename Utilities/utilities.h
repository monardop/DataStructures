#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

   #define MIN(X, Y) (((X)<=(Y))?(X):(Y))
   #define STATIC_ELEMENTS 100

   #define EMPTY 0
   #define NO_SPACE 0
   #define OK 1

   typedef struct sNodo{
        void *data;
        unsigned dataSize;
        struct sNodo *next;
   }tNode;

   void *memoryCopy(void *dst, const void *src, unsigned dataSize);
   int memoryCompare(const char *a, const char *b, unsigned dataSize);
   int strLen(const char *str);

#endif // UTILITIES_H_INCLUDED
