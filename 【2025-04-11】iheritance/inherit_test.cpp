#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 普通使用
//class Person
//{
//public:
//	string name;
//	int age;
//	char sex;
//};
//
//class Student : public Person
//{
//public:
//	int st_number;
//};
//
//int main()
//{
//	Student st1;
//	st1.sex = 'b';
//	st1.st_number = 23;
//	return 0;
//}




// 继承类模板

//namespace tr
//{
//	template<class T>
//	class stack: public vector<T>
//	{
//	public:
//		void push(T x)
//		{
//			vector<T>::push_back(x);
//		}
//	};
//}
//
//int main()
//{
//	tr::stack<int> st;
//	st.push(3);
//	return 0;
//}


//// 基类和派生类的转换关系
//class Person 
//{
//public:
//	Person(int a)
//		:name("小红")
//		,age(a)
//	{}
//
//	Person(const Person& p)
//	{
//		name = p.name;
//		age = p.age;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		if (this != &p)
//		{
//			name = p.name;
//			age = p.age;
//		}
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//	string name;
//	int age;
//};
//
//class Student : public Person
//{
//public:
//	Student(int number, int a)
//		:Person(a) // 在初始化列表显示调用父类的默认构造
//	{
//		cout << "Student(int number, int a)" << endl;
//		st_number = number;
//	}
//
//	// 拷贝构造错误写法：
//	/*
//	Student(const Student& s)
//	{
//		Person(s);
//		st_number = s.st_number;
//		cout << "Student(const Student& s)" << endl;
//
//	}
//	*/
//
//	// 正确写法：
//	Student(const Student& s)
//		: Person(s)
//	{
//		st_number = s.st_number;
//		cout << "Student(const Student& s)" << endl;
//
//	}
//
//	Student& operator=(const Student& s)
//	{
//		cout << "Student& operator=(const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator=(s); // 显式调用父类的=重载来初始化父类的成员
//			st_number = s.st_number;
//		}
//		return *this;
//	}
//
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//	int st_number;
//};
//
//int main()
//{
//	Student st1(23, 18);
//	Student st2(st1);
//	Student st3(25, 35);
//	st1 = st3;
//	return 0;
//}
//
//
//
//class Base1 { public: int _b1; };
//class Base2 { public: int _b2; };
//class Derive : public Base1, public Base2 { public: int _d; };
//int main()
//{
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	return 0;
//}



// 菱形继承与虚拟继承
class Person
{
public:
	string _name; // 姓名
	// 使用虚继承Person类
};
class Student : virtual public Person
{
protected:
	int _num; //学号
};
// 使用虚继承Person类
class Teacher : virtual public Person
{
protected:
	int _id; // 职工编号
};

// 教授助理
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // 主修课程
};

int main()
{
	// 使用虚继承，可以解决数据冗余和二义性
	Assistant a;
	a._name = "tr";
	return 0;
};