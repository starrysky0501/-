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

void non_recusive(int *a, int left, int right) // �ǵݹ�Ŀ�����������ջ�ĺ���ȳ�˼�룬����������������±�����ջ��
{
	Stack q;
	StackInit(&q);               
	StackPush(&q,left);                   //���ոô����˳��������±�������ҵ���ջ����ջ���Ǵ��������˳��
	StackPush(&q, right);
	while (!StackEmpty(&q))
	{
		int end = StackTop(&q);
		StackPop(&q);
		int begin = StackTop(&q);
		StackPop(&q);
		int key_index = partsort(a, begin, end);
		if (begin < key_index - 1)  //��֤��������Ӧ��������
		{
			StackPush(&q, begin);
			StackPush(&q, key_index - 1);
		}
		if (key_index + 1 < end)  //��֤��������Ӧ��������
		{
			StackPush(&q, key_index + 1);
			StackPush(&q, end);
		}
	}
}

int partsort(int *a, int left, int right)  //ǰ��ָ�뷨
{
	int mid = GetMid(a, left, right);
	swap(&a[mid], &a[right]);
	int cur = left;    //ע�⣺����д��0,����ĳ�ֵ�±�left�ڸı�.
	int prev = left - 1;
	int key = a[right];//ѡ���ұߵ�ֵΪ��Ŧ
	while (cur < right)  //�˳�ѭ�����ǵ�cur�ߵ�rightʱ
	{
		if (a[cur] < key && ++prev != cur) //��prev��cur���ʱ�����ý���
		{
			swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	prev++;
	swap(&a[prev],&a[right]);
	return prev;
}
//˼�룺������ָ��prev��cur;(�ƴ���������ұ���)
//      cur���ƶ��� cur��Ӧ��ֵС��key��cur���prevһ������1��
//      ��cur���ڵ���keyֵ��cur��1��prev���䣬ֱ���ҵ�С��key��ֵ����prev��һ,֮��cur��rev����
//      �˳�ѭ����prevǰ(����prev)����С��key��ֵ������prev��right��ֵ��

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

void InsertSort(int *a, int n) //ֱ�Ӳ�������:��a[end+1]���뵽a[0]--a[end]����������
{
	for (int i = 0; i <n - 1; i++)  //��������
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
				break;
		}
		a[end + 1] = tmp;
	}
}

void MergeSort(int *a, int n)  //���㷨��ʱ�临�Ӷ�ΪO(N*logN) 
{
	int *tmp = (int *)malloc(sizeof(int)*n); //�ռ临�Ӷ�ΪO(N)
	_MergeSort(a, 0, n - 1, tmp);  //����һ���µĺ�����������ú����Լ���ÿ�ζ�Ҫ�����µĿռ䣬��������һ���µ����������
	free(tmp);
}

void _MergeSort(int *a, int left, int right, int *tmp)
{
	if (left == right)     //������ֻ��һ��Ԫ��ʱ���ݹ����
		return;
	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);
	int begin1 = left;     //�ϲ���˼��Ϊ:�ӵݹ�����һ�㿪ʼ���ˣ�����ô���һ��Ϊ�������֣��������������������tmp��
	int end1 = mid;        //              ֮��������������鿽��a������
	int begin2 = mid + 1;
	int end2 = right;
	int i = begin1;  //��֤��tmp�����е������ֵ��a�������ֵһ��
	while (begin1 <= end1 && begin2 <= end2)  //���ھ��ǵݹ����һ�㣬�����������һ��Ԫ��
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
	while (begin1 <=end1)   //һ������Ԫ��û�У���һ�����仹��Ԫ�أ����ο�����
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
//memcpy�����Ĺ����Ǵ�Դsrc��ָ���ڴ��ַ����ʼλ�ÿ�ʼ����n���ֽڵ�Ŀ��dest��ָ���ڴ��ַ����ʼλ���С�
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
//�ݹ�̫������ջ���������
//��������һ��ģ��Ϊ: ��������
//�鲢����:���η�(�����������ţ������ϵ�����)(˼��:�ֽ�+�ϲ�)
//���ŵķǵݹ��㷨��������ջ���������±�ѹ��ջ�У���̬�仯��
//��������ջ�ϵĵݹ�ģ�������ݽṹ�е�ջ�ṹ���ݹ�-->�ǵݹ飩
//�ݹ�-->�ǵݹ飺�ĳ�ѭ��(쳲���������/ǰn���)
//               ����ջ�����ݽṹ