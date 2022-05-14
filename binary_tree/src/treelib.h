#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct t_node
{
	int val;
	struct t_node *left;
	struct t_node *right;
}treeNode;

void initTree(treeNode **head);
treeNode *newTreeNode(int val);
treeNode *findTreeNode(treeNode *root, int val);
int insertValue();
void insertTreeNode(treeNode **root, treeNode *newNode);
void loadTree(treeNode **root);
int countLeafs(treeNode *root);
int countNodes(treeNode *root);
treeNode *rightestNode(treeNode *root);
treeNode *leftestNode(treeNode *root);
void deleteTreeNode(treeNode **root, int val); //==> TODO...
void deleteTree(treeNode **root); //==> TODO...
int treeHeight(treeNode *root);
int treeIsBalanced(treeNode *root);
void balanceTree(treeNode **root);


// PRINTING FUNCTIONS
void prtPreOrder(treeNode *root);
void prtInOrder(treeNode *root);
void prtPostOrder(treeNode *root);
void gotoxy(int x, int y);
void prtTree(treeNode *root);