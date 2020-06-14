#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

Position createNode( ElementType dv )
{
	Position iPtr  = (Position)malloc( sizeof(TN) );
	iPtr->data     = dv;
	iPtr->left  =  iPtr->right  = NULL;

	return iPtr;
}

Position insert( Position tPtr, ElementType dv, int direct )
{
	if ( direct == 0 )
	{
		tPtr->data  = dv;
		return tPtr;
	}
	else
	{
		Position nPtr  = createNode( dv );
		if ( direct == -1 )
			tPtr->left  = nPtr;
		else if ( direct == 1 )
			tPtr->right = nPtr;

		return nPtr;
	}
}


ElementType * find ( ElementType * arr, int size, ElementType data )
{
	int i = 0;
	while ( arr[i] != data ) i++;

	if ( i == size )
		return NULL;
	else
		return arr + i;
}

void _buildTree( Tree root, ElementType *preOrder, ElementType *inOrder, int size, int direct )
{
	if ( size > 0 )
	{
		root  = insert( root, *preOrder, direct );
		// printf("insert node data = %d\n", root->data );

		ElementType  * iptr = find( inOrder, size, *preOrder );
		int lsize, rsize;
		if ( iptr )
		{
			lsize  = iptr - inOrder;
			rsize  = size - lsize - 1;

			if ( lsize > 0 )
				_buildTree( root, preOrder + 1, inOrder, lsize, -1 );

			if ( rsize > 0 )
				_buildTree( root, preOrder + lsize + 1, iptr + 1, rsize, 1 );
		}	
	}
}

Tree  buildTree( ElementType *preOrder, ElementType *inOrder, int size )
{
	Position  root = createNode( *preOrder );

	_buildTree( root, preOrder, inOrder, size, 0 );

	return root;
}

void pstReview( Tree root )
{
	if ( root )
	{
		pstReview( root->left );
		pstReview( root->right );
		printf(" %d", root->data );
	}
}