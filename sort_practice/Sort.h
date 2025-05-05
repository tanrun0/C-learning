#pragma once
#include<iostream>
using namespace std;
// ��������
// ˼·��������ֳ�������ʹ��������ΰѴ������е�Ԫ�ز��뵽������ĺ��ʵ�λ��
// ʱ�临�Ӷȣ�O(n^2), �ռ临�Ӷ�O(1)���ȶ�

void InsertSort(int* arr, int n)
{
	for (int i = 1; i < n; i++) // ������Ԫ�شӵڶ���Ԫ�ؿ�ʼ
	{
		int tmp = arr[i], j = i - 1;
		while (j >= 0 && arr[j] > tmp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
	}
}

// ϣ�����򣨸�����Ĳ�������
// ˼·��
// 1. ѡ���������У�������Ҫѡ��һ���������� h���������У�h = n / 2, n / 4, ..., 1��,Ҳ����ÿ�����ּ�� h Ϊһ�顣
// 2. ���������з���������򣺶���ÿ������ h��������ֳ� h ���飬��ÿ�����ڵ�Ԫ�ؽ��в�������
// 3. ��С�������𽥼�С���� h ��ֵ���ظ����� 2��ֱ�� h ���� 1������ 1 ʱ�ʹ����������
// ʱ�临�Ӷȣ�O(n^2), �ռ临�Ӷ�O(1)�����ȶ�����Ϊ��ͬԪ�ؿ��ܱ��ֵ���ͬ���顿

void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;
		// ����ض���gap�����е��β�������
		for (int i = gap; i < n; i++) // i ����һ���������
		{
			int tmp = arr[i], j = i - gap; // arr[j] �������ǰһ��
			while (j >= 0 && arr[j] > tmp)
			{
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = tmp;
		}
	}
}

// ѡ������
// ˼·��ÿ�δӴ���������ѡ��һ����Сֵ����ӵ����������е�ĩβ��ֱ��ȫ�������������꼴�ɡ�
// ʱ�临�Ӷȣ�O(n^2)���ռ临�Ӷȣ�O(1)�����ȶ�����ΪԪ�ؽ���λ�õ�ʱ�򣬿��ܻύ����ͬԪ�ص����λ�á�
void SelectSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int mini = i;
		for (int j = i; j < n; j++)
		{
			if (arr[j] < arr[mini])
				mini = j;
		}
		swap(arr[i], arr[mini]);
	}
}

// ð������
// ˼·������ n - 1�����飬ÿ�α�����ʱ�򣬱Ƚ����ڵ�����Ԫ�أ����arr[i] > arr[i + 1]���򽻻�λ��
// ÿ�ֶ����԰�����Ԫ�ؽ��������
// ʱ�临�Ӷȣ�O(n^2)���ռ临�Ӷȣ�O(1)���ȶ�

void BulleSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}


// ������
// ˼·������ �ѣ�����ѣ����Ӷ� <= ���ף�
// ÿ�ΰѶѶ�Ԫ�ػ������Ȼ������ѣ���ʱ�ĶѾͲ��������һ��Ԫ���ˣ�����ʱ��Ͱ����ֵ�ź���
// ʱ�临�Ӷȣ�O(nlogn)���ռ临�Ӷȣ�O(1)�����ȶ�����Ϊ�ͶѶ�Ԫ�ؽ�����ʱ����ܸı����λ�á�

void HeapAdjust(int* arr, int start, int end) // ���µ�������
{
	int child = 2 * start + 1; // Ĭ�Ϻ����ӱȽ�
	while (child < end)
	{
		if (child + 1 < end && arr[child] < arr[child + 1]) // �����Һ������� ��� ����һ��
		{
			child++;
		}
		if (arr[start] >= arr[child]) // �Ѿ��������ˣ������ٵ���
			break;
		swap(arr[child], arr[start]);
		start = child;
		child = start * 2 + 1;
	}
}

// ������
void HeapSort(int* arr, int n) 
{
	// ���������
	for (int i = (n - 2) / 2; i >= 0; i--)  // n - 1 �����һ���ڵ㣬((n - 1) - 1 / 2)���õ����׽ڵ㣨��ΪҶ�ӽڵ㲻�õ�����
	{
		HeapAdjust(arr, i, n);
	}

	// ��������
	for (int i = n - 1; i > 0; i--) {
		// �����Ѷ�Ԫ�ص���󣬼����źñ��ε����ֵ
		std::swap(arr[0], arr[i]);
		// ������
		HeapAdjust(arr, 0, i);
	}
}


// �������򣨷��ε�˼�룬�������С���⣩
// ˼�룺
// 1. ѡȡ��׼����������ѡ��һ��Ԫ����Ϊ��׼����һ��Ϊ����Ԫ�� / ����Ԫ�� / ���Ԫ�أ�
// 2. �������������Ϊ�����֣���߲���С�ڵ��ڻ�׼���ұ߲��ִ��ڻ�׼��
// ����������������˫ָ�룬һ��ָ�루1��ʼ��ָ�� <= ��׼��������ұ߽磬��һ��ָ�루2���������顿
// 3. �ݹ����򣺶����������ֵݹ���ÿ�������


// ��������
int partition(int* arr, int low, int high) // [low, hight]��Ҫ�ֵ�����
{
	int pivot = arr[high]; // ѡȡ���һ��Ԫ����Ϊ��׼
	int i = low - 1; // i �ǣ�������� �ұ߽�(��ʼʱ��������Ϊ ��)

	for (int j = low; j < high; j++) // ѭ���ﲻ�����׼
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]); // �� <= pivot ��Ԫ�ػ���������
		}
	}
	swap(arr[i + 1], arr[high]); // ���û�׼��λ�ã���׼��λ��������ӳ�����ֺõ����������λ�ã�
	return i + 1; // ���ػ�׼���±�

}

// ��������
void QuickSort(int* arr, int low, int high)
{
	if (low < high) // ���䲻Ϊ��
	{
		int pi = partition(arr, low, high);
		QuickSort(arr, low, pi - 1); // �������ٻ���
		QuickSort(arr, pi + 1, high); // �������ٻ���
	}
}