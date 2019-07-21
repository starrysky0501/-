//括号匹配问题。
//#include<stdio.h>
//#include<assert.h>
//#include<stdlib.h>
//#include<stdbool.h>
//
//typedef char STDataType;
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
//bool isValid(char * s){
//	Stack st;
//	StackInit(&st);
//	char *symbol[3] = { "()", "[]", "{}" };
//	while (*s)
//	{
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			StackPush(&st, *s);
//		}
//		else if (*s == ')' || *s == ']' || *s == '}')
//		{
//			if (StackEmpty(&st))
//				return false;
//			STDataType top = StackTop(&st);
//			StackPop(&st);
//			for (size_t i = 0; i<3; i++)
//			{
//				if (*s == symbol[i][1])
//				{
//					if (top != symbol[i][0])
//					{
//						StackDestory(&st);
//						return false;
//					}
//					else
//					{
//						break;
//					}
//				}
//			}
//		}
//		s++;
//	}
//	if (st._top == 0)
//		return true;
//	else
//		return false;
//}

//实现一个最小栈。
//声明两个栈
//一个栈存储当前最小值，第一个元素直接进入该栈，后面想入栈必须比当前最小值小。
//出栈时如果最小值出栈，则另一个栈相应的值也出栈。
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
//typedef struct {
//	Stack _st;
//	Stack _minst;
//} MinStack;
//
///** initialize your data structure here. */
//
//MinStack* minStackCreate() {
//	MinStack* q = (MinStack*)malloc(sizeof(MinStack));
//	StackInit(&(q->_st));
//	StackInit(&(q->_minst));
//	return q;
//}
//
//void minStackPush(MinStack* obj, int x) {
//	StackPush(&(obj->_st), x);
//	if (StackEmpty(&(obj->_minst)) || x <= StackTop(&(obj->_minst)))
//	{
//		StackPush(&(obj->_minst), x);
//	}
//}
//
//void minStackPop(MinStack* obj) {
//	int top = StackTop(&(obj->_st));
//	StackPop(&(obj->_st));
//	if (top == StackTop(&(obj->_minst)))
//	{
//		StackPop(&(obj->_minst));
//	}
//}
//
//int minStackTop(MinStack* obj) {
//	if (StackEmpty(&(obj->_st)))
//		return -1;
//	else
//		return obj->_st._a[obj->_st._top - 1];
//}
//
//int minStackGetMin(MinStack* obj) {
//	if (StackEmpty(&(obj->_minst)))
//		return -1;
//	else
//		return obj->_minst._a[obj->_minst._top - 1];
//}
//
//void minStackFree(MinStack* obj) {
//	StackDestory(&(obj->_minst));
//	StackDestory(&(obj->_st));
//	free(obj);
//}

// 设计循环队列
//typedef struct {
//	int *_cycle_array;
//	int front;
//	int tail;
//	int length;
//} MyCircularQueue;
//
///** Initialize your data structure here. Set the size of the queue to be k. */
//bool myCircularQueueIsEmpty(MyCircularQueue* obj);
//bool myCircularQueueIsFull(MyCircularQueue* obj);
//
//MyCircularQueue* myCircularQueueCreate(int k) {
//	MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	q->_cycle_array = (int *)malloc(sizeof(int)*(k + 1));
//	q->tail = q->front = 0;
//	q->length = k + 1;
//	return q;
//}
//
///** Insert an element into the circular queue. Return true if the operation is successful. */
////向循环队列中插入一个元素
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//	if (myCircularQueueIsFull(obj))
//		return false;
//	obj->_cycle_array[obj->tail] = value;
//	obj->tail++;
//	if (obj->tail == obj->length)
//	{
//		obj->tail = 0;
//	}
//	return true;
//}
//
///** Delete an element from the circular queue. Return true if the operation is successful. */
////从循环队列中删除一个元素
//bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//	if (myCircularQueueIsEmpty(obj))
//		return false;
//	obj->front++;
//	if (obj->front == obj->length)
//		obj->front = 0;
//	return true;
//}
//
///** Get the front item from the queue. */
//int myCircularQueueFront(MyCircularQueue* obj) {
//	if (myCircularQueueIsEmpty(obj))
//		return -1;
//	return obj->_cycle_array[obj->front];
//}
//
///** Get the last item from the queue. */
//int myCircularQueueRear(MyCircularQueue* obj) {
//	if (myCircularQueueIsEmpty(obj))
//		return -1;
//	int tail = obj->tail;
//	if (tail == 0)
//	{
//		tail = obj->length - 1;
//	}
//	else
//	{
//		tail--;
//	}
//	return obj->_cycle_array[tail];
//}
//
///** Checks whether the circular queue is empty or not. */
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//	if (obj->front == obj->tail)
//		return true;
//	else
//		return false;
//}
//
///** Checks whether the circular queue is full or not. */
//bool myCircularQueueIsFull(MyCircularQueue* obj) {
//	if (obj->front == (obj->tail + 1) % (obj->length))
//		return true;
//	else
//		return false;
//}
//
//void myCircularQueueFree(MyCircularQueue* obj) {
//	free(obj->_cycle_array);
//	free(obj);
//}