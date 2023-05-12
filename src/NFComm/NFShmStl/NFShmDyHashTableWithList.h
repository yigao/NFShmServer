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
#include "NFShmList.h"
#include <iterator>
#include <algorithm>
#include <vector>

/**
 * @brief NFShmHashTable是一种基于内存的Hash表，
 * 它是使用共享内存实现的，可以在多个进程之间共享数据。它具有高性能，低内存使用，可用于存储和检索大量数据。
 * 此外，它还支持锁定机制，以确保数据的安全性和一致性
 */

template<class Val>
struct NFShmDyHashTableWithListNode
{
    NFShmDyHashTableWithListNode()
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
        m_list_pos = -1;
        m_self = 0;

        if (std::numeric_limits<Val>::is_specialized)
        {
            std::_Construct(&m_value);
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
    int m_list_pos;
};

template<class Val, class Key, class HashFcn,
        class ExtractKey, class EqualKey>
class NFShmDyHashTableWithList;

template<class Val, class Key, class HashFcn,
        class ExtractKey, class EqualKey>
struct NFShmDyHashTableWithListIterator;

template<class Val, class Key, class HashFcn,
        class ExtractKey, class EqualKey>
struct NFShmDyHashTableWithListConstIterator;

template<class Val, class Key, class HashFcn,
        class ExtractKey, class EqualKey>
struct NFShmDyHashTableWithListIterator
{
    typedef NFShmDyHashTableWithList<Val, Key, HashFcn, ExtractKey, EqualKey>
            _Hashtable;
    typedef NFShmDyHashTableWithListIterator<Val, Key, HashFcn,
            ExtractKey, EqualKey>
            iterator;
    typedef NFShmDyHashTableWithListConstIterator<Val, Key, HashFcn,
            ExtractKey, EqualKey>
            const_iterator;
    typedef NFShmDyHashTableWithListNode<Val> _Node;

    typedef std::forward_iterator_tag iterator_category;
    typedef Val value_type;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef Val &reference;
    typedef Val *pointer;

    _Node *m_curNode;
    _Hashtable *m_hashTable;

    NFShmDyHashTableWithListIterator(_Node *__n, _Hashtable *__tab)
            : m_curNode(__n), m_hashTable(__tab) {}

    NFShmDyHashTableWithListIterator() {}

    reference operator*() const { return m_curNode->m_value; }

    pointer operator->() const { return &(operator*()); }

    iterator &operator++();

    iterator operator++(int);

    bool operator==(const iterator &__it) const { return m_curNode == __it.m_curNode; }

    bool operator!=(const iterator &__it) const { return m_curNode != __it.m_curNode; }
};


template<class Val, class Key, class HashFcn,
        class ExtractKey, class EqualKey>
struct NFShmDyHashTableWithListConstIterator
{
    typedef NFShmDyHashTableWithList<Val, Key, HashFcn, ExtractKey, EqualKey>
            _Hashtable;
    typedef NFShmDyHashTableWithListIterator<Val, Key, HashFcn,
            ExtractKey, EqualKey>
            iterator;
    typedef NFShmDyHashTableWithListConstIterator<Val, Key, HashFcn,
            ExtractKey, EqualKey>
            const_iterator;
    typedef NFShmDyHashTableWithListNode<Val> _Node;

    typedef std::forward_iterator_tag iterator_category;
    typedef Val value_type;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef const Val &reference;
    typedef const Val *pointer;

    const _Node *m_curNode;
    const _Hashtable *m_hashTable;

    NFShmDyHashTableWithListConstIterator(const _Node *__n, const _Hashtable *__tab)
            : m_curNode(__n), m_hashTable(__tab) {}

    NFShmDyHashTableWithListConstIterator() {}

    NFShmDyHashTableWithListConstIterator(const iterator &__it)
            : m_curNode(__it.m_curNode), m_hashTable(__it.m_hashTable) {}

    reference operator*() const { return m_curNode->m_value; }

    pointer operator->() const { return &(operator*()); }

    const_iterator &operator++();

    const_iterator operator++(int);

    bool operator==(const const_iterator &__it) const { return m_curNode == __it.m_curNode; }

