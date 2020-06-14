#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

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
    if ( isFullHeap( hp ) )
        return FullHeapError;

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