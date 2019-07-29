#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void MergenonR(int *a, int n);
void printsort(int *a, int n);
void TestMergrnonR();
void Testcountsort();
void countsort(int *a, int n);

//归并排序的非递归:时间复杂度为O(N*logN) [gap每次乘2,想象成二叉树,高度为logN,每次合并比较的时间复杂度为O(N)]
//                 空间复杂度为O(N)
void MergenonR(int *a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);                  //准确来说;gap是begin1和end1区间的元素个数
	int gap = 1;                                             //控制一个区间的大小，最小值为一个元素，注意区分begin的含义
	while (gap < n)                                          //gap<n：当等于时，数组已经有序。
	{
		for (int begin = 0; begin < n; begin += 2 * gap)     //begin代表比较的两个有序区间元素的起始下标值，每次跳过两个有序区间。
		{                                                        
			int begin1 = begin, end1 = begin + gap -1;         
			if (end1 >= n)                                   //一种情况:当n为奇数个时,begin1为最后一个元素，则end1应判断在区间范围内
				end1 = n - 1;
			int begin2 = begin + gap, end2 = begin + 2 * gap-1; 
			if (end2 >= n)                                   //同上原理，为什么不判断begin2，因为当begin2不满足，
				end2 = n - 1;                                //end2经过判断一定在范围内，进入while循环会不满足<=的情况
			int index = begin;
			while (begin1 <= end1 && begin2 <= end2)         //*******以下代码为合并*******  
			{
				if (a[begin1] <= a[begin2])
					tmp[index++] = a[begin1++];
				else
					tmp[index++] = a[begin2++];
			}
			while (begin1 <= end1)
				tmp[index++] = a[begin1++];
			while (begin2 <= end2)
				tmp[index++] = a[begin2++];
		}
		memcpy(a, tmp, sizeof(int)*n);                      //区别于递归书写的位置，非递归是将元素遍历一次后，在更改gap，所以拷贝整个数组
		gap = gap * 2;  
	}                                                       //注意:没使用mid
}

//计数排序：求出数组的元素范围max-min+1，开辟空间，统计数组中每个元素出现的次数，该数组中元素的值减去
//(鸽巢原理)最小值为新空间的下标，开辟的空间按从小到达放对应元素的个数。最后在放回原数组中。
//          时间复杂度为:O(MAX(范围,N))   空间复杂度:0(范围)   缺点:数据范围不能太大
void countsort(int *a, int n)
{
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i]>max)
			max = a[i];
	}
	int range = max - min + 1;
	int* counta = (int*)malloc(sizeof(int)*range);
	memset(counta, 0, sizeof(int)*n);                     //注意:只能初始化为0，因为是按字节初始化的，不能初始化为1
	for (int i = 0; i < n; i++)
	{
		counta[a[i] - min]++;                             //统计次数
	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (counta[i]--)
		{
			a[j++] = i + min;                             //排序
		}
	}
}

void printsort(int *a,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void TestMergrnonR()
{
	int a[] = { 41, 2, 7, 92, 1, 3, 64, 8, 5, 0 };
	MergenonR(a, sizeof(a) / sizeof(a[0]));
	printsort(a, sizeof(a) / sizeof(a[0]));
}

void Testcountsort()
{
	int a[] = {44,56,44,12,43,12,78,33,56 };
	MergenonR(a, sizeof(a) / sizeof(a[0]));
	printsort(a, sizeof(a) / sizeof(a[0]));
}
//快排，归并，堆排应熟练掌握
//很多排序的底层用的是快排
//C语言库中有个函数Qsort，该函数就是使用快排
//归并也可以用小区间优化，归并适用于外排
//外排:将外存上的数据大小分成能放入内存的大小的文件，分别在内存中排序，之后在外存上使用归并将所有文件进行排序
