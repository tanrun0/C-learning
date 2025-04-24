#pragma once
#include"HashTable.h"

template<class K, class Hash = HashFunc<K>>
class unordered_set
{
	struct SetKOfV
	{
		const K& operator()(const K& key) // 这个pair<K, V>对应的是模板中的泛型 T
		{
			return key;
		}
	};

public:

	typedef typename Hash_bucket::HashTable<K, const K, SetKOfV, Hash>::Iterator iterator;
	typedef typename Hash_bucket::HashTable<K, const K, SetKOfV, Hash>::ConstIterator const_iterator;

	iterator begin()
	{
		return _ht.Begin();
	}

	iterator end()
	{
		return _ht.End();
	}

	const_iterator begin() const
	{
		return _ht.Begin();
	}

	const_iterator end() const
	{
		return _ht.End();
	}

	pair<iterator, bool> insert(const K& key)
	{
		return _ht.Insert(key);
	}

	iterator Find(const K& key)
	{
		return _ht.Find(key);
	}

	bool Erase(const K& key)
	{
		return _ht.Erase(key);
	}

private:
	Hash_bucket::HashTable<K, const K, SetKOfV, Hash> _ht; // HashTable的第二个模板参数要求const，这里就要传const
};




void test_set()
{
	unordered_set<int> s;
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 3, 3, 15 };
	for (auto e : a)
	{
		s.insert(e);
	}

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
	unordered_set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		// 不⽀持修改
		//*it += 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}