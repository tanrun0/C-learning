#include"Queue.h"


Queue::Queue() {
	_front = nullptr;
	 _rear = nullptr;
	_size = 0;
}
Queue::~Queue() {
	QNode* cur = _front;
	while (cur != nullptr) {
		QNode* nxt = cur->_next;
		delete cur;
		cur = nxt;
	}
	delete cur; // delete�Կ�ָ���ͷ�Ҳ�ǰ�ȫ���ݣ�������ָ���ֱ�ӷ���
	_front = nullptr;
	_rear = nullptr;
	std::cout << "���ٳɹ�" << std::endl;
}
QNode* Queue::GetQNode(QDataType data)
{
	QNode* newnode = new QNode;
	newnode->_data = data;
	newnode->_next = nullptr;
	return newnode;
}

// ��β����� 
void Queue::QueuePush(QDataType data) {
	QNode* newnode = GetQNode(data);
	if (QueueEmpty()) {
		_front = newnode;
		_rear = newnode;
	}
	else
	{
		_rear->_next = newnode;
		_rear = newnode;
	}
	_size++;
}

// ��ͷ������ 
void Queue::QueuePop() {
	if (QueueEmpty()) {
		std::cout << "����Ϊ��" << std::endl;
		return;
	}
	QNode* tmp = _front;
	_front = _front->_next;
	delete tmp;
	_size--;
	if (_size == 0) {
		_rear = nullptr;
	}

}
// ��ȡ����ͷ��Ԫ�� 
QDataType Queue::QueueFront() {
	if (QueueEmpty()) {
		std::cout << "����Ϊ��" << std::endl;
		return  -1;
	}
	return _front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType Queue::QueueBack() {
	if (QueueEmpty()) {
		std::cout << "����Ϊ��" << std::endl;
		return  -1;
	}
	return _rear->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
int Queue::QueueSize() {
	return _size;
}

// �������Ƿ�Ϊ��
bool Queue::QueueEmpty() {
	return _front == nullptr && _rear == nullptr;
}
