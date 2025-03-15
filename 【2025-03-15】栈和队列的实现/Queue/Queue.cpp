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
	delete cur; // delete对空指针释放也是安全操纵，遇到空指针会直接返回
	_front = nullptr;
	_rear = nullptr;
	std::cout << "销毁成功" << std::endl;
}
QNode* Queue::GetQNode(QDataType data)
{
	QNode* newnode = new QNode;
	newnode->_data = data;
	newnode->_next = nullptr;
	return newnode;
}

// 队尾入队列 
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

// 队头出队列 
void Queue::QueuePop() {
	if (QueueEmpty()) {
		std::cout << "队列为空" << std::endl;
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
// 获取队列头部元素 
QDataType Queue::QueueFront() {
	if (QueueEmpty()) {
		std::cout << "队列为空" << std::endl;
		return  -1;
	}
	return _front->_data;
}
// 获取队列队尾元素 
QDataType Queue::QueueBack() {
	if (QueueEmpty()) {
		std::cout << "队列为空" << std::endl;
		return  -1;
	}
	return _rear->_data;
}
// 获取队列中有效元素个数 
int Queue::QueueSize() {
	return _size;
}

// 检测队列是否为空
bool Queue::QueueEmpty() {
	return _front == nullptr && _rear == nullptr;
}
