// -------------------------------------------------------------------------
//    @FileName         :    NFShmHashtable.h
//    @Author           :    gaoyi
//    @Date             :    23-2-6
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmHashtable
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFShmVector.h"
#include <iterator>
#include <algorithm>
#include <vector>

/**
 * @brief NFShmHashTable是一种基于内存的Hash表，
 * 它是使用共享内存实现的，可以在多个进程之间共享数据。它具有高性能，低内存使用，可用于存储和检索大量数据。
 * 此外，它还支持锁定机制，以确保数据的安全性和一致性
 */

template<class Val>
struct NFShmHashTableNode
{
    NFShmHashTableNode()
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
        m_next = -1;
        if (std::is_pod<Val>::value)
        {
            std::_Construct(&m_value, Val());
        }
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    int m_next;
    Val m_value;
    bool m_valid;
};

template<class Val, class Key, int MAX_SIZE, class HashFcn,
        class ExtractKey, class EqualKey>
class NFShmHashTable;

template<class Val, class Key, int MAX_SIZE, class HashFcn,
        class ExtractKey, class EqualKey>
struct NFShmHashTableIterator;

template<class Val, class Key, int MAX_SIZE, class HashFcn,
        class ExtractKey, class EqualKey>
struct NFShmHashTableConstIterator;

template<class Val, class Key, int MAX_SIZE, class HashFcn,
        class ExtractKey, class EqualKey>
struct NFShmHashTableIterator
{
    typedef NFShmHashTable<Val, Key, MAX_SIZE, HashFcn, ExtractKey, EqualKey>
            _Hashtable;
    typedef NFShmHashTableIterator<Val, Key, MAX_SIZE, HashFcn,
            ExtractKey, EqualKey>
            iterator;
    typedef NFShmHashTableConstIterator<Val, Key, MAX_SIZE, HashFcn,
            ExtractKey, EqualKey>
            const_iterator;
    typedef NFShmHashTableNode<Val> _Node;

    typedef std::forward_iterator_tag iterator_category;
    typedef Val value_type;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef Val &reference;
    typedef Val *pointer;

    _Node *m_curNode;
    _Hashtable *m_hashTable;

    NFShmHashTableIterator(_Node *__n, _Hashtable *__tab)
            : m_curNode(__n), m_hashTable(__tab) {}

    NFShmHashTableIterator() {}

    reference operator*() const { return m_curNode->m_value; }

    pointer operator->() const { return &(operator*()); }

    iterator &operator++();

    iterator operator++(int);

    bool operator==(const iterator &__it) const { return m_curNode == __it.m_curNode; }

    bool operator!=(const iterator &__it) const { return m_curNode != __it.m_curNode; }
};


template<class Val, class Key, int MAX_SIZE, class HashFcn,
        class ExtractKey, class EqualKey>
struct NFShmHashTableConstIterator
{
    typedef NFShmHashTable<Val, Key, MAX_SIZE, HashFcn, ExtractKey, EqualKey>
            _Hashtable;
    typedef NFShmHashTableIterator<Val, Key, MAX_SIZE, HashFcn,
            ExtractKey, EqualKey>
            iterator;
    typedef NFShmHashTableConstIterator<Val, Key, MAX_SIZE, HashFcn,
            ExtractKey, EqualKey>
            const_iterator;
    typedef NFShmHashTableNode<Val> _Node;

    typedef std::forward_iterator_tag iterator_category;
    typedef Val value_type;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef const Val &reference;
    typedef const Val *pointer;

    const _Node *m_curNode;
    const _Hashtable *m_hashTable;

    NFShmHashTableConstIterator(const _Node *__n, const _Hashtable *__tab)
            : m_curNode(__n), m_hashTable(__tab) {}

    NFShmHashTableConstIterator() {}

    NFShmHashTableConstIterator(const iterator &__it)
            : m_curNode(__it.m_curNode), m_hashTable(__it.m_hashTable) {}

    reference operator*() const { return m_curNode->m_value; }

    pointer operator->() const { return &(operator*()); }

    const_iterator &operator++();

    const_iterator operator++(int);

    bool operator==(const const_iterator &__it) const { return m_curNode == __it.m_curNode; }

