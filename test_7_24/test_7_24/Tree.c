//�÷���ʹ�ö���ָ��
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	char val;
}Node;
void initialNode(Node** root, char *a, int *i)  //������ֵΪvoidʱ��Ϊ�˺����ڲ��������������ⲿҲ�ܻ�ȡ��Ӧ����Ϊ����ָ�룬
{                                             //���������ĸ��ڵ�ָ��ĵ�ַ������
	*root = (Node*)malloc(sizeof(Node));
	if (a[*i] == '#')
	{
		*root = NULL;           // �ص㣺ֱ�ӽ������'#'���ڵ������Ľṹ��洢ΪNULL
		return;                //ֻ���ز��У���Ϊ��������ĵݹ��������Ϊ���ڵ�ΪNULLʱ������һ��ע�⽫*root��ΪNULL
	}
	(*root)->val = a[*i];
	++(*i);
	initialNode(&(*root)->left, a, i);   //ע��ȡ��ַ
	++(*i);
	initialNode(&(*root)->right, a, i);
}
void inorderTraversal(Node* root)
{
	if (root == NULL)
		return;
	inorderTraversal(root->left);
	printf("%c ", root->val);
	inorderTraversal(root->right);
}
int main()
{
	char *_array = (char*)malloc(sizeof(char)* 100);
	scanf("%s", _array);
	int i = 0;
	Node* root = NULL;  
	initialNode(&root, _array, &i);
	inorderTraversal(root);
	system("pause");
	return 0;
}