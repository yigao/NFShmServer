// -------------------------------------------------------------------------
//    @FileName         :    NFShmList.h
//    @Author           :    gaoyi
//    @Date             :    23-2-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmList
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include <iterator>
#include <algorithm>
#include <vector>

struct NFShmListNodeBase
{
    NFShmListNodeBase()
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
struct NFShmListNode : public NFShmListNodeBase
{
    NFShmListNode()
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
struct NFShmListIteratorBase
{
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;

    Container *m_pContainer;
    NFShmListNodeBase *m_node;

    explicit NFShmListIteratorBase(const Container *pContainer, size_t iPos)
            : m_pContainer(const_cast<Container *>(pContainer))
    {
        m_node = m_pContainer->GetNode(iPos);
    }

    explicit NFShmListIteratorBase(const Container *pContainer, const NFShmListNodeBase *pNode)
            : m_pContainer(const_cast<Container *>(pContainer)), m_node(const_cast<NFShmListNodeBase *>(pNode))
    {
    }

    NFShmListIteratorBase() : m_pContainer(NULL), m_node(NULL) {}

    void _M_incr() { m_node = m_pContainer->GetNode(m_node->m_next); }

    void _M_decr() { m_node = m_pContainer->GetNode(m_node->m_prev); }

    bool operator==(const NFShmListIteratorBase &__x) const
    {
        return m_node == __x.m_node;
    }

    bool operator!=(const NFShmListIteratorBase &__x) const
    {
        return m_node != __x.m_node;
    }
};

template<class Tp, class Ref, class Ptr, class Container>
struct NFShmListIterator : public NFShmListIteratorBase<Container>
{
    typedef NFShmListIterator<Tp, Tp &, Tp *, Container> iterator;
    typedef NFShmListIterator<Tp, const Tp &, const Tp *, Container> const_iterator;
    typedef NFShmListIterator<Tp, Ref, Ptr, Container> _Self;

    typedef Tp value_type;
    typedef Ptr pointer;
    typedef Ref reference;
    typedef NFShmListNode<Tp> _Node;

    using NFShmListIteratorBase<Container>::m_node;

    explicit NFShmListIterator(const Container *pContainer, size_t iPos) : NFShmListIteratorBase<Container>(pContainer, iPos)
    {

    }

    explicit NFShmListIterator(const Container *pContainer, const NFShmListNodeBase *pNode) : NFShmListIteratorBase<Container>(pContainer, pNode)
    {
    }

    NFShmListIterator()
    {

    }

    NFShmListIterator(const iterator &__x) : NFShmListIteratorBase<Container>(__x.m_pContainer, __x.m_node)
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

template<class Tp, size_t MAX_SIZE>
class NFShmListBase
{
public:
    NFShmListBase()
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

    ~NFShmListBase()
    {
        clear();
        m_size = 0;
        m_freeStart = 0;
        memset(m_mem, 0, ARRAYSIZE_UNSAFE(m_mem));
        m_node = NULL;
    }

    int CreateInit()
    {
        m_size = 0;
        m_freeStart = 0;
        memset(m_mem, 0, ARRAYSIZE_UNSAFE(m_mem));
        m_node = (NFShmListNode<Tp>*)m_mem;

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

        return 0;
    }

    int ResumeInit()
    {
        m_node = (NFShmListNode<Tp>*)m_mem;
        if (!std::numeric_limits<Tp>::is_specialized)
        {
            for (size_t i = 0; i < MAX_SIZE; i++)
            {
                if (m_node[i].m_valid)
                {
#if NF_PLATFORM == NF_PLATFORM_WIN
                    new (&m_node[i].m_data) Tp();
#else
                    std::_Construct(&m_node[i].m_data);
#endif
                }
            }
        }

        return 0;
    }

