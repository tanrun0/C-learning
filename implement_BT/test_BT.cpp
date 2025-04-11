// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树

#include "BT.h"
#include <iostream>

// 测试代码
int main()
{
	string str("ABD##E#H##CF##G##");
	BT tree(str);
	tree.BT_LevelOrder(tree.root);
	int size = 0;
	tree.BT_Size(tree.root, size);
	cout << "节点个数：" << size << endl;
	cout << "第3层节点个数：" << tree.BT_LevelKSize(tree.root, 3) << endl;
	cout << "找节点3：";
	if (!tree.BT_Find(tree.root, 3)) {
		cout << "找到了" << endl;
	}
	else {
		cout << "没找到" << endl;
	}

	cout << "前序遍历结果：";
	tree.BT_PrevOrder(tree.root);
	cout << endl;

	cout << "层次遍历结果：";
	tree.BT_LevelOrder(tree.root);
	cout << endl;
	cout << "是否是完全二叉树：" ;
	if (tree.BinaryTreeComplete(tree.root))
	{
		cout << "是" << endl;
	}
	else {
		cout << "不是" << endl;
	}


}