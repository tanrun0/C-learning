#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include <fstream>
using namespace std;
//前置声明

//用户数据
typedef struct PersonInfo
{
	string name;
	string age;
	string tele;
	string addr;
	struct PersonInfo* next;  // 这里不能用PerInfo* 因为还未定义
}PerInfo; // 节点


void menu();
class contact 
{
public:
	contact();
	~contact();

	// 新建节点
	PerInfo* GETNode();
	//添加通讯录数据
	void AddContact();
	//删除通讯录数据
	void DelContact();
	//展示通讯录数据
	void ShowContact();
	//查找通讯录数据
	void FindContact();
	//修改通讯录数据
	void ModifyContact();
	// 加载文件数据
	void ContactLoad();
	// 保存通讯录数据
	void ContactSave();
	//销毁通讯录数据
	void DestroyContact();

private:
	PerInfo* head;  // 单链表的头指针
};