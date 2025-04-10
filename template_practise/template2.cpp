#include"template.h"

// 模板进阶测试
//int main()
//{
//	cout << Add<int, 5>(2) << endl; // 显示指定模板参数
//	cout << Add(2.1) << endl; // 没有显示传递，则有编译器推到：2.1 —— 浮点数，于是 T 就为浮点型，a用缺省值 3
//	return 0;
//
//}

//int main()
//{
//	tr::array<int,5> a1;
//	tr::array<int> a2;
//	return 0;
//}


#include <iostream>

int main()
{
	cout << "这是一个测试" << endl;
	Print<int, int> p1;
	cout << endl;
	Print<int*, int*> p2;
	Print<int&, int&> p3;
	return 0;
}
