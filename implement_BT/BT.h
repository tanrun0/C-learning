// BT.h
#pragma once
#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct BTNode
{
	BTNode(char value) :_data(value), _left(nullptr), _right(nullptr)
	{ }
	char _data;
	BTNode* _left;
	BTNode* _right;
};


// 这是一个用string来初始化字符二叉树
class BT
{
public:

	void BT_creat(BTNode*& root, string& str)
	{
		if (str.empty()) return;
		char c = str[0];
		str = str.substr(1);
		if (c == '#') { return; }
		if (root == nullptr)
		{
			root = new BTNode(c);
		}
		BT_creat(root->_left, str);
		BT_creat(root->_right, str);
	}

	// 二叉树销毁（用后序遍历）
	void BT_Destory(BTNode*& root)
	{
		if (!root) return;
		BT_Destory(root->_left);
		BT_Destory(root->_right);
		delete root;
		root = nullptr;
	}



	BT(string& str) { BT_creat(root, str); }
	~BT() { BT_Destory(root); }

	// 二叉树节点个数，用一个外部变量接收
	void BT_Size(BTNode* root, int& size) {
		if (!root) { return; }
		size++;
		BT_Size(root->_left, size);
		BT_Size(root->_right, size);
	}

	// 二叉树叶子节点个数
	int BT_LeafSize(BTNode* root) {
		if (!root) { return 0; }
		if (!root->_left && !root->_right) { return 1; }
		return BT_LeafSize(root->_left) + BT_LeafSize(root->_right);
	}

	// 二叉树第k层节点个数
	// 以root为根的第k层节点个数 = root的左子树的第k-1层节点个数 + root的右子树的第k-1层节点个数
	int BT_LevelKSize(BTNode* root, int k)
	{
		if (!root || k < 1) return 0;
		if (k == 1) { return 1; }
		return BT_LevelKSize(root->_left, k - 1) + BT_LevelKSize(root->_right, k - 1);
	}

	// 二叉树查找值为x的节点，遍历整棵树，如果找到了就直接返回
	BTNode* BT_Find(BTNode* root, char x)
	{
		if (!root) { return nullptr; }
		if (root->_data == x) { return root; }
		BTNode* f = BT_Find(root->_left, x); // 遍历左子树找
		if (!f){ return f; } // 如果找到了
		f = BT_Find(root->_right, x);
		if (!f) { return f; }
		return nullptr;
	}

	// 二叉树前序遍历 
	void BT_PrevOrder(BTNode* root)
	{
		if (!root) { return; }
		cout << root->_data << ' ';
		BT_PrevOrder(root->_left);
		BT_PrevOrder(root->_right);
	}

	// 层序遍历（这不是递归，用队列：上一层带下一层，即：出队列的节点的孩子如队列）
	// 我们让指针入队，这样既可以得到元素，也可以找到孩子
	void BT_LevelOrder(BTNode* root)
	{
		queue<BTNode*> q;
		if (root) { q.push(root); }
		while (!q.empty())
		{
			BTNode* front = q.front(); // 先记录队头元素
			cout << front->_data << ' ';
			q.pop(); // 删除队头元素
			if (front->_left) { q.push(front->_left); }
			if (front->_right) { q.push(front->_right); }// 把队头元素的非空左右孩子入队列
		}
	}

	// 判断二叉树是否是完全二叉树
	// 方法：层序遍历，也记录空节点，当空节点被pop出去的时候，判断队列里面还有没有其他非空节点，如果有则代表不是完全二叉树
	// 推理：非空节点的父节点也是非空，当空节点被pop出去的时候，这个父节点早被pop出去了，孩子早就入队列了
	int BinaryTreeComplete(BTNode* root)
	{
		queue<BTNode*> q;
		if (root) { q.push(root); }
		while (!q.empty())
		{
			BTNode* front = q.front();
			if (front == nullptr) { break; } // 遇到空节点退出
			q.pop();
			q.push(front->_left);
			q.push(front->_right);
		}
		while (!q.empty())
		{
			BTNode* front = q.front();
			if (front) // 非空
			{
				return false;
			}
			q.pop();
		}
		return true;
	}

	BTNode* root;
};

