#include <iostream>
#include "Stack.h"

int main() {
    // 1. 初始化栈
    Stack stack(5);
    std::cout << "栈初始化完成，初始容量为 5。" << std::endl;

    // 2. 检测栈是否为空
    if (stack.StackEmpty()) {
        std::cout << "栈为空。" << std::endl;
    }
    else {
        std::cout << "栈不为空。" << std::endl;
    }

    // 3. 入栈操作
    std::cout << "开始进行入栈操作..." << std::endl;
    stack.StackPush(10);
    stack.StackPush(20);
    stack.StackPush(30);
    std::cout << "入栈 10, 20, 30 后，栈的大小为: " << stack.StackSize() << std::endl;

    // 4. 获取栈顶元素
    STDataType top = stack.StackTop();
    if (top != -1) {
        std::cout << "当前栈顶元素为: " << top << std::endl;
    }
    else {
        std::cout << "栈为空，无法获取栈顶元素。" << std::endl;
    }

    // 5. 出栈操作
    std::cout << "开始进行出栈操作..." << std::endl;
    stack.StackPop();
    std::cout << "出栈一次后，栈的大小为: " << stack.StackSize() << std::endl;

    // 6. 再次获取栈顶元素
    top = stack.StackTop();
    if (top != -1) {
        std::cout << "当前栈顶元素为: " << top << std::endl;
    }
    else {
        std::cout << "栈为空，无法获取栈顶元素。" << std::endl;
    }

    // 7. 持续入栈直到触发扩容
    std::cout << "持续入栈直到触发扩容..." << std::endl;
    stack.StackPush(40);
    stack.StackPush(50);
    stack.StackPush(60);
    stack.StackPush(70);

    std::cout << "入栈 40, 50, 60，70 后，栈的容量为: " << stack.StackCapacity() << std::endl;

    // 8. 清空栈
    std::cout << "开始清空栈..." << std::endl;
    while (!stack.StackEmpty()) {
        stack.StackPop();
    }
    std::cout << "栈清空后，栈的大小为: " << stack.StackSize() << std::endl;

    // 9. 再次检测栈是否为空
    if (stack.StackEmpty()) {
        std::cout << "栈为空。" << std::endl;
    }
    else {
        std::cout << "栈不为空。" << std::endl;
    }

    return 0;
}