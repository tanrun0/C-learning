#include"BLL.h"
BLL::BLL()
	:phead(new LTNode)
{
	phead->prev = phead; // phead->prev ��β�ڵ�
	phead->next = phead; // phead->next �ǵ�һ�������ݵ��׽ڵ�
}
BLL::~BLL() {
	ListNode* cur = phead->next;
	while (cur != phead) {
		ListNode* nxt = cur->next; // ��¼��һ���ڵ�
		delete cur;
		cur = nxt;
	}
	delete phead;
	phead = nullptr;
}
LTNode* BLL::GETNode(LTDataType x) {
	ListNode* newnode = new ListNode;
	newnode->data = x;
	newnode->next = nullptr;
	newnode->prev = nullptr;
	return newnode;
}

bool BLL::LTEmpty() {
	if (phead->next == phead->prev) {
		return true;
	}
	return false;
}

void BLL::LTPrint() {
	if (LTEmpty()) {
		cout << "����Ϊ��" << endl;
		return;
	}
	else {
		ListNode* cur = phead->next;
		while (cur != phead) {
			cout << cur->data << " ";
			cur = cur->next;
		}
	}
}

void BLL::LTPushBack(LTDataType x) {
	ListNode* newnode = GETNode(x);
	// �������½ڵ�ģ����޸�ԭ����
	newnode->prev = phead->prev;
	newnode->next = phead;
	newnode->prev->next = newnode;
	phead->prev = newnode;
}

void BLL::LTPopBack() {
	if (LTEmpty()) {
		cout << "����Ϊ��" << endl;
		return;
	}
	ListNode* back = phead->prev;
	back->prev->next = phead;
	phead->prev = back->prev;
	delete back;
}

void BLL::LTPushFront(LTDataType x) {
	ListNode* newnode = GETNode(x);
	newnode->prev = phead;
	newnode->next = phead->next;
	newnode->next->prev = newnode;
	phead->next = newnode;
}

void BLL::LTPopFront() {
	if (LTEmpty()) {
		cout << "����Ϊ��" << endl;
		return;
	}
	ListNode* front = phead->next;
	phead->next = front->next;
	front->next->prev = phead;
	delete front;
}

// ��posλ��֮��������ݣ�Ĭ��posһ���������У�
void BLL::LTInsert(LTNode* pos, LTDataType x) {
	if (pos == nullptr) { return; }
	LTNode* newnode = GETNode(x);
	newnode->prev = pos;
	newnode->next = pos->next;
	newnode->next->prev = newnode;
	pos->next = newnode;
}

// ɾ��pos�ڵ�
void BLL::LTErase(LTNode* pos) {
	LTNode* pre = pos->prev;
	pre->next = pos->next;
	pre->next->prev = pre;
	delete pos;
}

LTNode* BLL::LTFind(LTDataType x) {
	if (LTEmpty()) {
		cout << "����Ϊ��" << endl;
		return nullptr;
	}
	LTNode* cur = phead->next;
	while (cur != phead) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	cout << "û�ҵ�" << endl;
	return nullptr;
}