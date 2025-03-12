#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<iomanip> // 这个是控制格式化输出的
#include<string>
#include <assert.h>
using namespace std;

void menu();
// 定义个人信息
class PerInfo 
{
	PerInfo();
	friend class Contact;
	string _name;
	string _age;
	string _sex;
	string _tele;
	string _addr;
};

class Contact
{
public:
	Contact(int capacity = 10);
	~Contact();
	// 扩容
	void EXPContact();

	// 添加联系人
	void ADDContact();

	// 删除指定姓名的联系人
	void DELContact();

	// 展示通讯录
	void SHOWContact();

	// 查找联系人
	void SEARCHContact();

	int FINDPerIndex(const string& name);

	// 修改联系人信息
	void MODIFYContact();

	// 排序联系人的信息-按名字
	void SORTContact();


private:
	PerInfo* _arry;
	int _size;
	int _capacity;
};