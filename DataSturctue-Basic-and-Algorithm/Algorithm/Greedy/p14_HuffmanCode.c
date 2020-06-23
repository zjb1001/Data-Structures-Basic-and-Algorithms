#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef  struct HUFFCODE Huffcode; 
struct HUFFCODE {
    char *code;
    char lett;
};

//  bstree head
typedef struct card Card;
struct card {
    char lett;
    int  freq;
};

typedef Card      BSTElementType;
typedef struct _bstnode     BSTN;
typedef BSTN  *           BSTree;
struct _bstnode {
    BSTElementType   data;
    BSTree left;
    BSTree right;
};
// 
// minheap head
#define  mindata -19999
typedef  BSTree      HPElementType;
typedef  HPElementType *  Position;
typedef  struct _minheap   MinHeap;
struct _minheap {
    HPElementType  *data;
    int   size;
    int   capacity;
};

int           _heapcmp( HPElementType va, HPElementType vb );
MinHeap       * minHeapCreate( int capa );
int           isMinHeapEmpty( MinHeap *hp );
int           isMinHeapEmpty( MinHeap *hp );
Position      insertMinHeap( MinHeap *hp, HPElementType ev );
int           shiftDown( MinHeap *hp,  int parent, HPElementType ev, int (*Cmp)( HPElementType, HPElementType ) );
MinHeap       *bulidMinHeap( HPElementType *arr, int size );
HPElementType popMinHeap( MinHeap *hp );
void          previewMinHeap( MinHeap *hp );
// 

int     isBstElementEqual( BSTElementType eva, BSTElementType evb );
BSTN    *bstNodeCreate( BSTElementType ev );
int     treeCmp( BSTree ta, BSTree tb );
BSTree  mergeBSTree( BSTree atr, BSTree btr );

void readInput( BSTree *arr, int size )
{
    BSTree *ptr = arr;
    for ( ; arr < ptr + size; arr++ )
    {
        BSTElementType ev;
        scanf(" %c %d",  &ev.lett, &ev.freq );       
        *arr = bstNodeCreate( ev );
    }
}

void preViewTree( BSTree bst )
{
    if ( bst )
    {
        printf( "%d ", bst->data.freq );
        preViewTree( bst->left );
        preViewTree( bst->right );
    }
}

void prtArr( char *code, int size )
{
    int i = 0;
    while (i < size )
        printf( "%c", code[i++] );
    printf("\n");
}
// /*
void prtHuffCode( BSTree bst, char *code, int top )
{
    // printf( "%s\n", code );
    if ( !bst ) return;

    if ( bst->data.lett == '+' )
    {
        if ( bst->left )
        { 
            code[top] = '0';
            prtHuffCode( bst->left,  code, top + 1 );
        }
        
        if ( bst->right )
       {
           code[top ] = '1';
           prtHuffCode( bst->right, code, top + 1 );
       }
       // end branch  
    }
    else 
    {
        // strcat( code, "\0" );
        // printf( "%c:%s\n", bst->data.lett, code );
        printf( "%c:", bst->data.lett );
        prtArr( code , top );
    } // end if
}

void getHuffCode( BSTree bst, char *code, int top, Huffcode *hfcode, int *curr )
{
    // *code to store walk down path, top mark leaf huffman code size
    // *hfcode is array of struct {char * code; char lett}.
    // *curr is array index
    if ( !bst ) return;

    if ( bst->data.lett == '+' )
    {
        if ( bst->left )
        { 
            code[top] = '0';
            getHuffCode( bst->left,  code, top + 1, hfcode, curr );
        }
        
        if ( bst->right )
       {
           code[top ] = '1';
           getHuffCode( bst->right, code, top + 1, hfcode, curr );
       } // end child branch  
    }
    else 
    {
        strncpy( hfcode[*curr].code, code, top ); 
        hfcode[*curr].code[top] = '\0';       
        hfcode[*curr].lett = bst->data.lett;
        *curr += 1;
    } 
}

