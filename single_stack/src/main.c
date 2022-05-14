#include "common.h"

void prtTail(node *tail);
void prtValue(node *val);
void menu();

int main()
{
	node *pile;
	int opt, temp=0;

	inicPila(&pile);

	do{
		system("clear");
		if(pile)
		{
            mostrar(pile);
            printf("\nTOPE = %p ==> %d\n", pile, tope(pile));
            printf("\nDESAPILADO => %d\n", temp);
		}

        printf("\nPILA VACIA => %d\n", pilaVacia(pile));

        menu();
		fflush(stdin);
		scanf("%d", &opt);

		switch(opt)
		{
			case 1:
                leer(&pile);
                break;
            case 2:
                temp = desapilar(&pile);
                break;
            case 3:
                cargarPila(&pile);
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
        printf("\nNode found! ==> %d", val->value);
    }else {
        printf("\nNode not found...");
    }
}

void menu()
{
    printf("\n1) Cargar un valor");
    printf("\n2) Desapilar tope");
    printf("\n3) Cargar varios valores");

    printf(" \n\n0) Salir");
    printf("\n\nInsert option: ");
}
