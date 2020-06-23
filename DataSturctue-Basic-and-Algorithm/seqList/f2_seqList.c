#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 5
#define ERROR -1
typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}

// 创建并返回一个空的线性表；
List MakeEmpty()
{
    List L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;

    return L;
}

// 返回线性表中X的位置。若找不到则返回ERROR；
Position Find( List L, ElementType X )
{
    int i = 0;
    for ( ; i <= L->Last && X != L->Data[i]; i++ );
    
    return (i <= L->Last) ? i : ERROR;
}

// 将X插入在位置P并返回true。若空间已满，则打印“FULL”并返回false；如果参数P指向非法位置，则打印“ILLEGAL POSITION”并返回false；
bool Insert( List L, ElementType X, Position P )
{
    if (L->Last == MAXSIZE - 1) {
        printf("FULL");
        return false;
    }

    else if (P > L->Last + 1) {
        printf("ILLEGAL POSITION");
        return false;
    }

    else if (P == L->Last + 1) {
        L->Data[++L->Last] = X;
        return true;
    }
        
    
    else {
        L->Last++;
        for (int end = L->Last; end > P; end--)
            L->Data[end] = L->Data[end - 1];
        
        L->Data[P] = X;

        return true;
    }
}

// 将位置P的元素删除并返回true。若参数P指向非法位置，则打印“POSITION P EMPTY”（其中P是参数值）并返回false。
bool Delete( List L, Position P )
{
    if ( P > L->Last || P < 0) {
        printf("POSITION %d EMPTY", P);
        return false;
    }
    else {
        for (int start = P; start + 1 <= L->Last; start++)
            L->Data[start] = L->Data[start + 1];

        L->Last--;
        return true;
    }
}