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


// ����һ����string����ʼ���ַ�������
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

	// ���������٣��ú��������
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

	// �������ڵ��������һ���ⲿ��������
	void BT_Size(BTNode* root, int& size) {
		if (!root) { return; }
		size++;
		BT_Size(root->_left, size);
		BT_Size(root->_right, size);
	}

	// ������Ҷ�ӽڵ����
	int BT_LeafSize(BTNode* root) {
		if (!root) { return 0; }
		if (!root->_left && !root->_right) { return 1; }
		return BT_LeafSize(root->_left) + BT_LeafSize(root->_right);
	}

	// ��������k��ڵ����
	// ��rootΪ���ĵ�k��ڵ���� = root���������ĵ�k-1��ڵ���� + root���������ĵ�k-1��ڵ����
	int BT_LevelKSize(BTNode* root, int k)
	{
		if (!root || k < 1) return 0;
		if (k == 1) { return 1; }
		return BT_LevelKSize(root->_left, k - 1) + BT_LevelKSize(root->_right, k - 1);
	}

	// ����������ֵΪx�Ľڵ㣬����������������ҵ��˾�ֱ�ӷ���
	BTNode* BT_Find(BTNode* root, char x)
	{
		if (!root) { return nullptr; }
		if (root->_data == x) { return root; }
		BTNode* f = BT_Find(root->_left, x); // ������������
		if (!f){ return f; } // ����ҵ���
		f = BT_Find(root->_right, x);
		if (!f) { return f; }
		return nullptr;
	}

	// ������ǰ����� 
	void BT_PrevOrder(BTNode* root)
	{
		if (!root) { return; }
		cout << root->_data << ' ';
		BT_PrevOrder(root->_left);
		BT_PrevOrder(root->_right);
	}

	// ����������ⲻ�ǵݹ飬�ö��У���һ�����һ�㣬���������еĽڵ�ĺ�������У�
	// ������ָ����ӣ������ȿ��Եõ�Ԫ�أ�Ҳ�����ҵ�����
	void BT_LevelOrder(BTNode* root)
	{
		queue<BTNode*> q;
		if (root) { q.push(root); }
		while (!q.empty())
		{
			BTNode* front = q.front(); // �ȼ�¼��ͷԪ��
			cout << front->_data << ' ';
			q.pop(); // ɾ����ͷԪ��
			if (front->_left) { q.push(front->_left); }
			if (front->_right) { q.push(front->_right); }// �Ѷ�ͷԪ�صķǿ����Һ��������
		}
	}

	// �ж϶������Ƿ�����ȫ������
	// ���������������Ҳ��¼�սڵ㣬���սڵ㱻pop��ȥ��ʱ���ж϶������滹��û�������ǿսڵ㣬��������������ȫ������
	// �����ǿսڵ�ĸ��ڵ�Ҳ�Ƿǿգ����սڵ㱻pop��ȥ��ʱ��������ڵ��类pop��ȥ�ˣ���������������
	int BinaryTreeComplete(BTNode* root)
	{
		queue<BTNode*> q;
		if (root) { q.push(root); }
		while (!q.empty())
		{
			BTNode* front = q.front();
			if (front == nullptr) { break; } // �����սڵ��˳�
			q.pop();
			q.push(front->_left);
			q.push(front->_right);
		}
		while (!q.empty())
		{
			BTNode* front = q.front();
			if (front) // �ǿ�
			{
				return false;
			}
			q.pop();
		}
		return true;
	}

	BTNode* root;
};

