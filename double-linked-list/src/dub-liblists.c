#include "common.h"

void d_initList(dNode **head)
{
	*head = NULL;
}

void d_prtList(dNode *head)
{
	printf("\n");

	while (head)
	{
		printf(" %d |", head->value);
		head = head->next;
	}

	printf("\n");
}

dNode *d_newNode(int value)
{
	dNode *temp = (dNode*) malloc (sizeof(dNode));

	temp->value = value;
	temp->prev = NULL;
	temp->next = NULL;

	return temp;
}

void d_addToHead(dNode **head, dNode *newNode)
{
	newNode->next = (*head);

	if (*head)
	{
		(*head)->prev = newNode;
	}

	(*head) = newNode;
}

dNode *d_findTail(dNode *head)
{
	dNode *tail;

	if (!head || !(head->next))
	{
		tail = head;
	} else
	{
		tail = d_findTail(head->next);
	}

	return tail;
}

void d_addToTail(dNode **head, dNode *newNode)
{
	if (*head == NULL)
	{
		(*head) = newNode;
	} else
	{
		dNode *tail = d_findTail(*head);
		tail->next = newNode;
		newNode->prev = tail;
	}
}

void d_addInOrder(dNode **head, dNode *newNode)
{
	if (*head == NULL)
	{
		(*head) = newNode;
	} else
	{
		if (newNode->value < (*head)->value)
		{
			d_addToHead(head, newNode);
		} else
		{
			dNode *temp = (*head);

			while (temp && newNode->value > temp->value)
			{
				temp = temp->next;
			}

			if (temp)
			{
				dNode *prev = temp->prev;
				prev->next = newNode;
				newNode->prev = prev;
				newNode->next = temp;
				temp->prev = newNode;
			} else
			{
				d_addToTail(head, newNode);
			}
		}

	}
}

int d_insertValue()
{
	int value;

	printf("\nInsert value: ");
	fflush(stdin);
	scanf("%d", &value);

	return value;
}

void d_loadList(dNode **head, void (*add)(dNode**, dNode*))
{
	dNode *temp;
	char flag;

	do {
		temp = d_newNode(d_insertValue());
		(*add)(head, temp);
		printf("\nContinue? (y/n): ");
		fflush(stdin);
		scanf(" %c", &flag);
	} while (flag != 'n');
}

void d_deleteHead(dNode **head)
{
	if (*head)
	{
		dNode *temp = (*head);

		if ((*head)->next==NULL)
		{
			d_initList(head);
			free(temp);
		} else
		{
			(*head) = (*head)->next;
			(*head)->prev = NULL;
			free(temp);
		}
	}
}

void d_deleteTail(dNode **head)
{
	if ((*head)->next) {
		dNode *tail = d_findTail(*head);
		dNode *prev = tail->prev;
		prev->next = NULL;
		free(tail);
	} else {
		d_deleteHead(head);
	}
}

dNode *d_findFromValue(dNode *head, int value)
{
	dNode *temp=NULL;

	if(head)
	{
		temp = head;

		while(temp && temp->value!=value)
		{
			temp = temp->next;
		}
	}

	return temp;
}

void d_deleteValue(dNode **head, int value)
{
	dNode *toDelete = d_findFromValue(*head, value);

	if(toDelete)
	{
		if(toDelete == (*head))
		{
			d_deleteHead(head);
		}else
		{
			if(!toDelete->next)
			{
				d_deleteTail(head);
			}else
			{
				dNode *prev = toDelete->prev;
				dNode *next = toDelete->next;
				prev->next = next;
				next->prev = prev;
				free(toDelete);
			}
		}
	}
}

void d_deleteList(dNode **head)
{
	dNode *temp;

	while(*head)
	{
		temp = (*head);
		(*head) = (*head)->next;
		free(temp);
	}
}

void d_fileToList(char *file, dNode **head, void (*add)(dNode**, dNode*))
{
	FILE *pFile = fopen(file, "rb");

	if(pFile)
	{
		int num;
		dNode *temp = (*head);

		while(fread(&num, sizeof(int), 1, pFile)>0);
		{
			temp = d_newNode(num);
			(*add)(head,temp);
			temp = temp->next;
		}

		fclose(pFile);
	}
}