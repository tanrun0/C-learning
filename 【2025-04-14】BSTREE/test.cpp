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
//		tree1.Insert(c - '0'); // 注意类型转换的写法，将使用(int)c 是将输出字符的ASCII值
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
	dict.Insert("insert", "插入");
	dict.Insert("erase", "删除");
	dict.Insert("left", "左边");
	dict.Insert("string", "字符串");

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
			cout << "单词拼写错误" << endl;
		}
	}

	string strs[] = { "苹果", "西瓜", "苹果", "樱桃", "苹果", "樱桃", "苹果", "樱桃", "苹果" };
	// 统计水果出现的次
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