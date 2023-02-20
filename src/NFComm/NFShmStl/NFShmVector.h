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
#include "NFComm/NFPluginModule/NFCheck.h"
#include <iterator>
#include <algorithm>
#include <vector>

template<class Tp, size_t MAX_SIZE>
class NFShmVectorBase
{
public:
    explicit NFShmVectorBase()
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

    ~NFShmVectorBase()
    {
        memset(m_mem, 0, ARRAYSIZE_UNSAFE(m_mem));
        m_size = 0;
        m_data = NULL;
    }

    int CreateInit()
    {
        m_size = 0;
        memset(m_mem, 0, ARRAYSIZE_UNSAFE(m_mem));
        m_data = (Tp*)m_mem;
        return 0;
    }

    int ResumeInit()
    {
        m_data = (Tp*)m_mem;
        for(size_t i = 0; i < m_size; i++)
        {
            std::_Construct(m_data+i);
        }
        return 0;
    }

protected:
    Tp* m_data;
    int8_t m_mem[sizeof(Tp) * MAX_SIZE];
    size_t m_size;
};

template<class Tp, size_t MAX_SIZE>
class NFShmVector : protected NFShmVectorBase<Tp, MAX_SIZE>
{
private:
    typedef NFShmVectorBase<Tp, MAX_SIZE> _Base;
protected:
    using _Base::m_data;
    using _Base::m_size;
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
public:
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
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    explicit NFShmVector(size_type __n)
    {
        if (__n > MAX_SIZE)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "NFShmVector Constructor:__n:{} > MAX_SIZE:{}, Vector Space Not Enough! __n change to MAX_SIZE", __n,
                         MAX_SIZE);
            __n = MAX_SIZE;
        }

        std::uninitialized_fill_n(m_data, __n, Tp());
        m_size = __n;
    }

    NFShmVector(size_type __n, const Tp &__value)
    {
        if (__n > MAX_SIZE)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "NFShmVector Constructor:__n:{} > MAX_SIZE:{}, Vector Space Not Enough! __n change to MAX_SIZE", __n,
                         MAX_SIZE);
            __n = MAX_SIZE;
        }

        std::uninitialized_fill_n(m_data, __n, __value);
        m_size = __n;
    }

    template<size_t X_MAX_SIZE>
    NFShmVector(const NFShmVector<Tp, X_MAX_SIZE> &__x)
    {
        int max_size = MAX_SIZE <= __x.size() ? MAX_SIZE : __x.size();
        auto finish = std::uninitialized_copy_n(__x.begin(), max_size, m_data);
        m_size = finish - begin();
    }

    NFShmVector(const NFShmVector<Tp, MAX_SIZE> &__x)
    {
        int max_size = MAX_SIZE <= __x.size() ? MAX_SIZE : __x.size();
        auto finish = std::uninitialized_copy_n(__x.begin(), max_size, m_data);
        m_size = finish - begin();
    }

    NFShmVector(const std::initializer_list<Tp> &list)
    {
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            if (push_back(*it) != 0)
            {
                break;
            }
        }
    }

    template<class _InputIterator>
    NFShmVector(_InputIterator __first, _InputIterator __last)
    {
        typedef typename std::__is_integer<_InputIterator>::__type _Integral;
        _M_initialize_aux(__first, __last, _Integral());
    }

    ~NFShmVector()
    {
        clear();
    }

    NFShmVector<Tp, MAX_SIZE> &operator=(const NFShmVector<Tp, MAX_SIZE> &__x);
    NFShmVector<Tp, MAX_SIZE> &operator=(const std::vector<Tp> &__x);

