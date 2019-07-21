#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
}SListNode;
typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plist);
void SListDestory(SList* plist);
void SListPushFront(SList* plist, SLTDataType x);
void SListPushBack(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
void SListPopBack(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x);
void SListInsertAfter(SListNode* pos, SLTDataType x);
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);
void SListPrint(SList* plist);
void TestSList1();
void TestSList2();