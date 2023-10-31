// -------------------------------------------------------------------------
//    @FileName         :    NFBagPage.h
//    @Author           :    gaoyi
//    @Date             :    23-10-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFBagPage
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFRawShmObj.h"
#include "NFLogicCommon/NFPackageDefine.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFGameCommon/NFComTypeDefine.h"
#include "NFLogicCommon/Item/NFItem.h"
#include "NFLogicCommon/Item/NFItemMgr.h"
#include "Package.pb.h"

typedef std::list<SItem> LIST_ITEM_EX;
// label - LIST_ITEM_EX(标签-物品列表)
typedef std::unordered_map<uint8_t, LIST_ITEM_EX> MAP_LABEL_LIST_ITEM_EX;
// index - SItemEx
typedef std::map<uint16_t, SItem> MAP_INDEX_ITEM_EX;
// label - MAP_INDEX_ITEM_EX
typedef std::map<uint8_t, MAP_INDEX_ITEM_EX> MAP_LABEL_MAP_INDEX_ITEM_EX;

// index - SItem
typedef std::map<uint16_t, SItem> MAP_INDEX_ITEM;

//label - VEC_ITEM_PROTO_EX
typedef std::unordered_map<uint8_t, VEC_ITEM_PROTO_EX> MAP_LABEL_VEC_ITEM_PROTO_EX;
//index - ItemProtoInfo
typedef std::map<uint16_t, proto_ff::ItemProtoInfo> MAP_INDEX_ITEM_PROTO_EX;

template<class ItemType, int MaxGridNum>
class NFBagPage : public NFRawShmObj, public NFSeqOP
{
    typedef NFShmVector<ItemType, MaxGridNum> VEC_PACKAGE_ITEM;
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
        m_nLastSortTime = 0;
        m_nExpandNum = 0;
        m_nOpenGrid = 0;
        m_setIdxRecord.clear();
        m_nPackageType = 0;
        m_initGrid = 0;
        m_maxGrid = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
public:
    int Init(NFShmObj *pShmObj, NFPlayer* pMaster, uint32_t nPackageType, uint32_t nInitGrid);
public:
    int32_t GetPackageType() { return m_nPackageType; }
public:
    //通过索引获取物品
    ItemType *GetItemByIndex(uint16_t nIndex);
    uint16_t SetItemByIndex(uint16_t nIndex, const ItemType& item);
    //获取指定物品数量
    int64_t GetItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum);
    //获取指定物品绑定和非绑定数量
    int64_t GetPackageItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum);
    //获取背包指定物品绑定和非绑定数量
    int64_t GetPackageItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas, ORDER_MAP_UINT16_INT64 &mapBindGridHas);
    
    //获取索引位置物品
    virtual const ItemType *GetItem(uint16_t nIndex);
    //获取第一个指定ID的物品
    virtual ItemType* GetFirstItemById(uint64_t item_id);
    //获取物品（根据tem.xlsx 表中 subType 字段 获取物品, 只返回找到的第一个物品）
    virtual const ItemType *GetItemByType(int32_t itemSubType);
public:
    //是否存在物品
    virtual bool HasItem(LIST_ITEM &lstItem);
    //背包是否存在物品
    bool HasPackageItem(const LIST_ITEM &lstItem, ORDER_MAP_UINT16_INT64 &mapGridReduceNum);
    //背包是否存在物品
    bool HasPackageItem(const MAP_UINT16_INT64 &mapIdxNum, ORDER_MAP_UINT16_INT64 &mapGridReduceNum);
    //是否存在物品
    bool HasBagItem(const LIST_ITEM &lstItem, ORDER_MAP_UINT16_INT64 &mapGridReduceNum);
    //是否存在物品
    bool HasBagItem(const MAP_UINT16_INT64 &mapIdxNum, ORDER_MAP_UINT16_INT64 &mapGridReduceNum);
