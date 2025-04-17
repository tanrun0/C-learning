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
		// 找到要插入的位置了，插入以后，要判断平衡因子的变化，如果出现不平衡的，需要旋转
		if (parent->_kv.first < kv.first) {
			parent->_right = cur;
		}
		else 
		{
			parent->_left = cur;
		}

		cur->_parent = parent;
		while (parent) {
			// 更新父节点平衡因子
			if (parent->_right == cur) {
				parent->_bf++;
			}
			else {
				parent->_bf--;
			}

			// 判断平衡因子
			if (parent->_bf == 0) {
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1) {
				cur = parent;
				parent = parent->_parent; // 往上传递
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				if (parent->_bf == -2 && cur->_bf == -1) // 左边高
				{
					RoteR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RoteL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1) // parent左边高，孩子右边高
				{
					RoteLR(parent); // 左右双旋，因为先旋的是孩子
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
				assert(false); // 出现非正常的平衡因子的时候，代表树有问题，直接终止
			}
		}
		return true;
	}

	// 画图出来好理解
	void RoteR(Node* parent)  // 右单旋
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;

		// 一，将 SubLR 连上 parent（1，parent要连接上SubLR；2，SubLR的parent需要更改）
		parent->_left = SubLR;
		if (SubLR) // SubLR 可能是 nullptr
		{
			SubLR->_parent = parent;
		}

		// 二，将 parent 连上 SubL （1，SubL连接上parent；2，parent的parent修改；3，SubL 的 parent要改；4，parent的parent的孩子连接要修改）
		// （分成：1, SubL改后成根节点了；2，SubL改后还是子树）
		Node* Pparent = parent->_parent;
		SubL->_right = parent;
		parent->_parent = SubL;

		if (parent == _root) // 如果SubL 变成根节点了
		{
			_root = SubL;
			SubL->_parent = nullptr;
		}
		else // 别忘记更改 Pparent的孩子的指向
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

	void RoteL(Node* parent) // 左单旋
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

	// 双旋，其实就是两个单旋，因为单选是同侧高，但是双选是一个左边高，一个右边高
	// 所以判断标准就是 parent 的平衡因子和 parent 的孩子的平衡因子是否同号
	// 比如：parent：左高，parent的左孩子右高，则先对左孩子左单旋，再对parent进行右单旋（这就是左右单旋转）
	// 双旋代码的难点在于：平衡因子的变化（因为左孩子的右边高的时候，也有多种插入方法）
	void RoteLR(Node* parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
		int bf = SubLR->_bf;
		
		// 两次单旋
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

		// 两次单旋
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
		// 空树也是AVL树
		if (nullptr == root)
			return true;
		// 计算pRoot结点的平衡因子：即pRoot左右子树的高度差
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight;

		// 如果计算出的平衡因子与pRoot的平衡因子不相等，或者
		// pRoot平衡因子的绝对值超过1，则一定不是AVL树
		if (abs(diff) >= 2)
		{
			cout << root->_kv.first << "高度差异常" << endl;
			return false;
		}

		if (root->_bf != diff)
		{
			cout << root->_kv.first << "平衡因子异常" << endl;
			return false;
		}

		// pRoot的左和右如果都是AVL树，则该树一定是AVL树
		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
	}
private:
	Node* _root = nullptr;
};
