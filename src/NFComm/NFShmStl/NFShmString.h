// -------------------------------------------------------------------------
//    @FileName         :    NFShmString.h
//    @Author           :    gaoyi
//    @Date             :    23-2-13
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmString
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFShmCore/NFShmMgr.h"

template<class Tp, int MAX_SIZE>
class NFShmStringBase
{
protected:
    Tp m_data[MAX_SIZE + 1];
    size_t m_size;

    size_t max_size() const { return MAX_SIZE; }

    NFShmStringBase()
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

    ~NFShmStringBase()
    {

    }

    int CreateInit()
    {
        m_size = 0;
        memset(m_data, 0, MAX_SIZE + 1);
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }
};

// ------------------------------------------------------------
// Class basic_string.

// Class invariants:
// (1) [start, finish) is a valid range.
// (2) Each iterator in [start, finish) points to a valid object
//     of type value_type.
// (3) *finish is a valid object of type value_type; in particular,
//     it is value_type().
// (4) [finish + 1, end_of_storage) is a valid range.
// (5) Each iterator in [finish + 1, end_of_storage) points to
//     unininitialized memory.

// Note one important consequence: a string of length n must manage
// a block of memory whose size is at least n + 1.


template<class CharT, int MAX_SIZE, class Traits>
class NFShmBasicString: private NFShmStringBase<CharT, MAX_SIZE>
{
public:
    typedef CharT value_type;
    typedef Traits traits_type;

    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    typedef const value_type *const_iterator;
    typedef value_type *iterator;

    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;


    static const size_type npos;

    typedef NFShmStringBase<CharT, MAX_SIZE> _Base;

public:                         // Constructor, destructor, assignment.
    explicit NFShmBasicString()
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

    NFShmBasicString(const NFShmBasicString &__s)
    {
        _M_range_initialize(__s.begin(), __s.end());
    }

    NFShmBasicString(const NFShmBasicString &__s, size_type __pos, size_type __n = npos)
    {
        if (__pos <= __s.size())
        {
            _M_range_initialize(__s.begin() + __pos,
                                __s.begin() + __pos + min(__n, __s.size() - __pos));
        }
    }

    NFShmBasicString(const CharT *__s, size_type __n) { _M_range_initialize(__s, __s + __n); }

    NFShmBasicString(const CharT *__s) { _M_range_initialize(__s, __s + Traits::length(__s)); }

    NFShmBasicString(size_type __n, CharT __c)
    {
        if (__n > MAX_SIZE)
        {
            __n = MAX_SIZE;
        }
        std::uninitialized_fill_n(m_data, __n, __c);
        m_size = __n;
        _M_terminate_string();
    }

    // Check to see if _InputIterator is an integer type.  If so, then
    // it can't be an iterator.
    template<class _InputIterator>
    NFShmBasicString(_InputIterator __f, _InputIterator __l)
    {
        typedef typename std::__is_integer<_InputIterator>::__type _Integral;
        _M_initialize_dispatch(__f, __l, _Integral());
    }

    NFShmBasicString(const CharT *__f, const CharT *__l)
    {
        _M_range_initialize(__f, __l);
    }

    ~NFShmBasicString()
    {

    }

    NFShmBasicString &operator=(const NFShmBasicString &__s)
    {
        if (&__s != this)
            assign(__s.begin(), __s.end());
        return *this;
    }

    NFShmBasicString &operator=(const CharT *__s) { return assign(__s, __s + Traits::length(__s)); }

    NFShmBasicString &operator=(CharT __c) { return assign(static_cast<size_type>(1), __c); }

