// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������

#include "BT.h"
#include <iostream>

// ���Դ���
int main()
{
	string str("ABD##E#H##CF##G##");
	BT tree(str);
	tree.BT_LevelOrder(tree.root);
	int size = 0;
	tree.BT_Size(tree.root, size);
	cout << "�ڵ������" << size << endl;
	cout << "��3��ڵ������" << tree.BT_LevelKSize(tree.root, 3) << endl;
	cout << "�ҽڵ�3��";
	if (!tree.BT_Find(tree.root, 3)) {
		cout << "�ҵ���" << endl;
	}
	else {
		cout << "û�ҵ�" << endl;
	}

	cout << "ǰ����������";
	tree.BT_PrevOrder(tree.root);
	cout << endl;

	cout << "��α��������";
	tree.BT_LevelOrder(tree.root);
	cout << endl;
	cout << "�Ƿ�����ȫ��������" ;
	if (tree.BinaryTreeComplete(tree.root))
	{
		cout << "��" << endl;
	}
	else {
		cout << "����" << endl;
	}


}