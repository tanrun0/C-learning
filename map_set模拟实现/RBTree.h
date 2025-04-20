#pragma once
#include<iostream>
using namespace std;
enum Color // ö�����ͣ�colorֻ��ȡֵred��black
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


template<class V, class Ref, class Ptr> // Ref �� Ptr Ϊ�����set��map��ͬ��ֵ�����ͣ�����Ҳ�÷���
struct RBTreeIterator
{
	typedef RBTreeNode<V> Node;
	typedef RBTreeIterator<V, Ref, Ptr> Self;

	Node* _node;
	Node* _root; // Ϊ�˽��end()--��endΪ��ָ�룬�ҵ�������û�����Ľڵ������

	RBTreeIterator(Node* node, Node* root) // ÿ�������������һ����ǰ������λ�õ�ָ���һ�����ڵ�ָ��
		:_node(node)
		, _root(root)
	{}


	Self& operator++()
	{
		if (_node->_right)
		{
			Node* leftmost = _node->_right;
			while (leftmost && leftmost->_left) // ����������������
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
		return *this; // ���ص���ԭ���ĵ���������Ϊ�Ǻ���++
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



template<class K, class V, class KeyOfVal> // KeyOfV�����Ƿº�����������ȡ��ͬ���͵�Val�ļ�
class RBTree
{
public:
	typedef RBTreeNode<V> Node;
	typedef RBTreeIterator<V, V&, V*> Iterator;
	typedef RBTreeIterator<V, const V&, const V*> ConstIterator; // ��ģ������ֱ�ӹ涨const���������޷��޸�

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
			else // ������һ���Ľڵ�
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
					cur = grandfather; // ���ϼ�������
					father = cur->_father;
				}
				else // uncle �����ڻ���uncleΪ�� 
				{
					if (father->_left == cur) // ��һ��ֱ��
					{
						father->_color = black;
						grandfather->_color = red;
						RotateR(grandfather); // father����ߣ�Ҫ�ҵ���
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
					cur = grandfather; // ���ϼ�������
					father = cur->_father;
				}
				else // uncle �����ڻ���uncleΪ�� 
				{
					if (father->_right == cur) // ��һ��ֱ��
					{
						father->_color = black;
						grandfather->_color = red;
						RotateL(grandfather); // father����ߣ�Ҫ�ҵ���
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
		_root->_color = black; // �����պ�grandfather�������Ժ󣬳�Ϊ�˸��ڵ���Ϊ��
		cout << "����ɹ�" << endl;
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
		int refNum = 0; // �����������һ��·���õ����refNum
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
		// refNum �ǲο�ֵ��������һ��·���ĺ�ɫ�ڵ������
		if (root == nullptr) // ����·������
		{
			if (blackNum != refNum)
			{
				cout << "·����ɫ�ڵ������ͬ" << endl;
				return false;
			}
			return true;
		}
		if (root->_color == red && root->_father->_color == red)
		{
			cout << "��������" << endl;
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