//删除链表中等于给定值 val 的所有节点
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//struct ListNode* removeElements(struct ListNode* head, int val){
//	if (head == NULL)  //没有元素
//		return NULL;
//	struct ListNode* cur = head;
//	struct ListNode* prev = NULL;
//	while (cur)
//	{
//		struct ListNode* next = cur->next;
//		if (cur->val == val)
//		{
//			if (prev == NULL)       //当删除的结点为头时
//			{
//				head = cur->next;
//			}
//			else
//			{
//				prev->next = cur->next;
//			}
//			free(cur);
//			cur = next;
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//	return head;
//
//}
//

//反转一个单链表。
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//struct ListNode* reverseList(struct ListNode* head){
//	/* if(head==NULL||head->next==NULL)    三个指针翻转
//	{
//	return head;
//	}
//	struct ListNode* n1=head;
//	struct ListNode* n2=n1->next;
//	struct ListNode* n3=n2->next;
//	n1->next=NULL;
//	while(n2)
//	{
//	n2->next=n1;
//	n1=n2;
//	n2=n3;
//	if(n3)
//	n3=n3->next;
//	}
//	return n1; */
//	struct ListNode* newhead = NULL;   //取节点头插的思想进行逆置
//	struct ListNode* cur = head;
//	while (cur)
//	{
//		struct ListNode* next = cur->next;
//		cur->next = newhead;
//		newhead = cur;
//		cur = next;
//	}
//	return newhead;
//}

//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//带有头结点的非空单链表
//快慢指针
//struct ListNode* middleNode(struct ListNode* head){
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//	while (fast&&fast->next)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	return slow;
//}

//输入一个链表，输出该链表中倒数第k个结点。
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
//class Solution {
//public:
//	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//		ListNode* slow = pListHead;
//		ListNode* fast = slow;
//		while (k--)
//		{
//			if (fast)
//				fast = fast->next;
//			else
//				return NULL;
//		}
//		while (fast)
//		{
//			slow = slow->next;
//			fast = fast->next;
//		}
//		return slow;
//	}
//};

// 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//创建一个头节点，直接插入，不用讨论是否存在头节点。
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
//	if (l1 == NULL)
//		return l2;
//	if (l2 == NULL)
//		return l1;
//	struct ListNode* head = NULL;
//	struct ListNode* tail = NULL;
//	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
//	while (l1 != NULL && l2 != NULL)
//	{
//		if (l1->val<l2->val)
//		{
//			tail->next = l1;
//			l1 = l1->next;
//		}
//		else
//		{
//			tail->next = l2;
//			l2 = l2->next;
//		}
//		tail = tail->next;
//	}
//	if (l1 != NULL)
//	{
//		tail->next = l1;
//	}
//	if (l2 != NULL)
//	{
//		tail->next = l2;
//	}
//	struct ListNode* list = head->next;
//	free(head);
//	return list;
//}

// 编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
//class Partition {
//public:
//	ListNode* partition(ListNode* pHead, int x) {
//		ListNode* lesshead = NULL;
//		ListNode* lesstail = NULL;
//		ListNode* greaterhead = NULL;
//		ListNode* greatertail = NULL;
//		lesshead = lesstail = (ListNode*)malloc(sizeof(ListNode));
//		greaterhead = greatertail = (ListNode*)malloc(sizeof(ListNode));
//		ListNode* cur = pHead;
//		while (cur)
//		{
//			if (cur->val < x)
//			{
//				lesstail->next = cur;
//				lesstail = cur;
//			}
//			else
//			{
//				greatertail->next = cur;
//				greatertail = cur;
//			}
//			cur = cur->next;
//		}
//		//当倒数第二个值为大于x，倒数第一个为小于x时，
//		//则greatertail->next指向最后一个小于x的值，形成了一个循环。
//		greatertail->next = NULL;
//		//当存储小于x的链表没值，仍旧成立
//		lesstail->next = greaterhead->next;
//		ListNode* list = lesshead->next;
//		free(lesshead);
//		free(greaterhead);
//		return list;
//	}
//};

//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
//class Solution {
//public:
//	ListNode* deleteDuplication(ListNode* pHead)
//	{
//		if (pHead == NULL || pHead->next == NULL)//当只有1个值或没值，直接返回头节点。
//			return pHead;
//		ListNode* n0 = NULL;
//		ListNode* n1 = pHead;
//		ListNode* n2 = pHead->next;
//		while (n2)
//		{
//			if (n1->val != n2->val)
//			{
//				n0 = n1;
//				n1 = n2;
//				n2 = n2->next;
//			}
//			else
//			{
//				while (n2 && n2->val == n1->val) // 将n2移动，找到第一个和n1不相等的位置
//					n2 = n2->next;
//				if (n0)//之前将这个条件里面的内容刚好写反，今后注意
//					n0->next = n2;
//				else   // 分类讨论是否改变头节点
//					pHead = n2;
//				while (n1 != n2)  //释放相等的结点
//				{
//					ListNode* next = n1->next;
//					free(n1);
//					n1 = next;
//				}
//				if (n2)  //当n2为空时，该值解引用会出现问题
//					n2 = n2->next;
//			}
//		}
//		return pHead;
//	}
//};

