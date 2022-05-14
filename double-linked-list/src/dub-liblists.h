typedef struct _dNode {
	int value;
	struct _dNode *prev;
	struct _dNode *next;
} dNode;

void d_initList(dNode **head);
void d_prtList(dNode *head);
dNode *d_newNode(int value);
void d_addToHead(dNode **head, dNode *newNode);
dNode *d_findTail(dNode *head);
void d_addToTail(dNode **head, dNode *newNode);
void d_addInOrder(dNode **head, dNode *newNode);
void d_loadList(dNode **head, void (*add)(dNode**, dNode*));
int d_insertValue();
void d_deleteHead(dNode **head);
void d_deleteTail(dNode **head);
void d_deleteValue(dNode **head, int value);
dNode *d_findFromValue(dNode *head, int value);
void d_deleteList(dNode **head);