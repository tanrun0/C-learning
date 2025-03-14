#pragma once
#include<iostream>
using namespace std;
typedef int LTDataType;

// 链表节点
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev; // 前指针
	struct ListNode* next; // 后指针
}LTNode;

// 带头结点的双向循环链表
class BLL {
public:
	BLL();
	~BLL();
	LTNode* GETNode(LTDataType x);

	bool LTEmpty();

	void LTPrint();

	void LTPushBack(LTDataType x);

	void LTPopBack();

	void LTPushFront(LTDataType x);

	void LTPopFront();

	// 在pos位置之后插入数据（默认pos一定在链表中）
	void LTInsert(LTNode* pos, LTDataType x);

	// 删除pos节点
	void LTErase(LTNode* pos);

	LTNode* LTFind(LTDataType x);
private:
	LTNode* phead;
};



