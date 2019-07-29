#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void MergenonR(int *a, int n);
void printsort(int *a, int n);
void TestMergrnonR();
void Testcountsort();
void countsort(int *a, int n);

//�鲢����ķǵݹ�:ʱ�临�Ӷ�ΪO(N*logN) [gapÿ�γ�2,����ɶ�����,�߶�ΪlogN,ÿ�κϲ��Ƚϵ�ʱ�临�Ӷ�ΪO(N)]
//                 �ռ临�Ӷ�ΪO(N)
void MergenonR(int *a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);                  //׼ȷ��˵;gap��begin1��end1�����Ԫ�ظ���
	int gap = 1;                                             //����һ������Ĵ�С����СֵΪһ��Ԫ�أ�ע������begin�ĺ���
	while (gap < n)                                          //gap<n��������ʱ�������Ѿ�����
	{
		for (int begin = 0; begin < n; begin += 2 * gap)     //begin����Ƚϵ�������������Ԫ�ص���ʼ�±�ֵ��ÿ�����������������䡣
		{                                                        
			int begin1 = begin, end1 = begin + gap -1;         
			if (end1 >= n)                                   //һ�����:��nΪ������ʱ,begin1Ϊ���һ��Ԫ�أ���end1Ӧ�ж������䷶Χ��
				end1 = n - 1;
			int begin2 = begin + gap, end2 = begin + 2 * gap-1; 
			if (end2 >= n)                                   //ͬ��ԭ��Ϊʲô���ж�begin2����Ϊ��begin2�����㣬
				end2 = n - 1;                                //end2�����ж�һ���ڷ�Χ�ڣ�����whileѭ���᲻����<=�����
			int index = begin;
			while (begin1 <= end1 && begin2 <= end2)         //*******���´���Ϊ�ϲ�*******  
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
		memcpy(a, tmp, sizeof(int)*n);                      //�����ڵݹ���д��λ�ã��ǵݹ��ǽ�Ԫ�ر���һ�κ��ڸ���gap�����Կ�����������
		gap = gap * 2;  
	}                                                       //ע��:ûʹ��mid
}

//����������������Ԫ�ط�Χmax-min+1�����ٿռ䣬ͳ��������ÿ��Ԫ�س��ֵĴ�������������Ԫ�ص�ֵ��ȥ
//(�볲ԭ��)��СֵΪ�¿ռ���±꣬���ٵĿռ䰴��С����Ŷ�ӦԪ�صĸ���������ڷŻ�ԭ�����С�
//          ʱ�临�Ӷ�Ϊ:O(MAX(��Χ,N))   �ռ临�Ӷ�:0(��Χ)   ȱ��:���ݷ�Χ����̫��
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
	memset(counta, 0, sizeof(int)*n);                     //ע��:ֻ�ܳ�ʼ��Ϊ0����Ϊ�ǰ��ֽڳ�ʼ���ģ����ܳ�ʼ��Ϊ1
	for (int i = 0; i < n; i++)
	{
		counta[a[i] - min]++;                             //ͳ�ƴ���
	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (counta[i]--)
		{
			a[j++] = i + min;                             //����
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
//���ţ��鲢������Ӧ��������
//�ܶ�����ĵײ��õ��ǿ���
//C���Կ����и�����Qsort���ú�������ʹ�ÿ���
//�鲢Ҳ������С�����Ż����鲢����������
//����:������ϵ����ݴ�С�ֳ��ܷ����ڴ�Ĵ�С���ļ����ֱ����ڴ�������֮���������ʹ�ù鲢�������ļ���������
