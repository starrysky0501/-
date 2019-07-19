#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top; 
	int _capacity; 
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
bool StackEmpty(Stack* ps);
int StackSize(Stack* ps);

//动态数组开辟空间实现栈