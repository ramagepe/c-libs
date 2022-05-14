#include "listlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/// Inicializa la lista asignando NULL al nodo cabeza la de la misma
void initList(node **head)
{
    *head = NULL;
}

/// Recorro e imprimo los valores de la lista
void prtList(node *head)
{
    printf("\n");

    while(head)
    {
        prtNode(head->value);
        head = head->next;
    }

    printf("\n");
}

/// Subprograma de prtList
void prtNode(int value)
{
    printf(" %d |", value);
}

/// Asigna el valor pasado por parametro a un nodo creado y retorna el mismo
node *newNode(int value)
{
    node *aux = (node *) malloc (sizeof(node));

    aux->value = value;
    aux->next = NULL;

    return aux;
}

/// Se agrega un nodo ya creado al inicio de la lista
void addToHead(node **head, node *newNode)
{
    if(*head)
    {
        newNode->next = (*head);
        (*head) = newNode;
    }else
    {
        (*head) = newNode;
    }
}

/// Funcion de carga mediante ingreso del usuario
void loadList(node **head, void(*add)(node**, node*))
{
    node *temp = newNode(insertValue());
    (*add)(head, temp);
}

/// Subprograma de loadList
int insertValue()
{
    int input;

    printf("\nInsert value: ");
    fflush(stdin);
    scanf("%d", &input);

    return input;
}

/// Encuentra el ultimo nodo de la lista y lo retorna
node *findTail(node *head)
{
    node *tail = head;

    if(tail)
    {
        while(tail->next)
        {
            tail = tail->next;
        }
    }

    return tail;
}

/// Busca un nodo segun el valor pasado por parametro y lo devuelve (NULL si no lo encuentra)
node *findFromValue(node *head, int value)
{
    if(head)
    {
        while(head && head->value != value)
        {
            head = head->next;
        }
    }

    return head;
}

/// Busca un nodo segun el valor pasado por parametro y devuelve 1 o 0  
int valueExists(node *head, int value)
{
    int flag = 0;

    if(head)
    {
        while(head && head->value != value)
        {
            head = head->next;
        }

        if(head && head->value == value)
        {
            flag = 1;
        }
    }

    return flag;
}

/// Agrega un nodo creado al final de la lista
void addToTail(node **head, node *newNode)
{
    if(!(*head))
    {
        *head = newNode;
    }else
    {
        node *tail = findTail(*head);
        tail->next = newNode;
    }
}

/// Elimina un nodo si coincide con el valor pasado por parametro
void deleteFromValue(node **head, int value)
{
    if((*head) && (*head)->value == value)
    {
        node *aux = (*head);
        (*head) = (*head)->next;
        free(aux);
    }else
    {
        node *prev;
        node *temp = (*head);

        while(temp && temp->value != value)
        {
            prev = temp;
            temp = temp->next;
        }

        if(temp)
        {
            prev->next = temp->next;
            free(temp);
        }
    }
}

/// Agrega un nodo en orden ascendente a la lista
void addInOrder(node **head, node *newNode)
{
    if(*head == NULL)
    {
        *head = newNode;
    }else
    {
        if(*head && newNode->value <= (*head)->value)
        {
            newNode->next = (*head);
            (*head) = newNode;
        }else
        {
            node *temp = (*head);
            node *prev;

            while(temp && temp->value <= newNode->value)
            {
                prev = temp;
                temp = temp->next;
            }

            prev->next = newNode;
            newNode->next = temp;
        }
    }
}

/// Elimina la lista y libera el espacio en memoria
void deleteList(node **head)
{
    if(*head)
    {
        node *temp;

        while(*head)
        {
            temp = (*head);
            (*head) = (*head)->next;
            free(temp);
        }
    }
}

/// Devuelve la suma total de los valores de los nodos de la lista
int sumValues(node *head)
{
    int sum = 0;

    while(head)
    {
        sum += head->value;
        head = head->next;
    }

    return sum;
}

/// Elimina el primer nodo de la lista
void deleteHead(node **head)
{
    if(*head)
    {
        node *temp = (*head);
        (*head) = (*head)-> next;
        free(temp);
    }
}

/// Elimina el ultimo nodo de la lista
void deleteTail(node **head)
{
    if(*head)
    {
        if((*head)->next == NULL)
        {
            node *temp = (*head);
            (*head) = (*head)->next;
            free(temp);
        }else
        {
            node *temp = (*head);
            node *prev;

            while(temp->next)
            {
                prev = temp;
                temp = temp->next;
            }

            prev->next = NULL;
            free(temp);
        }
    }
}

/// Copia los elementos de un archivo a una lista, se le pasa como parametro la funcion de agregado(head,tail,inOrder)
void fileToList(char *file, node **head, void(*add)(node**,node*))
{
    FILE *pFile = fopen(file, "rb");
    int value;

    if(pFile)
    {
        deleteList(head);
        node *temp = (*head);

        while(fread(&value, sizeof(int), 1, pFile)>0)
        {
            temp = newNode(value);
            (*add)(head, temp);
            //temp = temp->next;
        }

        fclose(pFile);
    }
}

/// Pasa en orden e intercalados los elementos de dos listas a una y devuelve esta
node *fusionLists(node **head, node **lista, node *fusion)
{
    node *temp;

    while(*head && (*lista))
    {
        if((*head)->value < (*lista)->value)
        {
            temp = (*head);
            (*head) = (*head)->next;
        }else
        {
            temp = (*lista);
            (*lista) = (*lista)->next;
        }

        temp->next = NULL;
        addToTail(&fusion, temp);
    }

    while(*head)
    {
        temp = (*head);
        (*head) = (*head)->next;
        temp->next = NULL;
        addToTail(&fusion, temp);
    }

    while(*lista)
    {
        temp = (*lista);
        (*lista) = (*lista)->next;
        temp->next = NULL;
        addToTail(&fusion, temp);
    }

    deleteList(head);
    deleteList(lista);

    return fusion;
}