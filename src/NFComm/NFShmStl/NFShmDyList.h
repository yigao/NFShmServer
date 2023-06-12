// -------------------------------------------------------------------------
//    @FileName         :    NFShmDyList.h
//    @Author           :    gaoyi
//    @Date             :    23-2-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmDyList
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include <iterator>
#include <algorithm>
#include <vector>

struct NFShmDyListNodeBase
{
    NFShmDyListNodeBase()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        m_next = 0;
        m_prev = 0;
        m_self = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    ptrdiff_t m_next;
    ptrdiff_t m_prev;
    ptrdiff_t m_self;
};

template<class Tp>
struct NFShmDyListNode : public NFShmDyListNodeBase
{
    NFShmDyListNode()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        m_valid = false;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    Tp m_data;
    bool m_valid;
};

template<class Container>
struct NFShmDyListIteratorBase
{
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;

    Container *m_pContainer;
    NFShmDyListNodeBase *m_node;

    explicit NFShmDyListIteratorBase(const Container *pContainer, size_t iPos)
            : m_pContainer(const_cast<Container *>(pContainer))
    {
        m_node = m_pContainer->GetNode(iPos);
    }

    explicit NFShmDyListIteratorBase(const Container *pContainer, const NFShmDyListNodeBase *pNode)
            : m_pContainer(const_cast<Container *>(pContainer)), m_node(const_cast<NFShmDyListNodeBase *>(pNode))
    {
    }

    NFShmDyListIteratorBase() : m_pContainer(NULL), m_node(NULL) {}

    void _M_incr() { m_node = m_pContainer->GetNode(m_node->m_next); }

    void _M_decr() { m_node = m_pContainer->GetNode(m_node->m_prev); }

    bool operator==(const NFShmDyListIteratorBase &__x) const
    {
        return m_node == __x.m_node;
    }

    bool operator!=(const NFShmDyListIteratorBase &__x) const
    {
        return m_node != __x.m_node;
    }
};

template<class Tp, class Ref, class Ptr, class Container>
struct NFShmDyListIterator : public NFShmDyListIteratorBase<Container>
{
    typedef NFShmDyListIterator<Tp, Tp &, Tp *, Container> iterator;
    typedef NFShmDyListIterator<Tp, const Tp &, const Tp *, Container> const_iterator;
    typedef NFShmDyListIterator<Tp, Ref, Ptr, Container> _Self;

    typedef Tp value_type;
    typedef Ptr pointer;
    typedef Ref reference;
    typedef NFShmDyListNode<Tp> _Node;

    using NFShmDyListIteratorBase<Container>::m_node;

    explicit NFShmDyListIterator(const Container *pContainer, size_t iPos) : NFShmDyListIteratorBase<Container>(pContainer, iPos)
    {

    }

    explicit NFShmDyListIterator(const Container *pContainer, const NFShmDyListNodeBase *pNode) : NFShmDyListIteratorBase<Container>(pContainer, pNode)
    {
    }

    NFShmDyListIterator()
    {

    }

    NFShmDyListIterator(const iterator &__x) : NFShmDyListIteratorBase<Container>(__x.m_pContainer, __x.m_node)
    {

    }

    reference operator*() const { return ((_Node *) m_node)->m_data; }

    pointer operator->() const { return &(operator*()); }

    _Self &operator++()
    {
        this->_M_incr();
        return *this;
    }

    _Self operator++(int)
    {
        _Self __tmp = *this;
        this->_M_incr();
        return __tmp;
    }

    _Self &operator--()
    {
        this->_M_decr();
        return *this;
    }

    _Self operator--(int)
    {
        _Self __tmp = *this;
        this->_M_decr();
        return __tmp;
    }
};

template<class Tp>
class NFShmDyListBase
{
public:
    NFShmDyListBase()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    ~NFShmDyListBase()
    {
        m_pSize = NULL;
        m_node = NULL;
        m_pBuffer = NULL;
        m_pMaxSize = NULL;
        m_pFreeStart = NULL;
    }

