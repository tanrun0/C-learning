// vector ģ��ʵ��
#include<iostream>
#include<assert.h>
#pragma once
namespace tr

{

    template<class T>
    class vector

    {

    public:

        // Vector�ĵ�������һ��ԭ��ָ��
        // ��������λ�õ�ȷ����ͨ����ʼ������λ�ü���ƫ��������ʾ�����ֳ�һ�����λ�õĸ���
        typedef T* iterator;

        typedef const T* const_iterator;

        iterator begin()
        {
            return _start;
        }

        iterator end()
        {
            return _finish;
        }

        const_iterator begin() const // �ṩconst�汾��begin()��const��Աʹ��
        {
            return _start;
        }

        const_iterator end() const
        {
            return _finish;
        }

            // construct and destroy

        vector() // ʲô������д����Ϊ��������ȱʡֵ��ֱ���߳�ʼ���б�����
        {}

        vector(int n, const T& value = T())
        {
            reserve(n);
            while (n--)
            {
                push_back(value);
            }
        }

        template<class InputIterator> // ����ģ����������ٶ��庯��ģ��
        // �����ú���ģ������Ϊ�����Խ��ܳ���vector����ĵ�������������string���������������ʼ��vector
        vector(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        // �������죬ע��ǳ���������������
        vector(const vector<T>& v)
        {
            reserve(v.capacity()); // reserve�Ὺ�ռ��һ��޸�end_of_storage
            for (auto x : v)
            {
                push_back(x);
            }
        }

        vector<T>& operator= (vector<T> v)
        {
            // ��Ϊ�����vֻ���ⲿ��һ�������������Ժ�v�ں�������ʱҲ���Զ����٣�����v�������Լ���ָ��Ŀռ�ȴ����*this
            swap(v);
            return *this;
        }

        ~vector()
        {
            delete[] _start;
            _start = _finish = _end_of_storage = nullptr;
        }

            // capacity

        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _end_of_storage - _start;
            }

        // ע�⣬����������Ҫ�ȼ�¼old_size��
        // ��Ϊ��_start�ı��� ��������_finishʱʹ��size()ʱ����ʹ���µ�_start�;�_finish���޷���ӳԭ����size
        void reserve(size_t n)
        {
            if (n > capacity())
            {
                size_t old_size = size();
                iterator _tmp = new T[n];

                // ����Ԫ��
                // memcpyֻ��ǳ��������Ϊmemcpy���ֽڸ��ƣ���������������Ч�����Ƕ�����Ҫ���ٿռ�ľ��޷��ﵽ�����Ч��
                for (size_t i = 0; i < old_size; i++)
                {
                    _tmp[i] = _start[i];  // ����������Ԫ����string��ʵ����������õ���operator=�������ܴﵽ�����Ч��
                }
                delete[] _start;
                _start = _tmp;
                _finish = _start + old_size;
                _end_of_storage = _start + n;
            }
        }

        void resize(size_t n, const T& value = T())
        {
            if (n > capacity())
            {
                reserve(n);
            }
            if (n > size())
            {
                for (iterator end = _finish; end != (_start + n); end++) // ���endָ�������ЧԪ�ص���һ��λ��
                {
                    *end = value;
                }
            }
            _finish = _start + n;
        }


            ///////////////access///////////////////////////////

        T& operator[](size_t pos)
        {
            return _start[pos];
        }

        const T& operator[](size_t pos)const
        {
            return _start[pos];
        }



            ///////////////modify/////////////////////////////

        void push_back(const T& x)
        {
            if (_finish == _end_of_storage)
            {
                size_t n = capacity() == 0 ? 4 : capacity() * 2;
                reserve(n);
            }
            *_finish = x;
            _finish++;
        }

        void pop_back()
        {
            erase(end() - 1);
        }

        void swap(vector<T>& v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_end_of_storage, v._end_of_storage);
        }

        iterator insert(iterator pos, const T& x)
        {
            assert(pos < _finish);
            if (_finish == _end_of_storage)
            {
                size_t old_size = size();
                size_t n = capacity() == 0 ? 4 : capacity() * 2;
                reserve(n); // ���ݻᵼ�µ�����ʧЧ
                pos = _start + old_size;
            }
            iterator end = _finish - 1;
            while (end >= pos)
            {
                *(end + 1) = *end;
                end--;
            }
            *pos = x;
            _finish++;
            return pos;
        }

        // ����ɾ����λ�õ���һ��Ԫ�صĵ�����
        iterator erase(iterator pos)
        {
            assert(pos < _finish);
            for (iterator end = pos; end < _finish - 1; end++)
            {
                *(end) = *(end + 1);
            }
            _finish--;
            return pos;
        }

    private:

        iterator _start = nullptr; // ָ�����ݿ�Ŀ�ʼ

        iterator _finish = nullptr; // ָ����Ч���ݵ�β

        iterator _end_of_storage = nullptr; // ָ��洢������β

    };

}