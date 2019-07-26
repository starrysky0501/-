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
	while (end > 0)  //������������
	{
		for (int i = 1; i < end; i++)   //���Ƶ������� ��������ָ��λ�ÿ�ѡ����ѡ����ǵڼ���ָ��λ�á�
		{
			if (a[i - 1]>a[i])          //������for(int i=0;i<end-1;i++) ���Ƶ�һ��ָ��
			{
				swap(&a[i - 1], &a[i]);
			}
		}
		end--;
	}

}
//����������������
//int partsort(int *a, int left, int right) // ����ָ�뷨:keyֵѡ������������ұߵ�ֵ��
//{                                         //key����ߣ��ȴ�������ɨ�裻key���ұߣ��ȴ�������ɨ�衣�������ֵ����������
//	int key = a[right];
//	int key_index = right;                //����λ�ñ��棬���㵥�˽������λ����ؼ��ִ���λ�ý��н���
//	while (left < right)
//	{
//		while (left < right && a[left] <= key) 
//		{
//			left++;                       //ע��:a[left]<=key��a[right]>=key��һ��Ҫ�е��ں�,���������������
//		}                               
//		while (left < right && a[right] >= key)
//		{
//			right--;
//		}
//		if (left < right) //ûif������������ʱ���������Ӽ���leftλ�øı䣬����ѭ������Ľ������ִ���
//		{
//			swap(&a[left], &a[right]);
//			left++;                      
//			right--;    //��һ������� �ӼӼ���������ֻ��һ��ֵ����ֵ�п��ܲ���keyֵ��
//		}
//	}

//	swap(&a[left], &a[key_index]);   //���������е�ֵ
//	return left;
//}  

int partsort(int *a, int left, int right) // ����ָ�뷨:keyֵѡ������������ұߵ�ֵ��
{
	int mid = GetMid(a, left, right);
	int key = a[right];
	int key_index = right;
	swap(&a[mid], &a[right]);
	while (left < right)
	{
		while (left < right && a[left] <= key)  //û��left<right,���ܻ����Խ������
		{
			left++;                       //ע��:a[left]<=key��a[right]>=key��һ��Ҫ�е��ںţ�����ͬʱû��,
		}                                 //      �������ѭ���� ����: 49 38 65 97 76 13 27 49 
		while (left < right && a[right] >= key)
		{
			right--;
		}

		swap(&a[left], &a[right]);
		//left++;
		//right--;                         //����left++,right--ʱ���еĻ������ѭ����
	}
	swap(&a[left], &a[key_index]);
	return left;
}

int _partsort(int *a, int left, int right)  //�ڿӷ�(��ֵ)
{
	int key = a[right];   //�ڿ�
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
	a[left] = key;    //��keyֵ����left��right�������㣬left�����С��key���ұߴ���key
	return left;
}

void QuickSort(int *a, int left, int right)
{
	if (left >= right)    //�������������������2, 1;��������ֵ�Ľ��key��QuickSort�����е�ֵ��[0,-1][1,1]
		return;
	if (right - left + 1 > 10)
	{
		int key = partsort(a, left, right);
		QuickSort(a, left, key - 1);
		QuickSort(a, key + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);  //�ݹ��ı�leftֵ
	}
}
//�ڵݹ�������ʱ����������ݱȽ��٣����ǿ��Բ��û������䣬����ֱ�Ӳ��뷨Ч�ʻ���ߡ���Ϊ�����һ��ݹ��������Ľ��Ϊ2��n-1�η�����
//�����ᴴ��û��Ҫ��ջ֡��
int GetMid(int *a, int left, int right)  //����ȡ�з�
{  //����������(˳�������)�����,ʱ�临�Ӷ�ΪO(N*N)����������ȡ�з����Ч��
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
//˼��Ϊ:�ڴ��������еĵ�һ��Ԫ�أ��м�Ԫ�غ����һ��Ԫ��ȡ��Сλ���м���Ǹ�Ԫ�ء�
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

//���������ܲ��ܾ���(����),ȡ����ѡ�ĳ�ʼֵ��(key)
//����ָ�뷨:��ѡ���ұ�Ϊkeyֵ�������������ɨ�裬����ֽ�С��ֵ�������ұߵ����(�ұ�Ӧ�Ŵ���key��ֵ)
//           ���磺49 38 65 97 76 13 49 27 49