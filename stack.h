typedef  int  ElementType;
typedef  struct _snode SN;
typedef  SN *         ST;
struct _snode {
    ElementType  *data;
    int capacity;
    int size;
};

int isEmpty(ST st);
ElementType Pop(ST st);
void Push(ST st, ElementType elem);
int isFull(ST st);


int isEmpty(ST st)
{
    return st->size == -1;
}

ElementType Pop(ST st)
{
    return st->arr[st->size--];
}

void Push(ST st, ElementType elem)
{
    st->arr[++st->size]  = elem;
}

int isFull(ST st)
{
    return st->size == st->capacity - 1;
}

ST initStack(int capa)
{
    ST st  = (ST)malloc( sizeof(SN) );
    st->capacity  = 100;
    st->size      = -1;
    st->data      = (ElementType *)malloc( sizeof(ElementType) * st->capacity );
    
    return st;
}

int main()
{
    ST  ids  = initStack( 100 );
    int  i   = 0, m = 10;
    while ( i < m )
        if ( !isFull(ids) )  Push( ids, i++ ) 

    while ( i-- )
        if ( !isEmpty(ids) ) 
            printf( "%d ", Pop( ids) );

    return 0;
}