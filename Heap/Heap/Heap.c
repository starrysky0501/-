#include"Heap.h"

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_capacity = n;
	hp->_size = n;
	//�����ɶ�
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		Ajustdown(hp->_a, hp->_size, i);
	}
}

void Ajustdown(HPDataType* a, size_t n, size_t parent) //�Զ�����
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
	while (child > 0)                //������ʹ��parent>=0  (1)parent������Ϊsize_t���ͣ���ѭ��
    {                                //                     (2)��if�����parent�ᶪʧ���ȣ�-1/2
		if (a[child] < a[parent])    //                        ���Կ��Խ���ѭ������Ϊbreak;                       //
		{
			swap(&a[child], &a[parent]); //���� ��д����
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

void HeapSort(int* a, int n) //�������ţ���С���� ���������ţ����󶥶�
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
���ڶѵĻ���������
(1)���ʱ��Ӧ��ֵ�ŵ������е����һ�������ŵ���adjustup������һ���Ե����ϵ�����ֻ���жϺ��ӽ��͸��׽�㣬�����ж��ֵܽ��
(2)����ʱ����Ҫ�������м��λ�ã��������ִ�λ��������һ�������һ���ڵ㣬ֻ�����һ��adjustdown������
(3)������ʱ��Ӧע�������轨�󶥶ѡ�����һ���ڵ�����һ���ڵ㽻������֤���һ��Ϊ��Сֵ�����ŵ���һ��adjustdown(Ԫ�ظ�����1)���ɣ�
   ��Ϊ�м�Ԫ�ص�λ��δ�����ı䡣
(4)���ѵ�ʱ�临�Ӷ�ΪO(n);
(5)�Զ������㷨���Ե������㷨��ʱ�临�Ӷ�ΪO(log n)
(6)memcpy:���Ĺ����Ǵ�src�Ŀ�ʼλ�ÿ���n���ֽڵ����ݵ�dest�����dest�������ݣ����ᱻ���ǡ�
   �����ķ���ֵ��dest��ָ�롣memcpy����������string.hͷ�ļ��
*/