    void clear()
    {
        m_size = 0;
        m_freeStart = 0;

        for (size_t i = 0; i < MAX_SIZE; i++)
        {
            if (m_node[i].m_valid)
            {
#if NF_PLATFORM == NF_PLATFORM_WIN
                (&(m_node[i].m_data))->~Tp();
#else
                std::_Destroy(&(m_node[i].m_data));
#endif
            }
            m_node[i].m_next = i + 1;
            m_node[i].m_prev = 0;
            m_node[i].m_valid = false;
            m_node[i].m_self = i;
        }

        if (m_node[MAX_SIZE].m_valid)
        {
#if NF_PLATFORM == NF_PLATFORM_WIN
            (&(m_node[MAX_SIZE].m_data))->~Tp();
#else
            std::_Destroy(&(m_node[MAX_SIZE].m_data));
#endif
        }
        m_node[MAX_SIZE].m_next = MAX_SIZE;
        m_node[MAX_SIZE].m_prev = MAX_SIZE;
        m_node[MAX_SIZE].m_self = MAX_SIZE;
        m_node[MAX_SIZE].m_valid = false;
    }

protected:
    NFShmListNode<Tp>* m_node;
    int8_t m_mem[sizeof(NFShmListNode<Tp>) * (MAX_SIZE + 1)];
    ptrdiff_t m_freeStart;
    size_t m_size;
};

template<class Tp, size_t MAX_SIZE>
class NFShmList : protected NFShmListBase<Tp, MAX_SIZE>
{
    typedef NFShmListBase<Tp, MAX_SIZE> _Base;
protected:
    typedef void *_Void_pointer;
public:
    typedef NFShmList<Tp, MAX_SIZE> ListType;
    typedef Tp value_type;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef NFShmListNode<Tp> _Node;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

public:
    typedef NFShmListIterator<Tp, Tp &, Tp *, ListType> iterator;
    typedef NFShmListIterator<Tp, const Tp &, const Tp *, ListType> const_iterator;

    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;

protected:
    using _Base::m_node;
    using _Base::m_freeStart;
    using _Base::m_size;
protected:
    /**
     * @brief This function creates a node with the given data and assigns it to the free start position.
     * It then updates the free start position and constructs the data at the node position. It also sets the valid flag to true.
     * @param __x
     * @return
     */
    _Node *_M_create_node(const Tp &__x)
    {
        ptrdiff_t iSelf = m_freeStart;
        m_freeStart = m_node[m_freeStart].m_next;
#if NF_PLATFORM == NF_PLATFORM_WIN
        new (&m_node[iSelf].m_data) Tp(__x);
#else
        std::_Construct(&m_node[iSelf].m_data, __x);
#endif


        NF_ASSERT(!m_node[iSelf].m_valid);
        m_node[iSelf].m_valid = true;

        return &m_node[iSelf];
    }

    _Node *_M_create_node()
    {
        ptrdiff_t iSelf = m_freeStart;
        m_freeStart = m_node[m_freeStart].m_next;
#if NF_PLATFORM == NF_PLATFORM_WIN
        new (&m_node[iSelf].m_data) Tp();
#else
        std::_Construct(&m_node[iSelf].m_data, Tp());
#endif

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
#if NF_PLATFORM == NF_PLATFORM_WIN
        (&(pNode->m_data))->~Tp();
#else
        std::_Destroy(&(pNode->m_data));
#endif

        pNode->m_valid = false;
        pNode->m_next = m_freeStart;
        m_freeStart = pNode->m_self;
    }

public:
    explicit NFShmList()
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

    NFShmList(size_type __n, const Tp &__value)
    {
        insert(begin(), __n, __value);
    }

    explicit NFShmList(size_type __n)
    {
        insert(begin(), __n, Tp());
    }

    template<class _InputIterator>
    NFShmList(_InputIterator __first, _InputIterator __last)
    {
        insert(begin(), __first, __last);
    }

    NFShmList(const Tp *__first, const Tp *__last)
    {
        this->insert(begin(), __first, __last);
    }

    NFShmList(const_iterator __first, const_iterator __last)
    {
        this->insert(begin(), __first, __last);
    }

    template<size_t X_MAX_SIZE>
    NFShmList(const NFShmList<Tp, X_MAX_SIZE> &__x)
    {
        insert(begin(), __x.begin(), __x.end());
    }

    NFShmList(const NFShmList<Tp, MAX_SIZE> &__x)
    {
        insert(begin(), __x.begin(), __x.end());
    }

    NFShmList(const std::initializer_list<Tp> &list)
    {
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            push_back(*it);
        }
    }

    ~NFShmList()
    {

    }

    NFShmList<Tp, MAX_SIZE> &operator=(const NFShmList<Tp, MAX_SIZE> &__x);

public:
    iterator begin() { return iterator(this, m_node[MAX_SIZE].m_next); }

    const_iterator begin() const { return iterator(this, m_node[MAX_SIZE].m_next); }

    iterator end() { return iterator(this, MAX_SIZE); }

    const_iterator end() const { return iterator(this, MAX_SIZE); }

    reverse_iterator rbegin() { return reverse_iterator(end()); }

    const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

    reverse_iterator rend() { return reverse_iterator(begin()); }

    const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

    bool empty() const
    {
        if (m_node[MAX_SIZE].m_next == MAX_SIZE)
        {
            NF_ASSERT(m_size == 0);
        }
        return m_node[MAX_SIZE].m_next == MAX_SIZE;
    }

    bool full() const
    {
        if (m_freeStart == MAX_SIZE)
        {
            NF_ASSERT(m_size == MAX_SIZE);
        }
        return m_freeStart == MAX_SIZE;
    }

    size_type size() const
    {
        NF_ASSERT((size_type)std::distance(begin(), end()) == m_size);
        return m_size;
    }

    size_type max_size() const { return MAX_SIZE; }

    size_type capacity() const { return MAX_SIZE; }

    reference front() { return *begin(); }

    const_reference front() const { return *begin(); }

    reference back() { return *(--end()); }

    const_reference back() const { return *(--end()); }

    void swap(NFShmList<Tp, MAX_SIZE> &__x) {}

    _Node *GetNode(size_t index)
    {
        CHECK_EXPR(index <= MAX_SIZE, NULL, "index out of range:{}", index);
        return &m_node[index];
    }