int getWslHuffTree( BSTree bst, int height )
{
    if ( !bst ) return 0;

    if ( bst->data.lett != '+' )
        return height * bst->data.freq;

    if ( bst->data.lett == '+' )
        return  getWslHuffTree(bst->left, height + 1) +  getWslHuffTree( bst->right, height + 1);
}

// build huffmantree 
// parameters: treeNodesArr
BSTree buildHuffManTree( BSTree *treeArr, int size )
{
    MinHeap *order = bulidMinHeap( treeArr, size );

    BSTree  bstr   = NULL;
    while ( !isMinHeapEmpty( order ) && order->size != 1 )
    {
        HPElementType eva = popMinHeap( order );
        HPElementType evb = popMinHeap( order );
        bstr = mergeBSTree( eva, evb );
        
        // preViewTree( bstr ); printf( "\n" );
        
        insertMinHeap( order, bstr );
    } // end while
    if ( order->size )
        bstr = popMinHeap( order );

	free( order->data );
    free( order );

    return bstr;
}

int checkPreCode ( Huffcode *hcode, int size )
{
    int ans = 1;
    BSTElementType bev = { '+', 0 };
    BSTree bstr = bstNodeCreate( bev );
    BSTree pbst  = bstr;
    int i = 0;
    for ( ; i < size; i++ )
    {
        char *pch = hcode[i].code;
        int length= strlen( hcode[i].code );
        while ( pch - hcode[i].code < length )
        {
            if ( (*pch) == '0' )
            {
                if ( !pbst->left )
                {
                    pbst->left = bstNodeCreate( bev );
                    pbst = pbst->left;
                }
                else if ( pbst->left->data.lett != '+' )
                {
                    ans = 0;
                    break;
                }
                else 
                    pbst = pbst->left;                
            }

            if  ( (*pch) == '1' )
            {
                if ( !pbst->right )
                {
                    pbst->right = bstNodeCreate( bev );
                    pbst = pbst->right;
                }
                else if ( pbst->data.lett != '+' )
                {
                    ans = 0;
                    break;
                }
                else 
                    pbst = pbst->right;
            }

            pch++;               
        } // end while, and update pbst pointer data value

        if ( !ans ) break;
        
        if ( pbst->left || pbst->right)
        {
            ans = 0;
            break;
        }
        else 
            pbst->data.lett = hcode[i].lett;
        pbst = bstr;      // pbst pointe to tree root
    }
    
    return ans;
}

int checkHuffCode( BSTree *bstArr, int size, int wsl )
{
    Huffcode hcode[size];
    int i, useWsl = 0;
    for ( i = 0; i < size; i++ )
        hcode[i].code = (char *)malloc( sizeof( char ) * size );

    for ( i = 0; i < size; i++ )
    {
        scanf(" %c %s", &hcode[i].lett, hcode[i].code);
        useWsl += strlen( hcode[i].code ) * bstArr[i]->data.freq;
    }
    
    if ( useWsl != wsl )
        return 0;

    return checkPreCode( hcode, size );
}
// A 1 B 1 C 1 D 3 E 3 F 6 G 6

int main ( int argc, char **argv )
{
    char *code;
    int size, i;

    scanf("%d", &size);  // get members size 

    BSTree *treeArr    = (BSTree *)malloc( sizeof(BSTree) * (size) );
    readInput( treeArr, size );
  
    BSTree  bstr = buildHuffManTree( treeArr, size );
    
    Huffcode hfcode[size];  
    for ( i = 0; i < size; i++ )
        hfcode[i].code = (char *)malloc( sizeof(char) * size );

    code = (char *)malloc( sizeof(char) * size );
  
    int wsl = 0;
    wsl = getWslHuffTree( bstr, 0 );
    // printf( "wsl= %d\n", wsl );

    int qsize;
    scanf("%d", &qsize);
    for ( i = 0; i < qsize; i++ )
    {
        int check = checkHuffCode( treeArr, size, wsl );

        if ( !check )
            printf( "No\n");
        else 
            printf( "Yes\n" );
    }
    
    free( treeArr );  free( code );

    return 0;
}

