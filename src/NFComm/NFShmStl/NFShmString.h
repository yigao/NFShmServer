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
        memset(m_data, 0, sizeof(Tp) * (MAX_SIZE + 1));
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


template<int MAX_SIZE, class CharT = char, class Traits = std::char_traits<CharT>>
class NFShmString : private NFShmStringBase<CharT, MAX_SIZE>
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
    explicit NFShmString()
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

    NFShmString(const NFShmString &__s)
    {
        _M_range_initialize(__s.begin(), __s.end());
    }

    template<int MAX_SIZE2>
    NFShmString(const NFShmString<MAX_SIZE2> &__s)
    {
        _M_range_initialize(__s.begin(), __s.end());
    }

    NFShmString(const std::basic_string<CharT, Traits> &__s)
    {
        _M_range_initialize(__s.begin(), __s.end());
    }

    NFShmString(const NFShmString &__s, size_type __pos, size_type __n = npos)
    {
        if (__pos <= __s.size())
        {
            _M_range_initialize(__s.begin() + __pos,
                                __s.begin() + __pos + std::min(__n, __s.size() - __pos));
        }
    }

    NFShmString(const std::basic_string<CharT, Traits> &__s, size_type __pos, size_type __n = npos)
    {
        if (__pos <= __s.size())
        {
            _M_range_initialize(__s.begin() + __pos,
                                __s.begin() + __pos + std::min(__n, __s.size() - __pos));
        }
    }

    NFShmString(const CharT *__s, size_type __n) { _M_range_initialize(__s, __s + __n); }

    NFShmString(const CharT *__s) { _M_range_initialize(__s, __s + Traits::length(__s)); }

    NFShmString(size_type __n, CharT __c)
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
    NFShmString(_InputIterator __f, _InputIterator __l)
    {
        typedef typename std::__is_integer<_InputIterator>::__type _Integral;
        _M_initialize_dispatch(__f, __l, _Integral());
    }

    NFShmString(const CharT *__f, const CharT *__l)
    {
        _M_range_initialize(__f, __l);
    }

    ~NFShmString()
    {

    }

    NFShmString &operator=(const NFShmString &__s)
    {
        if (&__s != this)
            assign(__s.begin(), __s.end());
        return *this;
    }

    template<int MAX_SIZE2>
    NFShmString &operator=(const NFShmString<MAX_SIZE2> &__s)
    {
        assign(__s.begin(), __s.end());
        return *this;
    }

    NFShmString &operator=(const std::basic_string<CharT, Traits> &__s)
    {
        assign(__s.begin(), __s.end());
        return *this;
    }

    NFShmString &operator=(const CharT *__s) { return assign(__s, __s + Traits::length(__s)); }

    NFShmString &operator=(CharT __c) { return assign(static_cast<size_type>(1), __c); }

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
        typedef typename std::iterator_traits<_InputIter>::iterator_category _Category;
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
        auto finish = std::uninitialized_copy_n(__f, __n, m_data);
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

    void reserve(size_type = 0);

    size_type capacity() const { return MAX_SIZE; }

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

public:                         // Other modifier member functions.

    size_type copy(CharT *__s, size_type __n, size_type __pos = 0) const
    {
        NF_ASSERT(__pos <= size());
        const size_type __len = min(__n, size() - __pos);
        Traits::copy(__s, m_data + __pos, __len);
        return __len;
    }

    void swap(NFShmString &__s)
    {
    }

public:                         // Conversion to C string.

    const CharT *c_str() const { return m_data; }

    const CharT *data() const { return m_data; }

    std::basic_string<CharT, Traits> GetString() const
    {
        return std::basic_string<CharT, Traits>(begin(), end());
    }

    std::basic_string<CharT, Traits> ToString() const
    {
        return GetString();
    }

