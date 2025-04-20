#pragma once
#include<iostream>
using namespace std;
enum Color // 枚举类型，color只能取值red和black
{
	red,
	black
};

template<class V>
struct RBTreeNode 
{
	V _data;
	RBTreeNode<V>* _left;
	RBTreeNode<V>* _right;
	RBTreeNode<V>* _father;
	Color _color;

	RBTreeNode(const V& data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _father(nullptr)
		, _color(red)
	{}
};


template<class V, class Ref, class Ptr> // Ref 和 Ptr 为了面对set和map不同的值的类型，这里也用泛型
struct RBTreeIterator
{
	typedef RBTreeNode<V> Node;
	typedef RBTreeIterator<V, Ref, Ptr> Self;

	Node* _node;
	Node* _root; // 为了解决end()--，end为空指针，且迭代器内没有树的节点的问题

	RBTreeIterator(Node* node, Node* root) // 每个迭代器里面存一个当前迭代器位置的指针和一个根节点指针
		:_node(node)
		, _root(root)
	{}


	Self& operator++()
	{
		if (_node->_right)
		{
			Node* leftmost = _node->_right;
			while (leftmost && leftmost->_left) // 有左子树才往左走
			{
				leftmost = leftmost->_left;
			}
			_node = leftmost;
		}
		else
		{
			Node* cur = _node;
			Node* father = _node->_father;
			while (father && father->_right == cur)
			{
				cur = father;
				father = father->_father;
			}
			_node = father;
		}
		return *this; // 返回的是原来的迭代器，因为是后置++
	}

	Self& operator--()
	{
		if (_node == nullptr) // end()
		{
			Node* rightmost = _root;
			while (rightmost && rightmost->_right)
			{
				rightmost = rightmost->_right;
			}
			_node = rightmost;
		}
		else if (_node->_left)
		{
			Node* rightmost = _node->_left;
			while (rightmost && rightmost->_right)
			{
				rightmost = rightmost->_right;
			}
			_node = rightmost;
		}
		else
		{
			Node* cur = _node;
			Node* father = cur->_father;
			while (father && father->_left == cur)
			{
				cur = father;
				father = father->_father;
			}
			_node = father;
		}
		return *this;
	}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &(_node->_data);
	}

	bool operator!= (const Self& s) const
	{
		return _node != s._node;
	}

	bool operator== (const Self& s) const
	{
		return _node == s._node;
	}
};



template<class K, class V, class KeyOfVal> // KeyOfV啊了是仿函数，用来获取不同类型的Val的键
class RBTree
{
public:
	typedef RBTreeNode<V> Node;
	typedef RBTreeIterator<V, V&, V*> Iterator;
	typedef RBTreeIterator<V, const V&, const V*> ConstIterator; // 在模板这里直接规定const，这样就无法修改

	Iterator Begin()
	{
		Node* leftmost = _root;
		while (leftmost && leftmost->_left)
		{
			leftmost = leftmost->_left;
		}
		return Iterator(leftmost, _root);
	}

	Iterator End()
	{
		return Iterator(nullptr, _root);
	}
	
	ConstIterator Begin() const
	{
		Node* leftmost = _root;
		while (leftmost && leftmost->_left)
		{
			leftmost = leftmost->_left;
		}
		return ConstIterator(leftmost, _root);
	}

	ConstIterator End() const
	{
		return ConstIterator(nullptr, _root);
	}

	RBTree() = default;
	~RBTree()
	{
		Destroy(_root);
		_root = nullptr;
	}

	pair<Iterator, bool> Insert(const V& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_color = black;
			return make_pair(Iterator(_root, _root), true);
		}
		Node* father = nullptr;
		Node* cur = _root;
		KeyOfVal kov;
		while (cur)
		{
			if (kov(cur->_data) < kov(data))
			{
				father = cur;
				cur = cur->_right;
			}
			else if (kov(cur->_data) > kov(data))
			{
				father = cur;
				cur = cur->_left;
			}
			else // 不插入一样的节点
			{
				return make_pair(Iterator(cur, _root), false);
			}
		}
		cur = new Node(data);
		Node* newnode = cur;
		cur->_color = red;
		cur->_father = father;
		if (kov(cur->_data) < kov(father->_data))
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
		return make_pair(Iterator(newnode, _root), true);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

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

	Iterator Find(const K& key)
	{
		Node* cur = _root;
		KeyOfVal kov;
		while (cur)
		{
			if (kov(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else if (kov(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else
			{
				return Iterator(cur, _root);
			}
		}

		return End();
	}


private:

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

	void Destroy(Node* root)
	{
		if (root == nullptr)
			return;
		Destroy(root->_left);
		Destroy(root->_right);
		delete root;
	}

private:
	Node* _root = nullptr;
};