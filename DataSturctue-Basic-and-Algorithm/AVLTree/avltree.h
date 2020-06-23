typedef  int       ElementType;
typedef  struct _avlnode  AVLN;
typedef  AVLN *          AVLNP;
typedef  AVLNP         AVLTree;
struct _avlnode
{
	ElementType  data;
	AVLTree      left;
	AVLTree     right;
};

AVLTree LLRotate( AVLNP nbPtr );
AVLTree LRRotate( AVLNP nbPtr );
AVLTree RRRotate( AVLNP nbPtr );
AVLTree RLRotate( AVLNP nbPtr );
AVLTree Rotate( AVLNP nbPtr, AVLNP iPtr );
int getHeight( AVLTree tr );
int getBalanceFactor( AVLTree tr );
AVLNP getPreNode( AVLTree tr, AVLNP nPtr );
AVLNP insertNode( AVLTree tr, AVLNP nPtr );
inline AVLNP nodeCreate( ElementType elem );
AVLTree buildAVLTree( ElementType *arr, int size );