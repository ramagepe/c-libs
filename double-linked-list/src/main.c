#include "common.h"

void menu();
void prtState(dNode *head, dNode *tail);

int main()
{
	dNode *head, *tail, *temp;
	int input;

	d_initList(&head);
	d_initList(&tail);

	do{
		system("clear");
		prtState(head,tail);
		menu();
		fflush(stdin);
		scanf("%d", &input);

		switch(input)
		{
			case 1:
				d_loadList(&head, d_addToHead);
				break;
			case 2:
				d_loadList(&head, d_addToTail);
				break;
			case 3:
				d_loadList(&head, d_addInOrder);
				break;
			case 4:
				d_deleteHead(&head);
				break;
			case 5:
				d_deleteTail(&head);
				break;
			case 6:
				d_deleteValue(&head, d_insertValue());
				break;
			case 7:
				temp = d_findFromValue(head, d_insertValue());
				if(temp)
				{
					printf("\nValue found! ==> %d\n", temp->value);
					sleep(2);
				}else
				{
					printf("\nValue not in list...\n");
					sleep(2);
				}
			case 8:
				d_deleteList(&head);
				break;
			default:
				break;
		}

	}while(input!=0);

	return 0;
}

void menu()
{
	printf("\n\n1) Agregar al principio");
	printf("\n2) Agregar al final");
	printf("\n3) Agregar en orden");
	printf("\n4) Eliminar primero");
	printf("\n5) Eliminar ultimo");
	printf("\n6) Eliminar por valor");
	printf("\n7) Encontrar valor");
	printf("\n8) Eliminar lista");
	printf("\n\n0) Salir");
	printf("\n\nIngrese una opcion: ");
}

void prtState(dNode *head, dNode *tail)
{
	d_prtList(head);
	
	tail = d_findTail(head);
	
	if(head)
	{
		printf("\nHEAD = %d |==> %p", head->value, head);
	}

	if(tail)
	{
		printf("\nTAIL = %d |==> %p", tail->value, tail);
	}
}