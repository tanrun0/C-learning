#pragma once
#include<iostream>

// ������ʵ�ֶ���
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

	// ������QNode��
	QNode* GetQNode(QDataType data);
	// ��β����� 
	void QueuePush(QDataType data);
	// ��ͷ������ 
	void QueuePop();
	// ��ȡ����ͷ��Ԫ�� 
	QDataType QueueFront();
	// ��ȡ���ж�βԪ�� 
	QDataType QueueBack();
	// ��ȡ��������ЧԪ�ظ��� 
	int QueueSize();
	// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
	bool QueueEmpty();

private:

	QNode* _front;
	QNode* _rear;
	int _size;
};