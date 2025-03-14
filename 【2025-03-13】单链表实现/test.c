#include "SList.h"
#include <stdio.h>

// 测试函数，用于验证单链表的功能
void testSList() {
    SLTNode* phead = NULL;

    // 测试尾插
    printf("测试尾插:\n");
    SLTPushBack(&phead, 1);
    SLTPushBack(&phead, 2);
    SLTPushBack(&phead, 3);
    SLTPrint(phead);

    // 测试头插
    printf("测试头插:\n");
    SLTPushFront(&phead, 0);
    SLTPrint(phead);

    // 测试尾删
    printf("测试尾删:\n");
    SLTPopBack(&phead);
    SLTPrint(phead);

    // 测试头删
    printf("测试头删:\n");
    SLTPopFront(&phead);
    SLTPrint(phead);

    // 测试查找
    printf("测试查找:\n");
    SLTNode* pos = SLTFind(phead, 2);
    if (pos != NULL) {
        printf("找到元素 2\n");
    }
    else {
        printf("未找到元素 2\n");
    }

    // 测试在指定位置之前插入数据
    printf("测试在指定位置之前插入数据:\n");
    pos = SLTFind(phead, 2);
    if (pos != NULL) {
        SLTInsert(&phead, pos, 4);
        SLTPrint(phead);
    }

    // 测试删除指定位置节点
    printf("测试删除指定位置节点:\n");
    pos = SLTFind(phead, 2);
    if (pos != NULL) {
        SLTErase(&phead, pos);
        SLTPrint(phead);
    }

    // 测试在指定位置之后插入数据
    printf("测试在指定位置之后插入数据:\n");
    pos = SLTFind(phead, 4);
    if (pos != NULL) {
        SLTInsertAfter(&phead, pos, 5);
        SLTPrint(phead);
    }

    // 测试删除指定位置之后的节点
    printf("测试删除指定位置之后的节点:\n");
    pos = SLTFind(phead, 4);
    if (pos != NULL) {
        SLTEraseAfter(&phead, pos);
        SLTPrint(phead);
    }

    // 测试销毁链表
    printf("测试销毁链表:\n");
    SListDesTroy(&phead);
    SLTPrint(phead);
}

int main() {
    testSList();
    return 0;
}