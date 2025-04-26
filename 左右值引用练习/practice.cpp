#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"string.h"
using namespace std;

// 延长生命周期
//int main()
//{
//
//
//	double x = 1.1, y = 2.2;
//	// double& r1 = x + y; 报错：无法从“double”转换为“double &
//	const double& rr2 = x + y;
//	double&& rr3 = x + y;
//	rr3++; // 并且非 const 的右值引用可以修改
//
//	return 0;
//
//}


// 引用类型不同，导致函数参数类型不同
// 重载以后的，参数匹配问题

//void f(int& x)
//{
//	cout << "左值引用重载 f(" << x << ")\n";
//}
//void f(const int& x)
//{
//	cout << "到 const 的左值引用重载 f(" << x << ")\n";
//}
//void f(int&& x)
//{
//	cout << "右值引用重载 f(" << x << ")\n";
//}
//
//int main()
//{
//	int i = 1;
//	const int ci = 2;
//	f(i); // 调用 f(int&)
//	f(ci); // 调用 f(const int&)
//	f(3); // 调用 f(int&&)，如果没有 f(int&&) 重载，则会调用 f(const int&)
//	f(std::move(i)); // 调用 f(int&&)
//	// 右值引用变量在用于表达式时是左值
//	int&& x = 1;
//	f(x); // 调用 f(int& x)
//	f(std::move(x)); // 调用 f(int&& x)
//	return 0;
//}


// 无法延长局部变量生命周期

//const tr::string& addStrings(tr::string num1, tr::string num2) {
//	tr::string str;
//	int end1 = num1.size() - 1, end2 = num2.size() - 1;
//	// 进位
//	int next = 0;
//	while (end1 >= 0 || end2 >= 0)
//	{
//		int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
//		int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
//		int ret = val1 + val2 + next;
//		next = ret / 10;
//		ret = ret % 10;
//		str += ('0' + ret);
//	}
//	if (next == 1)
//		str += '1';
//	reverse(str.begin(), str.end());
//	return str;
//}

//// 输出型参数
//void addStrings(tr::string num1, tr::string num2, tr::string& num3) {
//	int end1 = num1.size() - 1, end2 = num2.size() - 1;
//	// 进位
//	int next = 0;
//	while (end1 >= 0 || end2 >= 0)
//	{
//		int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
//		int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
//		int ret = val1 + val2 + next;
//		next = ret / 10;
//		ret = ret % 10;
//		num3 += ('0' + ret);
//	}
//	if (next == 1)
//		num3 += '1';
//	reverse(num3.begin(), num3.end());
//}


//tr::string addStrings(tr::string num1, tr::string num2) {
//	tr::string str;
//	int end1 = num1.size() - 1, end2 = num2.size() - 1;
//	// 进位
//	int next = 0;
//	while (end1 >= 0 || end2 >= 0)
//	{
//		int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
//		int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
//		int ret = val1 + val2 + next;
//		next = ret / 10;
//		ret = ret % 10;
//		str += ('0' + ret);
//	}
//	if (next == 1)
//		str += '1';
//	reverse(str.begin(), str.end());
//	return str;
//}
//
//
//int main()
//{
//	tr::string num3;
//	num3 = addStrings({ "1111111111" }, { "2222222222" });
//	cout << num3.c_str() << endl;
//	return 0;
//}




//// 由于引用折叠，且T& 是左值引用，所以：f1实例化以后总是左值引用
//template<class T>
//void f1(T& x)
//{}
//
//// 由于引用折叠限定，且T&& 是右值引用，则f2实例化后可以是左值引，也可以是右值引用
//template<class T>
//void f2(T&& x)
//{
//}
//
//int main()
//{
//	typedef int& lref;
//	typedef int&& rref;
//	int n = 0;
//	lref& r1 = n; // r1 的类型是 int&
//	lref&& r2 = n; // r2 的类型是 int&
//	rref& r3 = n; // r3 的类型是 int&
//	rref&& r4 = 1; // r4 的类型是 int&&
//
//
//
//	// 没有折叠->实例化为void f1(int& x)
//	f1<int>(n);
//	f1<int>(0); // 报错
//	// 折叠->实例化为void f1(int& x)
//	f1<int&>(n);
//	f1<int&>(0); // 报错
//	// 折叠->实例化为void f1(int& x)
//	f1<int&&>(n);
//	f1<int&&>(0); // 报错
//	// 折叠->实例化为void f1(const int& x)
//	f1<const int&>(n);
//	f1<const int&>(0);
//	// 折叠->实例化为void f1(const int& x)
//	f1<const int&&>(n);
//	f1<const int&&>(0);
//
//	// 没有折叠->实例化为void f2(int&& x)
//	f2<int>(n); // 报错
//	f2<int>(0);
//	// 折叠->实例化为void f2(int& x)
//	f2<int&>(n);
//	f2<int&>(0); // 报错
//	// 折叠->实例化为void f2(int&& x)
//	f2<int&&>(n); // 报错
//	f2<int&&>(0);
//	return 0;
//}

template<class T>
void Function(T && t)
{
	int a = 0;
	T x = a;
	//x++;
	cout << &a << endl;
	cout << &x << endl << endl;
}
int main()
{
	// 10是右值，推导出T为int，模板实例化为void Function(int&& t)
	Function(10); // 右值
	int a;
	// a是左值，推导出T为int&，引用折叠，模板实例化为void Function(int& t)
	Function(a); // 左值
	// std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
	Function(std::move(a)); // 右值
	const int b = 8;
	// a是左值，推导出T为const int&，引⽤折叠，模板实例化为void Function(const int&t)
	// 所以Function内部会编译报错，x不能++
	Function(b); // const 左值
	// std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&&
	// 所以Function内部会编译报错，x不能++
	Function(std::move(b)); // const 右值
	return 0;
}

// 完美转发
template<class T>
void Function(T&& t)
{
	Fun(forward<T>(t));
}