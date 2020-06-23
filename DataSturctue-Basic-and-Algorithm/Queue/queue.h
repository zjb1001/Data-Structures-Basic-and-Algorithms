typedef  int   ElementType;
typedef  struct _qelem     QE;
typedef  struct _queue  QUEUE;
typedef  QUEUE *         QPtr;
struct _queue
{
	QE     *data;
	int capacity;
	int    start;
	int     tail;
};
struct _qelem
{
	ElementType lidx;
	ElementType uidx;
};

QPtr  initQueue( int capa );
int isEmpty( QPtr q );
int isFull( QPtr q );
QE  deQueue( QPtr q );
void  enQueue( QPtr q, QE elem );
