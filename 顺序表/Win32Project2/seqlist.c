#define _CRT_SECURE_NO_WARNINGS
#include "seqlist.h"
void seqlistinit(seqlist *ps)
{
	assert(ps);
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
}

void seqlistDestory(seqlist *ps)
{
	assert(ps);
	if (ps->_array)
	{
		free(ps->_array);
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

void seqcheck_capacity(seqlist *ps)
{
	assert(ps);
	if (ps->_capacity == ps->_size)
	{
		size_t newcapacity = (ps->_capacity == 0) ? 4: (ps->_capacity * 2);
		ps->_array = realloc(ps->_array, sizeof(DataType)*newcapacity);
		ps->_capacity = newcapacity;
	}
}

void seqlistpushback(seqlist *ps, DataType x)
{
	assert(ps);
	seqcheck_capacity(ps);
	ps->_array[ps->_size] = x;
	ps->_size++;
}

void seqlistpushfront(seqlist *ps, DataType x)
{
	assert(ps);
	seqcheck_capacity(ps);
	size_t end = ps->_size;
	while (end > 0)
	{
		ps->_array[end] = ps->_array[end-1];
		--end;
	}
	ps->_array[end] = x;
	ps->_size++;
}

size_t seqlistsize(seqlist *ps)
{
	assert(ps);
	return ps->_size;
}

DataType seqlistat(seqlist *ps, size_t pos)
{
	assert(ps);
	return ps->_array[pos];
}

void seqlistpopback(seqlist *ps)
{
	assert(ps);
	if (ps->_size==0)
	{
		printf("顺序表为空!\n");
		return;
	}
	ps->_size--;
}

void seqlistpopfront(seqlist *ps)
{
	assert(ps);
	if (ps->_size==0)
	{
		printf("顺序表为空!\n");
		return;
	}
	for (size_t i = 1; i < ps->_size; i++)
	{
		ps->_array[i - 1] = ps->_array[i];
	}
	ps->_size--;
}

void seqlistinsert(seqlist *ps, size_t pos, DataType x)
{
	assert(ps);
	seqcheck_capacity(ps);
	/*size_t end = ps->_size;  
	while (end>pos)   //注意千万别等于 小心死循环  负数变成无符号整型会成为最大的正数
	{
		ps->_array[end] = ps->_array[end - 1];
		--end;
	}
	ps->_array[end] = x;
	ps->_size++;*/

	int end = ps->_size - 1;
	while (end >= (int)pos) //会有整形提升，所以应将pos类型强制转换
	{
		ps->_array[end + 1] = ps->_array[end];
		--end;
	}
	ps->_array[end+1] = x;
	ps->_size++;
}

void seqlisterase(seqlist *ps, size_t pos)
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("顺序表为空!\n");
		return;
	}
	size_t start = pos;
	while (start<ps->_size-1)
	{
		ps->_array[start] = ps->_array[start + 1];
		++start;
	}
	ps->_size--;
}

size_t seqlistfind(seqlist *ps, DataType x)
{
	for (size_t i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListBubbleSort(seqlist* ps)
{
	size_t end = ps->_size ;
	int pos = 0;
	while (end > 1)
	{
		for (int i = 1; i < end; i++)
		{
			if (ps->_array[i - 1]>ps->_array[i])
			{
				pos = 1;
				int temp = ps->_array[i - 1];
				ps->_array[i - 1] = ps->_array[i];
				ps->_array[i] = temp;
			}

		}
		if (pos == 0)
			break;
		end--;
	}	
}

int SeqListBinaryFind(seqlist *ps, DataType x)
{
	size_t left = 0;
	size_t right = ps->_size - 1;
	while (left <= right)
	{
		size_t middle = left + (right - left) / 2;
		if (x > ps->_array[middle])
			left = middle + 1;
		else if (x < ps->_array[middle])
			right = middle - 1;
		else
			return middle;  //返回下标
	}
	return -1;
}

void SeqListModify(seqlist *ps, size_t pos, DataType x)
{
	if (pos>ps->_size - 1)
	{
		printf("不存在该位置!\n");
		return;
	}
	else
		ps->_array[pos] = x;
}

void SeqListRemove(seqlist *ps, DataType x)
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("顺序表为空!\n");
		return;
	}
	/*size_t start = seqlistfind(ps, x);
	if ((int)start == -1)
		return;
	while (start<ps->_size - 1)
	{
		ps->_array[start] = ps->_array[start + 1];
		++start;
	}
	ps->_size--;*/
	int start =(int) seqlistfind(ps, x);    //注意ps不用取地址，本身就为指针
	if (start != -1)
		seqlisterase(ps, start);           //注意ps不用取地址，本身就为指针
}

