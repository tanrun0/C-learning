#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
// #include"string.h"
using namespace std;


// Print 打印出函数参数包里面的所有参数
// 递归终止函数：当参数列表为空时匹配这个函数
//void ShowList()
//{
//	cout << endl;
//}
//
//// 递归包展开函数
//template<class T, class...Args>
//void ShowList(T x, Args...args)
//{
//	cout << x << " "; // 打印被展开的单个参数
//	ShowList(args...);
//}
//
//template<class...Args>
//void Print(Args... args)
//{
//	ShowList(args...);
//}

//int main()
//{
//	Print(1, string("xxxxx"), 2.2);
//	return 0;
//}

//template<class T1, class T2, class...Args>
//void ShowList(T1 x1, T2 x2, Args...args)
//{
//	cout << x1 << endl;
//	cout << x2 << endl;
//	cout << sizeof...(args) << endl;
//}
//
//int main()
//{
//	ShowList(1, 2.2, 3.3, "hello world");
//	return 0;
//}

////错误示例
//template<class T, class... Args>
//void ShowList(T value, Args... args) {
//    cout << value << " ";
//    if constexpr (sizeof...(args) > 0) {  // 编译时判断
//        ShowList(args...);               // 仅在 args 非空时实例化
//    }
//    // 否则自动终止
//}
//
//int main()
//{
//	ShowList(1, 2.2, 3.3, "hello world");
//	return 0;
//}


//template <class T>
//const T& GetArg(const T& x) {
//    cout << x << " ";  // 打印参数
//    return x;          // 返回原参数（保证类型不变）
//}
//
//template <class ...Args>
//void Arguments(Args... args) {}  // 空函数，仅用于接收展开后的参数包
//
//template <class ...Args>
//void Print(Args... args) {
//    Arguments(GetArg(args)...);  // 关键：展开参数包并调用 GetArg 处理每个参数
//}
//int main()
//{
//    Print(1, 2.2, 3.3, "hello world");
//    return 0;
//}


//int main()
//{
//	tr::string s1 = "hello world";
//	tr::string s3 = tr::string("tr");
//	s1 = move(s1);
//	return 0;
//}

//auto lambda1 = [](int x, int y)->int {return x + y; };
//int main()
//{
//	cout << lambda1(1, 1) << endl; // 输出 2 
//	return 0;
//}



//int x = 0;
//// 捕捉列表必须为空，因为全局变量不用捕捉就可以用，没有可被捕捉的变量
//auto func1 = []() {x++; };
//
//int main()
//{
//	// 只能用当前lambda局部域和捕捉的对象和全局对象
//	int a = 0, b = 1, c = 2, d = 3;
//	auto func1 = [a, &b]
//		{
//			//a++; 值捕捉的变量不能修改（有常性
//			b++; // 引用捕捉的变量可以修改
//			int ret = a + b;
//			return ret;
//		};
//	cout << func1() << endl;
//
//	// 隐式值捕捉
//	// 用了哪些变量就捕捉哪些变量
//	auto func2 = [=]
//		{
//			int ret = a + b + c;
//			return ret;
//		};
//	cout << func2() << endl;
//
//	// 混合捕捉1
//	auto func4 = [&, a, b]
//		{
//			c++;
//			d++;
//			return a + b + c + d;
//		};
//	cout << func4() << endl;
//	cout << a << " " << b << " " << c << " " << d << endl;
//
//	// 局部的静态和全局变量不能捕捉，也不需要捕捉
//	static int m = 0;
//	auto func5 = []
//		{
//			int ret = x + m;
//			return ret;
//		};
//	cout << func5() << endl;
//	// 传值捕捉本质是⼀种拷贝,并且被const修饰了
//	// mutable相当于去掉const属性，可以修改了
//	// 但是修改了不会影响外⾯被捕捉的值，因为是⼀种拷贝
//	auto func6 = [=]()mutable
//		{
//			a++;
//			b++;
//			c++;
//			d++;
//			return a + b + c + d;
//		};
//	cout << func6() << endl;
//	cout << a << " " << b << " " << c << " " << d << endl;
//	return 0;
//}



//#include<functional>
//int f(int a, int b)
//{
//	return a + b;
//}
//struct Functor
//{
//public:
//	int operator() (int a, int b)
//	{
//		return a + b;
//	}
//};
//class Plus
//{
//public:
//	Plus(int n = 10)
//		:_n(n)
//	{
//	}
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)
//	{
//		return (a + b) * _n;
//	}
//private:
//		int _n;
//};
//int main()
//{
//
//	// 包装各种可调用对象
//	function<int(int, int)> f1 = f;
//	function<int(int, int)> f2 = Functor();
//	function<int(int, int)> f3 = [](int a, int b) {return a + b; };
//	cout << f1(1, 1) << endl;
//	cout << f2(1, 1) << endl;
//	cout << f3(1, 1) << endl;
//	// 包装静态成员函数
//	// 成员函数要指定类域并且前面加&才能获取地址
//	function<int(int, int)> f4 = &Plus::plusi;
//	cout << f4(1, 1) << endl;
//	// 包装普通成员函数
//	// 普通成员函数还有一个隐含的this指针参数，所以绑定时传对象或者对象的指针过去都可以
//	function<double(Plus*, double, double)> f5 = &Plus::plusd;
//	Plus pd;
//	cout << f5(&pd, 1.1, 1.1) << endl;
//	function<double(Plus, double, double)> f6 = &Plus::plusd;
//	cout << f6(pd, 1.1, 1.1) << endl;
//	cout << f6(pd, 1.1, 1.1) << endl;
//	function<double(Plus&&, double, double)> f7 = &Plus::plusd;
//	cout << f7(move(pd), 1.1, 1.1) << endl;
//	cout << f7(Plus(), 1.1, 1.1) << endl;
//	return 0;
//}




//#include<functional>
//using placeholders::_1;
//using placeholders::_2;
//using placeholders::_3;
//int Sub(int a, int b)
//{
//	return (a - b) * 10;
//}
//int SubX(int a, int b, int c)
//{
//	return (a - b - c) * 10;
//}
//class Plus
//{
//public:
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)
//	{
//		return a + b;
//	}
//};
//int main()
//{
//	auto sub1 = bind(Sub, _1, _2);
//	cout << sub1(10, 5) << endl;
//
//	// 改变参数位置顺序
//	auto sub2 = bind(Sub, _2, _1);
//	cout << sub2(10, 5) << endl;
//
//	// 调整参数个数（常用）
//	auto sub3 = bind(Sub, 100, _1);
//	cout << sub3(5) << endl;
//	auto sub4 = bind(Sub, _1, 100);
//	cout << sub4(5) << endl;
//
//	// 分别绑死第123个参数
//	auto sub5 = bind(SubX, 100, _1, _2);
//	cout << sub5(5, 1) << endl;
//	auto sub6 = bind(SubX, _2, 100, _1);
//	cout << sub6(5, 1) << endl;
//	auto sub7 = bind(SubX, _1, _2, 100);
//	cout << sub7(5, 1) << endl;
//
//	// 成员函数对象进行绑死，就不需要每次都传递了
//	function<double(double, double)> f7 = bind(&Plus::plusd, Plus(), _1, _2);
//	cout << f7(1.1, 1.1) << endl;
//}



//double Divide(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//int main()
//{
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Divide(len, time) << endl;
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (...)
//	{
//		cout << "Unkown Exception" << endl;
//	}
//	int i = 0;
//	cout << noexcept(Divide(1, 2)) << endl;
//	cout << noexcept(Divide(1, 0)) << endl;
//	cout << noexcept(++i) << endl;
//	return 0;
//}

#include <stdexcept> // 标准异常头文件
#include <vector>

int main() {
    try {
        std::vector<int> v(100000000); // 可能抛出 std::bad_alloc
        throw std::runtime_error("自定义运行时错误");
    }
    catch (const std::exception& e) { // 捕获所有派生自 std::exception 的异常
        std::cerr << "捕获异常: " << e.what() << std::endl;
    }
    return 0;
}