public:
    iterator begin() { return m_data; }

    const_iterator begin() const { return m_data; }

    iterator end() { return m_data + m_size; }

    const_iterator end() const { return m_data + m_size; }

    reverse_iterator rbegin() { return reverse_iterator(end()); }

    const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

    reverse_iterator rend() { return reverse_iterator(begin()); }

    const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

    size_type size() const { return m_size; }

    size_type max_size() const { return MAX_SIZE; }

    size_type capacity() const { return MAX_SIZE; }

    bool empty() const { return begin() == end(); }

    reference operator[](size_type __n)
    {
        NF_ASSERT_MSG(__n < MAX_SIZE, "__n:{} >= MAX_SIZE:{}, the server dump", __n, MAX_SIZE);
        CHECK_EXPR(__n < m_size, *(begin() + __n), "__n:{} >= m_size:{}, you can't use it", __n, m_size);
        return *(begin() + __n);
    }

    const_reference operator[](size_type __n) const
    {
        NF_ASSERT_MSG(__n < MAX_SIZE, "__n:{} >= MAX_SIZE:{}, the server dump", __n, MAX_SIZE);
        CHECK_EXPR(__n < m_size, *(begin() + __n), "__n:{} >= m_size:{}, you can't use it", __n, m_size);
        return *(begin() + __n);
    }

    reference at(size_type __n)
    {
        NF_ASSERT_MSG(__n < MAX_SIZE, "__n:{} >= MAX_SIZE:{}, the server dump", __n, MAX_SIZE);
        CHECK_EXPR(__n < m_size, *(begin() + __n), "__n:{} >= m_size:{}, you can't use it", __n, m_size);
        return *(begin() + __n);
    }

    const_reference at(size_type __n) const
    {
        NF_ASSERT_MSG(__n < MAX_SIZE, "__n:{} >= MAX_SIZE:{}, the server dump", __n, MAX_SIZE);
        CHECK_EXPR(__n < m_size, *(begin() + __n), "__n:{} >= m_size:{}, you can't use it", __n, m_size);
        return *(begin() + __n);
    }

    void reserve(size_type __n)
    {

    }

    void shrink_to_fit()
    {

    }

    Tp *data()
    {
        return std::__addressof(front());
    }

    const Tp *data() const
    {
        return std::__addressof(front());
    }

    void assign(size_type __n, const Tp &__val) { _M_fill_assign(__n, __val); }

    template<class _InputIterator>
    void assign(_InputIterator __first, _InputIterator __last)
    {
        typedef typename std::__is_integer<_InputIterator>::__type _Integral;
        _M_assign_dispatch(__first, __last, _Integral());
    }

    reference front()
    {
        NF_ASSERT_MSG(0 < MAX_SIZE, "index:{} >= MAX_SIZE:{}, the server dump", 0, MAX_SIZE);
        CHECK_EXPR(0 < m_size, *(begin() + 0), "index:{} >= m_size:{}, you can't use it", 0, m_size);
        return *begin();
    }

    const_reference front() const
    {
        NF_ASSERT_MSG(0 < MAX_SIZE, "index:{} >= MAX_SIZE:{}, the server dump", 0, MAX_SIZE);
        CHECK_EXPR(0 < m_size, *(begin() + 0), "index:{} >= m_size:{}, you can't use it", 0, m_size);
        return *begin();
    }

    reference back()
    {
        NF_ASSERT_MSG((int) m_size - 1 >= 0 && (int) m_size - 1 < MAX_SIZE, "index:{} < 0 || >= MAX_SIZE:{}, the server dump", (int) m_size - 1,
                      MAX_SIZE);
        CHECK_EXPR((int) m_size - 1 >= 0, *(begin() + 0), "index:{} < 0 || >= m_size:{}, you can't use it", (int) m_size - 1, m_size);
        return *(end() - 1);
    }

    const_reference back() const
    {
        NF_ASSERT_MSG((int) m_size - 1 >= 0 && (int) m_size - 1 < MAX_SIZE, "index:{} < 0 || >= MAX_SIZE:{}, the server dump", (int) m_size - 1,
                      MAX_SIZE);
        CHECK_EXPR((int) m_size - 1 >= 0, *(begin() + 0), "index:{} < 0 || >= m_size:{}, you can't use it", (int) m_size - 1, m_size);
        return *(end() - 1);
    }

    int emplace_back(const Tp &__x)
    {
        return push_back(__x);
    }

    int push_back(const Tp &__x)
    {
        if (m_data + m_size != m_data + MAX_SIZE)
        {
            std::_Construct(m_data + m_size, __x);
            ++m_size;
            return 0;
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "NFShmVector push_back Failed, Vector Not Enough Space");
            return -1;
        }
    }

    int emplace_back()
    {
        return push_back();
    }

    int push_back()
    {
        if (m_data + m_size != m_data + MAX_SIZE)
        {
            std::_Construct(m_data + m_size);
            ++m_size;
            return 0;
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "NFShmVector push_back Failed, Vector Not Enough Space");
            return -1;
        }
    }

    void swap(NFShmVector<Tp, MAX_SIZE> &__x)
    {

    }

    iterator emplace(iterator __position, const Tp &__x)
    {
        return insert(__position, __x);
    }

    iterator insert(iterator __position, const Tp &__x)
    {
        size_type __n = __position - begin();
        if (m_data + m_size != m_data + MAX_SIZE && __position == end())
        {
            std::_Construct(m_data + m_size, __x);
            ++m_size;
        }
        else
        {
            if (_M_insert_aux(__position, __x) < 0)
            {
                return end();
            }
        }
        return begin() + __n;
    }

    iterator emplace(iterator __position)
    {
        return insert(__position);
    }

    iterator insert(iterator __position)
    {
        size_type __n = __position - begin();
        if (m_data + m_size != m_data + MAX_SIZE && __position == end())
        {
            std::_Construct(m_data + m_size);
            ++m_size;
        }
        else
        {
            if (_M_insert_aux(__position) < 0)
            {
                return end();
            }
        }
        return begin() + __n;
    }

    void insert(iterator __position,
                const_iterator __first, const_iterator __last);

    template<class _InputIterator>
    void insert(iterator __pos, _InputIterator __first, _InputIterator __last)
    {
        typedef typename std::__is_integer<_InputIterator>::__type _Integral;
        _M_insert_dispatch(__pos, __first, __last, _Integral());
    }

    void insert(iterator __pos, size_type __n, const Tp &__x) { _M_fill_insert(__pos, __n, __x); }

    void pop_back()
    {
        --m_size;
        std::_Destroy(m_data + m_size);
    }

    /**
     * @brief This function erases the element at the given position and returns the iterator to the next element.
     *          It also reduces the size of the vector and constructs a default object at the end of the vector.
     *          It checks if the given position is valid and returns end() if it is not.
     * @param __position
     * @return
     */
    iterator erase(iterator __position)
    {
        CHECK_EXPR(__position != end(), end(), "");
        CHECK_EXPR(__position - begin() < m_size, end(), "");

        if (__position + 1 != end())
            std::copy(__position + 1, m_data + m_size, __position);
        --m_size;
        std::_Destroy(m_data + m_size);
        return __position;
    }

    /**
     * @brief   This function erases the elements in the range [__first, __last) from the vector.
     *          It copies the elements beginning from __last to the position __first and destroys the elements from __i to m_data + m_size.
     *          It then constructs the elements from __i to m_data + m_size with the default constructor and updates the size of the vector.
     *          Finally, it returns the iterator __first.
     * @param __first
     * @param __last
     * @return
     */
    iterator erase(iterator __first, iterator __last)
    {
        iterator __i = std::copy(__last, m_data + m_size, __first);
        std::_Destroy(__i, m_data + m_size);
        m_size = m_size - (__last - __first);
        return __first;
    }

    /**
     * @brief  This function resizes the vector to the given size '__new_size'.
     * If the new size is less than the current size, elements from the beginning + __new_size to the end are erased.
     * If the new size is greater than the current size, elements of value '__x' are inserted from the end to the new size.
     * @param __new_size
     * @param __x
     */
    void resize(size_type __new_size, const Tp &__x)
    {
        if (__new_size < size())
            erase(begin() + __new_size, end());
        else
            insert(end(), __new_size - size(), __x);
    }

    void resize(size_type __new_size)
    {
        resize(__new_size, Tp());
    }

    void clear()
    {
        erase(begin(), end());
    }

    iterator binary_insert(const Tp &val)
    {
        return binary_insert(val, std::less<Tp>());
    }

    /**
     * @brief  // This function performs a binary insertion of the given value 'val' into the vector, using the provided comparison function 'comp'.
     * If the vector does not have enough space, an iterator to the end of the vector is returned and an error message is thrown.
     * Otherwise, the iterator to the newly inserted value is returned.
     * @tparam _Compare
     * @param val
     * @param comp
     * @return
     */
    template<typename _Compare>
    iterator binary_insert(const Tp &val, _Compare comp)
    {
        CHECK_EXPR(m_size < MAX_SIZE, end(), "The Vector No Enough Space! binary_insert Fail!");

        auto iter = std::lower_bound(begin(), end(), val, comp);
        auto new_iter = insert(iter);
        if (new_iter != end())
        {
            *new_iter = val;
        }
        return new_iter;
    }

    iterator binary_search(const Tp &val)
    {
        return binary_search(val, std::less<Tp>());
    }

    /**
     * @brief This function performs a binary search on the container for the given value, using the given comparison function.
     * If the value is found, an iterator pointing to it is returned, otherwise a null iterator is returned.
     * @tparam _Compare
     * @param val
     * @param comp
     * @return
     */
    template<typename _Compare>
    iterator binary_search(const Tp &val, _Compare comp)
    {
        auto pair_iter = std::equal_range(begin(), end(), val, comp);
        if (pair_iter.first != pair_iter.second)
        {
            return pair_iter.first;
        }
        return NULL;
    }

    std::vector<iterator> binary_search_array(const Tp &val)
    {
        return binary_search_array(val, std::less<Tp>());
    }

    template<typename _Compare>
    std::vector<iterator> binary_search_array(const Tp &val, _Compare comp)
    {
        std::vector<iterator> vec;
        auto pair_iter = std::equal_range(begin(), end(), val, comp);
        for (auto iter = pair_iter.first; iter != pair_iter.second; iter++)
        {
            vec.push_back(iter);
        }
        return vec;
    }

    template<typename _Compare>
    int binary_delete(const Tp &val, _Compare comp)
    {
        auto pair_iter = std::equal_range(begin(), end(), val, comp);
        erase(pair_iter.first, pair_iter.second);
        return 0;
    }

    int binary_delete(const Tp &val)
    {
        return binary_delete(val, std::less<Tp>());
    }

    template<typename _Compare>
    bool is_sorted(_Compare comp)
    {
        return std::is_sorted(begin(), end(), comp);
    }

    bool is_sorted()
    {
        return is_sorted(std::less<Tp>());
    }

    void sort()
    {
        return sort(std::less<Tp>());
    }

    template<typename _Compare>
    void sort(_Compare comp)
    {
        return std::sort(begin(), end(), comp);
    }

    void random_shuffle()
    {
        std::random_shuffle(begin(), end());
    }

    void shuffle()
    {
        std::shuffle(begin(), end());
    }

    void remove(const Tp& value)
    {
        auto iter = std::remove(begin(), end(), value);
        if (iter != end())
        {
            erase(iter, end());
        }
    }

    template<class Predicate>
    void remove_if(Predicate pre)
    {
        auto iter = std::remove_if(begin(), end(), pre);
        if (iter != end())
        {
            erase(iter, end());
        }
    }

    void unique()
    {
        auto iter = std::unique(begin(), end());
        if (iter != end())
        {
            erase(iter, end());
        }
    }
