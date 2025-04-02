// vector 模拟实现
#include<iostream>
#include<assert.h>
#pragma once
namespace tr

{

    template<class T>
    class vector

    {

    public:

        // Vector的迭代器是一个原生指针
        // 迭代器的位置的确可以通过起始迭代器位置加上偏移量来表示，呈现出一种相对位置的概念
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

        const_iterator begin() const // 提供const版本的begin()给const成员使用
        {
            return _start;
        }

        const_iterator end() const
        {
            return _finish;
        }

            // construct and destroy

        vector() // 什么都不用写，因为声明给了缺省值，直接走初始化列表定义了
        {}

        vector(int n, const T& value = T())
        {
            reserve(n);
            while (n--)
            {
                push_back(value);
            }
        }

        template<class InputIterator> // 在类模版里面可以再定义函数模板
        // 这里用函数模板是因为：可以接受除了vector以外的迭代器，比如用string的区间迭代器来初始化vector
        vector(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        // 拷贝构造，注意浅拷贝和深拷贝的问题
        vector(const vector<T>& v)
        {
            reserve(v.capacity()); // reserve会开空间且会修改end_of_storage
            for (auto x : v)
            {
                push_back(x);
            }
        }

        vector<T>& operator= (vector<T> v)
        {
            // 因为这里的v只是外部的一个拷贝，交换以后，v在函数结束时也会自动销毁，但是v的内容以及所指向的空间却给了*this
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

        // 注意，在这里我们要先记录old_size，
        // 因为当_start改变了 后续计算_finish时使用size()时，是使用新的_start和旧_finish，无法反映原来的size
        void reserve(size_t n)
        {
            if (n > capacity())
            {
                size_t old_size = size();
                iterator _tmp = new T[n];

                // 拷贝元素
                // memcpy只是浅拷贝，因为memcpy是字节复制，对于内置类型有效，但是对于需要开辟空间的就无法达到深拷贝的效果
                for (size_t i = 0; i < old_size; i++)
                {
                    _tmp[i] = _start[i];  // 比如这里是元素是string，实际上这里调用的是operator=，所以能达到深拷贝的效果
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
                for (iterator end = _finish; end != (_start + n); end++) // 最后end指向的是有效元素的下一个位置
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
                reserve(n); // 扩容会导致迭代器失效
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

        // 返回删除的位置的下一个元素的迭代器
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

        iterator _start = nullptr; // 指向数据块的开始

        iterator _finish = nullptr; // 指向有效数据的尾

        iterator _end_of_storage = nullptr; // 指向存储容量的尾

    };

}