#include <stdio.h>
#include <stdlib.h>

typedef int  ElementType;
typedef struct _tnode TN;
typedef TN *   Position;
typedef Position BTree;
struct _tnode {
    ElementType  data;
    Position     left;
    Position     right;
};

typedef struct _qnode QN;
typedef QN * PQ;
struct _qnode {
    Position queue[100];
    int start;
    int tail;
    int capacity;
};

int isEmpty(PQ q)
{
	if ( q->start == -1 && q->tail == -1 )
		return 1;
		
    return  (q->tail < q->start ) ? 1 : 0;
}

Position Dequeue(PQ q)
{
    if ( !isEmpty(q) )
        return q->queue[q->start++];

    return NULL;
}

int Enqueue(PQ q, Position iPtr)
{
//	printf("\nstart enqueue is %d %d\n", q->start, q->tail);
	
    if ( q->tail == q->capacity - 1  && q->start == 0)
    {
        printf("Queue full\n");
        return 0;
    }

    if ( q->tail == q->capacity - 1  && q->start != 0 )
    {
        int i, j = 0;
        for( i = q->start; i <= q->tail; i++ )
            q->queue[j++] = q->queue[i];

        q->tail  = q->tail - q->start;  q->start  = 0;  
    }
    
    if ( isEmpty(q) )
    {
//    	printf("empty enqueue\n");
    	q->start  =  q->tail  = -1;
    	
    	q->queue[++q->tail]  = iPtr;
		q->start++;	
	} 
	else
		q->queue[++q->tail]  = iPtr;
    	
//	printf("after enqueue is %d %d\n", q->start, q->tail);
	
    return 1;
}

char ** readInput(int row, int column);
void prt2DArr(char ** arr, int row, int column);

Position  insertNode( BTree BST, ElementType data , int direct)
{
    Position iPtr  = ( Position )malloc( sizeof(TN) );
    iPtr->data  = data;
    iPtr->left  =  iPtr->right  = NULL;

    if ( direct == 0 )
        BST->left  = iPtr;
    else if ( direct  == 1 )
        BST->right  = iPtr;

    return iPtr;
}

BTree  createTree(char ** arr, int row, int column)
{
    int check[row];
    int i = -1;
    while ( ++i < row ) check[i] = -1;

    int j;
    for ( i = 0; i < row; i++ )
        for ( j = 0; j < column; j++ )
            if ( arr[i][j] != '-')     
                check[ arr[i][j] - '0' ] = 1;

    Position nodes[row];
    i = 0;
    while (i < row)
    {
        Position iPtr = (Position)malloc( sizeof(TN) );
        iPtr->data = i;
        iPtr->left = iPtr->right = NULL;

        nodes[i++]  = iPtr;
    }

    i  = 0;
    while ( i < row )
    {
        if ( arr[i][0] != '-' )
            nodes[i]->left  = nodes[arr[i][0] - '0'];
        
        if ( arr[i][1] != '-' )
            nodes[i]->right = nodes[arr[i][1] - '0'];

        i++;
        // printf("connecting %d\n",  i);
    }

    i = 0;
    while ( check[i] != -1 ) i++;
    BTree root = nodes[i];

    return root;
}

void  preOrderReview(BTree BST)
{
    if ( BST )
    {
        printf("%d ",  BST->data);
        preOrderReview(BST->left);
        preOrderReview(BST->right);
    }
}

void bfsOrderReview( BTree BST, int flag )
{
    PQ  q  = (PQ)malloc( sizeof(QN) );
    q->start = q->tail  = -1;
    q->capacity  = 100;

    Enqueue( q, BST );

    while ( !isEmpty(q) )
    {
        Position iPtr  = Dequeue( q );
        if ( iPtr )
        {
            if ( !iPtr->left && !iPtr->right ) 
            {
                if ( !flag )
                {
                    printf("%d", iPtr->data );
                    flag  = 1;
                }
                else
                    printf(" %d", iPtr->data );  
            }
            
        	if ( iPtr->left )
           	 	Enqueue( q, iPtr->left );
            
        	if ( iPtr->right )
            	Enqueue( q, iPtr->right );

        }
    }       
}

int main()
{
    int num;
    scanf("%d", &num);
    char **arr  = readInput(num, 2);
    // prt2DArr(arr, num, 2);

    BTree btree  = createTree(arr, num, 2);
    // preOrderReview(btree);
    
    // printf("root exists: %d\n", btree->data);
    bfsOrderReview(btree, 0);
    
    return 0;
}

char ** readInput(int row, int column)
{
    char **arr = (char **)malloc( sizeof(char *) * row );
    int i = 0;
    while (i < row )
    {
        arr[i]  = (char *)malloc( sizeof(char) * column );
        scanf(" %c %c", &arr[i][0], &arr[i][1] );
        
        i++;
    }

    return arr;
}

void prt2DArr(char ** arr, int row, int column)
{
    int i, j;
    for ( i = 0; i < row; i++ )
    {
        for ( j = 0 ; j < column; j++)
            printf("%c ", arr[i][j]);
        
        printf("\n");
    }
}