protected:
    int _M_insert_aux(iterator __position, const Tp &__x);

    int _M_insert_aux(iterator __position);

    void _M_fill_insert(iterator __pos, size_type __n, const Tp &__x);

    void _M_fill_assign(size_type __n, const Tp &__val);

    template<class _Integer>
    void _M_initialize_aux(_Integer __n, _Integer __value, std::__true_type)
    {
        if (__n > MAX_SIZE)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0,
                         "NFShmVector Constructor _M_initialize_aux, __n:{} > MAX_SIZE:{}, Vector Space Not Enough! __n change to MAX_SIZE", __n,
                         MAX_SIZE);
            __n = MAX_SIZE;
        }
        std::uninitialized_fill_n(m_data, __n, __value);
        m_size = __n;
    }

    template<class _InputIterator>
    void _M_initialize_aux(_InputIterator __first, _InputIterator __last,
                           std::__false_type)
    {
        _M_range_initialize(__first, __last, typename std::iterator_traits<_InputIterator>::iterator_category());
    }

    template<class _InputIterator>
    void _M_range_initialize(_InputIterator __first,
                             _InputIterator __last, std::input_iterator_tag)
    {
        for (; __first != __last; ++__first)
        {
            if (push_back(*__first) != 0)
            {
                break;
            }
        }
    }

    // This function is only called by the constructor.
    template<class _ForwardIterator>
    void _M_range_initialize(_ForwardIterator __first,
                             _ForwardIterator __last, std::forward_iterator_tag)
    {
        size_type __n = std::distance(__first, __last);
        if (__n > MAX_SIZE)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0,
                         "NFShmVector Constructor _M_range_initialize, __n:{} > MAX_SIZE:{}, Vector Space Not Enough! __n change to MAX_SIZE", __n,
                         MAX_SIZE);
            __n = MAX_SIZE;
        }
        auto finish = std::uninitialized_copy_n(__first, __n, m_data);
        m_size = finish - begin();
    }

    template<class _InputIterator>
    void _M_range_insert(iterator __pos,
                         _InputIterator __first, _InputIterator __last,
                         std::input_iterator_tag);

    template<class _ForwardIterator>
    void _M_range_insert(iterator __pos,
                         _ForwardIterator __first, _ForwardIterator __last,
                         std::forward_iterator_tag);


    template<class _Integer>
    void _M_assign_dispatch(_Integer __n, _Integer __val, std::__true_type)
    {
        _M_fill_assign((size_type) __n, (Tp) __val);
    }

    template<class _InputIter>
    void _M_assign_dispatch(_InputIter __first, _InputIter __last, std::__false_type)
    {
        _M_assign_aux(__first, __last, typename std::iterator_traits<_InputIter>::iterator_category());
    }

    template<class _InputIterator>
    void _M_assign_aux(_InputIterator __first, _InputIterator __last,
                       std::input_iterator_tag);

    template<class _ForwardIterator>
    void _M_assign_aux(_ForwardIterator __first, _ForwardIterator __last,
                       std::forward_iterator_tag);

    template<class _Integer>
    void _M_insert_dispatch(iterator __pos, _Integer __n, _Integer __val,
                            std::__true_type)
    {
        _M_fill_insert(__pos, (size_type) __n, (Tp) __val);
    }

    template<class _InputIterator>
    void _M_insert_dispatch(iterator __pos,
                            _InputIterator __first, _InputIterator __last,
                            std::__false_type)
    {
        _M_range_insert(__pos, __first, __last, typename std::iterator_traits<_InputIterator>::iterator_category());
    }
};


