#include <iostream>
#include "Queue.h"

int main() {
    // ����һ�����ж���
    Queue queue;

    // �������Ƿ�Ϊ��
    if (queue.QueueEmpty()) {
        std::cout << "���г�ʼΪ�ա�" << std::endl;
    }

    // ��Ӳ���
    std::cout << "��ʼ��Ӳ���..." << std::endl;
    queue.QueuePush(10);
    queue.QueuePush(20);
    queue.QueuePush(30);
    queue.QueuePush(40);
    queue.QueuePush(50);

    std::cout << "��� 10, 20, 30��40��50 �󣬶��д�СΪ: " << queue.QueueSize() << std::endl;

    // ��ȡ��ͷԪ��
    std::cout << "��ǰ��ͷԪ��Ϊ: " << queue.QueueFront() << std::endl;

    // ��ȡ��βԪ��
    std::cout << "��ǰ��βԪ��Ϊ: " << queue.QueueBack() << std::endl;

    // ���Ӳ���
    std::cout << "��ʼ���Ӳ���..." << std::endl;
    queue.QueuePop();
    std::cout << "����һ�κ󣬶��д�СΪ: " << queue.QueueSize() << std::endl;

    // �ٴλ�ȡ��ͷԪ��
    std::cout << "����һ�κ󣬵�ǰ��ͷԪ��Ϊ: " << queue.QueueFront() << std::endl;

    // �ٴλ�ȡ��βԪ��
    std::cout << "����һ�κ󣬵�ǰ��βԪ��Ϊ: " << queue.QueueBack() << std::endl;

    // ��ն���
    std::cout << "��ʼ��ն���..." << std::endl;
    while (!queue.QueueEmpty()) {
        queue.QueuePop();
    }
    std::cout << "��ն��к󣬶��д�СΪ: " << queue.QueueSize() << std::endl;

    // �ٴμ������Ƿ�Ϊ��
    if (queue.QueueEmpty()) {
        std::cout << "��������գ�����Ϊ�ա�" << std::endl;
    }

    return 0;
}