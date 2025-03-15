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

// ��ջ 
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

// ��ջ 
void Stack::StackPop() {
	if (StackEmpty()) {
		std::cout << "ջΪ��" << std::endl;
	}
	_top--;
}

// ��ȡջ��Ԫ�� 
STDataType Stack::StackTop() {
	if (StackEmpty()) {
		std::cout << "ջΪ��" << std::endl;
		return -1;
	}
	else {
		return _a[_top];
	}
}
// ��ȡջ����ЧԪ�ظ��� 
int Stack::StackSize() {
	return _top + 1;
}

// ���ջ�Ƿ�Ϊ��
bool Stack::StackEmpty() {
	return (_top == -1);
}

int Stack::StackCapacity() {
	return _capacity;
}