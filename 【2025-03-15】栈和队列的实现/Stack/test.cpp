#include <iostream>
#include "Stack.h"

int main() {
    // 1. ��ʼ��ջ
    Stack stack(5);
    std::cout << "ջ��ʼ����ɣ���ʼ����Ϊ 5��" << std::endl;

    // 2. ���ջ�Ƿ�Ϊ��
    if (stack.StackEmpty()) {
        std::cout << "ջΪ�ա�" << std::endl;
    }
    else {
        std::cout << "ջ��Ϊ�ա�" << std::endl;
    }

    // 3. ��ջ����
    std::cout << "��ʼ������ջ����..." << std::endl;
    stack.StackPush(10);
    stack.StackPush(20);
    stack.StackPush(30);
    std::cout << "��ջ 10, 20, 30 ��ջ�Ĵ�СΪ: " << stack.StackSize() << std::endl;

    // 4. ��ȡջ��Ԫ��
    STDataType top = stack.StackTop();
    if (top != -1) {
        std::cout << "��ǰջ��Ԫ��Ϊ: " << top << std::endl;
    }
    else {
        std::cout << "ջΪ�գ��޷���ȡջ��Ԫ�ء�" << std::endl;
    }

    // 5. ��ջ����
    std::cout << "��ʼ���г�ջ����..." << std::endl;
    stack.StackPop();
    std::cout << "��ջһ�κ�ջ�Ĵ�СΪ: " << stack.StackSize() << std::endl;

    // 6. �ٴλ�ȡջ��Ԫ��
    top = stack.StackTop();
    if (top != -1) {
        std::cout << "��ǰջ��Ԫ��Ϊ: " << top << std::endl;
    }
    else {
        std::cout << "ջΪ�գ��޷���ȡջ��Ԫ�ء�" << std::endl;
    }

    // 7. ������ջֱ����������
    std::cout << "������ջֱ����������..." << std::endl;
    stack.StackPush(40);
    stack.StackPush(50);
    stack.StackPush(60);
    stack.StackPush(70);

    std::cout << "��ջ 40, 50, 60��70 ��ջ������Ϊ: " << stack.StackCapacity() << std::endl;

    // 8. ���ջ
    std::cout << "��ʼ���ջ..." << std::endl;
    while (!stack.StackEmpty()) {
        stack.StackPop();
    }
    std::cout << "ջ��պ�ջ�Ĵ�СΪ: " << stack.StackSize() << std::endl;

    // 9. �ٴμ��ջ�Ƿ�Ϊ��
    if (stack.StackEmpty()) {
        std::cout << "ջΪ�ա�" << std::endl;
    }
    else {
        std::cout << "ջ��Ϊ�ա�" << std::endl;
    }

    return 0;
}