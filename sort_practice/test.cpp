#include"Sort.h"

int main()
{
	int arr[] = { 2,5,4,9,6,8,7,3,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	// InsertSort(arr, n); // ��������
	// ShellSort(arr, n); // ϣ������
	// SelectSort(arr, n); // ѡ������
	// BulleSort(arr, n); // ð������
	// HeapSort(arr, n); // ������
	QuickSort(arr, 0, n - 1);


	for (auto num : arr)
		cout << num << ' ';
	cout << endl;
}