//时间复杂度：O(N) 空间复杂度 O(1)
//进行一次元素遍历；每次开辟常数个空间
void SeqListRemoveAll(seqlist* ps, DataType x)
{
	assert(ps);
	size_t j = 0, i = 0;
	while (i<ps->_size)
	{
		if (ps->_array[i] != x)
		{
			ps->_array[j++] = ps->_array[i];
		}
		i++;
	}
	ps->_size = j;
}

void Testseqlist1()
{
	seqlist q;
	seqlistinit(&q);
	seqlistpushback(&q, 1);
	seqlistpushback(&q, 2);
	seqlistpushback(&q, 3);
	seqlistpushback(&q, 4);
	seqlistpushfront(&q, 10);
	seqlistpopback(&q);
	seqlistpopfront(&q);
	for (size_t i = 0; i < seqlistsize(&q); i++)
	{
		printf("%d ", seqlistat(&q, i));
	}
	printf("\n");
	seqlistDestory(&q);
}

void Testseqlist2()
{
	seqlist p;
	seqlistinit(&p);
	seqlistpushback(&p, 1);
	seqlistpushback(&p, 2);
	seqlistpushback(&p, 3);
	seqlistpushback(&p, 4);
	seqlistinsert(&p, 3, 10);
	seqlistinsert(&p, 0, 20);
	seqlisterase(&p, 0);
	seqlisterase(&p, 1);
	for (size_t i = 0; i < seqlistsize(&p); i++)
	{
		printf("%d ", seqlistat(&p, i));
	}
	printf("\n");
	seqlistDestory(&p);
}

void Testseqlist3()
{
	seqlist p;
	seqlistinit(&p);
	seqlistpushback(&p, 2);
	seqlistpushback(&p, 4);
	seqlistpushback(&p, 1);
	seqlistpushback(&p, 3);
	seqlistpushback(&p, 7);
	seqlistpushback(&p, 5);
	seqlistpushback(&p, 5);
	seqlistpushback(&p, 5);
	seqlistpushback(&p, 8);
	seqlistpushback(&p, 6);
	SeqListBubbleSort(&p);
	for (size_t i = 0; i < seqlistsize(&p); i++)
	{
		printf("%d ", seqlistat(&p, i));
	}
	printf("\n");
	if (SeqListBinaryFind(&p, 7) == -1)
	{
		printf("没找到!\n");
	}
	else
	{
		printf("找到了，改值的下标为：%d\n", SeqListBinaryFind(&p, 7));
	}
	SeqListModify(&p, 3, 40);
	for (size_t i = 0; i < seqlistsize(&p); i++)
	{
		printf("%d ", seqlistat(&p, i));
	}
	printf("\n");
	SeqListRemove(&p, 1);
	for (size_t i = 0; i < seqlistsize(&p); i++)
	{
		printf("%d ", seqlistat(&p, i));
	}
	printf("\n");
	SeqListRemoveAll(&p, 5);
	for (size_t i = 0; i < seqlistsize(&p); i++)
	{
		printf("%d ", seqlistat(&p, i));
	}
	printf("\n");
	seqlistDestory(&p);
}