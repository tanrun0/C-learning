#pragma once
#include<iostream>

// 用链表实现队列
typedef int QDataType;

typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

class Queue {
public:
	Queue();
	~Queue();

	// 申请新QNode：
	QNode* GetQNode(QDataType data);
	// 队尾入队列 
	void QueuePush(QDataType data);
	// 队头出队列 
	void QueuePop();
	// 获取队列头部元素 
	QDataType QueueFront();
	// 获取队列队尾元素 
	QDataType QueueBack();
	// 获取队列中有效元素个数 
	int QueueSize();
	// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
	bool QueueEmpty();

private:

	QNode* _front;
	QNode* _rear;
	int _size;
};