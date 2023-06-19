// -------------------------------------------------------------------------
//    @FileName         :    NFShmObjIterator.h
//    @Author           :    gaoyi
//    @Date             :    23-6-13
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmObjIterator
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"

class NFShmObj;

template<class Tp, class Ref, class Ptr, class Container>
struct NFShmObjIterator
{
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;

    typedef NFShmObjIterator<Tp, Tp &, Tp *, Container> iterator;
    typedef NFShmObjIterator<Tp, const Tp &, const Tp *, Container> const_iterator;
    typedef NFShmObjIterator<Tp, Ref, Ptr, Container> _Self;

    typedef Tp value_type;
    typedef Ptr pointer;
    typedef Ref reference;

    Container *m_pContainer;
    int m_type;
    size_t m_pos;

    explicit NFShmObjIterator(const Container *pContainer, int type, size_t pos)
            : m_pContainer(const_cast<Container *>(pContainer)), m_type(type), m_pos(pos)
    {
    }

    NFShmObjIterator() : m_pContainer(NULL), m_type(0), m_pos(0) {}

    NFShmObjIterator(const iterator &__x) : NFShmObjIterator(__x.m_pContainer, __x.m_type, __x.m_pos)
    {

    }

    template<class Tpx>
    NFShmObjIterator(const NFShmObjIterator<Tpx, Tpx &, Tpx *, Container> &__x) : NFShmObjIterator(__x.m_pContainer, __x.m_type, __x.m_pos)
    {

    }

    reference operator*() const { return *(dynamic_cast<pointer>(m_pContainer->GetIterObj(m_type, m_pos))); }

    pointer operator->() const { return dynamic_cast<pointer>(m_pContainer->GetIterObj(m_type, m_pos)); }

    pointer GetObj() const { return dynamic_cast<pointer>(m_pContainer->GetIterObj(m_type, m_pos)); }

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

    void _M_incr() { m_pos = m_pContainer->IterIncr(m_type, m_pos); }

    void _M_decr() { m_pos = m_pContainer->IterDecr(m_type, m_pos); }

    bool operator==(const NFShmObjIterator &__x) const
    {
        return m_pContainer == __x.m_pContainer && m_type == __x.m_type && m_pos == __x.m_pos;
    }

    bool operator!=(const NFShmObjIterator &__x) const
    {
        return !(m_pContainer == __x.m_pContainer && m_type == __x.m_type && m_pos == __x.m_pos);
    }

    NFShmObjIterator& operator=(const NFShmObjIterator &__x)
    {
        if (this != &__x)
        {
            m_pContainer = __x.m_pContainer;
            m_type = __x.m_type;
            m_pos = __x.m_pos;
        }

        return *this;
    }
};