    bool operator!=(const const_iterator &__it) const { return m_curNode != __it.m_curNode; }
};

template<class Val, class Key, int MAX_SIZE, class HF, class Ex, class Eq>
class NFShmHashTable;

template<class Val, class Key, int MAX_SIZE, class HF, class Ex, class Eq>
bool operator==(const NFShmHashTable<Val, Key, MAX_SIZE, HF, Ex, Eq> &__ht1,
                const NFShmHashTable<Val, Key, MAX_SIZE, HF, Ex, Eq> &__ht2);

template<class Val, class Key, int MAX_SIZE, class HashFcn,
        class ExtractKey, class EqualKey>
class NFShmHashTable
{
public:
    typedef Key key_type;
    typedef Val value_type;
    typedef HashFcn hasher;
    typedef EqualKey key_equal;

    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef value_type &reference;
    typedef const value_type &const_reference;

    hasher hash_funct() const { return m_hash; }

    key_equal key_eq() const { return m_equals; }

private:
    typedef NFShmHashTableNode<Val> _Node;

    _Node *_M_get_node()
    {
        int iNowAssignIdx = m_bucketsFreeIdx;
        m_bucketsFreeIdx = m_buckets[m_bucketsFreeIdx].m_next;
        return &m_buckets[iNowAssignIdx];
    }

    void _M_put_node(_Node *__p) {}

private:
    hasher m_hash;
    key_equal m_equals;
    ExtractKey m_get_key;
    NFShmVector<_Node, MAX_SIZE> m_buckets;
    int m_bucketsFreeIdx; //!<空闲链表头节点
    NFShmVector<int, MAX_SIZE> m_bucketsFirstIdx;
    size_type m_num_elements;

public:
    typedef NFShmHashTableIterator<Val, Key, MAX_SIZE, HashFcn, ExtractKey, EqualKey>
            iterator;
    typedef NFShmHashTableConstIterator<Val, Key, MAX_SIZE, HashFcn, ExtractKey, EqualKey>
            const_iterator;

    friend struct
            NFShmHashTableIterator<Val, Key, MAX_SIZE, HashFcn, ExtractKey, EqualKey>;
    friend struct
            NFShmHashTableConstIterator<Val, Key, MAX_SIZE, HashFcn, ExtractKey, EqualKey>;

public:
    NFShmHashTable(const HashFcn &__hf,
                   const EqualKey &__eql,
                   const ExtractKey &__ext)
            : m_hash(__hf),
              m_equals(__eql),
              m_get_key(__ext),
              m_num_elements(0)
    {
        _M_initialize_buckets();
    }

    NFShmHashTable(const HashFcn &__hf, const EqualKey &__eql)
            :
            m_hash(__hf),
            m_equals(__eql),
            m_get_key(ExtractKey()),
            m_num_elements(0)
    {
        _M_initialize_buckets();
    }

    NFShmHashTable(const NFShmHashTable &__ht)
            :
            m_hash(__ht.m_hash),
            m_equals(__ht.m_equals),
            m_get_key(__ht.m_get_key),
            m_num_elements(0)
    {
        _M_copy_from(__ht);
    }

    NFShmHashTable &operator=(const NFShmHashTable &__ht)
    {
        if (&__ht != this)
        {
            m_hash = __ht.m_hash;
            m_equals = __ht.m_equals;
            m_get_key = __ht.m_get_key;
            _M_copy_from(__ht);
        }
        return *this;
    }

    ~NFShmHashTable() { }

    size_type size() const { return m_num_elements; }

    size_type max_size() const { return MAX_SIZE; }

    bool empty() const { return size() == 0; }

    void swap(NFShmHashTable &__ht)
    {

    }

    iterator begin()
    {
        for (size_type __n = 0; __n < m_buckets.size(); ++__n)
            if (m_buckets[__n].m_valid)
                return iterator(m_buckets[__n], this);
        return end();
    }

    iterator end() { return iterator(0, this); }

    const_iterator begin() const
    {
        for (size_type __n = 0; __n < m_buckets.size(); ++__n)
            if (m_buckets[__n].m_valid)
                return const_iterator(m_buckets[__n], this);
        return end();
    }

    const_iterator end() const { return const_iterator(0, this); }

