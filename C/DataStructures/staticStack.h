#ifndef STATICSTACK_H_INCLUDED
#define STATICSTACK_H_INCLUDED

typedef struct 
{
    int vector[10];
    int top;
}STACK;


STACK initialize();
int is_full(STACK stack);
void push(STACK stack, int number);
void peack(STACK stack);
void pop(STACK stack);


#endif // STATICSTACK_H_INCLUDED