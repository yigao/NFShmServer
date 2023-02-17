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
        m_self = 0;
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
    size_t m_self;
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

    /**
     * @brief This function gets a node from the free list of the NFShmHashTable, assigns the index to the current free index,
     * increases the number of elements, and returns the node.
     * @return
     */
    _Node *_M_get_node()
    {
        //已经没有可用的节点了
        if (m_firstFreeIdx < 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "The NFShmHashTable No Enough Space! New Node Failed!");
            return NULL;
        }

        int iNowAssignIdx = m_firstFreeIdx;
        m_firstFreeIdx = m_buckets[m_firstFreeIdx].m_next;
        ++m_num_elements;
        return &m_buckets[iNowAssignIdx];
    }

    void _M_put_node(_Node *__p)
    {
        __p->m_next = m_firstFreeIdx;
        m_firstFreeIdx = __p->m_self;
        --m_num_elements;
    }

private:
    hasher m_hash;
    key_equal m_equals;
    ExtractKey m_get_key;
    NFShmVector<_Node, MAX_SIZE> m_buckets;
    int m_firstFreeIdx; //!<空闲链表头节点
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
    NFShmHashTable()
    {
        m_hash = HashFcn();
        m_equals = EqualKey();
        m_get_key = ExtractKey();

        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }

    NFShmHashTable(const NFShmHashTable &__ht) : m_hash(__ht.m_hash), m_equals(__ht.m_equals), m_get_key(__ht.m_get_key), m_num_elements(0)
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

    ~NFShmHashTable()
    {

    }

    int CreateInit()
    {
        _M_initialize_buckets();
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    size_type size() const { return m_num_elements; }

    size_type max_size() const { return MAX_SIZE; }

    bool empty() const { return size() == 0; }

    bool full() const { return size() == MAX_SIZE; }

    size_t left_size() const { return size() >= MAX_SIZE ? 0 : MAX_SIZE - size(); }

    _Node *get_node(int idx)
    {
        if (idx >= 0 && idx < (int) m_buckets.size())
        {
            return &m_buckets[idx];
        }
        return NULL;
    }

    const _Node *get_node(int idx) const
    {
        if (idx >= 0 && idx < (int) m_buckets.size())
        {
            return &m_buckets[idx];
        }
        return NULL;
    }

    void swap(NFShmHashTable &__ht)
    {

    }

    iterator begin()
    {
        for (size_type __n = 0; __n < m_bucketsFirstIdx.size(); ++__n)
            if (m_bucketsFirstIdx[__n] != -1)
                return iterator(&m_buckets[m_bucketsFirstIdx[__n]], this);
        return end();
    }

    iterator end() { return iterator(0, this); }

    const_iterator begin() const
    {
        for (size_type __n = 0; __n < m_bucketsFirstIdx.size(); ++__n)
            if (m_bucketsFirstIdx[__n] != -1)
                return const_iterator(&m_buckets[m_bucketsFirstIdx[__n]], this);
        return end();
    }

    const_iterator end() const { return const_iterator(0, this); }

    template<class _Vl, class _Ky, int _MAX_SIZE, class _HF, class _Ex, class _Eq>
    friend bool operator==(const NFShmHashTable<_Vl, _Ky, _MAX_SIZE, _HF, _Ex, _Eq> &,
                           const NFShmHashTable<_Vl, _Ky, _MAX_SIZE, _HF, _Ex, _Eq> &);

public:

    size_type bucket_count() const { return m_buckets.size(); }

    size_type max_bucket_count() const { return MAX_SIZE; }

    size_type elems_in_bucket(size_type __bucket) const
    {
        size_type __result = 0;
        for (size_type __curIndex = __bucket; __curIndex != -1; __curIndex = m_buckets[__curIndex].m_next)
            __result += 1;
        return __result;
    }

    std::pair<iterator, bool> insert_unique(const value_type &__obj)
    {
        return insert_unique_noresize(__obj);
    }

    iterator insert_equal(const value_type &__obj)
    {
        return insert_equal_noresize(__obj);
    }

    std::pair<iterator, bool> insert_unique_noresize(const value_type &__obj);

    iterator insert_equal_noresize(const value_type &__obj);

    template<class _InputIterator>
    void insert_unique(_InputIterator __f, _InputIterator __l)
    {
        insert_unique(__f, __l, typename std::iterator_traits<_InputIterator>::iterator_category());
    }

    template<class _InputIterator>
    void insert_equal(_InputIterator __f, _InputIterator __l)
    {
        insert_equal(__f, __l, typename std::iterator_traits<_InputIterator>::iterator_category());
    }

    template<class _InputIterator>
    void insert_unique(_InputIterator __f, _InputIterator __l,
                       std::input_iterator_tag)
    {
        for (; __f != __l; ++__f)
            insert_unique(*__f);
    }

    template<class _InputIterator>
    void insert_equal(_InputIterator __f, _InputIterator __l,
                      std::input_iterator_tag)
    {
        for (; __f != __l; ++__f)
            insert_equal(*__f);
    }

    template<class _ForwardIterator>
    void insert_unique(_ForwardIterator __f, _ForwardIterator __l,
                       std::forward_iterator_tag)
    {
        size_type __n = std::distance(__f, __l);
        size_type left = left_size();
        if (left < __n)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "NFShmHashTable Has No Enough Space:(left:{}, insert:{}), only insert left:{}", left, __n, left);
            __n = left;
        }
        for (; __n > 0; --__n, ++__f)
            insert_unique_noresize(*__f);
    }

    template<class _ForwardIterator>
    void insert_equal(_ForwardIterator __f, _ForwardIterator __l,
                      std::forward_iterator_tag)
    {
        size_type __n = std::distance(__f, __l);
        size_type left = left_size();
        if (left < __n)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "NFShmHashTable Has No Enough Space:(left:{}, insert:{}), only insert left:{}", left, __n, left);
            __n = left;
        }
        resize(m_num_elements + __n);
        for (; __n > 0; --__n, ++__f)
            insert_equal_noresize(*__f);
    }

    void insert_unique(const value_type *__f, const value_type *__l)
    {
        size_type __n = __l - __f;
        size_type left = left_size();
        if (left < __n)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "NFShmHashTable Has No Enough Space:(left:{}, insert:{}), only insert left:{}", left, __n, left);
            __n = left;
        }
        for (; __n > 0; --__n, ++__f)
            insert_unique_noresize(*__f);
    }

    void insert_equal(const value_type *__f, const value_type *__l)
    {
        size_type __n = __l - __f;
        size_type left = left_size();
        if (left < __n)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "NFShmHashTable Has No Enough Space:(left:{}, insert:{}), only insert left:{}", left, __n, left);
            __n = left;
        }
        for (; __n > 0; --__n, ++__f)
            insert_equal_noresize(*__f);
    }

    void insert_unique(const_iterator __f, const_iterator __l)
    {
        size_type __n = std::distance(__f, __l);
        size_type left = left_size();
        if (left < __n)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "NFShmHashTable Has No Enough Space:(left:{}, insert:{}), only insert left:{}", left, __n, left);
            __n = left;
        }
        for (; __n > 0; --__n, ++__f)
            insert_unique_noresize(*__f);
    }

    void insert_equal(const_iterator __f, const_iterator __l)
    {
        size_type __n = std::distance(__f, __l);
        size_type left = left_size();
        if (left < __n)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "NFShmHashTable Has No Enough Space:(left:{}, insert:{}), only insert left:{}", left, __n, left);
            __n = left;
        }
        for (; __n > 0; --__n, ++__f)
            insert_equal_noresize(*__f);
    }

    reference find_or_insert(const value_type &__obj);

    iterator find(const key_type &__key)
    {
        size_type __n = _M_bkt_num_key(__key);
        NF_ASSERT(__n < m_bucketsFirstIdx.size());
        int iFirstIndex = m_bucketsFirstIdx[__n];

        _Node *__first;
        for (__first = get_node(iFirstIndex);
             __first && !m_equals(m_get_key(__first->m_value), __key);
             __first = get_node(__first->m_next)) {}

        return iterator(__first, this);
    }

    const_iterator find(const key_type &__key) const
    {
        size_type __n = _M_bkt_num_key(__key);
        NF_ASSERT(__n < m_bucketsFirstIdx.size());
        int iFirstIndex = m_bucketsFirstIdx[__n];

        const _Node *__first;
        for (__first = get_node(iFirstIndex);
             __first && !m_equals(m_get_key(__first->m_value), __key);
             __first = get_node(__first->m_next)) {}

        return const_iterator(__first, this);
    }

    size_type count(const key_type &__key) const
    {
        const size_type __n = _M_bkt_num_key(__key);
        size_type __result = 0;
        NF_ASSERT(__n < m_bucketsFirstIdx.size());
        int iFirstIndex = m_bucketsFirstIdx[__n];

        for (const _Node *__cur = get_node(iFirstIndex); __cur; __cur = get_node(__cur->m_next))
        {
            if (m_equals(m_get_key(__cur->m_value), __key))
            {
                ++__result;
            }
        }

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

    void debug_string()
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "----------------NFShmHashTable begin size:{} MAX_SIZE:{}----------------", size(),
                  MAX_SIZE);

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "buckets begin:");
        for (int i = 0; i < (int) m_buckets.size(); ++i)
        {
            if (m_buckets[i].m_valid)
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "[{}]=next:{})", i, m_buckets[i].m_next);
            }
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "buckets end");
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "first idx begin:");
        for (int i = 0; i < (int) m_bucketsFirstIdx.size(); ++i)
        {
            if (m_bucketsFirstIdx[i] != -1)
            {
                int nodes = 0;
                std::string node_str;
                for (_Node *curNode = get_node(m_bucketsFirstIdx[i]); curNode; curNode = get_node(curNode->m_next))
                {
                    nodes++;
                    if (std::is_integral<value_type>::value || std::is_same<value_type, std::string>::value)
                    {
                        node_str += NF_FORMAT(" (node:{} bucket idx:{} valid:{} next:{} value:{}) ", nodes, curNode->m_self, curNode->m_valid,
                                              curNode->m_next, curNode->m_value);
                    }
                    else
                    {
                        node_str += NF_FORMAT(" (node:{} bucket idx:{} valid:{} next:{}) ", nodes, curNode->m_self, curNode->m_valid,
                                              curNode->m_next);
                    }
                }
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "frist idx:{} value:{} = nodes:{})", i, m_bucketsFirstIdx[i], node_str);
            }
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "first idx end");

        std::string str;
        for (auto iter = begin(); iter != end(); iter++)
        {
            if (std::is_integral<value_type>::value || std::is_same<value_type, std::string>::value)
            {
                str += NF_FORMAT(" (first idx:{} buckets idx:{} num:{} value:{} next:{}) ", _M_bkt_num(*iter), iter.m_curNode->m_self,
                                 count(m_get_key(*iter)), *iter, iter.m_curNode->m_next);
            }
            else
            {
                str += NF_FORMAT(" (first idx:{} buckets idx:{} num:{} next:{}) ", _M_bkt_num(*iter), iter.m_curNode->m_self, count(m_get_key(*iter)),
                                 iter.m_curNode->m_next);
            }
        }

        std::string freeStr;
        for (auto freeNode = get_node(m_firstFreeIdx); freeNode != NULL; freeNode = get_node(freeNode->m_next))
        {
            freeStr += NF_FORMAT(" (buckets idx:{} next:{}) ", freeNode->m_self, freeNode->m_next);
        }

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "iters:{}", str);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "first free idx:{} free list:{}", m_firstFreeIdx, freeStr);

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "----------------NFShmHashTable end -------------------------------------");
    }

