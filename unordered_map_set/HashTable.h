#pragma once
#include<vector>
#include<iostream>
#include<string>
using namespace std;


template<class K>
struct HashFunc // Ҫ��struct��Ȼ���ʲ���operator()
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

// ģ���ػ�����KeyΪstring��ʱ�����ȵ�������ػ���ģ����ʵ���������
template<>
struct HashFunc<string>
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (auto e : key) // һ�ְ�stringת����int���㷨
		{
			hash *= 131;
			hash += e;
		}
		return hash;
	}
};

namespace Hash_bucket
{

	template<class T> // �����T������set��key������map��pair<K, V>
	struct HashNode // �ڵ�
	{
		T _data;
		HashNode<T>* _next;

		HashNode(T data)
			:_data(data)
			, _next(nullptr)
		{
		}
	};
	// ǰ����������ΪHTIterator������HashTable������HashTable�ֶ����ں��棩
	// ע����ģ���ǰ������Ҫ����ģ��Ĳ����б�
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	template<class K, class T, class Ptr, class Ref, class KOfT, class Hash> // Ptr �� Ref ֻ��Ϊ�˷�����д
	struct HTIterator
	{
		typedef HashNode<T> Node;
		typedef HTIterator<K, T, Ptr, Ref, KOfT, Hash> Self;



		// operator++�������������һ���ڵ㣬��һ��Ͱ�������ˣ���һ��Ͱ���Ҳ����ˣ�����������Ҫ���ù�ϣ������
		Node* _node; // ָ��ǰλ�õ�ָ��
		const HashTable<K, T, KOfT, Hash>* _pht; // ��ϣ����������һ��Ͱ��
		
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

		// �����������ֻ֧��++
		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else // ���Ͱ�����ˣ�����һ��Ͱ
			{
				KOfT kot;
				Hash hs;
				size_t hashi = hs(kot(_node->_data)) % _pht->_table.size(); // -> �����ȼ����� .
				hashi++;

				while (hashi < _pht->_table.size())
				{
					if (_pht->_table[hashi] != nullptr)
					{
						break;
					}
					hashi++;
				}
				// while�˳����������
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


	// KOfV����set��map�������ģ�Hash(key to int)�Ƕ����ڹ�ϣ��������ģ���Ϊ�����棬�û����Ը����Լ���key�����ʹ��벻ͬ�ĺ������������д���ˣ�Ҫ��ֻ�ܽ�������ģ�
	template<class K, class T, class KOfT, class Hash>
	class HashTable
	{

		template<class K, class T, class Ptr, class Ref, class KOfT, class Hash>
		friend struct HTIterator; // ��Ԫ����
		typedef HashNode<T> Node;

	public:
		typedef HTIterator<K, T, T*, T&, KOfT, Hash> Iterator;
		typedef HTIterator<K, T, const T*, const T&, KOfT, Hash> ConstIterator;


		Iterator End()
		{
			return Iterator(nullptr, this);
		}

		Iterator Begin() // ���嵽map��set�����Iterator�ٷ�һ��
		{
			// �ҵ�һ��Ͱ�ĵ�һ���ڵ�
			if (_n == 0)
			{
				return End();
			}
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return Iterator(cur, this); // ���ܵ�ǰ�ڵ��ָ���������ϣ���ָ��
				}
			}

			return End();
		}

		ConstIterator End() const
		{
			return ConstIterator(nullptr, this);
		}

		ConstIterator Begin() const // ���嵽map��set�����Iterator�ٷ�һ��
		{
			// �ҵ�һ��Ͱ�ĵ�һ���ڵ�
			if (_n == 0)
			{
				return End();
			}
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return ConstIterator(cur, this); // ���ܵ�ǰ�ڵ��ָ���������ϣ���ָ��
				}
			}

			return End();
		}

	public:

		HashTable()
		{
			// _table.size()��ʼʱΪ 0���������_stl...��һ������0������������ʼ��
			_table.resize(__stl_next_prime(static_cast<unsigned int>(_table.size())), nullptr); // static_cast<unsigned int>(_table.size())) �ѷ��ص�size_tת����unsigned int
		}

		~HashTable()
		{
			// ��ÿһ��Ͱ�ͷ�
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i]; // �õ���ǰͰ�ĵ�һ���ڵ�
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
			if (it != End()) // �ҵ���
			{
				return make_pair(it, false) ; // ��������ͬԪ��
			}


			if (_n == _table.size()) // ��������Ϊ 1 ,����
			{
				// ����һ���µ�TableȻ���Ԫ���ƶ���ȥ
				// ֱ����������Ϊ��swap�Ժ󣬺�����������ʱ���������٣������ڴ����Node*���������ͣ���û���Զ��������������޷��ͷ�Node*������һ��ռ� 
				vector<Node*> newtable(__stl_next_prime(static_cast<unsigned int>(_table.size() + 1)), nullptr); // �ұȵ�ǰ_table.size()�������
				for (size_t i = 0; i < _table.size(); i++) // ��������Ͱ����
				{
					Node* cur = _table[i]; 
					while (cur)
					{
						Node* next = cur->_next;
						size_t newhashi = hs(kot(cur->_data)) % newtable.size();
						// ͷ�嵽�±�
						cur->_next = newtable[newhashi];
						newtable[newhashi] = cur;
						cur = next;
					}
					_table[i] = nullptr; // �ٰ�ԭ��Ͱ��ָ����Ϊ��
				}
				swap(_table, newtable);
			}
			size_t hashi = hs(kot(data)) % _table.size(); // ӳ���ϣ��ַ
			
			// �½ڵ�ͷ��
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

			return End(); // û�ҵ�
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
				if (hs(kot(cur->_data)) == key) // �ҵ���
				{
					if (prev == nullptr) // ���Ҫɾ���Ľڵ�Ϊͷ���
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
		inline unsigned long __stl_next_prime(unsigned long n) // ��ȡ��һ�����ݵ�������С
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