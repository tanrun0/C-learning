#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<class T>
class Less
{
public:
	bool operator()(const T& a, const T& b)
	{
		return a < b;
	}
};

template<class T>
class Greater
{
public:
	bool operator()(const T& a, const T& b)
	{
		return a > b;
	}
};

namespace tr
{
	template<class T, class Container = vector<T>, class Compare = Less<T>>
	// Compare 就是比较方法
	class priority_queue
	{
	public:
		void Adjustup(size_t child)
		{
			Compare com; // 构造仿函数对象
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_a[child], _a[parent])) // 用仿函数对象调用仿函数
				{
					std::swap(_a[child], _a[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else {
					break;
				}
			}
		}

		void Adjustdown(size_t parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _a.size())
			{
				if (child + 1 < _a.size() && com(_a[child + 1], _a[child]))
				{
					child++;
				}
				if (com(_a[child], _a[parent])) // 相当于孩子节点小于父亲
				{
					std::swap(_a[child], _a[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else {
					break;
				}
			}
		}

		priority_queue(){}
		void push(const T& x)
		{
			_a.push_back(x);
			Adjustup(_a.size() - 1);
		}
		T& top()
		{
			return _a[0];
		}
		const T& top() const
		{
			return _a[0];
		}
		void pop()
		{
			std::swap(_a[0], _a[_a.size() - 1]);
			_a.pop_back();
			Adjustdown(0);
		}
		size_t size() { return _a.size(); }
		bool empty() { return _a.empty(); }
	private:
		Container _a;
	};


};