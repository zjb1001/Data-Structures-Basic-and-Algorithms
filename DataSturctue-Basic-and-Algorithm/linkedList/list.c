#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Node
{
    int         Element;
    Position    Next;
};

// Initialize list L
List Initialize( )
{
    Position head;

    head = (Position) malloc( sizeof(struct Node) );
    head->Next = NULL;
    
    return head;
}

// Return ture if list is empty
int IsEmpty( List L )
{
    return L->Next == NULL;
}

// Clear members in list
List MakeEmpty( List L )
{
    if ( IsEmpty(L) ) return L;

    Position P = L->Next;

    while( P ) 
    {
        free(P);
        P = P->Next;
    }

    L->Next = NULL;

    return L
}

// Create linked temp node
Position CreateNode( int X )
{
    Position tmpCell;

    tmpCell = (Position) malloc( sizeof(struct Node) );
    tmpCell->Element = X;
    tmpCell->Next     = NULL;

    return tmpCell;
}

// Add member to last position
List Append( int X, List L )
{
    // Alloca memory to new node
    Position valueCell = CreateNode( X );

    if ( IsEmpty(L) ) 
    {
        L->Next = valueCell;  // why i can't using P = valueCell
    }
    else 
    {
        Position P = L->Next; // Assuming header exist!

        while( P->Next ) P = P->Next;

        P->Next = valueCell;
    }
    //
    return L;
}

Position Last( List L )
{
    if ( IsEmpty(L) )
        return L->Next;

    Position P = L->Next;

    while( P->Next ) P = P->Next;

    return P;
}

// Print member in L; 
void Print( List L )
{
    printf("====================Here are list members=======================\n");

    Position tmpCell = L->Next;

    while( tmpCell )
    {
        printf("%d ", tmpCell->Element);
        tmpCell = tmpCell->Next;
    }

    printf("\n");
}


int main( )
{
    // List names = CreateList();
    List names = Initialize();

    Position lastMember = Last( names );
    if ( lastMember ) 
        printf("Last Function call: last member is %d \n", lastMember->Element);
    else
        printf("Last Function call: NULL linked list \n");
    

    // check empty list
    // if ( IsEmpty(names) ) 
    //     printf("Yes, it is an empty list!\n");
    // else
    //     printf("Wor, It is not an empty list\n");

    int ids[] = { 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010 };
    int size = sizeof(ids) / sizeof(int);
    int *ptr = ids;

    while( size-- )
        names = Append( *ptr++, names );

    Print(names);

    lastMember = Last( names );
    if ( lastMember ) 
        printf("Last Function call: last member is %d \n", lastMember->Element);
    else
        printf("Last Function call: NULL linked list \n");

    // Position head = Header(names);
    // printf("first member is %d \n", head->Element);
    

    // Position where = Find( 1003, names );
    // printf("Found member data is %d \n", where->Element);

    return 0;
}