public:
    //移除物品
    virtual bool RemoveItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind = (int8_t)EBindState::EBindState_all);
    //移除物品 sourceParam : 物品移除来源（暂时没有）
    virtual bool RemoveItem(LIST_ITEM &lstItem, SCommonSource &sourceParam);
    //移除物品 index,num sourceParam : 物品移除来源（暂时没有）
    virtual bool RemoveItemByIndex(uint16_t nIndex, int64_t nNum, SCommonSource &sourceParam);
    //移除物品 index-num nGetType : 物品移除来源（暂时没有）
    virtual bool RemoveItem(MAP_UINT16_INT64 &mapIndexItem, SCommonSource &sourceParam);
    //移除背包物品
    bool RemovePackageItem(ORDER_MAP_UINT16_INT64 &mapGridReduceNum, MAP_UINT64_INT64 &mapItemNum);
    //移除物品
    bool RemoveBagItem(ORDER_MAP_UINT16_INT64 &mapGridReduceNum, MAP_UINT64_INT64 &mapItemNum);
public:
    //是否能添加物品
    virtual bool CanAddItem(LIST_ITEM &lstItem);
    //能否添加物品
    virtual bool CanAddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx);
    //能否添加进背包
    bool CanPackageAddItem(MAP_LABEL_LIST_ITEM_EX &mapInLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapInLabelVecItemProtoEx, MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx);
    //能否添加到背包  mapOutGridAddNum:可堆叠的格子，每个格子上增加的数量 index - num
    bool CanBagAddItem(MAP_LABEL_LIST_ITEM_EX &mapInLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapInLabelVecItemProtoEx, MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx);
public:
    //添加物品
    virtual bool AddItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind = (int8_t)EBindState::EBindState_no);
    //添加物品 sourceParam : 物品来源（暂时没有）
    virtual bool AddItem(LIST_ITEM &lstItem, SCommonSource &sourceParam, bool update = true, bool tip = true);
    
    //添加物品 sourceParam : 物品来源（暂时没有）
    virtual bool AddItem(VEC_ITEM_PROTO &vecProtoItems, SCommonSource &sourceParam, bool update = true, bool tip = true);
    //添加物品 sourceParam : 物品来源（暂时没有）
    virtual bool AddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam, bool update = true, bool tip = true);
    //添加物品 sourceParam : 物品来源（暂时没有）,这个接口是通过传进来的物品顺序添加前端物品tip提示
    virtual bool AddItemEx(VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam);
    //添加物品 sourceParam : 物品来源（暂时没有） vecProtoItemsOut:传出参数，外部需要的物品数据
    virtual bool AddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecProtoItemsOut, SCommonSource &sourceParam, bool update = true, bool tip = true);
    //添加背包物品
    bool AddPackageItem(MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, const VEC_ITEM_PROTO_EX &vecProtoTipItemsEx, bool update = true);
    //添加物品事件处理
    void OnAddItemEvent(MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, SCommonSource &sourceParam);
    //填充传出参数
    void OnAddItemParam(MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, VEC_ITEM_PROTO_EX &vecProtoExParam);
public:
    //清空背包所有物品
    virtual bool ClearPackage();
    //扩展背包
    virtual int32_t Expand(int32_t& nNum);
    virtual int32_t GetMaxGridNum();
    
    //获取某个物品剩余可叠加的数量
    int64_t GetItemLeftPile(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas, ORDER_MAP_UINT16_INT64 &mapBindGridHas);
    //获取某个标签内物品剩余可叠加数量
    int64_t GetLabelItemLeftPile(uint8_t byLabel, uint64_t nItemID, int64_t stackLimit, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas, ORDER_MAP_UINT16_INT64 &mapBindGridHas);
    
public:
    //移除所有指定类型的物品（根据 tem.xlsx 表中 subType 字段 移除物品）
    virtual bool RemoveAllByType(int32_t itemSubType, SCommonSource &sourceParam);
    virtual bool RemoveAllByItemID(uint64_t nItemID, SCommonSource& sourceParam);
    //仓库或背包容量全部开启
    virtual void AllOpenGrid();
    //获取标签页空格子索引列表 nNum:为0表示标签页所有的空格子，大于0时 只返回 nNum 个空格子
    uint32_t GetEmptyGrid(VEC_UINT16 &vecGrid);
    uint32_t GetEmptyGrid();
    bool ValidIndex(uint16_t nIndex){ return nIndex < m_nOpenGrid; }
    void SetPackageSaveFlag(bool bSave=true);