//链表的回文结构。
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
//class PalindromeList {
//public:
//	//使用头插的方式将中间结点（包括该结点）的后面结点重新连接
//	struct ListNode* reverseList(struct ListNode* head)
//	{
//		struct ListNode* newnode = NULL;
//		struct ListNode* cur = head;
//		while (cur)
//		{
//			struct ListNode* next = cur->next;
//			cur->next = newnode;
//			newnode = cur;
//			cur = next;
//		}
//		return newnode;
//	}
//	bool chkPalindrome(ListNode* A) {
//		struct ListNode*cur = A;
//		int n = 0;
//		while (cur)
//		{
//			++n;
//			cur = cur->next;
//		}
//		cur = A;
//		int mid = n / 2;
//		while (mid--)
//		{
//			cur = cur->next;
//		}
//		struct ListNode* head1 = reverseList(cur);
//		struct ListNode* head2 = A;
//		mid = n / 2;
//		while (mid--) //奇数个结点，则为较少的那个链表为结束标准
//		{            //偶数个结点，则两个链表的结点个数相等
//			if (head1->val == head2->val)
//			{
//				head1 = head1->next;
//				head2 = head2->next;
//			}
//			else
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//};

//输入两个链表，找出它们的第一个公共结点。
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//	struct ListNode* curA = headA;
//	struct ListNode* curB = headB;
//	int lenA = 0, lenB = 0;
//	while (curA)
//	{
//		++lenA;
//		curA = curA->next;
//	}
//	while (curB)
//	{
//		++lenB;
//		curB = curB->next;
//	}
//	int gap = abs(lenA - lenB);
//	struct ListNode* longst = headA;
//	struct ListNode* shortst = headB;
//	if (lenA<lenB)
//	{
//		longst = headB;
//		shortst = headA;
//	}
//
//	while (gap--)
//	{
//		longst = longst->next;
//	}
//
//	while (longst)
//	{
//		if (longst == shortst)
//		{
//			return longst;
//		}
//		else
//		{
//			longst = longst->next;
//			shortst = shortst->next;
//		}
//	}
//	return  NULL;
//}

//给定一个链表，判断链表中是否有环
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//bool hasCycle(struct ListNode *head) {
//	struct ListNode* fast = head;
//	struct ListNode* slow = head;
//	while (fast &&fast->next)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//		if (slow == fast)
//			return true;
//	}
//	return false;
//}

//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//struct ListNode *detectCycle(struct ListNode *head) {
//	int pos = 0;
//	struct ListNode* slow = head;
//	struct ListNode* fast = head;
//	while (fast && fast->next)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//		if (slow == fast)
//		{
//			pos = 1; //标志该链表有环
//			slow = head; //将slow置回到起点与fast在相遇点开始，每次都走一步,直到相遇
//			break;
//		}
//	}
//	while (slow != fast &&fast) //要加上fast的判断，因为当没有环时，fast会走到空。因为fast比slow走的快,所以只用判断fast.
//	{
//		slow = slow->next;
//		fast = fast->next;
//	}
//	if (pos == 0)
//		return NULL;
//	return slow;
//}

//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。要求返回这个链表的深度拷贝。
/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;

Node() {}

Node(int _val, Node* _next, Node* _random) {
val = _val;
next = _next;
random = _random;
}
};
*/
//Node* BuyNode(int val)
//{
//	Node* newnode = (Node*)malloc(sizeof(Node));
//	newnode->val = val;
//	newnode->next = NULL;
//	newnode->random = NULL;
//	return newnode;
//}
//class Solution {
//public:
//	Node* copyRandomList(Node* head){
//		Node* cur = head;
//		while (cur)
//		{
//			//拷贝插入
//			Node* cpnode = BuyNode(cur->val);
//			Node* next = cur->next;
//			cur->next = cpnode;
//			cpnode->next = next;
//			cur = next;
//		}
//		cur = head;
//		while (cur)
//		{
//			//置random
//			Node* cpnode = cur->next;
//			Node* next = cur->next->next;
//			if (cur->random)
//			{
//				cpnode->random = cur->random->next;
//			}
//			cur = next;
//		}
//		cur = head;
//		Node* newhead = BuyNode(0);
//		Node* newtail = newhead;
//		while (cur)
//		{
//			Node* next = cur->next->next;
//			Node* cpnode = cur->next;  //这里一定要创建cpnode节点，不能用cur->next表示，根据实例，当原链表的next到达NULL时，导致cur->next成为一个
//			cur->next = next;          //空值.之后会使newtail->next和newtail都为NULL，导致新链表没有节点2的值。
//			newtail->next = cpnode;
//			newtail = cpnode;
//			cur = next;
//		}
//		Node* list = newhead->next;
//		free(newhead);
//		return list;
//	}
//};
//
//// 之前错误：Node with val 2 was not copied but a reference to the original one 
