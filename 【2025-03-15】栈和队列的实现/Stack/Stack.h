#pragma once
#include<iostream>

// 支持动态增长的栈
typedef int STDataType;

class Stack {
public:
	// 初始化栈 
	Stack(int c = 10);
	~Stack();
	// 入栈 
	void StackPush(STDataType data);
	// 出栈 
	void StackPop();
	// 获取栈顶元素 
	STDataType StackTop();
	// 获取栈中有效元素个数 
	int StackSize();
	// 检测栈是否为空
	bool StackEmpty();
	// 获得栈的容量大小
	int StackCapacity();
private:
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
};