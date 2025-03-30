#include "HP.h"

int main() {
    Heap hp;
    // 初始化堆
    HeapInit(&hp);

    // 测试堆的插入操作
    printf("测试堆的插入操作:\n");
    HeapPush(&hp, 3);
    HeapPush(&hp, 1);
    HeapPush(&hp, 2);
    printf("插入 3, 1, 2 后，堆顶元素: %d\n", HeapTop(&hp));
    printf("堆的大小: %d\n", HeapSize(&hp));

    // 测试堆的删除操作
    printf("\n测试堆的删除操作:\n");
    HeapPop(&hp);
    printf("删除堆顶元素后，堆顶元素: %d\n", HeapTop(&hp));
    printf("堆的大小: %d\n", HeapSize(&hp));

    // 测试堆的判空操作
    printf("\n测试堆的判空操作:\n");
    if (HeapEmpty(&hp)) {
        printf("堆为空\n");
    }
    else {
        printf("堆不为空\n");
    }

    // 销毁堆
    HeapDestory(&hp);

    // 再次测试堆的判空操作
    printf("\n销毁堆后，测试堆的判空操作:\n");
    if (HeapEmpty(&hp)) {
        printf("堆为空\n");
    }
    else {
        printf("堆不为空\n");
    }

    printf("测试堆排序\n");
    HPDataType arr[] = { 5, 4, 3, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前数组: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    HeapSort(arr, n);

    printf("排序后数组: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