    iterator GetIterator(size_t index)
    {
        CHECK_EXPR(index <= MAX_SIZE, end(), "index out of range:{}", index);
        return iterator(this, index);
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

        m_size++;
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
        m_size--;
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
    void _M_insert_dispatch(iterator __pos,
                            _InputIterator __first, _InputIterator __last,
                            __false_type);


    template<class _Integer>
    void _M_assign_dispatch(_Integer __n, _Integer __val, __true_type) { _M_fill_assign((size_type) __n, (Tp) __val); }

    template<class _InputIterator>
    void _M_assign_dispatch(_InputIterator __first, _InputIterator __last,
                            __false_type);

    void _M_fill_assign(size_type __n, const Tp &__val);

    void _M_fill_insert(iterator __pos, size_type __n, const Tp &__x);
};

template<class Tp, size_t MAX_SIZE>
inline bool operator==(const NFShmList<Tp, MAX_SIZE> &__x, const NFShmList<Tp, MAX_SIZE> &__y)
{
    typedef typename NFShmList<Tp, MAX_SIZE>::const_iterator const_iterator;
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
inline bool operator<(const NFShmList<Tp, MAX_SIZE> &__x,
                      const NFShmList<Tp, MAX_SIZE> &__y)
{
    return std::lexicographical_compare(__x.begin(), __x.end(),
                                        __y.begin(), __y.end());
}

template<class _Tp, size_t MAX_SIZE>
template<class _InputIter>
void NFShmList<_Tp, MAX_SIZE>::_M_insert_dispatch(iterator __position,
                                                  _InputIter __first, _InputIter __last,
                                                  std::__false_type)
{
    for (; __first != __last; ++__first)
        insert(__position, *__first);
}

template<class Tp, size_t MAX_SIZE>
void NFShmList<Tp, MAX_SIZE>::insert(iterator __position,
                                     const Tp *__first, const Tp *__last)
{
    for (; __first != __last; ++__first)
        insert(__position, *__first);
}

template<class Tp, size_t MAX_SIZE>
void NFShmList<Tp, MAX_SIZE>::insert(iterator __position,
                                     const_iterator __first, const_iterator __last)
{
    for (; __first != __last; ++__first)
        insert(__position, *__first);
}

template<class _Tp, size_t MAX_SIZE>
void NFShmList<_Tp, MAX_SIZE>::_M_fill_insert(iterator __position,
                                              size_type __n, const _Tp &__x)
{
    for (; __n > 0; --__n)
        insert(__position, __x);
}

template<class _Tp, size_t MAX_SIZE>
typename NFShmList<_Tp, MAX_SIZE>::iterator NFShmList<_Tp, MAX_SIZE>::erase(iterator __first,
                                                                            iterator __last)
{
    while (__first != __last)
        erase(__first++);
    return __last;
}

template<class _Tp, size_t MAX_SIZE>
void NFShmList<_Tp, MAX_SIZE>::resize(size_type __new_size, const _Tp &__x)
{
    iterator __i = begin();
    size_type __len = 0;
    for (; __i != end() && __len < __new_size; ++__i, ++__len);
    if (__len == __new_size)
        erase(__i, end());
    else                          // __i == end()
        insert(end(), __new_size - __len, __x);
}

template<class _Tp, size_t MAX_SIZE>
NFShmList<_Tp, MAX_SIZE> &NFShmList<_Tp, MAX_SIZE>::operator=(const NFShmList<_Tp, MAX_SIZE> &__x)
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

template<class _Tp, size_t MAX_SIZEc>
void NFShmList<_Tp, MAX_SIZEc>::_M_fill_assign(size_type __n, const _Tp &__val)
{
    iterator __i = begin();
    for (; __i != end() && __n > 0; ++__i, --__n)
        *__i = __val;
    if (__n > 0)
        insert(end(), __n, __val);
    else
        erase(__i, end());
}

template<class _Tp, size_t MAX_SIZEc>
template<class _InputIter>
void
NFShmList<_Tp, MAX_SIZEc>::_M_assign_dispatch(_InputIter __first2, _InputIter __last2,
                                              std::__false_type)
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


template<class _Tp, size_t MAX_SIZE>
void NFShmList<_Tp, MAX_SIZE>::remove(const _Tp &__value)
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

template<class _Tp, size_t MAX_SIZE>
void NFShmList<_Tp, MAX_SIZE>::unique()
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

template<class _Tp, size_t MAX_SIZE>
inline void NFShmList<_Tp, MAX_SIZE>::reverse()
{
    std::reverse(begin(), end());
}

template<class _Tp, size_t MAX_SIZE>
template<class _Predicate>
void NFShmList<_Tp, MAX_SIZE>::remove_if(_Predicate __pred)
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

template<class _Tp, size_t MAX_SIZE>
template<class _BinaryPredicate>
void NFShmList<_Tp, MAX_SIZE>::unique(_BinaryPredicate __binary_pred)
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