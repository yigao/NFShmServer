// -------------------------------------------------------------------------
//    @FileName         :    NFShmDyHashSet.h
//    @Author           :    gaoyi
//    @Date             :    23-2-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmDyHashSet
//
// -------------------------------------------------------------------------

#pragma once

#include "NFShmDyHashTable.h"

template<class Value, class HashFcn, class EqualKey>
class NFShmDyHashSet
{
private:
    typedef NFShmDyHashTable<Value, Value, HashFcn, std::_Identity<Value>, EqualKey> _Ht;
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

    hasher hash_funct() const { return m_hashTable.hash_funct(); }

    key_equal key_eq() const { return m_hashTable.key_eq(); }

public:
    NFShmDyHashSet()
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

    size_t CountSize(int iObjectCount)
    {
        return m_hashTable.CountSize(iObjectCount);
    }

    virtual int Init(const char* pBuffer, int bufSize, int iObjectCount, bool bResetShm = true)
    {
        return m_hashTable.Init(pBuffer, bufSize, iObjectCount, bResetShm);
    }

public:
    size_type size() const { return m_hashTable.size(); }

    size_type max_size() const { return m_hashTable.max_size(); }

    bool empty() const { return m_hashTable.empty(); }

    void swap(NFShmDyHashSet &__hs) { m_hashTable.swap(__hs.m_hashTable); }

    iterator begin() const { return m_hashTable.begin(); }

    iterator end() const { return m_hashTable.end(); }

    bool full() const { return m_hashTable.full(); }

    size_t left_size() const { return m_hashTable.left_size(); }

    void debug_string() { m_hashTable.debug_string(); }
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

    iterator erase(iterator __it) { return m_hashTable.erase(__it); }

    void erase(iterator __f, iterator __l) { m_hashTable.erase(__f, __l); }

    void clear() { m_hashTable.clear(); }

public:
    void resize(size_type __hint) { m_hashTable.resize(__hint); }

    size_type bucket_count() const { return m_hashTable.bucket_count(); }

    size_type max_bucket_count() const { return m_hashTable.max_bucket_count(); }

    size_type elems_in_bucket(size_type __n) const { return m_hashTable.elems_in_bucket(__n); }
};

template<class Value, class HashFcn, class EqualKey>
class NFShmDyHashMultiSet
{
private:
    typedef NFShmDyHashTable<Value, Value, HashFcn, std::_Identity<Value>, EqualKey> _Ht;
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
    NFShmDyHashMultiSet()
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

    size_t CountSize(int iObjectCount)
    {
        return m_hashTable.CountSize(iObjectCount);
    }

    virtual int Init(const char* pBuffer, int bufSize, int iObjectCount, bool bResetShm = true)
    {
        return m_hashTable.Init(pBuffer, bufSize, iObjectCount, bResetShm);
    }
public:
    size_type size() const { return m_hashTable.size(); }

    size_type max_size() const { return m_hashTable.max_size(); }

    bool empty() const { return m_hashTable.empty(); }

    void swap(NFShmDyHashMultiSet &hs) { m_hashTable.swap(hs.m_hashTable); }

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