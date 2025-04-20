// 基于红黑树实现的set
#pragma once
#include"RBTree.h"
#include<iostream>
using namespace std;



namespace tr
{
	template<class K>
	class set
	{
	public:
		struct setKeyOfVal
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
		typedef typename RBTree<K, const K, setKeyOfVal>::Iterator iterator; 
		typedef typename RBTree<K, const K, setKeyOfVal>::ConstIterator const_iterator;

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

		pair<iterator, bool> insert(const K& key)
		{
			return _t.Insert(key);
		}

		iterator find(const K& key)
		{
			return _t.Find(key);
		}

	private:
		RBTree<K, const K,setKeyOfVal> _t;
	};
}