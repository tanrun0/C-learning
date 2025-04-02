#include <iostream>
#include "my_vector.h"

using namespace tr;

// 简单的测试函数
void testVector() {
    // 测试默认构造函数
    vector<int> v1;
    std::cout << "v1 size: " << v1.size() << ", capacity: " << v1.capacity() << std::endl;

    // 测试带参数的构造函数
    vector<int> v2(5, 10);
    std::cout << "v2 size: " << v2.size() << ", capacity: " << v2.capacity() << std::endl;
    for (size_t i = 0; i < v2.size(); ++i) {
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;

    // 测试区间构造函数
    int arr[] = { 1, 2, 3, 4, 5 };
    vector<int> v3(arr, arr + 5);
    std::cout << "v3 size: " << v3.size() << ", capacity: " << v3.capacity() << std::endl;
    for (size_t i = 0; i < v3.size(); ++i) {
        std::cout << v3[i] << " ";
    }
    std::cout << std::endl;

    // 测试拷贝构造函数
    vector<int> v4(v3);
    std::cout << "v4 size: " << v4.size() << ", capacity: " << v4.capacity() << std::endl;
    for (size_t i = 0; i < v4.size(); ++i) {
        std::cout << v4[i] << " ";
    }
    std::cout << std::endl;

    // 测试赋值运算符
    vector<int> v5;
    v5 = v2;
    std::cout << "v5 size: " << v5.size() << ", capacity: " << v5.capacity() << std::endl;
    for (size_t i = 0; i < v5.size(); ++i) {
        std::cout << v5[i] << " ";
    }
    std::cout << std::endl;

    // 测试push_back和pop_back
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    std::cout << "v1 size after push_back: " << v1.size() << ", capacity: " << v1.capacity() << std::endl;
    v1.pop_back();
    std::cout << "v1 size after pop_back: " << v1.size() << ", capacity: " << v1.capacity() << std::endl;

    // 测试insert
    v1.insert(v1.begin(), 0);
    std::cout << "v1 size after insert: " << v1.size() << ", capacity: " << v1.capacity() << std::endl;
    for (size_t i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;

    // 测试erase
    v1.erase(v1.begin());
    std::cout << "v1 size after erase: " << v1.size() << ", capacity: " << v1.capacity() << std::endl;
    for (size_t i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;

    // 测试resize
    v1.resize(5, 5);
    std::cout << "v1 size after resize: " << v1.size() << ", capacity: " << v1.capacity() << std::endl;
    for (size_t i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    testVector();
    return 0;
}