    template<class _Vl, class _Ky, int MAX_SIZE, class _HF, class _Ex, class _Eq>
    friend bool operator==(const NFShmHashTable<_Vl, _Ky, MAX_SIZE, _HF, _Ex, _Eq> &,
                           const NFShmHashTable<_Vl, _Ky, MAX_SIZE, _HF, _Ex, _Eq> &);

public:

    size_type bucket_count() const { return m_buckets.size(); }

    size_type max_bucket_count() const { return MAX_SIZE; }

    size_type elems_in_bucket(size_type __bucket) const
    {
        size_type __result = 0;
        for (_Node *__cur = m_buckets[__bucket]; __cur; __cur = __cur->m_next)
            __result += 1;
        return __result;
    }

    pair<iterator, bool> insert_unique(const value_type &__obj)
    {
        resize(m_num_elements + 1);
        return insert_unique_noresize(__obj);
    }

    iterator insert_equal(const value_type &__obj)
    {
        resize(m_num_elements + 1);
        return insert_equal_noresize(__obj);
    }

    pair<iterator, bool> insert_unique_noresize(const value_type &__obj);

    iterator insert_equal_noresize(const value_type &__obj);

    template<class _InputIterator>
    void insert_unique(_InputIterator __f, _InputIterator __l)
    {
        insert_unique(__f, __l, __ITERATOR_CATEGORY(__f));
    }

    template<class _InputIterator>
    void insert_equal(_InputIterator __f, _InputIterator __l)
    {
        insert_equal(__f, __l, __ITERATOR_CATEGORY(__f));
    }

    template<class _InputIterator>
    void insert_unique(_InputIterator __f, _InputIterator __l,
                       input_iterator_tag)
    {
        for (; __f != __l; ++__f)
            insert_unique(*__f);
    }

    template<class _InputIterator>
    void insert_equal(_InputIterator __f, _InputIterator __l,
                      input_iterator_tag)
    {
        for (; __f != __l; ++__f)
            insert_equal(*__f);
    }

    template<class _ForwardIterator>
    void insert_unique(_ForwardIterator __f, _ForwardIterator __l,
                       forward_iterator_tag)
    {
        size_type __n = 0;
        distance(__f, __l, __n);
        resize(m_num_elements + __n);
        for (; __n > 0; --__n, ++__f)
            insert_unique_noresize(*__f);
    }

    template<class _ForwardIterator>
    void insert_equal(_ForwardIterator __f, _ForwardIterator __l,
                      forward_iterator_tag)
    {
        size_type __n = 0;
        distance(__f, __l, __n);
        resize(m_num_elements + __n);
        for (; __n > 0; --__n, ++__f)
            insert_equal_noresize(*__f);
    }

    void insert_unique(const value_type *__f, const value_type *__l)
    {
        size_type __n = __l - __f;
        resize(m_num_elements + __n);
        for (; __n > 0; --__n, ++__f)
            insert_unique_noresize(*__f);
    }

    void insert_equal(const value_type *__f, const value_type *__l)
    {
        size_type __n = __l - __f;
        resize(m_num_elements + __n);
        for (; __n > 0; --__n, ++__f)
            insert_equal_noresize(*__f);
    }

    void insert_unique(const_iterator __f, const_iterator __l)
    {
        size_type __n = 0;
        distance(__f, __l, __n);
        resize(m_num_elements + __n);
        for (; __n > 0; --__n, ++__f)
            insert_unique_noresize(*__f);
    }

    void insert_equal(const_iterator __f, const_iterator __l)
    {
        size_type __n = 0;
        distance(__f, __l, __n);
        resize(m_num_elements + __n);
        for (; __n > 0; --__n, ++__f)
            insert_equal_noresize(*__f);
    }

    reference find_or_insert(const value_type &__obj);

    iterator find(const key_type &__key)
    {
        size_type __n = _M_bkt_num_key(__key);
        _Node *__first;
        for (__first = m_buckets[__n];
             __first && !m_equals(m_get_key(__first->m_value), __key);
             __first = __first->m_next) {}
        return iterator(__first, this);
    }

