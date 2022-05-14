#include "fila.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void menu();

int main()
{
	fila q;
	int input;

	q_init(&q);

	do{
		system("clear");
		if(q.head)
		{
            q_prt(q);
            printf("\nHEAD = %p ==> %d\n", q.head, q_head(q));
            printf("\nTAIL = %p ==> %d\n", q.tail, q_tail(q));
		}

        printf("\nFILA VACIA => %d\n", q_empty(q));

        menu();
		fflush(stdin);
		scanf("%d", &input);

		switch(input)
		{
			case 1:
                q_read(&q);
                break;
            case 2:
                q_extract(&q);
                break;
		}

	}while(input!=0);

	return 0;
}

void menu()
{
    printf("\n1) Agregar");
    printf("\n2) Extraer");
    printf(" \n\n0) Salir");
    printf("\n\nInsert option: ");
}