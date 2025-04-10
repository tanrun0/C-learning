#pragma once
#pragma once
#include<iostream>
#include<vector>
using namespace std;

// 非参数类型模板
//namespace tr
//{
//
//	template<class T, size_t N = 10>
//	class array
//	{
//	public:
//		array(){}
//		T& operator[](size_t index) { return _array[index]; }
//		const T& operator[](size_t index) const { return _array[index]; }
//		size_t size() { return _size; }
//		bool empty() { return _size == 0; }
//
//	private:
//		T _array[N]; // 由模板非类型形参的大小来初始化底层数组大小
//		size_t _size;
//	};
//
//}


// 函数模板特化
//// 通用模板函数
//template <typename T>
//T add(T a, T b) {
//	return a + b;
//}

//// 正确的针对 int 类型的特化版本
//template <>
//int add<int>(int a, int b) {
//	std::cout << "<int, int>" << std::endl;
//	return a + b;
//}

//int add(int a, int b)
//{
//	cout << "<int, int>" << endl;
//	return a + b;
//}

// 类模板特化

// 普通模板（通用模板）
//template<class T1, class T2>
//class Print
//{
//public:
//	Print() { cout << "Print<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};

//// 全特化
//template<>
//class Print<int, double>
//{
//public:
//	Print() { cout << "Print<int, double>" << endl; } // 调默认构造初始化的时候顺便打印
//private:
//	int _d1;
//	double _d2;
//};


//// 类模板偏特化（参数部分确定）
//template<class T1, class T2>
//class Print
//{
//public:
//	Print() { cout << "Print<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};

//template<class T2>
//class Print<int, T2>
//{
//public:
//	Print() { cout << "Print<int, T2>" << endl; } // 调默认构造初始化的时候顺便打印
//private:
//	int _d1;
//	double _d2;
//};
//
//template<class T1>
//class Print<T1, double>
//{
//public:
//	Print() { cout << "Print<T1, double>" << endl; } // 调默认构造初始化的时候顺便打印
//private:
//	int _d1;
//	double _d2;
//};

// 参数更进一步限制
template<class T1, class T2>
class Print
{
public:
	Print() { cout << "Print<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// 参数偏特化成指针类型
template<class T1, class T2>
class Print<T1*, T2*>
{
public:
	Print() { cout << "Print<T1*, T2*>" << endl; }
private:
	T1 _d1; // 在这里T1不是T1*，就是普通的T1类型，这样我们即可以使用T1，又可以使用T1*
	T2 _d2;
};

// 参数偏特化成引用类型
template<class T1, class T2>
class Print<T1&, T2&>
{
public:
	Print() { cout << "Print<T1&, T2&>" << endl; }
private:
	T1 _d1; // 在这里T1不是T1*，就是普通的T1类型，这样我们即可以使用T1，又可以使用T1*
	T2 _d2;
};