private:
    /**
     * @brief  This function initializes the buckets by setting all buckets to be invalid,
     * the next index to be the next index in the array and the first index of each bucket to be -1.
     * It also sets the number of elements and the free index to 0.
     */
    void _M_initialize_buckets()
    {
        m_buckets.insert(m_buckets.end(), MAX_SIZE, _Node());
        m_bucketsFirstIdx.insert(m_bucketsFirstIdx.end(), MAX_SIZE, -1);
        m_num_elements = 0;
        m_firstFreeIdx = 0;
        for (int i = 0; i < (int) m_buckets.size(); ++i)
        {
            m_buckets[i].m_next = i + 1;
            m_buckets[i].m_valid = false;
            m_buckets[i].m_self = i;
        }

        m_buckets[MAX_SIZE - 1].m_next = -1;

        for (int i = 0; i < (int) m_bucketsFirstIdx.size(); ++i)
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

    /**
     * @brief  This function creates a new node in the linked list and initializes it with the given value.
     * It allocates memory for the node and sets the valid and next flags to true and -1 respectively.
     * Finally, the node's value is constructed using the given value.
     * @param __obj
     * @return
     */
    _Node *_M_new_node(const value_type &__obj)
    {
        _Node *pNode = _M_get_node();
        if (pNode)
        {
            pNode->m_valid = true;
            pNode->m_next = -1;
            std::_Construct(&pNode->m_value, __obj);
        }

        return pNode;
    }

    /**
     * @brief This function deletes a node in the linked list by destroying its value and constructing a new one, then putting the node back.
     * @param __n
     */
    void _M_delete_node(_Node *__n)
    {
        __n->m_valid = false;
        std::_Destroy(&__n->m_value);
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
    m_curNode = m_hashTable->get_node(m_curNode->m_next);
    if (!m_curNode)
    {
        size_type __bucket = m_hashTable->_M_bkt_num(__old->m_value);
        while (!m_curNode && ++__bucket < m_hashTable->m_bucketsFirstIdx.size())
            m_curNode = m_hashTable->get_node(m_hashTable->m_bucketsFirstIdx[__bucket]);
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
    m_curNode = m_hashTable->get_node(m_curNode->m_next);
    if (!m_curNode)
    {
        size_type __bucket = m_hashTable->_M_bkt_num(__old->m_value);
        while (!m_curNode && ++__bucket < m_hashTable->m_bucketsFirstIdx.size())
            m_curNode = m_hashTable->get_node(m_hashTable->m_bucketsFirstIdx[__bucket]);
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
inline typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK>::difference_type *
distance_type(const NFShmHashTableIterator<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK> &)
{
    return (typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK>::difference_type *) 0;
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
inline typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK>::difference_type *
distance_type(const NFShmHashTableConstIterator<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK> &)
{
    return (typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _ExK, _EqK>::difference_type *) 0;
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
bool operator==(const NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq> &__ht1,
                const NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq> &__ht2)
{
    typedef typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::_Node _Node;
    if (__ht1.m_bucketsFirstIdx.size() != __ht2.m_bucketsFirstIdx.size())
        return false;
    for (int __n = 0; __n < (int) __ht1.m_bucketsFirstIdx.size(); ++__n)
    {
        _Node *__cur1 = get_node(__ht1.m_bucketsFirstIdx[__n]);
        _Node *__cur2 = get_node(__ht2.m_bucketsFirstIdx[__n]);
        for (; __cur1 && __cur2 && __cur1->m_value == __cur2->m_value;
               __cur1 = get_node(__cur1->m_next), get_node(__cur2 = __cur2->m_next)) {}
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


/**
 * @brief insert_unique_noresize() inserts the given object into the NFShmHashTable,
 * if it is not already present. It returns a std::pair consisting of an iterator to the element
 * and a bool value which is true if the element was successfully inserted.
 * The bool value is false if the element was already present in the NFShmHashTable.
 * This function does not check for the size of the NFShmHashTable, and does not resize it.
 * @tparam _Val
 * @tparam _Key
 * @tparam MAX_SIZE
 * @tparam _HF
 * @tparam _Ex
 * @tparam _Eq
 * @param __obj
 * @return
 */
template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
std::pair<typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::iterator, bool>
NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>
::insert_unique_noresize(const value_type &__obj)
{
    const size_type __n = _M_bkt_num(__obj);
    NF_ASSERT(__n < m_bucketsFirstIdx.size());

    int iFirstIndex = m_bucketsFirstIdx[__n];
    for (_Node *__cur = get_node(iFirstIndex); __cur; __cur = get_node(__cur->m_next))
    {
        if (m_equals(m_get_key(__cur->m_value), m_get_key(__obj)))
        {
            return std::pair<iterator, bool>(iterator(__cur, this), false);
        }
    }

    _Node *__tmp = _M_new_node(__obj);
    if (__tmp == NULL)
    {
        return std::pair<iterator, bool>(end(), false);
    }

    __tmp->m_next = iFirstIndex;
    m_bucketsFirstIdx[__n] = __tmp->m_self;
    return std::pair<iterator, bool>(iterator(__tmp, this), true);
}

/**
 * @brief This function inserts an element into the hash table with no resize.
 * It takes the value_type as a parameter and returns an iterator.
 * It first finds the bucket number for the parameter and then checks if the key already exists in the table.
 * If so, it creates a new node and inserts it into the table. Otherwise, it sets the previous node's next pointer to the new node.
 * Finally, it returns an iterator to the new node.
 * @tparam _Val
 * @tparam _Key
 * @tparam MAX_SIZE
 * @tparam _HF
 * @tparam _Ex
 * @tparam _Eq
 * @param __obj
 * @return
 */
template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::iterator
NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>
::insert_equal_noresize(const value_type &__obj)
{
    //已经没有可用的节点了
    const size_type __n = _M_bkt_num(__obj);
    NF_ASSERT(__n < m_bucketsFirstIdx.size());

    int iFirstIndex = m_bucketsFirstIdx[__n];

    for (_Node *__cur = get_node(iFirstIndex); __cur; __cur = get_node(__cur->m_next))
    {
        if (m_equals(m_get_key(__cur->m_value), m_get_key(__obj)))
        {
            _Node *__tmp = _M_new_node(__obj);
            if (__tmp == NULL)
            {
                return end();
            }
            __tmp->m_next = __cur->m_next;
            __cur->m_next = __tmp->m_self;
            return iterator(__tmp, this);
        }
    }

    _Node *__tmp = _M_new_node(__obj);
    if (__tmp == NULL)
    {
        return end();
    }

    __tmp->m_next = iFirstIndex;
    m_bucketsFirstIdx[__n] = __tmp->m_self;
    return iterator(__tmp, this);
}

/**
 * @brief Finds the value associated with the given key or inserts the given value if it is not found.
 * Returns a reference to the found or inserted value.
 * The key is obtained from the given value using the get_key function.
 * The given value is stored in a node and linked to the bucket with the given key.
 * If the key is already present, the existing node is returned.
 * @tparam _Val
 * @tparam _Key
 * @tparam MAX_SIZE
 * @tparam _HF
 * @tparam _Ex
 * @tparam _Eq
 * @param __obj
 * @return
 */
template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::reference
NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::find_or_insert(const value_type &__obj)
{
    const size_type __n = _M_bkt_num(__obj);
    NF_ASSERT(__n < m_bucketsFirstIdx.size());

    int iFirstIndex = m_bucketsFirstIdx[__n];
    for (_Node *__cur = get_node(iFirstIndex); __cur; __cur = get_node(__cur->m_next))
    {
        if (m_equals(m_get_key(__cur->m_value), m_get_key(__obj)))
        {
            return __cur->m_value;
        }
    }

    _Node *__tmp = _M_new_node(__obj);
    NF_ASSERT(__tmp != NULL);

    __tmp->m_next = m_bucketsFirstIdx[__n];
    m_bucketsFirstIdx[__n] = __tmp->m_self;
    return __tmp->m_value;
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
std::pair<typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::iterator,
        typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::iterator>
NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::equal_range(const key_type &__key)
{
    typedef std::pair<iterator, iterator> _Pii;
    const size_type __n = _M_bkt_num_key(__key);
    NF_ASSERT(__n < m_bucketsFirstIdx.size());

    int iFirstIndex = m_bucketsFirstIdx[__n];
    for (_Node *__first = get_node(iFirstIndex); __first; __first = get_node(__first->m_next))
    {
        if (m_equals(m_get_key(__first->m_value), __key))
        {
            for (_Node *__cur = get_node(__first->m_next); __cur; __cur = get_node(__cur->m_next))
            {
                if (!m_equals(m_get_key(__cur->m_value), __key))
                {
                    return _Pii(iterator(__first, this), iterator(__cur, this));
                }
            }
            for (size_type __m = __n + 1; __m < m_bucketsFirstIdx.size(); ++__m)
            {
                if (m_bucketsFirstIdx[__m] != -1)
                {
                    return _Pii(iterator(__first, this), iterator(get_node(m_bucketsFirstIdx[__m]), this));
                }
            }
            return _Pii(iterator(__first, this), end());
        }
    }
    return _Pii(end(), end());
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
std::pair<typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::const_iterator,
        typename NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::const_iterator>
NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>
::equal_range(const key_type &__key) const
{
    typedef std::pair<const_iterator, const_iterator> _Pii;
    const size_type __n = _M_bkt_num_key(__key);
    NF_ASSERT(__n < m_bucketsFirstIdx.size());

    int iFirstIndex = m_bucketsFirstIdx[__n];
    for (_Node *__first = get_node(iFirstIndex); __first; __first = get_node(__first->m_next))
    {
        if (m_equals(m_get_key(__first->m_value), __key))
        {
            for (_Node *__cur = get_node(__first->m_next); __cur; __cur = get_node(__cur->m_next))
            {
                if (!m_equals(m_get_key(__cur->m_value), __key))
                {
                    return _Pii(const_iterator(__first, this), const_iterator(__cur, this));
                }
            }
            for (size_type __m = __n + 1; __m < m_bucketsFirstIdx.size(); ++__m)
            {
                if (m_bucketsFirstIdx[__m] != -1)
                {
                    return _Pii(const_iterator(__first, this), const_iterator(get_node(m_bucketsFirstIdx[__m]), this));
                }
            }
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
    NF_ASSERT(__n < m_bucketsFirstIdx.size());
    int iFirstIndex = m_bucketsFirstIdx[__n];
    size_type __erased = 0;

    _Node *__first = get_node(iFirstIndex);
    if (__first)
    {
        _Node *__cur = __first;
        _Node *__next = get_node(__cur->m_next);
        while (__next)
        {
            if (m_equals(m_get_key(__next->m_value), __key))
            {
                __cur->m_next = __next->m_next;
                _M_delete_node(__next);
                __next = get_node(__cur->m_next);
                ++__erased;
            }
            else
            {
                __cur = __next;
                __next = get_node(__cur->m_next);
            }
        }
        if (m_equals(m_get_key(__first->m_value), __key))
        {
            m_bucketsFirstIdx[__n] = __first->m_next;
            _M_delete_node(__first);
            ++__erased;
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
        NF_ASSERT(__n < m_bucketsFirstIdx.size());
        int iCurIndex = m_bucketsFirstIdx[__n];
        _Node *__cur = get_node(iCurIndex);

        if (__cur == __p)
        {
            m_bucketsFirstIdx[__n] = __cur->m_next;
            _M_delete_node(__cur);
        }
        else
        {
            _Node *__next = get_node(__cur->m_next);
            while (__next)
            {
                if (__next == __p)
                {
                    __cur->m_next = __next->m_next;
                    _M_delete_node(__next);
                    break;
                }
                else
                {
                    __cur = __next;
                    __next = get_node(__cur->m_next);
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

/**
 * @brief do nothing
 * @tparam _Val
 * @tparam _Key
 * @tparam MAX_SIZE
 * @tparam _HF
 * @tparam _Ex
 * @tparam _Eq
 * @param __num_elements_hint
 */
template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>
::resize(size_type __num_elements_hint)
{

}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>
::_M_erase_bucket(const size_type __n, _Node *__first, _Node *__last)
{
    _Node *__cur = get_node(m_bucketsFirstIdx[__n]);
    if (__cur == __first)
        _M_erase_bucket(__n, __last);
    else
    {
        NF_ASSERT(__cur);
        _Node *__next;
        for (__next = get_node(__cur->m_next);
             __next != __first;
             __cur = __next, __next = get_node(__cur->m_next));
        while (__next != __last)
        {
            __cur->m_next = __next->m_next;
            _M_delete_node(__next);
            __next = get_node(__cur->m_next);
        }
    }
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>
::_M_erase_bucket(const size_type __n, _Node *__last)
{
    _Node *__cur = get_node(m_bucketsFirstIdx[__n]);
    while (__cur != __last)
    {
        NF_ASSERT(__cur);
        _Node *__next = get_node(__cur->m_next);
        _M_delete_node(__cur);
        __cur = __next;
        m_bucketsFirstIdx[__n] = __cur ? __cur->m_self : -1;
    }
}

template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>::clear()
{
    m_buckets.clear();
    m_bucketsFirstIdx.clear();
    _M_initialize_buckets();
}


template<class _Val, class _Key, int MAX_SIZE, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val, _Key, MAX_SIZE, _HF, _Ex, _Eq>
::_M_copy_from(const NFShmHashTable &__ht)
{
    m_buckets.clear();
    m_bucketsFirstIdx.clear();
    m_buckets = __ht.m_buckets;
    m_bucketsFirstIdx = __ht.m_bucketsFirstIdx;
    m_num_elements = __ht.m_num_elements;
    m_firstFreeIdx = __ht.m_firstFreeIdx;
}
