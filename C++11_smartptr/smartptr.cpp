// ����ָ����ϰ
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
//	// unique_ptr<Date> up1(new Date[5]); ����
//
//	// ����º���ɾ����
//	// shared_ptr<Date> up1(new Date[5], Del());
//	// ʹ��lambda
//	// shared_ptr<Date> up1(new Date[5], [](Date* ptr) {delete[] ptr; });
//
//	// ģ���������º�����Ϊɾ����
//	unique_ptr<Date, Del> up1(new Date[5]);
//	return 0;
//}


//int main()
//{
//	shared_ptr<Date> sp1(new Date);
//	//shared_ptr<Date> sp2(sp1); // �� sp1 �������� sp2
//	//shared_ptr<Date> sp3 = sp2;
//	//// ������������ͬһ��ռ�
//	shared_ptr<Date> sp2 = make_shared<Date>(2025, 5, 2); // �ó�ʼ�������ֱֵ�ӹ���
//
//	if (sp2) // ʵ������ if(sp2.operator bool())
//	{
//		cout << "p2��Ϊ��" << endl;
//	}
//	return 0;
//}

//// �����Լ�ģ��ʵ�ֵ�unique_ptr
//int main()
//{
//	tr::unique_ptr<Date> up1(new Date);
//	// tr::unique_ptr<Date> up2(up1); // ��֧�ֿ�������
//	tr::unique_ptr<Date> up3(move(up1)); // �ƶ����죬����up1��������
//	return 0;
//}

//// ����shared_ptr
//int main()
//{
//
//	// ����
//	tr::shared_ptr<Date> sp1(new Date);
//	// ��������
//	tr::shared_ptr<Date> sp2(sp1);
//	cout << sp2.use_count() << endl;
//
//	tr::shared_ptr<Date> sp3(new Date);
//	cout << sp3.use_count() << endl;
//	// ������ֵ
//	sp3 = sp1;
//	cout << sp1.use_count() << endl;
//
//	cout << "------------------------------------------------------------" << endl;
//
//	// �ƶ�����
//	tr::shared_ptr<Date> sp4(move(sp1));
//	cout << sp4.use_count() << endl;
//	cout << sp1.use_count() << endl; // sp1�Ѿ������ˣ���Ӧ�ü���ʹ��sp1���������0����Ϊ��use_count �������жϣ�
//
//	// �ƶ���ֵ
//	sp4 = move(sp2);
//	cout << sp4.use_count() << endl; // sp2Ҳ�����ˣ����ٹ���Date��Դ
//
//	cout << "------------------------------------------------------------" << endl;
//
//	tr::shared_ptr<Date> sp5(new Date[5], [](Date* ptr) {delete[] ptr; });
//	cout << sp5.use_count() << endl;
//	return 0;
//}


// ʹ��weak_ptr
int main()
{
	shared_ptr<string> sp1(new string("111111"));
	shared_ptr<string> sp2(sp1);
	weak_ptr<string> wp = sp1;

	cout << wp.expired() << endl;
	cout << wp.use_count() << endl;

	// sp1��sp2��ָ����������Դ����weak_ptr�͹�����
	sp1 = make_shared<string>("222222");
	cout << wp.expired() << endl;
	cout << wp.use_count() << endl;
	sp2 = make_shared<string>("333333");
	cout << wp.expired() << endl;
	cout << wp.use_count() << endl;
	cout << "-------------------------------------------------" << endl;
	wp = sp1; // ���°�
	//shared_ptr<string> sp3 = wp.lock(); 
	cout << wp.use_count() << endl;
	auto sp3 = wp.lock(); // ����weak_ptr�Լ�����һ��shared_ptr

	cout << wp.expired() << endl;
	cout << wp.use_count() << endl;
	*sp3 += "###";
	cout << *sp1 << endl;
	return 0;
}