#include"stack.h"

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	ps->_capacity = ps->_top = 0;
	free(ps->_a);
	ps->_a = NULL;
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_capacity == ps->_top)
	{
		size_t newsize = (ps->_capacity == 0) ? 2 : 2 * ps->_capacity;
		ps->_a = realloc(ps->_a,sizeof(STDataType)*newsize);
		ps->_capacity = newsize;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	if (ps->_top != 0)
		ps->_top--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top != 0);
	return ps->_a[ps->_top-1];
}
bool StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
		return true;
	else
		return false;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}