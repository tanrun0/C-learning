#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#define TEST_SEQUENCE_LIST

// 实现顺序表的增删改查
#define INIT_CAPACITY 4
typedef int SLDataType;
// 动态顺序表 -- 按需申请
typedef struct SeqList
{
    SLDataType* a;
    int size;     // 有效数据个数
    int capacity; // 空间容量
}SL;

//初始化和销毁
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
// 检查是否需要扩容，并实现扩容（扩大两倍），realloc函数：
// void *realloc(void *ptr, size_t size); （ptr是原空间）
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

//头部插入删除 / 尾部插入删除
// 表尾插入
void SLPushBack(SL* ps, SLDataType x) {
    assert(ps);
    SLCheckCapacity(ps);
    ps->a[ps->size] = x;
    ps->size++;
}
// 表尾删除
void SLPopBack(SL* ps) {
    assert(ps);
    assert(ps->size > 0); 
    ps->size--;
}
// 表头插入
void SLPushFront(SL* ps, SLDataType x) {
    assert(ps);
    SLCheckCapacity(ps);
    for (int i = ps->size - 1; i >= 0; i--) {
        ps->a[i + 1] = ps->a[i];
    }
    ps->a[0] = x;
    ps->size++;
}
// 表头删除
void SLPopFront(SL* ps) {
    assert(ps);
    assert(ps->size > 0);
    for (int i = 1; i < ps->size; i++) {
        ps->a[i - 1] = ps->a[i];
    }
    ps->size--;
}

//指定位置插入
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
// 指定位置删除数据
void SLErase(SL* ps, int pos) {
    assert(ps);
    assert(pos >= 0 && pos <= ps->size - 1); // ps->size == 0 : pos >= 0 就不满足了
    for (int i = pos + 1; i < ps->size; i++) {
        ps->a[i - 1] = ps->a[i];
    }
    ps->size--;
}
// 找指定元素的下标
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

// 测试代码，使用条件编译（当定义了TEST_SEQUENCE_LIST宏时，才执行下面这段代码）
#ifdef TEST_SEQUENCE_LIST
// 测试代码
int main() {
    SL sl;
    // 初始化顺序表
    SLInit(&sl);

    // 测试表尾插入
    printf("Testing SLPushBack:\n");
    SLPushBack(&sl, 1);
    SLPushBack(&sl, 2);
    SLPushBack(&sl, 3);
    SLPrint(&sl);  // 预期输出: 1 2 3

    // 测试表头插入
    printf("Testing SLPushFront:\n");
    SLPushFront(&sl, 0);
    SLPrint(&sl);  // 预期输出: 0 1 2 3

    // 测试指定位置插入
    printf("Testing SLInsert:\n");
    SLInsert(&sl, 2, 10);
    SLPrint(&sl);  // 预期输出: 0 1 10 2 3

    // 测试查找元素
    printf("Testing SLFind:\n");
    int index = SLFind(&sl, 10);
    if (index != -1) {
        printf("Element 10 found at index %d\n", index);
    }
    else {
        printf("Element 10 not found\n");
    }

    // 测试表尾删除
    printf("Testing SLPopBack:\n");
    SLPopBack(&sl);
    SLPrint(&sl);  // 预期输出: 0 1 10 2

    // 测试表头删除
    printf("Testing SLPopFront:\n");
    SLPopFront(&sl);
    SLPrint(&sl);  // 预期输出: 1 10 2

    // 测试指定位置删除
    printf("Testing SLErase:\n");
    SLErase(&sl, 1);
    SLPrint(&sl);  // 预期输出: 1 2

    // 销毁顺序表
    SLDestroy(&sl);

    return 0;
}
#endif