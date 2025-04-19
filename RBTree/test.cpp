#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#include"RBTree.h"

void TestRBTree1()
{
	RBTree<int, int> t;
	// 常规的测试用例
	// int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	// 特殊的带有双旋场景的测试用例
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

	for (auto e : a)
	{
		t.Insert({ e, e });
	}

	t.InOrder();
	if (t.IsBalance())
	{
		cout << "是平衡树" << endl;
	}
	else
	{
		cout << "不是平衡树" << endl;
	}
}

int main()
{
	TestRBTree1();

	return 0;
}