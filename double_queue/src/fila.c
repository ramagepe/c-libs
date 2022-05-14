#include "fila.h"

void q_init(fila *q)
{
	d_initList(&q->head);
	d_initList(&q->tail);
}

void q_add(fila *q, int val)
{
	dNode *temp = d_newNode(val);

	d_addToTail(&q->head, temp);
	q->tail = temp;
}

void q_extract(fila *q)
{
	d_deleteHead(&q->head);
}

void q_prt(fila q)
{
	d_prtList(q.head);
}

void q_read(fila *q)
{
	q_add(q, d_insertValue());
}

int q_head(fila q)
{
	return q.head->value;
}

int q_tail(fila q)
{
	return q.tail->value;
}

int q_empty(fila q)
{
	int flag=1;

	if(q.head && q.tail)
	{
		flag = 0;
	}

	return flag;
}