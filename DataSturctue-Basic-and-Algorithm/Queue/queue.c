#include  "queue.h"
#include  <stdlib.h>


QPtr  initQueue( int capa )
{
	QPtr  Q  = (QPtr)malloc( sizeof( QUEUE ) );

	Q->capacity  = capa;
	Q->start  =  Q->tail  = -1;
	Q->data   = (QE *)malloc( sizeof( QE ) * capa );

	return Q;
}

int isEmpty( QPtr q )
{
	if ( q->start == -1 )
		return 1;

	if ( q->start > q->tail )
		return 2;

	return 0;
}

int isFull( QPtr q )
{
	if ( q->tail - q->start  ==  q->capacity - 1 )
		return 1;

	return 0;
}

QE  deQueue( QPtr q )
{
	return  q->data[q->start++];
}

void  enQueue( QPtr q, QE elem )
{
	if ( q->tail == q->capacity - 1  && q->start != 0)
	{
		int i = q->start, j = 0;
		while ( i <= q->tail )
			q->data[j++]  = q->data[i++];

		q->tail  = q->tail - q->start; q->start  = 0; 
	}

	if ( isEmpty(q) )
	{
		q->tail  =  q->start  = 0;
		q->data[q->tail]  = elem;
	}
	else 
		q->data[++q->tail]  = elem;
}