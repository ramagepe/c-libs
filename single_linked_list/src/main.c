#include "listlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void prtTail(node *tail);
void prtValue(node *val);
void menu();

int main()
{
	node *head, *temp;
	int opt;

	initList(&head);

	do{
		system("clear");
		if(head)
		{
            prtList(head);
            printf("\nHEAD = %p ==> %d\n", head, head->value);
            printf("\nTAIL = %p ==> %d\n", findTail(head), findTail(head)->value);
		}

        menu();
		fflush(stdin);
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
				loadList(&head, addToHead);
				break;
            case 2:
                loadList(&head, addToTail);
                break;
            case 3:
                loadList(&head, addInOrder);
                break;
            case 4:
                temp = findFromValue(head, insertValue());
                prtValue(temp);
                sleep(2);
                break;
            case 5:
                deleteFromValue(&head, insertValue());
                break;
            case 6:
                printf("\nSUMA = %d", sumValues(head));
                break;
            case 7:
                deleteHead(&head);
                break;
            case 8:
                deleteTail(&head);
                break;
            case 9:
                deleteList(&head);
                break;
			default:
				break;
		}

	}while(opt!=0);

	return 0;
}

void prtTail(node *tail)
{
    if(tail)
    {
        printf("\nTAIL = %d | %p\n", tail->value, tail);
    }else{
        printf("\nTail not found...\n");
    }

    sleep(2);
}

void prtValue(node *val)
{
    if(val)
    {
        printf("\nNode found! ==> %d\n", val->value);
    }else {
        printf("\nNode not found...\n");
    }
}

void menu()
{
    printf("\n1) Agregar al principio");
    printf("\n2) Agregar al final");
    printf("\n3) Agregar en orden");
    printf("\n4) Encontrar por valor");
    printf("\n5) Borrar por valor");
    printf("\n6) Sumar valores");
    printf("\n7) Borrar primero");
    printf("\n8) Borrar ultimo");
    printf("\n9) Borrar lista");
    printf(" \n\n0) Salir");
    printf("\n\nInsert option: ");
}
