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
void SeqListModify(seqlist *ps, size_t pos, DataType x);//修改某个位置的数据为x
void SeqListRemove(seqlist *ps, DataType x); //删除该值
void SeqListRemoveAll(seqlist* ps, DataType x);//删除所有x，重复做删除指定值的操作
void Testseqlist1();
void Testseqlist2();
void Testseqlist3();