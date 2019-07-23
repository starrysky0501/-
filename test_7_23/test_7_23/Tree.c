#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	char val;
}Node;
Node* initialNode(char *a, int *i)
{
	Node* root = (Node*)malloc(sizeof(Node));
	if (a[*i] == '#')
		return NULL;
	root->val = a[*i];
	++(*i);
	root->left = initialNode(a, i);
	++(*i);
	root->right = initialNode(a, i);
	return root;
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
	Node *root=initialNode(_array, &i);
	inorderTraversal(root);
	system("pause");
	return 0;
}