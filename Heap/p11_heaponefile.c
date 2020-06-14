#include <stdio.h>
#include <stdlib.h>
// #include "heap.h"

typedef int   ElementType;
typedef ElementType    HE;
typedef int         Index;
typedef struct _heap HEAP;
typedef HEAP *       HPtr;    
struct _heap {
    HE * data;
    int  capacity;
    int  start;
    int  size;
};
#define FullHeapError -1

void swapptr (HE *arr, Index i, Index j);
HPtr initHeap( int capacity );
int isEmptyHeap( HPtr hp );
int isFullHeap( HPtr hp );
Index PushHeap( HPtr hp, HE dv );
void prtPath( HPtr hp, Index idx );


void readInput( HE *arr, int size, HE *qarr, int qsize )
{
    int i = 0;
    while ( i < size )  scanf( "%d", &arr[i++] );

    i = 0;
    while ( i < qsize ) scanf( "%d", &qarr[i++] );
}

int main( int argc, char **argv )
{
    int size, qsize;
    scanf( "%d %d", &size, &qsize );
    HE *arr  = (HE *)malloc( sizeof(HE) * size );
    HE *qarr = (HE *)malloc( sizeof(HE) * qsize );
    readInput( arr, size, qarr, qsize );

    HPtr hp = initHeap( size );
    int i = 0;
    for (  ; i < size; i++ )
    {
        if ( isFullHeap( hp ) )
        {
            printf("Heap Full, Pls pay attention\n");
            break;
        }
            
        PushHeap( hp, arr[i] );
    }
    
    i = 0;
    while ( i < qsize )
    {
        prtPath( hp, qarr[i++]);
        printf("\n");
    }

    free(arr);
    free(qarr);
    return 0;
}

void swapptr (HE *arr, Index i, Index j)
{
    HE tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

HPtr initHeap( int capacity )
{
    HPtr hp  = (HPtr)malloc( sizeof( HEAP ) );

    hp->capacity  = capacity;
    hp->start     = 0;
    hp->size      = 0;
    hp->data      = (HE *)malloc( sizeof( HE ) * (capacity + 1) );

    return hp;
}

int isEmptyHeap( HPtr hp )
{
    return ( hp->size == 0 );
}

int isFullHeap( HPtr hp )
{
    return ( hp->size == hp->capacity );
}

Index PushHeap( HPtr hp, HE dv )
{
    // if ( isFullHeap( hp ) )
    //     return FullHeapError;

    if ( isEmptyHeap( hp ) )
    {
        hp->data[++hp->size] = dv;
        return hp->size;
    }

    hp->data[++hp->size]    = dv;

    Index curi, pari;  
    curi = hp->size;
    pari = curi / 2;
    while ( pari > 0 && hp->data[curi] < hp->data[pari] )
    {
        swapptr( hp->data, curi, pari);
        curi = pari;
        pari = curi / 2;
    }
    
    return curi;
} 

void prtPath( HPtr hp, Index idx )
{
    int flag   = 0;
    Index pari = idx / 2;
    while ( idx > 0 )
    {
        if ( !flag ) 
        {
            printf( "%d",  hp->data[idx] );
            flag = 1;
        }            
        else 
            printf( " %d", hp->data[idx] );

        idx  = pari;
        pari = idx / 2;
    }
}