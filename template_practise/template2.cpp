#include"template.h"

// ģ����ײ���
//int main()
//{
//	cout << Add<int, 5>(2) << endl; // ��ʾָ��ģ�����
//	cout << Add(2.1) << endl; // û����ʾ���ݣ����б������Ƶ���2.1 ���� ������������ T ��Ϊ�����ͣ�a��ȱʡֵ 3
//	return 0;
//
//}

//int main()
//{
//	tr::array<int,5> a1;
//	tr::array<int> a2;
//	return 0;
//}


#include <iostream>

int main()
{
	cout << "����һ������" << endl;
	Print<int, int> p1;
	cout << endl;
	Print<int*, int*> p2;
	Print<int&, int&> p3;
	return 0;
}