public:                         // Append, operator+=, push_back.

    NFShmString &operator+=(const NFShmString &__s) { return append(__s); }

    template<int MAX_SIZE2>
    NFShmString &operator+=(const NFShmString<MAX_SIZE2> &__s) { return append(__s.begin(), __s.end()); }

    NFShmString &operator+=(const std::basic_string<CharT, Traits> &__s) { return append(__s.begin(), __s.end()); }

    NFShmString &operator+=(const CharT *__s) { return append(__s); }

    NFShmString &operator+=(CharT __c)
    {
        push_back(__c);
        return *this;
    }

    NFShmString &append(const NFShmString &__s) { return append(__s.begin(), __s.end()); }

    NFShmString &append(const NFShmString &__s,
                        size_type __pos, size_type __n)
    {
        if (__pos <= __s.size())
        {
            return append(__s.begin() + __pos,
                          __s.begin() + __pos + std::min(__n, __s.size() - __pos));
        }

        return *this;
    }

    NFShmString &append(const CharT *__s, size_type __n) { return append(__s, __s + __n); }

    NFShmString &append(const CharT *__s) { return append(__s, __s + Traits::length(__s)); }

    NFShmString &append(size_type __n, CharT __c);

    // Check to see if _InputIterator is an integer type.  If so, then
    // it can't be an iterator.
    template<class _InputIter>
    NFShmString &append(_InputIter __first, _InputIter __last)
    {
        typedef typename std::__is_integer<_InputIter>::__type _Integral;
        return _M_append_dispatch(__first, __last, _Integral());
    }

    NFShmString &append(const CharT *__first, const CharT *__last);

    void push_back(CharT __c)
    {
        if (m_size >= MAX_SIZE)
            return;
        _M_construct_null(m_data + m_size + 1);
        Traits::assign(*(m_data + m_size), __c);
        ++m_size;
    }

    void pop_back()
    {
        Traits::assign(*(m_data + m_size - 1), _M_null());
        --m_size;
    }

public:
    template<class _InputIter>
    NFShmString &append(_InputIter __f, _InputIter __l, input_iterator_tag);

    template<class _ForwardIter>
    NFShmString &append(_ForwardIter __f, _ForwardIter __l,
                        forward_iterator_tag);

    template<class _Integer>
    NFShmString &_M_append_dispatch(_Integer __n, _Integer __x, __true_type)
    {
        return append((size_type) __n, (CharT) __x);
    }

    template<class _InputIter>
    NFShmString &_M_append_dispatch(_InputIter __f, _InputIter __l,
                                    __false_type)
    {
        typedef typename iterator_traits<_InputIter>::iterator_category _Category;
        return append(__f, __l, _Category());
    }

public:                         // Assign

    NFShmString &assign(const NFShmString &__s) { return assign(__s.begin(), __s.end()); }

    NFShmString &assign(const NFShmString &__s,
                        size_type __pos, size_type __n)
    {
        if (__pos > __s.size())
            return *this;
        return assign(__s.begin() + __pos,
                      __s.begin() + __pos + min(__n, __s.size() - __pos));
    }

    NFShmString &assign(const CharT *__s, size_type __n) { return assign(__s, __s + __n); }

    NFShmString &assign(const CharT *__s) { return assign(__s, __s + Traits::length(__s)); }

    NFShmString &assign(size_type __n, CharT __c);

    // Check to see if _InputIterator is an integer type.  If so, then
    // it can't be an iterator.
    template<class _InputIter>
    NFShmString &assign(_InputIter __first, _InputIter __last)
    {
        typedef typename std::__is_integer<_InputIter>::__type _Integral;
        return _M_assign_dispatch(__first, __last, _Integral());
    }

    NFShmString &assign(const CharT *__f, const CharT *__l);

private:                        // Helper functions for assign.

    template<class _Integer>
    NFShmString &_M_assign_dispatch(_Integer __n, _Integer __x, __true_type)
    {
        return assign((size_type) __n, (CharT) __x);
    }

    template<class _InputIter>
    NFShmString &_M_assign_dispatch(_InputIter __f, _InputIter __l,
                                    __false_type);