    int CreateInit()
    {
        m_pSize = NULL;
        m_node = NULL;
        m_pBuffer = NULL;
        m_pMaxSize = NULL;
        m_pFreeStart = NULL;

        return 0;
    }

    int ResumeInit()
    {
        m_pSize = NULL;
        m_node = NULL;
        m_pBuffer = NULL;
        m_pMaxSize = NULL;
        m_pFreeStart = NULL;

        return 0;
    }

    void clear()
    {
        *m_pSize = 0;
        *m_pFreeStart = 0;
        size_t MAX_SIZE = *m_pMaxSize;
        for (size_t i = 0; i < MAX_SIZE; i++)
        {
            if (m_node[i].m_valid)
            {
                std::_Destroy(&(m_node[i].m_data));
            }
            m_node[i].m_next = i + 1;
            m_node[i].m_prev = 0;
            m_node[i].m_valid = false;
            m_node[i].m_self = i;
        }

        if (m_node[MAX_SIZE].m_valid)
        {
            std::_Destroy(&(m_node[MAX_SIZE].m_data));
        }
        m_node[MAX_SIZE].m_next = MAX_SIZE;
        m_node[MAX_SIZE].m_prev = MAX_SIZE;
        m_node[MAX_SIZE].m_self = MAX_SIZE;
        m_node[MAX_SIZE].m_valid = false;
    }

    /**
    * 计算所用内存的大小
    */
    static size_t CountSize(int iObjectCount)
    {
        //size + maxSize + freeStart + sizeof(NFShmDyListNode<Tp>) * (iObjectCount + 1)
        return sizeof(size_t) + sizeof(size_t) + sizeof(ptrdiff_t) + sizeof(NFShmDyListNode<Tp>) * (iObjectCount+1);
    }

    virtual int Init(const char* pBuffer, int bufSize, int iObjectCount, bool bResetShm = true)
    {
        CHECK_NULL(pBuffer);
        CHECK_EXPR(iObjectCount >= 0, -1, "iObjectCount:{}",iObjectCount);
        int iCountSize = CountSize(iObjectCount);
        NF_ASSERT_MSG(bufSize >= iCountSize, "bufSize:{} iCountSize:{}", bufSize, iCountSize);

        m_pBuffer = (char*)pBuffer;
        m_pSize = (size_t*)pBuffer;
        m_pMaxSize = (size_t*)(pBuffer+sizeof(size_t));
        m_pFreeStart = (ptrdiff_t*)(pBuffer+sizeof(size_t) + sizeof(size_t));
        m_node = (NFShmDyListNode<Tp>*)(pBuffer + sizeof(size_t) + sizeof(size_t)+sizeof(ptrdiff_t));

        if (bResetShm)
        {
            memset((void*)pBuffer, 0, bufSize);
            *m_pMaxSize = iObjectCount;
            size_t MAX_SIZE = *m_pMaxSize;
            for (size_t i = 0; i < MAX_SIZE; i++)
            {
                m_node[i].m_next = i + 1;
                m_node[i].m_prev = 0;
                m_node[i].m_valid = false;
                m_node[i].m_self = i;
            }

            m_node[MAX_SIZE].m_next = MAX_SIZE;
            m_node[MAX_SIZE].m_prev = MAX_SIZE;
            m_node[MAX_SIZE].m_self = MAX_SIZE;
            m_node[MAX_SIZE].m_valid = false;
        }
        else
        {
            NF_ASSERT_MSG(*m_pSize <= *m_pMaxSize, "size:{} max_size:{}", *m_pSize, *m_pMaxSize);
            NF_ASSERT_MSG(*m_pMaxSize == iObjectCount, "max size:{} object count:{}", *m_pMaxSize, iObjectCount);
            if (!std::numeric_limits<Tp>::is_specialized)
            {
                size_t MAX_SIZE = *m_pMaxSize;
                for (size_t i = 0; i < MAX_SIZE; i++)
                {
                    if (m_node[i].m_valid)
                    {
                        std::_Construct(&m_node[i].m_data);
                    }
                }
            }
        }

        return 0;
    }
protected:
    char* m_pBuffer;
    NFShmDyListNode<Tp>* m_node;
    ptrdiff_t* m_pFreeStart;
    size_t* m_pSize;
    size_t* m_pMaxSize;
};

