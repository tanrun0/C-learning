#include<iostream>
#include<string>
#include<vector>
using namespace std;

// ��ͨʹ��
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




// �̳���ģ��

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


//// ������������ת����ϵ
//class Person 
//{
//public:
//	Person(int a)
//		:name("С��")
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
//		:Person(a) // �ڳ�ʼ���б���ʾ���ø����Ĭ�Ϲ���
//	{
//		cout << "Student(int number, int a)" << endl;
//		st_number = number;
//	}
//
//	// �����������д����
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
//	// ��ȷд����
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
//			Person::operator=(s); // ��ʽ���ø����=��������ʼ������ĳ�Ա
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



// ���μ̳�������̳�
class Person
{
public:
	string _name; // ����
	// ʹ����̳�Person��
};
class Student : virtual public Person
{
protected:
	int _num; //ѧ��
};
// ʹ����̳�Person��
class Teacher : virtual public Person
{
protected:
	int _id; // ְ�����
};

// ��������
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // ���޿γ�
};

int main()
{
	// ʹ����̳У����Խ����������Ͷ�����
	Assistant a;
	a._name = "tr";
	return 0;
};