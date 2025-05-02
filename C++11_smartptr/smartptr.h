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

		// ���ÿ�������Ϳ�����ֵ
		unique_ptr(const unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;

		unique_ptr(unique_ptr<T>&& up)
			:_ptr(up._ptr)
		{
			up._ptr = nullptr; // ԭ�����ÿգ��൱��ת���˹���Ȩ
		}

		unique_ptr<T>& operator=(unique_ptr<T>&& up)
		{
			delete _ptr; // ���ͷŵ�ǰ������Ŀռ�
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

		explicit shared_ptr(T* ptr = nullptr) // û��ɾ������ʱ��ƥ�����
			:_ptr(ptr)
			, _count(new int(1))
		{}

		template<class D>
		shared_ptr(T* ptr, D del) // ��ɾ������ʱ���ƥ�����
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

		// �ƶ����캯�����������_count���䣬����ԭ����ָ��Ҫ�ÿգ�
		shared_ptr(shared_ptr<T>&& sp)
			: _ptr(sp._ptr)
			, _count(sp._count)
			, _del(move(sp._del)) // ����Ҳ����del���ƶ����캯�������Ч��
		{
			sp._ptr = nullptr;
			sp._count = nullptr;
		}

		void release() // ��ֻ������������ֵ��ʱ��releaseҲ����Ҫʹ��
		{
			if (_count && --(*_count) == 0)
			{
				_del(_ptr); // ����ɾ������ɾ���������Դ
				delete _count;
				_ptr = nullptr;
				_count = nullptr; // �ڰ��Լ�����Դ�ͷ���
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

		// �ƶ���ֵ
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
			return _count ? *_count : 0; // ��� _count Ϊ�գ����� 0
		}

	private:
		T* _ptr;
		int* _count; 
		function<void(T*)> _del = [](T* ptr) {delete ptr;}; // ɾ���������ṩȱʡֵ
	};
}
