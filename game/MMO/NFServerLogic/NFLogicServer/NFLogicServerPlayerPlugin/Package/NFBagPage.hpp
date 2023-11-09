// -------------------------------------------------------------------------
//    @FileName         :    NFBagPage.h
//    @Author           :    gaoyi
//    @Date             :    23-10-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFBagPage
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPackageBag.h"

template<class ItemType, int nPackageType, int InitGridNum, int MaxGridNum>
class NFBagPage : public NFPackageBag
{
    static_assert(InitGridNum <= MaxGridNum, "InitGridNum > MaxGridNum");
    static_assert(!(std::is_base_of<ItemType, NFItem>::value || std::is_same<ItemType, NFItem>::value), "ItemType is not base of NFItemBase");
    typedef NFShmVector<ItemType, MaxGridNum> BAG_VEC_PACKAGE_ITEM;
public:
    NFBagPage()
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
    
    virtual ~NFBagPage()
    {
    
    }
    
    int CreateInit()
    {
        
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }

public:
    virtual int Init(NFShmObj *pShmObj, NFPlayer *pMaster);
public:
    //通过索引获取物品
    virtual bool IsEmptyGridByIndex(uint16_t nIndex);
    virtual NFItem *GetItemByIndex(uint16_t nIndex);
    virtual uint16_t SetItemByIndex(uint16_t nIndex, const NFItem &item);
    virtual uint16_t SetItemByIndex(uint16_t nIndex, const NFItem *pItem);
protected:
    BAG_VEC_PACKAGE_ITEM m_vecItems;                    //背包数据
};

template<class ItemType, int nPackageType, int InitGridNum, int MaxGridNum>
int NFBagPage<ItemType, nPackageType, InitGridNum, MaxGridNum>::Init(NFShmObj *pShmObj, NFPlayer *pMaster)
{
    NFPackageBag::Init(pShmObj, pMaster);
    m_nLastSortTime = 0;
    m_nExpandNum = 0;
    m_nOpenGrid = InitGridNum;
    m_nPackageType = nPackageType;
    m_initGrid = InitGridNum;
    m_maxGrid = MaxGridNum;
    m_vecItems.resize(MaxGridNum);
    
    return 0;
}

template<class ItemType, int nPackageType, int InitGridNum, int MaxGridNum>
bool NFBagPage<ItemType, nPackageType, InitGridNum, MaxGridNum>::IsEmptyGridByIndex(uint16_t nIndex)
{
    if (nIndex < m_nOpenGrid)
    {
        if (m_vecItems[nIndex].GetItemID() > 0)
        {
            return false;
        }
    }
    return true;
}

template<class ItemType, int nPackageType, int InitGridNum, int MaxGridNum>
NFItem *NFBagPage<ItemType, nPackageType, InitGridNum, MaxGridNum>::GetItemByIndex(uint16_t nIndex)
{
    if (nIndex < m_nOpenGrid)
    {
        if (m_vecItems[nIndex].GetItemID() > 0)
        {
            return &m_vecItems[nIndex];
        }
    }
    return nullptr;
}

template<class ItemType, int nPackageType, int InitGridNum, int MaxGridNum>
uint16_t NFBagPage<ItemType, nPackageType, InitGridNum, MaxGridNum>::SetItemByIndex(uint16_t nIndex, const NFItem &item)
{
    if (nIndex < m_nOpenGrid)
    {
        m_vecItems[nIndex] = item;
        return nIndex;
    }
    return -1;
}

template<class ItemType, int nPackageType, int InitGridNum, int MaxGridNum>
uint16_t NFBagPage<ItemType, nPackageType, InitGridNum, MaxGridNum>::SetItemByIndex(uint16_t nIndex, const NFItem *pItem)
{
    if (pItem)
    {
        SetItemByIndex(nIndex, *pItem);
    }
    else {
        if (nIndex < m_nOpenGrid)
        {
            m_vecItems[nIndex].Clear();
            return nIndex;
        }
    }
    return 0;
}