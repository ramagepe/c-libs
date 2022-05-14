#include "dub-liblists.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct
{
	dNode *head;
	dNode *tail;
} fila;

void q_init(fila *q);
void q_add(fila *q, int val);
void q_extract(fila *q);
void q_prt(fila q);
void q_read(fila *q);
int q_head(fila q);
int q_tail(fila q);
int q_empty(fila q);