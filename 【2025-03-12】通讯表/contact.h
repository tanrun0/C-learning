#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<iomanip> // ����ǿ��Ƹ�ʽ�������
#include<string>
#include <assert.h>
using namespace std;

void menu();
// ���������Ϣ
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
	// ����
	void EXPContact();

	// �����ϵ��
	void ADDContact();

	// ɾ��ָ����������ϵ��
	void DELContact();

	// չʾͨѶ¼
	void SHOWContact();

	// ������ϵ��
	void SEARCHContact();

	int FINDPerIndex(const string& name);

	// �޸���ϵ����Ϣ
	void MODIFYContact();

	// ������ϵ�˵���Ϣ-������
	void SORTContact();


private:
	PerInfo* _arry;
	int _size;
	int _capacity;
};