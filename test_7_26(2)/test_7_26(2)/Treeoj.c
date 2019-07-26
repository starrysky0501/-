//判断一棵树是否为平衡二叉树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

//int TreeHeight(struct TreeNode* root)   //求树的高度
//{
//	if (root == NULL)
//		return 0;
//	int LeftHeight = TreeHeight(root->left);
//	int rightHeight = TreeHeight(root->right);
//	return (LeftHeight>rightHeight) ? LeftHeight + 1 : rightHeight + 1;
//}
//bool isBalanced(struct TreeNode* root){   //按照根，左子树，右子树的顺序进行求树的高度
//	if (root == NULL)
//		return true;
//	int left = TreeHeight(root->left);      //先求出根节点
//	int right = TreeHeight(root->right);
//	return abs(left - right)<2 && isBalanced(root->left) && isBalanced(root->right); //是且的关系，需要同时满足
//}
//以该节点为根节点，求左右是否平衡；接着该节点的左子树是否平衡，最后该节点的右子树是否平衡

