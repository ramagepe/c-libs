#include "common.h"

void inicPila(pila *head)
{
	initList(head);
}

void apilar(pila *head, int value)
{
	node *temp;
	temp = newNode(value);
	addToHead(head, temp);
}

int desapilar(pila *head)
{
	return deleteHead(head);
}

void mostrar(pila head)
{
	prtList(head);
}

int tope(pila head)
{
	return head->value;
}

int pilaVacia(pila head)
{
	int flag=0;

	if(!head)
	{
		flag = 1;
	}

	return flag;
}

void leer(pila *head)
{
	apilar(head, insertValue());
}

int cargarPila(pila *head)
{
	char flag, i=0;

	do{
		leer(head);
		i++;
		printf("\nContinue? (y/n): ");
		fflush(stdin);
		scanf(" %c", &flag);
	}while(flag!='n');

	return i;
}