    bool operator!=(const const_iterator &__it) const { return m_curNode != __it.m_curNode; }
};

template<class Val, class Key, class HashFcn,
        class ExtractKey, class EqualKey>
class NFShmDyHashTableWithList
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
    typedef NFShmDyHashTableWithListNode<Val> _Node;

    /**
     * @brief This function gets a node from the free list of the NFShmHashTable, assigns the index to the current free index,
     * increases the number of elements, and returns the node.
     * @return
     */
    _Node *_M_get_node()
    {
        //已经没有可用的节点了
        if (*m_pFirstFreeIdx < 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "The NFShmHashTable No Enough Space! New Node Failed!");
            return NULL;
        }

        int iNowAssignIdx = *m_pFirstFreeIdx;
        *m_pFirstFreeIdx = m_buckets[*m_pFirstFreeIdx].m_next;
        ++(*m_pNumElements);
        return &m_buckets[iNowAssignIdx];
    }

    void _M_put_node(_Node *__p)
    {
        __p->m_next = *m_pFirstFreeIdx;
        *m_pFirstFreeIdx = __p->m_self;
        --(*m_pNumElements);
    }

private:
    hasher m_hash;
    key_equal m_equals;
    ExtractKey m_get_key;
    char* m_pBuffer;
    int* m_pFirstFreeIdx; //!<空闲链表头节点
    size_type* m_pNumElements;
    size_t* m_pMaxSize;
    bool* m_pGetList;
    NFShmDyVector<_Node> m_buckets;
    NFShmDyVector<int> m_bucketsFirstIdx;
    NFShmDyList<int> m_bucketsListIdx;

public:
    typedef NFShmDyHashTableWithListIterator<Val, Key, HashFcn, ExtractKey, EqualKey>
            iterator;
    typedef NFShmDyHashTableWithListConstIterator<Val, Key, HashFcn, ExtractKey, EqualKey>
            const_iterator;

    friend struct
            NFShmDyHashTableWithListIterator<Val, Key, HashFcn, ExtractKey, EqualKey>;
    friend struct
            NFShmDyHashTableWithListConstIterator<Val, Key, HashFcn, ExtractKey, EqualKey>;

