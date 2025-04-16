#include<iostream>
#include"BSTREE.h"
using namespace std;


//void test1()
//{
//	tr::BSTREE tree1;
//
//	string s = "153426";
//	for (auto c : s)
//	{
//		tree1.Insert(c - '0'); // ע������ת����д������ʹ��(int)c �ǽ�����ַ���ASCIIֵ
//	}
//	tree1.Print();
//	tree1.Erase(1);
//	tree1.Print();
//
//	tree1.Erase(3);
//	tree1.Print();
//
//	tree1.Erase(2);
//	tree1.Print();
//
//	tree1.Erase(4);
//	tree1.Print();
//
//	tree1.Erase(6);
//	tree1.Print();
//
//	tree1.Erase(5);
//	tree1.Print();
//
//	tree1.Print();
//}


void Test2()
{
	tr::BSTree<string, string> dict;
	dict.Insert("insert", "����");
	dict.Insert("erase", "ɾ��");
	dict.Insert("left", "���");
	dict.Insert("string", "�ַ���");

	string str;
	while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << str << ":" << ret->_value << endl;
		}
		else
		{
			cout << "����ƴд����" << endl;
		}
	}

	string strs[] = { "ƻ��", "����", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��" };
	// ͳ��ˮ�����ֵĴ�
	tr::BSTree<string, int> countTree;
	for (auto str : strs)
	{
		auto ret = countTree.Find(str);
		if (ret == NULL)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	countTree.InOrder();
}
int main()
{

	Test2();
	return 0;
}