template<class _Tp, int MAX_SIZE>
inline bool
operator==(const NFShmVector<_Tp, MAX_SIZE> &__x, const NFShmVector<_Tp, MAX_SIZE> &__y)
{
    return __x.size() == __y.size() &&
           std::equal(__x.begin(), __x.end(), __y.begin());
}

template<class _Tp, int MAX_SIZE>
inline bool
operator<(const NFShmVector<_Tp, MAX_SIZE> &__x, const NFShmVector<_Tp, MAX_SIZE> &__y)
{
    return std::lexicographical_compare(__x.begin(), __x.end(),
                                        __y.begin(), __y.end());
}

template<class _Tp, size_t MAX_SIZE>
NFShmVector<_Tp, MAX_SIZE> &
NFShmVector<_Tp, MAX_SIZE>::operator=(const NFShmVector<_Tp, MAX_SIZE> &__x)
{
    if (&__x != this)
    {
        const size_type __xlen = __x.size();
        if (size() >= __xlen)
        {
            iterator __i = std::copy(__x.begin(), __x.end(), begin());
            std::_Destroy(__i, m_data + m_size);
        }
        else
        {
            std::copy(__x.begin(), __x.begin() + size(), m_data);
            std::uninitialized_copy(__x.begin() + size(), __x.end(), m_data + m_size);
        }
        m_size = __xlen;
    }
    return *this;
}

