#pragma once
#include<iostream>

// ֧�ֶ�̬������ջ
typedef int STDataType;

class Stack {
public:
	// ��ʼ��ջ 
	Stack(int c = 10);
	~Stack();
	// ��ջ 
	void StackPush(STDataType data);
	// ��ջ 
	void StackPop();
	// ��ȡջ��Ԫ�� 
	STDataType StackTop();
	// ��ȡջ����ЧԪ�ظ��� 
	int StackSize();
	// ���ջ�Ƿ�Ϊ��
	bool StackEmpty();
	// ���ջ��������С
	int StackCapacity();
private:
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
};