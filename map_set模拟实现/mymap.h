// ���ں����ʵ�ֵ�map
#pragma once
#include"RBTree.h"
#include<iostream>
using namespace std;

namespace tr
{
	template<class K, class V> // �����map��ģ�壬��ӦRBTree�ǣ�_Key : K , _Val : pair<K, V>
	class map
	{
	public:
		struct mapKeyOfVal
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename RBTree<K, pair<const K, V>, mapKeyOfVal>:: Iterator iterator; // ��������ȡ��һ����ĳ�Ա��Ҫָ�����
		typedef typename RBTree<K, pair<const K, V>, mapKeyOfVal>:: ConstIterator const_iterator;

		iterator begin()
		{
			return _t.Begin();
		}

		iterator end()
		{
			return _t.End();
		}

		const_iterator begin() const
		{
			return _t.Begin();
		}

		const_iterator end() const
		{
			return _t.End();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

		iterator find(const K& key)
		{
			return _t.Find(key);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}

	private:
		RBTree<K, pair<const K, V>, mapKeyOfVal> _t; // �ײ����RBTree
	};
}