template<class _Tp, size_t MAX_SIZE>
NFShmVector<_Tp, MAX_SIZE> &
NFShmVector<_Tp, MAX_SIZE>::operator=(const std::vector<_Tp> &__x)
{
    assign(__x.begin(), __x.end());
    return *this;
}

template<class _Tp, size_t MAX_SIZE>
void NFShmVector<_Tp, MAX_SIZE>::_M_fill_assign(size_t __n, const value_type &__val)
{
    if (__n > capacity())
    {
        NFLogWarning(NF_LOG_SYSTEMLOG, 0, "The Vector Left Space:{} Not Enough! Can't Assign {} Element, Only {}", MAX_SIZE, __n, MAX_SIZE);
        __n = capacity();
    }

    if (__n > size())
    {
        std::fill(begin(), end(), __val);
        std::uninitialized_fill_n(m_data + m_size, __n - size(), __val);
        m_size = __n;
    }
    else
        erase(std::fill_n(begin(), __n, __val), end());
}

template<class _Tp, size_t MAX_SIZE>
int NFShmVector<_Tp, MAX_SIZE>::_M_insert_aux(iterator __position, const _Tp &__x)
{
    CHECK_EXPR(m_data + m_size != m_data + MAX_SIZE, -1, "The Vector No Enough Space!");
    std::_Construct(m_data + m_size, *(m_data + m_size - 1));
    ++m_size;
    _Tp __x_copy = __x;
    std::copy_backward(__position, m_data + m_size - 2, m_data + m_size - 1);
    *__position = __x_copy;
    return 0;
}

