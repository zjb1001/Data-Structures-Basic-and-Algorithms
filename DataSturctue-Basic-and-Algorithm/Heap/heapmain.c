#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/*
5 3
46 23 26 24 10
5 4 3
*/

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