#include"HP.h"

// ��������Ԫ�ص�ֵ
void swap(HPDataType* a, HPDataType* b) {
	HPDataType temp = *a;
	*a = *b;
	*b = temp;
}

void HeapInit(Heap* php) 
{
	assert(php);
	php->_a = NULL;
	php->_size = 0;
	php->_capacity = 0;
}

// �ѵ�����
void HeapDestory(Heap* hp) 
{
	assert(hp);
	free(hp->_a);
	hp->_size = hp->_capacity = 0;
	hp->_a = NULL;
}

// ���ϵ���
void adjustup(Heap* hp, int child)
{
	int parents = (child - 1) / 2;
	while (child > 0) {
		if (hp->_a[parents] <= hp->_a[child]) {
			break;
		}
		swap(&hp->_a[parents], &hp->_a[child]);
		child = parents;
		parents = (child - 1) / 2;
	}
}

// ���µ���
void adjustdown(Heap* hp, int parent) {
	int child = parent * 2 + 1; // ��Ĭ�Ϻ����ӱȽ�
	while (child < hp->_size) { // ��û��Ҷ�ӽڵ�
		if ((child + 1) < hp->_size - 1 && hp->_a[child + 1] < hp->_a[child]) {
			child++; // ����Һ��ӱ�����С������Һ��ӱȣ����ֺ���С�ıȣ�
		}
		if (hp->_a[parent] <= hp->_a[child]) {
			break;
		}
		swap(&hp->_a[parent], &hp->_a[child]);
		parent = child;
		child = parent * 2 + 1;
	}
}

// ���ݲ���
void HeapExtend(Heap* hp) {
	assert(hp);
	if (hp->_capacity == hp->_size) {
		int newcapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * (newcapacity));
		if (tmp == NULL) {
			return;
		}
		hp->_a = tmp;
		hp->_capacity = newcapacity;
	}
}

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x) 
{
	HeapExtend(hp);
	hp->_a[hp->_size] = x;
	adjustup(hp, hp->_size);
	hp->_size++;
}


// �ѵ�ɾ��
void HeapPop(Heap* hp) {
	assert(!HeapEmpty(hp));
	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	adjustdown(hp, 0);
}

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp) {
	assert(!HeapEmpty(hp));
	return hp->_a[0];
}

// �ѵ����ݸ���
int HeapSize(Heap* hp) {
	assert(hp);
	return hp->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp) {
	assert(hp);
	return hp->_size == 0;
}

// ��������ж�����
void HeapSort(int* a, int n) 
{
	Heap hp;
	HeapInit(&hp);
	for (int i = 0; i < n; i++) {
		HeapPush(&hp, a[i]); // ������
	}
	for (int i = 0; i < n; i++) {
		a[i] = HeapTop(&hp);
		HeapPop(&hp);
	}
	HeapDestory(&hp);
}