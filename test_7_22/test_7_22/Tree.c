//二叉树的前序遍历(先序遍历)
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
//int TreeSize(struct TreeNode* root)  //利用后序遍历的思想，先算左子树，再算右子树，之后到根处将他们相加在加一
//{
//	if (root == NULL)    //递归结束的条件
//		return 0;
//	return TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//void _preorderTraversal(struct TreeNode* root, int* a, int* i)
//{
//	if (root == NULL)     //利用先序遍历存储值
//		return;
//	a[*i] = root->val;
//	++(*i);     //值加一
//	_preorderTraversal(root->left, a, i);
//	_preorderTraversal(root->right, a, i);
//}
//int* preorderTraversal(struct TreeNode* root, int* returnSize){
//	//该题要求动态开辟一个数组，系统会帮你释放。
//	*returnSize = TreeSize(root);    //由于我们不知二叉树的节点个数，则应建一个函数，求其节点个数
//	int *_array = (int*)malloc(*returnSize*sizeof(int));
//	int i = 0;
//	_preorderTraversal(root, _array, &i);
//	return _array;
//}
//为什么需要创建 _preorderTraversal这个函数?
//因为如果在原先函数preorderTraversal里面，它每次调用重新开辟新的空间数组，做不到复用，不可能将值都存放在数组里面


//二叉树的中序遍历
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
//int TreeSize(struct TreeNode* root)
//{
//	if (root == NULL)
//		return 0;
//	return TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//void _inorderTraversal(struct TreeNode* root, int* a, int *i)
//{
//	if (root == NULL)
//		return;
//	_inorderTraversal(root->left, a, i);
//	a[*i] = root->val;
//	++(*i);
//	_inorderTraversal(root->right, a, i);
//}
//int* inorderTraversal(struct TreeNode* root, int* returnSize){
//	*returnSize = TreeSize(root);
//	int *_array = (int*)malloc(*returnSize*sizeof(int));
//	int i = 0;
//	_inorderTraversal(root, _array, &i);
//	return _array;
//}


//二叉树的后序遍历
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
//int TreeSize(struct TreeNode* root)
//{
//	if (root == NULL)
//		return 0;
//	return TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//void _inorderTraversal(struct TreeNode* root, int* a, int *i)
//{
//	if (root == NULL)
//		return;
//	_inorderTraversal(root->left, a, i);
//	_inorderTraversal(root->right, a, i);
//	a[*i] = root->val;
//	++(*i);
//}
//int* postorderTraversal(struct TreeNode* root, int* returnSize){
//	*returnSize = TreeSize(root);
//	int *_array = (int*)malloc(*returnSize*sizeof(int));
//	int i = 0;
//	_inorderTraversal(root, _array, &i);
//	return _array;
//}


//相同的树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
//bool isSameTree(struct TreeNode* p, struct TreeNode* q){
//	if (p == NULL && q == NULL)
//		return true;
//	if (p == NULL || q == NULL)  //说明此时有一个为空，另一个子树非空，结构不同；当两个都为空时，则在第一个条件就返回了
//		return false;
//	if (p->val != q->val)     //非空且结构相同，判断两个数该节点的值
//		return false;
//	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//第一个if条件:（1）当两个树为空时，则结构相同，无值，直接返回true
//            （2）判断最后一个return的一个递归的出口 
//第一和第二个if条件结合使用可以判断两个数的结构是否相同
//最后一个return的返回条件是“且”,当左子树不满足时，就不用判断右子树了


//二叉树的最大深度
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
//int maxDepth(struct TreeNode* root){
//	if (root == NULL)
//		return 0;
//	int LeftDepth = maxDepth(root->left);
//	int RightDepth = maxDepth(root->right);
//	return (LeftDepth > RightDepth) ? LeftDepth + 1 : RightDepth + 1;
//}
//注意，创建两个变量将左右子树的高度存储起来,如果在return中利用条件运算符会导致重复递归。 


//另一个树的子树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//	if (p == NULL && q == NULL)
//		return true;
//	if (p == NULL || q == NULL)
//		return false;
//	if (p->val != q->val)
//		return false;
//	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//
//bool isSubtree(struct TreeNode* s, struct TreeNode* t){
//	/*if(t==NULL)   //   当子树为空时;并且为下一个if条件做铺垫
//	return true;
//	if(s==NULL)   //防止空指针内的成员访问;t不为空,s为空
//	return false;
//	bool flag=false;
//	flag=isSameTree(s,t);
//	if(!flag)
//	flag=isSubtree(s->left, t) ;
//	if(!flag)
//	flag=isSubtree(s->right,t);
//	return flag;*/
//	return isSameTree(s, t) || s != NULL && (isSubtree(s->left, t) || isSubtree(s->right, t));
//}


//对称二叉树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
//bool isMirror(struct TreeNode* root1, struct TreeNode* root2)
//{
//	if (root1 == NULL && root2 == NULL)
//		return true;
//	if (root1 == NULL || root2 == NULL)
//		return false;
//	return (root1->val == root2->val) && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
//}
//bool isSymmetric(struct TreeNode* root){
//	return isMirror(root, root);
//}
////它们的根节点相同
////左子树与右子树对称




