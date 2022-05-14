typedef struct _node
{
	int value;
	struct _node *next;
} node;

void initList(node **head);
void prtList(node *head);
void prtNode(int value);
node *newNode(int value);
int insertValue();
void addToHead(node **head, node *newNode);
node *findTail(node *head);
void addToTail(node **head, node *newNode);
void loadList(node **head, void(*add)(node**, node*));
node *findFromValue(node *head, int value);
int valueExists(node *head, int value);
void deleteFromValue(node **head, int value);
void deleteHead(node **head);
void deleteTail(node **head);
void deleteNode(node **head, node *toDel);
void addInOrder(node **head, node *newNode);
int sumValues(node *head);
void showPairPos(node *head);
void deleteList(node **head);
void fileToList(char *file, node **head, void(*add)(node**,node*));
node *fusionLists(node **head, node **lista, node *fusion);
