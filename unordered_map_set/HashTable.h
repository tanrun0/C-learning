#pragma once
#include<vector>
#include<iostream>
#include<string>
using namespace std;


template<class K>
struct HashFunc // 要用struct不然访问不了operator()
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

// 模板特化，当Key为string的时候优先调用这个特化的模板来实例化这个类
template<>
struct HashFunc<string>
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (auto e : key) // 一种把string转换成int的算法
		{
			hash *= 131;
			hash += e;
		}
		return hash;
	}
};

namespace Hash_bucket
{

	template<class T> // 这里的T，对于set是key，对于map是pair<K, V>
	struct HashNode // 节点
	{
		T _data;
		HashNode<T>* _next;

		HashNode(T data)
			:_data(data)
			, _next(nullptr)
		{
		}
	};
	// 前置声明（因为HTIterator依赖于HashTable，但是HashTable又定义在后面）
	// 注意类模板的前置声明要带上模板的参数列表
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	template<class K, class T, class Ptr, class Ref, class KOfT, class Hash> // Ptr 和 Ref 只是为了方便书写
	struct HTIterator
	{
		typedef HashNode<T> Node;
		typedef HTIterator<K, T, Ptr, Ref, KOfT, Hash> Self;



		// operator++操作：如果光有一个节点，把一个桶遍历完了，下一个桶就找不到了，所以我们需要利用哈希表来找
		Node* _node; // 指向当前位置的指针
		const HashTable<K, T, KOfT, Hash>* _pht; // 哈希表，用于找下一个桶链
		
		HTIterator(Node* node, const HashTable<K, T, KOfT, Hash>* pht)
			:_node(node)
			, _pht(pht)
		{ }

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &(_node->_data);
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}

		// 单向迭代器，只支持++
		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else // 这个桶走完了，找下一个桶
			{
				KOfT kot;
				Hash hs;
				size_t hashi = hs(kot(_node->_data)) % _pht->_table.size(); // -> 的优先级高于 .
				hashi++;

				while (hashi < _pht->_table.size())
				{
					if (_pht->_table[hashi] != nullptr)
					{
						break;
					}
					hashi++;
				}
				// while退出有两种情况
				if (hashi == _pht->_table.size())
				{
					_node = nullptr;
				}
				else
				{
					_node = _pht->_table[hashi];
				}

			}
			return *this;
		}

	};


	// KOfV是由set和map传进来的，Hash(key to int)是定义在哈希表类外面的（因为在外面，用户可以根据自己的key的类型传入不同的函数，在里面就写死了，要改只能进类里面改）
	template<class K, class T, class KOfT, class Hash>
	class HashTable
	{

		template<class K, class T, class Ptr, class Ref, class KOfT, class Hash>
		friend struct HTIterator; // 友元声明
		typedef HashNode<T> Node;

	public:
		typedef HTIterator<K, T, T*, T&, KOfT, Hash> Iterator;
		typedef HTIterator<K, T, const T*, const T&, KOfT, Hash> ConstIterator;


		Iterator End()
		{
			return Iterator(nullptr, this);
		}

		Iterator Begin() // 具体到map和set还会把Iterator再封一遍
		{
			// 找第一个桶的第一个节点
			if (_n == 0)
			{
				return End();
			}
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return Iterator(cur, this); // 接受当前节点的指针和整个哈希表的指针
				}
			}

			return End();
		}

		ConstIterator End() const
		{
			return ConstIterator(nullptr, this);
		}

		ConstIterator Begin() const // 具体到map和set还会把Iterator再封一遍
		{
			// 找第一个桶的第一个节点
			if (_n == 0)
			{
				return End();
			}
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return ConstIterator(cur, this); // 接受当前节点的指针和整个哈希表的指针
				}
			}

			return End();
		}

	public:

		HashTable()
		{
			// _table.size()初始时为 0，即会进入_stl...找一个大于0的素数用来初始化
			_table.resize(__stl_next_prime(static_cast<unsigned int>(_table.size())), nullptr); // static_cast<unsigned int>(_table.size())) 把返回的size_t转换成unsigned int
		}

		~HashTable()
		{
			// 将每一个桶释放
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i]; // 得到当前桶的第一个节点
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
		}


		pair<Iterator, bool> Insert(const T& data)
		{
			KOfT kot;
			Hash hs;
			Iterator it = Find(kot(data));
			if (it != End()) // 找到了
			{
				return make_pair(it, false) ; // 不插入相同元素
			}


			if (_n == _table.size()) // 负载因子为 1 ,扩容
			{
				// 创建一个新的Table然后把元素移动过去
				// 直接已走是因为：swap以后，函数结束，临时变量被销毁，但由于存的是Node*（内置类型），没有自动调用析构，就无法释放Node*链的这一块空间 
				vector<Node*> newtable(__stl_next_prime(static_cast<unsigned int>(_table.size() + 1)), nullptr); // 找比当前_table.size()大的素数
				for (size_t i = 0; i < _table.size(); i++) // 遍历所有桶的链
				{
					Node* cur = _table[i]; 
					while (cur)
					{
						Node* next = cur->_next;
						size_t newhashi = hs(kot(cur->_data)) % newtable.size();
						// 头插到新表
						cur->_next = newtable[newhashi];
						newtable[newhashi] = cur;
						cur = next;
					}
					_table[i] = nullptr; // 再把原来桶的指针置为空
				}
				swap(_table, newtable);
			}
			size_t hashi = hs(kot(data)) % _table.size(); // 映射哈希地址
			
			// 新节点头插
			Node* newnode = new Node(data);
			newnode->_next = _table[hashi];
			_table[hashi] = newnode;
			++_n;

			return make_pair(Iterator(newnode, this), true);
		}

		Iterator Find(const K& key)
		{
			KOfT kot;
			Hash hs;
			size_t hashi = hs(key) % (_table.size()); 
			Node* cur = _table[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return Iterator(cur, this);
				}
				cur = cur->_next;
			}

			return End(); // 没找到
		}

		bool Erase(const K& key)
		{
			KOfT kot;
			Hash hs;
			size_t hashi = hs(key) % (_table.size());
			Node* prev = nullptr;
			Node* cur = _table[hashi];
			while (cur)
			{
				if (hs(kot(cur->_data)) == key) // 找到了
				{
					if (prev == nullptr) // 如果要删除的节点为头结点
					{
						_table[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					--_n;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}

			return false;
		}




	private:
		inline unsigned long __stl_next_prime(unsigned long n) // 获取下一次扩容的容量大小
		{
			static const int __stl_num_primes = 28;
			static const unsigned long __stl_prime_list[__stl_num_primes] =
			{
				53, 97, 193, 389, 769,
				1543, 3079, 6151, 12289, 24593,
				49157, 98317, 196613, 393241, 786433,
				1572869, 3145739, 6291469, 12582917, 25165843,
				50331653, 100663319, 201326611, 402653189, 805306457,
				1610612741, 3221225473, 4294967291
			};
			const unsigned long* first = __stl_prime_list;
			const unsigned long* last = __stl_prime_list +
				__stl_num_primes;
			const unsigned long* pos = lower_bound(first, last, n);
			return pos == last ? *(last - 1) : *pos;
		}



	private:
		vector<Node*> _table;
		size_t _n = 0;
	};

}