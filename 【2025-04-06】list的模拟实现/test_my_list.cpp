#include"my_list.h"
using namespace tr;

// ��ӡ�б�Ԫ�صĺ���
template<class T>
void printList(const list<T>& ls) {
    for (auto it = ls.begin(); it != ls.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testList() {
    // ����Ĭ�Ϲ��캯��
    list<int> ls1;
    std::cout << "Testing default constructor: ";
    printList(ls1);

    // ���Դ������Ĺ��캯��
    list<int> ls2(5, 10);
    std::cout << "Testing constructor with n and value: ";
    printList(ls2);

    // ���Ե��������캯��
    list<int> ls3(ls2.begin(), ls2.end());
    std::cout << "Testing constructor with iterators: ";
    printList(ls3);

    // ���Կ������캯��
    list<int> ls4(ls3);
    std::cout << "Testing copy constructor: ";
    printList(ls4);

    // ���Ը�ֵ�����
    list<int> ls5;
    ls5 = ls4;
    std::cout << "Testing assignment operator: ";
    printList(ls5);

    // ���� push_back
    ls5.push_back(20);
    std::cout << "Testing push_back: ";
    printList(ls5);

    // ���� push_front
    ls5.push_front(5);
    std::cout << "Testing push_front: ";
    printList(ls5);

    // ���� pop_back
    ls5.pop_back();
    std::cout << "Testing pop_back: ";
    printList(ls5);

    // ���� pop_front
    ls5.pop_front();
    std::cout << "Testing pop_front: ";
    printList(ls5);

    // ���� insert
    auto it = ls5.begin();
    ++it;
    ls5.insert(it, 15);
    std::cout << "Testing insert: ";
    printList(ls5);

    // ���� erase
    it = ls5.begin();
    ++it;
    ls5.erase(it);
    std::cout << "Testing erase: ";
    printList(ls5);

    // ���� clear
    ls5.clear();
    std::cout << "Testing clear: ";
    printList(ls5);

    // ���� size �� empty
    std::cout << "Size after clear: " << ls5.size() << std::endl;
    std::cout << "Is empty after clear: " << (ls5.empty() ? "Yes" : "No") << std::endl;
}

int main() {
    testList();
    return 0;
}