public:
    NFShmDyHashTableWithList()
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

    ~NFShmDyHashTableWithList()
    {

    }

    int CreateInit()
    {
        m_pBuffer = NULL;
        m_pFirstFreeIdx = NULL;
        m_pNumElements = NULL;
        m_pMaxSize = NULL;
        m_pGetList = NULL;
        return 0;
    }

    int ResumeInit()
    {
        m_pBuffer = NULL;
        m_pFirstFreeIdx = NULL;
        m_pNumElements = NULL;
        m_pMaxSize = NULL;
        m_pGetList = NULL;
        return 0;
    }

    /**
* 计算所用内存的大小
*/
    size_t CountSize(int iObjectCount)
    {
        //    int *m_pFirstFreeIdx; //!<空闲链表头节点
        //    size_t *m_pNumElements;
        //    size_t* m_pMaxSize;
        //bool* m_pGetList;
        //NFShmDyVector<_Node> m_buckets;
        //NFShmDyVector<int> m_bucketsFirstIdx;
        // NFShmDyList<int> m_bucketsListIdx;
        return sizeof(int) + sizeof(size_type) + sizeof(size_t) + sizeof(bool) + m_buckets.CountSize(iObjectCount) + m_bucketsFirstIdx.CountSize(iObjectCount) + m_bucketsListIdx.CountSize(iObjectCount);
    }

    virtual int Init(const char* pBuffer, int bufSize, int iObjectCount, bool bResetShm = true)
    {
        CHECK_NULL(pBuffer);
        CHECK_EXPR(iObjectCount >= 0, -1, "iObjectCount:{}",iObjectCount);
        int iCountSize = CountSize(iObjectCount);
        NF_ASSERT_MSG(bufSize >= iCountSize, "bufSize:{} iCountSize:{}", bufSize, iCountSize);

        m_pBuffer = (char*)pBuffer;
        m_pFirstFreeIdx = (int*)pBuffer;
        m_pNumElements = (size_type*)(pBuffer+sizeof(int));
        m_pMaxSize = (size_t*)(pBuffer+sizeof(int)+sizeof(size_type));
        m_pGetList = (bool*)(pBuffer+sizeof(int)+sizeof(size_type)+sizeof(size_t));
        if (bResetShm)
        {
            memset((void*)pBuffer, 0, bufSize);
            *m_pFirstFreeIdx = 0;
            *m_pNumElements = 0;
            *m_pMaxSize = iObjectCount;
            *m_pGetList = false;
        }
        else {
            NF_ASSERT_MSG(*m_pNumElements <= iObjectCount, "size:{} max_size:{}", *m_pNumElements, iObjectCount);
            NF_ASSERT_MSG(*m_pMaxSize == iObjectCount, "max size:{} object count:{}", *m_pMaxSize, iObjectCount);
        }

        char* pBucketsBuffer = (char*)(pBuffer + sizeof(int) + sizeof(size_type) + sizeof(size_t) + sizeof(bool));
        size_t bucketsSize = m_buckets.CountSize(iObjectCount);
        char* pBucketsFirstIDxBuffer = pBucketsBuffer + bucketsSize;
        size_t bucketsFirstIdxSize = m_bucketsFirstIdx.CountSize(iObjectCount);
        char* pBucketsListIdxBuffer = pBucketsFirstIDxBuffer + bucketsFirstIdxSize;
        size_t bucketsListIdxSize = m_bucketsListIdx.CountSize(iObjectCount);
        m_buckets.Init(pBucketsBuffer, bucketsSize, iObjectCount, bResetShm);
        m_bucketsFirstIdx.Init(pBucketsFirstIDxBuffer, bucketsFirstIdxSize, iObjectCount, bResetShm);
        m_bucketsListIdx.Init(pBucketsListIdxBuffer, bucketsListIdxSize, iObjectCount, bResetShm);
        if (bResetShm)
        {
            _M_initialize_buckets();
        }

        return 0;
    }

    size_type size() const { return *m_pNumElements; }

    size_type max_size() const { return *m_pMaxSize; }

    bool empty() const { return size() == 0; }

    bool full() const { return size() == *m_pMaxSize; }

    size_t left_size() const { return size() >= *m_pMaxSize ? 0 : *m_pMaxSize - size(); }

    bool is_get_list() const { return *m_pGetList; }
    void set_get_list(bool flag) { *m_pGetList = flag; }

    const NFShmDyList<int>& get_list() const { return m_bucketsListIdx; }

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

    iterator get_iterator(int idx)
    {
        return iterator(get_node(idx), this);
    }

    int auto_erase(int num)
    {
        int count = 0;
        for(int i = 0; i < num; i++)
        {
            if (m_bucketsListIdx.size() > 0)
            {
                auto iter = m_bucketsListIdx.begin();
                erase(get_iterator(*iter));
                count++;
            }
        }

        return count;
    }

    const iterator get_iterator(int idx) const
    {
        return const_iterator(get_node(idx), this);
    }

    void swap(NFShmDyHashTableWithList &__ht)
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
public:

    size_type bucket_count() const { return m_buckets.size(); }

    size_type max_bucket_count() const { return *m_pMaxSize; }

    size_type elems_in_bucket(size_type __bucket) const
    {
        size_type __result = 0;
        for (int __curIndex = __bucket; __curIndex != -1; __curIndex = m_buckets[__curIndex].m_next)
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
        resize(*m_pNumElements + __n);
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

        if (*m_pGetList && __first)
        {
            NF_ASSERT(*m_bucketsListIdx.GetIterator(__first->m_list_pos) == (int)__first->m_self);
            m_bucketsListIdx.splice(m_bucketsListIdx.end(), m_bucketsListIdx.GetIterator(__first->m_list_pos));
        }
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

        if (*m_pGetList && __first)
        {
            NF_ASSERT(*m_bucketsListIdx.GetIterator(__first->m_list_pos) == (int)__first->m_self);
            m_bucketsListIdx.splice(m_bucketsListIdx.end(), m_bucketsListIdx.GetIterator(__first->m_list_pos));
        }
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

    iterator erase(const iterator &__it);

    void erase(iterator __first, iterator __last);

    const_iterator erase(const const_iterator &__it);

    void erase(const_iterator __first, const_iterator __last);

    void resize(size_type __num_elements_hint);

    void clear();

    void debug_string()
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "----------------NFShmHashTable begin size:{} MAX_SIZE:{}----------------", size(),
                  *m_pMaxSize);

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
                    node_str += NF_FORMAT(" (node:{} bucket idx:{} valid:{} next:{}) ", nodes, curNode->m_self, curNode->m_valid,
                                          curNode->m_next);
                }
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "frist idx:{} value:{} = nodes:{})", i, m_bucketsFirstIdx[i], node_str);
            }
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "first idx end");

        std::string str;
        //for (auto iter = begin(); iter != end(); iter++)
        //{
        //    str += NF_FORMAT(" (first idx:{} buckets idx:{} num:{} next:{}) ", _M_bkt_num(*iter), iter.m_curNode->m_self, count(m_get_key(*iter)),
        //                     iter.m_curNode->m_next);
        //}

        std::string freeStr;
        for (auto freeNode = get_node(*m_pFirstFreeIdx); freeNode != NULL; freeNode = get_node(freeNode->m_next))
        {
            freeStr += NF_FORMAT(" (buckets idx:{} next:{}) ", freeNode->m_self, freeNode->m_next);
        }

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "iters:{}", str);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "first free idx:{} free list:{}", *m_pFirstFreeIdx, freeStr);

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
        m_buckets.insert(m_buckets.end(), *m_pMaxSize, _Node());
        m_bucketsFirstIdx.insert(m_bucketsFirstIdx.end(), *m_pMaxSize, -1);
        *m_pNumElements = 0;
        *m_pFirstFreeIdx = 0;
        for (int i = 0; i < (int) m_buckets.size(); ++i)
        {
            m_buckets[i].m_next = i + 1;
            m_buckets[i].m_valid = false;
            m_buckets[i].m_self = i;
        }

        m_buckets[*m_pMaxSize - 1].m_next = -1;

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
            NF_ASSERT(!m_bucketsListIdx.full());
            auto iter = m_bucketsListIdx.insert(m_bucketsListIdx.end(), pNode->m_self);
            NF_ASSERT(iter != m_bucketsListIdx.end());
            NF_ASSERT(*iter == (int)pNode->m_self);
            pNode->m_list_pos = iter.m_node->m_self;
            NF_ASSERT(*m_bucketsListIdx.GetIterator(pNode->m_list_pos) == (int)pNode->m_self);

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
        NF_ASSERT(__n->m_valid);
        NF_ASSERT(__n->m_list_pos != -1);
        NF_ASSERT(*m_bucketsListIdx.GetIterator(__n->m_list_pos) == (int)__n->m_self);
        __n->m_valid = false;
        m_bucketsListIdx.erase(m_bucketsListIdx.GetIterator(__n->m_list_pos));
        __n->m_list_pos = -1;

        std::_Destroy(&__n->m_value);

        _M_put_node(__n);
    }

    void _M_erase_bucket(const size_type __n, _Node *__first, _Node *__last);

    void _M_erase_bucket(const size_type __n, _Node *__last);

    void _M_copy_from(const NFShmDyHashTableWithList &__ht);

};

