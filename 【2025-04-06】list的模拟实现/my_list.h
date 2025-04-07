// list ��ģ��ʵ��
#include<iostream>
using namespace std;

namespace tr
{
    // �ڵ���
    template<class T>
    struct ListNode // struct Ĭ�ϳ�Ա�ǹ�����
    {
        ListNode(const T& val = T())
            :_pPre(nullptr)
            ,_pNext(nullptr)
            ,_val(val)
        { }
        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };


    //List�ĵ�������
    template<class T, class Ref, class Ptr>
    struct ListIterator // �ڵ��ָ��
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self; // ListIterator<T, Ref, Ptr>��������౾��
        ListIterator(PNode pNode = nullptr)
            :_pNode(pNode)
        { }

        ListIterator(const Self& l)
        {
            _pNode = l._pNode;
        }
        Ref operator*()
        {
            return (*_pNode)._val;
        }
        Ptr operator->()  // ???
        {
            return &((*_pNode)._val);
        }

        Self& operator++()
        {
            _pNode = _pNode->_pNext;
            return *this; // ���ܷ���_PNode�����ص�Ӧ����iterator����Ȼiterator �ĳ�Ա������PNode�������кܶ��װ�õĽӿںͲ���
        }
        Self operator++(int)
        {
            Self tmp(_pNode);
            _pNode = _pNode->_pNext;
            return tmp;
        }
        Self& operator--()
        {
            _pNode = _pNode->_pPre;
            return *this;
        }
        Self operator--(int)  // ��Ϊtmp����ʱ��������Ҫ����tmp������Ȼ����������
        {
            Self tmp(_pNode);
            _pNode = _pNode->_pPre;
            return tmp;
        }
        bool operator!=(const Self& l)
        {
            return _pNode != l._pNode;
        }
        bool operator==(const Self& l)
        {
            return _pNode == l._pNode;
        }
        PNode _pNode;
    };


    //list��
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T*> const_iterator;
    public:

        void CreateHead()
        {
            _pHead = new Node();
            _pHead->_pNext = _pHead;
            _pHead->_pPre = _pHead;
        }

        // List�Ĺ���
        list()
        {
            CreateHead();
        }
        list(int n, const T& value = T())
        {
            CreateHead();
            while (n--)
            {
                push_back(value);
            }
        }
        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            CreateHead();
            while (first != last)
            {
                push_back(*first);
                first++;
            }
        }

        list(const list<T>& l)
        {
            CreateHead();
            PNode cur = l._pHead -> _pNext;
            while (cur != l._pHead)
            {
                push_back(cur->_val);
                cur = cur->_pNext;
            }
        }

        list<T>& operator=(const list<T> l)
        {
            for (const_iterator it = l.begin(); it != l.end(); it++)
            {
                push_back(*it);
            }
            return *this;
        }
        ~list()
        {
            clear();
            delete _pHead;
            _pHead = nullptr;
        }


        // List Iterator
        iterator begin()
        {
            return iterator(_pHead->_pNext);
        }
        iterator end()
        {
            return iterator(_pHead); // ���һ���ڵ��next����head
        }
        const_iterator begin() const
        {
            return const_iterator(_pHead->_pNext);
        }
        const_iterator end() const
        {
            return const_iterator(_pHead);
        }


        // List Capacity
        size_t size()const
        {
            size_t count = 0;
            for (const_iterator it = begin(); it != end(); it++)
            {
                count++;
            }
            return count;
        }
        bool empty()const
        {
            return _pHead->_pNext == _pHead;
        }


        // List Access
        T& front()
        {
            return _pHead->_pNext->_val;
        }
        const T& front()const
        {
            return _pHead->_pNext->_val;
        }
        T& back()
        {
            return _pHead->_pPre->_val;
        }
        const T& back()const
        {
            return _pHead->_pPre->_val;
        }


        // List Modify
        void push_back(const T& val) { insert(end(), val); }
        void pop_back() { erase(--end()); }
        void push_front(const T& val) { insert(begin(), val); }
        void pop_front() { erase(begin()); }
        // ��posλ��ǰ����ֵΪval�Ľڵ�
        iterator insert(iterator pos, const T& val)
        {
            PNode cur = pos._pNode;
            PNode pre = cur->_pPre;
            PNode newnode = new Node(val);
            newnode->_pPre = pre;
            newnode->_pNext = cur;
            pre->_pNext = newnode;
            cur->_pPre = newnode;
            return iterator(newnode);
        }
        // ɾ��posλ�õĽڵ㣬���ظýڵ����һ��λ��
        iterator erase(iterator pos)
        {
            PNode cur = pos._pNode;
            PNode pre = cur->_pPre;
            PNode nxt = cur->_pNext;
            pre->_pNext = nxt;
            nxt->_pPre = pre;
            delete cur;
            return iterator(nxt);
        }
        void clear()
        {
            iterator cur(_pHead->_pNext);
            while (cur != end())
            {
                cur = erase(cur);
            }
        }
    private:

        PNode _pHead;
    };
};