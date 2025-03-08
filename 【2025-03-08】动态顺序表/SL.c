#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#define TEST_SEQUENCE_LIST

// ʵ��˳������ɾ�Ĳ�
#define INIT_CAPACITY 4
typedef int SLDataType;
// ��̬˳��� -- ��������
typedef struct SeqList
{
    SLDataType* a;
    int size;     // ��Ч���ݸ���
    int capacity; // �ռ�����
}SL;

//��ʼ��������
void SLInit(SL* ps) {
    assert(ps);
    ps->a = (SLDataType*)malloc(sizeof(SLDataType) * INIT_CAPACITY);
    if (ps->a == NULL) {
        printf("malloc fail");
        exit(EXIT_FAILURE); 
    }
    ps->size = 0;
    ps->capacity = INIT_CAPACITY;
}
void SLDestroy(SL* ps) {
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->size = 0;
    ps->capacity = 0;
}
void SLPrint(SL* ps) {
    assert(ps);
    if (ps->size == 0) {
        printf("SL is empty");
        return;
    }
    for (int i = 0; i < ps->size; i++) {
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}
// ����Ƿ���Ҫ���ݣ���ʵ�����ݣ�������������realloc������
// void *realloc(void *ptr, size_t size); ��ptr��ԭ�ռ䣩
void SLCheckCapacity(SL* ps) {
    assert(ps);
    if (ps->size == ps->capacity) {
        int newcapacity = ps->capacity * 2;
        SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
        if (tmp == NULL) {
            printf("realloc fail");
            exit(EXIT_FAILURE);
        }
        ps->a = tmp;
        ps->capacity = newcapacity;
    }
}

//ͷ������ɾ�� / β������ɾ��
// ��β����
void SLPushBack(SL* ps, SLDataType x) {
    assert(ps);
    SLCheckCapacity(ps);
    ps->a[ps->size] = x;
    ps->size++;
}
// ��βɾ��
void SLPopBack(SL* ps) {
    assert(ps);
    assert(ps->size > 0); 
    ps->size--;
}
// ��ͷ����
void SLPushFront(SL* ps, SLDataType x) {
    assert(ps);
    SLCheckCapacity(ps);
    for (int i = ps->size - 1; i >= 0; i--) {
        ps->a[i + 1] = ps->a[i];
    }
    ps->a[0] = x;
    ps->size++;
}
// ��ͷɾ��
void SLPopFront(SL* ps) {
    assert(ps);
    assert(ps->size > 0);
    for (int i = 1; i < ps->size; i++) {
        ps->a[i - 1] = ps->a[i];
    }
    ps->size--;
}

//ָ��λ�ò���
void SLInsert(SL* ps, int pos, SLDataType x) {
    assert(ps);
    assert(pos >= 0 && pos <= ps->size);
    SLCheckCapacity(ps);
    for (int i = ps->size - 1; i >= pos; i--) {
        ps->a[i + 1] = ps->a[i];
    }
    ps->a[pos] = x;
    ps->size++;
}
// ָ��λ��ɾ������
void SLErase(SL* ps, int pos) {
    assert(ps);
    assert(pos >= 0 && pos <= ps->size - 1); // ps->size == 0 : pos >= 0 �Ͳ�������
    for (int i = pos + 1; i < ps->size; i++) {
        ps->a[i - 1] = ps->a[i];
    }
    ps->size--;
}
// ��ָ��Ԫ�ص��±�
int SLFind(SL* ps, SLDataType x) {
    assert(ps);
    for (int i = 0; i < ps->size; i++)
    {
        if (ps->a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

// ���Դ��룬ʹ���������루��������TEST_SEQUENCE_LIST��ʱ����ִ��������δ��룩
#ifdef TEST_SEQUENCE_LIST
// ���Դ���
int main() {
    SL sl;
    // ��ʼ��˳���
    SLInit(&sl);

    // ���Ա�β����
    printf("Testing SLPushBack:\n");
    SLPushBack(&sl, 1);
    SLPushBack(&sl, 2);
    SLPushBack(&sl, 3);
    SLPrint(&sl);  // Ԥ�����: 1 2 3

    // ���Ա�ͷ����
    printf("Testing SLPushFront:\n");
    SLPushFront(&sl, 0);
    SLPrint(&sl);  // Ԥ�����: 0 1 2 3

    // ����ָ��λ�ò���
    printf("Testing SLInsert:\n");
    SLInsert(&sl, 2, 10);
    SLPrint(&sl);  // Ԥ�����: 0 1 10 2 3

    // ���Բ���Ԫ��
    printf("Testing SLFind:\n");
    int index = SLFind(&sl, 10);
    if (index != -1) {
        printf("Element 10 found at index %d\n", index);
    }
    else {
        printf("Element 10 not found\n");
    }

    // ���Ա�βɾ��
    printf("Testing SLPopBack:\n");
    SLPopBack(&sl);
    SLPrint(&sl);  // Ԥ�����: 0 1 10 2

    // ���Ա�ͷɾ��
    printf("Testing SLPopFront:\n");
    SLPopFront(&sl);
    SLPrint(&sl);  // Ԥ�����: 1 10 2

    // ����ָ��λ��ɾ��
    printf("Testing SLErase:\n");
    SLErase(&sl, 1);
    SLPrint(&sl);  // Ԥ�����: 1 2

    // ����˳���
    SLDestroy(&sl);

    return 0;
}
#endif