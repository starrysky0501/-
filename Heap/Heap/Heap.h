#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
void Ajustdown(HPDataType* a, size_t n, size_t parent);
void AdjustUp(HPDataType *a, size_t child);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
void HeapSort(int* a, int n);
void swap(HPDataType* p1, HPDataType* p2);
void Heapprint(Heap* hp);
void TestHeap1();
void TestHeap2();