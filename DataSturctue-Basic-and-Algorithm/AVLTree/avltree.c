#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

inline AVLNP nodeCreate( ElementType elem )
{
	AVLN *nPtr = (AVLNP)malloc( sizeof( ElementType ) );
	nPtr->data  = elem;
	nPtr->left  = nPtr->right = NULL;

	return nPtr;
}

AVLTree buildAVLTree( ElementType *arr, int size )
{
	if ( !size )
		return NULL;

	AVLTree root = nodeCreate( arr[0] );

	int i = 1;
	for (  ; i < size; i++ )
	{
		AVLNP tmpPtr  = nodeCreate( arr[i] );		
		insertNode( root, tmpPtr );
		
		AVLNP partPtr = getPreNode( root, tmpPtr );
		int b_factor  = getBalanceFactor( partPtr );
        // printf("curdata=%d, partdata=%d, b_factor=%d \n", tmpPtr->data, partPtr->data, b_factor );

        int i = 1;
		while ( b_factor != -2 && b_factor != 2 && i < 4 )
		{           
            partPtr = getPreNode( root, partPtr );
            if ( partPtr )
                b_factor = getBalanceFactor( partPtr );
            else 
                break;
            i++;
            // printf("partPtr=%d, b_factor=%d\n", partPtr->data, b_factor );
        } // while loop

        if (partPtr && partPtr->data != root->data )
        {
            AVLNP oneMoreUp = getPreNode( root, partPtr );
			if ( oneMoreUp->left == partPtr )
				oneMoreUp->left  = Rotate ( partPtr, tmpPtr );
			else
				oneMoreUp->right = Rotate ( partPtr, tmpPtr ); 
        }   
        else if (partPtr && partPtr->data == root->data )
        {
            root = Rotate ( partPtr, tmpPtr );	
            // printf("After modify %d\n", root->data );
        }
                   
	} // for loop

	return root;
}

int getHeight( AVLTree tr )
{
    if ( !tr )
        return 0;
    
    if ( tr && !tr->left && !tr->right )
        return 1;

 
    int lhgt = 1 + getHeight( tr->left );
    int rhgt = 1 + getHeight( tr->right );

    return lhgt > rhgt ? lhgt : rhgt;
   
}

int getBalanceFactor( AVLTree tr )
{
    int lsonhgt = getHeight( tr->left );
    int rsonhgt = getHeight( tr->right );

    return rsonhgt - lsonhgt;
}

AVLNP getPreNode( AVLTree tr, AVLNP nPtr )
{
    if ( !tr )
        return NULL;

    if (nPtr == tr)
        return NULL;

    while ( tr )
    {
        if ( tr->left == nPtr || tr->right == nPtr )
            break;

        if ( nPtr->data < tr->data )
            tr = tr->left;
        else
            tr = tr->right;    
    }

    return tr;
}

AVLNP insertNode( AVLTree tr, AVLNP nPtr )
{
    while ( tr )
    {
        if ( nPtr->data < tr->data )
        {
            if ( !tr->left )
            {
                tr->left = nPtr;
                break;
            }
            else 
            {
                tr = tr->left;
                continue;
            }
        }

        if ( nPtr->data > tr->data )
        {
            if ( !tr->right )
            {
                tr->right = nPtr;
                break;
            }
            else
            {
                tr = tr->right;
                continue;
            }    
        }
    } // while loop

    return nPtr;
}

AVLTree LLRotate( AVLNP nbPtr )
{
    AVLNP nroot = nbPtr->left;
    nbPtr->left = NULL;

    if ( !nroot->right )
        nroot->right = nbPtr;
    else 
    {
        nroot->right->right = nbPtr;
        nroot->right = RRRotate( nroot->right );
    }

    return nroot;
}

AVLTree LRRotate( AVLNP nbPtr )
{
    AVLNP nroot = nbPtr->left->right;
    AVLNP lson  = nbPtr->left;
    lson->right= NULL;

    if ( nroot->left )
    {
        nroot->left->left = nbPtr->left;
        nbPtr->left = NULL;
        nroot->right= nbPtr;
        nroot->left = LLRotate( nroot->left );    // pay attention to function parameters
    }
    else if ( nroot->right )
    {
        nroot->left = nbPtr->left;
        nbPtr->left = NULL;
        nroot->right->right = nbPtr;
        nroot->right = RRRotate( nroot->right );  // pay attention to function parameters
    } 
    else
    {
        nroot->left = nbPtr->left;
        nbPtr->left = NULL;
        nroot->right= nbPtr;
    }
 
    return nroot;
}

AVLTree RRRotate( AVLNP nbPtr )
{
    AVLNP  nroot = nbPtr->right;
    nbPtr->right= NULL;

    if ( !nroot->left )
        nroot->left = nbPtr;
    else
    {
        nroot->left->left = nbPtr;
        nroot->left  = LLRotate( nroot->left );
    }
    
    return nroot;    
}

AVLTree RLRotate( AVLNP nbPtr )
{
    AVLNP nroot = nbPtr->right->left;
    AVLNP rson  = nbPtr->right;
    rson->left = NULL;

    if ( nroot->left )
    {
        nroot->left->left = nbPtr;
        nroot->right = nbPtr->right;
        nbPtr->right = NULL;
        nroot->left  = LLRotate( nroot->left );
    }
    else if ( nroot->right )
    {
        nroot->left = nbPtr;
        nroot->right->right = nbPtr->right;
        nbPtr->right = NULL;
        nroot->right = RRRotate( nroot->right );
    }
    else
    {
        nroot->left = nbPtr;
        nroot->right= nbPtr->right;
        nbPtr->right= NULL;
    }
    
    return nroot;    
}

AVLTree Rotate( AVLNP nbPtr, AVLNP iPtr )
{
    if ( iPtr->data < nbPtr->data )
    {
        if ( iPtr->data < nbPtr->left->data )
            return LLRotate( nbPtr );
        else
            return LRRotate( nbPtr );
    }
    else
    {
        if ( iPtr->data > nbPtr->right->data )
            return RRRotate( nbPtr );
        else
            return RLRotate( nbPtr );        
    }
}