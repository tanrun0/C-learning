#pragma once
#include<iostream>
using namespace std;
// ģ��ʵ������������

//namespace tr
//{
//	struct TreeNode
//	{
//		TreeNode() = default; // ����Ҫ����Ĭ�Ϲ��캯��
//		TreeNode(int val)
//			:_val(val)
//			, _left(nullptr)
//			, _right(nullptr)
//		{
//		}
//
//		int _val;
//		TreeNode* _left;
//		TreeNode* _right;
//	};
//	class BSTREE
//	{
//	public:
//		BSTREE() 
//			:_root(nullptr)
//		{ }
//
//		bool Insert(int val)
//		{
//			TreeNode* newnode = new TreeNode(val);
//			if (_root == nullptr)
//			{
//				_root = newnode;
//				return true;
//			}
//
//			TreeNode* cur = _root;
//			TreeNode* parent = nullptr;
//			while (cur)
//			{
//				if (cur->_val < val)
//
//				{
//					parent = cur;
//					cur = cur->_right;
//
//				}
//				else if (cur->_val > val)
//				{
//					parent = cur;
//					cur = cur->_left;
//
//				}
//				else // ��������ȵ�Ԫ��
//				{
//					return false;
//				}
//			}
//			// �ҵ�Ҫ�����λ���ˣ����Ǵ�ʱ��Ҫ�ж������ӵ����ڵ����߻����ұ�
//			if (parent->_val < val)
//				parent->_right = newnode;
//			else
//				parent->_left = newnode;
//
//			return true;
//		}
//
//		void Print_1(TreeNode* _root)
//		{
//			if (!_root)
//				return;
//			Print_1(_root->_left);
//			cout << _root->_val << ' ';
//			Print_1(_root->_right);
//		}
//
//		void Print()
//		{
//			Print_1(_root); // ��Ϊ����û�취����_root�������ٷ�һ��
//			cout << endl;
//		}
//
//		TreeNode* Find(const int& val)
//		{
//			TreeNode* cur = _root;
//			while (cur)
//			{
//				if (cur->_val == val)
//				{
//					return cur;
//				}
//				else if (cur->_val > val)
//				{
//					cur = cur->_left;
//				}
//				else
//				{
//					cur = cur->_right;
//				}
//			}
//			return nullptr;
//		}
//
//		bool Erase(const int& val)
//		{
//			// ɾ�������Ϸ����������1��ɾ��Ҷ�ӣ�2��ɾ�������ӽڵ㣬3��ɾ��˫���ӽڵ�
//			if (!_root) { return false; }
//			TreeNode* erase = _root;
//			TreeNode* eraseparent = _root;
//
//			while (erase)
//			{
//				if (erase->_val > val)
//				{
//					eraseparent = erase; // ��¼���׽ڵ�
//					erase = erase->_left;
//				}
//				else if (erase->_val < val)
//				{
//					eraseparent = erase;
//					erase = erase->_right;
//				}
//				else // �ҵ�Ҫɾ���Ľڵ�
//				{
//					if (!erase->_left || !erase->_right) // ���� Ҷ�ӽڵ� �� �����ӽڵ�����
//					{
//						if (erase == _root) // ���⴦��Ҫɾ���Ľڵ�Ϊ���ڵ�ʱ
//						{
//							if (erase->_left)
//							{
//								_root = erase->_left;
//							}
//							else
//							{
//								_root = erase->_right;
//							}
//						}
//						else if (eraseparent->_left == erase) // ����Ҫɾ���Ľڵ��Ǹ��ڵ������
//						{
//							if (erase->_left) // ȷ��Ҫɾ���Ľڵ�ĺ�������һ��
//							{
//								eraseparent->_left = erase->_left; // Ȼ������ĺ��ӽ�������
//							}
//							else
//							{   // �������ӣ������ҡ�
//								// ͬʱ�������Ҷ�ӽڵ㣬�����ȡ���Һ���������ȥ
//								eraseparent->_left = erase->_right; // ��ɾ���ڵ�Ϊ���ڵ�����ӣ������Һ��ӣ����԰ѱ�ɾ���ڵ���Һ��Ӹ����ڵ������
//							}
//						}
//						else
//						{
//							if (erase->_left) // ȷ��Ҫɾ���Ľڵ�ĺ�������һ��
//							{
//								eraseparent->_right = erase->_left; // Ȼ������ĺ��ӽ�������
//							}
//							else
//							{ // �������ӣ������ҡ�
//								// ͬʱ�������Ҷ�ӽڵ㣬�����ȡ���Һ���������ȥ
//								eraseparent->_right = erase->_right;
//							}
//						}
//						delete erase; // delete nullptr ���������
//						return true;
//					}
//
//					// ����˫�ڵ����������ѡ��ȥ�����������ڵ㣩
//					else
//					{
//						TreeNode* replaceparent = erase;
//						TreeNode* replace = erase->_left;
//						while (replace->_right)
//						{
//							replaceparent = replace;
//							replace = replace->_right;
//						}
//
//						// �ҳ��������ڵ�һ����Ҷ�ӽڵ�
//						erase->_val = replace->_val; // �滻
//						if (replaceparent->_left == replace)
//						{
//							replaceparent->_left = nullptr;
//						}
//						else
//						{
//							replaceparent->_right = nullptr;
//						}
//						delete replace;
//						return true;
//					}
//				}
//			}
//			return false;
//		}
//
//	private:
//		TreeNode* _root;
//	};
//}



