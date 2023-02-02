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
        _M_next = NULL;
        _M_prev = NULL;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    NFShmListNodeBase *_M_next;
    NFShmListNodeBase *_M_prev;
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

    Tp _M_data;
    bool m_valid;
};

struct NFShmListIteratorBase
{
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;

    NFShmListNodeBase *_M_node;

    NFShmListIteratorBase(NFShmListNodeBase *__x) : _M_node(__x) {}

    NFShmListIteratorBase() {}

    void _M_incr() { _M_node = _M_node->_M_next; }

    void _M_decr() { _M_node = _M_node->_M_prev; }

    bool operator==(const NFShmListIteratorBase &__x) const
    {
        return _M_node == __x._M_node;
    }

    bool operator!=(const NFShmListIteratorBase &__x) const
    {
        return _M_node != __x._M_node;
    }
};

template<class Tp, class Ref, class Ptr>
struct NFShmListIterator : public NFShmListIteratorBase
{
    typedef NFShmListIterator<Tp, Tp &, Tp *> iterator;
    typedef NFShmListIterator<Tp, const Tp &, const Tp *> const_iterator;
    typedef NFShmListIterator<Tp, Ref, Ptr> _Self;

    typedef Tp value_type;
    typedef Ptr pointer;
    typedef Ref reference;
    typedef NFShmListNode<Tp> _Node;

    NFShmListIterator(_Node *__x) : NFShmListIteratorBase(__x) {}

    NFShmListIterator() {}

    NFShmListIterator(const iterator &__x) : NFShmListIteratorBase(__x._M_node) {}

