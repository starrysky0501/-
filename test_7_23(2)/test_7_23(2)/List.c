#include"List.h"

void ListInit(List* plt)
{
	assert(plt);
	ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	head->_next = head;
	head->_prev = head;
	plt->_head = head;
}
void ListDestroy(List* plt)
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	plt->_head = NULL;
}
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_prev = NULL;
	return newnode;
}
void ListPushBack(List* plt, LTDataType x)
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* tail = head->_prev;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode = BuyListNode(x);
	//head----tail +newnode
	tail->_next = newnode;
	newnode->_prev = tail;
	newnode->_next = head;
	head->_prev = newnode;
}
void ListPushFront(List* plt, LTDataType x)
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* first = head->_next;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode = BuyListNode(x);
	//head---newnode---first
	head->_next = newnode;
	newnode->_prev = head;
	newnode->_next = first;
	first->_prev = newnode;
}
void ListPopBack(List* plt)
{
	assert(plt);
	ListNode* head = plt->_head;
	assert(head->_next != head);
	ListNode* tail = head->_prev;
	ListNode* prev = tail->_prev;
	//head---prev tail
	free(tail);
	prev->_next = head;
	head->_prev = prev;
}
void ListPopFront(List* plt)
{
	assert(plt);
	ListNode* head = plt->_head;
	assert(head->_next != head);
	ListNode* first = head->_next;
	ListNode* second = first->_next;
	free(first);
	head->_next = second;
	second->_prev = head;
}
ListNode* ListFind(List* plt, LTDataType x)
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
void ListInsert(ListNode* pos, LTDataType x)//在pos之前插入x
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);
	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}
void ListErase(ListNode* pos)//删除pos位置的值
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	free(pos);
	prev->_next = next;
	next->_prev = prev;
}

void ListPrint(List* plt)
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* cur = head->_next;
	printf("head<==>");
	while (cur != head)
	{
		printf("%d<==>", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}
void TestNode1()
{
	List q;
	ListInit(&q);
	ListPushBack(&q, 1);
	ListPushBack(&q, 2);
	ListPushBack(&q, 3);
	ListPushBack(&q, 4);
	ListPushFront(&q, 5);
	ListPrint(&q);
	ListPopBack(&q);
	ListPrint(&q);
	ListPopFront(&q);
	ListPrint(&q);
	ListNode *pos = ListFind(&q, 2);
	ListInsert(pos, 20);
	ListPrint(&q);
	pos = ListFind(&q, 20);
	ListErase(pos);
	ListPrint(&q);
	ListDestroy(&q);
}