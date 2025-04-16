#pragma once
#include<iostream>
using namespace std;
// 模拟实现搜索二叉树

//namespace tr
//{
//	struct TreeNode
//	{
//		TreeNode() = default; // 表明要生成默认构造函数
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
//				else // 不接受相等的元素
//				{
//					return false;
//				}
//			}
//			// 找到要插入的位置了，但是此时还要判断是链接到父节点的左边还是右边
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
//			Print_1(_root); // 因为外面没办法访问_root，所以再封一层
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
//			// 删除大体上分三种情况：1、删除叶子，2、删除单孩子节点，3、删除双孩子节点
//			if (!_root) { return false; }
//			TreeNode* erase = _root;
//			TreeNode* eraseparent = _root;
//
//			while (erase)
//			{
//				if (erase->_val > val)
//				{
//					eraseparent = erase; // 记录父亲节点
//					erase = erase->_left;
//				}
//				else if (erase->_val < val)
//				{
//					eraseparent = erase;
//					erase = erase->_right;
//				}
//				else // 找到要删除的节点
//				{
//					if (!erase->_left || !erase->_right) // 处理 叶子节点 和 单孩子节点的情况
//					{
//						if (erase == _root) // 特殊处理要删除的节点为根节点时
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
//						else if (eraseparent->_left == erase) // 代表要删除的节点是父节点的左孩子
//						{
//							if (erase->_left) // 确定要删除的节点的孩子是哪一个
//							{
//								eraseparent->_left = erase->_left; // 然后把它的孩子交给父亲
//							}
//							else
//							{   // 不是左孩子，就是右。
//								// 同时处理：面对叶子节点，就随便取左右孩子链接上去
//								eraseparent->_left = erase->_right; // 被删除节点为父节点的左孩子，且有右孩子，所以把被删除节点的右孩子给父节点的左孩子
//							}
//						}
//						else
//						{
//							if (erase->_left) // 确定要删除的节点的孩子是哪一个
//							{
//								eraseparent->_right = erase->_left; // 然后把它的孩子交给父亲
//							}
//							else
//							{ // 不是左孩子，就是右。
//								// 同时处理：面对叶子节点，就随便取左右孩子链接上去
//								eraseparent->_right = erase->_right;
//							}
//						}
//						delete erase; // delete nullptr 不会出问题
//						return true;
//					}
//
//					// 处理双节点情况（这里选择去左子树找最大节点）
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
//						// 找出来的最大节点一定是叶子节点
//						erase->_val = replace->_val; // 替换
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



// 实现 key ：value 场景
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
					else // 相同元素不插入
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
					if (!erase->_left || !erase->_right) // 叶子节点或单孩子节点
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

					else // 处理双孩子节点
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
