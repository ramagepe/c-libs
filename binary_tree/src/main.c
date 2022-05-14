#include "main.h"

int main()
{
	treeNode *root, *temp;
	int input;

	initTree(&root);
	initTree(&temp);

	do
	{
		system("clear");
		prtStatus(root);
		menu();
		fflush(stdin);
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			loadTree(&root);
			break;
		case 2:
			temp = findTreeNode(root, insertValue());
			if (temp)
			{
				printf("\nNode found! ==> %d\n", temp->val);
				sleep(2);
			}
			else
			{
				printf("\nNode not found...\n");
				sleep(2);
			}
			break;
		case 3:
			deleteTreeNode(&root, insertValue());
			break;
		case 4:
			balanceTree(&root);
			break;
		default:
			break;
		}

	} while (input != 0);

	return 0;
}

void menu()
{
	printf("\n\n1) Add values");
	printf("\n2) Find value");
	printf("\n3) Delete node");
	printf("\n4) Balance tree");
	printf("\n\n 0) Salir");
	printf("\n\nIngrese una opcion: ");
}

void prtStatus(treeNode *root)
{
	if (root)
	{
		prtTree(root);
		printf("\n=== PRE-ORDER ===\n");
		prtPreOrder(root);
		printf("\n=== IN-ORDER ===\n");
		prtInOrder(root);
		printf("\n=== POST-ORDER ===\n");
		prtPostOrder(root);
		printf("\n");
		printf("\nLEAFS =====> %d", countLeafs(root));
		printf("\nNODES =====> %d", countNodes(root));
		printf("\nL HEIGTH ==> %d", treeHeight(root->left));
		printf("\nR HEIGTH ==> %d", treeHeight(root->right));
		printf("\nBALANCED ==> %d", treeIsBalanced(root));
	}
}