    reference operator*() const { return ((_Node *) _M_node)->_M_data; }

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
    }

    int CreateInit()
    {
        m_size = 0;
        m_freeStart = 0;
        _M_node->_M_next = _M_node;
        _M_node->_M_prev = _M_node;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

protected:
    NFShmListNode<Tp> _M_node[MAX_SIZE + 1];
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
    typedef Tp value_type;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef NFShmListNode<Tp> _Node;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    typedef typename _Base::allocator_type allocator_type;

    allocator_type get_allocator() const { return _Base::get_allocator(); }

public:
    typedef NFShmListIterator<Tp, Tp &, Tp *> iterator;
    typedef NFShmListIterator<Tp, const Tp &, const Tp *> const_iterator;

#ifdef __STL_CLASS_PARTIAL_SPECIALIZATION
    typedef reverse_iterator<const_iterator> const_reverse_iterator;
  typedef reverse_iterator<iterator>       reverse_iterator;
#else /* __STL_CLASS_PARTIAL_SPECIALIZATION */
    typedef reverse_bidirectional_iterator <const_iterator, value_type,
    const_reference, difference_type>
            const_reverse_iterator;
    typedef reverse_bidirectional_iterator <iterator, value_type, reference,
    difference_type>
            reverse_iterator;
#endif /* __STL_CLASS_PARTIAL_SPECIALIZATION */

protected:
    using _Base::_M_node;
    using _Base::_M_put_node;
    using _Base::_M_get_node;

protected:
    _Node *_M_create_node(const Tp &__x)
    {
        _Node *__p = _M_get_node();
        __STL_TRY{
                _Construct(&__p->_M_data, __x);
        }
        __STL_UNWIND(_M_put_node(__p));
        return __p;
    }

    _Node *_M_create_node()
    {
        _Node *__p = _M_get_node();
        __STL_TRY{
                _Construct(&__p->_M_data);
        }
        __STL_UNWIND(_M_put_node(__p));
        return __p;
    }

public:
    explicit NFShmList(const allocator_type &__a = allocator_type()) : _Base(__a) {}

    iterator begin() { return (_Node *) (_M_node->_M_next); }

    const_iterator begin() const { return (_Node *) (_M_node->_M_next); }

    iterator end() { return _M_node; }

    const_iterator end() const { return _M_node; }

    reverse_iterator rbegin() { return reverse_iterator(end()); }

    const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

    reverse_iterator rend() { return reverse_iterator(begin()); }

    const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

    bool empty() const { return _M_node->_M_next == _M_node; }

    size_type size() const
    {
        size_type __result = 0;
        distance(begin(), end(), __result);
        return __result;
    }

    size_type max_size() const { return size_type(-1); }

    reference front() { return *begin(); }

    const_reference front() const { return *begin(); }

    reference back() { return *(--end()); }

    const_reference back() const { return *(--end()); }

    void swap(list<Tp, _Alloc> &__x) { __STD::swap(_M_node, __x._M_node); }

    iterator insert(iterator __position, const Tp &__x)
    {
        _Node *__tmp = _M_create_node(__x);
        __tmp->_M_next = __position._M_node;
        __tmp->_M_prev = __position._M_node->_M_prev;
        __position._M_node->_M_prev->_M_next = __tmp;
        __position._M_node->_M_prev = __tmp;
        return __tmp;
    }

    iterator insert(iterator __position) { return insert(__position, Tp()); }

#ifdef __STL_MEMBER_TEMPLATES
    // Check whether it's an integral type.  If so, it's not an iterator.

  template<class _Integer>
  void _M_insert_dispatch(iterator __pos, _Integer __n, _Integer __x,
                          __true_type) {
    _M_fill_insert(__pos, (size_type) __n, (_Tp) __x);
  }

  template <class _InputIterator>
  void _M_insert_dispatch(iterator __pos,
                          _InputIterator __first, _InputIterator __last,
                          __false_type);

  template <class _InputIterator>
  void insert(iterator __pos, _InputIterator __first, _InputIterator __last) {
    typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
    _M_insert_dispatch(__pos, __first, __last, _Integral());
  }

#else /* __STL_MEMBER_TEMPLATES */

    void insert(iterator __position, const Tp *__first, const Tp *__last);

    void insert(iterator __position,
                const_iterator __first, const_iterator __last);

#endif /* __STL_MEMBER_TEMPLATES */

    void insert(iterator __pos, size_type __n, const Tp &__x) { _M_fill_insert(__pos, __n, __x); }

    void _M_fill_insert(iterator __pos, size_type __n, const Tp &__x);

    void push_front(const Tp &__x) { insert(begin(), __x); }

    void push_front() { insert(begin()); }

    void push_back(const Tp &__x) { insert(end(), __x); }

    void push_back() { insert(end()); }

    iterator erase(iterator __position)
    {
        NFShmListNodeBase *__next_node = __position._M_node->_M_next;
        NFShmListNodeBase *__prev_node = __position._M_node->_M_prev;
        _Node *__n = (_Node *) __position._M_node;
        __prev_node->_M_next = __next_node;
        __next_node->_M_prev = __prev_node;
        _Destroy(&__n->_M_data);
        _M_put_node(__n);
        return iterator((_Node *) __next_node);
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

    NFShmList(size_type __n, const Tp &__value,
              const allocator_type &__a = allocator_type())
            : _Base(__a) { insert(begin(), __n, __value); }

    explicit NFShmList(size_type __n)
            : _Base(allocator_type()) { insert(begin(), __n, Tp()); }

#ifdef __STL_MEMBER_TEMPLATES

    // We don't need any dispatching tricks here, because insert does all of
  // that anyway.
  template <class _InputIterator>
  list(_InputIterator __first, _InputIterator __last,
       const allocator_type& __a = allocator_type())
    : _Base(__a)
    { insert(begin(), __first, __last); }

#else /* __STL_MEMBER_TEMPLATES */

    NFShmList(const Tp *__first, const Tp *__last,
              const allocator_type &__a = allocator_type())
            : _Base(__a) { this->insert(begin(), __first, __last); }

    NFShmList(const_iterator __first, const_iterator __last,
              const allocator_type &__a = allocator_type())
            : _Base(__a) { this->insert(begin(), __first, __last); }

#endif /* __STL_MEMBER_TEMPLATES */

    NFShmList(const list<Tp, _Alloc> &__x) : _Base(__x.get_allocator()) { insert(begin(), __x.begin(), __x.end()); }

    ~NFShmList() {}

    list<Tp, _Alloc> &operator=(const list<Tp, _Alloc> &__x);

public:
    // assign(), a generalized assignment member function.  Two
    // versions: one that takes a count, and one that takes a range.
    // The range version is a member template, so we dispatch on whether
    // or not the type is an integer.

    void assign(size_type __n, const Tp &__val) { _M_fill_assign(__n, __val); }

    void _M_fill_assign(size_type __n, const Tp &__val);

#ifdef __STL_MEMBER_TEMPLATES

    template <class _InputIterator>
  void assign(_InputIterator __first, _InputIterator __last) {
    typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
    _M_assign_dispatch(__first, __last, _Integral());
  }

  template <class _Integer>
  void _M_assign_dispatch(_Integer __n, _Integer __val, __true_type)
    { _M_fill_assign((size_type) __n, (_Tp) __val); }

  template <class _InputIterator>
  void _M_assign_dispatch(_InputIterator __first, _InputIterator __last,
                          __false_type);

#endif /* __STL_MEMBER_TEMPLATES */

protected:
    void transfer(iterator __position, iterator __first, iterator __last)
    {
        if (__position != __last)
        {
            // Remove [first, last) from its old position.
            __last._M_node->_M_prev->_M_next = __position._M_node;
            __first._M_node->_M_prev->_M_next = __last._M_node;
            __position._M_node->_M_prev->_M_next = __first._M_node;

            // Splice [first, last) into its new position.
            NFShmListNodeBase *__tmp = __position._M_node->_M_prev;
            __position._M_node->_M_prev = __last._M_node->_M_prev;
            __last._M_node->_M_prev = __first._M_node->_M_prev;
            __first._M_node->_M_prev = __tmp;
        }
    }

public:
    void splice(iterator __position, NFShmList &__x)
    {
        if (!__x.empty())
            this->transfer(__position, __x.begin(), __x.end());
    }

    void splice(iterator __position, NFShmList &, iterator __i)
    {
        iterator __j = __i;
        ++__j;
        if (__position == __i || __position == __j) return;
        this->transfer(__position, __i, __j);
    }

    void splice(iterator __position, NFShmList &, iterator __first, iterator __last)
    {
        if (__first != __last)
            this->transfer(__position, __first, __last);
    }

    void remove(const Tp &__value);

    void unique();

    void merge(NFShmList &__x);

    void reverse();

    void sort();

#ifdef __STL_MEMBER_TEMPLATES
    template <class _Predicate> void remove_if(_Predicate);
  template <class _BinaryPredicate> void unique(_BinaryPredicate);
  template <class _StrictWeakOrdering> void merge(list&, _StrictWeakOrdering);
  template <class _StrictWeakOrdering> void sort(_StrictWeakOrdering);
#endif /* __STL_MEMBER_TEMPLATES */
};


template<class _Tp, class _Alloc>
inline bool
operator==(const list<_Tp, _Alloc> &__x, const list<_Tp, _Alloc> &__y)
{
    typedef typename NFShmList<_Tp, _Alloc>::const_iterator const_iterator;
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

template<class _Tp, class _Alloc>
inline bool operator<(const list<_Tp, _Alloc> &__x,
                      const list<_Tp, _Alloc> &__y)
{
    return lexicographical_compare(__x.begin(), __x.end(),
                                   __y.begin(), __y.end());
}

#ifdef __STL_FUNCTION_TMPL_PARTIAL_ORDER

template <class _Tp, class _Alloc>
inline bool operator!=(const list<_Tp,_Alloc>& __x,
                       const list<_Tp,_Alloc>& __y) {
  return !(__x == __y);
}

template <class _Tp, class _Alloc>
inline bool operator>(const list<_Tp,_Alloc>& __x,
                      const list<_Tp,_Alloc>& __y) {
  return __y < __x;
}

template <class _Tp, class _Alloc>
inline bool operator<=(const list<_Tp,_Alloc>& __x,
                       const list<_Tp,_Alloc>& __y) {
  return !(__y < __x);
}

template <class _Tp, class _Alloc>
inline bool operator>=(const list<_Tp,_Alloc>& __x,
                       const list<_Tp,_Alloc>& __y) {
  return !(__x < __y);
}

template <class _Tp, class _Alloc>
inline void
swap(list<_Tp, _Alloc>& __x, list<_Tp, _Alloc>& __y)
{
  __x.swap(__y);
}

#endif /* __STL_FUNCTION_TMPL_PARTIAL_ORDER */

#ifdef __STL_MEMBER_TEMPLATES

template <class _Tp, class _Alloc> template <class _InputIter>
void
list<_Tp, _Alloc>::_M_insert_dispatch(iterator __position,
                                      _InputIter __first, _InputIter __last,
                                      __false_type)
{
  for ( ; __first != __last; ++__first)
    insert(__position, *__first);
}

#else /* __STL_MEMBER_TEMPLATES */

template<class _Tp, class _Alloc>
void
NFShmList<_Tp, _Alloc>::insert(iterator __position,
                               const _Tp *__first, const _Tp *__last)
{
    for (; __first != __last; ++__first)
        insert(__position, *__first);
}

template<class _Tp, class _Alloc>
void
NFShmList<_Tp, _Alloc>::insert(iterator __position,
                               const_iterator __first, const_iterator __last)
{
    for (; __first != __last; ++__first)
        insert(__position, *__first);
}

#endif /* __STL_MEMBER_TEMPLATES */

template<class _Tp, class _Alloc>
void
NFShmList<_Tp, _Alloc>::_M_fill_insert(iterator __position,
                                       size_type __n, const _Tp &__x)
{
    for (; __n > 0; --__n)
        insert(__position, __x);
}

template<class _Tp, class _Alloc>
typename list<_Tp, _Alloc>::iterator NFShmList<_Tp, _Alloc>::erase(iterator __first,
                                                                   iterator __last)
{
    while (__first != __last)
        erase(__first++);
    return __last;
}

template<class _Tp, class _Alloc>
void NFShmList<_Tp, _Alloc>::resize(size_type __new_size, const _Tp &__x)
{
    iterator __i = begin();
    size_type __len = 0;
    for (; __i != end() && __len < __new_size; ++__i, ++__len);
    if (__len == __new_size)
        erase(__i, end());
    else                          // __i == end()
        insert(end(), __new_size - __len, __x);
}

template<class _Tp, class _Alloc>
list<_Tp, _Alloc> &NFShmList<_Tp, _Alloc>::operator=(const list<_Tp, _Alloc> &__x)
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

template<class _Tp, class _Alloc>
void NFShmList<_Tp, _Alloc>::_M_fill_assign(size_type __n, const _Tp &__val)
{
    iterator __i = begin();
    for (; __i != end() && __n > 0; ++__i, --__n)
        *__i = __val;
    if (__n > 0)
        insert(end(), __n, __val);
    else
        erase(__i, end());
}

#ifdef __STL_MEMBER_TEMPLATES

template <class _Tp, class _Alloc> template <class _InputIter>
void
list<_Tp, _Alloc>::_M_assign_dispatch(_InputIter __first2, _InputIter __last2,
                                      __false_type)
{
  iterator __first1 = begin();
  iterator __last1 = end();
  for ( ; __first1 != __last1 && __first2 != __last2; ++__first1, ++__first2)
    *__first1 = *__first2;
  if (__first2 == __last2)
    erase(__first1, __last1);
  else
    insert(__last1, __first2, __last2);
}

#endif /* __STL_MEMBER_TEMPLATES */

template<class _Tp, class _Alloc>
void NFShmList<_Tp, _Alloc>::remove(const _Tp &__value)
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

template<class _Tp, class _Alloc>
void NFShmList<_Tp, _Alloc>::unique()
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

template<class _Tp, class _Alloc>
void NFShmList<_Tp, _Alloc>::merge(list<_Tp, _Alloc> &__x)
{
    iterator __first1 = begin();
    iterator __last1 = end();
    iterator __first2 = __x.begin();
    iterator __last2 = __x.end();
    while (__first1 != __last1 && __first2 != __last2)
        if (*__first2 < *__first1)
        {
            iterator __next = __first2;
            transfer(__first1, __first2, ++__next);
            __first2 = __next;
        }
        else
            ++__first1;
    if (__first2 != __last2) transfer(__last1, __first2, __last2);
}

inline void __List_base_reverse(NFShmListNodeBase *__p)
{
    NFShmListNodeBase *__tmp = __p;
    do
    {
        __STD::swap(__tmp->_M_next, __tmp->_M_prev);
        __tmp = __tmp->_M_prev;     // Old next node is now prev.
    } while (__tmp != __p);
}

template<class _Tp, class _Alloc>
inline void NFShmList<_Tp, _Alloc>::reverse()
{
    __List_base_reverse(this->_M_node);
}

template<class _Tp, class _Alloc>
void NFShmList<_Tp, _Alloc>::sort()
{
    // Do nothing if the list has length 0 or 1.
    if (_M_node->_M_next != _M_node && _M_node->_M_next->_M_next != _M_node)
    {
        list<_Tp, _Alloc> __carry;
        list<_Tp, _Alloc> __counter[64];
        int __fill = 0;
        while (!empty())
        {
            __carry.splice(__carry.begin(), *this, begin());
            int __i = 0;
            while (__i < __fill && !__counter[__i].empty())
            {
                __counter[__i].merge(__carry);
                __carry.swap(__counter[__i++]);
            }
            __carry.swap(__counter[__i]);
            if (__i == __fill) ++__fill;
        }

        for (int __i = 1; __i < __fill; ++__i)
            __counter[__i].merge(__counter[__i - 1]);
        swap(__counter[__fill - 1]);
    }
}

#ifdef __STL_MEMBER_TEMPLATES

template <class _Tp, class _Alloc> template <class _Predicate>
void list<_Tp, _Alloc>::remove_if(_Predicate __pred)
{
  iterator __first = begin();
  iterator __last = end();
  while (__first != __last) {
    iterator __next = __first;
    ++__next;
    if (__pred(*__first)) erase(__first);
    __first = __next;
  }
}

template <class _Tp, class _Alloc> template <class _BinaryPredicate>
void list<_Tp, _Alloc>::unique(_BinaryPredicate __binary_pred)
{
  iterator __first = begin();
  iterator __last = end();
  if (__first == __last) return;
  iterator __next = __first;
  while (++__next != __last) {
    if (__binary_pred(*__first, *__next))
      erase(__next);
    else
      __first = __next;
    __next = __first;
  }
}

template <class _Tp, class _Alloc> template <class _StrictWeakOrdering>
void list<_Tp, _Alloc>::merge(list<_Tp, _Alloc>& __x,
                              _StrictWeakOrdering __comp)
{
  iterator __first1 = begin();
  iterator __last1 = end();
  iterator __first2 = __x.begin();
  iterator __last2 = __x.end();
  while (__first1 != __last1 && __first2 != __last2)
    if (__comp(*__first2, *__first1)) {
      iterator __next = __first2;
      transfer(__first1, __first2, ++__next);
      __first2 = __next;
    }
    else
      ++__first1;
  if (__first2 != __last2) transfer(__last1, __first2, __last2);
}

template <class _Tp, class _Alloc> template <class _StrictWeakOrdering>
void list<_Tp, _Alloc>::sort(_StrictWeakOrdering __comp)
{
  // Do nothing if the list has length 0 or 1.
  if (_M_node->_M_next != _M_node && _M_node->_M_next->_M_next != _M_node) {
    list<_Tp, _Alloc> __carry;
    list<_Tp, _Alloc> __counter[64];
    int __fill = 0;
    while (!empty()) {
      __carry.splice(__carry.begin(), *this, begin());
      int __i = 0;
      while(__i < __fill && !__counter[__i].empty()) {
        __counter[__i].merge(__carry, __comp);
        __carry.swap(__counter[__i++]);
      }
      __carry.swap(__counter[__i]);
      if (__i == __fill) ++__fill;
    }

    for (int __i = 1; __i < __fill; ++__i)
      __counter[__i].merge(__counter[__i-1], __comp);
    swap(__counter[__fill-1]);
  }
}