public:                         // Insert

    NFShmString &insert(size_type __pos, const NFShmString &__s)
    {
        if (__pos > size())
            return *this;
        if (size() > max_size() - __s.size())
            return *this;
        insert(m_data + __pos, __s.begin(), __s.end());
        return *this;
    }

    NFShmString &insert(size_type __pos, const NFShmString &__s,
                        size_type __beg, size_type __n)
    {
        if (__pos > size() || __beg > __s.size())
            return *this;
        size_type __len = std::min(__n, __s.size() - __beg);
        if (size() > max_size() - __len)
            *this;
        insert(m_data + __pos,
               __s.begin() + __beg, __s.begin() + __beg + __len);
        return *this;
    }

    NFShmString &insert(size_type __pos, const CharT *__s, size_type __n)
    {
        if (__pos > size())
            return *this;
        if (size() > max_size() - __n)
            return *this;
        insert(m_data + __pos, __s, __s + __n);
        return *this;
    }

    NFShmString &insert(size_type __pos, const CharT *__s)
    {
        if (__pos > size())
            return *this;
        size_type __len = Traits::length(__s);
        if (size() > max_size() - __len)
            return *this;
        insert(m_data + __pos, __s, __s + __len);
        return *this;
    }

    NFShmString &insert(size_type __pos, size_type __n, CharT __c)
    {
        if (__pos > size())
            return *this;
        if (size() > max_size() - __n)
            return *this;
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
    void insert(iterator __p, _InputIter, _InputIter, input_iterator_tag);

    template<class _ForwardIter>
    void insert(iterator __p, _ForwardIter, _ForwardIter, forward_iterator_tag);


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
        typedef typename iterator_traits<_InputIter>::iterator_category _Category;
        insert(__p, __first, __last, _Category());
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

    NFShmString &erase(size_type __pos = 0, size_type __n = npos)
    {
        if (__pos > size())
            return *this;
        erase(m_data + __pos, m_data + __pos + std::min(__n, size() - __pos));
        return *this;
    }

    iterator erase(iterator __position)
    {
        // The move includes the terminating null.
        Traits::move(__position, __position + 1, m_data + m_size - __position);
        --m_size;
        return __position;
    }

    iterator erase(iterator __first, iterator __last)
    {
        if (__first != __last)
        {
            // The move includes the terminating null.
            Traits::move(__first, __last, (m_data + m_size - __last) + 1);
            m_size = m_size - (__last - __first);
        }
        return __first;
    }

public:                         // Compare

    int compare(const NFShmString &__s) const { return _M_compare(m_data, m_data + m_size, __s.m_data, __s.m_data + m_size); }

    int compare(size_type __pos1, size_type __n1,
                const NFShmString &__s) const
    {
        NF_ASSERT(__pos1 <= size());
        return _M_compare(m_data + __pos1,
                          m_data + __pos1 + min(__n1, size() - __pos1),
                          __s.m_data, __s.m_data + m_size);
    }

    int compare(size_type __pos1, size_type __n1,
                const NFShmString &__s,
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

template<int MAX_SIZE, class CharT, class _Traits>
const typename NFShmString<MAX_SIZE, CharT, _Traits>::size_type
        NFShmString<MAX_SIZE, CharT, _Traits>::npos
        = (typename NFShmString<MAX_SIZE, CharT, _Traits>::size_type) -1;

// Change the string's capacity so that it is large enough to hold
//  at least __res_arg elements, plus the terminating null.  Note that,
//  if __res_arg < capacity(), this member function may actually decrease
//  the string's capacity.
template<int MAX_SIZE, class CharT, class _Traits>
void NFShmString<MAX_SIZE, CharT, _Traits>::reserve(size_type __res_arg)
{

}

template<int MAX_SIZE, class CharT, class _Traits>
NFShmString<MAX_SIZE, CharT, _Traits> &
NFShmString<MAX_SIZE, CharT, _Traits>::append(size_type __n, CharT __c)
{
    if (__n > max_size() || size() + __n > max_size())
    {
        __n = max_size() - size();
    }

    if (__n > 0)
    {
        std::uninitialized_fill_n(m_data + m_size + 1, __n - 1, __c);
        _M_construct_null(m_data + m_size + __n);
        _Traits::assign(*(m_data + m_size), __c);
        m_size += __n;
    }
    return *this;
}

template<int MAX_SIZE, class CharT, class _Traits>
template<class _InputIterator>
NFShmString<MAX_SIZE, CharT, _Traits> &
NFShmString<MAX_SIZE, CharT, _Traits>::append(_InputIterator __first,
                                              _InputIterator __last,
                                              input_iterator_tag)
{
    for (; __first != __last; ++__first)
        push_back(*__first);
    return *this;
}

template<int MAX_SIZE, class CharT, class _Traits>
template<class _ForwardIter>
NFShmString<MAX_SIZE, CharT, _Traits> &
NFShmString<MAX_SIZE, CharT, _Traits>::append(_ForwardIter __first,
                                              _ForwardIter __last,
                                              forward_iterator_tag)
{
    if (__first != __last)
    {
        const size_type __old_size = size();
        difference_type __n = std::distance(__first, __last);
        if (static_cast<size_type>(__n) > max_size() ||
            __old_size + static_cast<size_type>(__n) > max_size())
        {
            __n = max_size() - size();
            if (__n > 0)
            {
                _ForwardIter __f1 = __first;
                ++__f1;
                std::uninitialized_copy_n(__f1, __n - 1, m_data + m_size + 1);
                _M_construct_null(m_data + m_size + __n);
                _Traits::assign(*(m_data + m_size), *__first);
                m_size += __n;
            }
        }
        else
        {
            _ForwardIter __f1 = __first;
            ++__f1;
            uninitialized_copy(__f1, __last, m_data + m_size + 1);
            _M_construct_null(m_data + m_size + __n);
            _Traits::assign(*(m_data + m_size), *__first);
            m_size += __n;
        }
    }
    return *this;
}

template<int MAX_SIZE, class CharT, class _Traits>
NFShmString<MAX_SIZE, CharT, _Traits> &
NFShmString<MAX_SIZE, CharT, _Traits>::append(const CharT *__first,
                                              const CharT *__last)
{
    if (__first != __last)
    {
        const size_type __old_size = size();
        ptrdiff_t __n = __last - __first;
        if (__n > max_size() || __old_size + __n > max_size())
        {
            __n = max_size() - size();
            if (__n > 0)
            {
                const CharT *__last2 = __first + __n;
                const CharT *__f1 = __first;
                ++__f1;
                std::uninitialized_copy(__f1, __last2, m_data + m_size + 1);
                _M_construct_null(m_data + m_size + __n);
                _Traits::assign(*(m_data + m_size), *__first);
                m_size += __n;
            }
        }
        else
        {
            const CharT *__f1 = __first;
            ++__f1;
            uninitialized_copy(__f1, __last, m_data + m_size + 1);
            _M_construct_null(m_data + m_size + __n);
            _Traits::assign(*(m_data + m_size), *__first);
            m_size += __n;
        }
    }
    return *this;
}

template<int MAX_SIZE, class CharT, class _Traits>
NFShmString<MAX_SIZE, CharT, _Traits> &
NFShmString<MAX_SIZE, CharT, _Traits>::assign(size_type __n, CharT __c)
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

template<int MAX_SIZE, class CharT, class _Traits>
template<class _InputIter>
NFShmString<MAX_SIZE, CharT, _Traits> &NFShmString<MAX_SIZE, CharT, _Traits>
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

template<int MAX_SIZE, class CharT, class _Traits>
NFShmString<MAX_SIZE, CharT, _Traits> &
NFShmString<MAX_SIZE, CharT, _Traits>::assign(const CharT *__f,
                                              const CharT *__l)
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


template<int MAX_SIZE, class CharT, class _Traits>
typename NFShmString<MAX_SIZE, CharT, _Traits>::iterator
NFShmString<MAX_SIZE, CharT, _Traits>
::_M_insert_aux(NFShmString<MAX_SIZE, CharT, _Traits>::iterator __p,
                CharT __c)
{
    iterator __new_pos = __p;
    if (m_size < MAX_SIZE)
    {
        _M_construct_null(m_data + m_size + 1);
        _Traits::move(__p + 1, __p, m_data + m_size - __p);
        _Traits::assign(*__p, __c);
        ++m_size;
    }
    else
    {
        return *this;
    }
    return __new_pos;
}

template<int MAX_SIZE, class CharT, class _Traits>
void NFShmString<MAX_SIZE, CharT, _Traits>
::insert(NFShmString<MAX_SIZE, CharT, _Traits>::iterator __position,
         size_t __n, CharT __c)
{
    if (__n != 0)
    {
        if (size_type(MAX_SIZE - m_size) >= __n)
        {
            const size_type __elems_after = m_data + m_size - __position;
            iterator __old_finish = m_data + m_size;
            if (__elems_after >= __n)
            {
                uninitialized_copy((m_data + m_size - __n) + 1, m_data + m_size + 1,
                                   m_data + m_size + 1);
                m_size += __n;
                _Traits::move(__position + __n,
                              __position, (__elems_after - __n) + 1);
                _Traits::assign(__position, __n, __c);
            }
            else
            {
                uninitialized_fill_n(m_data + m_size + 1, __n - __elems_after - 1, __c);
                m_size += __n - __elems_after;
                uninitialized_copy(__position, __old_finish + 1, m_data + m_size);
                m_size += __elems_after;
                _Traits::assign(__position, __elems_after + 1, __c);
            }
        }
    }
}

template<int MAX_SIZE, class CharT, class _Traits>
template<class _InputIter>
void NFShmString<MAX_SIZE, CharT, _Traits>::insert(iterator __p,
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

template<int MAX_SIZE, class CharT, class _Traits>
template<class _ForwardIter>
void
NFShmString<MAX_SIZE, CharT, _Traits>::insert(iterator __position,
                                              _ForwardIter __first,
                                              _ForwardIter __last,
                                              forward_iterator_tag)
{
    if (__first != __last)
    {
        difference_type __n = 0;
        distance(__first, __last, __n);
        if (MAX_SIZE - m_size >= __n)
        {
            const difference_type __elems_after = m_data + m_size - __position;
            iterator __old_finish = m_data + m_size;
            if (__elems_after >= __n)
            {
                std::uninitialized_copy((m_data + m_size - __n) + 1, m_data + m_size + 1,
                                        m_data + m_size + 1);
                m_size += __n;
                _Traits::move(__position + __n,
                              __position, (__elems_after - __n) + 1);
                _M_copy(__first, __last, __position);
            }
            else
            {
                _ForwardIter __mid = __first;
                advance(__mid, __elems_after + 1);
                uninitialized_copy(__mid, __last, m_data + m_size + 1);
                m_size += __n - __elems_after;
                std::uninitialized_copy(__position, __old_finish + 1, m_data + m_size);
                m_size += __elems_after;
                _M_copy(__first, __mid, __position);
            }
        }
    }
}


template<int MAX_SIZE, class CharT, class _Traits>
void
NFShmString<MAX_SIZE, CharT, _Traits>::insert(iterator __position,
                                              const CharT *__first,
                                              const CharT *__last)
{
    if (__first != __last)
    {
        const ptrdiff_t __n = __last - __first;
        if (MAX_SIZE - m_size >= __n)
        {
            const ptrdiff_t __elems_after = m_data + m_size - __position;
            iterator __old_finish = m_data + m_size;
            if (__elems_after >= __n)
            {
                std::uninitialized_copy((m_data + m_size - __n) + 1, m_data + m_size + 1,
                                        m_data + m_size + 1);
                m_size += __n;
                _Traits::move(__position + __n,
                              __position, (__elems_after - __n) + 1);
                _M_copy(__first, __last, __position);
            }
            else
            {
                const CharT *__mid = __first;
                std::advance(__mid, __elems_after + 1);
                std::uninitialized_copy(__mid, __last, m_data + m_size + 1);
                m_size += __n - __elems_after;
                std::uninitialized_copy(__position, __old_finish + 1, m_data + m_size);
                m_size += __elems_after;
                _M_copy(__first, __mid, __position);
            }
        }
    }
}

// Operator== and operator!=

template<int MAX_SIZE, class CharT, class _Traits>
inline bool
operator==(const NFShmString<MAX_SIZE, CharT, _Traits>& __x,
           const NFShmString<MAX_SIZE, CharT, _Traits>& __y) {
    return __x.size() == __y.size() &&
           _Traits::compare(__x.data(), __y.data(), __x.size()) == 0;
}

template<int MAX_SIZE, class CharT, class _Traits>
inline bool
operator==(const CharT* __s,
           const NFShmString<MAX_SIZE, CharT, _Traits>& __y) {
    size_t __n = _Traits::length(__s);
    return __n == __y.size() && _Traits::compare(__s, __y.data(), __n) == 0;
}

template<int MAX_SIZE, class CharT, class _Traits>
inline bool
operator==(const NFShmString<MAX_SIZE, CharT, _Traits>& __x,
           const CharT* __s) {
    size_t __n = _Traits::length(__s);
    return __x.size() == __n && _Traits::compare(__x.data(), __s, __n) == 0;
}

// Operator< (and also >, <=, and >=).

template<int MAX_SIZE, class CharT, class _Traits>
inline bool
operator<(const NFShmString<MAX_SIZE, CharT, _Traits>& __x,
          const NFShmString<MAX_SIZE, CharT, _Traits>& __y) {
    return NFShmString<MAX_SIZE, CharT, _Traits>
           ::_M_compare(__x.begin(), __x.end(), __y.begin(), __y.end()) < 0;
}

template<int MAX_SIZE, class CharT, class _Traits>
inline bool
operator<(const CharT* __s,
          const NFShmString<MAX_SIZE, CharT, _Traits>& __y) {
    size_t __n = _Traits::length(__s);
    return NFShmString<MAX_SIZE, CharT, _Traits>
           ::_M_compare(__s, __s + __n, __y.begin(), __y.end()) < 0;
}

template<int MAX_SIZE, class CharT, class _Traits>
inline bool
operator<(const NFShmString<MAX_SIZE, CharT, _Traits>& __x,
          const CharT* __s) {
    size_t __n = _Traits::length(__s);
    return NFShmString<MAX_SIZE, CharT, _Traits>
           ::_M_compare(__x.begin(), __x.end(), __s, __s + __n) < 0;
}

/**
*@brief 求hash值
*/
namespace std
{
    template<int SIZE>
    struct hash<NFShmString<SIZE>>
    {
        size_t operator()(const NFShmString <SIZE> &eventKey) const
        {
            return std::hash<std::string>()(eventKey.ToString());
        }
    };
}