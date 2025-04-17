#pragma once

#include<iostream>
#include<assert.h>
using namespace std;

template<class K, class V>
struct AVLTREENode
{
	pair<K, V> _kv;
	AVLTREENode<K, V>* _left;
	AVLTREENode<K, V>* _right;
	AVLTREENode<K, V>* _parent;
	int _bf;

	AVLTREENode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{}
};

template<class K, class V>
class AVLTREE
{
	typedef AVLTREENode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr) 
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first) // ?
			{ 
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first) 
			{
				parent = cur;
				cur = cur->_left;
			}
			else 
			{
				return false;
			}
		}

		cur = new Node(kv);
		// �ҵ�Ҫ�����λ���ˣ������Ժ�Ҫ�ж�ƽ�����ӵı仯��������ֲ�ƽ��ģ���Ҫ��ת
		if (parent->_kv.first < kv.first) {
			parent->_right = cur;
		}
		else 
		{
			parent->_left = cur;
		}

		cur->_parent = parent;
		while (parent) {
			// ���¸��ڵ�ƽ������
			if (parent->_right == cur) {
				parent->_bf++;
			}
			else {
				parent->_bf--;
			}

			// �ж�ƽ������
			if (parent->_bf == 0) {
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1) {
				cur = parent;
				parent = parent->_parent; // ���ϴ���
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				if (parent->_bf == -2 && cur->_bf == -1) // ��߸�
				{
					RoteR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RoteL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1) // parent��߸ߣ������ұ߸�
				{
					RoteLR(parent); // ����˫������Ϊ�������Ǻ���
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RoteRL(parent);
				}
				else
				{
					assert(false);
				}
				break;
			}
			else
			{
				assert(false); // ���ַ�������ƽ�����ӵ�ʱ�򣬴����������⣬ֱ����ֹ
			}
		}
		return true;
	}

	// ��ͼ���������
	void RoteR(Node* parent)  // �ҵ���
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;

		// һ���� SubLR ���� parent��1��parentҪ������SubLR��2��SubLR��parent��Ҫ���ģ�
		parent->_left = SubLR;
		if (SubLR) // SubLR ������ nullptr
		{
			SubLR->_parent = parent;
		}

		// ������ parent ���� SubL ��1��SubL������parent��2��parent��parent�޸ģ�3��SubL �� parentҪ�ģ�4��parent��parent�ĺ�������Ҫ�޸ģ�
		// ���ֳɣ�1, SubL�ĺ�ɸ��ڵ��ˣ�2��SubL�ĺ���������
		Node* Pparent = parent->_parent;
		SubL->_right = parent;
		parent->_parent = SubL;

		if (parent == _root) // ���SubL ��ɸ��ڵ���
		{
			_root = SubL;
			SubL->_parent = nullptr;
		}
		else // �����Ǹ��� Pparent�ĺ��ӵ�ָ��
		{
			if (Pparent->_left == parent)
			{
				Pparent->_left = SubL;
			}
			else {
				Pparent->_right = SubL;
			}
			SubL->_parent = Pparent;
		}

		SubL->_bf = parent->_bf = 0;
	}

	void RoteL(Node* parent) // ����
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;

		parent->_right = SubRL;
		if (SubRL)
		{
			SubRL->_parent = parent;
		}
		Node* Pparent = parent->_parent;
		SubR->_left = parent;
		parent->_parent = SubR;

		if (Pparent == nullptr)
		{
			_root = SubR;
			SubR->_parent = nullptr;
		}
		else
		{
			if (Pparent->_left == parent)
			{
				Pparent->_left = SubR;
			}
			else
			{
				Pparent->_right = SubR;
			}
			SubR->_parent = Pparent;
		}

		SubR->_bf = parent->_bf = 0;
	}

	// ˫������ʵ����������������Ϊ��ѡ��ͬ��ߣ�����˫ѡ��һ����߸ߣ�һ���ұ߸�
	// �����жϱ�׼���� parent ��ƽ�����Ӻ� parent �ĺ��ӵ�ƽ�������Ƿ�ͬ��
	// ���磺parent����ߣ�parent�������Ҹߣ����ȶ������������ٶ�parent�����ҵ�������������ҵ���ת��
	// ˫��������ѵ����ڣ�ƽ�����ӵı仯����Ϊ���ӵ��ұ߸ߵ�ʱ��Ҳ�ж��ֲ��뷽����
	void RoteLR(Node* parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
		int bf = SubLR->_bf;
		
		// ���ε���
		RoteL(SubL);
		RoteR(parent);

		if (bf == 0)
		{
			SubL->_bf = 0;
			SubLR->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			SubL->_bf = 0;
			SubLR->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1)
		{
			SubL->_bf = -1;
			SubLR->_bf = 0;
			parent->_bf = 0;
		}
		else {
			assert(false);
		}
	}

	void RoteRL(Node* parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		int bf = SubRL->_bf;

		// ���ε���
		RoteR(SubR);
		RoteL(parent);

		if (bf == 0)
		{
			SubR->_bf = 0;
			SubRL->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			SubR->_bf = 1;
			SubRL->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 1)
		{
			SubR->_bf = 0;
			SubRL->_bf = 0;
			parent->_bf = -1;
		}
		else {
			assert(false);
		}
	}


	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	int Height()
	{
		return _Height(_root);
	}

	int Size()
	{
		return _Size(_root);
	}

	bool IsBalanceTree()
	{
		return _IsBalanceTree(_root);
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
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

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	int _Size(Node* root)
	{
		if (root == nullptr)
			return 0;

		return _Size(root->_left) + _Size(root->_right) + 1;
	}

	bool _IsBalanceTree(Node* root)
	{
		// ����Ҳ��AVL��
		if (nullptr == root)
			return true;
		// ����pRoot����ƽ�����ӣ���pRoot���������ĸ߶Ȳ�
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight;

		// ����������ƽ��������pRoot��ƽ�����Ӳ���ȣ�����
		// pRootƽ�����ӵľ���ֵ����1����һ������AVL��
		if (abs(diff) >= 2)
		{
			cout << root->_kv.first << "�߶Ȳ��쳣" << endl;
			return false;
		}

		if (root->_bf != diff)
		{
			cout << root->_kv.first << "ƽ�������쳣" << endl;
			return false;
		}

		// pRoot��������������AVL���������һ����AVL��
		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
	}
private:
	Node* _root = nullptr;
};
