typedef  int   ElementType;
typedef  struct _tnode  TN;
typedef  TN *     Position;
typedef  Position     Tree;
struct _tnode
{
	ElementType      data;
	struct _tnode *  left;
	struct _tnode * right;
};

Position createNode( ElementType dv );
Position insert( Position tPtr, ElementType dv, int direct );
ElementType * find ( ElementType * arr, int size, ElementType data );
void _buildTree( Tree root, ElementType *preOrder, ElementType *inOrder, int size, int direct );
Tree  buildTree( ElementType *preOrder, ElementType *inOrder, int size );
void pstReview( Tree root );


