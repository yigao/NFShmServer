// -------------------------------------------------------------------------
//    @FileName         :    NFShmHashSet.h
//    @Author           :    gaoyi
//    @Date             :    23-2-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmHashSet
//
// -------------------------------------------------------------------------

#pragma once

#include "NFShmHashTable.h"

template<class Value, int MAX_SIZE,
        class HashFcn = std::hash<Value>,
        class EqualKey = std::equal_to<Value>>
class NFShmHashSet;

template<class _Value, int MAX_SIZE, class _HashFcn, class _EqualKey>
inline bool
operator==(const NFShmHashSet<_Value, MAX_SIZE, _HashFcn, _EqualKey> &__hs1,
           const NFShmHashSet<_Value, MAX_SIZE, _HashFcn, _EqualKey> &__hs2);

template<class Value, int MAX_SIZE, class HashFcn, class EqualKey>
class NFShmHashSet
{
private:
    typedef NFShmHashTable<Value, Value, MAX_SIZE, HashFcn, std::_Identity<Value>, EqualKey> _Ht;
    _Ht m_hashTable;

public:
    typedef typename _Ht::key_type key_type;
    typedef typename _Ht::value_type value_type;
    typedef typename _Ht::hasher hasher;
    typedef typename _Ht::key_equal key_equal;

    typedef typename _Ht::size_type size_type;
    typedef typename _Ht::difference_type difference_type;
    typedef typename _Ht::const_pointer pointer;
    typedef typename _Ht::const_pointer const_pointer;
    typedef typename _Ht::const_reference reference;
    typedef typename _Ht::const_reference const_reference;

    typedef typename _Ht::const_iterator iterator;
    typedef typename _Ht::const_iterator const_iterator;

    typedef typename _Ht::allocator_type allocator_type;

    hasher hash_funct() const { return m_hashTable.hash_funct(); }

    key_equal key_eq() const { return m_hashTable.key_eq(); }

public:
    NFShmHashSet()
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
    NFShmHashSet(_InputIterator __f, _InputIterator __l) { m_hashTable.insert_unique(__f, __l); }

    NFShmHashSet(const value_type *__f, const value_type *__l) { m_hashTable.insert_unique(__f, __l); }

    NFShmHashSet(const_iterator __f, const_iterator __l) { m_hashTable.insert_unique(__f, __l); }

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

    void swap(NFShmHashSet &__hs) { m_hashTable.swap(__hs.m_hashTable); }

    template<class _Val, int X_MAX_SIZE, class _HF, class _EqK>
    friend bool operator==(const NFShmHashSet<_Val, X_MAX_SIZE, _HF, _EqK> &,
                           const NFShmHashSet<_Val, X_MAX_SIZE, _HF, _EqK> &);

    iterator begin() const { return m_hashTable.begin(); }

    iterator end() const { return m_hashTable.end(); }

public:
    pair<iterator, bool> insert(const value_type &__obj)
    {
        pair<typename _Ht::iterator, bool> __p = m_hashTable.insert_unique(__obj);
        return pair<iterator, bool>(__p.first, __p.second);
    }

    template<class _InputIterator>
    void insert(_InputIterator __f, _InputIterator __l) { m_hashTable.insert_unique(__f, __l); }

    void insert(const value_type *__f, const value_type *__l)
    {
        m_hashTable.insert_unique(__f, __l);
    }

    void insert(const_iterator __f, const_iterator __l) { m_hashTable.insert_unique(__f, __l); }

    pair<iterator, bool> insert_noresize(const value_type &__obj)
    {
        pair<typename _Ht::iterator, bool> __p =
                m_hashTable.insert_unique_noresize(__obj);
        return pair<iterator, bool>(__p.first, __p.second);
    }

    iterator find(const key_type &__key) const { return m_hashTable.find(__key); }

    size_type count(const key_type &__key) const { return m_hashTable.count(__key); }

    pair<iterator, iterator> equal_range(const key_type &__key) const { return m_hashTable.equal_range(__key); }

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

template<class _Value, int MAX_SIZE, class _HashFcn, class _EqualKey>
inline bool
operator==(const NFShmHashSet<_Value, MAX_SIZE, _HashFcn, _EqualKey> &__hs1,
           const NFShmHashSet<_Value, MAX_SIZE, _HashFcn, _EqualKey> &__hs2)
{
    return __hs1.m_hashTable == __hs2.m_hashTable;
}

template<class Value, int MAX_SIZE,
        class HashFcn = std::hash<Value>,
        class EqualKey = std::equal_to<Value>>
class NFShmHashMultiSet;

template<class _Val, int MAX_SIZE, class _HashFcn, class _EqualKey>
inline bool
operator==(const NFShmHashMultiSet<_Val, MAX_SIZE, _HashFcn, _EqualKey> &__hs1,
           const NFShmHashMultiSet<_Val, MAX_SIZE, _HashFcn, _EqualKey> &__hs2);


template<class Value, int MAX_SIZE, class HashFcn, class EqualKey>
class NFShmHashMultiSet
{
private:
    typedef NFShmHashTable<Value, Value, MAX_SIZE, HashFcn, std::_Identity<Value>, EqualKey> _Ht;
    _Ht m_hashTable;

public:
    typedef typename _Ht::key_type key_type;
    typedef typename _Ht::value_type value_type;
    typedef typename _Ht::hasher hasher;
    typedef typename _Ht::key_equal key_equal;

    typedef typename _Ht::size_type size_type;
    typedef typename _Ht::difference_type difference_type;
    typedef typename _Ht::const_pointer pointer;
    typedef typename _Ht::const_pointer const_pointer;
    typedef typename _Ht::const_reference reference;
    typedef typename _Ht::const_reference const_reference;

    typedef typename _Ht::const_iterator iterator;
    typedef typename _Ht::const_iterator const_iterator;

    typedef typename _Ht::allocator_type allocator_type;

    hasher hash_funct() const { return m_hashTable.hash_funct(); }

    key_equal key_eq() const { return m_hashTable.key_eq(); }

public:
    NFShmHashMultiSet()
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
    NFShmHashMultiSet(_InputIterator __f, _InputIterator __l) { m_hashTable.insert_equal(__f, __l); }

    NFShmHashMultiSet(const value_type *__f, const value_type *__l) { m_hashTable.insert_equal(__f, __l); }

    NFShmHashMultiSet(const_iterator __f, const_iterator __l) { m_hashTable.insert_equal(__f, __l); }

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

    void swap(NFShmHashMultiSet &hs) { m_hashTable.swap(hs.m_hashTable); }

    template<class _Val, int _MAX_SIZE, class _HF, class _EqK>
    friend bool operator==(const NFShmHashMultiSet<_Val, _MAX_SIZE, _HF, _EqK> &,
                           const NFShmHashMultiSet<_Val, _MAX_SIZE, _HF, _EqK> &);

    iterator begin() const { return m_hashTable.begin(); }

    iterator end() const { return m_hashTable.end(); }

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

    iterator find(const key_type &__key) const { return m_hashTable.find(__key); }

    size_type count(const key_type &__key) const { return m_hashTable.count(__key); }

    pair<iterator, iterator> equal_range(const key_type &__key) const { return m_hashTable.equal_range(__key); }

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

template<class _Val, int MAX_SIZE, class _HashFcn, class _EqualKey, class _Alloc>
inline bool
operator==(const NFShmHashMultiSet<_Val, MAX_SIZE, _HashFcn, _EqualKey> &__hs1,
           const NFShmHashMultiSet<_Val, MAX_SIZE, _HashFcn, _EqualKey> &__hs2)
{
    return __hs1.m_hashTable == __hs2.m_hashTable;
}