// ʵ�� key ��value ����
namespace tr
{
	template<class K, class V>
	struct BSTreeNode
	{
		K _key;
		V _value;
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;

		BSTreeNode(const K& key, const V& value)
			:_key(key)
			,_value(value)
			,_left(nullptr)
			,_right(nullptr)
		{}
	};

	template<class K, class V>
	class BSTree
	{
		typedef BSTreeNode<K, V> Node;
	public:
		bool Insert(const K& key, const V& value)
		{
			Node* newnode = new Node(key, value);
			if (!_root)
			{
				_root = newnode;
			}
			else
			{
				Node* parent = nullptr;
				Node* cur = _root;
				while (cur)
				{
					if (cur->_key > key)
					{
						parent = cur;
						cur = cur->_left;
					}
					else if (cur->_key < key)
					{
						parent = cur;
						cur = cur->_right;
					}
					else // ��ͬԪ�ز�����
					{
						return false;
					}
				}
				if (parent->_key > key)
				{
					parent->_left = newnode;
				}
				else
				{
					parent->_right = newnode;
				}
			}
			return true;
		}

		Node* Find(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}
		bool Erase(const K& key)
		{
			if (!_root) { return false; }
			Node* eraseparent = nullptr;
			Node* erase = _root;

			while (erase)
			{
				if (erase->_key > key)
				{
					eraseparent = erase;
					erase = erase->_left;
				}
				else if (erase->_key < key)
				{
					eraseparent = erase;
					erase = erase->_right;
				}
				else 
				{
					if (!erase->_left || !erase->_right) // Ҷ�ӽڵ�򵥺��ӽڵ�
					{
						if (erase == _root)
						{
							if (erase->_left) {
								_root = erase->_left;
							}
							else {
								_root = erase->_right;
							}
						}

						else if (eraseparent->_left == erase)
						{
							if (erase->_left){
								eraseparent->_left = erase->_left;
							}
							else {
								eraseparent->_left = erase->_right;
							}
						}

						else {
							if (erase->_left) {
								eraseparent->_right = erase->left;
							}
							else {
								eraseparent->_right = erase->_right;
							}
						}
					delete erase;
					return true;
					}

					else // ����˫���ӽڵ�
					{
						Node* replaceparent = erase;
						Node* replace = erase->_left;
						while (replace->_right)
						{
							replaceparent = replace;
							replace = replace->_right;
						}
						erase->_key = replace->_key;
						erase->_value = replace->_value;
						if (replaceparent->_left == replace){
							replaceparent->_left == nullptr;
						}
						else {
							replaceparent->_right == nullptr;
						}
						delete replace;
						return true;
					}
				}
			}
			return false;
		}
		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << ": " << root->_value;
			_InOrder(root->_right);
		}
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}
	private:
		Node* _root = nullptr;
	};
}
