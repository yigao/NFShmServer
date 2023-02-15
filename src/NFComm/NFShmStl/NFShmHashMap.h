// -------------------------------------------------------------------------
//    @FileName         :    NFShmHashMap.h
//    @Author           :    gaoyi
//    @Date             :    23-2-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmHashMap
//
// -------------------------------------------------------------------------

#pragma once

#include "NFShmHashTable.h"
#include "NFShmPair.h"

template<class Key, class Tp, int MAX_SIZE,
        class HashFcn = std::hash<Key>,
        class EqualKey = std::equal_to<Key>>
class NFShmHashMap;

template<class _Key, class _Tp, int MAX_SIZE, class _HashFn, class _EqKey>
inline bool operator==(const NFShmHashMap<_Key, _Tp, MAX_SIZE, _HashFn, _EqKey> &,
                       const NFShmHashMap<_Key, _Tp, MAX_SIZE, _HashFn, _EqKey> &);

template<class Key, class Tp, int MAX_SIZE, class HashFcn, class EqualKey>
class NFShmHashMap
{
private:
    typedef NFShmHashTable<std::pair<Key, Tp>, Key, MAX_SIZE, HashFcn,
            std::_Select1st<std::pair<Key, Tp> >, EqualKey> _Ht;
    _Ht m_hashTable;

public:
    typedef typename _Ht::key_type key_type;
    typedef Tp data_type;
    typedef Tp mapped_type;
    typedef typename _Ht::value_type value_type;
    typedef typename _Ht::hasher hasher;
    typedef typename _Ht::key_equal key_equal;

    typedef typename _Ht::size_type size_type;
    typedef typename _Ht::difference_type difference_type;
    typedef typename _Ht::pointer pointer;
    typedef typename _Ht::const_pointer const_pointer;
    typedef typename _Ht::reference reference;
    typedef typename _Ht::const_reference const_reference;

    typedef typename _Ht::iterator iterator;
    typedef typename _Ht::const_iterator const_iterator;

    hasher hash_funct() const { return m_hashTable.hash_funct(); }

    key_equal key_eq() const { return m_hashTable.key_eq(); }

public:
    NFShmHashMap()
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

    template<class _InputIterator>
    NFShmHashMap(_InputIterator __f, _InputIterator __l) { m_hashTable.insert_unique(__f, __l); }

    NFShmHashMap(const value_type *__f, const value_type *__l) { m_hashTable.insert_unique(__f, __l); }

    NFShmHashMap(const_iterator __f, const_iterator __l) { m_hashTable.insert_unique(__f, __l); }

    NFShmHashMap(iterator __f, iterator __l) { m_hashTable.insert_unique(__f, __l); }

