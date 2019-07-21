#include"SList.h"

void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}
void SListPushBack(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	if (plist->_head == NULL)
	{
		plist->_head = newnode;
	}
	else
	{
		SListNode* cur = plist->_head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}
}
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_next = plist->_head;
	plist->_head = newnode;
}
void SListPrint(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}
void SListPopFront(SList* plist)
{
	assert(plist);
	if (plist->_head == NULL)
	{
		return;
	}
	else
	{
		SListNode* cur = plist->_head;
		plist->_head = cur->_next;
		free(cur);
		cur = NULL;
	}
}
void SListPopBack(SList* plist)
{
	assert(plist);
	SListNode* cur = plist->_head;
	if (cur==NULL)
		return;
	else if (cur->_next == NULL)
	{
		free(cur);
		cur = NULL;
	}
	else
	{
		while (cur->_next->_next != NULL)
		{
			cur = cur->_next;
		}
		free(cur->_next);
		cur->_next = NULL;
	}
}
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->_next;
		}
	}
	return NULL;
}
void SListInsertAfter(SListNode* pos, SLTDataType x)//在给定位置后面插入数据
{
	assert(pos);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_next = pos->_next;
	pos->_next = newnode;
}
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->_next == NULL)
		return;
	else
	{
		SListNode* next = pos->_next;
		pos->_next = next->_next;
		free(next);
		next = NULL;
	}
}
void SListRemove(SList* plist, SLTDataType x)//是eraseafter函数和find函数的结合
{
	assert(plist);
	if (plist->_head == NULL)
		return;
	else
	{
		SListNode* cur = plist->_head;
		SListNode* prev = NULL;
		while (cur)
		{
			if (cur->_data == x)
			{
				if (prev == NULL)
					plist->_head = cur->_next;
				else
					prev->_next = cur->_next;
				free(cur);
				cur = NULL;
			}
			else
			{
				prev = cur;
				cur = cur->_next;
			}
		}
	}
}
void SListDestory(SList* plist)
{
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
}
void TestSList1()
{
	SList list;
	SListInit(&list);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPushFront(&list, 1);
	SListPrint(&list);
	SListPopFront(&list);
	SListPrint(&list);
	SListPopBack(&list);
	SListPrint(&list);
	SListDestory(&list);
}
void TestSList2()
{
	SList list;
	SListInit(&list);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPushFront(&list, 1);
	SListPrint(&list);
	SListNode* find = SListFind(&list, 3);
	SListInsertAfter(find, 12);
	SListPrint(&list);
	find = SListFind(&list, 4);
	SListEraseAfter(find);
	SListPrint(&list);
	SListRemove(&list, 2);
	SListPrint(&list);
	SListDestory(&list);
}