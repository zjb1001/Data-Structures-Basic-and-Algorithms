#include "bstree.h"
#include <stdlib.h>
#include <stdio.h>

void  preOrder( BSTree bs )
{
	if ( bs )
	{
		printf( " %d", bs->data );
		preOrder( bs->left );
		preOrder( bs->right );
	}
}

int isTreeMorphism( BSTree stree, BSTree ttree )
{
	if ( !stree && !ttree )
		return 1;
	
	if ( (stree && !ttree) || (!stree && ttree) )
		return 0;

	if ( stree->data != ttree->data )
		return 0;
	else
	{
		// printf("iteration loop check!\n");
		if ( !stree->left && !ttree->left && !stree->right && !ttree->right )
			return 1;

		// else if ( !isTreeMorphism( stree->left, ttree->left ) )
		// 	return 0;

		// else 
		// 	return isTreeMorphism( stree->right, ttree->right );

		return isTreeMorphism( stree->left, ttree->left ) ? isTreeMorphism( stree->right, ttree->right ) : 0;
	}    
}

BPoistion insertBSTree( BPoistion bt, BPoistion tp )
{
	if ( tp->data < bt->data )
	{
		if ( bt->left == NULL )
			bt->left  = tp;
		else
			insertBSTree( bt->left, tp );
	}
	else if ( tp->data > bt->data )
	{
		if ( bt->right == NULL )
			bt->right  = tp;
		else
			insertBSTree( bt->right, tp );
	}

	return tp;
}

BSTree  buildBSTree( ElementType * arr, int size )
{
	if ( !size )
		return NULL;

	BSTree btree  = (BSTree)malloc( sizeof( BTN ) );
	btree->data   = arr[0];
	btree->left   =  btree->right  = NULL;

	int i = 1;
	for (  ; i < size; i++ )
	{
		BPoistion iPtr = (BPoistion)malloc( sizeof( BTN ) );
		iPtr->data  = arr[i];
		iPtr->left  =  iPtr->right  = NULL;

		insertBSTree( btree, iPtr );
	}

	return btree;
}