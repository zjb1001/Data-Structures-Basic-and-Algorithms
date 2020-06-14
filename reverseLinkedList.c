#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Read()
{
    int size, item;
    scanf( "%d", &size );

    List outL = (List)malloc( sizeof(struct Node) );
    PtrToNode currPtr = outL;
    for ( int i = 0; i < size; i++ )
    {
        PtrToNode tmpN = (PtrToNode)malloc( sizeof(struct Node) );
        scanf( "%d", &tmpN->Data );
        tmpN->Next = NULL;

        currPtr->Next = tmpN;
        currPtr = tmpN;
    }

    return outL;
}

List Reverse( List L )
{
    List outL = (List)malloc( sizeof( struct Node ) );

    L  = L->Next;
    PtrToNode preN  = NULL, tmpN;

    while ( L )
    {
        tmpN    = L->Next;
        L->Next = preN;
        preN    = L;
        L       = tmpN;
    }

    outL->Next = preN;
    return outL;
}

void Print( List L )
{
    int first = 1;
    L = L->Next;
    while ( L )
    {
        if (first )
        {
            printf( "%d",  L->Data );
            first = 0;
        }            
        else 
            printf( " %d", L->Data );

        L = L->Next;
    }
        
    printf( "\n" );
}