#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;


// Print ��ӡ��������������������в���
// �ݹ���ֹ�������������б�Ϊ��ʱƥ���������
//void ShowList()
//{
//	cout << endl;
//}
//
//// �ݹ��չ������
//template<class T, class...Args>
//void ShowList(T x, Args...args)
//{
//	cout << x << " "; // ��ӡ��չ���ĵ�������
//	ShowList(args...);
//}
//
//template<class...Args>
//void Print(Args... args)
//{
//	ShowList(args...);
//}

//int main()
//{
//	Print(1, string("xxxxx"), 2.2);
//	return 0;
//}

//template<class T1, class T2, class...Args>
//void ShowList(T1 x1, T2 x2, Args...args)
//{
//	cout << x1 << endl;
//	cout << x2 << endl;
//	cout << sizeof...(args) << endl;
//}
//
//int main()
//{
//	ShowList(1, 2.2, 3.3, "hello world");
//	return 0;
//}

////����ʾ��
//template<class T, class... Args>
//void ShowList(T value, Args... args) {
//    cout << value << " ";
//    if constexpr (sizeof...(args) > 0) {  // ����ʱ�ж�
//        ShowList(args...);               // ���� args �ǿ�ʱʵ����
//    }
//    // �����Զ���ֹ
//}
//
//int main()
//{
//	ShowList(1, 2.2, 3.3, "hello world");
//	return 0;
//}


template <class T>
const T& GetArg(const T& x) {
    cout << x << " ";  // ��ӡ����
    return x;          // ����ԭ��������֤���Ͳ��䣩
}

template <class ...Args>
void Arguments(Args... args) {}  // �պ����������ڽ���չ����Ĳ�����

template <class ...Args>
void Print(Args... args) {
    Arguments(GetArg(args)...);  // �ؼ���չ�������������� GetArg ����ÿ������
}
int main()
{
    Print(1, 2.2, 3.3, "hello world");
    return 0;
}