    int CreateInit()
    {
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

public:
    size_type size() const { return m_hashTable.size(); }

    size_type max_size() const { return m_hashTable.max_size(); }

    bool empty() const { return m_hashTable.empty(); }

    void swap(NFShmHashMap &__hs) { m_hashTable.swap(__hs.m_hashTable); }

    template<class _K1, class _T1, int _MAX_SIZE, class _HF, class _EqK>
    friend bool operator==(const NFShmHashMap<_K1, _T1, _MAX_SIZE, _HF, _EqK> &,
                           const NFShmHashMap<_K1, _T1, _MAX_SIZE, _HF, _EqK> &);

    iterator begin() { return m_hashTable.begin(); }

    iterator end() { return m_hashTable.end(); }

    const_iterator begin() const { return m_hashTable.begin(); }

    const_iterator end() const { return m_hashTable.end(); }

public:
    std::pair<iterator, bool> insert(const value_type &__obj) { return m_hashTable.insert_unique(__obj); }
    std::pair<iterator, bool> emplace(const key_type&__key, const data_type& __data) { return m_hashTable.insert_unique(std::make_pair(__key, __data)); }
    iterator emplace_hint(const key_type&__key, const data_type& __data) { auto pair = m_hashTable.insert_unique(std::make_pair(__key, __data)); return pair.first; }

    template<class _InputIterator>
    void insert(_InputIterator __f, _InputIterator __l) { m_hashTable.insert_unique(__f, __l); }

    void insert(const value_type *__f, const value_type *__l)
    {
        m_hashTable.insert_unique(__f, __l);
    }

    void insert(const_iterator __f, const_iterator __l) { m_hashTable.insert_unique(__f, __l); }

    std::pair<iterator, bool> insert_noresize(const value_type &__obj) { return m_hashTable.insert_unique_noresize(__obj); }

    iterator find(const key_type &__key) { return m_hashTable.find(__key); }

    const_iterator find(const key_type &__key) const { return m_hashTable.find(__key); }

    Tp &operator[](const key_type &__key)
    {
        return m_hashTable.find_or_insert(value_type(__key, Tp())).second;
    }

    size_type count(const key_type &__key) const { return m_hashTable.count(__key); }

    std::pair<iterator, iterator> equal_range(const key_type &__key) { return m_hashTable.equal_range(__key); }

    std::pair<const_iterator, const_iterator>
    equal_range(const key_type &__key) const { return m_hashTable.equal_range(__key); }

    size_type erase(const key_type &__key) { return m_hashTable.erase(__key); }

    void erase(iterator __it) { m_hashTable.erase(__it); }

    void erase(iterator __f, iterator __l) { m_hashTable.erase(__f, __l); }

    void clear() { m_hashTable.clear(); }

    void resize(size_type __hint) { m_hashTable.resize(__hint); }

    size_type bucket_count() const { return m_hashTable.bucket_count(); }

    size_type max_bucket_count() const { return m_hashTable.max_bucket_count(); }

    size_type elems_in_bucket(size_type __n) const { return m_hashTable.elems_in_bucket(__n); }
};

template<class _Key, class _Tp, int MAX_SIZE, class _HashFcn, class _EqlKey>
inline bool
operator==(const NFShmHashMap<_Key, _Tp, MAX_SIZE, _HashFcn, _EqlKey> &__hm1,
           const NFShmHashMap<_Key, _Tp, MAX_SIZE, _HashFcn, _EqlKey> &__hm2)
{
    return __hm1.m_hashTable == __hm2.m_hashTable;
}

template<class Key, class Tp, int MAX_SIZE,
        class HashFcn = std::hash<Key>,
        class EqualKey = std::equal_to<Key>>
class NFShmHashMultiMap;

template<class _Key, class _Tp, int MAX_SIZE, class _HF, class _EqKey>
inline bool
operator==(const NFShmHashMultiMap<_Key, _Tp, MAX_SIZE, _HF, _EqKey> &__hm1,
           const NFShmHashMultiMap<_Key, _Tp, MAX_SIZE, _HF, _EqKey> &__hm2);

template<class Key, class Tp, int MAX_SIZE, class HashFcn, class EqualKey>
class NFShmHashMultiMap
{
private:
    typedef NFShmHashTable<NFShmPair<const Key, Tp>, Key, MAX_SIZE, HashFcn,
            std::_Select1st<NFShmPair<const Key, Tp> >, EqualKey> _Ht;
    _Ht m_hashTable;

public:
    typedef typename _Ht::key_type key_type;
    typedef Tp data_type;
    typedef Tp mapped_type;
    typedef typename _Ht::value_type value_type;
    typedef typename _Ht::hasher hasher;
    typedef typename _Ht::key_equal key_equal;

    typedef typename _Ht::size_type size_type;
    typedef typename _Ht::difference_type difference_type;
    typedef typename _Ht::pointer pointer;
    typedef typename _Ht::const_pointer const_pointer;
    typedef typename _Ht::reference reference;
    typedef typename _Ht::const_reference const_reference;