template<class Tp>
class NFShmDyList : public NFShmDyListBase<Tp>
{
    typedef NFShmDyListBase<Tp> _Base;
protected:
    typedef void *_Void_pointer;
public:
    typedef NFShmDyList<Tp> ListType;
    typedef Tp value_type;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef NFShmDyListNode<Tp> _Node;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

public:
    typedef NFShmDyListIterator<Tp, Tp &, Tp *, ListType> iterator;
    typedef NFShmDyListIterator<Tp, const Tp &, const Tp *, ListType> const_iterator;

    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;

protected:
    using _Base::m_node;
    using _Base::m_pFreeStart;
    using _Base::m_pSize;
    using _Base::m_pMaxSize;
protected:
    /**
     * @brief This function creates a node with the given data and assigns it to the free start position.
     * It then updates the free start position and constructs the data at the node position. It also sets the valid flag to true.
     * @param __x
     * @return
     */
    _Node *_M_create_node(const Tp &__x)
    {
        ptrdiff_t iSelf = *m_pFreeStart;
        *m_pFreeStart = m_node[*m_pFreeStart].m_next;

        std::_Construct(&m_node[iSelf].m_data, __x);

        NF_ASSERT(!m_node[iSelf].m_valid);
        m_node[iSelf].m_valid = true;

        return &m_node[iSelf];
    }

    _Node *_M_create_node()
    {
        ptrdiff_t iSelf = *m_pFreeStart;
        *m_pFreeStart = m_node[*m_pFreeStart].m_next;

        std::_Construct(&m_node[iSelf].m_data, Tp());

        NF_ASSERT(!m_node[iSelf].m_valid);
        m_node[iSelf].m_valid = true;

        return &m_node[iSelf];
    }

    /**
     * @brief This function recycles a node given by the pointer pNode.
     * It destroys the data stored in the node and constructs a new data object.
     * The node is then marked as invalid and added to the start of the free list.
     * @param pNode
     */
    void _M_recycle_node(_Node *pNode)
    {
        NF_ASSERT(pNode);
        NF_ASSERT(pNode->m_valid);

		std::_Destroy(&(pNode->m_data));

        pNode->m_valid = false;
        pNode->m_next = *m_pFreeStart;
        *m_pFreeStart = pNode->m_self;
    }

public:
    explicit NFShmDyList()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    int CreateInit()
    {
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    ~NFShmDyList()
    {

    }

    NFShmDyList<Tp> &operator=(const NFShmDyList<Tp> &__x);

public:
    iterator begin() { return iterator(this, m_node[*m_pMaxSize].m_next); }

    const_iterator begin() const { return iterator(this, m_node[*m_pMaxSize].m_next); }

    iterator end() { return iterator(this, *m_pMaxSize); }

    const_iterator end() const { return iterator(this, *m_pMaxSize); }

    reverse_iterator rbegin() { return reverse_iterator(end()); }

    const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

    reverse_iterator rend() { return reverse_iterator(begin()); }

    const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

    bool empty() const
    {
        if (m_node[*m_pMaxSize].m_next == *m_pMaxSize)
        {
            NF_ASSERT(*m_pSize == 0);
        }
        return m_node[*m_pMaxSize].m_next == *m_pMaxSize;
    }

    bool full() const
    {
        if (*m_pFreeStart == *m_pMaxSize)
        {
            NF_ASSERT(*m_pSize == *m_pMaxSize);
        }
        return *m_pFreeStart == *m_pMaxSize;
    }

    size_type size() const
    {
        NF_ASSERT((size_type)std::distance(begin(), end()) == *m_pSize);
        return *m_pSize;
    }

    size_type max_size() const { return *m_pMaxSize; }

    size_type capacity() const { return *m_pMaxSize; }

    reference front() { return *begin(); }

    const_reference front() const { return *begin(); }

    reference back() { return *(--end()); }

    const_reference back() const { return *(--end()); }

    void swap(NFShmDyList<Tp> &__x) {}

    _Node *GetNode(size_t index)
    {
        CHECK_EXPR(index <= *m_pMaxSize, NULL, "index out of range:{}", index);
        return &m_node[index];
    }

    iterator GetIterator(size_t index)
    {
        CHECK_EXPR(index <= *m_pMaxSize, end(), "index out of range:{}", index);
        return iterator(this, index);
    }

    iterator GetIterator(_Node* pNode)
    {
        return iterator(this, pNode);
    }

    /**
    * Inserts the given element at the position of the iterator's next.
    *
    * @param __position - The position to insert the element.
    * @param __x - The element to insert.
    * @return An iterator pointing to the inserted element.
    */
    iterator insert(iterator __position, const Tp &__x)
    {
        if (full())
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "The List Space Not Enough, Insert Failed");
            return end();
        }
        _Node *__tmp = _M_create_node(__x);
        __tmp->m_next = __position.m_node->m_self;
        __tmp->m_prev = __position.m_node->m_prev;
        GetNode(__position.m_node->m_prev)->m_next = __tmp->m_self;
        __position.m_node->m_prev = __tmp->m_self;

