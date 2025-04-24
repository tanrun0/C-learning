#pragma once
#include"HashTable.h"

template<class K, class V, class Hash = HashFunc<K>>
class unordered_map
{
	struct MapKOfV
	{
		const K& operator()(const pair<K, V>& kv) // 这个pair<K, V>对应的是模板中的泛型 T
		{
			return kv.first;
		}
	};
public:


	typedef typename Hash_bucket::HashTable<K, pair<const K, V>, MapKOfV, Hash>::Iterator iterator;
	typedef typename Hash_bucket::HashTable<K, pair<const K, V>, MapKOfV, Hash>::ConstIterator const_iterator;

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

	pair<iterator, bool> insert(const pair<K, V>& kv)
	{
		return _ht.Insert(kv);
	}

	iterator Find(const K& key)
	{
		return _ht.Find(key);
	}

	bool Erase(const K& key)
	{
		return _ht.Erase(key);
	}
	
	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _ht.Insert(make_pair(key, V())); // 这个V就是值，如果是内置类型也会生成匿名对象，默认构造
		return ret.first->second; // ret.fitst拿到的是迭代器，迭代器调->得到的是_node内pair<K, V>的指针，然后->second得到的是V
	}

private:
	Hash_bucket::HashTable<K, pair<const K, V>, MapKOfV, Hash> _ht;
};


void test_map()
{
	unordered_map<string, string> dict;
	dict.insert({ "sort", "排序" });
	dict.insert({ "left", "左边" });
	dict.insert({ "right", "右边" });
	dict["left"] = "左边，剩余";
	dict["insert"] = "插入";
	dict["string"];
	unordered_map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		it->second += 'x';
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
}
