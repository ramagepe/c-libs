#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./src/listlib.h"

/// Inicializa la lista asignando NULL al nodo cabeza la de la misma
void initList(node **head)
{
    *head = NULL;
}

//RR// Recorro e imprimo los valores de la lista en forma recursiva
void prtList(node *head)
{
    if(head->next)
    {
        prtNode(head->value);
        prtList(head->next);
    }else
    {
        prtNode(head->value);
    }
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

///RR/// Encuentra el ultimo nodo de la lista y lo retorna de manera recursiva
node *findTail(node *head)
{
    node *tail;

    if(head->next)
    {
        tail = findTail(head->next);
    }else
    {
        tail = head;
    }

    return tail;
}

///RR/// Busca un nodo de manera recursiva segun el valor pasado por parametro y lo devuelve (NULL si no lo encuentra)
node *findFromValue(node *head, int value)
{
    node *temp = head;

    if(head && head->value != value)
    {
        temp = findFromValue(head->next, value);
    }else
    {
        temp = head;
    }

    return temp;
}

///RR/// Busca un nodo de manera recursiva segun el valor pasado por parametro y devuelve 1 o 0 
int valueExists(node *head, int value)
{
    int flag = 0;

    if(head)
    {
        if(head && head->value == value)
        {
            flag = 1;
        }else
        {
            flag = valueExists(head->next, value);
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

///RR/// Elimina un nodo si coincide con el valor pasado por parametro
void deleteFromValue(node **head, int value)
{
    node *temp = (*head);

    if(temp)
    {
        if(temp->value != value)
        {
            deleteFromValue(&(*head)->next, value);
        }else
        {
            deleteNode(head, temp);
        }
    }
}

///RR/// Agrega un nodo en orden ascendente a la lista
void addInOrder(node **head, node *newNode)
{
    if(!*head)
    {
        *head = newNode;
    }else
    {
        node *temp = (*head);

        if(newNode->value <= temp->value)
        {
            addToHead(head, newNode);
        }else
        {
            if(temp->value <= newNode->value)
            {
                addInOrder(&temp->next, newNode);
                
            }else
            {
                if(!temp->next)
                {
                    addToTail(head, newNode);
                }else
                {
                    newNode->next = temp->next;
                    temp->next = newNode;
                }
            }
        }
    }
}

///RR/// Elimina la lista y libera el espacio en memoria  (!!!)
void deleteList(node **head)
{
    if(*head)
    {
        node *temp = (*head);
        free(*head);
        deleteList(&temp->next);
    }
}

///RR/// Devuelve la suma total de los valores de los nodos de la lista
int sumValues(node *head)
{
    int sum = 0;

    if(head)
    {
        sum = head->value + sumValues(head->next);
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

void deleteNode(node **head, node *toDel)
{
    if(head)
    {
        if(*head==toDel)
        {
            deleteHead(head);
        }else
        {
            node *temp = (*head);
            node* prev;

            while(temp && temp!=toDel)
            {
                prev = temp;
                temp = temp->next;
            }

            if(temp)
            {
                if(!temp->next)
                {
                    prev->next = NULL;
                    free(temp);
                }else
                {
                    prev->next = temp->next;
                    free(temp);
                }
            }
        }
    }
}

///RR/// Muestra los nodos que se encuetran en una posicion par (suponiendo que se empieza de 1)

void showPairPos(node *head)
{   
    if(head)
    {
        head = head->next;
        if(head)
        {
            printf(" %d |", head->value);
            showPairPos(head->next);
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
            temp = temp->next;
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