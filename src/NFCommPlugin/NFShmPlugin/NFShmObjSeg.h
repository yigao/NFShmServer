// -------------------------------------------------------------------------
//    @FileName         :    NFObjSeg.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmHashObjectMgr.h"
#include "NFComm/NFPluginModule/NFObject.h"
#include "NFComm/NFShmCore/NFArray.h"
#include "NFComm/NFShmStl/NFShmDyList.h"
#include "NFComm/NFShmStl/NFShmDyVector.h"
#include "NFComm/NFShmStl/NFShmDyHashMapWithList.h"
#include "NFShmIdx.h"

class NFShmObj;

class NFShmObjSeg;

template<class Tp, class Ref, class Ptr, class Container>
struct NFShmObjSegIterator
{
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;

    typedef NFShmObjSegIterator<Tp, Tp &, Tp *, Container> iterator;
    typedef NFShmObjSegIterator<Tp, const Tp &, const Tp *, Container> const_iterator;
    typedef NFShmObjSegIterator<Tp, Ref, Ptr, Container> _Self;

    typedef Tp value_type;
    typedef Ptr pointer;
    typedef Ref reference;

    Container *m_pContainer;
    NFShmDyList<NFShmIdx>::iterator m_iter;

    explicit NFShmObjSegIterator(const Container *pContainer, NFShmDyList<NFShmIdx>::iterator iter)
            : m_pContainer(const_cast<Container *>(pContainer)), m_iter(iter)
    {
    }

    explicit NFShmObjSegIterator(const Container *pContainer, NFShmDyList<NFShmIdx>::const_iterator iter)
            : m_pContainer(const_cast<Container *>(pContainer)), m_iter(iter.m_pContainer, iter.m_node)
    {
    }

    NFShmObjSegIterator() : m_pContainer(NULL) {}

    NFShmObjSegIterator(const iterator &__x) : NFShmObjSegIterator(__x.m_pContainer, __x.m_iter)
    {

    }

    reference operator*() const { return *(m_iter->GetAttachedObj()); }

    pointer operator->() const { return &(operator*()); }

    pointer GetShmObj() const { return m_iter->GetAttachedObj(); }

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

    void _M_incr() { m_iter._M_incr(); }

    void _M_decr() { m_iter._M_decr(); }

    bool operator==(const NFShmObjSegIterator &__x) const
    {
        return m_pContainer == __x.m_pContainer && m_iter == __x.m_iter;
    }

    bool operator!=(const NFShmObjSegIterator &__x) const
    {
        return !(m_pContainer == __x.m_pContainer && m_iter == __x.m_iter);
    }
};

class NFShmObjSeg : public NFObject
{
    friend class NFCSharedMemModule;
public:
public:
    typedef NFShmObjSegIterator<NFShmObj, NFShmObj &, NFShmObj *, NFShmObjSeg> iterator;
    typedef NFShmObjSegIterator<NFShmObj, const NFShmObj &, const NFShmObj *, NFShmObjSeg> const_iterator;

    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
public:
    static void *operator new(size_t nSize, void *pBuffer) throw();

    static NFShmObjSeg *CreateObject(NFIPluginManager *pPluginManager);

    static void operator delete(void *pSeg);
public:
    int FormatObj();                        //格式化对象区

    void *AllocMemForObject();

    void FreeMemForObject(void *pMem);

    int CreateObject();
public:
    int HashInsert(ShmObjHashKey key, int objId);

    NFShmObj *HashFind(ShmObjHashKey key);

    int HashErase(ShmObjHashKey key);
public:
    NFShmObj *GetObj(int iIdx);

    NFShmIdx *GetIdx(int iIdx);

    int GetObjId(void *pstObj);
public:
    NFShmObj *GetHeadObj();

    NFShmObj *GetNextObj(NFShmObj *pObj);

    bool IsEnd(int iIndex);
public:
    int GetItemCount() const { return m_iItemCount; }

    int GetUsedCount() const { return m_idxLst.size(); }

    int GetFreeCount() const { return m_iItemCount - GetUsedCount(); }

    int GetObjSize() const { return m_nObjSize; }

    int GetMemSize() const { return m_nMemSize; }

    int GetAllSize() const { return m_nMemSize + sizeof(NFShmObjSeg); }

    static int GetHashSize(int itemCount) { return NFShmDyHashMapWithList<uint64_t, int>::CountSize(itemCount); }
public:
    iterator begin() { return iterator(this, m_idxLst.begin()); }

    const_iterator begin() const { return const_iterator(this, m_idxLst.begin()); }

    iterator end() { return iterator(this, m_idxLst.end()); }

    const_iterator end() const { return iterator(this, m_idxLst.end()); }

    reverse_iterator rbegin() { return reverse_iterator(end()); }

    const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

    reverse_iterator rend() { return reverse_iterator(begin()); }

    const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }
public:
    /**
     * @brief ShmObj类链表迭代器+1
     * @param iType
     * @param iPos
     * @return
     */
    virtual size_t IterIncr(size_t iPos)
    {
        auto iter = m_idxLst.GetIterator(iPos);
        iter++;
        return iter.m_node->m_self;
    }

    /**
     * @brief ShmObj类链表迭代器-1
     * @param iType
     * @param iPos
     * @return
     */
    virtual size_t IterDecr(size_t iPos)
    {
        auto iter = m_idxLst.GetIterator(iPos);
        iter--;
        return iter.m_node->m_self;
    }

    virtual size_t IterBegin()
    {
        auto iter = m_idxLst.begin();
        return iter.m_node->m_self;
    }

    virtual size_t IterEnd()
    {
        auto iter = m_idxLst.end();
        return iter.m_node->m_self;
    }

    virtual size_t IterNext(size_t iPos)
    {
        auto iter = m_idxLst.GetIterator(iPos);
        iter++;
        return iter.m_node->m_self;
    }

    virtual NFShmObj* GetIterObj(size_t iPos)
    {
        auto iter = m_idxLst.GetIterator(iPos);
        return iter->GetAttachedObj();
    }

    virtual const NFShmObj* GetIterObj(size_t iPos) const
    {
        auto iter = m_idxLst.GetIterator(iPos);
        return iter->GetAttachedObj();
    }
protected:
    NFShmIdx *CreateIdx();

    int DestroyIdx(int iIdx);
private:
    NFShmObjSeg(NFIPluginManager *p);

    ~NFShmObjSeg();

    int SetAndInitObj(size_t nObjSize, int iItemCount, NFShmObj *(*pfCreateObj)(NFIPluginManager *, void *), bool iUseHash = false);

    size_t m_nObjSize;
    size_t m_nMemSize;
    NFShmDyList<NFShmIdx> m_idxLst;
    NFShmObj *m_pObjs;
    NFShmDyHashMapWithList<ShmObjHashKey, int> m_hashMgr;
    int m_iItemCount;
    bool m_iUseHash;

    NFShmObj *(*m_pCreateFn)(NFIPluginManager *, void *);
};


