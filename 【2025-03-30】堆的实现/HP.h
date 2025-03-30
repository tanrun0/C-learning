#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// ʵ��С����
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a; // ������洢
	int _size;
	int _capacity;
}Heap;


void swap(HPDataType* a, HPDataType* b);
// ���ϵ�����hp ����ľ�����������ջ������ĵ�ַ _a ��
void adjustup(Heap* hp, int child);
// ���µ���
void adjustdown(Heap* hp, int parent);
// ���ݲ���
void HeapExtend(Heap* hp);
void HeapInit(Heap* php);
// �ѵ�����
void HeapDestory(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);

// ��������ж�����
void HeapSort(int* a, int n);

