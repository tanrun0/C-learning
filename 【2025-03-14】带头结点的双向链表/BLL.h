#pragma once
#include<iostream>
using namespace std;
typedef int LTDataType;

// ����ڵ�
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev; // ǰָ��
	struct ListNode* next; // ��ָ��
}LTNode;

// ��ͷ����˫��ѭ������
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

	// ��posλ��֮��������ݣ�Ĭ��posһ���������У�
	void LTInsert(LTNode* pos, LTDataType x);

	// ɾ��pos�ڵ�
	void LTErase(LTNode* pos);

	LTNode* LTFind(LTDataType x);
private:
	LTNode* phead;
};



