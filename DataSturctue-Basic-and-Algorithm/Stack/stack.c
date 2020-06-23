#include "stack.h"
#include <stdlib.h>

int isEmpty(ST st)
{
    return st->top == -1;
}

ElementType Pop(ST st)
{
    return st->data[st->top--];
}

void Push(ST st, ElementType elem)
{
    st->data[++st->top]  = elem;
}

int isFull(ST st)
{
    return st->top == st->capacity - 1;
}

ST initStack(int capa)
{
    ST st  = (ST)malloc( sizeof(SN) );
    st->capacity  = capa;
    st->top       = -1;
    st->data      = (ElementType *)malloc( sizeof(ElementType) * capa );
    
    return st;
}