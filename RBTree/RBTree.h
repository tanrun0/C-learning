#pragma once
#include<iostream>
enum Color // ö�����ͣ�colorֻ��ȡֵred��black
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
			else // ������һ���Ľڵ�
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


	// ���Ҫ��1�����ܳ������죬ͨ��father�жϺ��Ӳ����㣨���������ӣ��Ҳ�֪�������ڲ��ڣ����Ǻ����ж�gather�ܷ���
	// ���Ҫ��2��·���ϵĺ�ɫ�ڵ������Ҫ��ͬ������ͨ���ݹ�
	// �ݹ��������β� -> ÿ��ջ֡���涼����һ����ÿ�δ����ֵ��ͬ��ջ֡��ľͲ�ͬ��
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

private:
	Node* _root = nullptr;
};