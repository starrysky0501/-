//用队列实现栈
//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//typedef int QUDataType;
//typedef struct QueueNode
//{
//	struct QueueNode* _next;
//	QUDataType _data;
//}QueueNode;
//typedef struct Queue
//{
//	QueueNode* _front; // 队头
//	QueueNode* _rear; // 队尾
//}Queue;
//
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->_front = NULL;
//	pq->_rear = NULL;
//}
//void QueueDestory(Queue* pq)
//{
//	assert(pq);
//	while (pq->_front)
//	{
//		QueueNode* next = pq->_front->_next;
//		free(pq->_front);
//		pq->_front = next;
//	}
//	pq->_rear = NULL;
//}
//QueueNode* BuyQueueNode(QUDataType x)
//{
//	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
//	newnode->_data = x;
//	newnode->_next = NULL;
//	return newnode;
//}
//void QueuePush(Queue* pq, QUDataType x)
//{
//	assert(pq);
//	if (pq->_front == NULL)
//	{
//		QueueNode* cur = BuyQueueNode(x);
//		pq->_rear = cur;
//		pq->_front = cur;
//	}
//	else
//	{
//		QueueNode* cur = BuyQueueNode(x);
//		pq->_rear->_next = cur;
//		pq->_rear = cur;
//	}
//}
//void QueuePop(Queue* pq)
//{
//	assert(pq && pq->_front != NULL);
//	QueueNode* next = pq->_front->_next;
//	free(pq->_front);
//	pq->_front = next;
//}
//QUDataType QueueFront(Queue* pq)
//{
//	assert(pq && pq->_front != NULL);
//	return pq->_front->_data;
//}
//QUDataType QueueBack(Queue* pq)
//{
//	assert(pq && pq->_rear != NULL);
//	return pq->_rear->_data;
//}
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//	if (pq->_front == NULL)
//		return true;
//	else
//		return false;
//}
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//	size_t sizenode = 0;
//	QueueNode* cur = pq->_front;
//	while (cur)
//	{
//		sizenode++;
//		cur = cur->_next;
//	}
//	return sizenode;
//}
//
//typedef struct {
//	Queue queue1;
//	Queue queue2;
//} MyStack;
///** Initialize your data structure here. */
//
//MyStack* myStackCreate() {
//	MyStack* q = (MyStack*)malloc(sizeof(MyStack));
//	QueueInit(&(q->queue2));
//	QueueInit(&(q->queue1));
//	return q;
//}
//
///** Push element x onto stack. */
//void myStackPush(MyStack* obj, int x) {
//	if (QueueEmpty(&(obj->queue1)))
//	{
//		QueuePush(&(obj->queue2), x);
//	}
//	else
//	{
//		QueuePush(&(obj->queue1), x);
//	}
//}
//
///** Removes the element on top of the stack and returns that element. */
//int myStackPop(MyStack* obj) {
//	Queue *empty = &obj->queue1;
//	Queue *nonempty = &obj->queue2;
//	if (QueueEmpty(&obj->queue2))
//	{
//		empty = &obj->queue2;
//		nonempty = &obj->queue1;
//	}
//	while (QueueSize(nonempty)>1)
//	{
//		QueuePush(empty, QueueFront(nonempty));
//		QueuePop(nonempty);
//	}
//	int top = QueueFront(nonempty);
//	QueuePop(nonempty);
//	return top;
//}
//
///** Get the top element. */
//int myStackTop(MyStack* obj) {
//	Queue *empty = &obj->queue1;
//	Queue *nonempty = &obj->queue2;
//	if (QueueEmpty(&obj->queue2))
//	{
//		empty = &obj->queue2;
//		nonempty = &obj->queue1;
//	}
//	int top = 0;
//	while (QueueSize(nonempty)>0)
//	{
//		if (QueueSize(nonempty) == 1)
//		{
//			top = QueueFront(nonempty);
//		}
//		QueuePush(empty, QueueFront(nonempty));
//		QueuePop(nonempty);
//	}
//
//	return top;
//}
//
///** Returns whether the stack is empty. */
//bool myStackEmpty(MyStack* obj) {
//	return  QueueEmpty(&obj->queue1) && QueueEmpty(&obj->queue2);
//}
//
//void myStackFree(MyStack* obj) {
//	QueueDestory(&obj->queue1);
//	QueueDestory(&obj->queue2);
//	free(obj);
//}