template<class _Val, class _Key, class _HF, class _ExK, class _EqK>
NFShmDyHashTableWithListIterator<_Val, _Key, _HF, _ExK, _EqK> &
NFShmDyHashTableWithListIterator<_Val, _Key, _HF, _ExK, _EqK>::operator++()
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

template<class _Val, class _Key, class _HF, class _ExK, class _EqK>
inline NFShmDyHashTableWithListIterator<_Val, _Key, _HF, _ExK, _EqK>
NFShmDyHashTableWithListIterator<_Val, _Key, _HF, _ExK, _EqK>::operator++(int)
{
    iterator __tmp = *this;
    ++*this;
    return __tmp;
}

template<class _Val, class _Key, class _HF, class _ExK, class _EqK>
NFShmDyHashTableWithListConstIterator<_Val, _Key, _HF, _ExK, _EqK> &
NFShmDyHashTableWithListConstIterator<_Val, _Key, _HF, _ExK, _EqK>::operator++()
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

template<class _Val, class _Key, class _HF, class _ExK, class _EqK>
inline NFShmDyHashTableWithListConstIterator<_Val, _Key, _HF, _ExK, _EqK>
NFShmDyHashTableWithListConstIterator<_Val, _Key, _HF, _ExK, _EqK>::operator++(int)
{
    const_iterator __tmp = *this;
    ++*this;
    return __tmp;
}

