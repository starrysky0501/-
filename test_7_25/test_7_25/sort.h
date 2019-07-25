#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>

void InsertSort(int *a, int n);
void shellsort(int *a, int n);
void selectsort(int *a, int n);
void HeapSort(int *a, int n);
void AdjustDown(int *a, int size, int parent);
//void  _shellsort(int *a, int n);
void swap(int *a, int *b);
void Print(int *a, int n);
void TestSort1();
void TestSort2();
void TestSort3();
void TestSort4();
void TestSort5();

void InsertSort(int *a, int n) //ֱ�Ӳ�������:��a[end+1]���뵽a[0]--a[end]����������
{
	for (int i = 0; i <n-1; i++)  //��������
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)       //��������
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void  shellsort(int *a, int n) // ϣ������=Ԥ����(�ӽ���˳������)+��������
{
	int gap = n;      //gapԽС������Խ����gapԽ������Խ��
	while (gap>1)
	{
		gap = gap / 3 + 1;   //��һ��֤���һ�εĲ�������
		for (int i = 0; i < n - gap; i++)   // ��ѭ������֮�����ڣ���·ͬʱ��������
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}	
}

//void  _shellsort(int *a, int n) 
//{
//	int gap = n;
//	while (gap > 1)   
//	{
//		gap = gap / 3 + 1;  //gap��ȡֵ�仯
//		for (int j = 0; j < gap; j++)   //��·����
//		{
//			for (int i = j; i < n - gap; i += gap)   //һ·���������ڶ�·����
//			{
//				int end = i;
//				int tmp = a[end + gap];
//				while (end >= 0)
//				{
//					if (tmp < a[end])
//					{
//						a[end + gap] = a[end];
//						end -= gap;
//					}
//					else
//					{
//						break;
//					}
//				}
//				a[end + gap] = tmp;
//			}
//		}
//	}
//}

void selectsort(int *a, int n)  //ֱ��ѡ������
{
	int begin = 0;
	int end = n - 1;
	int min_index;
	int max_index;
	while (begin < end)  //С�ڻ�С�ڵ��ڶ�����
	{
		min_index = max_index = begin;  //ע��:����beginÿ�θı䣬�ұ���ÿ���������±�ıȽϷ�Χ�ڡ�
		for (int i = begin+1; i <=end; i++)  // ȥ����һλ��Ĭ��Ϊ������С��
		{
			if (a[i] < a[min_index])
			{
				min_index = i;
			}
			if (a[i]>a[max_index])
			{
				max_index = i;
			}
		}
		swap(&a[min_index], &a[begin]);
		if (max_index == begin)  //��һ�������У���һ��Ԫ��Ϊ����Ԫ�أ�����һ�����飬�Ὣ����ֵ������Сֵ�±괦��
			max_index = min_index;//����Ҫ�����жϡ���:9��4��7��2��1��6��5
		swap(&a[max_index], &a[end]);
		begin++;
		end--;
	}
}
void HeapSort(int *a, int n)  //������:�����򽨴��
{
	for (int i = (n - 1 - 1) / 2; i >=0; i--) //���ѣ��ӵ�һ����Ҷ�ӽ�㿪ʼ
	{
		AdjustDown(a, n, i);
	}
	while (n > 1)
	{
		swap(&a[0], &a[n - 1]); //�������ĸ��ڵ�����һ�����,�������ƣ�ͬʱҲ��֤�����м䲿������.
		n--;
		AdjustDown(a, n, 0);  // ֻ�ôӸ��ڵ����µ������ɡ�
	}
}
void AdjustDown(int *a, int size, int parent) //���µ����㷨
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child]>a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;  
	}
}
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Print(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void TestSort1()
{
	int a[] = { 7, 4, 1, 6, 8, 3, 2, 5, 9 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}
void TestSort2()
{
	int a[] = { 4, 1, 7, 8, 3, 2, 5, 9 };
	shellsort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}

//void TestSort2()
//{
//	srand(time(0));    �����������⺯��_shellsort�Ƿ�������
//	const int N = 20;
//	int *a = (int*)malloc(sizeof(int)*N);
//	for (int i = 0; i < N; i++)
//	{
//		a[i] = rand()%20;
//	}
//	Print(a, N);
//	_shellsort(a, N);
//	Print(a, N);
//}

void TestSort3()
{
	int a[] = { 5, 6, 1, 7, 8, 4, 2, 5, 9 };
	selectsort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}
void TestSort4()
{
	const N = 100000;
	int *a = (int*)malloc(sizeof(int)*N);
	int *b = (int*)malloc(sizeof(int)*N);
	int *c = (int*)malloc(sizeof(int)*N);
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		a[i] = rand();
		b[i] = a[i];
		c[i] = a[i];
	}
	int begin1 = clock();
	InsertSort(a, N);
	int end1 = clock();
	int begin2 = clock();
	shellsort(b, N);
	int end2 = clock();
	int begin3 = clock();
	selectsort(c, N);
	int end3 = clock();
	printf("ֱ�Ӳ�����������ʱ��:%d\n", end1 - begin1);
	printf("ϣ����������ʱ��:%d\n", end2 - begin2);
	printf("ѡ����������ʱ��:%d\n", end3 - begin3);
}
void TestSort5()
{
	const N = 10000;
	int *a = (int*)malloc(sizeof(int)*N);
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		a[i] = rand();
	}
	int begin3 = clock();
	selectsort(a, N);
	int end3 = clock();
	int begin2 = clock();
	shellsort(a, N);
	int end2 = clock();
	int begin1 = clock();
	InsertSort(a, N);
	int end1 = clock();
	printf("ֱ�Ӳ�����������ʱ��:%d\n", end1 - begin1);
	printf("ϣ����������ʱ��:%d\n", end2 - begin2);
	printf("ѡ����������ʱ��:%d\n", end3 - begin3);
}
void TestSort6()
{
	int a[] = { 5, 6, 1, 7, 8, 4, 2, 5, 9 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}
//ѡ��������������µ�ʱ�临�Ӷȶ�ΪO(N*N),Ч�����;
//ֱ�Ӳ���������������ʱ�临�Ӷ�ΪO(N),������ΪO(N*N);
//�������������ϣ��û��ֱ�Ӳ���ʱ�临�Ӷ��ţ����һ��Ԥ��;
//