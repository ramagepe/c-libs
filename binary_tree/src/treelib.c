#include "treelib.h"

void initTree(treeNode **head)
{
	(*head) = NULL;
}

treeNode *newTreeNode(int val)
{
	treeNode *temp = (treeNode*)malloc(sizeof(treeNode));

	temp->val = val;
	temp->right = NULL;
	temp->left = NULL;

	return temp;
}

treeNode *findTreeNode(treeNode *root, int val)
{
	treeNode *temp = NULL;

    if(root)
	{
		if(root->val == val)
			temp = root;
		else
            if(root->val < val)
                temp = findTreeNode(root->right, val);

            if(root->val > val)
                temp = findTreeNode(root->left, val);
	}

    return temp;
}

int insertValue()
{
    int val;

    printf("\nInsert value: ");
    fflush(stdin);
    scanf("%d", &val);

    return val;
}

void insertTreeNode(treeNode **root, treeNode *newNode)
{
    if(!(*root))
    {
        (*root) = newNode;
    }else
    {
        if((*root)->val < newNode->val)
            insertTreeNode(&(*root)->right, newNode);

        if((*root)->val > newNode->val)
            insertTreeNode(&(*root)->left, newNode);
    }
}

void loadTree(treeNode **root)
{
    treeNode *temp;
    temp = newTreeNode(insertValue());
    insertTreeNode(root, temp);
}

int countLeafs(treeNode *root)
{
    int count=0;

    if(root)
    {
        if(!root->left && !root->right)
        {
            count++;
        }
        
        count += countLeafs(root->right);
        count += countLeafs(root->left);
    }

    return count;
}

int countNodes(treeNode *root)
{
    int count=0;

    if(root)
    {
        count++;
        count += countNodes(root->right);
        count += countNodes(root->left);
    }

    return count;
}

treeNode *rightestNode(treeNode *root)
{
    treeNode *temp = root;

    if(root->right)
    {
        temp = rightestNode(root->right);
    }

    return temp;
}

treeNode *leftestNode(treeNode *root)
{
    treeNode *temp = root;

    if(root->left)
    {
        temp = leftestNode(root->left);
    }

    return temp;
}

void deleteTreeNode(treeNode **root, int val)
{
    if(*root)
    {
        if((*root)->val == val)
        {
            if((*root)->left)
            {
                treeNode *temp = rightestNode((*root)->left);
                (*root)->val = temp->val;
                deleteTreeNode(&(*root)->left, temp->val);
            }else if((*root)->right)
            {
                treeNode *temp = leftestNode((*root)->right);
                (*root)->val = temp->val;
                deleteTreeNode(&(*root)->right, temp->val);
            }else
            {
                free(*root);
                (*root) = NULL;
            }
        }else
        {
            if((*root)->val < val)
            {
                deleteTreeNode(&(*root)->right, val);
            }else if((*root)->val > val)
            {
                deleteTreeNode(&(*root)->left, val);
            }
        }
    }
}

void deleteTree(treeNode **root)
{
    if(*root)
    {
        deleteTree(&(*root)->left);
        deleteTree(&(*root)->right);
        deleteTreeNode(root, (*root)->val);
    }
}

int max(int a, int b)
{
    return (a>=b)? a : b;
}

int diff(int a, int b)
{
    return (a-b<0)?(a-b)*(-1):a-b;
}

int treeHeight(treeNode *root)
{
    int height = 0;

    if(root)
    {
        height = 1 + max(treeHeight(root->right), treeHeight(root->left));
    }

    return height;
}

int treeIsBalanced(treeNode *root)
{
    int flag=1;

    if(root)
    {
        if(diff(treeHeight(root->right), treeHeight(root->left))>1)
        {
            flag=0;
        }
    }

    return flag;
}

int treeToArray(treeNode *root, int *values, int i)
{
    if(root)
    {
        i=treeToArray(root->left, values,i);
        values[i]=root->val;
        i++;
        i=treeToArray(root->right, values,i);
    }

    return i;
}

int *genArray(int len)
{
    return (int*)malloc(sizeof(int)*len);
}

void arrayToTree(treeNode **root, int *values, int start, int end)
{
    if(start <= end)
    {
        int mid = (start + end)/2;
        insertTreeNode(root, newTreeNode(values[mid]));
        arrayToTree(&(*root)->left, values, start, mid-1);
        arrayToTree(&(*root)->right, values, mid+1, end);
    }
}

void balanceTree(treeNode **root)
{
    if(*root && !treeIsBalanced(*root))
    {
        int *values = genArray(countNodes(*root));
        int qNodes = treeToArray(*root, values, 0);
        deleteTree(root);
        arrayToTree(root, values, 0, qNodes-1);
    }
}

// ====> PRINTING FUNCTIONS <==== //

void prtPreOrder(treeNode *root)
{
    if(root)
    {
        printf(" %d |", root->val);
        prtPreOrder(root->left);
        prtPreOrder(root->right);
    }
}

void prtInOrder(treeNode *root)
{
    if(root)
    {
        prtInOrder(root->left);
        printf(" %d |", root->val);
        prtInOrder(root->right);
    }
}

void prtPostOrder(treeNode *root)
{
    if(root)
    {
        prtPostOrder(root->left);
        prtPostOrder(root->right);
        printf(" %d |", root->val);
    }
}

void prtUtil(treeNode *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += 10;
 
    // Process right child first
    prtUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->val);
 
    // Process left child
    prtUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void prtTree(treeNode *root)
{
   // Pass initial space count as 0
   prtUtil(root, 0);
}

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

