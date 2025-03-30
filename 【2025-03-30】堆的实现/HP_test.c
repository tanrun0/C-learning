#include "HP.h"

int main() {
    Heap hp;
    // ��ʼ����
    HeapInit(&hp);

    // ���ԶѵĲ������
    printf("���ԶѵĲ������:\n");
    HeapPush(&hp, 3);
    HeapPush(&hp, 1);
    HeapPush(&hp, 2);
    printf("���� 3, 1, 2 �󣬶Ѷ�Ԫ��: %d\n", HeapTop(&hp));
    printf("�ѵĴ�С: %d\n", HeapSize(&hp));

    // ���Զѵ�ɾ������
    printf("\n���Զѵ�ɾ������:\n");
    HeapPop(&hp);
    printf("ɾ���Ѷ�Ԫ�غ󣬶Ѷ�Ԫ��: %d\n", HeapTop(&hp));
    printf("�ѵĴ�С: %d\n", HeapSize(&hp));

    // ���Զѵ��пղ���
    printf("\n���Զѵ��пղ���:\n");
    if (HeapEmpty(&hp)) {
        printf("��Ϊ��\n");
    }
    else {
        printf("�Ѳ�Ϊ��\n");
    }

    // ���ٶ�
    HeapDestory(&hp);

    // �ٴβ��Զѵ��пղ���
    printf("\n���ٶѺ󣬲��Զѵ��пղ���:\n");
    if (HeapEmpty(&hp)) {
        printf("��Ϊ��\n");
    }
    else {
        printf("�Ѳ�Ϊ��\n");
    }

    printf("���Զ�����\n");
    HPDataType arr[] = { 5, 4, 3, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("����ǰ����: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    HeapSort(arr, n);

    printf("���������: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


