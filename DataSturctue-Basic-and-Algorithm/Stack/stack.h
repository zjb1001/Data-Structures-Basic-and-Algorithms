typedef  int  ElementType;
typedef  struct _snode SN;
typedef  SN *         ST;
struct _snode {
    ElementType  *data;
    int capacity;
    int top;
};

int isEmpty(ST st);
ElementType Pop(ST st);
void Push(ST st, ElementType elem);
int isFull(ST st);
ST initStack(int capa);
