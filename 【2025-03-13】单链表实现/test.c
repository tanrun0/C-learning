#include "SList.h"
#include <stdio.h>

// ���Ժ�����������֤������Ĺ���
void testSList() {
    SLTNode* phead = NULL;

    // ����β��
    printf("����β��:\n");
    SLTPushBack(&phead, 1);
    SLTPushBack(&phead, 2);
    SLTPushBack(&phead, 3);
    SLTPrint(phead);

    // ����ͷ��
    printf("����ͷ��:\n");
    SLTPushFront(&phead, 0);
    SLTPrint(phead);

    // ����βɾ
    printf("����βɾ:\n");
    SLTPopBack(&phead);
    SLTPrint(phead);

    // ����ͷɾ
    printf("����ͷɾ:\n");
    SLTPopFront(&phead);
    SLTPrint(phead);

    // ���Բ���
    printf("���Բ���:\n");
    SLTNode* pos = SLTFind(phead, 2);
    if (pos != NULL) {
        printf("�ҵ�Ԫ�� 2\n");
    }
    else {
        printf("δ�ҵ�Ԫ�� 2\n");
    }

    // ������ָ��λ��֮ǰ��������
    printf("������ָ��λ��֮ǰ��������:\n");
    pos = SLTFind(phead, 2);
    if (pos != NULL) {
        SLTInsert(&phead, pos, 4);
        SLTPrint(phead);
    }

    // ����ɾ��ָ��λ�ýڵ�
    printf("����ɾ��ָ��λ�ýڵ�:\n");
    pos = SLTFind(phead, 2);
    if (pos != NULL) {
        SLTErase(&phead, pos);
        SLTPrint(phead);
    }

    // ������ָ��λ��֮���������
    printf("������ָ��λ��֮���������:\n");
    pos = SLTFind(phead, 4);
    if (pos != NULL) {
        SLTInsertAfter(&phead, pos, 5);
        SLTPrint(phead);
    }

    // ����ɾ��ָ��λ��֮��Ľڵ�
    printf("����ɾ��ָ��λ��֮��Ľڵ�:\n");
    pos = SLTFind(phead, 4);
    if (pos != NULL) {
        SLTEraseAfter(&phead, pos);
        SLTPrint(phead);
    }

    // ������������
    printf("������������:\n");
    SListDesTroy(&phead);
    SLTPrint(phead);
}

int main() {
    testSList();
    return 0;
}