#include <iostream>
#include "BLL.h"

int main() {
    // ����һ����ͷ����˫��ѭ���������
    BLL list;

    // ���������Ƿ�Ϊ��
    std::cout << "��ʼ״̬�������Ƿ�Ϊ��: " << (list.LTEmpty() ? "��" : "��") << std::endl;

    // ����β�����
    std::cout << "ִ��β�����������Ԫ�� 1, 2, 3" << std::endl;
    list.LTPushBack(1);
    list.LTPushBack(2);
    list.LTPushBack(3);
    std::cout << "β�����������Ԫ��: ";
    list.LTPrint();

    // ����ͷ�����
    std::cout << "ִ��ͷ�����������Ԫ�� 0" << std::endl;
    list.LTPushFront(0);
    std::cout << "ͷ�����������Ԫ��: ";
    list.LTPrint();

    // ���Բ��Ҳ���
    std::cout << "����Ԫ�� 2" << std::endl;
    LTNode* foundNode = list.LTFind(2);
    if (foundNode != nullptr) {
        std::cout << "�ҵ�Ԫ�� 2" << std::endl;
    }

    // ������ָ��λ�ú�������
    if (foundNode != nullptr) {
        std::cout << "��Ԫ�� 2 ֮�����Ԫ�� 4" << std::endl;
        list.LTInsert(foundNode, 4);
        std::cout << "�������������Ԫ��: ";
        list.LTPrint();
    }

    // ����βɾ����
    std::cout << "ִ��βɾ����" << std::endl;
    list.LTPopBack();
    std::cout << "βɾ����������Ԫ��: ";
    list.LTPrint();

    // ����ͷɾ����
    std::cout << "ִ��ͷɾ����" << std::endl;
    list.LTPopFront();
    std::cout << "ͷɾ����������Ԫ��: ";
    list.LTPrint();

    // ����ɾ��ָ��λ�ýڵ����
    if (foundNode != nullptr) {
        std::cout << "ɾ��Ԫ�� 2" << std::endl;
        list.LTErase(foundNode);
        std::cout << "ɾ������������Ԫ��: ";
        list.LTPrint();
    }

    // ����ٴβ��������Ƿ�Ϊ��
    std::cout << "���״̬�������Ƿ�Ϊ��: " << (list.LTEmpty() ? "��" : "��") << std::endl;

    return 0;
}