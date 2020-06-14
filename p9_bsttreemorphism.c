#include <stdio.h>
#include <stdlib.h>
#include "./BSTree/bstree.h"

typedef  int ElementType;

void readInput();
// BSTree buildBSTree( ElementType * arr,  int size );
void readArr( ElementType * arr, int size );
void prtArr( ElementType * arr, int size );

int main( int argc, char ** argv )
{
	readInput();
	return 0;
}

void readArr( ElementType * arr, int size )
{
	int i = 0;
	while ( i < size )
	{
		scanf( "%d", arr + i );
		i++;
	}
}

void prtArr( ElementType * arr, int size )
{
	int i = 0;
	for (  ; i < size; i++ )
		printf( " %d", arr[i] );
	printf("\n");
}

void readInput()
{
	int N, L;
	scanf( "%d", &N );

	while ( N )
	{
		scanf( "%d", &L );
		
		ElementType * srtArr  = (ElementType *)malloc( sizeof(ElementType) * N );
		readArr( srtArr, N );
		// prtArr( srtArr, N );
		BSTree  btree  = buildBSTree( srtArr , N );
		// printf("tree build successfully\n");
		// preOrder( btree );

		int i = 0;
		while ( i++ < L )
		{
			
			ElementType * tstArr  = (ElementType *)malloc( sizeof(ElementType) * N );
			readArr( tstArr, N );
			// prtArr( tstArr, N );
			BSTree ttree = buildBSTree( tstArr, N );
			// printf("tree build successfully\n");
			// preOrder( ttree );

			if ( isTreeMorphism( btree, ttree ) )
				printf("Yes\n");
			else 
				printf("No\n");
		}
		
		scanf( "%d", &N );		
	}
}