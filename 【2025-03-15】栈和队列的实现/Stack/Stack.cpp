#include"Stack.h"

Stack::Stack(int c)
	: _a(new STDataType[c])
	, _top(-1)
	, _capacity(c)
{ }

Stack::~Stack() {
	delete[] _a;
	_a = nullptr;
}

// 入栈 
void Stack::StackPush(STDataType data) {
	if (_top == _capacity - 1) {
		int newcapacity = _capacity * 2;
		STDataType* tmp = new STDataType[newcapacity];
		delete _a;
		_a = tmp;
		_capacity = newcapacity;
	}
	_a[++_top] = data;
}

// 出栈 
void Stack::StackPop() {
	if (StackEmpty()) {
		std::cout << "栈为空" << std::endl;
	}
	_top--;
}

// 获取栈顶元素 
STDataType Stack::StackTop() {
	if (StackEmpty()) {
		std::cout << "栈为空" << std::endl;
		return -1;
	}
	else {
		return _a[_top];
	}
}
// 获取栈中有效元素个数 
int Stack::StackSize() {
	return _top + 1;
}

// 检测栈是否为空
bool Stack::StackEmpty() {
	return (_top == -1);
}

int Stack::StackCapacity() {
	return _capacity;
}