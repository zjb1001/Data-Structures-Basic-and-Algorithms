#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );
List Reverse( List L );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    // for ( Position P=L; P; P = P->Next ) printf("%d ", P->Data);
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }

    // printf("X= %d\n", X);
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

Position Find( List L, ElementType X )
{
    while (L)
    {
        if (L->Data == X)
            break;
        
        L = L->Next;
    }

    if ( L )
        return L;
    else 
        return ERROR;
}

List Insert( List L, ElementType X, Position P )
{
    if (P != L) {
        Position preP = L;
        while(preP && preP->Next != P)
            preP = preP->Next;

        if (!preP) {
            printf("Wrong Position for Insertion\n");
            return ERROR;
        }
        else {
            Position newN = (Position)malloc(sizeof(struct LNode));
            newN->Data = X;
            newN->Next = preP->Next;
            preP->Next = newN;
            return L;
        }
    }
    else 
    {
        Position newN = (Position)malloc(sizeof(struct LNode));
        newN->Data = X;
        newN->Next = L;
        return newN;
    }
}

List Delete( List L, Position P )
{
    if (P == L) {
        Position head = L->Next;
        free(L);
        return head;
    }
    else {
        Position preP = L;
        while (preP && preP->Next != P)
            preP = preP->Next;
        
        if ( preP ) {
            preP->Next = P->Next;
            free(P);
            return L;
        }
        else {
            printf("Wrong Position for Deletion\n");
            return ERROR;
        } 
    }
}

List Reverse( List L )
{
    PtrToLNode preN = NULL;
    PtrToLNode nxtN;
    while (L) {
        nxtN = L->Next;
        L->Next = preN;
        preN = L;
        L    = nxtN;
    }

    return preN;
}
