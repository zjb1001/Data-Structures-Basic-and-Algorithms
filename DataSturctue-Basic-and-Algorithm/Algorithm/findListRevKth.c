#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
typedef int Position;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
typedef  PtrToLNode Head;
struct LNode
{
    ElementType Data;
    PtrToLNode  Next;
};

typedef struct List {
    Head Node;
    PtrToLNode Last;
} List;

PtrToLNode Insert( List *, ElementType, Position );
PtrToLNode InsertPtr( List *L, ElementType X, PtrToLNode nP );
PtrToLNode Append( List *, ElementType X );
PtrToLNode findRevKth( List *, int );
void readList( List *, int method );
void PrtList( List );
void Delete( List *L );

int main()
{
    int K;
    scanf("%d", &K);

    List L;
    L.Node = (Head)malloc( sizeof(struct LNode) );
    L.Node->Next = NULL;
    L.Last = L.Node;

    readList( &L, 0 );
    // PrtList( L );
    // for ( int i = 0; i < 5; i++ )
    // {
    //     PtrToLNode found = findRevKth( &L, i );
    //     if ( found )
    //         printf("-%dth %d\n", i, found->Data);
    //     else 
    //         printf("Not Found\n");
    // }  

    PtrToLNode found = findRevKth( &L, K );
    if ( found )
        printf("%d\n", found->Data);
    else 
        printf("NULL\n");

    Delete( &L );
    return 0;
}

void readList( List *L, int method )
{
    int dv, idx = 0;
    scanf(" %d", &dv);
    while ( dv != -1 )
    {
        switch (method) { 
            case 0:
                Append( L, dv );
                break;
            case 1:
                Insert( L, dv, idx );
                break;
            case 2:
                InsertPtr( L, dv, L->Last);
                break;
        }
        scanf(" %d", &dv);
        idx++;
    }
}

PtrToLNode Insert( List *L, ElementType X, Position P )
{
    int i = -1;
    PtrToLNode iPtr = L->Node;
    while ( ++i < P && iPtr )
        iPtr = iPtr->Next;

    if ( !iPtr && i != P ) 
        return NULL;

    PtrToLNode nPtr = (PtrToLNode)malloc( sizeof(struct LNode) );
    nPtr->Data = X;    
    nPtr->Next = iPtr->Next;
    iPtr->Next = nPtr;

    if ( !nPtr->Next )
        L->Last = nPtr;

    return nPtr;
}

PtrToLNode InsertPtr( List *L, ElementType X, PtrToLNode nP )
{
    PtrToLNode iPtr = L->Node;
    while ( iPtr && iPtr != nP )
        iPtr = iPtr->Next;

    if ( !iPtr )
        return NULL;

    PtrToLNode nPtr = (PtrToLNode)malloc( sizeof(struct LNode) );
    nPtr->Data = X;
    nPtr->Next = iPtr->Next;
    iPtr->Next = nPtr;

    if ( !nPtr->Next )
        L->Last = nPtr;

    return nPtr;
}

PtrToLNode Append( List *L, ElementType X )
{
    PtrToLNode nPtr = (PtrToLNode)malloc( sizeof( struct LNode) );
    nPtr->Data = X;
    nPtr->Next = NULL;
    L->Last->Next = nPtr;
    L->Last = nPtr;
}

PtrToLNode findRevKth( List *L, int K )
{
    PtrToLNode currP = L->Node->Next;
    PtrToLNode nxtKP = currP;
    int i = 0;
    while ( nxtKP && ++i < K )
        nxtKP = nxtKP->Next;
    
    if ( i != K )
        return NULL;

    while ( nxtKP != L->Last )
    {
        currP = currP->Next;
        nxtKP = nxtKP->Next;
    }

    return currP;
}

void PrtList( List L )
{
    PtrToLNode iPtr = L.Node->Next;
    while ( iPtr != L.Last )
    {
        printf("%d ", iPtr->Data);
        iPtr = iPtr->Next;
    }
        
    printf("%d\n", L.Last->Data);
}

void Delete( List *L )
{
    PtrToLNode iPtr = L->Node;
    while ( iPtr )
    {   
        PtrToLNode nxtPtr = iPtr->Next;
        free( iPtr );
        iPtr = nxtPtr;
    }
}