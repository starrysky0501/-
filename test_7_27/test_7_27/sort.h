#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include"Stack.h"

void QuickSort(int *a, int left, int right);
int partsort(int *a, int left, int right);
int GetMid(int *a, int left, int right);
void InsertSort(int *a, int n);
void MergeSort(int *a, int n);
void _MergeSort(int *a, int left, int right, int *tmp);
void swap(int *a, int *b);
void Print(int *a, int n);
void TestQuick1();
void TestQuick2();
void TestMerge();

void QuickSort(int *a, int left, int right)
{
	if (left >= right)
		return;
	if (right - left + 1 > 10)
	{
		int key = partsort(a, left, right);
		QuickSort(a, left, key - 1);
		QuickSort(a, key + 1, right);
	}
	else
	{
		InsertSort(a, sizeof(a) / sizeof(a[0]));
	}
}

void non_recusive(int *a, int left, int right) // 非递归的快速排序，利用栈的后进先出思想，将排序区间的左右下表存放在栈中
{
	Stack q;
	StackInit(&q);               
	StackPush(&q,left);                   //按照该代码的顺序，数组的下标从左向右的入栈，出栈则是从右向左的顺序
	StackPush(&q, right);
	while (!StackEmpty(&q))
	{
		int end = StackTop(&q);
		StackPop(&q);
		int begin = StackTop(&q);
		StackPop(&q);
		int key_index = partsort(a, begin, end);
		if (begin < key_index - 1)  //保证区间最少应有两个数
		{
			StackPush(&q, begin);
			StackPush(&q, key_index - 1);
		}
		if (key_index + 1 < end)  //保证区间最少应有两个数
		{
			StackPush(&q, key_index + 1);
			StackPush(&q, end);
		}
	}
}

int partsort(int *a, int left, int right)  //前后指针法
{
	int mid = GetMid(a, left, right);
	swap(&a[mid], &a[right]);
	int cur = left;    //注意：不能写成0,区间的初值下标left在改变.
	int prev = left - 1;
	int key = a[right];//选最右边的值为枢纽
	while (cur < right)  //退出循环就是当cur走到right时
	{
		if (a[cur] < key && ++prev != cur) //当prev和cur相等时，不用交换
		{
			swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	prev++;
	swap(&a[prev],&a[right]);
	return prev;
}
//思想：有两个指针prev和cur;(推大的数据向右边走)
//      cur先移动， cur对应的值小于key，cur会和prev一起增加1；
//      当cur大于等于key值，cur加1，prev不变，直到找到小于key的值，将prev加一,之后cur和rev交换
//      退出循环后，prev前(包括prev)都是小于key的值。交换prev和right的值。

int GetMid(int *a, int left, int right)
{
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
	else  //a[mid]>=a[left]
	{
		if (a[right] > a[mid])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
}

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
				break;
		}
		a[end + 1] = tmp;
	}
}

void MergeSort(int *a, int n)  //该算法的时间复杂度为O(N*logN) 
{
	int *tmp = (int *)malloc(sizeof(int)*n); //空间复杂度为O(N)
	_MergeSort(a, 0, n - 1, tmp);  //创建一个新的函数，如果调用函数自己，每次都要开辟新的空间，而不是在一个新的数组上完成
	free(tmp);
}

void _MergeSort(int *a, int left, int right, int *tmp)
{
	if (left == right)     //当区间只有一个元素时，递归结束
		return;
	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);
	int begin1 = left;     //合并的思想为:从递归最深一层开始回退，到达该处第一次为两个数字，将这两个区间排序放在tmp中
	int end1 = mid;        //              之后将区间有序的数组拷回a数组中
	int begin2 = mid + 1;
	int end2 = right;
	int i = begin1;  //保证在tmp数组中的区间初值与a的区间初值一致
	while (begin1 <= end1 && begin2 <= end2)  //等于就是递归最后一层，两个区间各有一个元素
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1];
			begin1++;
		}
		else
		{
			tmp[i++] = a[begin2];
			begin2++;
		}
	}
	while (begin1 <=end1)   //一个区间元素没有，另一个区间还有元素，依次拷贝。
	{
		tmp[i++] = a[begin1];
		begin1++;
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2];
		begin2++;
	}
	memcpy(a + left, tmp + left, sizeof(int)*(i - left));
}
//memcpy函数的功能是从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中。
//void* memcpy(void* destination, const void* source, size_t num);

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Print(int *a, int n)
{
	for (int i = 0; i < n ; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void TestQuick1()
{
	int a[] = { 4, 2, 6, 8, 5, 1, 9, 7, 3, 0 };
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	Print(a, sizeof(a) / sizeof(a[0]));
}

void TestQuick2()
{
	int a[] = { 4, 2, 6, 8, 5, 1, 9, 7, 3, 0 };
	non_recusive(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	Print(a, sizeof(a) / sizeof(a[0]));
}

void TestMerge()
{
	int a[] = { 4, 2, 6, 8, 5, 1, 9, 7, 3, 0 };
	MergeSort(a, sizeof(a) / sizeof(a[0]));
	Print(a, sizeof(a) / sizeof(a[0]));
}
//递归太深会出现栈溢出的问题
//解决问题的一种模型为: 创造条件
//归并排序:分治法(可以用于外排，磁盘上的排序)(思想:分解+合并)
//快排的非递归算法，借助于栈，将左右下标压入栈中，动态变化。
//将函数在栈上的递归模拟变成数据结构中的栈结构（递归-->非递归）
//递归-->非递归：改成循环(斐波那契数列/前n项和)
//               借助栈的数据结构