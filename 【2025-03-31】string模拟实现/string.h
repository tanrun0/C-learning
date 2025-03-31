// 用C语言风格带'\0'的字符串来模拟实现
#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;
namespace tr
{

    class string

    {

        friend ostream& operator<<(ostream& _cout, const tr::string& s);

        friend istream& operator>>(istream& _cin, tr::string& s);

    public:

        typedef char* iterator;

    public:

        string(const char* str = "")
            :_size(strlen(str))
            , _capacity(_size)
            , _str(new(char[_capacity + 1]))
        {
            strcpy(_str, str);
        }

        string(const string& s)
        {
            _size = s._size;
            _capacity = s._capacity;
            _str = new(char[_capacity + 1]);
            strcpy(_str, s._str);
        }

        string& operator=(const string& s)
        {
            if (this != &s)
            {
                _size = s._size;
                _capacity = s._capacity;
                char* tmp = new(char[_capacity + 1]);
                strcpy(tmp, s._str);
                delete[] _str;
                _str = tmp;
            }
            return *this;
        }

        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

        // iterator

        iterator begin() {
            return &_str[0];
        }

        iterator end() {
            return &_str[_size];
        }


        // modify

        void push_back(char c)
        {
            if (_size == _capacity)
            {
                _capacity = _capacity != 0 ? _capacity * 2 : 1;
                char* tmp = new(char[_capacity + 1]);
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
            }
            _str[_size] = c;
            _size++;
            _str[_size] = '\0';
        }

        string& operator+=(char c)
        {
            push_back(c);
            return *this;
        }

        void append(const char* str)
        {
            for (int i = 0; i < strlen(str); i++)
            {
                push_back(str[i]);
            }
        }

        string& operator+=(const char* str)
        {
            append(str);
            return *this;
        }

        void clear()
        {
            _size = 0;
            _str[_size] = '\0';
        }

        void swap(string& s)
        {
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
            std::swap(_str, s._str);
        }

        const char* c_str()const
        {
            return _str;
        }


        // capacity

        size_t size()const
        {
            return _size;
        }

        size_t capacity()const
        {
            return _capacity;
        }

        bool empty()const
        {
            return _size == 0;
        }

        void resize(size_t n, char c = '\0')
        {
            if (n > _capacity)
            {
                reserve(n * 2);
            }
            if (n > _size)
            {
                for (size_t i = _size; i < n; ++i)
                {
                    _str[i] = c;
                }
            }
            _str[n] = '\0'; // _size < n 时也直接截断了
            _size = n;
        }

        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char* tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }

        char& operator[](size_t index)
        {
            return _str[index];
        }

        const char& operator[](size_t index)const
        {
            return _str[index];
        }


        bool operator<(const string& s)
        {
            return strcmp(_str, s._str) < 0;
        }

        bool operator<=(const string& s)
        {
            return !(strcmp(_str, s._str) > 0);
        }

        bool operator>(const string& s)
        {
            return strcmp(_str, s._str) > 0;
        }

        bool operator>=(const string& s)
        {
            return !(strcmp(_str, s._str) < 0);
        }

        bool operator==(const string& s)
        {
            return strcmp(_str, s._str) == 0;
        }

        bool operator!=(const string& s)
        {
            return !(strcmp(_str, s._str) == 0);
        }

        // 返回c在string中第一次出现的位置
        size_t find(char c, size_t pos = 0) const
        {
            assert(pos < _size);
            for (size_t i = pos; i < _size; i++)
            {
                if (_str[i] == c)
                {
                    return i;
                }
            }
            return npos;
        }

        // 返回子串s在string中第一次出现的位置

        size_t find(const char* s, size_t pos = 0) const
        {
            const char* p = strstr(_str + pos, s);
            if (p != nullptr)
            {
                return p - _str;
            }
            return npos;
        }

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置

        string& insert(size_t pos, char c)
        {
            assert(pos <= _size);
            if (_size == _capacity)
            {
                reserve(_capacity * 2);
            }
            memmove(_str + pos + 1, _str + pos, _size - pos + 1); // 左开减右闭得到元素个数
            _str[pos] = c;
            ++_size;
            return *this;
        }

        string& insert(size_t pos, const char* str)
        {
            assert(pos <= _size);
            size_t len = strlen(str);
            if (_size + len >= _capacity)
            {
                reserve(_size + len);
            }
            memmove(_str + pos + len, _str + pos, _size - pos + 1);
            strncpy(_str + pos, str, len);
            _size += len;
            return *this;
        }

        // 删除从pos位置开始的len个元素，并返回下一个位置
        string& erase(size_t pos, size_t len)
        {
            assert(pos < _size);
            if (pos + len > _size)
            {
                _size = pos;
                _str[_size] = '\0';
            }
            else
            {
                strcpy(_str + pos, _str + pos + len );
                _size -= len;
            }
            return *this;
        }


        static const size_t npos = -1;
    private:
        size_t _size;
        size_t _capacity;
        char* _str;
    };

    ostream& operator<<(ostream& _cout, const tr::string& s) {
        _cout << s._str;
        return _cout;
    }

    istream& operator>>(istream& _cin, tr::string& s) {
        s.clear();
        char ch;
        while (_cin.get(ch) && ch != ' ' && ch != '\n') {
            s += ch;
        }
        return _cin;
    }
}