template<class _Tp, size_t MAX_SIZE>
int NFShmVector<_Tp, MAX_SIZE>::_M_insert_aux(iterator __position)
{
    CHECK_EXPR(m_data + m_size != m_data + MAX_SIZE, -1, "The Vector No Enough Space!");

    std::_Construct(m_data + m_size, *(m_data + m_size - 1));
    ++m_size;
    std::copy_backward(__position, m_data + m_size - 2, m_data + m_size - 1);
    *__position = _Tp();
    return 0;
}

template<class _Tp, size_t MAX_SIZE>
void NFShmVector<_Tp, MAX_SIZE>::_M_fill_insert(iterator __position, size_type __n,
                                                const _Tp &__x)
{
    CHECK_EXPR_NOT_RET(m_data + m_size != m_data + MAX_SIZE, "The Vector No Enough Space! Insert Fail!");
    if (__n != 0)
    {
        if (size_type(MAX_SIZE - m_size) < __n)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "The Vector Left Space:{} Not Enough! Can't Insert {} Element, Only {}", MAX_SIZE - m_size, __n,
                         MAX_SIZE - m_size);
            __n = size_type(MAX_SIZE - m_size);
        }

        _Tp __x_copy = __x;
        const size_type __elems_after = m_data + m_size - __position;
        iterator __old_finish = m_data + m_size;
        if (__elems_after > __n)
        {
            std::uninitialized_copy(m_data + m_size - __n, m_data + m_size, m_data + m_size);
            m_size += __n;
            std::copy_backward(__position, __old_finish - __n, __old_finish);
            std::fill(__position, __position + __n, __x_copy);
        }
        else
        {
            std::uninitialized_fill_n(m_data + m_size, __n - __elems_after, __x_copy);
            m_size += __n - __elems_after;
            std::uninitialized_copy(__position, __old_finish, m_data + m_size);
            m_size += __elems_after;
            std::fill(__position, __old_finish, __x_copy);
        }
    }
}

template<class _Tp, size_t MAX_SIZE>
void NFShmVector<_Tp, MAX_SIZE>::insert(iterator __position,
                                        const_iterator __first,
                                        const_iterator __last)
{
    CHECK_EXPR_NOT_RET(m_data + m_size != m_data + MAX_SIZE, "The Vector No Enough Space! Insert Fail!");

    if (__first != __last)
    {
        size_type __n = std::distance(__first, __last);

        if (size_type(MAX_SIZE - m_size) < __n)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "The Vector Left Space:{} Not Enough! Can't Insert {} Element, Only {}", MAX_SIZE - m_size, __n,
                         MAX_SIZE - m_size);
            __n = size_type(MAX_SIZE - m_size);
            auto temp = __first;
            std::advance(temp, __n);
            __last = temp;
            NF_ASSERT(std::distance(__first, __last) == __n);
        }

        const size_type __elems_after = m_data + m_size - __position;
        iterator __old_finish = m_data + m_size;
        if (__elems_after > __n)
        {
            std::uninitialized_copy(m_data + m_size - __n, m_data + m_size, m_data + m_size);
            m_size += __n;
            std::copy_backward(__position, __old_finish - __n, __old_finish);
            std::copy(__first, __last, __position);
        }
        else
        {
            std::uninitialized_copy(__first + __elems_after, __last, m_data + m_size);
            m_size += __n - __elems_after;
            std::uninitialized_copy(__position, __old_finish, m_data + m_size);
            m_size += __elems_after;
            std::copy(__first, __first + __elems_after, __position);
        }
    }
}