//用栈实现队列
//用两个栈，栈二如果不为空，则返回栈二的栈顶元素
//         栈二如果为空，则将栈一的所有元素全部压入到栈二中，在取栈顶。
//注：栈二可能为空，也可能不为空，不为空可能由于pop函数或peek函数。
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* _a;
//	int _top;
//	int _capacity;
//}Stack;
//
//void StackInit(Stack* ps)
//{
//	assert(ps);
//	ps->_a = NULL;
//	ps->_capacity = ps->_top = 0;
//}
//
//void StackDestory(Stack* ps)
//{
//	assert(ps);
//	ps->_capacity = ps->_top = 0;
//	free(ps->_a);
//	ps->_a = NULL;
//}
//void StackPush(Stack* ps, STDataType x)
//{
//	assert(ps);
//	if (ps->_capacity == ps->_top)
//	{
//		size_t newsize = (ps->_capacity == 0) ? 2 : 2 * ps->_capacity;
//		ps->_a = realloc(ps->_a, sizeof(STDataType)*newsize);
//		ps->_capacity = newsize;
//	}
//	ps->_a[ps->_top] = x;
//	ps->_top++;
//}
//void StackPop(Stack* ps)
//{
//	assert(ps && ps->_top > 0);
//	if (ps->_top != 0)
//		ps->_top--;
//}
//STDataType StackTop(Stack* ps)
//{
//	assert(ps && ps->_top != 0);
//	return ps->_a[ps->_top - 1];
//}
//bool StackEmpty(Stack* ps)
//{
//	assert(ps);
//	if (ps->_top == 0)
//		return true;
//	else
//		return false;
//}
//int StackSize(Stack* ps)
//{
//	assert(ps);
//	return ps->_top;
//}
//
//
//typedef struct {
//	Stack _popst;
//	Stack _pushst;
//} MyQueue;
//
///** Initialize your data structure here. */
//
//MyQueue* myQueueCreate() {
//	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
//	StackInit(&q->_popst);
//	StackInit(&q->_pushst);
//	return q;
//}
//
///** Push element x to the back of queue. */
//void myQueuePush(MyQueue* obj, int x) {
//	StackPush(&obj->_pushst, x);
//}
//
///** Removes the element from in front of queue and returns that element. */
//int myQueuePop(MyQueue* obj) {
//	if (StackEmpty(&obj->_popst))
//	{
//		while (!StackEmpty(&obj->_pushst))
//		{
//			int top = StackTop(&obj->_pushst);
//			StackPop(&obj->_pushst);
//			StackPush(&obj->_popst, top);
//		}
//	}
//	int _top = StackTop(&obj->_popst);
//	StackPop(&obj->_popst);
//	return _top;
//}
//
///** Get the front element. */
//int myQueuePeek(MyQueue* obj) {
//	if (StackEmpty(&obj->_popst))
//	{
//		while (!StackEmpty(&obj->_pushst))
//		{
//			int top = StackTop(&obj->_pushst);
//			StackPop(&obj->_pushst);
//			StackPush(&obj->_popst, top);
//		}
//	}
//	int _top = StackTop(&obj->_popst);
//	return _top;
//}
//
///** Returns whether the queue is empty. */
//bool myQueueEmpty(MyQueue* obj) {
//	if (StackEmpty(&obj->_popst) && StackEmpty(&obj->_pushst))
//		return true;
//	else
//		return false;
//}
//
//void myQueueFree(MyQueue* obj) {
//	StackDestory(&obj->_popst);
//	StackDestory(&obj->_pushst);
//	free(obj);
//}
