#include"HP.h"

// 交换两个元素的值
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

// 堆的销毁
void HeapDestory(Heap* hp) 
{
	assert(hp);
	free(hp->_a);
	hp->_size = hp->_capacity = 0;
	hp->_a = NULL;
}

// 向上调整
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

// 向下调整
void adjustdown(Heap* hp, int parent) {
	int child = parent * 2 + 1; // 先默认和左孩子比较
	while (child < hp->_size) { // 还没到叶子节点
		if ((child + 1) < hp->_size - 1 && hp->_a[child + 1] < hp->_a[child]) {
			child++; // 如果右孩子比左孩子小，则和右孩子比（保持和最小的比）
		}
		if (hp->_a[parent] <= hp->_a[child]) {
			break;
		}
		swap(&hp->_a[parent], &hp->_a[child]);
		parent = child;
		child = parent * 2 + 1;
	}
}

// 扩容操作
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

// 堆的插入
void HeapPush(Heap* hp, HPDataType x) 
{
	HeapExtend(hp);
	hp->_a[hp->_size] = x;
	adjustup(hp, hp->_size);
	hp->_size++;
}


// 堆的删除
void HeapPop(Heap* hp) {
	assert(!HeapEmpty(hp));
	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	adjustdown(hp, 0);
}

// 取堆顶的数据
HPDataType HeapTop(Heap* hp) {
	assert(!HeapEmpty(hp));
	return hp->_a[0];
}

// 堆的数据个数
int HeapSize(Heap* hp) {
	assert(hp);
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp) {
	assert(hp);
	return hp->_size == 0;
}

// 对数组进行堆排序
void HeapSort(int* a, int n) 
{
	Heap hp;
	HeapInit(&hp);
	for (int i = 0; i < n; i++) {
		HeapPush(&hp, a[i]); // 创建堆
	}
	for (int i = 0; i < n; i++) {
		a[i] = HeapTop(&hp);
		HeapPop(&hp);
	}
	HeapDestory(&hp);
}