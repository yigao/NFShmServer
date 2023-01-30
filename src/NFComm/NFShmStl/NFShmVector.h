// -------------------------------------------------------------------------
//    @FileName         :    NFShmVector.h
//    @Author           :    gaoyi
//    @Date             :    23-1-30
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmVector
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include <iterator>
#include <algorithm>

template<class Tp, int MAX_SIZE>
class NFShmVector
{
public:
    typedef Tp value_type;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef value_type *iterator;
    typedef const value_type *const_iterator;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
protected:
    Tp *m_end_of_storage;
    Tp m_data[MAX_SIZE];
    size_type m_size;
protected:
    int _M_insert_aux(iterator __position, const Tp& __x);
    int _M_insert_aux(iterator __position);
public:
    iterator begin() { return m_data; }

    const_iterator begin() const { return m_data; }

    iterator end() { return m_data+m_size; }

    const_iterator end() const { return m_data+m_size; }

    reverse_iterator rbegin() { return reverse_iterator(end()); }

    const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

    reverse_iterator rend() { return reverse_iterator(begin()); }

    const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

    size_type size() const { return m_size; }

    size_type max_size() const { return MAX_SIZE; }

    size_type capacity() const { return MAX_SIZE; }

    bool empty() const { return begin() == end(); }

    reference operator[](size_type __n) { return *(begin() + __n); }

    const_reference operator[](size_type __n) const { return *(begin() + __n); }

    explicit NFShmVector()
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
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            std::_Construct(m_data+i, Tp());
        }
        m_size = 0;
        m_end_of_storage = m_data + MAX_SIZE;
        return 0;
    }

    int ResumeInit()
    {
        m_end_of_storage = m_data + MAX_SIZE;
        return 0;
    }

    explicit NFShmVector(size_type __n)
    {
        if (__n > MAX_SIZE)
        {
            __n = MAX_SIZE;
        }
        std::uninitialized_fill_n(m_data, __n, Tp());
        m_size = __n;
    }

    NFShmVector(const NFShmVector<Tp, MAX_SIZE> &__x)
    {
        auto finish = std::uninitialized_copy(__x.begin(), __x.end(), m_data);
        m_size = finish - begin();
    }

    NFShmVector(const Tp *__first, const Tp *__last)
    {
        if (__last - __first <= MAX_SIZE)
        {
            auto finish = std::uninitialized_copy(__first, __last, m_data);
            m_size = finish - begin();
        }
        else
        {
            __last = __first + MAX_SIZE;
            auto finish = std::uninitialized_copy(__first, __last, m_data);
            m_size = finish - begin();
        }
    }

    ~NFShmVector()
    {
    }

    NFShmVector<Tp, MAX_SIZE> &operator=(const NFShmVector<Tp, MAX_SIZE> &__x);

    void reserve(size_type __n)
    {

    }

    // assign(), a generalized assignment member function.  Two
    // versions: one that takes a count, and one that takes a range.
    // The range version is a member template, so we dispatch on whether
    // or not the type is an integer.

    void assign(size_type __n, const Tp &__val) { _M_fill_assign(__n, __val); }

    void _M_fill_assign(size_type __n, const Tp &__val);

    reference front() { return *begin(); }

    const_reference front() const { return *begin(); }

    reference back() { return *(end() - 1); }

    const_reference back() const { return *(end() - 1); }

    int push_back(const Tp &__x)
    {
        if (m_data + m_size != m_end_of_storage)
        {
            std::_Construct(m_data + m_size, __x);
            ++m_size;
            return 0;
        }
        else
            return _M_insert_aux(end(), __x);
    }

    int push_back()
    {
        if (m_data + m_size != m_end_of_storage)
        {
            std::_Construct(m_data + m_size);
            ++m_size;
            return 0;
        }
        else
            return _M_insert_aux(end());
    }

    void swap(NFShmVector<Tp, MAX_SIZE> &__x)
    {

    }

    iterator insert(iterator __position, const Tp &__x)
    {
        size_type __n = __position - begin();
        if (m_data + m_size != m_end_of_storage && __position == end())
        {
            std::_Construct(m_data + m_size, __x);
            ++m_size;
        }
        else
            _M_insert_aux(__position, __x);
        return begin() + __n;
    }

    iterator insert(iterator __position)
    {
        size_type __n = __position - begin();
        if (m_data + m_size != m_end_of_storage && __position == end())
        {
            std::_Construct(m_data + m_size);
            ++m_size;
        }
        else
            _M_insert_aux(__position);
        return begin() + __n;
    }

    void insert(iterator __position,
                const_iterator __first, const_iterator __last);

    void insert(iterator __pos, size_type __n, const Tp &__x) { _M_fill_insert(__pos, __n, __x); }

    void _M_fill_insert(iterator __pos, size_type __n, const Tp &__x);

    void pop_back()
    {
        --m_size;
        destroy(m_data + m_size);
    }

    iterator erase(iterator __position)
    {
        if (__position + 1 != end())
            copy(__position + 1, m_data + m_size, __position);
        --m_size;
        std::_Destroy(m_data + m_size);
        return __position;
    }

    iterator erase(iterator __first, iterator __last)
    {
        iterator __i = copy(__last, m_data + m_size, __first);
        std::_Destroy(__i, m_data + m_size);
        m_size = m_size - (__last - __first);
        return __first;
    }

    void resize(size_type __new_size, const Tp &__x)
    {
        if (__new_size < size())
            erase(begin() + __new_size, end());
        else
            insert(end(), __new_size - size(), __x);
    }

    void resize(size_type __new_size) { resize(__new_size, Tp()); }

    void clear() { erase(begin(), end()); }
};


