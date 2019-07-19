#include"Dequeue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = NULL;
	pq->_rear = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	while (pq->_front)
	{
		QueueNode* next = pq->_front->_next;
		free(pq->_front);
		pq->_front = next;
	}
	pq->_rear = NULL;
}
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	if (pq->_front == NULL)
	{
		QueueNode* cur = BuyQueueNode(x);
		pq->_rear = cur;
		pq->_front = cur;
	}
	else
	{
		QueueNode* cur = BuyQueueNode(x);
		pq->_rear->_next=cur;
		pq->_rear = cur;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq && pq->_front != NULL);
	QueueNode* next= pq->_front->_next;
	free(pq->_front);
	pq->_front = next;
}
QUDataType QueueFront(Queue* pq)
{
	assert(pq && pq->_front != NULL);
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq)
{
	assert(pq && pq->_rear != NULL);
	return pq->_rear->_data;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	if (pq->_front == NULL)
		return true;
	else
		return false;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	size_t sizenode = 0;
	QueueNode* cur = pq->_front;
	while (cur)
	{
		sizenode++;
		cur = cur->_next;
	}
	return sizenode;
}