    const_iterator find(const key_type &__key) const
    {
        size_type __n = _M_bkt_num_key(__key);
        const _Node *__first;
        for (__first = m_buckets[__n];
             __first && !m_equals(m_get_key(__first->m_value), __key);
             __first = __first->m_next) {}
        return const_iterator(__first, this);
    }

    size_type count(const key_type &__key) const
    {
        const size_type __n = _M_bkt_num_key(__key);
        size_type __result = 0;

        for (const _Node *__cur = m_buckets[__n]; __cur; __cur = __cur->m_next)
            if (m_equals(m_get_key(__cur->m_value), __key))
                ++__result;
        return __result;
    }

    std::pair<iterator, iterator>
    equal_range(const key_type &__key);

    std::pair<const_iterator, const_iterator>
    equal_range(const key_type &__key) const;

    size_type erase(const key_type &__key);

    void erase(const iterator &__it);

    void erase(iterator __first, iterator __last);

    void erase(const const_iterator &__it);

    void erase(const_iterator __first, const_iterator __last);

    void resize(size_type __num_elements_hint);

    void clear();

private:
    void _M_initialize_buckets()
    {
        m_buckets.insert(m_buckets.end(), MAX_SIZE);
        m_bucketsFirstIdx.insert(m_bucketsFirstIdx.end(), MAX_SIZE);
        m_num_elements = 0;
        m_bucketsFreeIdx = 0;
        for(int i = 0; i < (int)m_buckets.size(); ++i)
        {
            m_buckets[i].m_next = i + 1;
            m_buckets[i].m_valid = false;
        }
        m_buckets[MAX_SIZE-1].m_next = -1;

        for(int i = 0; i < (int)m_bucketsFirstIdx.size(); ++i)
        {
            m_bucketsFirstIdx[i] = -1;
        }
    }

    size_type _M_bkt_num_key(const key_type &__key) const
    {
        return _M_bkt_num_key(__key, m_bucketsFirstIdx.size());
    }

    size_type _M_bkt_num(const value_type &__obj) const
    {
        return _M_bkt_num_key(m_get_key(__obj));
    }

    size_type _M_bkt_num_key(const key_type &__key, size_t __n) const
    {
        return m_hash(__key) % __n;
    }

    size_type _M_bkt_num(const value_type &__obj, size_t __n) const
    {
        return _M_bkt_num_key(m_get_key(__obj), __n);
    }

    _Node *_M_new_node(const value_type &__obj)
    {
        _Node *__n = _M_get_node();
        __n->m_valid = true;
        __n->m_next = -1;
        std::_Construct(&__n->m_value, __obj);

        //是冲突链表的第一个节点
        if(m_bucketsFirstIdx[__n] == -1)
        {
            m_bucketsFirstIdx[__n] = iNowAssignIdx;
        }
        else
        {
            m_buckets[iPreIndex].m_next = iNowAssignIdx;
        }
        return __n;
    }

    void _M_delete_node(_Node *__n)
    {
        destroy(&__n->m_value);
        _M_put_node(__n);
    }

    void _M_erase_bucket(const size_type __n, _Node *__first, _Node *__last);

    void _M_erase_bucket(const size_type __n, _Node *__last);

