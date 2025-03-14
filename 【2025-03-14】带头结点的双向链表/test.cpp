#include <iostream>
#include "BLL.h"

int main() {
    // 创建一个带头结点的双向循环链表对象
    BLL list;

    // 测试链表是否为空
    std::cout << "初始状态，链表是否为空: " << (list.LTEmpty() ? "是" : "否") << std::endl;

    // 测试尾插操作
    std::cout << "执行尾插操作，插入元素 1, 2, 3" << std::endl;
    list.LTPushBack(1);
    list.LTPushBack(2);
    list.LTPushBack(3);
    std::cout << "尾插操作后链表元素: ";
    list.LTPrint();

    // 测试头插操作
    std::cout << "执行头插操作，插入元素 0" << std::endl;
    list.LTPushFront(0);
    std::cout << "头插操作后链表元素: ";
    list.LTPrint();

    // 测试查找操作
    std::cout << "查找元素 2" << std::endl;
    LTNode* foundNode = list.LTFind(2);
    if (foundNode != nullptr) {
        std::cout << "找到元素 2" << std::endl;
    }

    // 测试在指定位置后插入操作
    if (foundNode != nullptr) {
        std::cout << "在元素 2 之后插入元素 4" << std::endl;
        list.LTInsert(foundNode, 4);
        std::cout << "插入操作后链表元素: ";
        list.LTPrint();
    }

    // 测试尾删操作
    std::cout << "执行尾删操作" << std::endl;
    list.LTPopBack();
    std::cout << "尾删操作后链表元素: ";
    list.LTPrint();

    // 测试头删操作
    std::cout << "执行头删操作" << std::endl;
    list.LTPopFront();
    std::cout << "头删操作后链表元素: ";
    list.LTPrint();

    // 测试删除指定位置节点操作
    if (foundNode != nullptr) {
        std::cout << "删除元素 2" << std::endl;
        list.LTErase(foundNode);
        std::cout << "删除操作后链表元素: ";
        list.LTPrint();
    }

    // 最后再次测试链表是否为空
    std::cout << "最后状态，链表是否为空: " << (list.LTEmpty() ? "是" : "否") << std::endl;

    return 0;
}