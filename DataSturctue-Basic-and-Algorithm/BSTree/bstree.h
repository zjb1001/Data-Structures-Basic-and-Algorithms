typedef  int    ElementType;
typedef  struct _btnode BTN;
typedef  BTN *    BPoistion;
typedef  BPoistion   BSTree;
struct _btnode
{
	ElementType  data;
	BSTree       left;
	BSTree      right;
};

int isTreeMorphism( BSTree stree, BSTree ttree );
BPoistion insertBSTree( BPoistion bt, BPoistion tp );
BSTree  buildBSTree( ElementType * arr, int size );
void  preOrder( BSTree bs );