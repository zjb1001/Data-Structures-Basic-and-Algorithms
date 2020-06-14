typedef int   ElementType;
typedef ElementType    HE;
typedef int         Index;
typedef struct _heap HEAP;
typedef HEAP *       HPtr;    
struct _heap {
    HE * data;
    int  capacity;
    int  start;
    int  size;
};
#define FullHeapError -1

void swapptr (HE *arr, Index i, Index j);
HPtr initHeap( int capacity );
int isEmptyHeap( HPtr hp );
int isFullHeap( HPtr hp );
Index PushHeap( HPtr hp, HE dv );
void prtPath( HPtr hp, Index idx );

