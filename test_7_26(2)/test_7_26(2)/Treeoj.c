//�ж�һ�����Ƿ�Ϊƽ�������
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

//int TreeHeight(struct TreeNode* root)   //�����ĸ߶�
//{
//	if (root == NULL)
//		return 0;
//	int LeftHeight = TreeHeight(root->left);
//	int rightHeight = TreeHeight(root->right);
//	return (LeftHeight>rightHeight) ? LeftHeight + 1 : rightHeight + 1;
//}
//bool isBalanced(struct TreeNode* root){   //���ո�������������������˳����������ĸ߶�
//	if (root == NULL)
//		return true;
//	int left = TreeHeight(root->left);      //��������ڵ�
//	int right = TreeHeight(root->right);
//	return abs(left - right)<2 && isBalanced(root->left) && isBalanced(root->right); //���ҵĹ�ϵ����Ҫͬʱ����
//}
//�Ըýڵ�Ϊ���ڵ㣬�������Ƿ�ƽ�⣻���Ÿýڵ���������Ƿ�ƽ�⣬���ýڵ���������Ƿ�ƽ��

