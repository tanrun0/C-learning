#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
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


template <class T>
const T& GetArg(const T& x) {
    cout << x << " ";  // 打印参数
    return x;          // 返回原参数（保证类型不变）
}

template <class ...Args>
void Arguments(Args... args) {}  // 空函数，仅用于接收展开后的参数包

template <class ...Args>
void Print(Args... args) {
    Arguments(GetArg(args)...);  // 关键：展开参数包并调用 GetArg 处理每个参数
}
int main()
{
    Print(1, 2.2, 3.3, "hello world");
    return 0;
}