    void _M_copy_from(const NFShmHashTable &__ht);

};

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _ExK, class _EqK>
NFShmHashTableIterator<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK> &
NFShmHashTableIterator<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK>::operator++()
{
    const _Node *__old = m_curNode;
    m_curNode = m_curNode->m_next;
    if (!m_curNode)
    {
        size_type __bucket = m_hashTable->_M_bkt_num(__old->m_value);
        while (!m_curNode && ++__bucket < m_hashTable->m_buckets.size())
            m_curNode = m_hashTable->m_buckets[__bucket];
    }
    return *this;
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _ExK, class _EqK>
inline NFShmHashTableIterator<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK>
NFShmHashTableIterator<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK>::operator++(int)
{
    iterator __tmp = *this;
    ++*this;
    return __tmp;
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _ExK, class _EqK>
NFShmHashTableConstIterator<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK> &
NFShmHashTableConstIterator<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK>::operator++()
{
    const _Node *__old = m_curNode;
    m_curNode = m_curNode->m_next;
    if (!m_curNode)
    {
        size_type __bucket = m_hashTable->_M_bkt_num(__old->m_value);
        while (!m_curNode && ++__bucket < m_hashTable->m_buckets.size())
            m_curNode = m_hashTable->m_buckets[__bucket];
    }
    return *this;
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _ExK, class _EqK>
inline NFShmHashTableConstIterator<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK>
NFShmHashTableConstIterator<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK>::operator++(int)
{
    const_iterator __tmp = *this;
    ++*this;
    return __tmp;
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _ExK, class _EqK>
inline std::forward_iterator_tag
iterator_category(const NFShmHashTableIterator<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK> &)
{
    return std::forward_iterator_tag();
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _ExK, class _EqK>
inline _Val *
value_type(const NFShmHashTableIterator<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK> &)
{
    return (_Val *) 0;
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _ExK, class _EqK>
inline NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK>::difference_type *
distance_type(const NFShmHashTableIterator<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK> &)
{
    return (NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK>::difference_type *) 0;
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _ExK, class _EqK>
inline std::forward_iterator_tag
iterator_category(const NFShmHashTableConstIterator<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK> &)
{
    return std::forward_iterator_tag();
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _ExK, class _EqK>
inline _Val *
value_type(const NFShmHashTableConstIterator<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK> &)
{
    return (_Val *) 0;
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _ExK, class _EqK>
inline NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK>::difference_type *
distance_type(const NFShmHashTableConstIterator<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK> &)
{
    return (NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK>::difference_type *) 0;
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
bool operator==(const NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq> &__ht1,
                const NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq> &__ht2)
{
    typedef typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::_Node _Node;
    if (__ht1.m_buckets.size() != __ht2.m_buckets.size())
        return false;
    for (int __n = 0; __n < __ht1.m_buckets.size(); ++__n)
    {
        _Node *__cur1 = __ht1.m_buckets[__n];
        _Node *__cur2 = __ht2.m_buckets[__n];
        for (; __cur1 && __cur2 && __cur1->m_value == __cur2->m_value;
               __cur1 = __cur1->m_next, __cur2 = __cur2->m_next) {}
        if (__cur1 || __cur2)
            return false;
    }
    return true;
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
inline bool operator!=(const NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq> &__ht1,
                       const NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq> &__ht2)
{
    return !(__ht1 == __ht2);
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Extract, class _EqKey>
inline void swap(NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Extract, _EqKey> &__ht1,
                 NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Extract, _EqKey> &__ht2)
{
    __ht1.swap(__ht2);
}


template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
pair<typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::iterator, bool>
NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>
::insert_unique_noresize(const value_type &__obj)
{
    //已经没有可用的节点了
    if(m_bucketsFreeIdx < 0)
    {
        return std::pair<iterator, bool>(end(), false);
    }

    const size_type __n = _M_bkt_num(__obj);
    NF_ASSERT(__n < m_bucketsFirstIdx.size());

    int iPreIndex = -1;
    int iCurIndex = m_bucketsFirstIdx[__n];

    while(iCurIndex != -1)
    {
        //已经存在该Key则返回失败
        _Node *__cur = &m_buckets[iCurIndex];
        if (m_equals(m_get_key(__cur->m_value), m_get_key(__obj)))
        {
            return std::pair<iterator, bool>(iterator(__cur, this), false);
        }

        iPreIndex = iCurIndex;
        iCurIndex = m_buckets[iCurIndex].m_next;
    }

    int iNowAssignIdx = m_bucketsFreeIdx;
    m_bucketsFreeIdx = m_buckets[m_bucketsFreeIdx].m_next;
    ++m_num_elements;

    std::_Construct(&m_buckets[iNowAssignIdx].m_value, __obj);
    m_buckets[iNowAssignIdx].m_valid = true;
    m_buckets[iNowAssignIdx].m_next = -1;

    //是冲突链表的第一个节点
    if(m_bucketsFirstIdx[__n] == -1)
    {
        m_bucketsFirstIdx[__n] = iNowAssignIdx;
    }
    else
    {
        m_buckets[iPreIndex].m_next = iNowAssignIdx;
    }

    _Node *__tmp = _M_new_node(__obj);
    __tmp->m_next = __first;
    m_buckets[__n] = __tmp;
    ++m_num_elements;
    return pair<iterator, bool>(iterator(__tmp, this), true);
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::iterator
NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>
::insert_equal_noresize(const value_type &__obj)
{
    const size_type __n = _M_bkt_num(__obj);
    _Node *__first = m_buckets[__n];

    for (_Node *__cur = __first; __cur; __cur = __cur->m_next)
        if (m_equals(m_get_key(__cur->m_value), m_get_key(__obj)))
        {
            _Node *__tmp = _M_new_node(__obj);
            __tmp->m_next = __cur->m_next;
            __cur->m_next = __tmp;
            ++m_num_elements;
            return iterator(__tmp, this);
        }

    _Node *__tmp = _M_new_node(__obj);
    __tmp->m_next = __first;
    m_buckets[__n] = __tmp;
    ++m_num_elements;
    return iterator(__tmp, this);
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::reference
NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::find_or_insert(const value_type &__obj)
{
    resize(m_num_elements + 1);

    size_type __n = _M_bkt_num(__obj);
    _Node *__first = m_buckets[__n];

    for (_Node *__cur = __first; __cur; __cur = __cur->m_next)
        if (m_equals(m_get_key(__cur->m_value), m_get_key(__obj)))
            return __cur->m_value;

    _Node *__tmp = _M_new_node(__obj);
    __tmp->m_next = __first;
    m_buckets[__n] = __tmp;
    ++m_num_elements;
    return __tmp->m_value;
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
pair<typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::iterator,
        typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::iterator>
NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::equal_range(const key_type &__key)
{
    typedef pair<iterator, iterator> _Pii;
    const size_type __n = _M_bkt_num_key(__key);

    for (_Node *__first = m_buckets[__n]; __first; __first = __first->m_next)
        if (m_equals(m_get_key(__first->m_value), __key))
        {
            for (_Node *__cur = __first->m_next; __cur; __cur = __cur->m_next)
                if (!m_equals(m_get_key(__cur->m_value), __key))
                    return _Pii(iterator(__first, this), iterator(__cur, this));
            for (size_type __m = __n + 1; __m < m_buckets.size(); ++__m)
                if (m_buckets[__m])
                    return _Pii(iterator(__first, this),
                                iterator(m_buckets[__m], this));
            return _Pii(iterator(__first, this), end());
        }
    return _Pii(end(), end());
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
pair<typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::const_iterator,
        typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::const_iterator>
NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>
::equal_range(const key_type &__key) const
{
    typedef pair<const_iterator, const_iterator> _Pii;
    const size_type __n = _M_bkt_num_key(__key);

    for (const _Node *__first = m_buckets[__n];
         __first;
         __first = __first->m_next)
    {
        if (m_equals(m_get_key(__first->m_value), __key))
        {
            for (const _Node *__cur = __first->m_next;
                 __cur;
                 __cur = __cur->m_next)
                if (!m_equals(m_get_key(__cur->m_value), __key))
                    return _Pii(const_iterator(__first, this),
                                const_iterator(__cur, this));
            for (size_type __m = __n + 1; __m < m_buckets.size(); ++__m)
                if (m_buckets[__m])
                    return _Pii(const_iterator(__first, this),
                                const_iterator(m_buckets[__m], this));
            return _Pii(const_iterator(__first, this), end());
        }
    }
    return _Pii(end(), end());
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::size_type
NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::erase(const key_type &__key)
{
    const size_type __n = _M_bkt_num_key(__key);
    _Node *__first = m_buckets[__n];
    size_type __erased = 0;

    if (__first)
    {
        _Node *__cur = __first;
        _Node *__next = __cur->m_next;
        while (__next)
        {
            if (m_equals(m_get_key(__next->m_value), __key))
            {
                __cur->m_next = __next->m_next;
                _M_delete_node(__next);
                __next = __cur->m_next;
                ++__erased;
                --m_num_elements;
            }
            else
            {
                __cur = __next;
                __next = __cur->m_next;
            }
        }
        if (m_equals(m_get_key(__first->m_value), __key))
        {
            m_buckets[__n] = __first->m_next;
            _M_delete_node(__first);
            ++__erased;
            --m_num_elements;
        }
    }
    return __erased;
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::erase(const iterator &__it)
{
    _Node *__p = __it.m_curNode;
    if (__p)
    {
        const size_type __n = _M_bkt_num(__p->m_value);
        _Node *__cur = m_buckets[__n];

        if (__cur == __p)
        {
            m_buckets[__n] = __cur->m_next;
            _M_delete_node(__cur);
            --m_num_elements;
        }
        else
        {
            _Node *__next = __cur->m_next;
            while (__next)
            {
                if (__next == __p)
                {
                    __cur->m_next = __next->m_next;
                    _M_delete_node(__next);
                    --m_num_elements;
                    break;
                }
                else
                {
                    __cur = __next;
                    __next = __cur->m_next;
                }
            }
        }
    }
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>
::erase(iterator __first, iterator __last)
{
    size_type __f_bucket = __first.m_curNode ?
                           _M_bkt_num(__first.m_curNode->m_value) : m_buckets.size();
    size_type __l_bucket = __last.m_curNode ?
                           _M_bkt_num(__last.m_curNode->m_value) : m_buckets.size();

    if (__first.m_curNode == __last.m_curNode)
        return;
    else if (__f_bucket == __l_bucket)
        _M_erase_bucket(__f_bucket, __first.m_curNode, __last.m_curNode);
    else
    {
        _M_erase_bucket(__f_bucket, __first.m_curNode, 0);
        for (size_type __n = __f_bucket + 1; __n < __l_bucket; ++__n)
            _M_erase_bucket(__n, 0);
        if (__l_bucket != m_buckets.size())
            _M_erase_bucket(__l_bucket, __last.m_curNode);
    }
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
inline void
NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::erase(const_iterator __first,
                                                           const_iterator __last)
{
    erase(iterator(const_cast<_Node *>(__first.m_curNode),
                   const_cast<NFShmHashTable *>(__first.m_hashTable)),
          iterator(const_cast<_Node *>(__last.m_curNode),
                   const_cast<NFShmHashTable *>(__last.m_hashTable)));
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
inline void
NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::erase(const const_iterator &__it)
{
    erase(iterator(const_cast<_Node *>(__it.m_curNode),
                   const_cast<NFShmHashTable *>(__it.m_hashTable)));
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>
::resize(size_type __num_elements_hint)
{
    const size_type __old_n = m_buckets.size();
    if (__num_elements_hint > __old_n)
    {
        const size_type __n = _M_next_size(__num_elements_hint);
        if (__n > __old_n)
        {
            vector<_Node *> __tmp(__n, (_Node *) (0),
                                  m_buckets.get_allocator());
            for (size_type __bucket = 0; __bucket < __old_n; ++__bucket)
            {
                _Node *__first = m_buckets[__bucket];
                while (__first)
                {
                    size_type __new_bucket = _M_bkt_num(__first->m_value, __n);
                    m_buckets[__bucket] = __first->m_next;
                    __first->m_next = __tmp[__new_bucket];
                    __tmp[__new_bucket] = __first;
                    __first = m_buckets[__bucket];
                }
            }
            m_buckets.swap(__tmp);
        }
    }
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>
::_M_erase_bucket(const size_type __n, _Node *__first, _Node *__last)
{
    _Node *__cur = m_buckets[__n];
    if (__cur == __first)
        _M_erase_bucket(__n, __last);
    else
    {
        _Node *__next;
        for (__next = __cur->m_next;
             __next != __first;
             __cur = __next, __next = __cur->m_next);
        while (__next != __last)
        {
            __cur->m_next = __next->m_next;
            _M_delete_node(__next);
            __next = __cur->m_next;
            --m_num_elements;
        }
    }
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>
::_M_erase_bucket(const size_type __n, _Node *__last)
{
    _Node *__cur = m_buckets[__n];
    while (__cur != __last)
    {
        _Node *__next = __cur->m_next;
        _M_delete_node(__cur);
        __cur = __next;
        m_buckets[__n] = __cur;
        --m_num_elements;
    }
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::clear()
{
    m_buckets.clear();
    m_num_elements = 0;
}


template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>
::_M_copy_from(const NFShmHashTable &__ht)
{
    m_buckets.clear();
    m_buckets = __ht.m_buckets;
    m_num_elements = __ht.m_num_elements;
}
