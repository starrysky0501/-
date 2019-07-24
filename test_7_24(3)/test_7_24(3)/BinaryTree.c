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

int BinaryTreeLeafSize(BTNode* root) //�ж�Ҷ�ӽڵ�ĸ���
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)//�������ĵ�k��ڵ�ĸ���
{
	if (root == NULL)   //����Ϊ��ʱ;����Ĳ����ö�����û�ڵ�ʱ���������K��Ĺ����У����ÿ��û�ڵ㣬�ͷ���NULL��
		return 0;
	if (k == 1)
		return 1;
	return  BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
	//����rootΪ���ڵ�ĵ�K��Ľڵ�������൱������ root->leftΪ���ڵ�ĵ�k-1�ĸ��������� root->rightΪ���ڵ�ĵ�k-1�ĸ����ĺ�
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	struct BinaryTreeNode* left = BinaryTreeFind(root->_left, x);     // ����ʹ��BTNode���Ͷ���
	struct BinaryTreeNode* right = BinaryTreeFind(root->_right, x);   //����ʹ��BTNode���Ͷ���
	if (left != NULL)
		return left;
	if (right != NULL)
		return right;
	return NULL;
}
void BinaryTreeLevelOrder(BTNode* root)   //�������Ĳ�α���:���ö����Ƚ��ȳ���˼�� �Ƚ����ڵ�����У�����������зǿգ�������У�
{                                         //������Ӧ�����Һ�������С�
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
			QueuePush(&q, front->_left);    //����дroot->left
		}
		if (front->_right != NULL)                                    //���������дrppt->left���ͻ�������ڵ����������ڵ�ֵ��ѭ��
		{
			QueuePush(&q, front->_right);  //����дroot->right
		}
	}
}
int BinaryTreeComplete(BTNode* root)      
{
	if (root == NULL)  //���������Ϊ��,��ҲΪ��ȫ������
		return 1;
	struct Queue q;   //���ڱ����������⣬���ﲻ����Queue 
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))                            //  ��������:  Queue( Queuenode* _front,Queuenode* _tail)
	{                                                  //             Queuenode(Queuenode _next,BTNode* _data)
		BTNode *front = QueueFront(&q);                // ��������㣺BTNode(BTNode* left,BTNode* right,chat _data)
		if (QueueFront(&q) != NULL)
		{
			QueuePop(&q);
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
		{               //ɾ��break���С� QueueEmpty�пգ����ж�data��nextֵ��Ϊ�գ��������޽ڵ�
			break;      //QueueFront�Ƕ��нṹ���е�data���ݣ���Ŷ������ṹ��Ľ��ָ��
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
//�ú���˼��Ϊ:���ò�α�������������������ڶ������������һ�����������ΪNULLʱ������ѭ�����ж�ʣ�����_dataֵ�Ƿ�Ϊ��
//������ǣ�������ȫ��������

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
	printf("�������Ľڵ���Ϊ:%d\n", size);
	int leafsize = BinaryTreeLeafSize(root);
	printf("��������Ҷ�ӽڵ���Ϊ:%d\n", leafsize);
	int Ksize = BinaryTreeLevelKSize(root, 3);
	printf("�������ĵ�3��Ľڵ���Ϊ:%d\n", Ksize);
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
		printf("�ö���������ȫ������\n");
	else
	{
		printf("�ö�����������ȫ������\n");
	}
	BinaryTreeDestory(&root);
}

void TestBinaryTree3()
{
	char a[100];
	scanf("%s", a);
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, &i);
	printf("���������������:");
	BinaryTreePrevOrder(root);
	printf("\n");
	printf("���������������:");
	BinaryTreeInOrder(root);
	printf("\n");
	printf("�������ĺ������:");
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeDestory(&root);
}
