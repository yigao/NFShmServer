// -------------------------------------------------------------------------
//    @FileName         :    NFPackageBag.h
//    @Author           :    gaoyi
//    @Date             :    23-11-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFPackageBag
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFRawShmObj.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFLogicCommon/NFPackageDefine.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFGameCommon/NFComTypeDefine.h"
#include "NFLogicCommon/Item/NFItem.h"
#include "NFLogicCommon/Item/NFItemMgr.h"
#include "Package.pb.h"
#include "NFLogicCommon/NFLogDefine.h"
#include "DescStoreEx/ItemDescEx.h"
#include "Facade/NFDeityPart.h"

class NFPlayer;

class NFPackageBag : public NFRawShmObj
{
public:
    //扩展物品结构(临时计算用的中间结构)
    struct SItemEx : public SItem
    {
        int64_t stackNum;    //堆叠数量
        uint8_t byType;        //类型 EItemType 枚举
        SItemEx() : stackNum(0), byType(0) {}
    };
    
    typedef std::list<SItemEx> LIST_ITEM_EX;
// index - SItemEx
    typedef std::map<uint16_t, SItemEx> MAP_INDEX_ITEM_EX;
// label - MAP_INDEX_ITEM_EX
    typedef std::map<uint8_t, MAP_INDEX_ITEM_EX> MAP_LABEL_MAP_INDEX_ITEM_EX;

// index - SItem
    typedef std::map<uint16_t, SItem> MAP_INDEX_ITEM;

//label - VEC_ITEM_PROTO_EX
    typedef std::unordered_map<uint8_t, VEC_ITEM_PROTO_EX> MAP_LABEL_VEC_ITEM_PROTO_EX;
//index - ItemProtoInfo
    typedef std::map<uint16_t, proto_ff::ItemProtoInfo> MAP_INDEX_ITEM_PROTO_EX;
// label - LIST_ITEM_EX(标签-物品列表)
    typedef std::unordered_map<uint8_t, LIST_ITEM_EX> MAP_LABEL_LIST_ITEM_EX;
public:
    NFPackageBag();
    
    virtual ~NFPackageBag();
    
    int CreateInit();
    int ResumeInit();
public:
    virtual int Init(NFShmObj *pShmObj, NFPlayer *pMaster);
    
    virtual int LoadFromDB(const proto_ff::RoleDBUnitBagData* pUnitBagData);
    
    virtual int32_t GetPackageType() { return m_nPackageType; }
    
    virtual uint32_t GetOpenGrid() { return m_nOpenGrid; }
    
    virtual bool ValidIndex(uint16_t nIndex) { return nIndex < m_nOpenGrid; }
    
    virtual void SetPackageSaveFlag(bool bSave = true);
    
    void SendPackageInfoToClient();
    
    void Save(proto_ff::RoleDBUnitBagData& bagData);
public:
    //通过索引获取物品
    virtual bool IsEmptyGridByIndex(uint16_t nIndex) = 0;
    virtual NFItem *GetItemByIndex(uint16_t nIndex) = 0;
    virtual uint16_t SetItemByIndex(uint16_t nIndex, const NFItem &item) = 0;
    virtual uint16_t SetItemByIndex(uint16_t nIndex, const NFItem *pItem) = 0;
    //获取指定物品数量
    virtual int64_t GetItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum);
    //获取指定物品绑定和非绑定数量
    virtual int64_t GetPackageItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum);
    //获取背包指定物品绑定和非绑定数量
    virtual int64_t GetPackageItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas, ORDER_MAP_UINT16_INT64 &mapBindGridHas);
    
    //获取索引位置物品
    virtual const NFItem *GetItem(uint16_t nIndex);
    //获取第一个指定ID的物品
    virtual NFItem *GetFirstItemById(uint64_t item_id);
    //获取物品（根据tem.xlsx 表中 subType 字段 获取物品, 只返回找到的第一个物品）
    virtual const NFItem *GetItemByType(int32_t itemSubType);
public:
    //是否存在物品
    virtual bool HasItem(const LIST_ITEM &lstItem);
    //背包是否存在物品
    virtual bool HasPackageItem(const LIST_ITEM &lstItem, ORDER_MAP_UINT16_INT64 &mapGridReduceNum);
    //背包是否存在物品
    virtual bool HasPackageItem(const MAP_UINT16_INT64 &mapIdxNum, ORDER_MAP_UINT16_INT64 &mapGridReduceNum);
    //是否存在物品
    virtual bool HasBagItem(const LIST_ITEM &lstItem, ORDER_MAP_UINT16_INT64 &mapGridReduceNum);
    //是否存在物品
    virtual bool HasBagItem(const MAP_UINT16_INT64 &mapIdxNum, ORDER_MAP_UINT16_INT64 &mapGridReduceNum);
public:
    //移除物品
    virtual bool RemoveItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind = (int8_t) EBindState::EBindState_all);
    //移除物品 sourceParam : 物品移除来源（暂时没有）
    virtual bool RemoveItem(LIST_ITEM &lstItem, SCommonSource &sourceParam);
    //移除物品 index,num sourceParam : 物品移除来源（暂时没有）
    virtual bool RemoveItemByIndex(uint16_t nIndex, int64_t nNum, SCommonSource &sourceParam);
    //移除物品 index-num nGetType : 物品移除来源（暂时没有）
    virtual bool RemoveItem(MAP_UINT16_INT64 &mapIndexItem, SCommonSource &sourceParam);
    //移除背包物品
    virtual bool RemovePackageItem(ORDER_MAP_UINT16_INT64 &mapGridReduceNum, MAP_UINT64_INT64 &mapItemNum);
    //移除物品
    virtual bool RemoveBagItem(ORDER_MAP_UINT16_INT64 &mapGridReduceNum, MAP_UINT64_INT64 &mapItemNum);
