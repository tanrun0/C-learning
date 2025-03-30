#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// 实现小根堆
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a; // 用数组存储
	int _size;
	int _capacity;
}Heap;


void swap(HPDataType* a, HPDataType* b);
// 向上调整（hp 传入的就是用来储存栈的数组的地址 _a ）
void adjustup(Heap* hp, int child);
// 向下调整
void adjustdown(Heap* hp, int parent);
// 扩容操作
void HeapExtend(Heap* hp);
void HeapInit(Heap* php);
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);

// 对数组进行堆排序
void HeapSort(int* a, int n);

