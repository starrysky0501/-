#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>

void BubbleSort(int *a, int n);
void QuickSort(int *a, int left, int right);
int partsort(int *a, int left, int right);
int _partsort(int *a, int left, int right);
int GetMid(int *a, int left, int right);
void InsertSort(int *a, int n);
void swap(int *a, int *b);
void Print(int *a, int n);
void TestSort1();
void TestSort2();

void InsertSort(int *a, int n) //直接插入排序:将a[end+1]插入到a[0]--a[end]有序区间中
{
	for (int i = 0; i <n - 1; i++)  //整体排序
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

void BubbleSort(int *a, int n)
{
	int end = n;
	while (end > 0)  //控制整体排序
	{
		for (int i = 1; i < end; i++)   //控制单趟排序 ，有两个指针位置可选，看选择的是第几个指针位置。
		{
			if (a[i - 1]>a[i])          //还可以for(int i=0;i<end-1;i++) 控制第一个指针
			{
				swap(&a[i - 1], &a[i]);
			}
		}
		end--;
	}

}
//测试用例后有问题
//int partsort(int *a, int left, int right) // 左右指针法:key值选数组最左或最右边的值。
//{                                         //key最左边，先从右向左扫描；key最右边，先从左向右扫描。否则会出现单趟排序错误
//	int key = a[right];
//	int key_index = right;                //将该位置保存，方便单趟结束后的位置与关键字处的位置进行交换
//	while (left < right)
//	{
//		while (left < right && a[left] <= key) 
//		{
//			left++;                       //注意:a[left]<=key和a[right]>=key，一定要有等于号,否则会出现排序错误。
//		}                               
//		while (left < right && a[right] >= key)
//		{
//			right--;
//		}
//		if (left < right) //没if条件，当等于时，交换，加减后，left位置改变，对于循环外面的交换出现错误。
//		{
//			swap(&a[left], &a[right]);
//			left++;                      
//			right--;    //有一种情况， 加加减减后区间只有一个值，该值有可能不比key值大
//		}
//	}

//	swap(&a[left], &a[key_index]);   //交换数组中的值
//	return left;
//}  

int partsort(int *a, int left, int right) // 左右指针法:key值选数组最左或最右边的值。
{
	int mid = GetMid(a, left, right);
	int key = a[right];
	int key_index = right;
	swap(&a[mid], &a[right]);
	while (left < right)
	{
		while (left < right && a[left] <= key)  //没有left<right,可能会出现越界的情况
		{
			left++;                       //注意:a[left]<=key和a[right]>=key，一定要有等于号，否则同时没有,
		}                                 //      会出现死循环。 例如: 49 38 65 97 76 13 27 49 
		while (left < right && a[right] >= key)
		{
			right--;
		}

		swap(&a[left], &a[right]);
		//left++;
		//right--;                         //当有left++,right--时，有的会出现死循环。
	}
	swap(&a[left], &a[key_index]);
	return left;
}

int _partsort(int *a, int left, int right)  //挖坑法(赋值)
{
	int key = a[right];   //挖坑
	while (left < right)
	{
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[right] = a[left];
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[left] = a[right];
	}
	a[left] = key;    //将key值赋给left和right的相遇点，left的左边小于key，右边大于key
	return left;
}

void QuickSort(int *a, int left, int right)
{
	if (left >= right)    //当数组里面存在两个数2, 1;分析返回值的结果key在QuickSort函数中的值。[0,-1][1,1]
		return;
	if (right - left + 1 > 10)
	{
		int key = partsort(a, left, right);
		QuickSort(a, left, key - 1);
		QuickSort(a, key + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);  //递归会改变left值
	}
}
//在递归子问题时，区间的数据比较少，我们可以不用划分区间，采用直接插入法效率会更高。因为到最后一层递归树，他的结点为2的n-1次方个。
//这样会创建没必要的栈帧。
int GetMid(int *a, int left, int right)  //三数取中法
{  //当数组有序(顺序或逆序)情况下,时间复杂度为O(N*N)，采用三数取中法提高效率
	int mid = left + (right - left) / 2;
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] > a[right])
			return right;
		else
			return left;
	}
	else   //a[mid]>=a[left]
	{
		if (a[right]>a[mid])
			return mid;
		else if (a[right]>a[left])
			return right;
		else
			return left;
	}
}
//思想为:在待排序序列的第一个元素，中间元素和最后一个元素取大小位于中间的那个元素。
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
	int a[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}

void TestSort2()
{
	int a[] = { 49, 38, 65, 97, 76, 13, 27, 49 };//1, 5, 9, 7, 6, 8 
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	Print(a, sizeof(a) / sizeof(a[0]));
}

//快速排序能不能均分(区间),取决于选的初始值。(key)
//左右指针法:当选最右边为key值，如果从右向左扫描，会出现较小的值放在最右边的情况(右边应放大于key的值)
//           例如：49 38 65 97 76 13 49 27 49