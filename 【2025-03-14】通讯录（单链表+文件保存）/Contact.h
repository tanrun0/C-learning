#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include <fstream>
using namespace std;
//ǰ������

//�û�����
typedef struct PersonInfo
{
	string name;
	string age;
	string tele;
	string addr;
	struct PersonInfo* next;  // ���ﲻ����PerInfo* ��Ϊ��δ����
}PerInfo; // �ڵ�


void menu();
class contact 
{
public:
	contact();
	~contact();

	// �½��ڵ�
	PerInfo* GETNode();
	//���ͨѶ¼����
	void AddContact();
	//ɾ��ͨѶ¼����
	void DelContact();
	//չʾͨѶ¼����
	void ShowContact();
	//����ͨѶ¼����
	void FindContact();
	//�޸�ͨѶ¼����
	void ModifyContact();
	// �����ļ�����
	void ContactLoad();
	// ����ͨѶ¼����
	void ContactSave();
	//����ͨѶ¼����
	void DestroyContact();

private:
	PerInfo* head;  // �������ͷָ��
};