        (*m_pSize)++;
        return iterator(this, __tmp);
    }

    iterator insert(iterator __position) { return insert(__position, Tp()); }


    template<class _InputIterator>
    void insert(iterator __pos, _InputIterator __first, _InputIterator __last)
    {
        typedef typename std::__is_integer<_InputIterator>::__type _Integral;
        _M_insert_dispatch(__pos, __first, __last, _Integral());
    }

    void insert(iterator __position, const Tp *__first, const Tp *__last);

    void insert(iterator __position,
                const_iterator __first, const_iterator __last);

    void insert(iterator __pos, size_type __n, const Tp &__x) { _M_fill_insert(__pos, __n, __x); }

    void push_front(const Tp &__x) { insert(begin(), __x); }

    void push_front() { insert(begin()); }

    void push_back(const Tp &__x)
    {
        insert(end(), __x);
    }

    void push_back()
    {
        insert(end());
    }

    /**
     * @brief  This function erases the element at the given position and returns an iterator pointing to the next element.
     * If the position is at the end, it returns the end iterator.
     * The node at the given position is recycled and the previous and next nodes are linked accordingly. The size of the list is also decremented.
     * @param __position
     * @return
     */
    iterator erase(iterator __position)
    {
        if (__position == end())
        {
            return end();
        }
        ptrdiff_t __next_node = __position.m_node->m_next;
        ptrdiff_t __prev_node = __position.m_node->m_prev;
        _M_recycle_node(static_cast<_Node*>(__position.m_node));
        m_node[__prev_node].m_next = __next_node;
        m_node[__next_node].m_prev = __prev_node;
        (*m_pSize)--;
        return iterator(this, __next_node);
    }

    iterator erase(iterator __first, iterator __last);

    void clear() { _Base::clear(); }

    void resize(size_type __new_size, const Tp &__x);

    void resize(size_type __new_size) { this->resize(__new_size, Tp()); }

    void pop_front() { erase(begin()); }

    void pop_back()
    {
        iterator __tmp = end();
        erase(--__tmp);
    }

public:
    void assign(size_type __n, const Tp &__val) { _M_fill_assign(__n, __val); }

    template<class _InputIterator>
    void assign(_InputIterator __first, _InputIterator __last)
    {
        typedef typename std::__is_integer<_InputIterator>::__type _Integral;
        _M_assign_dispatch(__first, __last, _Integral());
    }