public:
    //是否能添加物品
    virtual bool CanAddItem(LIST_ITEM &lstItem);
    //能否添加物品
    virtual bool CanAddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx);
    //能否添加进背包
    virtual bool CanPackageAddItem(MAP_LABEL_LIST_ITEM_EX &mapInLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapInLabelVecItemProtoEx, MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx);
    //能否添加到背包  mapOutGridAddNum:可堆叠的格子，每个格子上增加的数量 index - num
    virtual bool CanBagAddItem(MAP_LABEL_LIST_ITEM_EX &mapInLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapInLabelVecItemProtoEx, MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx);
public:
    //添加物品
    virtual bool AddItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind = (int8_t) EBindState::EBindState_no);
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
    virtual bool AddPackageItem(MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, const VEC_ITEM_PROTO_EX &vecProtoTipItemsEx, bool update = true);
    //添加物品事件处理
    virtual void OnAddItemEvent(MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, SCommonSource &sourceParam);
    //填充传出参数
    virtual void OnAddItemParam(MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, VEC_ITEM_PROTO_EX &vecProtoExParam);
public:
    //清空背包所有物品
    virtual bool ClearPackage();
    //扩展背包
    virtual int32_t Expand(int32_t &nNum);
    virtual int32_t GetMaxGridNum();
    
    //获取某个物品剩余可叠加的数量
    virtual int64_t GetItemLeftPile(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas, ORDER_MAP_UINT16_INT64 &mapBindGridHas);
    //获取某个标签内物品剩余可叠加数量
    virtual int64_t GetLabelItemLeftPile(uint8_t byLabel, uint64_t nItemID, int64_t stackLimit, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas, ORDER_MAP_UINT16_INT64 &mapBindGridHas);

public:
    //移除所有指定类型的物品（根据 tem.xlsx 表中 subType 字段 移除物品）
    virtual bool RemoveAllByType(int32_t itemSubType, SCommonSource &sourceParam);
    virtual bool RemoveAllByItemID(uint64_t nItemID, SCommonSource &sourceParam);
    //仓库或背包容量全部开启
    virtual void AllOpenGrid();
    //获取标签页空格子索引列表 nNum:为0表示标签页所有的空格子，大于0时 只返回 nNum 个空格子
    virtual uint32_t GetEmptyGrid(VEC_UINT16 &vecGrid);
    virtual uint32_t GetEmptyGrid();

public:
    //设置更新信息
    virtual bool SetUpdateItemInfo(NFItem *pItem, proto_ff::ItemProtoInfo *protoItemInfo, bool bDel = false);
    //添加背包更新信息
    virtual bool AddPackageUpdateInfo(NFItem *pItem, proto_ff::NotifyPackageUpdate &ret, bool bDel = false);
    //更新背包
    virtual void UpdatePackageInfo(proto_ff::NotifyPackageUpdate &protoUpdate);
    //更新扩展
    virtual bool UpdatePackageExpand();
    
    //移除物品事件处理
    virtual void OnRemoveItemEvent(MAP_UINT64_INT64 &mapItemNum, SCommonSource &sourceParam);
    //添加收集物品（主要是用于任务收集物品）
    virtual void AddCollectItem(proto_ff::ItemProtoInfo &itemProto, VEC_ITEM_PROTO_EX &vCollectItems);
    //收集物品事件触发
    virtual void CollectItemEvent(VEC_ITEM_PROTO_EX &vCollectItems, SCommonSource &sourceParam, int32_t nOperateType = EItemOpetateType_None);
    
    //物品日志
    virtual void ItemLog(MAP_UINT16_INT64 &items, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, SCommonSource &source);
    virtual void ItemLog(MAP_UINT64_INT64 &items, SCommonSource &source);
    //清空索引记录
    virtual void ClearIdxRecord();
    //get 索引记录
    virtual SET_UINT16 &GetIdxRecord();

public:
    virtual bool SortItem();
    virtual bool BagItemSort();
    //堆叠合并
    uint16_t PileMerge(VEC_PACKAGE_ITEM vecItems, VEC_ITEM_PROTO_EX &vecPileProtoEx);
public:
    //
    virtual void ItemSell(proto_ff::PackageSellReq &req);
    //处理物品
    virtual void ProcessItem(const LIST_ITEM &lstItem, LIST_ITEM &outLstItem, MAP_UINT32_INT64 &mapAttr, bool addFlag = false);
    //处理物品
    virtual void ProcessItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecOutProtoItemsEx, MAP_UINT32_INT64 &mapAttr, bool addFlag);

public:
    //合并背包物品列表
    virtual void MergePackageItemList(LIST_ITEM &inlstItem, VEC_ITEM_PROTO_EX &vecinProtoEx, MAP_LABEL_LIST_ITEM_EX &mapOutLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapOutLabelVecItemProtoEx);
    //合并物品列表
    virtual void MergeItemList(LIST_ITEM &inlstItem, VEC_ITEM_PROTO_EX &vecinProtoEx, MAP_LABEL_LIST_ITEM_EX &mapOutLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapOutLabelVecItemProtoEx);
public:
    uint64_t calcDynExp(int32_t type, int32_t num);
protected:
    uint64_t m_nLastSortTime;                        //上次整理的时间
    uint16_t m_nExpandNum;                            //扩展格子数
    uint16_t m_nOpenGrid;                            //背包开启格子数
    uint16_t m_nPackageType;
    
    int32_t m_initGrid;                                //初始化格子大小
    int32_t m_maxGrid;                                //最大格子大小
    NFShmPtr<NFPlayer> m_pMaster;
    SET_UINT16 m_setIdxRecord;                        //记录每次加物品 数量有增加的格子索引，在每次加物品之前先清空
};