public:
    //设置更新信息
    bool SetUpdateItemInfo(ItemType *pItem, proto_ff::ItemProtoInfo *protoItemInfo, bool bDel = false);
    //添加背包更新信息
    bool AddPackageUpdateInfo(ItemType *pItem, proto_ff::NotifyPackageUpdate &ret, bool bDel = false);
    //更新背包
    void UpdatePackageInfo(proto_ff::NotifyPackageUpdate &protoUpdate);
    //更新扩展
    bool UpdatePackageExpand();
    
    //移除物品事件处理
    void OnRemoveItemEvent(MAP_UINT64_INT64 &mapItemNum, SCommonSource &sourceParam);
    //添加收集物品（主要是用于任务收集物品）
    void AddCollectItem(proto_ff::ItemProtoInfo& itemProto, VEC_ITEM_PROTO_EX& vCollectItems);
    //收集物品事件触发
    void CollectItemEvent(VEC_ITEM_PROTO_EX &vCollectItems, SCommonSource &sourceParam, int32_t nOperateType = EItemOpetateType_None);
    
    //物品日志
    void ItemLog(MAP_UINT16_INT64 &items, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, SCommonSource &source);
    void ItemLog(MAP_UINT64_INT64 &items, SCommonSource &source);
    //清空索引记录
    void ClearIdxRecord();
    //get 索引记录
    SET_UINT16& GetIdxRecord();
    
    uint32_t GetOpenGrid(){ return m_nOpenGrid; }
    bool SortItem();
    bool BagItemSort();
    //堆叠合并
    uint16_t PileMerge(VEC_PACKAGE_ITEM vecItems, VEC_ITEM_PROTO_EX &vecPileProtoEx);
    //
    void ItemSell(proto_ff::PackageSellReq& req);
    void ShentiEquipSell(proto_ff::PackageSellReq& req);
    //处理物品
    void ProcessItem(LIST_ITEM& lstItem, LIST_ITEM& outLstItem, MAP_UINT32_INT64& mapAttr,bool addFlag = false);
    //处理物品
    void ProcessItem(VEC_ITEM_PROTO_EX& vecProtoItemsEx, VEC_ITEM_PROTO_EX& vecOutProtoItemsEx, MAP_UINT32_INT64& mapAttr, bool addFlag);

public:
    //合并背包物品列表
    void MergePackageItemList(LIST_ITEM &inlstItem, VEC_ITEM_PROTO_EX &vecinProtoEx, MAP_LABEL_LIST_ITEM_EX &mapOutLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapOutLabelVecItemProtoEx);
    //合并物品列表
    void MergeItemList(LIST_ITEM &inlstItem, VEC_ITEM_PROTO_EX &vecinProtoEx, MAP_LABEL_LIST_ITEM_EX &mapOutLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapOutLabelVecItemProtoEx);

private:
    uint64_t m_nLastSortTime;                        //上次整理的时间
    uint16_t m_nExpandNum;                            //扩展格子数
    uint16_t m_nOpenGrid;                            //背包开启格子数
    VEC_PACKAGE_ITEM m_vecItems;                    //背包数据
    SET_UINT16 m_setIdxRecord;                        //记录每次加物品 数量有增加的格子索引，在每次加物品之前先清空
    uint16_t m_nPackageType;
    
    int32_t m_initGrid;                                //初始化格子大小
    int32_t m_maxGrid;                                //最大格子大小

protected:
    NFShmPtr<NFPlayer> m_pMaster;
};


template<class ItemType, int MaxGridNum>
int NFBagPage<ItemType, MaxGridNum>::Init(NFShmObj *pShmObj, NFPlayer* pMaster, uint32_t nPackageType, uint32_t nInitGrid)
{
    InitShmObj(pShmObj);
    m_pMaster = pMaster;
    
    CHECK_EXPR(nInitGrid <= MaxGridNum, -1, "nInitGrid:{} maxGridNum:{} Error", nInitGrid, MaxGridNum);
    m_nLastSortTime = 0;
    m_nExpandNum = 0;
    m_nOpenGrid = nInitGrid;
    m_vecItems.resize(MaxGridNum);
    m_setIdxRecord.clear();
    m_nPackageType = nPackageType;
    m_initGrid = nInitGrid;
    m_maxGrid = MaxGridNum;
    return 0;
}

template<class ItemType, int MaxGridNum>
ItemType *NFBagPage<ItemType, MaxGridNum>::GetItemByIndex(uint16_t nIndex)
{
    if (nIndex < m_nOpenGrid)
    {
        return m_vecItems[nIndex];
    }
    return nullptr;
}

