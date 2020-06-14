#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef int *     Array;
typedef  int *      iPtr;

void prtArrByRange( Array arr, int left, int right )
{
    for ( int i = left; i <= right; i++ )
        printf( "%d ", arr[i] );
    
    printf( "\n" );
}

void _msort( Array arr, Array tmpArr, int left, int right )
{
    int center;
    if ( left < right  )
    {
        center = (left + right) / 2;
        _msort( arr, tmpArr, left, center );
        _msort( arr, tmpArr, center + 1, right );
        merge( arr, tmpArr, left, center + 1, right );
    }
}

void mergeSort( Array arr, int size )
{
    iPtr tmpArr;
    tmpArr = (iPtr)malloc( sizeof(ElementType) * size );

    if ( tmpArr )
    {
        _msort( arr, tmpArr, 0, size - 1 );
        free( tmpArr );
    }
    else
        printf( "No space for tmp Array" );
}

void merge( Array arr, Array tmpArr, int front, int rear, int right )
{
    int i;

    int curr = front;
    int pf = front, pr = rear;
    for (  ; pf < rear && pr <= right; curr++ )
    {
        if ( arr[pf] < arr[pr] )
            tmpArr[curr] = arr[pf++];        
        else 
            tmpArr[curr] = arr[pr++];
    }

    for ( i = pf; i < rear; i++, curr++ )
        tmpArr[curr] = arr[i];

    for ( i = pr; i <= right; i++, curr++ )
        tmpArr[curr] = arr[i];

    for ( i = front; i <= right; i++ )   
        arr[i] = tmpArr[i];
}

void prtArr( ElementType arr[], int size )
{
    for ( int i = 0; i < size; i++ )
        if ( i == 0)
            printf( "%d", arr[i] );
        else 
            printf( " %d", arr[i] );
    
    printf( "\n" );
}

void readInput( Array srcArr, Array aftArr, int size )
{
    for ( int i = 0; i < size; i++ )
        scanf( "%d", srcArr++ );

    for ( int i = 0; i < size; i++ )
        scanf( " %d", aftArr++ );
}

//10
//3 1 2 8 7 5 9 4 0 6
//1 3 2 8 5 7 4 9 0 6

// int isInsertSort( Array srcArr, Array aftArr, int size )
// {
//     iPtr psta = srcArr;
//     int flag = 0;
//     while ( srcArr < (psta + size) &&  (*srcArr++ != *aftArr++) ) flag = 1;

//     while ( srcArr < (psta + size) )
//         if ( *srcArr++ != *aftArr++ )
//         {
//             flag = 0; 
//             break;
//         }

//     if ( psta )
//     return flag;
// }

int isSorted ( Array arr, iPtr pptr )
{
    iPtr pfrt = arr, paft = arr + 1;
    while ( paft <= pptr )
    {
        if ( *pfrt > *paft )
            return 0;
        pfrt++; paft++;
    }

    return 1;
}

int isInsertSort( Array arr, Array narr, int size )
{
    iPtr pa = arr + size - 1, pb = narr + size -1;
    while ( pa != arr)
    {
        if ( *pa != *pb ) break;
        pa--; pb--;
    }

    return isSorted( narr, pb );
}

int whereIsSort( Array arr, Array narr, int size )
{
    iPtr pa = arr + size - 1, pb = narr + size - 1;
    while ( pa != arr)
    {
        if ( *pa != *pb ) break;
        pa--; pb--;
    }

//    printf( "src=%d, narr=%d\n", *pa, *pb );
    return pb - narr + 1;
}

void insertSortNext( Array arr, int size, int curr )
{
	int i;
    ElementType elem = arr[curr];
    for ( i = curr; i > 0 && elem < arr[i-1]; i-- )
        arr[i] = arr[i - 1];
        
    arr[i] = elem;       // place elem
}

void mergeSort2( Array arr, int size, Array tarArr )
{
    Array tmpArr = (Array)malloc( sizeof(ElementType) * size );

    int subsize = 1, nextstop = 0;
    while ( subsize < size )
    {
        if ( isEqual(arr, tarArr) )  
            nextstop = 1;

        int center;
        int bef = 0, aft = 2 * subsize - 1;
        while ( bef < size )
        {
            if ( aft > size -1 ) aft = size - 1;
            center = (bef + aft) / 2;
            merge( arr, tmpArr, bef, center + 1, aft );

            bef = aft + 1;
            aft = bef + 2*subsize - 1;
        }

        // prtArr( arr, size );
        subsize = nextstop ? size : (subsize * 2);
    }
    
    free( tmpArr );
}

int isEqual( Array arrA, Array arrB, int size )
{
    int flag = 1;
    for ( int i = 0; i < size; i++ )
        if ( *arrA++ != *arrB++ )
        {
            flag = 0;
            break;
        }

    return flag;
}
int main( int argc, char **argv )
{
    int size, curr;
    scanf( "%d", &size );

    int srcArr[size], aftArr[size];
    readInput( srcArr, aftArr, size );

    if ( isInsertSort( srcArr, aftArr, size ) )
    {
    	printf( "Insertion Sort\n" );    	
        curr = whereIsSort( srcArr, aftArr, size );

        insertSortNext( aftArr, size, curr );        
        prtArr( aftArr, size );
    }
    else
    {
        printf( "Merge Sort\n" );
        mergeSort2( srcArr, size, aftArr );
        prtArr( srcArr, size );
    }
   
    // mergeSort2( srcArr, size, aftArr );
    return 0;
}




