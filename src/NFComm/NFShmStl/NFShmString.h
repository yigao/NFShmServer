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


template<class CharT, int MAX_SIZE, class Traits = std::char_traits<CharT>>
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

    NFShmBasicString(const std::basic_string<CharT, Traits> &__s)
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

    NFShmBasicString(const std::basic_string<CharT, Traits> &__s, size_type __pos, size_type __n = npos)
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
const typename NFShmBasicString<_CharT, MAX_SIZE, _Traits>::size_type
        NFShmBasicString<_CharT, MAX_SIZE, _Traits>::npos
        = (typename NFShmBasicString<_CharT, MAX_SIZE, _Traits>::size_type) -1;

// Change the string's capacity so that it is large enough to hold
//  at least __res_arg elements, plus the terminating null.  Note that,
//  if __res_arg < capacity(), this member function may actually decrease
//  the string's capacity.
template<class _CharT, int MAX_SIZE, class _Traits>
void NFShmBasicString<_CharT, MAX_SIZE, _Traits>::reserve(size_type __res_arg)
{

}