template<class ItemType, int MaxGridNum>
uint16_t NFBagPage<ItemType, MaxGridNum>::SetItemByIndex(uint16_t nIndex, const ItemType& item)
{
    if (nIndex < m_nOpenGrid)
    {
        m_vecItems[nIndex] = item;
        return nIndex;
    }
    return -1;
}

template<class ItemType, int MaxGridNum>
int64_t NFBagPage<ItemType, MaxGridNum>::GetItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum)
{
    LIST_ITEM lstOutItem;
    MAP_UINT32_INT64 mapAttr;
    uint32_t attrId = 0;
    if (NFItemMgr::Instance(GetShmObj()->m_pObjPluginManager)->IsVirItem(nItemID, attrId))
    {
        return m_pMaster->GetAttr(attrId);
    }
    
    return GetPackageItemNum(nItemID, nUnBindNum, nBindNum);
}

template<class ItemType, int MaxGridNum>
int64_t NFBagPage<ItemType, MaxGridNum>::GetPackageItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum)
{
    return 0;
}

template<class ItemType, int MaxGridNum>
int64_t NFBagPage<ItemType, MaxGridNum>::GetPackageItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas, ORDER_MAP_UINT16_INT64 &mapBindGridHas)
{
    return 0;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::HasItem(LIST_ITEM &lstItem)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::HasPackageItem(const LIST_ITEM &lstItem, ORDER_MAP_UINT16_INT64 &mapGridReduceNum)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::HasPackageItem(const MAP_UINT16_INT64 &mapIdxNum, ORDER_MAP_UINT16_INT64 &mapGridReduceNum)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::HasBagItem(const LIST_ITEM &lstItem, ORDER_MAP_UINT16_INT64 &mapGridReduceNum)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::HasBagItem(const MAP_UINT16_INT64 &mapIdxNum, ORDER_MAP_UINT16_INT64 &mapGridReduceNum)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::RemoveItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::RemoveItem(LIST_ITEM &lstItem, SCommonSource &sourceParam)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::RemoveItemByIndex(uint16_t nIndex, int64_t nNum, SCommonSource &sourceParam)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::RemoveItem(MAP_UINT16_INT64 &mapIndexItem, SCommonSource &sourceParam)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::RemovePackageItem(ORDER_MAP_UINT16_INT64 &mapGridReduceNum, MAP_UINT64_INT64 &mapItemNum)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::RemoveBagItem(ORDER_MAP_UINT16_INT64 &mapGridReduceNum, MAP_UINT64_INT64 &mapItemNum)
{
    return false;
}

template<class ItemType, int MaxGridNum>
const ItemType *NFBagPage<ItemType, MaxGridNum>::GetItem(uint16_t nIndex)
{
    return nullptr;
}

template<class ItemType, int MaxGridNum>
ItemType *NFBagPage<ItemType, MaxGridNum>::GetFirstItemById(uint64_t item_id)
{
    return nullptr;
}

template<class ItemType, int MaxGridNum>
const ItemType *NFBagPage<ItemType, MaxGridNum>::GetItemByType(int32_t itemSubType)
{
    return nullptr;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::CanAddItem(LIST_ITEM &lstItem)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::CanAddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::CanPackageAddItem(MAP_LABEL_LIST_ITEM_EX &mapInLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapInLabelVecItemProtoEx, MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::CanBagAddItem(MAP_LABEL_LIST_ITEM_EX &mapInLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapInLabelVecItemProtoEx, MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::AddItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::AddItem(LIST_ITEM &lstItem, SCommonSource &sourceParam, bool update, bool tip)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::AddItem(VEC_ITEM_PROTO &vecProtoItems, SCommonSource &sourceParam, bool update, bool tip)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::AddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam, bool update, bool tip)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::AddItemEx(VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::AddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecProtoItemsOut, SCommonSource &sourceParam, bool update, bool tip)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::AddPackageItem(MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, const VEC_ITEM_PROTO_EX &vecProtoTipItemsEx, bool update)
{
    return false;
}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::OnAddItemEvent(MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, SCommonSource &sourceParam)
{

}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::OnAddItemParam(MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, VEC_ITEM_PROTO_EX &vecProtoExParam)
{

}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::ClearPackage()
{
    return false;
}

template<class ItemType, int MaxGridNum>
int32_t NFBagPage<ItemType, MaxGridNum>::Expand(int32_t &nNum)
{
    return 0;
}

template<class ItemType, int MaxGridNum>
int32_t NFBagPage<ItemType, MaxGridNum>::GetMaxGridNum()
{
    return 0;
}

template<class ItemType, int MaxGridNum>
int64_t NFBagPage<ItemType, MaxGridNum>::GetItemLeftPile(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas, ORDER_MAP_UINT16_INT64 &mapBindGridHas)
{
    return 0;
}

template<class ItemType, int MaxGridNum>
int64_t NFBagPage<ItemType, MaxGridNum>::GetLabelItemLeftPile(uint8_t byLabel, uint64_t nItemID, int64_t stackLimit, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas, ORDER_MAP_UINT16_INT64 &mapBindGridHas)
{
    return 0;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::RemoveAllByType(int32_t itemSubType, SCommonSource &sourceParam)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::RemoveAllByItemID(uint64_t nItemID, SCommonSource &sourceParam)
{
    return false;
}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::AllOpenGrid()
{

}

template<class ItemType, int MaxGridNum>
uint32_t NFBagPage<ItemType, MaxGridNum>::GetEmptyGrid(VEC_UINT16 &vecGrid)
{
    return 0;
}

template<class ItemType, int MaxGridNum>
uint32_t NFBagPage<ItemType, MaxGridNum>::GetEmptyGrid()
{
    return 0;
}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::SetPackageSaveFlag(bool bSave)
{

}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::SetUpdateItemInfo(ItemType *pItem, proto_ff::ItemProtoInfo *protoItemInfo, bool bDel)
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::AddPackageUpdateInfo(ItemType *pItem, proto_ff::NotifyPackageUpdate &ret, bool bDel)
{
    return false;
}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::UpdatePackageInfo(proto_ff::NotifyPackageUpdate &protoUpdate)
{

}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::UpdatePackageExpand()
{
    return false;
}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::OnRemoveItemEvent(MAP_UINT64_INT64 &mapItemNum, SCommonSource &sourceParam)
{

}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::AddCollectItem(proto_ff::ItemProtoInfo &itemProto, VEC_ITEM_PROTO_EX &vCollectItems)
{

}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::CollectItemEvent(VEC_ITEM_PROTO_EX &vCollectItems, SCommonSource &sourceParam, int32_t nOperateType)
{

}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::ItemLog(MAP_UINT16_INT64 &items, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, SCommonSource &source)
{

}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::ItemLog(MAP_UINT64_INT64 &items, SCommonSource &source)
{

}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::ClearIdxRecord()
{

}

template<class ItemType, int MaxGridNum>
SET_UINT16 &NFBagPage<ItemType, MaxGridNum>::GetIdxRecord()
{
    return m_setIdxRecord;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::SortItem()
{
    return false;
}

template<class ItemType, int MaxGridNum>
bool NFBagPage<ItemType, MaxGridNum>::BagItemSort()
{
    return false;
}

template<class ItemType, int MaxGridNum>
uint16_t NFBagPage<ItemType, MaxGridNum>::PileMerge(NFBagPage::VEC_PACKAGE_ITEM vecItems, VEC_ITEM_PROTO_EX &vecPileProtoEx)
{
    return 0;
}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::ItemSell(proto_ff::PackageSellReq &req)
{

}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::ShentiEquipSell(proto_ff::PackageSellReq &req)
{

}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::ProcessItem(LIST_ITEM &lstItem, LIST_ITEM &outLstItem, MAP_UINT32_INT64 &mapAttr, bool addFlag)
{

}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::ProcessItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecOutProtoItemsEx, MAP_UINT32_INT64 &mapAttr, bool addFlag)
{

}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::MergePackageItemList(LIST_ITEM &inlstItem, VEC_ITEM_PROTO_EX &vecinProtoEx, MAP_LABEL_LIST_ITEM_EX &mapOutLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapOutLabelVecItemProtoEx)
{

}

template<class ItemType, int MaxGridNum>
void NFBagPage<ItemType, MaxGridNum>::MergeItemList(LIST_ITEM &inlstItem, VEC_ITEM_PROTO_EX &vecinProtoEx, MAP_LABEL_LIST_ITEM_EX &mapOutLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapOutLabelVecItemProtoEx)
{

}
