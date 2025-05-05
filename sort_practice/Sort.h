#pragma once
#include<iostream>
using namespace std;
// 插入排序
// 思路：把数组分成已排序和待排序，依次把待排序中的元素插入到已排序的合适的位置
// 时间复杂度：O(n^2), 空间复杂度O(1)，稳定

void InsertSort(int* arr, int n)
{
	for (int i = 1; i < n; i++) // 待排序元素从第二个元素开始
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

// 希尔排序（改良版的插入排序）
// 思路：
// 1. 选择增量序列：首先需要选择一个增量序列 h，常见的有（h = n / 2, n / 4, ..., 1）,也就是每个数字间隔 h 为一组。
// 2. 按增量进行分组插入排序：对于每个增量 h，将数组分成 h 个组，对每个组内的元素进行插入排序。
// 3. 缩小增量：逐渐减小增量 h 的值，重复步骤 2，直到 h 减至 1。减到 1 时就代表排序好了
// 时间复杂度：O(n^2), 空间复杂度O(1)，不稳定【因为相同元素可能被分到不同的组】

void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;
		// 针对特定的gap，进行单次插入排序
		for (int i = gap; i < n; i++) // i 是下一个待排序的
		{
			int tmp = arr[i], j = i - gap; // arr[j] 待排序的前一个
			while (j >= 0 && arr[j] > tmp)
			{
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = tmp;
		}
	}
}

// 选择排序
// 思路：每次从待排序列中选出一个最小值，添加到已排序序列的末尾，直到全部待排数据排完即可。
// 时间复杂度：O(n^2)，空间复杂度：O(1)，不稳定【因为元素交换位置的时候，可能会交换相同元素的相对位置】
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

// 冒泡排序
// 思路：遍历 n - 1次数组，每次遍历的时候，比较相邻的两个元素，如果arr[i] > arr[i + 1]，则交换位置
// 每轮都可以把最大的元素交换到最后
// 时间复杂度：O(n^2)，空间复杂度：O(1)，稳定

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


// 堆排序
// 思路：利用 堆（大根堆：孩子都 <= 父亲）
// 每次把堆顶元素换到最后，然后调整堆（此时的堆就不包含最后一个元素了），这时候就把最大值排好了
// 时间复杂度：O(nlogn)，空间复杂度：O(1)，不稳定【因为和堆顶元素交换的时候可能改变相对位置】

void HeapAdjust(int* arr, int start, int end) // 向下调整代码
{
	int child = 2 * start + 1; // 默认和左孩子比较
	while (child < end)
	{
		if (child + 1 < end && arr[child] < arr[child + 1]) // 找左右孩子里面 最大 的那一个
		{
			child++;
		}
		if (arr[start] >= arr[child]) // 已经调整好了，无需再调整
			break;
		swap(arr[child], arr[start]);
		start = child;
		child = start * 2 + 1;
	}
}

// 堆排序
void HeapSort(int* arr, int n) 
{
	// 构建大根堆
	for (int i = (n - 2) / 2; i >= 0; i--)  // n - 1 是最后一个节点，((n - 1) - 1 / 2)，得到父亲节点（因为叶子节点不用调整）
	{
		HeapAdjust(arr, i, n);
	}

	// 进行排序
	for (int i = n - 1; i > 0; i--) {
		// 交换堆顶元素到最后，即：排好本次的最大值
		std::swap(arr[0], arr[i]);
		// 调整堆
		HeapAdjust(arr, 0, i);
	}
}


// 快速排序（分治的思想，大问题变小问题）
// 思想：
// 1. 选取基准：从数组中选择一个元素作为基准。（一般为最左元素 / 最右元素 / 随机元素）
// 2. 分区：将数组分为两部分，左边部分小于等于基准，右边部分大于基准。
// 【分区操作可以用双指针，一个指针（1）始终指向 <= 基准的区域的右边界，另一个指针（2）遍历数组】
// 3. 递归排序：对左右两部分递归调用快速排序。


// 分区函数
int partition(int* arr, int low, int high) // [low, hight]是要分的区间
{
	int pivot = arr[high]; // 选取最后一个元素作为基准
	int i = low - 1; // i 是：左区间的 右边界(初始时，左区间为 空)

	for (int j = low; j < high; j++) // 循环里不处理基准
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]); // 把 <= pivot 的元素换到左区间
		}
	}
	swap(arr[i + 1], arr[high]); // 放置基准的位置（基准的位置用来反映：划分好的左右区间的位置）
	return i + 1; // 返回基准的下标

}

// 快速排序
void QuickSort(int* arr, int low, int high)
{
	if (low < high) // 区间不为空
	{
		int pi = partition(arr, low, high);
		QuickSort(arr, low, pi - 1); // 左区间再划分
		QuickSort(arr, pi + 1, high); // 右区间再划分
	}
}