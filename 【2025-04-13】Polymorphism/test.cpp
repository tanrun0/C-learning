#include<iostream>
using namespace std;
//class Animal
//{
//public:
//	virtual void yell()
//	{
//		cout << "Animal::yell()" << endl;
//	}
//	int num = 20;
//};
//
//class Dog: public Animal
//{
//public:
//	virtual void yell() override
//	{
//		cout << "����" << endl;
//	}
//	int age = 10;
//};
//
//class Cat: public Animal
//{
//public:
//	virtual void yell() override
//	{
//		cout << "����" << endl;
//	}
//};
//
//void Func(Animal* ptr) // ����һ�������ָ��
//{
//	ptr->yell(); // �����ǻ����ָ�� �����麯��yell
//}
//int main()
//{
//	Animal animal; 
//	Dog dog;
//	Cat cat;
//	
//	//// ����������ͬ���ָ��
//	Func(&animal);
//	Func(&dog); // ����ָ�봫�ݸ�����ָ�룬�����ϴ��͡�����Ƭ��
//	Func(&cat);
//	return 0;
//}

//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();
//	return 0;
//}



//class Animal // ������
//{
//public:
//	virtual void yell() = 0; // ���麯��
//};
//	
//class Dog: public Animal
//{
//public:
//	virtual void yell()
//	{
//		cout << "����" << endl;
//	}
//};
//	
//int main()
//{
//	// Animal animal; // ������Animal��: �޷�ʵ����������
//	Dog dog;
//	dog.yell();
//	return 0;
//}


// �麯����

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//protected:
//	int _b = 1;
//	char _ch = 'x';
//};
//int main()
//{
//	Base b;
//	cout << sizeof(&b) << endl;
//	cout << sizeof(b) << endl;
//	return 0;
//}


//class Animal
//{
//public:
//	virtual void yell(){ cout << "Animal::yell()" << endl; }
//
//	// virtual void print(){ cout << "Animal::print()" << endl; }
//
//
//	int a_num = 20;
//};
//
//class Dog: public Animal
//{
//public:
//	virtual void yell() {cout << "����" << endl;}
//
//	virtual void fight() { cout << "Dog::fight()" << endl; }
//
//	virtual void dance() { cout << "Dog::dance()" << endl; }
//
//	int d_num = 10;
//};
//
//int main()
//{
//	Animal a1; 
//	Animal a2;
//	Dog dog;
//	cout << endl;
//	return 0;
//}
