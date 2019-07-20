#include"Heap.h"

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_capacity = n;
	hp->_size = n;
	//构建成堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		Ajustdown(hp->_a, hp->_size, i);
	}
}

void Ajustdown(HPDataType* a, size_t n, size_t parent) //自顶向下
{
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child + 1 < n && a[child + 1] < a[child])                                 //
			child++;
		if (a[child] <a[parent])                                                     //
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapDestory(Heap* hp)
{
	if (hp->_a)
		free(hp->_a);
	hp->_capacity = hp->_size = 0;
}

void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->_capacity == hp->_size)
	{
		int newnode = 0 ? 2 : hp->_capacity * 2;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)*newnode);
		hp->_capacity = newnode;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_a,hp->_size-1);
}

void AdjustUp(HPDataType *a, size_t child)
{
	size_t parent = (child - 1) / 2;
	while (child > 0)                //不建议使用parent>=0  (1)parent的类型为size_t类型，死循环
    {                                //                     (2)在if条件里，parent会丢失精度：-1/2
		if (a[child] < a[parent])    //                        但仍可以结束循环，因为break;                       //
		{
			swap(&a[child], &a[parent]); //粗心 忘写交换
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(Heap* hp)
{
	assert(hp);
	if (!HeapEmpty(&hp))
	{
		swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
		hp->_size--;
		Ajustdown(hp->_a, hp->_size, 0);
	}
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	if (!HeapEmpty(&hp))
		return hp->_a[0];
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return (hp->_size == 0);
}

void HeapSort(int* a, int n) //按降序排，建小顶堆 ；按升序排，建大顶堆
{
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		Ajustdown(a, n, i);
	}
	while (n>1)
	{
		swap(&a[0], &a[n - 1]);
		n--;
		Ajustdown(a, n, 0);
	}
}
void swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void Heapprint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

void TestHeap1()
{
	int a[] = { 2, 7, 8, 0, 7, 5, 3, 1, 9 };
	Heap st;
	HeapInit(&st, a, sizeof(a) / sizeof(a[0]));
	Heapprint(&st);
	HeapPush(&st, 4);
	Heapprint(&st);
	HeapPush(&st,-1);
	Heapprint(&st);
	HeapPop(&st);
	Heapprint(&st);
	HeapDestory(&st);
}

void TestHeap2()
{
	int a[] = { 2, 7, 8, 0, 7, 5, 3, 1, 9 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

/*
关于堆的基本操作：
(1)入堆时，应将值放到数组中的最后一个，接着调用adjustup函数，一次自底向上调整，只用判断孩子结点和父亲结点，不用判断兄弟结点
(2)出堆时，不要动数组中间的位置，否则会出现错位，交换第一个和最后一个节点，只需调用一次adjustdown函数。
(3)堆排序时，应注意升序，需建大顶堆。将第一个节点和最后一个节点交换，保证最后一个为最小值，接着调用一次adjustdown(元素个数少1)即可，
   因为中间元素的位置未发生改变。
(4)建堆的时间复杂度为O(n);
(5)自顶向下算法和自底向上算法的时间复杂度为O(log n)
(6)memcpy:它的功能是从src的开始位置拷贝n个字节的数据到dest。如果dest存在数据，将会被覆盖。
   函数的返回值是dest的指针。memcpy函数定义在string.h头文件里。
*/