template<class _Val, class _Key, class _HF, class _ExK, class _EqK>
inline std::forward_iterator_tag
iterator_category(const NFShmDyHashTableWithListIterator<_Val, _Key, _HF, _ExK, _EqK> &)
{
    return std::forward_iterator_tag();
}

template<class _Val, class _Key, class _HF, class _ExK, class _EqK>
inline _Val *
value_type(const NFShmDyHashTableWithListIterator<_Val, _Key, _HF, _ExK, _EqK> &)
{
    return (_Val *) 0;
}

template<class _Val, class _Key, class _HF, class _ExK, class _EqK>
inline typename NFShmDyHashTableWithList<_Val, _Key, _HF, _ExK, _EqK>::difference_type *
distance_type(const NFShmDyHashTableWithListIterator<_Val, _Key, _HF, _ExK, _EqK> &)
{
    return (typename NFShmDyHashTableWithList<_Val, _Key, _HF, _ExK, _EqK>::difference_type *) 0;
}

template<class _Val, class _Key, class _HF, class _ExK, class _EqK>
inline std::forward_iterator_tag
iterator_category(const NFShmDyHashTableWithListConstIterator<_Val, _Key, _HF, _ExK, _EqK> &)
{
    return std::forward_iterator_tag();
}

template<class _Val, class _Key, class _HF, class _ExK, class _EqK>
inline _Val *
value_type(const NFShmDyHashTableWithListConstIterator<_Val, _Key, _HF, _ExK, _EqK> &)
{
    return (_Val *) 0;
}

