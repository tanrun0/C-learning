#pragma once
#include<iostream>
enum Color // 枚举类型，color只能取值red和black
{
	red,
	black
};

template<class K, class V>
struct RBTreeNode 
{
	pair<K, V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _father;
	Color _color;

	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _father(nullptr)
		, _color(red)
	{}
};


template<class K, class V>
class RBTree
{
public:
	typedef RBTreeNode<K, V> Node;

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_color = black;
			return true;
		}
		Node* father = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				father = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				father = cur;
				cur = cur->_left;
			}
			else // 不插入一样的节点
			{
				return false;
			}
		}
		cur = new Node(kv);
		cur->_color = red;
		cur->_father = father;
		if (cur->_kv.first < father->_kv.first)
		{
			father->_left = cur;
		}
		else
		{
			father->_right = cur;
		}

		while (father && father->_color == red)
		{
			Node* grandfather = father->_father;
			if (grandfather->_left == father)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_color == red)
				{
					father->_color = black;
					grandfather->_color = red;
					uncle->_color = black;
					cur = grandfather; // 往上继续调整
					father = cur->_father;
				}
				else // uncle 不存在或者uncle为黑 
				{
					if (father->_left == cur) // 成一条直线
					{
						father->_color = black;
						grandfather->_color = red;
						RotateR(grandfather); // father在左边，要右单旋
					}
					else
					{
						RotateL(father);
						cur->_color = black;
						grandfather->_color = red;
						RotateR(grandfather);
					}
				}
			}
			else 
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_color == red)
				{
					father->_color = black;
					grandfather->_color = red;
					uncle->_color = black;
					cur = grandfather; // 往上继续调整
					father = cur->_father;
				}
				else // uncle 不存在或者uncle为黑 
				{
					if (father->_right == cur) // 成一条直线
					{
						father->_color = black;
						grandfather->_color = red;
						RotateL(grandfather); // father在左边，要右单旋
					}
					else
					{
						RotateR(father);
						cur->_color = black;
						grandfather->_color = red;
						RotateL(grandfather);
					}
				}
			}
		}
		_root->_color = black; // 处理：刚好grandfather调整完以后，成为了根节点且为红
		cout << "插入成功" << endl;
		return true;
	}

	void RotateR(Node* father)
	{
		Node* subL = father->_left;
		Node* subLR = subL->_right;

		father->_left = subLR;
		if (subLR)
		{
			subLR->_father = father;
		}
		subL->_right = father;
		Node* grandfather = father->_father;
		father->_father = subL;
		if (grandfather == nullptr)
		{
			subL->_father = nullptr;
			_root = subL;
		}
		else
		{
			if (grandfather->_left == father)
			{
				grandfather->_left = subL;
			}
			else {
				grandfather->_right = subL;
			}
			subL->_father = grandfather;
		}
	}

	void RotateL(Node* father)
	{
		Node* subR = father->_right;
		Node* subRL = subR->_left;

		father->_right = subRL;
		if (subRL)
		{
			subRL->_father = father;
		}
		subR->_left = father;
		Node* grandfather = father->_father;
		father->_father = subR;
		if (grandfather == nullptr)
		{
			subR->_father = nullptr;
			_root = subR;
		}
		else
		{
			if (grandfather->_left == father)
			{
				grandfather->_left = subR;
			}
			else {
				grandfather->_right = subR;
			}
			subR->_father = grandfather;
		}
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}


	// 检查要点1：不能出现连红，通过father判断孩子不方便（有两个孩子，且不知道孩子在不在）但是孩子判断gather很方便
	// 检查要点2：路径上的黑色节点的数量要相同，这里通过递归
	// 递归里面有形参 -> 每个栈帧里面都会有一个（每次传入的值不同，栈帧里的就不同）
	bool IsBalance()
	{
		if (_root == nullptr)
		{
			return true;
		}
		if (_root->_color == red)
		{
			return false;
		}
		int refNum = 0; // 我们先随便走一条路径得到这个refNum
		Node* cur = _root;
		while (cur)
		{
			if (cur->_color == black)
				refNum++;
			cur = cur->_left;
		}
		return Check(_root, 0, refNum);
	}


private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	bool Check(Node* root, int blackNum, const int refNum)
	{
		// refNum 是参考值（是任意一条路径的黑色节点个数）
		if (root == nullptr) // 这条路走完了
		{
			if (blackNum != refNum)
			{
				cout << "路径黑色节点个数不同" << endl;
				return false;
			}
			return true;
		}
		if (root->_color == red && root->_father->_color == red)
		{
			cout << "出现连红" << endl;
			return false;
		}
		if (root->_color == black)
			blackNum++;
		return Check(root->_left, blackNum, refNum) && Check(root->_right, blackNum, refNum);
	}

private:
	Node* _root = nullptr;
};