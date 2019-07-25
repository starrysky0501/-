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

void InsertSort(int *a, int n) //直接插入排序:将a[end+1]插入到a[0]--a[end]有序区间中
{
	for (int i = 0; i <n-1; i++)  //整体排序
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)       //单趟排序
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

void  shellsort(int *a, int n) // 希尔排序=预排序(接近于顺序有序)+插入排序
{
	int gap = n;      //gap越小，排序越慢；gap越大，排序越快
	while (gap>1)
	{
		gap = gap / 3 + 1;   //加一保证最后一次的插入排序
		for (int i = 0; i < n - gap; i++)   // 该循环巧妙之处在于，多路同时进行排序
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
//		gap = gap / 3 + 1;  //gap的取值变化
//		for (int j = 0; j < gap; j++)   //多路排序
//		{
//			for (int i = j; i < n - gap; i += gap)   //一路排序区别于多路排序
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

void selectsort(int *a, int n)  //直接选择排序
{
	int begin = 0;
	int end = n - 1;
	int min_index;
	int max_index;
	while (begin < end)  //小于或小于等于都成立
	{
		min_index = max_index = begin;  //注意:等于begin每次改变，且保持每次在数组下标的比较范围内。
		for (int i = begin+1; i <=end; i++)  // 去除第一位，默认为最大和最小处
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
		if (max_index == begin)  //当一个数组中，第一个元素为最大的元素，遍历一次数组，会将最大的值换到最小值下标处，
			max_index = min_index;//所以要进行判断。例:9，4，7，2，1，6，5
		swap(&a[max_index], &a[end]);
		begin++;
		end--;
	}
}
void HeapSort(int *a, int n)  //堆排序:升序，则建大堆
{
	for (int i = (n - 1 - 1) / 2; i >=0; i--) //建堆；从第一个非叶子结点开始
	{
		AdjustDown(a, n, i);
	}
	while (n > 1)
	{
		swap(&a[0], &a[n - 1]); //交换树的根节点和最后一个结点,依此类推；同时也保证树的中间部分有序.
		n--;
		AdjustDown(a, n, 0);  // 只用从根节点向下调整即可。
	}
}
void AdjustDown(int *a, int size, int parent) //向下调整算法
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
//	srand(time(0));    利用随机数检测函数_shellsort是否有问题
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
	printf("直接插入排序所用时间:%d\n", end1 - begin1);
	printf("希尔排序所用时间:%d\n", end2 - begin2);
	printf("选择排序所用时间:%d\n", end3 - begin3);
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
	printf("直接插入排序所用时间:%d\n", end1 - begin1);
	printf("希尔排序所用时间:%d\n", end2 - begin2);
	printf("选择排序所用时间:%d\n", end3 - begin3);
}
void TestSort6()
{
	int a[] = { 5, 6, 1, 7, 8, 4, 2, 5, 9 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}
//选择排序最好最坏情况下的时间复杂度都为O(N*N),效率最低;
//直接插入排序最好情况下时间复杂度为O(N),最坏情况下为O(N*N);
//如果是正序有序，希尔没有直接插入时间复杂度优，会多一个预排;
//