template<class _Tp, size_t MAX_SIZE>
template<class _InputIter>
void NFShmVector<_Tp, MAX_SIZE>::_M_assign_aux(_InputIter __first, _InputIter __last,
                                               std::input_iterator_tag)
{
    iterator __cur = begin();
    for (; __first != __last && __cur != end(); ++__cur, ++__first)
        *__cur = *__first;
    if (__first == __last)
        erase(__cur, end());
    else
        insert(end(), __first, __last);
}

template<class _Tp, size_t MAX_SIZE>
template<class _ForwardIter>
void NFShmVector<_Tp, MAX_SIZE>::_M_assign_aux(_ForwardIter __first, _ForwardIter __last,
                                               std::forward_iterator_tag)
{
    size_type __len = std::distance(__first, __last);

    if (__len > capacity())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "__len > capacity(), some copy not success");
        std::_Destroy(m_data, m_data + m_size);
        auto finish = std::uninitialized_copy_n(__first, MAX_SIZE, m_data);
        m_size = finish - begin();
    }
    else if (size() >= __len)
    {
        iterator __new_finish = std::copy(__first, __last, m_data);
        std::_Destroy(__new_finish, m_data + m_size);
        m_size = __new_finish - begin();
    }
    else
    {
        _ForwardIter __mid = __first;
        std::advance(__mid, size());
        std::copy(__first, __mid, m_data);
        auto finish = std::uninitialized_copy(__mid, __last, m_data + m_size);
        m_size = finish - begin();
    }
}

template<class _Tp, size_t MAX_SIZE>
template<class _InputIterator>
void NFShmVector<_Tp, MAX_SIZE>::_M_range_insert(iterator __pos,
                                                 _InputIterator __first,
                                                 _InputIterator __last,
                                                 std::input_iterator_tag)
{
    for (; __first != __last; ++__first)
    {
        __pos = insert(__pos, *__first);
        if (__pos == end())
        {
            break;
        }
        ++__pos;
    }
}

template<class _Tp, size_t MAX_SIZE>
template<class _ForwardIterator>
void NFShmVector<_Tp, MAX_SIZE>::_M_range_insert(iterator __position,
                                                 _ForwardIterator __first,
                                                 _ForwardIterator __last,
                                                 std::forward_iterator_tag)
{
    CHECK_EXPR_NOT_RET(m_data + m_size != m_data + MAX_SIZE, "The Vector No Enough Space! Insert Fail!");
    if (__first != __last)
    {
        size_type __n = std::distance(__first, __last);

        if (size_type(MAX_SIZE - m_size) < __n)
        {
            NFLogWarning(NF_LOG_SYSTEMLOG, 0, "The Vector Left Space:{} Not Enough! Can't Insert {} Element, Only {}", MAX_SIZE - m_size, __n,
                         MAX_SIZE - m_size);
            __n = size_type(MAX_SIZE - m_size);
            auto temp = __first;
            std::advance(temp, __n);
            __last = temp;
            NF_ASSERT(std::distance(__first, __last) == __n);
        }

        const size_type __elems_after = m_data + m_size - __position;
        iterator __old_finish = m_data + m_size;
        if (__elems_after > __n)
        {
            std::uninitialized_copy(m_data + m_size - __n, m_data + m_size, m_data + m_size);
            m_size += __n;
            std::copy_backward(__position, __old_finish - __n, __old_finish);
            std::copy(__first, __last, __position);
        }
        else
        {
            _ForwardIterator __mid = __first;
            std::advance(__mid, __elems_after);
            std::uninitialized_copy(__mid, __last, m_data + m_size);
            m_size += __n - __elems_after;
            std::uninitialized_copy(__position, __old_finish, m_data + m_size);
            m_size += __elems_after;
            std::copy(__first, __mid, __position);
        }
    }
}