protected:
    void transfer(iterator __position, iterator __first, iterator __last) {
        NF_ASSERT(this == __position.m_pContainer);
        NF_ASSERT(this == __first.m_pContainer);
        NF_ASSERT(this == __last.m_pContainer);
        if (__position != __last) {
            // Remove [first, last) from its old position.
            GetNode(__last.m_node->m_prev)->m_next     = __position.m_node->m_self;
            GetNode(__first.m_node->m_prev)->m_next    = __last.m_node->m_self;
            GetNode(__position.m_node->m_prev)->m_next = __first.m_node->m_self;

            // Splice [first, last) into its new position.
            ptrdiff_t __tmp      = __position.m_node->m_prev;
            __position.m_node->m_prev = __last.m_node->m_prev;
            __last.m_node->m_prev     = __first.m_node->m_prev;
            __first.m_node->m_prev    = __tmp;
        }
    }
public:
    void splice(iterator __position, iterator __i) {
        iterator __j = __i;
        ++__j;
        if (__position == __i || __position == __j) return;
        this->transfer(__position, __i, __j);
    }
    void splice(iterator __position, iterator __first, iterator __last) {
        if (__first != __last)
            this->transfer(__position, __first, __last);
    }
public:
    void remove(const Tp &__value);

    void unique();

    void reverse();

    void sort()
    {
        std::list<Tp> list(begin(), end());
        list.sort();
        clear();
        assign(list.begin(), list.end());
    }

    void random_shuffle()
    {
        std::vector<Tp> vec(begin(), end());
        std::random_shuffle(vec.begin(), vec.end());
        clear();
        assign(vec.begin(), vec.end());
    }

    template<class _Predicate>
    void remove_if(_Predicate);

    template<class _BinaryPredicate>
    void unique(_BinaryPredicate);

protected:
    template<class _Integer>
    void _M_insert_dispatch(iterator __pos, _Integer __n, _Integer __x, std::__true_type)
    {
        _M_fill_insert(__pos, (size_type) __n, (Tp) __x);
    }

    template<class _InputIterator>
	void _M_insert_dispatch(iterator __pos, _InputIterator __first, _InputIterator __last, std::__false_type);


    template<class _Integer>
    void _M_assign_dispatch(_Integer __n, _Integer __val, std::__true_type) { _M_fill_assign((size_type) __n, (Tp) __val); }

    template<class _InputIterator>
    void _M_assign_dispatch(_InputIterator __first, _InputIterator __last, std::__false_type);

    void _M_fill_assign(size_type __n, const Tp &__val);

    void _M_fill_insert(iterator __pos, size_type __n, const Tp &__x);
};

template<class Tp>
inline bool operator==(const NFShmDyList<Tp> &__x, const NFShmDyList<Tp> &__y)
{
    typedef typename NFShmDyList<Tp>::const_iterator const_iterator;
    const_iterator __end1 = __x.end();
    const_iterator __end2 = __y.end();

    const_iterator __i1 = __x.begin();
    const_iterator __i2 = __y.begin();
    while (__i1 != __end1 && __i2 != __end2 && *__i1 == *__i2)
    {
        ++__i1;
        ++__i2;
    }
    return __i1 == __end1 && __i2 == __end2;
}

template<class Tp, size_t MAX_SIZE>
inline bool operator<(const NFShmDyList<Tp> &__x,
                      const NFShmDyList<Tp> &__y)
{
    return std::lexicographical_compare(__x.begin(), __x.end(),
                                        __y.begin(), __y.end());
}

template<class _Tp>
template<class _InputIter>
void NFShmDyList<_Tp>::_M_insert_dispatch(iterator __position, _InputIter __first, _InputIter __last, std::__false_type)
{
    for (; __first != __last; ++__first)
        insert(__position, *__first);
}

template<class Tp>
void NFShmDyList<Tp>::insert(iterator __position,
                                     const Tp *__first, const Tp *__last)
{
    for (; __first != __last; ++__first)
        insert(__position, *__first);
}