    int CreateInit()
    {
        _M_terminate_string();
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

protected:
    using _Base::m_data;
    using _Base::m_size;
private:

    void _M_construct_null(CharT *__p)
    {
        std::_Construct(__p);
        *__p = (CharT) 0;
    }

    static CharT _M_null()
    {
        return (CharT) 0;
    }

    void _M_terminate_string()
    {
        _M_construct_null(m_data + m_size);
    }

    template<class _InputIter>
    void _M_range_initialize(_InputIter __f, _InputIter __l,
                             std::input_iterator_tag)
    {
        _M_construct_null(m_data + m_size);
        append(__f, __l);
    }

    template<class _ForwardIter>
    void _M_range_initialize(_ForwardIter __f, _ForwardIter __l,
                             std::forward_iterator_tag)
    {
        difference_type __n = std::distance(__f, __l);
        if (__n > MAX_SIZE)
        {
            __n = MAX_SIZE;
        }
        auto finish = std::uninitialized_copy_n(__f, __n, m_data);
        m_size = finish - m_data;
        _M_terminate_string();
    }

    template<class _InputIter>
    void _M_range_initialize(_InputIter __f, _InputIter __l)
    {
        typedef typename iterator_traits<_InputIter>::iterator_category _Category;
        _M_range_initialize(__f, __l, _Category());
    }

    template<class _Integer>
    void _M_initialize_dispatch(_Integer __n, _Integer __x, std::__true_type)
    {
        if (__n > MAX_SIZE)
        {
            __n = MAX_SIZE;
        }

        std::uninitialized_fill_n(m_data, __n, __x);
        m_size = __n;
        _M_terminate_string();
    }

    template<class _InputIter>
    void _M_initialize_dispatch(_InputIter __f, _InputIter __l, std::__false_type)
    {
        _M_range_initialize(__f, __l);
    }


    void _M_range_initialize(const CharT *__f, const CharT *__l)
    {
        ptrdiff_t __n = __l - __f;
        if (__n > MAX_SIZE)
        {
            __n = MAX_SIZE;
        }
        auto finish = uninitialized_copy_n(__f, __n, m_data);
        m_size = finish - m_data;
        _M_terminate_string();
    }


public:                         // Iterators.
    iterator begin() { return m_data; }

    iterator end() { return m_data + m_size; }

    const_iterator begin() const { return m_data; }

    const_iterator end() const { return m_data + m_size; }

    reverse_iterator rbegin() { return reverse_iterator(m_data + m_size); }

    reverse_iterator rend() { return reverse_iterator(m_data); }

    const_reverse_iterator rbegin() const { return const_reverse_iterator(m_data + m_size); }

    const_reverse_iterator rend() const { return const_reverse_iterator(m_data); }

public:                         // Size, capacity, etc.
    size_type size() const { return m_size; }

    size_type length() const { return size(); }

    size_t max_size() const { return _Base::max_size(); }

    void resize(size_type __n, CharT __c)
    {
        if (__n <= size())
            erase(begin() + __n, end());
        else
            append(__n - size(), __c);
    }

    void resize(size_type __n) { resize(__n, _M_null()); }

    void reserve(size_type = 0);

    size_type capacity() const { return (m_data + MAX_SIZE - m_data) - 1; }

    void clear()
    {
        if (!empty())
        {
            Traits::assign(*m_data, _M_null());
            std::_Destroy(m_data + 1, m_data + m_size + 1);
            m_size = 0;
        }
    }

    bool empty() const { return m_size == 0; }

public:                         // Element access.

    const_reference operator[](size_type __n) const { return *(m_data + __n); }

    reference operator[](size_type __n) { return *(m_data + __n); }

    const_reference at(size_type __n) const
    {
        NF_ASSERT(__n < size());
        return *(m_data + __n);
    }

    reference at(size_type __n)
    {
        NF_ASSERT(__n < size());
        return *(m_data + __n);
    }

public:                         // Append, operator+=, push_back.

    NFShmBasicString &operator+=(const NFShmBasicString &__s) { return append(__s); }

    NFShmBasicString &operator+=(const CharT *__s) { return append(__s); }

    NFShmBasicString &operator+=(CharT __c)
    {
        push_back(__c);
        return *this;
    }

    NFShmBasicString &append(const NFShmBasicString &__s) { return append(__s.begin(), __s.end()); }

    NFShmBasicString &append(const NFShmBasicString &__s,
                             size_type __pos, size_type __n)
    {
        NF_ASSERT(__pos <= __s.size());
        return append(__s.begin() + __pos,
                      __s.begin() + __pos + min(__n, __s.size() - __pos));
    }

    NFShmBasicString &append(const CharT *__s, size_type __n) { return append(__s, __s + __n); }

    NFShmBasicString &append(const CharT *__s) { return append(__s, __s + Traits::length(__s)); }

    NFShmBasicString &append(size_type __n, CharT __c);


    // Check to see if _InputIterator is an integer type.  If so, then
    // it can't be an iterator.
    template<class _InputIter>
    NFShmBasicString &append(_InputIter __first, _InputIter __last)
    {
        typedef typename std::__is_integer<_InputIter>::__type _Integral;
        return _M_append_dispatch(__first, __last, _Integral());
    }

    NFShmBasicString &append(const CharT *__first, const CharT *__last);

    void push_back(CharT __c)
    {
        if (m_size == MAX_SIZE)
        {
            return;
        }
        _M_construct_null(m_data + m_size + 1);
        Traits::assign(*(m_data + m_size), __c);
        ++m_size;
    }

    void pop_back()
    {
        Traits::assign(*(m_data + m_size - 1), _M_null());
        std::_Destroy(m_data + m_size);
        --m_size;
    }

private:                        // Helper functions for append.

    template<class _InputIter>
    NFShmBasicString &append(_InputIter __f, _InputIter __l, std::input_iterator_tag);

    template<class _ForwardIter>
    NFShmBasicString &append(_ForwardIter __f, _ForwardIter __l,
                             std::forward_iterator_tag);

    template<class _Integer>
    NFShmBasicString &_M_append_dispatch(_Integer __n, _Integer __x, __true_type)
    {
        return append((size_type) __n, (CharT) __x);
    }

    template<class _InputIter>
    NFShmBasicString &_M_append_dispatch(_InputIter __f, _InputIter __l,
                                         __false_type)
    {
        return append(__f, __l, typename std::iterator_traits<_InputIter>::iterator_category());
    }

public:                         // Assign

    NFShmBasicString &assign(const NFShmBasicString &__s) { return assign(__s.begin(), __s.end()); }

    NFShmBasicString &assign(const NFShmBasicString &__s,
                             size_type __pos, size_type __n)
    {
        NF_ASSERT(__pos <= __s.size());
        return assign(__s.begin() + __pos,
                      __s.begin() + __pos + min(__n, __s.size() - __pos));
    }

    NFShmBasicString &assign(const CharT *__s, size_type __n) { return assign(__s, __s + __n); }

    NFShmBasicString &assign(const CharT *__s) { return assign(__s, __s + Traits::length(__s)); }

    NFShmBasicString &assign(size_type __n, CharT __c);

    // Check to see if _InputIterator is an integer type.  If so, then
    // it can't be an iterator.
    template<class _InputIter>
    NFShmBasicString &assign(_InputIter __first, _InputIter __last)
    {
        typedef typename std::__is_integer<_InputIter>::__type _Integral;
        return _M_assign_dispatch(__first, __last, _Integral());
    }

    NFShmBasicString &assign(const CharT *__f, const CharT *__l);

private:                        // Helper functions for assign.

    template<class _Integer>
    NFShmBasicString &_M_assign_dispatch(_Integer __n, _Integer __x, __true_type)
    {
        return assign((size_type) __n, (CharT) __x);
    }

    template<class _InputIter>
    NFShmBasicString &_M_assign_dispatch(_InputIter __f, _InputIter __l,
                                         __false_type);

public:                         // Insert

    NFShmBasicString &insert(size_type __pos, const NFShmBasicString &__s)
    {
        NF_ASSERT(__pos <= size());
        NF_ASSERT(size() <= max_size() - __s.size());
        insert(m_data + __pos, __s.begin(), __s.end());
        return *this;
    }

    NFShmBasicString &insert(size_type __pos, const NFShmBasicString &__s,
                             size_type __beg, size_type __n)
    {
        NF_ASSERT(!(__pos > size() || __beg > __s.size()));
        size_type __len = min(__n, __s.size() - __beg);
        NF_ASSERT(!(size() > max_size() - __len));
        insert(m_data + __pos,
               __s.begin() + __beg, __s.begin() + __beg + __len);
        return *this;
    }

    NFShmBasicString &insert(size_type __pos, const CharT *__s, size_type __n)
    {
        NF_ASSERT(__pos <= size());
        NF_ASSERT(size() <= max_size() - __n);
        insert(m_data + __pos, __s, __s + __n);
        return *this;
    }

    NFShmBasicString &insert(size_type __pos, const CharT *__s)
    {
        NF_ASSERT(__pos <= size());
        size_type __len = Traits::length(__s);
        NF_ASSERT(size() <= max_size() - __len);
        insert(m_data + __pos, __s, __s + __len);
        return *this;
    }

    NFShmBasicString &insert(size_type __pos, size_type __n, CharT __c)
    {
        NF_ASSERT(__pos <= size());
        NF_ASSERT(size() <= max_size() - __n);
        insert(m_data + __pos, __n, __c);
        return *this;
    }

    iterator insert(iterator __p, CharT __c)
    {
        if (__p == m_data + m_size)
        {
            push_back(__c);
            return m_data + m_size - 1;
        }
        else
            return _M_insert_aux(__p, __c);
    }

    void insert(iterator __p, size_t __n, CharT __c);

    // Check to see if _InputIterator is an integer type.  If so, then
    // it can't be an iterator.
    template<class _InputIter>
    void insert(iterator __p, _InputIter __first, _InputIter __last)
    {
        typedef typename std::__is_integer<_InputIter>::__type _Integral;
        _M_insert_dispatch(__p, __first, __last, _Integral());
    }

    void insert(iterator __p, const CharT *__first, const CharT *__last);

private:                        // Helper functions for insert.

    template<class _InputIter>
    void insert(iterator __p, _InputIter, _InputIter, std::input_iterator_tag);

    template<class _ForwardIter>
    void insert(iterator __p, _ForwardIter, _ForwardIter, std::forward_iterator_tag);


    template<class _Integer>
    void _M_insert_dispatch(iterator __p, _Integer __n, _Integer __x,
                            __true_type)
    {
        insert(__p, (size_type) __n, (CharT) __x);
    }

    template<class _InputIter>
    void _M_insert_dispatch(iterator __p, _InputIter __first, _InputIter __last,
                            __false_type)
    {
        insert(__p, __first, __last, typename std::iterator_traits<_InputIter>::iterator_category());
    }

    template<class _InputIterator>
    void
    _M_copy(_InputIterator __first, _InputIterator __last, iterator __result)
    {
        for (; __first != __last; ++__first, ++__result)
            Traits::assign(*__result, *__first);
    }

    iterator _M_insert_aux(iterator, CharT);

    void
    _M_copy(const CharT *__first, const CharT *__last, CharT *__result)
    {
        Traits::copy(__result, __first, __last - __first);
    }

public:                         // Erase.

    NFShmBasicString &erase(size_type __pos = 0, size_type __n = npos)
    {
        NF_ASSERT(__pos <= size());
        erase(m_data + __pos, m_data + __pos + min(__n, size() - __pos));
        return *this;
    }

    iterator erase(iterator __position)
    {
        // The move includes the terminating null.
        Traits::move(__position, __position + 1, m_data + m_size - __position);
        std::_Destroy(m_data + m_size);
        --m_data + m_size;
        return __position;
    }

    iterator erase(iterator __first, iterator __last)
    {
        if (__first != __last)
        {
            // The move includes the terminating null.
            Traits::move(__first, __last, (m_data + m_size - __last) + 1);
            const iterator __new_finish = m_data + m_size - (__last - __first);
            destroy(__new_finish + 1, m_data + m_size + 1);
            m_data + m_size = __new_finish;
        }
        return __first;
    }

public:                         // Replace.  (Conceptually equivalent
    // to erase followed by insert.)
    NFShmBasicString &replace(size_type __pos, size_type __n,
                              const NFShmBasicString &__s)
    {
        NF_ASSERT(__pos <= size());
        const size_type __len = min(__n, size() - __pos);
        NF_ASSERT(size() - __len < max_size() - __s.size());
        return replace(m_data + __pos, m_data + __pos + __len,
                       __s.begin(), __s.end());
    }

    NFShmBasicString &replace(size_type __pos1, size_type __n1,
                              const NFShmBasicString &__s,
                              size_type __pos2, size_type __n2)
    {
        NF_ASSERT(!(__pos1 > size() || __pos2 > __s.size()));
        const size_type __len1 = min(__n1, size() - __pos1);
        const size_type __len2 = min(__n2, __s.size() - __pos2);
        NF_ASSERT(size() - __len1 < max_size() - __len2);
        return replace(m_data + __pos1, m_data + __pos1 + __len1,
                       __s.m_data + __pos2, __s.m_data + __pos2 + __len2);
    }

    NFShmBasicString &replace(size_type __pos, size_type __n1,
                              const CharT *__s, size_type __n2)
    {
        NF_ASSERT(__pos <= size());
        const size_type __len = min(__n1, size() - __pos);
        NF_ASSERT(!(__n2 > max_size() || size() - __len >= max_size() - __n2));
        return replace(m_data + __pos, m_data + __pos + __len,
                       __s, __s + __n2);
    }

    NFShmBasicString &replace(size_type __pos, size_type __n1,
                              const CharT *__s)
    {
        NF_ASSERT(__pos <= size());
        const size_type __len = min(__n1, size() - __pos);
        const size_type __n2 = Traits::length(__s);
        NF_ASSERT(!(__n2 > max_size() || size() - __len >= max_size() - __n2));
        return replace(m_data + __pos, m_data + __pos + __len,
                       __s, __s + Traits::length(__s));
    }

    NFShmBasicString &replace(size_type __pos, size_type __n1,
                              size_type __n2, CharT __c)
    {
        NF_ASSERT(__pos <= size());
        const size_type __len = min(__n1, size() - __pos);
        NF_ASSERT(!(__n2 > max_size() || size() - __len >= max_size() - __n2));
        return replace(m_data + __pos, m_data + __pos + __len, __n2, __c);
    }

    NFShmBasicString &replace(iterator __first, iterator __last,
                              const NFShmBasicString &__s) { return replace(__first, __last, __s.begin(), __s.end()); }

    NFShmBasicString &replace(iterator __first, iterator __last,
                              const CharT *__s, size_type __n) { return replace(__first, __last, __s, __s + __n); }

    NFShmBasicString &replace(iterator __first, iterator __last,
                              const CharT *__s)
    {
        return replace(__first, __last, __s, __s + Traits::length(__s));
    }

    NFShmBasicString &replace(iterator __first, iterator __last,
                              size_type __n, CharT __c);

    // Check to see if _InputIterator is an integer type.  If so, then
    // it can't be an iterator.
    template<class _InputIter>
    NFShmBasicString &replace(iterator __first, iterator __last,
                              _InputIter __f, _InputIter __l)
    {
        typedef typename std::__is_integer<_InputIter>::__type _Integral;
        return _M_replace_dispatch(__first, __last, __f, __l, _Integral());
    }

    NFShmBasicString &replace(iterator __first, iterator __last,
                              const CharT *__f, const CharT *__l);

private:                        // Helper functions for replace.

    template<class _Integer>
    NFShmBasicString &_M_replace_dispatch(iterator __first, iterator __last,
                                          _Integer __n, _Integer __x,
                                          __true_type)
    {
        return replace(__first, __last, (size_type) __n, (CharT) __x);
    }

    template<class _InputIter>
    NFShmBasicString &_M_replace_dispatch(iterator __first, iterator __last,
                                          _InputIter __f, _InputIter __l,
                                          __false_type)
    {
        typedef typename iterator_traits<_InputIter>::iterator_category _Category;
        return replace(__first, __last, __f, __l, _Category());
    }

    template<class _InputIter>
    NFShmBasicString &replace(iterator __first, iterator __last,
                              _InputIter __f, _InputIter __l, input_iterator_tag);

    template<class _ForwardIter>
    NFShmBasicString &replace(iterator __first, iterator __last,
                              _ForwardIter __f, _ForwardIter __l,
                              forward_iterator_tag);

public:                         // Other modifier member functions.

    size_type copy(CharT *__s, size_type __n, size_type __pos = 0) const
    {
        NF_ASSERT(__pos <= size());
        const size_type __len = min(__n, size() - __pos);
        Traits::copy(__s, m_data + __pos, __len);
        return __len;
    }

    void swap(NFShmBasicString &__s)
    {
    }

public:                         // Conversion to C string.

    const CharT *c_str() const { return m_data; }

    const CharT *data() const { return m_data; }

public:                         // find.

    size_type find(const NFShmBasicString &__s, size_type __pos = 0) const { return find(__s.begin(), __pos, __s.size()); }

    size_type find(const CharT *__s, size_type __pos = 0) const { return find(__s, __pos, Traits::length(__s)); }

    size_type find(const CharT *__s, size_type __pos, size_type __n) const;

    size_type find(CharT __c, size_type __pos = 0) const;

public:                         // rfind.

    size_type rfind(const NFShmBasicString &__s, size_type __pos = npos) const { return rfind(__s.begin(), __pos, __s.size()); }

    size_type rfind(const CharT *__s, size_type __pos = npos) const { return rfind(__s, __pos, Traits::length(__s)); }

    size_type rfind(const CharT *__s, size_type __pos, size_type __n) const;

    size_type rfind(CharT __c, size_type __pos = npos) const;

public:                         // find_first_of

    size_type find_first_of(const NFShmBasicString &__s, size_type __pos = 0) const { return find_first_of(__s.begin(), __pos, __s.size()); }

    size_type find_first_of(const CharT *__s, size_type __pos = 0) const { return find_first_of(__s, __pos, Traits::length(__s)); }

    size_type find_first_of(const CharT *__s, size_type __pos,
                            size_type __n) const;

    size_type find_first_of(CharT __c, size_type __pos = 0) const { return find(__c, __pos); }

public:                         // find_last_of

    size_type find_last_of(const NFShmBasicString &__s,
                           size_type __pos = npos) const { return find_last_of(__s.begin(), __pos, __s.size()); }

    size_type find_last_of(const CharT *__s, size_type __pos = npos) const { return find_last_of(__s, __pos, Traits::length(__s)); }

    size_type find_last_of(const CharT *__s, size_type __pos,
                           size_type __n) const;

    size_type find_last_of(CharT __c, size_type __pos = npos) const
    {
        return rfind(__c, __pos);
    }

public:                         // find_first_not_of

    size_type find_first_not_of(const NFShmBasicString &__s,
                                size_type __pos = 0) const { return find_first_not_of(__s.begin(), __pos, __s.size()); }

    size_type find_first_not_of(const CharT *__s, size_type __pos = 0) const { return find_first_not_of(__s, __pos, Traits::length(__s)); }

    size_type find_first_not_of(const CharT *__s, size_type __pos,
                                size_type __n) const;

    size_type find_first_not_of(CharT __c, size_type __pos = 0) const;

public:                         // find_last_not_of

    size_type find_last_not_of(const NFShmBasicString &__s,
                               size_type __pos = npos) const { return find_last_not_of(__s.begin(), __pos, __s.size()); }

    size_type find_last_not_of(const CharT *__s, size_type __pos = npos) const { return find_last_not_of(__s, __pos, Traits::length(__s)); }

    size_type find_last_not_of(const CharT *__s, size_type __pos,
                               size_type __n) const;

    size_type find_last_not_of(CharT __c, size_type __pos = npos) const;

public:                         // Substring.

    NFShmBasicString substr(size_type __pos = 0, size_type __n = npos) const
    {
        NF_ASSERT(__pos <= size());
        return NFShmBasicString(m_data + __pos,
                            m_data + __pos + min(__n, size() - __pos));
    }

public:                         // Compare

    int compare(const NFShmBasicString &__s) const { return _M_compare(m_data, m_data + m_size, __s.m_data, __s.m_data + m_size); }

    int compare(size_type __pos1, size_type __n1,
                const NFShmBasicString &__s) const
    {
        NF_ASSERT(__pos1 <= size());
        return _M_compare(m_data + __pos1,
                          m_data + __pos1 + min(__n1, size() - __pos1),
                          __s.m_data, __s.m_data + m_size);
    }

    int compare(size_type __pos1, size_type __n1,
                const NFShmBasicString &__s,
                size_type __pos2, size_type __n2) const
    {
        NF_ASSERT(!(__pos1 > size() || __pos2 > __s.size()));
        return _M_compare(m_data + __pos1,
                          m_data + __pos1 + min(__n1, size() - __pos1),
                          __s.m_data + __pos2,
                          __s.m_data + __pos2 + min(__n2, size() - __pos2));
    }

    int compare(const CharT *__s) const
    {
        return _M_compare(m_data, m_data + m_size, __s, __s + Traits::length(__s));
    }

    int compare(size_type __pos1, size_type __n1, const CharT *__s) const
    {
        NF_ASSERT(__pos1 <= size());
        return _M_compare(m_data + __pos1,
                          m_data + __pos1 + min(__n1, size() - __pos1),
                          __s, __s + Traits::length(__s));
    }

    int compare(size_type __pos1, size_type __n1, const CharT *__s,
                size_type __n2) const
    {
        NF_ASSERT (__pos1 <= size());
        return _M_compare(m_data + __pos1,
                          m_data + __pos1 + min(__n1, size() - __pos1),
                          __s, __s + __n2);
    }

public:                        // Helper function for compare.
    static int _M_compare(const CharT *__f1, const CharT *__l1,
                          const CharT *__f2, const CharT *__l2)
    {
        const ptrdiff_t __n1 = __l1 - __f1;
        const ptrdiff_t __n2 = __l2 - __f2;
        const int cmp = Traits::compare(__f1, __f2, min(__n1, __n2));
        return cmp != 0 ? cmp : (__n1 < __n2 ? -1 : (__n1 > __n2 ? 1 : 0));
    }
};



// ------------------------------------------------------------
// Non-inline declarations.

template<class _CharT, int MAX_SIZE, class _Traits>
const NFShmBasicString<_CharT, MAX_SIZE, _Traits>::size_type
        NFShmBasicString<_CharT, MAX_SIZE, _Traits>::npos
        = (NFShmBasicString<_CharT, MAX_SIZE, _Traits>::size_type) -1;

// Change the string's capacity so that it is large enough to hold
//  at least __res_arg elements, plus the terminating null.  Note that,
//  if __res_arg < capacity(), this member function may actually decrease
//  the string's capacity.
template<class _CharT, int MAX_SIZE, class _Traits>
void NFShmBasicString<_CharT, MAX_SIZE, _Traits>::reserve(size_type __res_arg)
{

}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc> &
NFShmBasicString<_CharT, _Traits, _Alloc>::append(size_type __n, _CharT __c)
{
    if (__n > max_size() || size() > max_size() - __n)
        _M_throw_length_error();
    if (size() + __n > capacity())
        reserve(size() + max(size(), __n));
    if (__n > 0)
    {
        uninitialized_fill_n(m_data + m_size + 1, __n - 1, __c);
        __STL_TRY{
                _M_construct_null(m_data + m_size + __n);
        }
        __STL_UNWIND(destroy(m_data + m_size + 1, m_data + m_size + __n));
        _Traits::assign(*m_data + m_size, __c);
        m_data + m_size += __n;
    }
    return *this;
}

template<class _Tp, int MAX_SIZE, class _Traits, class _Alloc>
template<class _InputIterator>
basic_string<_Tp, _Traits, _Alloc> &
NFShmBasicString<_Tp, _Traits, _Alloc>::append(_InputIterator __first,
                                               _InputIterator __last,
                                               input_iterator_tag)
{
    for (; __first != __last; ++__first)
        push_back(*__first);
    return *this;
}

template<class _Tp, int MAX_SIZE, class _Traits, class _Alloc>
template<class _ForwardIter>
basic_string<_Tp, _Traits, _Alloc> &
NFShmBasicString<_Tp, _Traits, _Alloc>::append(_ForwardIter __first,
                                               _ForwardIter __last,
                                               forward_iterator_tag)
{
    if (__first != __last)
    {
        const size_type __old_size = size();
        difference_type __n = 0;
        distance(__first, __last, __n);
        if (static_cast<size_type>(__n) > max_size() ||
            __old_size > max_size() - static_cast<size_type>(__n))
            _M_throw_length_error();
        if (__old_size + static_cast<size_type>(__n) > capacity())
        {
            const size_type __len = __old_size +
                                    max(__old_size, static_cast<size_type>(__n)) + 1;
            pointer __new_start = _M_allocate(__len);
            pointer __new_finish = __new_start;
            __STL_TRY{
                    __new_finish = uninitialized_copy(m_data, m_data + m_size, __new_start);
                    __new_finish = uninitialized_copy(__first, __last, __new_finish);
                    _M_construct_null(__new_finish);
            }
            __STL_UNWIND((destroy(__new_start, __new_finish),
                    _M_deallocate(__new_start, __len)));
            destroy(m_data, m_data + m_size + 1);
            _M_deallocate_block();
            m_data = __new_start;
            m_data + m_size = __new_finish;
            m_data + MAX_SIZE = __new_start + __len;
        }
        else
        {
            _ForwardIter __f1 = __first;
            ++__f1;
            uninitialized_copy(__f1, __last, m_data + m_size + 1);
            __STL_TRY{
                    _M_construct_null(m_data + m_size + __n);
            }
            __STL_UNWIND(destroy(m_data + m_size + 1, m_data + m_size + __n));
            _Traits::assign(*m_data + m_size, *__first);
            m_data + m_size += __n;
        }
    }
    return *this;
}


template<class _Tp, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_Tp, _Traits, _Alloc> &
NFShmBasicString<_Tp, _Traits, _Alloc>::append(const _Tp *__first,
                                               const _Tp *__last)
{
    if (__first != __last)
    {
        const size_type __old_size = size();
        ptrdiff_t __n = __last - __first;
        if (__n > max_size() || __old_size > max_size() - __n)
            _M_throw_length_error();
        if (__old_size + __n > capacity())
        {
            const size_type __len = __old_size + max(__old_size, (size_t) __n) + 1;
            pointer __new_start = _M_allocate(__len);
            pointer __new_finish = __new_start;
            __STL_TRY{
                    __new_finish = uninitialized_copy(m_data, m_data + m_size, __new_start);
                    __new_finish = uninitialized_copy(__first, __last, __new_finish);
                    _M_construct_null(__new_finish);
            }
            __STL_UNWIND((destroy(__new_start, __new_finish),
                    _M_deallocate(__new_start, __len)));
            destroy(m_data, m_data + m_size + 1);
            _M_deallocate_block();
            m_data = __new_start;
            m_data + m_size = __new_finish;
            m_data + MAX_SIZE = __new_start + __len;
        }
        else
        {
            const _Tp *__f1 = __first;
            ++__f1;
            uninitialized_copy(__f1, __last, m_data + m_size + 1);
            __STL_TRY{
                    _M_construct_null(m_data + m_size + __n);
            }
            __STL_UNWIND(destroy(m_data + m_size + 1, m_data + m_size + __n));
            _Traits::assign(*m_data + m_size, *__first);
            m_data + m_size += __n;
        }
    }
    return *this;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc> &
NFShmBasicString<_CharT, _Traits, _Alloc>::assign(size_type __n, _CharT __c)
{
    if (__n <= size())
    {
        _Traits::assign(m_data, __n, __c);
        erase(m_data + __n, m_data + m_size);
    }
    else
    {
        _Traits::assign(m_data, size(), __c);
        append(__n - size(), __c);
    }
    return *this;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
template<class _InputIter>
basic_string<_CharT, _Traits, _Alloc> &NFShmBasicString<_CharT, _Traits, _Alloc>
::_M_assign_dispatch(_InputIter __f, _InputIter __l, __false_type)
{
    pointer __cur = m_data;
    while (__f != __l && __cur != m_data + m_size)
    {
        _Traits::assign(*__cur, *__f);
        ++__f;
        ++__cur;
    }
    if (__f == __l)
        erase(__cur, m_data + m_size);
    else
        append(__f, __l);
    return *this;
}


template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc> &
NFShmBasicString<_CharT, _Traits, _Alloc>::assign(const _CharT *__f,
                                                  const _CharT *__l)
{
    const ptrdiff_t __n = __l - __f;
    if (static_cast<size_type>(__n) <= size())
    {
        _Traits::copy(m_data, __f, __n);
        erase(m_data + __n, m_data + m_size);
    }
    else
    {
        _Traits::copy(m_data, __f, size());
        append(__f + size(), __l);
    }
    return *this;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc>::iterator
NFShmBasicString<_CharT, _Traits, _Alloc>
::_M_insert_aux(basic_string<_CharT, _Traits, _Alloc>::iterator __p,
                _CharT __c)
{
    iterator __new_pos = __p;
    if (m_data + m_size + 1 < m_data + MAX_SIZE)
    {
        _M_construct_null(m_data + m_size + 1);
        _Traits::move(__p + 1, __p, m_data + m_size - __p);
        _Traits::assign(*__p, __c);
        ++m_data + m_size;
    }
    else
    {
        const size_type __old_len = size();
        const size_type __len = __old_len +
                                max(__old_len, static_cast<size_type>(1)) + 1;
        iterator __new_start = _M_allocate(__len);
        iterator __new_finish = __new_start;
        __STL_TRY{
                __new_pos = uninitialized_copy(m_data, __p, __new_start);
                construct(__new_pos, __c);
                __new_finish = __new_pos + 1;
                __new_finish = uninitialized_copy(__p, m_data+m_size, __new_finish);
                _M_construct_null(__new_finish);
        }
        __STL_UNWIND((destroy(__new_start, __new_finish),
                _M_deallocate(__new_start, __len)));
        destroy(m_data, m_data + m_size + 1);
        _M_deallocate_block();
        m_data = __new_start;
        m_data + m_size = __new_finish;
        m_data + MAX_SIZE = __new_start + __len;
    }
    return __new_pos;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
void NFShmBasicString<_CharT, _Traits, _Alloc>
::insert(basic_string<_CharT, _Traits, _Alloc>::iterator __position,
         size_t __n, _CharT __c)
{
    if (__n != 0)
    {
        if (size_type(m_data + MAX_SIZE - m_data + m_size) >= __n + 1)
        {
            const size_type __elems_after = m_data + m_size - __position;
            iterator __old_finish = m_data + m_size;
            if (__elems_after >= __n)
            {
                uninitialized_copy((m_data + m_size - __n) + 1, m_data + m_size + 1,
                                   m_data + m_size + 1);
                m_data + m_size += __n;
                _Traits::move(__position + __n,
                              __position, (__elems_after - __n) + 1);
                _Traits::assign(__position, __n, __c);
            }
            else
            {
                uninitialized_fill_n(m_data + m_size + 1, __n - __elems_after - 1, __c);
                m_data + m_size += __n - __elems_after;
                __STL_TRY{
                        uninitialized_copy(__position, __old_finish + 1, m_data + m_size);
                        m_data+m_size += __elems_after;
                }
                __STL_UNWIND((destroy(__old_finish + 1, m_data + m_size),
                        m_data + m_size = __old_finish));
                _Traits::assign(__position, __elems_after + 1, __c);
            }
        }
        else
        {
            const size_type __old_size = size();
            const size_type __len = __old_size + max(__old_size, __n) + 1;
            iterator __new_start = _M_allocate(__len);
            iterator __new_finish = __new_start;
            __STL_TRY{
                    __new_finish = uninitialized_copy(m_data, __position, __new_start);
                    __new_finish = uninitialized_fill_n(__new_finish, __n, __c);
                    __new_finish = uninitialized_copy(__position, m_data+m_size,
                    __new_finish);
                    _M_construct_null(__new_finish);
            }
            __STL_UNWIND((destroy(__new_start, __new_finish),
                    _M_deallocate(__new_start, __len)));
            destroy(m_data, m_data + m_size + 1);
            _M_deallocate_block();
            m_data = __new_start;
            m_data + m_size = __new_finish;
            m_data + MAX_SIZE = __new_start + __len;
        }
    }
}

template<class _Tp, int MAX_SIZE, class _Traits, class _Alloc>
template<class _InputIter>
void NFShmBasicString<_Tp, _Traits, _Alloc>::insert(iterator __p,
                                                    _InputIter __first,
                                                    _InputIter __last,
                                                    input_iterator_tag)
{
    for (; __first != __last; ++__first)
    {
        __p = insert(__p, *__first);
        ++__p;
    }
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
template<class _ForwardIter>
void
NFShmBasicString<_CharT, _Traits, _Alloc>::insert(iterator __position,
                                                  _ForwardIter __first,
                                                  _ForwardIter __last,
                                                  forward_iterator_tag)
{
    if (__first != __last)
    {
        difference_type __n = 0;
        distance(__first, __last, __n);
        if (m_data + MAX_SIZE - m_data + m_size >= __n + 1)
        {
            const difference_type __elems_after = m_data + m_size - __position;
            iterator __old_finish = m_data + m_size;
            if (__elems_after >= __n)
            {
                uninitialized_copy((m_data + m_size - __n) + 1, m_data + m_size + 1,
                                   m_data + m_size + 1);
                m_data + m_size += __n;
                _Traits::move(__position + __n,
                              __position, (__elems_after - __n) + 1);
                _M_copy(__first, __last, __position);
            }
            else
            {
                _ForwardIter __mid = __first;
                advance(__mid, __elems_after + 1);
                uninitialized_copy(__mid, __last, m_data + m_size + 1);
                m_data + m_size += __n - __elems_after;
                __STL_TRY{
                        uninitialized_copy(__position, __old_finish + 1, m_data + m_size);
                        m_data+m_size += __elems_after;
                }
                __STL_UNWIND((destroy(__old_finish + 1, m_data + m_size),
                        m_data + m_size = __old_finish));
                _M_copy(__first, __mid, __position);
            }
        }
        else
        {
            const size_type __old_size = size();
            const size_type __len
                    = __old_size + max(__old_size, static_cast<size_type>(__n)) + 1;
            pointer __new_start = _M_allocate(__len);
            pointer __new_finish = __new_start;
            __STL_TRY{
                    __new_finish = uninitialized_copy(m_data, __position, __new_start);
                    __new_finish = uninitialized_copy(__first, __last, __new_finish);
                    __new_finish
                    = uninitialized_copy(__position, m_data+m_size, __new_finish);
                    _M_construct_null(__new_finish);
            }
            __STL_UNWIND((destroy(__new_start, __new_finish),
                    _M_deallocate(__new_start, __len)));
            destroy(m_data, m_data + m_size + 1);
            _M_deallocate_block();
            m_data = __new_start;
            m_data + m_size = __new_finish;
            m_data + MAX_SIZE = __new_start + __len;
        }
    }
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
void
NFShmBasicString<_CharT, _Traits, _Alloc>::insert(iterator __position,
                                                  const _CharT *__first,
                                                  const _CharT *__last)
{
    if (__first != __last)
    {
        const ptrdiff_t __n = __last - __first;
        if (m_data + MAX_SIZE - m_data + m_size >= __n + 1)
        {
            const ptrdiff_t __elems_after = m_data + m_size - __position;
            iterator __old_finish = m_data + m_size;
            if (__elems_after >= __n)
            {
                uninitialized_copy((m_data + m_size - __n) + 1, m_data + m_size + 1,
                                   m_data + m_size + 1);
                m_data + m_size += __n;
                _Traits::move(__position + __n,
                              __position, (__elems_after - __n) + 1);
                _M_copy(__first, __last, __position);
            }
            else
            {
                const _CharT *__mid = __first;
                advance(__mid, __elems_after + 1);
                uninitialized_copy(__mid, __last, m_data + m_size + 1);
                m_data + m_size += __n - __elems_after;
                __STL_TRY{
                        uninitialized_copy(__position, __old_finish + 1, m_data + m_size);
                        m_data+m_size += __elems_after;
                }
                __STL_UNWIND((destroy(__old_finish + 1, m_data + m_size),
                        m_data + m_size = __old_finish));
                _M_copy(__first, __mid, __position);
            }
        }
        else
        {
            const size_type __old_size = size();
            const size_type __len
                    = __old_size + max(__old_size, static_cast<size_type>(__n)) + 1;
            pointer __new_start = _M_allocate(__len);
            pointer __new_finish = __new_start;
            __STL_TRY{
                    __new_finish = uninitialized_copy(m_data, __position, __new_start);
                    __new_finish = uninitialized_copy(__first, __last, __new_finish);
                    __new_finish
                    = uninitialized_copy(__position, m_data+m_size, __new_finish);
                    _M_construct_null(__new_finish);
            }
            __STL_UNWIND((destroy(__new_start, __new_finish),
                    _M_deallocate(__new_start, __len)));
            destroy(m_data, m_data + m_size + 1);
            _M_deallocate_block();
            m_data = __new_start;
            m_data + m_size = __new_finish;
            m_data + MAX_SIZE = __new_start + __len;
        }
    }
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc> &
NFShmBasicString<_CharT, _Traits, _Alloc>
::replace(iterator __first, iterator __last, size_type __n, _CharT __c)
{
    const size_type __len = static_cast<size_type>(__last - __first);
    if (__len >= __n)
    {
        _Traits::assign(__first, __n, __c);
        erase(__first + __n, __last);
    }
    else
    {
        _Traits::assign(__first, __len, __c);
        insert(__last, __n - __len, __c);
    }
    return *this;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
template<class _InputIter>
basic_string<_CharT, _Traits, _Alloc> &
NFShmBasicString<_CharT, _Traits, _Alloc>
::replace(iterator __first, iterator __last, _InputIter __f, _InputIter __l,
          input_iterator_tag)
{
    for (; __first != __last && __f != __l; ++__first, ++__f)
        _Traits::assign(*__first, *__f);

    if (__f == __l)
        erase(__first, __last);
    else
        insert(__last, __f, __l);
    return *this;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
template<class _ForwardIter>
basic_string<_CharT, _Traits, _Alloc> &
NFShmBasicString<_CharT, _Traits, _Alloc>
::replace(iterator __first, iterator __last,
          _ForwardIter __f, _ForwardIter __l,
          forward_iterator_tag)
{
    difference_type __n = 0;
    distance(__f, __l, __n);
    const difference_type __len = __last - __first;
    if (__len >= __n)
    {
        _M_copy(__f, __l, __first);
        erase(__first + __n, __last);
    }
    else
    {
        _ForwardIter __m = __f;
        advance(__m, __len);
        _M_copy(__f, __m, __first);
        insert(__last, __m, __l);
    }
    return *this;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc> &
NFShmBasicString<_CharT, _Traits, _Alloc>
::replace(iterator __first, iterator __last,
          const _CharT *__f, const _CharT *__l)
{
    const ptrdiff_t __n = __l - __f;
    const difference_type __len = __last - __first;
    if (__len >= __n)
    {
        _M_copy(__f, __l, __first);
        erase(__first + __n, __last);
    }
    else
    {
        const _CharT *__m = __f + __len;
        _M_copy(__f, __m, __first);
        insert(__last, __m, __l);
    }
    return *this;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc>::size_type
NFShmBasicString<_CharT, _Traits, _Alloc>
::find(const _CharT *__s, size_type __pos, size_type __n) const
{
    if (__pos + __n > size())
        return npos;
    else
    {
        const const_iterator __result =
                search(m_data + __pos, m_data + m_size,
                       __s, __s + __n, _Eq_traits<_Traits>());
        return __result != m_data + m_size ? __result - begin() : npos;
    }
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc>::size_type
NFShmBasicString<_CharT, _Traits, _Alloc>
::find(_CharT __c, size_type __pos) const
{
    if (__pos >= size())
        return npos;
    else
    {
        const const_iterator __result =
                find_if(m_data + __pos, m_data + m_size,
                        bind2nd(_Eq_traits<_Traits>(), __c));
        return __result != m_data + m_size ? __result - begin() : npos;
    }
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc>::size_type
NFShmBasicString<_CharT, _Traits, _Alloc>
::rfind(const _CharT *__s, size_type __pos, size_type __n) const
{
    const size_t __len = size();

    if (__n > __len)
        return npos;
    else if (__n == 0)
        return min(__len, __pos);
    else
    {
        const const_iterator __last = begin() + min(__len - __n, __pos) + __n;
        const const_iterator __result = find_end(begin(), __last,
                                                 __s, __s + __n,
                                                 _Eq_traits<_Traits>());
        return __result != __last ? __result - begin() : npos;
    }
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc>::size_type
NFShmBasicString<_CharT, _Traits, _Alloc>
::rfind(_CharT __c, size_type __pos) const
{
    const size_type __len = size();

    if (__len < 1)
        return npos;
    else
    {
        const const_iterator __last = begin() + min(__len - 1, __pos) + 1;
        const_reverse_iterator __rresult =
                find_if(const_reverse_iterator(__last), rend(),
                        bind2nd(_Eq_traits<_Traits>(), __c));
        return __rresult != rend() ? (__rresult.base() - 1) - begin() : npos;
    }
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc>::size_type
NFShmBasicString<_CharT, _Traits, _Alloc>
::find_first_of(const _CharT *__s, size_type __pos, size_type __n) const
{
    if (__pos >= size())
        return npos;
    else
    {
        const_iterator __result = __STD::find_first_of(begin() + __pos, end(),
                                                       __s, __s + __n,
                                                       _Eq_traits<_Traits>());
        return __result != m_data + m_size ? __result - begin() : npos;
    }
}


template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc>::size_type
NFShmBasicString<_CharT, _Traits, _Alloc>
::find_last_of(const _CharT *__s, size_type __pos, size_type __n) const
{
    const size_type __len = size();

    if (__len < 1)
        return npos;
    else
    {
        const const_iterator __last = m_data + min(__len - 1, __pos) + 1;
        const const_reverse_iterator __rresult =
                __STD::find_first_of(const_reverse_iterator(__last), rend(),
                                     __s, __s + __n,
                                     _Eq_traits<_Traits>());
        return __rresult != rend() ? (__rresult.base() - 1) - m_data : npos;
    }
}


template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc>::size_type
NFShmBasicString<_CharT, _Traits, _Alloc>
::find_first_not_of(const _CharT *__s, size_type __pos, size_type __n) const
{
    if (__pos > size())
        return npos;
    else
    {
        const_iterator __result = find_if(m_data + __pos, m_data + m_size,
                                          _Not_within_traits<_Traits>(__s, __s + __n));
        return __result != m_data + m_size ? __result - m_data : npos;
    }
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc>::size_type
NFShmBasicString<_CharT, _Traits, _Alloc>
::find_first_not_of(_CharT __c, size_type __pos) const
{
    if (__pos > size())
        return npos;
    else
    {
        const_iterator __result
                = find_if(begin() + __pos, end(),
                          not1(bind2nd(_Eq_traits<_Traits>(), __c)));
        return __result != m_data + m_size ? __result - begin() : npos;
    }
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_CharT, _Traits, _Alloc>::size_type
NFShmBasicString<_CharT, _Traits, _Alloc>
::find_last_not_of(const _CharT *__s, size_type __pos, size_type __n) const
{

    const size_type __len = size();

    if (__len < 1)
        return npos;
    else
    {
        const const_iterator __last = begin() + min(__len - 1, __pos) + 1;
        const const_reverse_iterator __rresult =
                find_if(const_reverse_iterator(__last), rend(),
                        _Not_within_traits<_Traits>(__s, __s + __n));
        return __rresult != rend() ? (__rresult.base() - 1) - begin() : npos;
    }
}

template<class _Tp, int MAX_SIZE, class _Traits, class _Alloc>
basic_string<_Tp, _Traits, _Alloc>::size_type
NFShmBasicString<_Tp, _Traits, _Alloc>
::find_last_not_of(_Tp __c, size_type __pos) const
{
    const size_type __len = size();

    if (__len < 1)
        return npos;
    else
    {
        const const_iterator __last = begin() + min(__len - 1, __pos) + 1;
        const_reverse_iterator __rresult =
                find_if(const_reverse_iterator(__last), rend(),
                        not1(bind2nd(_Eq_traits<_Traits>(), __c)));
        return __rresult != rend() ? (__rresult.base() - 1) - begin() : npos;
    }
}

// ------------------------------------------------------------
// Non-member functions.

// Operator+

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
inline basic_string<_CharT, _Traits, _Alloc>
operator+(const basic_string<_CharT, _Traits, _Alloc> &__x,
          const basic_string<_CharT, _Traits, _Alloc> &__y)
{
    typedef basic_string<_CharT, _Traits, _Alloc> _Str;
    typedef typename _Str::_Reserve_t _Reserve_t;
    _Reserve_t __reserve;
    _Str __result(__reserve, __x.size() + __y.size(), __x.get_allocator());
    __result.append(__x);
    __result.append(__y);
    return __result;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
inline basic_string<_CharT, _Traits, _Alloc>
operator+(const _CharT *__s,
          const basic_string<_CharT, _Traits, _Alloc> &__y)
{
    typedef basic_string<_CharT, _Traits, _Alloc> _Str;
    typedef typename _Str::_Reserve_t _Reserve_t;
    _Reserve_t __reserve;
    const size_t __n = _Traits::length(__s);
    _Str __result(__reserve, __n + __y.size());
    __result.append(__s, __s + __n);
    __result.append(__y);
    return __result;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
inline basic_string<_CharT, _Traits, _Alloc>
operator+(_CharT __c,
          const basic_string<_CharT, _Traits, _Alloc> &__y)
{
    typedef basic_string<_CharT, _Traits, _Alloc> _Str;
    typedef typename _Str::_Reserve_t _Reserve_t;
    _Reserve_t __reserve;
    _Str __result(__reserve, 1 + __y.size());
    __result.push_back(__c);
    __result.append(__y);
    return __result;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
inline basic_string<_CharT, _Traits, _Alloc>
operator+(const basic_string<_CharT, _Traits, _Alloc> &__x,
          const _CharT *__s)
{
    typedef basic_string<_CharT, _Traits, _Alloc> _Str;
    typedef typename _Str::_Reserve_t _Reserve_t;
    _Reserve_t __reserve;
    const size_t __n = _Traits::length(__s);
    _Str __result(__reserve, __x.size() + __n, __x.get_allocator());
    __result.append(__x);
    __result.append(__s, __s + __n);
    return __result;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
inline basic_string<_CharT, _Traits, _Alloc>
operator+(const basic_string<_CharT, _Traits, _Alloc> &__x,
          const _CharT __c)
{
    typedef basic_string<_CharT, _Traits, _Alloc> _Str;
    typedef typename _Str::_Reserve_t _Reserve_t;
    _Reserve_t __reserve;
    _Str __result(__reserve, __x.size() + 1, __x.get_allocator());
    __result.append(__x);
    __result.push_back(__c);
    return __result;
}

// Operator== and operator!=

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
inline bool
operator==(const basic_string<_CharT, _Traits, _Alloc> &__x,
           const basic_string<_CharT, _Traits, _Alloc> &__y)
{
    return __x.size() == __y.size() &&
           _Traits::compare(__x.data(), __y.data(), __x.size()) == 0;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
inline bool
operator==(const _CharT *__s,
           const basic_string<_CharT, _Traits, _Alloc> &__y)
{
    size_t __n = _Traits::length(__s);
    return __n == __y.size() && _Traits::compare(__s, __y.data(), __n) == 0;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
inline bool
operator==(const basic_string<_CharT, _Traits, _Alloc> &__x,
           const _CharT *__s)
{
    size_t __n = _Traits::length(__s);
    return __x.size() == __n && _Traits::compare(__x.data(), __s, __n) == 0;
}

template<class _CharT, int MAX_SIZE, int MAX_SIZE, class _Traits, class _Alloc>
inline bool
operator<(const basic_string<_CharT, _Traits, _Alloc> &__x,
          const basic_string<_CharT, _Traits, _Alloc> &__y)
{
    return NFShmBasicString<_CharT, _Traits, _Alloc>
           ::_M_compare(__x.begin(), __x.end(), __y.begin(), __y.end()) < 0;
}

template<class _CharT, int MAX_SIZE, int MAX_SIZE, class _Traits, class _Alloc>
inline bool
operator<(const _CharT *__s,
          const basic_string<_CharT, _Traits, _Alloc> &__y)
{
    size_t __n = _Traits::length(__s);
    return NFShmBasicString<_CharT, _Traits, _Alloc>
           ::_M_compare(__s, __s + __n, __y.begin(), __y.end()) < 0;
}

template<class _CharT, int MAX_SIZE, int MAX_SIZE, class _Traits, class _Alloc>
inline bool
operator<(const basic_string<_CharT, _Traits, _Alloc> &__x,
          const _CharT *__s)
{
    size_t __n = _Traits::length(__s);
    return NFShmBasicString<_CharT, _Traits, _Alloc>
           ::_M_compare(__x.begin(), __x.end(), __s, __s + __n) < 0;
}

#include <iostream>

template <class _CharT, int MAX_SIZE, class _Traits>
inline bool
__sgi_string_fill(basic_ostream<_CharT, _Traits>& __os,
                  basic_streambuf<_CharT, _Traits>* __buf,
                  size_t __n)
{
  _CharT __f = __os.fill();
  size_t __i;
  bool __ok = true;

  for (__i = 0; __i < __n; __i++)
    __ok = __ok && !_Traits::eq_int_type(__buf->sputc(__f), _Traits::eof());
  return __ok;
}

template <class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_ostream<_CharT, _Traits>&
operator<<(basic_ostream<_CharT, _Traits>& __os,
           const basic_string<_CharT,_Traits,_Alloc>& __s)
{
  typename basic_ostream<_CharT, _Traits>::sentry __sentry(__os);
  bool __ok = false;

  if (__sentry) {
    __ok = true;
    size_t __n = __s.size();
    size_t __pad_len = 0;
    const bool __left = (__os.flags() & ios::left) != 0;
    const size_t __w = __os.width(0);
    basic_streambuf<_CharT, _Traits>* __buf = __os.rdbuf();

    if (__w != 0 && __n < __w)
      __pad_len = __w - __n;

    if (!__left)
      __ok = __sgi_string_fill(__os, __buf, __pad_len);

    __ok = __ok &&
           __buf->sputn(__s.data(), streamsize(__n)) == streamsize(__n);

    if (__left)
      __ok = __ok && __sgi_string_fill(__os, __buf, __pad_len);
  }

  if (!__ok)
    __os.setstate(ios_base::failbit);

  return __os;
}

template <class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_istream<_CharT, _Traits>&
operator>>(basic_istream<_CharT, _Traits>& __is,
           basic_string<_CharT,_Traits,_Alloc>& __s)
{
  typename basic_istream<_CharT, _Traits>::sentry __sentry(__is);

  if (__sentry) {
    basic_streambuf<_CharT, _Traits>* __buf = __is.rdbuf();
    const ctype<_CharT>& __ctype = use_facet<ctype<_CharT> >(__is.getloc());

    __s.clear();
    size_t __n = __is.width(0);
    if (__n == 0)
      __n = static_cast<size_t>(-1);
    else
      __s.reserve(__n);


    while (__n-- > 0) {
      typename _Traits::int_type __c1 = __buf->sbumpc();
      if (_Traits::eq_int_type(__c1, _Traits::eof())) {
        __is.setstate(ios_base::eofbit);
        break;
      }
      else {
        _CharT __c = _Traits::to_char_type(__c1);

        if (__ctype.is(ctype<_CharT>::space, __c)) {
          if (_Traits::eq_int_type(__buf->sputbackc(__c), _Traits::eof()))
            __is.setstate(ios_base::failbit);
          break;
        }
        else
          __s.push_back(__c);
      }
    }

    // If we have read no characters, then set failbit.
    if (__s.size() == 0)
      __is.setstate(ios_base::failbit);
  }
  else
    __is.setstate(ios_base::failbit);

  return __is;
}

template <class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
basic_istream<_CharT, _Traits>&
getline(istream& __is,
        basic_string<_CharT,_Traits,_Alloc>& __s,
        _CharT __delim)
{
  size_t __nread = 0;
  typename basic_istream<_CharT, _Traits>::sentry __sentry(__is, true);
  if (__sentry) {
    basic_streambuf<_CharT, _Traits>* __buf = __is.rdbuf();
    __s.clear();

    int __c1;
    while (__nread < __s.max_size()) {
      int __c1 = __buf->sbumpc();
      if (_Traits::eq_int_type(__c1, _Traits::eof())) {
        __is.setstate(ios_base::eofbit);
        break;
      }
      else {
        ++__nread;
        _CharT __c = _Traits::to_char_type(__c1);
        if (!_Traits::eq(__c, __delim))
          __s.push_back(__c);
        else
          break;              // Character is extracted but not appended.
      }
    }
  }
  if (__nread == 0 || __nread >= __s.max_size())
    __is.setstate(ios_base::failbit);

  return __is;
}

template <class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
inline basic_istream<_CharT, _Traits>&
getline(basic_istream<_CharT, _Traits>& __is,
        basic_string<_CharT,_Traits,_Alloc>& __s)
{
  return getline(__is, __s, '\n');
}

inline void __sgi_string_fill(ostream &__os, streambuf *__buf, size_t __n)
{
    char __f = __os.fill();
    size_t __i;

    for (__i = 0; __i < __n; __i++) __buf->sputc(__f);
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
ostream &operator<<(ostream &__os,
                    const basic_string<_CharT, _Traits, _Alloc> &__s)
{
    streambuf *__buf = __os.rdbuf();
    if (__buf)
    {
        size_t __n = __s.size();
        size_t __pad_len = 0;
        const bool __left = (__os.flags() & ios::left) != 0;
        const size_t __w = __os.width();

        if (__w > 0)
        {
            __n = min(__w, __n);
            __pad_len = __w - __n;
        }

        if (!__left)
            __sgi_string_fill(__os, __buf, __pad_len);

        const size_t __nwritten = __buf->sputn(__s.data(), __n);

        if (__left)
            __sgi_string_fill(__os, __buf, __pad_len);

        if (__nwritten != __n)
            __os.clear(__os.rdstate() | ios::failbit);

        __os.width(0);
    }
    else
        __os.clear(__os.rdstate() | ios::badbit);

    return __os;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
istream &operator>>(istream &__is, basic_string<_CharT, _Traits, _Alloc> &__s)
{
    if (!__is)
        return __is;

    streambuf *__buf = __is.rdbuf();
    if (__buf)
    {

#ifdef __USLC__
        /* Jochen Schlick '1999  - operator >> modified. Work-around to get the
 *                         output buffer flushed (necessary when using
 *                         "cout" (without endl or flushing) followed by
 *                         "cin >>" ...)
 */
    if (__is.flags() & ios::skipws) {
      _CharT __c;
      do
         __is.get(__c);
      while (__is && isspace(__c));
      if (__is)
         __is.putback(__c);
    }
#else
        if (__is.flags() & ios::skipws)
        {
            int __c;
            do
            {
                __c = __buf->sbumpc();
            } while (__c != EOF && isspace((unsigned char) __c));

            if (__c == EOF)
            {
                __is.clear(__is.rdstate() | ios::eofbit | ios::failbit);
            }
            else
            {
                if (__buf->sputbackc(__c) == EOF)
                    __is.clear(__is.rdstate() | ios::failbit);
            }
        }
#endif

        // If we arrive at end of file (or fail for some other reason) while
        // still discarding whitespace, then we don't try to read the string.
        if (__is)
        {
            __s.clear();

            size_t __n = __is.width();
            if (__n == 0)
                __n = static_cast<size_t>(-1);
            else
                __s.reserve(__n);

            while (__n-- > 0)
            {
                int __c1 = __buf->sbumpc();
                if (__c1 == EOF)
                {
                    __is.clear(__is.rdstate() | ios::eofbit);
                    break;
                }
                else
                {
                    _CharT __c = _Traits::to_char_type(__c1);

                    if (isspace((unsigned char) __c))
                    {
                        if (__buf->sputbackc(__c) == EOF)
                            __is.clear(__is.rdstate() | ios::failbit);
                        break;
                    }
                    else
                        __s.push_back(__c);
                }
            }

            // If we have read no characters, then set failbit.
            if (__s.size() == 0)
                __is.clear(__is.rdstate() | ios::failbit);
        }

        __is.width(0);
    }
    else                          // We have no streambuf.
        __is.clear(__is.rdstate() | ios::badbit);

    return __is;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
istream &getline(istream &__is,
                 basic_string<_CharT, _Traits, _Alloc> &__s,
                 _CharT __delim)
{
    streambuf *__buf = __is.rdbuf();
    if (__buf)
    {
        size_t __nread = 0;
        if (__is)
        {
            __s.clear();

            while (__nread < __s.max_size())
            {
                int __c1 = __buf->sbumpc();
                if (__c1 == EOF)
                {
                    __is.clear(__is.rdstate() | ios::eofbit);
                    break;
                }
                else
                {
                    ++__nread;
                    _CharT __c = _Traits::to_char_type(__c1);
                    if (!_Traits::eq(__c, __delim))
                        __s.push_back(__c);
                    else
                        break;              // Character is extracted but not appended.
                }
            }
        }

        if (__nread == 0 || __nread >= __s.max_size())
            __is.clear(__is.rdstate() | ios::failbit);
    }
    else
        __is.clear(__is.rdstate() | ios::badbit);

    return __is;
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
inline istream &
getline(istream &__is, basic_string<_CharT, _Traits, _Alloc> &__s)
{
    return getline(__is, __s, '\n');
}

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
void _S_string_copy(const basic_string<_CharT, _Traits, _Alloc> &__s,
                    _CharT *__buf,
                    size_t __n)
{
    if (__n > 0)
    {
        __n = min(__n - 1, __s.size());
        copy(__s.begin(), __s.begin() + __n, __buf);
        _Traits::assign(__buf[__n],
                        NFShmBasicString<_CharT, _Traits, _Alloc>::_M_null());
    }
}

inline const char *__get_c_string(const string &__s) { return __s.c_str(); }

template<class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
size_t __stl_string_hash(const basic_string<_CharT, _Traits, _Alloc> &__s)
{
    unsigned long __h = 0;
    for (NFShmBasicString<_CharT, _Traits, _Alloc>::const_iterator __i = __s.begin();
         __i != __s.end();
         ++__i)
        __h = 5 * __h + *__i;
    return size_t(__h);
}

template <class _CharT, int MAX_SIZE, class _Traits, class _Alloc>
struct hash<basic_string<_CharT,_Traits,_Alloc> > {
  size_t operator()(const basic_string<_CharT,_Traits,_Alloc>& __s) const
    { return __stl_string_hash(__s); }
};