template<class _Val, class _Key, class _HF, class _ExK, class _EqK>
inline typename NFShmDyHashTableWithList<_Val, _Key, _HF, _ExK, _EqK>::difference_type *
distance_type(const NFShmDyHashTableWithListConstIterator<_Val, _Key, _HF, _ExK, _EqK> &)
{
    return (typename NFShmDyHashTableWithList<_Val, _Key, _HF, _ExK, _EqK>::difference_type *) 0;
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
template<class _Val, class _Key, class _HF, class _Ex, class _Eq>
std::pair<typename NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::iterator, bool>
NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>
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
template<class _Val, class _Key, class _HF, class _Ex, class _Eq>
typename NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::iterator
NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>
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
template<class _Val, class _Key, class _HF, class _Ex, class _Eq>
typename NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::reference
NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::find_or_insert(const value_type &__obj)
{
    const size_type __n = _M_bkt_num(__obj);
    NF_ASSERT(__n < m_bucketsFirstIdx.size());

    int iFirstIndex = m_bucketsFirstIdx[__n];
    for (_Node *__cur = get_node(iFirstIndex); __cur; __cur = get_node(__cur->m_next))
    {
        if (m_equals(m_get_key(__cur->m_value), m_get_key(__obj)))
        {
            if (*m_pGetList && __cur)
            {
                NF_ASSERT(*m_bucketsListIdx.GetIterator(__cur->m_list_pos) == (int)__cur->m_self);
                m_bucketsListIdx.splice(m_bucketsListIdx.end(), m_bucketsListIdx.GetIterator(__cur->m_list_pos));
            }
            return __cur->m_value;
        }
    }

    _Node *__tmp = _M_new_node(__obj);
    NF_ASSERT(__tmp != NULL);

    __tmp->m_next = m_bucketsFirstIdx[__n];
    m_bucketsFirstIdx[__n] = __tmp->m_self;
    return __tmp->m_value;
}

template<class _Val, class _Key, class _HF, class _Ex, class _Eq>
std::pair<typename NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::iterator,
        typename NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::iterator>
NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::equal_range(const key_type &__key)
{
    typedef std::pair<iterator, iterator> _Pii;
    const size_type __n = _M_bkt_num_key(__key);
    NF_ASSERT(__n < m_bucketsFirstIdx.size());

    int iFirstIndex = m_bucketsFirstIdx[__n];
    for (_Node *__first = get_node(iFirstIndex); __first; __first = get_node(__first->m_next))
    {
        if (m_equals(m_get_key(__first->m_value), __key))
        {
            if (*m_pGetList && __first)
            {
                NF_ASSERT(*m_bucketsListIdx.GetIterator(__first->m_list_pos) == __first->m_self);
                m_bucketsListIdx.splice(m_bucketsListIdx.end(), m_bucketsListIdx.GetIterator(__first->m_list_pos));
            }

            for (_Node *__cur = get_node(__first->m_next); __cur; __cur = get_node(__cur->m_next))
            {
                if (!m_equals(m_get_key(__cur->m_value), __key))
                {
                    return _Pii(iterator(__first, this), iterator(__cur, this));
                }

                if (*m_pGetList && __cur)
                {
                    NF_ASSERT(*m_bucketsListIdx.GetIterator(__cur->m_list_pos) == __cur->m_self);
                    m_bucketsListIdx.splice(m_bucketsListIdx.end(), m_bucketsListIdx.GetIterator(__cur->m_list_pos));
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

template<class _Val, class _Key, class _HF, class _Ex, class _Eq>
std::pair<typename NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::const_iterator,
        typename NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::const_iterator>
NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>
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
            if (*m_pGetList && __first)
            {
                NF_ASSERT(*m_bucketsListIdx.GetIterator(__first->m_list_pos) == __first->m_self);
                m_bucketsListIdx.splice(m_bucketsListIdx.end(), m_bucketsListIdx.GetIterator(__first->m_list_pos));
            }

            for (_Node *__cur = get_node(__first->m_next); __cur; __cur = get_node(__cur->m_next))
            {
                if (!m_equals(m_get_key(__cur->m_value), __key))
                {
                    return _Pii(const_iterator(__first, this), const_iterator(__cur, this));
                }

                if (*m_pGetList && __cur)
                {
                    NF_ASSERT(*m_bucketsListIdx.GetIterator(__cur->m_list_pos) == __cur->m_self);
                    m_bucketsListIdx.splice(m_bucketsListIdx.end(), m_bucketsListIdx.GetIterator(__cur->m_list_pos));
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

template<class _Val, class _Key, class _HF, class _Ex, class _Eq>
typename NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::size_type
NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::erase(const key_type &__key)
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

template<class _Val, class _Key, class _HF, class _Ex, class _Eq>
typename NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::iterator NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::erase(const iterator &__it)
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
            _Node *__next = get_node(__cur->m_next);
            m_bucketsFirstIdx[__n] = __cur->m_next;
            _M_delete_node(__cur);
            return iterator(__next, this);
        }
        else
        {
            _Node *__next = get_node(__cur->m_next);
            while (__next)
            {
                if (__next == __p)
                {
                    __cur->m_next = __next->m_next;
                    __cur = __next;
                    __next = get_node(__cur->m_next);
                    _M_delete_node(__cur);
                    break;
                }
                else
                {
                    __cur = __next;
                    __next = get_node(__cur->m_next);
                }
            }
            return iterator(__next, this);
        }
    }
    return iterator(nullptr, this);
}

template<class _Val, class _Key, class _HF, class _Ex, class _Eq>
void NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>
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

template<class _Val, class _Key, class _HF, class _Ex, class _Eq>
inline void
NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::erase(const_iterator __first,
                                                                   const_iterator __last)
{
    erase(iterator(const_cast<_Node *>(__first.m_curNode),
                   const_cast<NFShmDyHashTableWithList *>(__first.m_hashTable)),
          iterator(const_cast<_Node *>(__last.m_curNode),
                   const_cast<NFShmDyHashTableWithList *>(__last.m_hashTable)));
}

template<class _Val, class _Key, class _HF, class _Ex, class _Eq>
inline typename NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::const_iterator
NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::erase(const const_iterator &__it)
{
    return erase(iterator(const_cast<_Node *>(__it.m_curNode),
                   const_cast<NFShmDyHashTableWithList *>(__it.m_hashTable)));
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
template<class _Val, class _Key, class _HF, class _Ex, class _Eq>
void NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>
::resize(size_type __num_elements_hint)
{

}

template<class _Val, class _Key, class _HF, class _Ex, class _Eq>
void NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>
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

template<class _Val, class _Key, class _HF, class _Ex, class _Eq>
void NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>
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

template<class _Val, class _Key, class _HF, class _Ex, class _Eq>
void NFShmDyHashTableWithList<_Val, _Key, _HF, _Ex, _Eq>::clear()
{
    m_buckets.clear();
    m_bucketsFirstIdx.clear();
    _M_initialize_buckets();
}



