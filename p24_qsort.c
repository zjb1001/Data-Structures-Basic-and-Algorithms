#include <stdlib.h>
#include <stdio.h>

/*
 *数据1：只有1个元素；
 *数据2：11个不相同的整数，测试基本正确性；
 *数据3：103个随机整数；
 *数据4：104个随机整数；
 *数据5：105个随机整数；
 *数据6：105个顺序整数；
 *数据7：105个逆序整数；
 *数据8：105个基本有序的整数；
 *数据9：105个随机正整数，每个数字不超过1000。
*/

typedef  int ElementType;
typedef  ElementType *     pElem;
typedef  ElementType *     Array;

int isOrder( Array arr, int size )
{
    int i, j;
    for ( i = 0, j = 1; j < size; i++, j++ )
        if ( arr[i] > arr[j] )
        return 0;

    return 1;
}

void prtArr( Array arr, int size )
{
    if ( size == 1 )
        printf( "%d", arr[0] );
    else
    {
        int i = 0, flag = 1;
        for ( ; i < size; i++  )
            if ( flag )
            {
                printf( "%d", arr[i] );
                flag = 0;
            }
            else 
                printf( " %d", arr[i] );            
    }    
}

void swap( pElem low, pElem high )
{
    if ( low == high )
        return;

    if ( low < high )
    {
        ElementType tmp = *low;
        *low  = *high;
        *high = tmp;
    }
}

void qsortMy( Array arr, int size )
{
    if ( size == 0 || size == 1)
        return;

    pElem pivot = arr + size - 1;
    pElem plow = arr, phigh = pivot -1;
    while ( plow < phigh )
    {
        for ( ; *plow < *pivot; plow++ );
        for ( ; *phigh>=*pivot && (phigh > plow); phigh--);
        
        if ( plow < phigh )
        {
            swap( plow, phigh );
            plow++;
        }    
    }

    if ( plow == phigh && (*plow > *pivot) )
            swap( plow, pivot );   

    qsortMy( arr,  plow - arr );
    qsortMy( plow + 1, pivot - plow );
}

void qsortMy2( Array arr, int size )
{
    if ( size == 0 || size == 1)
        return;

    pElem pivot = arr + size - 1;
    pElem plow = arr, phigh = pivot -1;
    while ( plow < phigh )
    {
        for ( ; *plow  <= *pivot; plow++ );
        for ( ; *phigh > *pivot && (phigh > plow); phigh--);
        
        if ( plow < phigh )
        {
            swap( plow, phigh );
            // plow++;
            phigh--;
        }    
    }

    if ( plow == phigh && (*plow > *pivot) )
            swap( plow, pivot );   

    qsortMy( arr,  plow - arr );
    qsortMy( plow + 1, pivot - plow );
}


int main( int argc, char **argv )
{
    int size;
    scanf( "%d", &size );

    Array arr = (Array)malloc( sizeof(ElementType) * size );
    int i;
    for ( i = 0; i < size; i++ )
        scanf( "%d", arr + i );

    int order = isOrder( arr, size );
    if ( order )
        prtArr( arr, size );
    else
    {
        qsortMy2( arr, size );
        prtArr( arr, size );
    }
    
    return 0;
}

