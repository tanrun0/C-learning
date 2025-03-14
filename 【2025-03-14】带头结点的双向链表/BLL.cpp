#include"BLL.h"
BLL::BLL()
	:phead(new LTNode)
{
	phead->prev = phead; // phead->prev 是尾节点
	phead->next = phead; // phead->next 是第一个有数据的首节点
}
BLL::~BLL() {
	ListNode* cur = phead->next;
	while (cur != phead) {
		ListNode* nxt = cur->next; // 记录下一个节点
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
		cout << "链表为空" << endl;
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
	// 先设置新节点的，再修改原来的
	newnode->prev = phead->prev;
	newnode->next = phead;
	newnode->prev->next = newnode;
	phead->prev = newnode;
}

void BLL::LTPopBack() {
	if (LTEmpty()) {
		cout << "链表为空" << endl;
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
		cout << "链表为空" << endl;
		return;
	}
	ListNode* front = phead->next;
	phead->next = front->next;
	front->next->prev = phead;
	delete front;
}

// 在pos位置之后插入数据（默认pos一定在链表中）
void BLL::LTInsert(LTNode* pos, LTDataType x) {
	if (pos == nullptr) { return; }
	LTNode* newnode = GETNode(x);
	newnode->prev = pos;
	newnode->next = pos->next;
	newnode->next->prev = newnode;
	pos->next = newnode;
}

// 删除pos节点
void BLL::LTErase(LTNode* pos) {
	LTNode* pre = pos->prev;
	pre->next = pos->next;
	pre->next->prev = pre;
	delete pos;
}

LTNode* BLL::LTFind(LTDataType x) {
	if (LTEmpty()) {
		cout << "链表为空" << endl;
		return nullptr;
	}
	LTNode* cur = phead->next;
	while (cur != phead) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	cout << "没找到" << endl;
	return nullptr;
}