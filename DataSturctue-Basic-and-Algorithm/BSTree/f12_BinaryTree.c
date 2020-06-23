#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

// 函数Insert将X插入二叉搜索树BST并返回结果树的根结点指针；
// 函数Delete将X从二叉搜索树BST中删除，并返回结果树的根结点指针；如果X不在树中，则打印一行Not Found并返回原树的根结点指针；
// 函数Find在二叉搜索树BST中找到X，返回该结点的指针；如果找不到则返回空指针；
// 函数FindMin返回二叉搜索树BST中最小元结点的指针；
// 函数FindMax返回二叉搜索树BST中最大元结点的指针。
BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}

// 函数Insert将X插入二叉搜索树BST并返回结果树的根结点指针；
BinTree Insert( BinTree BST, ElementType X ) 
{
    Position root = BST;

    Position newN = (Position)malloc(sizeof(struct TNode));
    newN->Data = X;
    newN->Left = NULL;
    newN->Right= NULL;

    if (!BST)
        root = newN;

    else {
        while (BST) {
            if ( X < BST->Data && !BST->Left ) {
                BST->Left = newN;
                break;
            }
            else if ( X < BST->Data && BST->Left )
                BST = BST->Left;

            else if ( X > BST->Data && !BST->Right) {
                BST->Right = newN;
                break;
            } 
            else 
                BST = BST->Right;
        }
    }

    return root;
}

// BinTree Insert( BinTree BST, ElementType X ) 
// {
//     if (!BST) {
//         Position newN = (Position)malloc(sizeof(struct TNode));
//         newN->Data = X;
//         newN->Left = NULL;
//         newN->Right= NULL;

//         BST = newN;
//     }

//     else if ( X < BST->Data ) 
//         BST->Left = Insert(BST->Left, X);

//     else if ( X > BST->Data ) 
//         BST->Right = Insert(BST->Right, X);

//     return BST;
// }

// 函数Find在二叉搜索树BST中找到X，返回该结点的指针；如果找不到则返回空指针；
Position Find( BinTree BST, ElementType X )
{
    Position found = NULL;

    while(BST) {
        if ( X == BST->Data ) {
            found = BST;
            break;
        }
            
        else if ( X < BST->Data )
            BST = BST->Left;

        else 
            BST = BST->Right;
    }

    return found;
}

// 函数FindMin返回二叉搜索树BST中最小元结点的指针;
Position FindMin( BinTree BST )
{
    Position minN;
    if (!BST) 
        minN = BST;
    else {
        while (BST->Left)
            BST = BST->Left;
        minN = BST;
    }
    
    return minN;
}

// 函数FindMax返回二叉搜索树BST中最大元结点的指针。
Position FindMax( BinTree BST )
{
    Position maxN;
    if (!BST)
        maxN = BST;
    else {
        while (BST->Right)
            BST = BST->Right;
        maxN = BST;
    }

    return maxN;
}

// 函数Delete将X从二叉搜索树BST中删除，并返回结果树的根结点指针；如果X不在树中，则打印一行Not Found并返回原树的根结点指针；
BinTree Delete( BinTree BST, ElementType X )
{
    Position tmpN;

    if (!BST) {
        printf("Not Found\n");
        // return BST;
    }
        
    else if (X < BST->Data) 
        BST->Left = Delete(BST->Left, X);

    else if (X > BST->Data)
        BST->Right= Delete(BST->Right, X);
    
    else if (BST->Left && BST->Right) {
        tmpN = FindMax(BST->Left);
        BST->Data = tmpN->Data;
        BST->Left = Delete(BST->Left, tmpN->Data); // replace X by leftMax->data!!!
    }

    else {
        tmpN = BST;

        if (BST->Left == NULL) 
            BST = BST->Right;
    
        else if(BST->Right == NULL)
            BST = BST->Left;

        free(tmpN);
    }
    
    return BST;
}

void PreorderTraversal( BinTree BT ) 
{
    if (BT) {
        printf(" %d", BT->Data);
        PreorderTraversal(BT->Left);        
        PreorderTraversal(BT->Right);
    }
}

void InorderTraversal( BinTree BT ) 
{
    if (BT) {
        InorderTraversal(BT->Left);  
        printf(" %d", BT->Data);              
        InorderTraversal(BT->Right);
    }
}