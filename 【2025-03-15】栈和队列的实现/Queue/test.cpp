#include <iostream>
#include "Queue.h"

int main() {
    // 创建一个队列对象
    Queue queue;

    // 检查队列是否为空
    if (queue.QueueEmpty()) {
        std::cout << "队列初始为空。" << std::endl;
    }

    // 入队操作
    std::cout << "开始入队操作..." << std::endl;
    queue.QueuePush(10);
    queue.QueuePush(20);
    queue.QueuePush(30);
    queue.QueuePush(40);
    queue.QueuePush(50);

    std::cout << "入队 10, 20, 30，40，50 后，队列大小为: " << queue.QueueSize() << std::endl;

    // 获取队头元素
    std::cout << "当前队头元素为: " << queue.QueueFront() << std::endl;

    // 获取队尾元素
    std::cout << "当前队尾元素为: " << queue.QueueBack() << std::endl;

    // 出队操作
    std::cout << "开始出队操作..." << std::endl;
    queue.QueuePop();
    std::cout << "出队一次后，队列大小为: " << queue.QueueSize() << std::endl;

    // 再次获取队头元素
    std::cout << "出队一次后，当前队头元素为: " << queue.QueueFront() << std::endl;

    // 再次获取队尾元素
    std::cout << "出队一次后，当前队尾元素为: " << queue.QueueBack() << std::endl;

    // 清空队列
    std::cout << "开始清空队列..." << std::endl;
    while (!queue.QueueEmpty()) {
        queue.QueuePop();
    }
    std::cout << "清空队列后，队列大小为: " << queue.QueueSize() << std::endl;

    // 再次检查队列是否为空
    if (queue.QueueEmpty()) {
        std::cout << "队列已清空，现在为空。" << std::endl;
    }

    return 0;
}