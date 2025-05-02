// 智能指针练习
#include<iostream>
#include<string>
#include<memory>
#include"smartptr.h"
using namespace std;

class Date
{
public:
	Date(int year = 1945, int month = 9, int day = 3)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date()" << endl;
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

//class Del
//{
//public:
//	void operator()(Date* ptr)
//	{
//		delete[] ptr;
//	}
//};

//int main()
//{
//	// unique_ptr<Date> up1(new Date[5]); 错误
//
//	// 传入仿函数删除器
//	// shared_ptr<Date> up1(new Date[5], Del());
//	// 使用lambda
//	// shared_ptr<Date> up1(new Date[5], [](Date* ptr) {delete[] ptr; });
//
//	// 模版参数处提仿函数作为删除器
//	unique_ptr<Date, Del> up1(new Date[5]);
//	return 0;
//}


//int main()
//{
//	shared_ptr<Date> sp1(new Date);
//	//shared_ptr<Date> sp2(sp1); // 用 sp1 拷贝构造 sp2
//	//shared_ptr<Date> sp3 = sp2;
//	//// 上面这三管理同一块空间
//	shared_ptr<Date> sp2 = make_shared<Date>(2025, 5, 2); // 用初始化对象的值直接构造
//
//	if (sp2) // 实际上是 if(sp2.operator bool())
//	{
//		cout << "p2不为空" << endl;
//	}
//	return 0;
//}

//// 测试自己模拟实现的unique_ptr
//int main()
//{
//	tr::unique_ptr<Date> up1(new Date);
//	// tr::unique_ptr<Date> up2(up1); // 不支持拷贝构造
//	tr::unique_ptr<Date> up3(move(up1)); // 移动构造，但是up1就悬空了
//	return 0;
//}

//// 测试shared_ptr
//int main()
//{
//
//	// 构造
//	tr::shared_ptr<Date> sp1(new Date);
//	// 拷贝构造
//	tr::shared_ptr<Date> sp2(sp1);
//	cout << sp2.use_count() << endl;
//
//	tr::shared_ptr<Date> sp3(new Date);
//	cout << sp3.use_count() << endl;
//	// 拷贝赋值
//	sp3 = sp1;
//	cout << sp1.use_count() << endl;
//
//	cout << "------------------------------------------------------------" << endl;
//
//	// 移动构造
//	tr::shared_ptr<Date> sp4(move(sp1));
//	cout << sp4.use_count() << endl;
//	cout << sp1.use_count() << endl; // sp1已经悬空了（不应该继续使用sp1，这里输出0是因为在use_count 里面有判断）
//
//	// 移动赋值
//	sp4 = move(sp2);
//	cout << sp4.use_count() << endl; // sp2也悬空了，不再管理Date资源
//
//	cout << "------------------------------------------------------------" << endl;
//
//	tr::shared_ptr<Date> sp5(new Date[5], [](Date* ptr) {delete[] ptr; });
//	cout << sp5.use_count() << endl;
//	return 0;
//}


// 使用weak_ptr
int main()
{
	shared_ptr<string> sp1(new string("111111"));
	shared_ptr<string> sp2(sp1);
	weak_ptr<string> wp = sp1;

	cout << wp.expired() << endl;
	cout << wp.use_count() << endl;

	// sp1和sp2都指向了其他资源，则weak_ptr就过期了
	sp1 = make_shared<string>("222222");
	cout << wp.expired() << endl;
	cout << wp.use_count() << endl;
	sp2 = make_shared<string>("333333");
	cout << wp.expired() << endl;
	cout << wp.use_count() << endl;
	cout << "-------------------------------------------------" << endl;
	wp = sp1; // 重新绑定
	//shared_ptr<string> sp3 = wp.lock(); 
	cout << wp.use_count() << endl;
	auto sp3 = wp.lock(); // 利用weak_ptr自己创建一个shared_ptr

	cout << wp.expired() << endl;
	cout << wp.use_count() << endl;
	*sp3 += "###";
	cout << *sp1 << endl;
	return 0;
}