template <class _Tp, int MAX_SIZE>
inline bool
operator==(const NFShmVector<_Tp, MAX_SIZE>& __x, const NFShmVector<_Tp, MAX_SIZE>& __y)
{
    return __x.size() == __y.size() &&
           std::equal(__x.begin(), __x.end(), __y.begin());
}

template <class _Tp, int MAX_SIZE>
inline bool
operator<(const NFShmVector<_Tp, MAX_SIZE>& __x, const NFShmVector<_Tp, MAX_SIZE>& __y)
{
    return std::lexicographical_compare(__x.begin(), __x.end(),
                                   __y.begin(), __y.end());
}

template <class _Tp, int MAX_SIZE>
NFShmVector<_Tp, MAX_SIZE>&
NFShmVector<_Tp, MAX_SIZE>::operator=(const NFShmVector<_Tp, MAX_SIZE>& __x)
{
    if (&__x != this) {
        const size_type __xlen = __x.size();
        if (size() >= __xlen) {
            iterator __i = copy(__x.begin(), __x.end(), begin());
            std::_Destroy(__i, m_data + m_size);
        }
        else {
            std::copy(__x.begin(), __x.begin() + size(), m_data);
            std::uninitialized_copy(__x.begin() + size(), __x.end(), m_data + m_size);
        }
        m_size = __xlen;
    }
    return *this;
}

template <class _Tp, int MAX_SIZE>
void NFShmVector<_Tp, MAX_SIZE>::_M_fill_assign(size_t __n, const value_type& __val)
{
    if (__n > capacity()) {
        __n = capacity();
    }

    if (__n > size()) {
        std::fill(begin(), end(), __val);
        std::uninitialized_fill_n(m_data + m_size, __n - size(), __val);
        m_size = __n;
    }
    else
        erase(fill_n(begin(), __n, __val), end());
}

template <class _Tp, int MAX_SIZE>
int NFShmVector<_Tp, MAX_SIZE>::_M_insert_aux(iterator __position, const _Tp& __x)
{
    if (m_data + m_size != m_end_of_storage) {
        std::_Construct(m_data + m_size, *(m_data + m_size - 1));
        ++m_size;
        _Tp __x_copy = __x;
        std::copy_backward(__position, m_data + m_size - 2, m_data + m_size - 1);
        *__position = __x_copy;
        return 0;
    }
    else {
        return -1;
    }
}

template <class _Tp, int MAX_SIZE>
int NFShmVector<_Tp, MAX_SIZE>::_M_insert_aux(iterator __position)
{
    if (m_data + m_size != m_end_of_storage) {
        std::_Construct(m_data + m_size, *(m_data + m_size - 1));
        ++m_size;
        std::copy_backward(__position, m_data + m_size - 2, m_data + m_size - 1);
        *__position = _Tp();
        return 0;
    }
    else {
        return -1;
    }
}

template <class _Tp, int MAX_SIZE>
void NFShmVector<_Tp, MAX_SIZE>::_M_fill_insert(iterator __position, size_type __n,
                                              const _Tp& __x)
{
    if (__n != 0) {
        if (size_type(m_end_of_storage - m_data + m_size) < __n) {
            __n = size_type(m_end_of_storage - m_data + m_size);
        }

        _Tp __x_copy = __x;
        const size_type __elems_after = m_data + m_size - __position;
        iterator __old_finish = m_data + m_size;
        if (__elems_after > __n) {
            std::uninitialized_copy(m_data + m_size - __n, m_data + m_size, m_data + m_size);
            m_size += __n;
            std::copy_backward(__position, __old_finish - __n, __old_finish);
            std::fill(__position, __position + __n, __x_copy);
        }
        else {
            std::uninitialized_fill_n(m_data + m_size, __n - __elems_after, __x_copy);
            m_size += __n - __elems_after;
            std::uninitialized_copy(__position, __old_finish, m_data + m_size);
            m_size += __elems_after;
            std::fill(__position, __old_finish, __x_copy);
        }
    }
}

template <class _Tp, int MAX_SIZE>
void NFShmVector<_Tp, MAX_SIZE>::insert(iterator __position,
                                 const_iterator __first,
                                 const_iterator __last)
{
    if (__first != __last) {
        size_type __n = 0;
        std::distance(__first, __last, __n);
        if (size_type(m_end_of_storage - m_data + m_size) < __n) {
            __n = size_type(m_end_of_storage - m_data + m_size);
        }

        const size_type __elems_after = m_data + m_size - __position;
        iterator __old_finish = m_data + m_size;
        if (__elems_after > __n) {
            std::uninitialized_copy(m_data + m_size - __n, m_data + m_size, m_data + m_size);
            m_size += __n;
            std::copy_backward(__position, __old_finish - __n, __old_finish);
            std::copy(__first, __last, __position);
        }
        else {
            std::uninitialized_copy(__first + __elems_after, __last, m_data + m_size);
            m_size += __n - __elems_after;
            std::uninitialized_copy(__position, __old_finish, m_data + m_size);
            m_size += __elems_after;
            std::copy(__first, __first + __elems_after, __position);
        }
    }
}