int  isBstElementEqual( BSTElementType eva, BSTElementType evb )
{
    return ( eva.freq == evb.freq ) && (!strcmp(&eva.lett, &evb.lett) );
}

BSTN *bstNodeCreate( BSTElementType ev )
{
    BSTN * newn = (BSTN *)malloc( sizeof(BSTN) );

    newn->data  = ev;
    newn->left  = newn->right = NULL;

    return newn;
}

int treeCmp( BSTree ta, BSTree tb )
{
    return ta->data.freq - tb->data.freq;
}

BSTree mergeBSTree( BSTree atr, BSTree btr )
{
    if ( !atr && !btr )   return NULL;  
    if ( !atr && btr  )   return btr;
    if (  atr && !btr )   return atr;

    BSTN * nroot = (BSTN *)malloc( sizeof( BSTN ) );
    nroot->data.lett = '+';
    nroot->data.freq = atr->data.freq + btr->data.freq;
    nroot->left  = atr; 
    nroot->right = btr;

    return nroot;
}

MinHeap * minHeapCreate( int capa )
{
    MinHeap * hp = (MinHeap *)malloc( sizeof(MinHeap) );

    hp->capacity = capa;
    hp->size     = 0;
    hp->data     = (HPElementType *)malloc( sizeof(HPElementType) * (capa + 1) );
    hp->data[0]  = (HPElementType)malloc( sizeof( BSTN ) );
    hp->data[0]->data.freq = mindata;

    return hp;
}

int isMinHeapEmpty( MinHeap *hp )
{
    return hp->size == 0;
}

int isMinHeapFull( MinHeap *hp )
{
    return hp->size == hp->capacity;
}

int _heapcmp( HPElementType va, HPElementType vb )
{
    return va->data.freq - vb->data.freq;
}

void  previewMinHeap( MinHeap *hp )
{
    int i;
    for ( i = 1; i <= hp->size; i++ )
        printf( "%c ", hp->data[i]->data.lett );
    printf("\n");
}

Position insertMinHeap( MinHeap *hp, HPElementType ev )
{
    if ( isMinHeapFull(hp) )
    {
        printf("heap full\n");
        return;
    }

    // printf( "before insert size=%d\n", hp->size );
    int idx = ++hp->size;
    for (  ; _heapcmp( hp->data[idx / 2], ev ) > 0; idx /= 2 )
        hp->data[idx] = hp->data[idx / 2];

    hp->data[idx]  = ev;

    return hp->data + idx + 1;
}

int  shiftDown( MinHeap *hp,  int part, HPElementType ev, 
                int (*Cmp)( HPElementType, HPElementType ) )
{ 
    int parent = part;
    for (   ; parent * 2 <= hp->size;  )
    {
        int child  = parent * 2;
        if ( child != hp->size  && Cmp( hp->data[child],  hp->data[child + 1] ) > 0 )
            child++;

        if ( Cmp( hp->data[child], ev ) >= 0 ) 
            break;
        else 
        {
            hp->data[parent] = hp->data[child];
            parent = child;
        }
    } // end for

    return parent;
}

MinHeap *bulidMinHeap( HPElementType *arr, int size )
{
    MinHeap *hp = minHeapCreate( size * 2 );
    HPElementType *src, *dst;
    src = arr; dst = hp->data + 1;
    for ( ; src < arr + size; ) 
    {
        *dst++ = *src++;
        hp->size++;
    }

    int parent = hp->size / 2;
    while ( parent > 0 )
    {
        int tmp = parent;

        HPElementType ev = hp->data[parent];
        parent = shiftDown( hp,  parent, ev, &_heapcmp );     
        hp->data[parent] = ev;

        parent = tmp - 1;
    } // end while

    return hp;
}

HPElementType popMinHeap( MinHeap *hp )
{
    HPElementType ans = hp->data[1];

    HPElementType ev  = hp->data[hp->size--];
    if ( !isMinHeapEmpty( hp ) )
    {   
        int parent = shiftDown( hp, 1, ev, &_heapcmp );
        hp->data[parent] = ev;
    }
    
    return ans;
}