//��������ǰ�����(�������)
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
//int TreeSize(struct TreeNode* root)  //���ú��������˼�룬������������������������֮�󵽸�������������ڼ�һ
//{
//	if (root == NULL)    //�ݹ����������
//		return 0;
//	return TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//void _preorderTraversal(struct TreeNode* root, int* a, int* i)
//{
//	if (root == NULL)     //������������洢ֵ
//		return;
//	a[*i] = root->val;
//	++(*i);     //ֵ��һ
//	_preorderTraversal(root->left, a, i);
//	_preorderTraversal(root->right, a, i);
//}
//int* preorderTraversal(struct TreeNode* root, int* returnSize){
//	//����Ҫ��̬����һ�����飬ϵͳ������ͷš�
//	*returnSize = TreeSize(root);    //�������ǲ�֪�������Ľڵ��������Ӧ��һ������������ڵ����
//	int *_array = (int*)malloc(*returnSize*sizeof(int));
//	int i = 0;
//	_preorderTraversal(root, _array, &i);
//	return _array;
//}
//Ϊʲô��Ҫ���� _preorderTraversal�������?
//��Ϊ�����ԭ�Ⱥ���preorderTraversal���棬��ÿ�ε������¿����µĿռ����飬���������ã������ܽ�ֵ���������������


//���������������
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


//�������ĺ������
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


//��ͬ����
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
//	if (p == NULL || q == NULL)  //˵����ʱ��һ��Ϊ�գ���һ�������ǿգ��ṹ��ͬ����������Ϊ��ʱ�����ڵ�һ�������ͷ�����
//		return false;
//	if (p->val != q->val)     //�ǿ��ҽṹ��ͬ���ж��������ýڵ��ֵ
//		return false;
//	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//��һ��if����:��1����������Ϊ��ʱ����ṹ��ͬ����ֵ��ֱ�ӷ���true
//            ��2���ж����һ��return��һ���ݹ�ĳ��� 
//��һ�͵ڶ���if�������ʹ�ÿ����ж��������Ľṹ�Ƿ���ͬ
//���һ��return�ķ��������ǡ��ҡ�,��������������ʱ���Ͳ����ж���������


//��������������
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
//ע�⣬�����������������������ĸ߶ȴ洢����,�����return����������������ᵼ���ظ��ݹ顣 


//��һ����������
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
//	/*if(t==NULL)   //   ������Ϊ��ʱ;����Ϊ��һ��if�������̵�
//	return true;
//	if(s==NULL)   //��ֹ��ָ���ڵĳ�Ա����;t��Ϊ��,sΪ��
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


//�Գƶ�����
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
////���ǵĸ��ڵ���ͬ
////���������������Գ�




