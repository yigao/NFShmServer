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
#include <iterator>
#include <algorithm>
#include <vector>


template <class Val>
struct NFShmHashTableNode
{
    NFShmHashTableNode* _M_next;
    Val _M_val;
};

template <class Val, class Key, class HashFcn,
        class ExtractKey, class EqualKey>
class NFShmHashTable;

template <class Val, class Key, class HashFcn,
        class ExtractKey, class EqualKey>
struct _Hashtable_iterator;

template <class Val, class Key, class HashFcn,
        class ExtractKey, class EqualKey>
struct _Hashtable_const_iterator;

template <class Val, class Key, class HashFcn,
        class ExtractKey, class EqualKey>
struct _Hashtable_iterator {
    typedef NFShmHashTable<Val,Key,HashFcn,ExtractKey,EqualKey>
            _Hashtable;
    typedef _Hashtable_iterator<Val, Key, HashFcn,
            ExtractKey, EqualKey>
            iterator;
    typedef _Hashtable_const_iterator<Val, Key, HashFcn,
            ExtractKey, EqualKey>
            const_iterator;
    typedef NFShmHashTableNode<Val> _Node;

    typedef forward_iterator_tag iterator_category;
    typedef Val value_type;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef Val& reference;
    typedef Val* pointer;

    _Node* _M_cur;
    _Hashtable* _M_ht;

    _Hashtable_iterator(_Node* __n, _Hashtable* __tab)
            : _M_cur(__n), _M_ht(__tab) {}
    _Hashtable_iterator() {}
    reference operator*() const { return _M_cur->_M_val; }
    pointer operator->() const { return &(operator*()); }
    iterator& operator++();
    iterator operator++(int);
    bool operator==(const iterator& __it) const
    { return _M_cur == __it._M_cur; }
    bool operator!=(const iterator& __it) const
    { return _M_cur != __it._M_cur; }
};


template <class Val, class Key, class HashFcn,
        class ExtractKey, class EqualKey>
struct _Hashtable_const_iterator {
    typedef NFShmHashTable<Val,Key,HashFcn,ExtractKey,EqualKey>
            _Hashtable;
    typedef _Hashtable_iterator<Val,Key,HashFcn,
            ExtractKey,EqualKey>
            iterator;
    typedef _Hashtable_const_iterator<Val, Key, HashFcn,
            ExtractKey, EqualKey>
            const_iterator;
    typedef NFShmHashTableNode<Val> _Node;

    typedef forward_iterator_tag iterator_category;
    typedef Val value_type;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef const Val& reference;
    typedef const Val* pointer;

    const _Node* _M_cur;
    const _Hashtable* _M_ht;

    _Hashtable_const_iterator(const _Node* __n, const _Hashtable* __tab)
            : _M_cur(__n), _M_ht(__tab) {}
    _Hashtable_const_iterator() {}
    _Hashtable_const_iterator(const iterator& __it)
            : _M_cur(__it._M_cur), _M_ht(__it._M_ht) {}
    reference operator*() const { return _M_cur->_M_val; }
#ifndef __SGI_STL_NO_ARROW_OPERATOR
    pointer operator->() const { return &(operator*()); }
#endif /* __SGI_STL_NO_ARROW_OPERATOR */
    const_iterator& operator++();
    const_iterator operator++(int);
    bool operator==(const const_iterator& __it) const
    { return _M_cur == __it._M_cur; }
    bool operator!=(const const_iterator& __it) const
    { return _M_cur != __it._M_cur; }
};

// Note: assumes long is at least 32 bits.
enum { __stl_num_primes = 28 };

static const unsigned long __stl_prime_list[__stl_num_primes] =
        {
                53ul,         97ul,         193ul,       389ul,       769ul,
                1543ul,       3079ul,       6151ul,      12289ul,     24593ul,
                49157ul,      98317ul,      196613ul,    393241ul,    786433ul,
                1572869ul,    3145739ul,    6291469ul,   12582917ul,  25165843ul,
                50331653ul,   100663319ul,  201326611ul, 402653189ul, 805306457ul,
                1610612741ul, 3221225473ul, 4294967291ul
        };

inline unsigned long __stl_next_prime(unsigned long __n)
{
    const unsigned long* __first = __stl_prime_list;
    const unsigned long* __last = __stl_prime_list + (int)__stl_num_primes;
    const unsigned long* pos = lower_bound(__first, __last, __n);
    return pos == __last ? *(__last - 1) : *pos;
}

// Forward declaration of operator==.

template <class Val, class Key, class HF, class Ex, class Eq>
class NFShmHashTable;

template <class Val, class Key, class HF, class Ex, class Eq>
bool operator==(const NFShmHashTable<Val,Key,HF,Ex,Eq>& __ht1,
                const NFShmHashTable<Val,Key,HF,Ex,Eq>& __ht2);


// Hashtables handle allocators a bit differently than other containers
//  do.  If we're using standard-conforming allocators, then a hashtable
//  unconditionally has a member variable to hold its allocator, even if
//  it so happens that all instances of the allocator type are identical.
// This is because, for hashtables, this extra storage is negligible.
//  Additionally, a base class wouldn't serve any other purposes; it
//  wouldn't, for example, simplify the exception-handling code.

template <class Val, class Key, class HashFcn,
        class ExtractKey, class EqualKey>
class NFShmHashTable {
public:
    typedef Key key_type;
    typedef Val value_type;
    typedef HashFcn hasher;
    typedef EqualKey key_equal;

    typedef size_t            size_type;
    typedef ptrdiff_t         difference_type;
    typedef value_type*       pointer;
    typedef const value_type* const_pointer;
    typedef value_type&       reference;
    typedef const value_type& const_reference;

    hasher hash_funct() const { return _M_hash; }
    key_equal key_eq() const { return _M_equals; }

private:
    typedef NFShmHashTableNode<Val> _Node;

    _Node* _M_get_node() { return NULL; }
    void _M_put_node(_Node* __p) { }

private:
    hasher                _M_hash;
    key_equal             _M_equals;
    ExtractKey            _M_get_key;
    vector<_Node*>        _M_buckets;
    size_type             _M_num_elements;

public:
    typedef _Hashtable_iterator<Val,Key,HashFcn,ExtractKey,EqualKey>
            iterator;
    typedef _Hashtable_const_iterator<Val,Key,HashFcn,ExtractKey,EqualKey>
            const_iterator;

    friend struct
            _Hashtable_iterator<Val,Key,HashFcn,ExtractKey,EqualKey>;
    friend struct
            _Hashtable_const_iterator<Val,Key,HashFcn,ExtractKey,EqualKey>;

public:
    NFShmHashTable(size_type __n,
                   const HashFcn&    __hf,
                   const EqualKey&   __eql,
                   const ExtractKey& __ext)
            : _M_hash(__hf),
              _M_equals(__eql),
              _M_get_key(__ext),
              _M_num_elements(0)
    {
        _M_initialize_buckets(__n);
    }

    NFShmHashTable(size_type __n,
                   const HashFcn&    __hf,
                   const EqualKey&   __eql)
            :
              _M_hash(__hf),
              _M_equals(__eql),
              _M_get_key(ExtractKey()),
              _M_num_elements(0)
    {
        _M_initialize_buckets(__n);
    }

    NFShmHashTable(const NFShmHashTable& __ht)
            :
              _M_hash(__ht._M_hash),
              _M_equals(__ht._M_equals),
              _M_get_key(__ht._M_get_key),
              _M_num_elements(0)
    {
        _M_copy_from(__ht);
    }

    NFShmHashTable& operator= (const NFShmHashTable& __ht)
    {
        if (&__ht != this) {
            clear();
            _M_hash = __ht._M_hash;
            _M_equals = __ht._M_equals;
            _M_get_key = __ht._M_get_key;
            _M_copy_from(__ht);
        }
        return *this;
    }

    ~NFShmHashTable() { clear(); }

    size_type size() const { return _M_num_elements; }
    size_type max_size() const { return size_type(-1); }
    bool empty() const { return size() == 0; }

    void swap(NFShmHashTable& __ht)
    {

    }

    iterator begin()
    {
        for (size_type __n = 0; __n < _M_buckets.size(); ++__n)
            if (_M_buckets[__n])
                return iterator(_M_buckets[__n], this);
        return end();
    }

    iterator end() { return iterator(0, this); }

    const_iterator begin() const
    {
        for (size_type __n = 0; __n < _M_buckets.size(); ++__n)
            if (_M_buckets[__n])
                return const_iterator(_M_buckets[__n], this);
        return end();
    }

    const_iterator end() const { return const_iterator(0, this); }

    template <class _Vl, class _Ky, class _HF, class _Ex, class _Eq>
  friend bool operator== (const NFShmHashTable<_Vl, _Ky, _HF, _Ex, _Eq>&,
                          const NFShmHashTable<_Vl, _Ky, _HF, _Ex, _Eq>&);
public:

    size_type bucket_count() const { return _M_buckets.size(); }

    size_type max_bucket_count() const
    { return __stl_prime_list[(int)__stl_num_primes - 1]; }

    size_type elems_in_bucket(size_type __bucket) const
    {
        size_type __result = 0;
        for (_Node* __cur = _M_buckets[__bucket]; __cur; __cur = __cur->_M_next)
            __result += 1;
        return __result;
    }

    pair<iterator, bool> insert_unique(const value_type& __obj)
    {
        resize(_M_num_elements + 1);
        return insert_unique_noresize(__obj);
    }

    iterator insert_equal(const value_type& __obj)
    {
        resize(_M_num_elements + 1);
        return insert_equal_noresize(__obj);
    }

    pair<iterator, bool> insert_unique_noresize(const value_type& __obj);
    iterator insert_equal_noresize(const value_type& __obj);

    template <class _InputIterator>
  void insert_unique(_InputIterator __f, _InputIterator __l)
  {
    insert_unique(__f, __l, __ITERATOR_CATEGORY(__f));
  }

  template <class _InputIterator>
  void insert_equal(_InputIterator __f, _InputIterator __l)
  {
    insert_equal(__f, __l, __ITERATOR_CATEGORY(__f));
  }

  template <class _InputIterator>
  void insert_unique(_InputIterator __f, _InputIterator __l,
                     input_iterator_tag)
  {
    for ( ; __f != __l; ++__f)
      insert_unique(*__f);
  }

  template <class _InputIterator>
  void insert_equal(_InputIterator __f, _InputIterator __l,
                    input_iterator_tag)
  {
    for ( ; __f != __l; ++__f)
      insert_equal(*__f);
  }

  template <class _ForwardIterator>
  void insert_unique(_ForwardIterator __f, _ForwardIterator __l,
                     forward_iterator_tag)
  {
    size_type __n = 0;
    distance(__f, __l, __n);
    resize(_M_num_elements + __n);
    for ( ; __n > 0; --__n, ++__f)
      insert_unique_noresize(*__f);
  }

  template <class _ForwardIterator>
  void insert_equal(_ForwardIterator __f, _ForwardIterator __l,
                    forward_iterator_tag)
  {
    size_type __n = 0;
    distance(__f, __l, __n);
    resize(_M_num_elements + __n);
    for ( ; __n > 0; --__n, ++__f)
      insert_equal_noresize(*__f);
  }

    void insert_unique(const value_type* __f, const value_type* __l)
    {
        size_type __n = __l - __f;
        resize(_M_num_elements + __n);
        for ( ; __n > 0; --__n, ++__f)
            insert_unique_noresize(*__f);
    }

    void insert_equal(const value_type* __f, const value_type* __l)
    {
        size_type __n = __l - __f;
        resize(_M_num_elements + __n);
        for ( ; __n > 0; --__n, ++__f)
            insert_equal_noresize(*__f);
    }

    void insert_unique(const_iterator __f, const_iterator __l)
    {
        size_type __n = 0;
        distance(__f, __l, __n);
        resize(_M_num_elements + __n);
        for ( ; __n > 0; --__n, ++__f)
            insert_unique_noresize(*__f);
    }

    void insert_equal(const_iterator __f, const_iterator __l)
    {
        size_type __n = 0;
        distance(__f, __l, __n);
        resize(_M_num_elements + __n);
        for ( ; __n > 0; --__n, ++__f)
            insert_equal_noresize(*__f);
    }

    reference find_or_insert(const value_type& __obj);

    iterator find(const key_type& __key)
    {
        size_type __n = _M_bkt_num_key(__key);
        _Node* __first;
        for ( __first = _M_buckets[__n];
              __first && !_M_equals(_M_get_key(__first->_M_val), __key);
              __first = __first->_M_next)
        {}
        return iterator(__first, this);
    }

    const_iterator find(const key_type& __key) const
    {
        size_type __n = _M_bkt_num_key(__key);
        const _Node* __first;
        for ( __first = _M_buckets[__n];
              __first && !_M_equals(_M_get_key(__first->_M_val), __key);
              __first = __first->_M_next)
        {}
        return const_iterator(__first, this);
    }

    size_type count(const key_type& __key) const
    {
        const size_type __n = _M_bkt_num_key(__key);
        size_type __result = 0;

        for (const _Node* __cur = _M_buckets[__n]; __cur; __cur = __cur->_M_next)
            if (_M_equals(_M_get_key(__cur->_M_val), __key))
                ++__result;
        return __result;
    }

    std::pair<iterator, iterator>
    equal_range(const key_type& __key);

    std::pair<const_iterator, const_iterator>
    equal_range(const key_type& __key) const;

    size_type erase(const key_type& __key);
    void erase(const iterator& __it);
    void erase(iterator __first, iterator __last);

    void erase(const const_iterator& __it);
    void erase(const_iterator __first, const_iterator __last);

    void resize(size_type __num_elements_hint);
    void clear();

private:
    size_type _M_next_size(size_type __n) const
    { return __stl_next_prime(__n); }

    void _M_initialize_buckets(size_type __n)
    {
        const size_type __n_buckets = _M_next_size(__n);
        _M_buckets.reserve(__n_buckets);
        _M_buckets.insert(_M_buckets.end(), __n_buckets, (_Node*) 0);
        _M_num_elements = 0;
    }

    size_type _M_bkt_num_key(const key_type& __key) const
    {
        return _M_bkt_num_key(__key, _M_buckets.size());
    }

    size_type _M_bkt_num(const value_type& __obj) const
    {
        return _M_bkt_num_key(_M_get_key(__obj));
    }

    size_type _M_bkt_num_key(const key_type& __key, size_t __n) const
    {
        return _M_hash(__key) % __n;
    }

    size_type _M_bkt_num(const value_type& __obj, size_t __n) const
    {
        return _M_bkt_num_key(_M_get_key(__obj), __n);
    }

    _Node* _M_new_node(const value_type& __obj)
    {
        _Node* __n = _M_get_node();
        __n->_M_next = 0;
        construct(&__n->_M_val, __obj);
        return __n;
    }

    void _M_delete_node(_Node* __n)
    {
        destroy(&__n->_M_val);
        _M_put_node(__n);
    }

    void _M_erase_bucket(const size_type __n, _Node* __first, _Node* __last);
    void _M_erase_bucket(const size_type __n, _Node* __last);

    void _M_copy_from(const NFShmHashTable& __ht);

};

template <class _Val, class _Key, class _HF, class _ExK, class _EqK>
_Hashtable_iterator<_Val,_Key,_HF,_ExK,_EqK>&
_Hashtable_iterator<_Val,_Key,_HF,_ExK,_EqK>::operator++()
{
    const _Node* __old = _M_cur;
    _M_cur = _M_cur->_M_next;
    if (!_M_cur) {
        size_type __bucket = _M_ht->_M_bkt_num(__old->_M_val);
        while (!_M_cur && ++__bucket < _M_ht->_M_buckets.size())
            _M_cur = _M_ht->_M_buckets[__bucket];
    }
    return *this;
}

template <class _Val, class _Key, class _HF, class _ExK, class _EqK>
inline _Hashtable_iterator<_Val,_Key,_HF,_ExK,_EqK>
_Hashtable_iterator<_Val,_Key,_HF,_ExK,_EqK>::operator++(int)
{
    iterator __tmp = *this;
    ++*this;
    return __tmp;
}

template <class _Val, class _Key, class _HF, class _ExK, class _EqK>
_Hashtable_const_iterator<_Val,_Key,_HF,_ExK,_EqK>&
_Hashtable_const_iterator<_Val,_Key,_HF,_ExK,_EqK>::operator++()
{
    const _Node* __old = _M_cur;
    _M_cur = _M_cur->_M_next;
    if (!_M_cur) {
        size_type __bucket = _M_ht->_M_bkt_num(__old->_M_val);
        while (!_M_cur && ++__bucket < _M_ht->_M_buckets.size())
            _M_cur = _M_ht->_M_buckets[__bucket];
    }
    return *this;
}

template <class _Val, class _Key, class _HF, class _ExK, class _EqK>
inline _Hashtable_const_iterator<_Val,_Key,_HF,_ExK,_EqK>
_Hashtable_const_iterator<_Val,_Key,_HF,_ExK,_EqK>::operator++(int)
{
    const_iterator __tmp = *this;
    ++*this;
    return __tmp;
}

template <class _Val, class _Key, class _HF, class _ExK, class _EqK>
inline std::forward_iterator_tag
iterator_category(const _Hashtable_iterator<_Val,_Key,_HF,_ExK,_EqK>&)
{
    return std::forward_iterator_tag();
}

template <class _Val, class _Key, class _HF, class _ExK, class _EqK>
inline _Val*
value_type(const _Hashtable_iterator<_Val,_Key,_HF,_ExK,_EqK>&)
{
    return (_Val*) 0;
}

template <class _Val, class _Key, class _HF, class _ExK, class _EqK>
inline NFShmHashTable<_Val,_Key,_HF,_ExK,_EqK>::difference_type*
distance_type(const _Hashtable_iterator<_Val,_Key,_HF,_ExK,_EqK>&)
{
    return (NFShmHashTable<_Val,_Key,_HF,_ExK,_EqK>::difference_type*) 0;
}

template <class _Val, class _Key, class _HF, class _ExK, class _EqK>
inline std::forward_iterator_tag
iterator_category(const _Hashtable_const_iterator<_Val,_Key,_HF,_ExK,_EqK>&)
{
    return std::forward_iterator_tag();
}

template <class _Val, class _Key, class _HF, class _ExK, class _EqK>
inline _Val*
value_type(const _Hashtable_const_iterator<_Val,_Key,_HF,_ExK,_EqK>&)
{
    return (_Val*) 0;
}

template <class _Val, class _Key, class _HF, class _ExK, class _EqK>
inline NFShmHashTable<_Val,_Key,_HF,_ExK,_EqK>::difference_type*
distance_type(const _Hashtable_const_iterator<_Val,_Key,_HF,_ExK,_EqK>&)
{
    return (NFShmHashTable<_Val,_Key,_HF,_ExK,_EqK>::difference_type*) 0;
}

template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
bool operator==(const NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>& __ht1,
                const NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>& __ht2)
{
    typedef typename NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>::_Node _Node;
    if (__ht1._M_buckets.size() != __ht2._M_buckets.size())
        return false;
    for (int __n = 0; __n < __ht1._M_buckets.size(); ++__n) {
        _Node* __cur1 = __ht1._M_buckets[__n];
        _Node* __cur2 = __ht2._M_buckets[__n];
        for ( ; __cur1 && __cur2 && __cur1->_M_val == __cur2->_M_val;
                __cur1 = __cur1->_M_next, __cur2 = __cur2->_M_next)
        {}
        if (__cur1 || __cur2)
            return false;
    }
    return true;
}

template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
inline bool operator!=(const NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>& __ht1,
                       const NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>& __ht2) {
  return !(__ht1 == __ht2);
}

template <class _Val, class _Key, class _HF, class _Extract, class _EqKey>
inline void swap(NFShmHashTable<_Val, _Key, _HF, _Extract, _EqKey>& __ht1,
                 NFShmHashTable<_Val, _Key, _HF, _Extract, _EqKey>& __ht2) {
  __ht1.swap(__ht2);
}


template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
pair<typename NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>::iterator, bool>
NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>
::insert_unique_noresize(const value_type& __obj)
{
    const size_type __n = _M_bkt_num(__obj);
    _Node* __first = _M_buckets[__n];

    for (_Node* __cur = __first; __cur; __cur = __cur->_M_next)
        if (_M_equals(_M_get_key(__cur->_M_val), _M_get_key(__obj)))
            return pair<iterator, bool>(iterator(__cur, this), false);

    _Node* __tmp = _M_new_node(__obj);
    __tmp->_M_next = __first;
    _M_buckets[__n] = __tmp;
    ++_M_num_elements;
    return pair<iterator, bool>(iterator(__tmp, this), true);
}

template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
typename NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>::iterator
NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>
::insert_equal_noresize(const value_type& __obj)
{
    const size_type __n = _M_bkt_num(__obj);
    _Node* __first = _M_buckets[__n];

    for (_Node* __cur = __first; __cur; __cur = __cur->_M_next)
        if (_M_equals(_M_get_key(__cur->_M_val), _M_get_key(__obj))) {
            _Node* __tmp = _M_new_node(__obj);
            __tmp->_M_next = __cur->_M_next;
            __cur->_M_next = __tmp;
            ++_M_num_elements;
            return iterator(__tmp, this);
        }

    _Node* __tmp = _M_new_node(__obj);
    __tmp->_M_next = __first;
    _M_buckets[__n] = __tmp;
    ++_M_num_elements;
    return iterator(__tmp, this);
}

template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
typename NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>::reference
NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>::find_or_insert(const value_type& __obj)
{
    resize(_M_num_elements + 1);

    size_type __n = _M_bkt_num(__obj);
    _Node* __first = _M_buckets[__n];

    for (_Node* __cur = __first; __cur; __cur = __cur->_M_next)
        if (_M_equals(_M_get_key(__cur->_M_val), _M_get_key(__obj)))
            return __cur->_M_val;

    _Node* __tmp = _M_new_node(__obj);
    __tmp->_M_next = __first;
    _M_buckets[__n] = __tmp;
    ++_M_num_elements;
    return __tmp->_M_val;
}

template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
pair<typename NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>::iterator,
        typename NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>::iterator>
NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>::equal_range(const key_type& __key)
{
    typedef pair<iterator, iterator> _Pii;
    const size_type __n = _M_bkt_num_key(__key);

    for (_Node* __first = _M_buckets[__n]; __first; __first = __first->_M_next)
        if (_M_equals(_M_get_key(__first->_M_val), __key)) {
            for (_Node* __cur = __first->_M_next; __cur; __cur = __cur->_M_next)
                if (!_M_equals(_M_get_key(__cur->_M_val), __key))
                    return _Pii(iterator(__first, this), iterator(__cur, this));
            for (size_type __m = __n + 1; __m < _M_buckets.size(); ++__m)
                if (_M_buckets[__m])
                    return _Pii(iterator(__first, this),
                                iterator(_M_buckets[__m], this));
            return _Pii(iterator(__first, this), end());
        }
    return _Pii(end(), end());
}

template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
pair<typename NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>::const_iterator,
        typename NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>::const_iterator>
NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>
::equal_range(const key_type& __key) const
{
    typedef pair<const_iterator, const_iterator> _Pii;
    const size_type __n = _M_bkt_num_key(__key);

    for (const _Node* __first = _M_buckets[__n] ;
         __first;
         __first = __first->_M_next) {
        if (_M_equals(_M_get_key(__first->_M_val), __key)) {
            for (const _Node* __cur = __first->_M_next;
                 __cur;
                 __cur = __cur->_M_next)
                if (!_M_equals(_M_get_key(__cur->_M_val), __key))
                    return _Pii(const_iterator(__first, this),
                                const_iterator(__cur, this));
            for (size_type __m = __n + 1; __m < _M_buckets.size(); ++__m)
                if (_M_buckets[__m])
                    return _Pii(const_iterator(__first, this),
                                const_iterator(_M_buckets[__m], this));
            return _Pii(const_iterator(__first, this), end());
        }
    }
    return _Pii(end(), end());
}

template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
typename NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>::size_type
NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>::erase(const key_type& __key)
{
    const size_type __n = _M_bkt_num_key(__key);
    _Node* __first = _M_buckets[__n];
    size_type __erased = 0;

    if (__first) {
        _Node* __cur = __first;
        _Node* __next = __cur->_M_next;
        while (__next) {
            if (_M_equals(_M_get_key(__next->_M_val), __key)) {
                __cur->_M_next = __next->_M_next;
                _M_delete_node(__next);
                __next = __cur->_M_next;
                ++__erased;
                --_M_num_elements;
            }
            else {
                __cur = __next;
                __next = __cur->_M_next;
            }
        }
        if (_M_equals(_M_get_key(__first->_M_val), __key)) {
            _M_buckets[__n] = __first->_M_next;
            _M_delete_node(__first);
            ++__erased;
            --_M_num_elements;
        }
    }
    return __erased;
}

template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>::erase(const iterator& __it)
{
    _Node* __p = __it._M_cur;
    if (__p) {
        const size_type __n = _M_bkt_num(__p->_M_val);
        _Node* __cur = _M_buckets[__n];

        if (__cur == __p) {
            _M_buckets[__n] = __cur->_M_next;
            _M_delete_node(__cur);
            --_M_num_elements;
        }
        else {
            _Node* __next = __cur->_M_next;
            while (__next) {
                if (__next == __p) {
                    __cur->_M_next = __next->_M_next;
                    _M_delete_node(__next);
                    --_M_num_elements;
                    break;
                }
                else {
                    __cur = __next;
                    __next = __cur->_M_next;
                }
            }
        }
    }
}

template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>
::erase(iterator __first, iterator __last)
{
    size_type __f_bucket = __first._M_cur ?
                           _M_bkt_num(__first._M_cur->_M_val) : _M_buckets.size();
    size_type __l_bucket = __last._M_cur ?
                           _M_bkt_num(__last._M_cur->_M_val) : _M_buckets.size();

    if (__first._M_cur == __last._M_cur)
        return;
    else if (__f_bucket == __l_bucket)
        _M_erase_bucket(__f_bucket, __first._M_cur, __last._M_cur);
    else {
        _M_erase_bucket(__f_bucket, __first._M_cur, 0);
        for (size_type __n = __f_bucket + 1; __n < __l_bucket; ++__n)
            _M_erase_bucket(__n, 0);
        if (__l_bucket != _M_buckets.size())
            _M_erase_bucket(__l_bucket, __last._M_cur);
    }
}

template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
inline void
NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>::erase(const_iterator __first,
                                             const_iterator __last)
{
    erase(iterator(const_cast<_Node*>(__first._M_cur),
                   const_cast<NFShmHashTable*>(__first._M_ht)),
          iterator(const_cast<_Node*>(__last._M_cur),
                   const_cast<NFShmHashTable*>(__last._M_ht)));
}

template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
inline void
NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>::erase(const const_iterator& __it)
{
    erase(iterator(const_cast<_Node*>(__it._M_cur),
                   const_cast<NFShmHashTable*>(__it._M_ht)));
}

template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>
::resize(size_type __num_elements_hint)
{
    const size_type __old_n = _M_buckets.size();
    if (__num_elements_hint > __old_n) {
        const size_type __n = _M_next_size(__num_elements_hint);
        if (__n > __old_n) {
            vector<_Node*> __tmp(__n, (_Node*)(0),
                                       _M_buckets.get_allocator());
            for (size_type __bucket = 0; __bucket < __old_n; ++__bucket) {
                _Node* __first = _M_buckets[__bucket];
                while (__first) {
                    size_type __new_bucket = _M_bkt_num(__first->_M_val, __n);
                    _M_buckets[__bucket] = __first->_M_next;
                    __first->_M_next = __tmp[__new_bucket];
                    __tmp[__new_bucket] = __first;
                    __first = _M_buckets[__bucket];
                }
            }
            _M_buckets.swap(__tmp);
        }
    }
}

template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>
::_M_erase_bucket(const size_type __n, _Node* __first, _Node* __last)
{
    _Node* __cur = _M_buckets[__n];
    if (__cur == __first)
        _M_erase_bucket(__n, __last);
    else {
        _Node* __next;
        for (__next = __cur->_M_next;
             __next != __first;
             __cur = __next, __next = __cur->_M_next)
            ;
        while (__next != __last) {
            __cur->_M_next = __next->_M_next;
            _M_delete_node(__next);
            __next = __cur->_M_next;
            --_M_num_elements;
        }
    }
}

template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>
::_M_erase_bucket(const size_type __n, _Node* __last)
{
    _Node* __cur = _M_buckets[__n];
    while (__cur != __last) {
        _Node* __next = __cur->_M_next;
        _M_delete_node(__cur);
        __cur = __next;
        _M_buckets[__n] = __cur;
        --_M_num_elements;
    }
}

template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>::clear()
{
    for (size_type __i = 0; __i < _M_buckets.size(); ++__i) {
        _Node* __cur = _M_buckets[__i];
        while (__cur != 0) {
            _Node* __next = __cur->_M_next;
            _M_delete_node(__cur);
            __cur = __next;
        }
        _M_buckets[__i] = 0;
    }
    _M_num_elements = 0;
}


template <class _Val, class _Key, class _HF, class _Ex, class _Eq>
void NFShmHashTable<_Val,_Key,_HF,_Ex,_Eq>
::_M_copy_from(const NFShmHashTable& __ht)
{
    _M_buckets.clear();
    _M_buckets.reserve(__ht._M_buckets.size());
    _M_buckets.insert(_M_buckets.end(), __ht._M_buckets.size(), (_Node*) 0);
    for (size_type __i = 0; __i < __ht._M_buckets.size(); ++__i) {
        const _Node* __cur = __ht._M_buckets[__i];
        if (__cur) {
            _Node* __copy = _M_new_node(__cur->_M_val);
            _M_buckets[__i] = __copy;

            for (_Node* __next = __cur->_M_next;
                 __next;
                 __cur = __next, __next = __cur->_M_next) {
                __copy->_M_next = _M_new_node(__next->_M_val);
                __copy = __copy->_M_next;
            }
        }
    }
    _M_num_elements = __ht._M_num_elements;
}
