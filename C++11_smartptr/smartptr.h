#pragma once
#include<iostream>
#include <functional>
using namespace std;
namespace tr
{
	template<class T>
	class unique_ptr
	{
	public:
		explicit unique_ptr(T* ptr)
			:_ptr(ptr)
		{
			cout << "init: " << _ptr << endl;
		}
		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "delete: " << _ptr << endl;
				delete _ptr;
			}
		}
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}

		// 禁用拷贝构造和拷贝赋值
		unique_ptr(const unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;

		unique_ptr(unique_ptr<T>&& up)
			:_ptr(up._ptr)
		{
			up._ptr = nullptr; // 原来的置空，相当于转移了管理权
		}

		unique_ptr<T>& operator=(unique_ptr<T>&& up)
		{
			delete _ptr; // 先释放当前所管理的空间
			_ptr = up._ptr;
			up._ptr = nullptr;
		}

	private:
		T* _ptr;
	};

	template<class T>
	class shared_ptr
	{
	public:

		explicit shared_ptr(T* ptr = nullptr) // 没有删除器的时候，匹配这个
			:_ptr(ptr)
			, _count(new int(1))
		{}

		template<class D>
		shared_ptr(T* ptr, D del) // 有删除器的时候会匹配这个
			:_ptr(ptr)
			,_count(new int(1))
			,_del(del)
		{}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			,_count(sp._count)
			,_del(sp._del)
		{
			++(*_count);
		}

		// 移动构造函数（区别就是_count不变，并且原来的指针要置空）
		shared_ptr(shared_ptr<T>&& sp)
			: _ptr(sp._ptr)
			, _count(sp._count)
			, _del(move(sp._del)) // 这里也调用del的移动构造函数，提高效率
		{
			sp._ptr = nullptr;
			sp._count = nullptr;
		}

		void release() // 不只用于析构，赋值的时候，release也可能要使用
		{
			if (_count && --(*_count) == 0)
			{
				_del(_ptr); // 调用删除器，删除管理的资源
				delete _count;
				_ptr = nullptr;
				_count = nullptr; // 在把自己的资源释放了
			}
		}

		~shared_ptr()
		{
			release();
		}
		
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				release();
				_ptr = sp._ptr;
				_count = sp._count;
				_del = sp._del;
				++(*_count);
			}
			return *this;
		}

		// 移动赋值
		shared_ptr<T>& operator=(shared_ptr<T>&& sp)
		{
			if (this != &sp)
			{
				release();
				_ptr = sp._ptr;
				_count = sp._count;
				_del = move(sp._del);
				sp._ptr = nullptr;
				sp._count = nullptr;
			}
			return *this;
		}

		T* operator->()
		{
			return _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		int use_count() const 
		{
			return _count ? *_count : 0; // 如果 _count 为空，返回 0
		}

	private:
		T* _ptr;
		int* _count; 
		function<void(T*)> _del = [](T* ptr) {delete ptr;}; // 删除器，并提供缺省值
	};
}
