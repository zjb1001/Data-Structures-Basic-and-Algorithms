#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); 
void Print( List L ); 

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);

    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

void Print( List L )
{
    PtrToNode curPtr = L->Next;

    if (curPtr)
    {
        while (curPtr)
        {
            printf(" %d", curPtr->Data);
            curPtr = curPtr->Next;
        }
        printf("\n"); 
    } else {
        printf("NULL\n");
    }
   
}

List Merge( List L1, List L2 )
{
    List L = (List)malloc(sizeof(struct Node));

    PtrToNode curPtr = L, aPtr = L1->Next, bPtr = L2->Next;

    while (aPtr && bPtr)
    {
        if (aPtr->Data <= bPtr->Data)
        {
            curPtr->Next = aPtr;
            aPtr = aPtr->Next;
        } else {
            curPtr->Next = bPtr;
            bPtr = bPtr->Next;
        }
        curPtr = curPtr->Next;
    }

    curPtr->Next = aPtr ? aPtr : bPtr;

    L1->Next = NULL;
    L2->Next = NULL;

    return L;
}

List Read()
{
    int knum;
    scanf("%d", &knum);

    List L = (List)malloc(sizeof(struct Node));

    PtrToNode curPtr = L;
    int i = 0;
    while (i < knum)
    {
        curPtr->Next = (PtrToNode)malloc(sizeof(struct Node));
        curPtr = curPtr->Next;
        scanf("%d", &curPtr->Data);
        curPtr->Next = NULL;
        i++;
    }

    // printf("L last element is= %d\n", L->Data);
    return L;
}