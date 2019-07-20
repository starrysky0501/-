#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;
typedef struct seqlist
{
	DataType* _array;
	size_t _size;
	size_t _capacity;
}seqlist;

void seqlistinit(seqlist *ps);
void seqlistDestory(seqlist *ps);

void seqlistpushback(seqlist *ps, DataType x);
void seqlistpushfront(seqlist *ps, DataType x);
void seqlistpopback(seqlist *ps);
void seqlistpopfront(seqlist *ps);
void seqlistinsert(seqlist *ps, size_t pos, DataType x);
void seqlisterase(seqlist *ps, size_t pos);

size_t seqlistsize(seqlist *ps);
size_t seqlistfind(seqlist *ps, DataType x);
DataType seqlistat(seqlist *ps, size_t pos);
void seqcheck_capacity(seqlist *ps);

void SeqListBubbleSort(seqlist *ps);
int SeqListBinaryFind(seqlist *ps, DataType x);
void SeqListModify(seqlist *ps, size_t pos, DataType x);//�޸�ĳ��λ�õ�����Ϊx
void SeqListRemove(seqlist *ps, DataType x); //ɾ����ֵ
void SeqListRemoveAll(seqlist* ps, DataType x);//ɾ������x���ظ���ɾ��ָ��ֵ�Ĳ���
void Testseqlist1();
void Testseqlist2();
void Testseqlist3();