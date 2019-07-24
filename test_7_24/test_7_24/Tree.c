//该方法使用二级指针
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	char val;
}Node;
void initialNode(Node** root, char *a, int *i)  //当返回值为void时，为了函数内部建立二叉树，外部也能获取，应定义为二级指针，
{                                             //将二叉树的根节点指针的地址传过来
	*root = (Node*)malloc(sizeof(Node));
	if (a[*i] == '#')
	{
		*root = NULL;           // 重点：直接将这个以'#'存在的子树的结构体存储为NULL
		return;                //只返回不行，因为中序遍历的递归结束条件为当节点为NULL时，所以一定注意将*root置为NULL
	}
	(*root)->val = a[*i];
	++(*i);
	initialNode(&(*root)->left, a, i);   //注意取地址
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