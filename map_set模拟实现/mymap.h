// 基于红黑树实现的map
#pragma once
#include"RBTree.h"
#include<iostream>
using namespace std;

namespace tr
{
	template<class K, class V> // 这个是map的模板，对应RBTree是：_Key : K , _Val : pair<K, V>
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
		typedef typename RBTree<K, pair<const K, V>, mapKeyOfVal>:: Iterator iterator; // 从类里面取另一个类的成员，要指明清楚
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
		RBTree<K, pair<const K, V>, mapKeyOfVal> _t; // 底层就是RBTree
	};
}

