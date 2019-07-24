#include"BinaryTree.h"
#include"Queue.h"

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (a[*pi] == '#')
		return NULL;
	root->_data = a[*pi];
	++(*pi);
	root->_left = BinaryTreeCreate(a, pi);
	++(*pi);
	root->_right = BinaryTreeCreate(a, pi);
	return root;
}

void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
	*root = NULL;
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root) //判断叶子节点的个数
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)//二叉树的第k层节点的个数
{
	if (root == NULL)   //当树为空时;所求的层数该二叉树没节点时。（当求第K层的过程中，如果每层没节点，就返回NULL）
		return 0;
	if (k == 1)
		return 1;
	return  BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
	//求以root为根节点的第K层的节点个数，相当于求以 root->left为根节点的第k-1的个数，与以 root->right为根节点的第k-1的个数的和
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	struct BinaryTreeNode* left = BinaryTreeFind(root->_left, x);     // 不能使用BTNode类型定义
	struct BinaryTreeNode* right = BinaryTreeFind(root->_right, x);   //不能使用BTNode类型定义
	if (left != NULL)
		return left;
	if (right != NULL)
		return right;
	return NULL;
}
void BinaryTreeLevelOrder(BTNode* root)   //二叉树的层次遍历:利用队列先进先出的思想 先将根节点入队列，接着如果队列非空，则出队列，
{                                         //并将相应的左右孩子入队列。
	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode *front = QueueFront(&q);
		printf("%c ", front->_data);
		QueuePop(&q);
		if (front->_left != NULL)
		{
			QueuePush(&q, front->_left);    //不能写root->left
		}
		if (front->_right != NULL)                                    //如果这两处写rppt->left，就会输出根节点左右两个节点值的循环
		{
			QueuePush(&q, front->_right);  //不能写root->right
		}
	}
}
int BinaryTreeComplete(BTNode* root)      
{
	if (root == NULL)  //如果二叉树为空,则也为完全二叉树
		return 1;
	struct Queue q;   //由于编译器的问题，这里不能用Queue 
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))                            //  队列链表:  Queue( Queuenode* _front,Queuenode* _tail)
	{                                                  //             Queuenode(Queuenode _next,BTNode* _data)
		BTNode *front = QueueFront(&q);                // 二叉树结点：BTNode(BTNode* left,BTNode* right,chat _data)
		if (QueueFront(&q) != NULL)
		{
			QueuePop(&q);
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
		{               //删除break不行。 QueueEmpty判空，是判断data和next值都为空，是链表无节点
			break;      //QueueFront是队列结构体中的data数据，存放二叉树结构体的结点指针
		}
	}
	while (!QueueEmpty(&q))
	{
		BTNode *front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
			return 0;
	}
	return 1;
}
//该函数思想为:利用层次遍历，将二叉树结点存放在队列里，当遇到第一个二叉树结点为NULL时，跳出循环，判断剩余结点的_data值是否都为空
//如果不是，则不是完全二叉树。

void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

void TestBinaryTree1()
{
	char a[100];
	scanf("%s", a);
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, &i);
	int size = BinaryTreeSize(root);
	printf("二叉树的节点数为:%d\n", size);
	int leafsize = BinaryTreeLeafSize(root);
	printf("二叉树的叶子节点数为:%d\n", leafsize);
	int Ksize = BinaryTreeLevelKSize(root, 3);
	printf("二叉树的第3层的节点树为:%d\n", Ksize);
	BTNode* root1 = BinaryTreeFind(root, 'B');
	printf("%c \n", root1->_data);
	BinaryTreeDestory(&root);
}

void TestBinaryTree2()
{
	char a[100];
	scanf("%s", a);
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, &i);
	BinaryTreeLevelOrder(root);
	printf("\n");
	int j = BinaryTreeComplete( root);
	if (j == 1)
		printf("该二叉树是完全二叉树\n");
	else
	{
		printf("该二叉树不是完全二叉树\n");
	}
	BinaryTreeDestory(&root);
}

void TestBinaryTree3()
{
	char a[100];
	scanf("%s", a);
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, &i);
	printf("二叉树的先序遍历:");
	BinaryTreePrevOrder(root);
	printf("\n");
	printf("二叉树的中序遍历:");
	BinaryTreeInOrder(root);
	printf("\n");
	printf("二叉树的后序遍历:");
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeDestory(&root);
}
