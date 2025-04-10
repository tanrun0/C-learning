#pragma once
#pragma once
#include<iostream>
#include<vector>
using namespace std;

// �ǲ�������ģ��
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
//		T _array[N]; // ��ģ��������βεĴ�С����ʼ���ײ������С
//		size_t _size;
//	};
//
//}


// ����ģ���ػ�
//// ͨ��ģ�庯��
//template <typename T>
//T add(T a, T b) {
//	return a + b;
//}

//// ��ȷ����� int ���͵��ػ��汾
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

// ��ģ���ػ�

// ��ͨģ�壨ͨ��ģ�壩
//template<class T1, class T2>
//class Print
//{
//public:
//	Print() { cout << "Print<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};

//// ȫ�ػ�
//template<>
//class Print<int, double>
//{
//public:
//	Print() { cout << "Print<int, double>" << endl; } // ��Ĭ�Ϲ����ʼ����ʱ��˳���ӡ
//private:
//	int _d1;
//	double _d2;
//};


//// ��ģ��ƫ�ػ�����������ȷ����
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
//	Print() { cout << "Print<int, T2>" << endl; } // ��Ĭ�Ϲ����ʼ����ʱ��˳���ӡ
//private:
//	int _d1;
//	double _d2;
//};
//
//template<class T1>
//class Print<T1, double>
//{
//public:
//	Print() { cout << "Print<T1, double>" << endl; } // ��Ĭ�Ϲ����ʼ����ʱ��˳���ӡ
//private:
//	int _d1;
//	double _d2;
//};

// ��������һ������
template<class T1, class T2>
class Print
{
public:
	Print() { cout << "Print<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

// ����ƫ�ػ���ָ������
template<class T1, class T2>
class Print<T1*, T2*>
{
public:
	Print() { cout << "Print<T1*, T2*>" << endl; }
private:
	T1 _d1; // ������T1����T1*��������ͨ��T1���ͣ��������Ǽ�����ʹ��T1���ֿ���ʹ��T1*
	T2 _d2;
};

// ����ƫ�ػ�����������
template<class T1, class T2>
class Print<T1&, T2&>
{
public:
	Print() { cout << "Print<T1&, T2&>" << endl; }
private:
	T1 _d1; // ������T1����T1*��������ͨ��T1���ͣ��������Ǽ�����ʹ��T1���ֿ���ʹ��T1*
	T2 _d2;
};