    typedef typename _Ht::iterator iterator;
    typedef typename _Ht::const_iterator const_iterator;

    typedef typename _Ht::allocator_type allocator_type;

    hasher hash_funct() const { return m_hashTable.hash_funct(); }

    key_equal key_eq() const { return m_hashTable.key_eq(); }

    allocator_type get_allocator() const { return m_hashTable.get_allocator(); }

public:
    NFShmHashMultiMap()
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

    template<class _InputIterator>
    NFShmHashMultiMap(_InputIterator __f, _InputIterator __l) { m_hashTable.insert_equal(__f, __l); }

    NFShmHashMultiMap(const value_type *__f, const value_type *__l) { m_hashTable.insert_equal(__f, __l); }

    NFShmHashMultiMap(const_iterator __f, const_iterator __l) { m_hashTable.insert_equal(__f, __l); }

    int CreateInit()
    {
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

public:
    size_type size() const { return m_hashTable.size(); }

    size_type max_size() const { return m_hashTable.max_size(); }

    bool empty() const { return m_hashTable.empty(); }

    void swap(NFShmHashMultiMap &__hs) { m_hashTable.swap(__hs.m_hashTable); }

    template<class _K1, class _T1, int _MAX_SIZE, class _HF, class _EqK>
    friend bool operator==(const NFShmHashMultiMap<_K1, _T1, _MAX_SIZE, _HF, _EqK> &,
                           const NFShmHashMultiMap<_K1, _T1, _MAX_SIZE, _HF, _EqK> &);

    iterator begin() { return m_hashTable.begin(); }

    iterator end() { return m_hashTable.end(); }

    const_iterator begin() const { return m_hashTable.begin(); }

    const_iterator end() const { return m_hashTable.end(); }

public:
    iterator insert(const value_type &__obj) { return m_hashTable.insert_equal(__obj); }

    template<class _InputIterator>
    void insert(_InputIterator __f, _InputIterator __l) { m_hashTable.insert_equal(__f, __l); }

    void insert(const value_type *__f, const value_type *__l)
    {
        m_hashTable.insert_equal(__f, __l);
    }

    void insert(const_iterator __f, const_iterator __l) { m_hashTable.insert_equal(__f, __l); }

    iterator insert_noresize(const value_type &__obj) { return m_hashTable.insert_equal_noresize(__obj); }

    iterator find(const key_type &__key) { return m_hashTable.find(__key); }

    const_iterator find(const key_type &__key) const { return m_hashTable.find(__key); }

    size_type count(const key_type &__key) const { return m_hashTable.count(__key); }

    std::pair<iterator, iterator> equal_range(const key_type &__key) { return m_hashTable.equal_range(__key); }

    std::pair<const_iterator, const_iterator>
    equal_range(const key_type &__key) const { return m_hashTable.equal_range(__key); }

    size_type erase(const key_type &__key) { return m_hashTable.erase(__key); }

    void erase(iterator __it) { m_hashTable.erase(__it); }

    void erase(iterator __f, iterator __l) { m_hashTable.erase(__f, __l); }

    void clear() { m_hashTable.clear(); }

public:
    void resize(size_type __hint) { m_hashTable.resize(__hint); }

    size_type bucket_count() const { return m_hashTable.bucket_count(); }

    size_type max_bucket_count() const { return m_hashTable.max_bucket_count(); }

    size_type elems_in_bucket(size_type __n) const { return m_hashTable.elems_in_bucket(__n); }
};

template<class _Key, class _Tp, int MAX_SIZE, class _HF, class _EqKey>
inline bool
operator==(const NFShmHashMultiMap<_Key, _Tp, MAX_SIZE, _HF, _EqKey> &__hm1,
           const NFShmHashMultiMap<_Key, _Tp, MAX_SIZE, _HF, _EqKey> &__hm2)
{
    return __hm1.m_hashTable == __hm2.m_hashTable;
}
