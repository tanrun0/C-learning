#include <iostream>

using namespace std;

//int main()
//{
//	// C 语言类型转换
//	int a = 1;
//	double b = 2.1;
//	// cout << a + b << endl;
//
//	int* ptr1 = &a;
//	int c = (int)ptr1;
//	cout << c << endl; // 输出：514849252
//	return 0;
//}


//class Add
//{
//public:
//
//	explicit Add(int a)
//		:_a(a)
//	{ }
//	
//	Add(int a, int b)
//		:_a(a),
//		_b(b)
//	{ }
//
//	void Print()
//	{
//		cout << _a + _b << endl;
//	}
//private:
//	int _a = 1;
//	int _b = 1;
//};
//
//
//int main()
//{
//	Add add1 = 2;
//	Add add2 = { 2,2 };
//	add1.Print(); // 输出 3
//	add2.Print(); // 输出 4
//	return 0;
//}


//class A
//{
//public:
//
//	A(double a)
//		:_a(a)
//	{}
//
//	A(double a, int b)
//		:_a(a),
//		_b(b)
//	{}
//
//	double Geta()
//	{
//		return _a;
//	}
//
//private:
//	double _a = 1;
//	int _b = 1;
//};
//
//class B
//{
//public:
//	B(A a1)
//		:_a(a1.Geta())
//	{
//	}
//
//	void Print()
//	{
//		cout << _a + _b << endl;
//	}
//private:
//	double _a = 1.1;
//	int _b = 1;
//};
//
//int main()
//{
//	//A a1 = 2.1;
//	//double c = a1;
//	//cout << c << endl; // 输出: 2.1
//
//	A a1 = 3.1;
//	B b1 = a1;
//	b1.Print(); // 输出: 4.1
//	return 0;
//}

#include <typeinfo>

int main() {
    int x = 42;
    // const std::type_info& ti = typeid(x); // typeid 返回的是 const std::type_info&
    std::cout << typeid(x).name() << std::endl;  // 输出: int (不同编译器的输出效果可能不同)
    return 0;
}