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
//		cout << "汪汪" << endl;
//	}
//	int age = 10;
//};
//
//class Cat: public Animal
//{
//public:
//	virtual void yell() override
//	{
//		cout << "喵喵" << endl;
//	}
//};
//
//void Func(Animal* ptr) // 接收一个基类的指针
//{
//	ptr->yell(); // 必须是基类的指针 调用虚函数yell
//}
//int main()
//{
//	Animal animal; 
//	Dog dog;
//	Cat cat;
//	
//	//// 传入三个不同类的指针
//	Func(&animal);
//	Func(&dog); // 子类指针传递给基类指针，“向上传型”（切片）
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



//class Animal // 抽象类
//{
//public:
//	virtual void yell() = 0; // 纯虚函数
//};
//	
//class Dog: public Animal
//{
//public:
//	virtual void yell()
//	{
//		cout << "汪汪" << endl;
//	}
//};
//	
//int main()
//{
//	// Animal animal; // 报错：“Animal”: 无法实例化抽象类
//	Dog dog;
//	dog.yell();
//	return 0;
//}


// 虚函数表

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
//	virtual void yell() {cout << "汪汪" << endl;}
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