template<class Tp>
void NFShmDyList<Tp>::insert(iterator __position,
                                     const_iterator __first, const_iterator __last)
{
    for (; __first != __last; ++__first)
        insert(__position, *__first);
}

template<class _Tp>
void NFShmDyList<_Tp>::_M_fill_insert(iterator __position,
                                              size_type __n, const _Tp &__x)
{
    for (; __n > 0; --__n)
        insert(__position, __x);
}

template<class _Tp>
typename NFShmDyList<_Tp>::iterator NFShmDyList<_Tp>::erase(iterator __first,
                                                                            iterator __last)
{
    while (__first != __last)
        erase(__first++);
    return __last;
}

template<class _Tp>
void NFShmDyList<_Tp>::resize(size_type __new_size, const _Tp &__x)
{
    iterator __i = begin();
    size_type __len = 0;
    for (; __i != end() && __len < __new_size; ++__i, ++__len);
    if (__len == __new_size)
        erase(__i, end());
    else                          // __i == end()
        insert(end(), __new_size - __len, __x);
}

template<class _Tp>
NFShmDyList<_Tp> &NFShmDyList<_Tp>::operator=(const NFShmDyList<_Tp> &__x)
{
    if (this != &__x)
    {
        iterator __first1 = begin();
        iterator __last1 = end();
        const_iterator __first2 = __x.begin();
        const_iterator __last2 = __x.end();
        while (__first1 != __last1 && __first2 != __last2)
            *__first1++ = *__first2++;
        if (__first2 == __last2)
            erase(__first1, __last1);
        else
            insert(__last1, __first2, __last2);
    }
    return *this;
}

template<class _Tp>
void NFShmDyList<_Tp>::_M_fill_assign(size_type __n, const _Tp &__val)
{
    iterator __i = begin();
    for (; __i != end() && __n > 0; ++__i, --__n)
        *__i = __val;
    if (__n > 0)
        insert(end(), __n, __val);
    else
        erase(__i, end());
}

template<class _Tp>
template<class _InputIter>
void NFShmDyList<_Tp>::_M_assign_dispatch(_InputIter __first2, _InputIter __last2, std::__false_type)
{
    iterator __first1 = begin();
    iterator __last1 = end();
    for (; __first1 != __last1 && __first2 != __last2; ++__first1, ++__first2)
        *__first1 = *__first2;
    if (__first2 == __last2)
        erase(__first1, __last1);
    else
        insert(__last1, __first2, __last2);
}


template<class _Tp>
void NFShmDyList<_Tp>::remove(const _Tp &__value)
{
    iterator __first = begin();
    iterator __last = end();
    while (__first != __last)
    {
        iterator __next = __first;
        ++__next;
        if (*__first == __value) erase(__first);
        __first = __next;
    }
}

template<class _Tp>
void NFShmDyList<_Tp>::unique()
{
    iterator __first = begin();
    iterator __last = end();
    if (__first == __last) return;
    iterator __next = __first;
    while (++__next != __last)
    {
        if (*__first == *__next)
            erase(__next);
        else
            __first = __next;
        __next = __first;
    }
}

template<class _Tp>
inline void NFShmDyList<_Tp>::reverse()
{
    std::reverse(begin(), end());
}

template<class _Tp>
template<class _Predicate>
void NFShmDyList<_Tp>::remove_if(_Predicate __pred)
{
    iterator __first = begin();
    iterator __last = end();
    while (__first != __last)
    {
        iterator __next = __first;
        ++__next;
        if (__pred(*__first)) erase(__first);
        __first = __next;
    }
}

template<class _Tp>
template<class _BinaryPredicate>
void NFShmDyList<_Tp>::unique(_BinaryPredicate __binary_pred)
{
    iterator __first = begin();
    iterator __last = end();
    if (__first == __last) return;
    iterator __next = __first;
    while (++__next != __last)
    {
        if (__binary_pred(*__first, *__next))
            erase(__next);
        else
            __first = __next;
        __next = __first;
    }
}