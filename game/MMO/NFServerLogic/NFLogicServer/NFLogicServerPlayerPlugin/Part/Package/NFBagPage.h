// -------------------------------------------------------------------------
//    @FileName         :    NFBagPage.h
//    @Author           :    gaoyi
//    @Date             :    22-11-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFBagPage
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFItemDefine.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "Part/Item/NFItemMgr.h"
#include "NFLogicCommon/NFLogDefine.h"
#include "NFLogicCommon/PackageDefine.h"
#include "Package.pb.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "DBProto.pb.h"
#include "CSPlayer.pb.h"

class NFPlayer;
class NFBagPage : public NFObject, public NFSeqOP
{
    typedef std::list<SItem> LIST_ITEM_EX;
    // label - LIST_ITEM_EX(标签-物品列表)
    typedef std::unordered_map<uint8_t, LIST_ITEM_EX> MAP_LABEL_LIST_ITEM_EX;
    // index - SItemEx
    typedef std::map<uint16_t, SItem> MAP_INDEX_ITEM_EX;
    // label - MAP_INDEX_ITEM_EX
    typedef std::map<uint8_t, MAP_INDEX_ITEM_EX > MAP_LABEL_MAP_INDEX_ITEM_EX;

    // index - SItem
    typedef std::map<uint16_t, SItem> MAP_INDEX_ITEM;

    //label - VEC_ITEM_PROTO_EX
    typedef std::unordered_map<uint8_t, VEC_ITEM_PROTO_EX> MAP_LABEL_VEC_ITEM_PROTO_EX;
    //index - ItemProtoInfo
    typedef std::map<uint16_t, proto_ff::ItemProtoInfo> MAP_INDEX_ITEM_PROTO_EX;
public:
    NFShmVector<NFGridItem, STORAGE_PACKAGE_MAX_GRID_NUM> m_grids;
    uint64_t m_nLastSortTime;						//上次整理的时间
    uint32_t m_nExpandNum;							//扩展格子数
    uint32_t m_nOpenGrid;							//背包开启格子数
    uint32_t m_initGrid;							//初始化格子大小
    uint32_t m_maxGrid;								//最大格子大小
    uint32_t m_nPackageType;
    NFShmPtr<NFPlayer> m_pMaster;
public:
    NFBagPage(NFIPluginManager* pPluginManager);

    virtual ~NFBagPage();

    int CreateInit();

    int ResumeInit();

    virtual int InitGrid(NFPlayer *pMaster, uint32_t nPackageType,uint32_t nInitGrid,uint32_t nMaxGrid);
public:
    virtual int Init(const proto_ff::RoleDBUnitBagData &dbData);

    //生物uint调用
    virtual int UnInit();

    /**
     * @brief 存储DB部件入口
     * @param proto
     * @return
     */
    virtual int SaveDB(proto_ff::RoleDBUnitBagData &dbData);

    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin() { return 0; }

    /**
     * @brief  登陆入口
     * @param playerInfo
     * @return
     */
    virtual int OnLogin(proto_ff::PlayerInfoRsp &playerInfo);

    void SendPackageInfoToClient();

    //堆叠合并
    uint16_t PileMerge(VEC_PACKAGE_ITEM vecItems, VEC_ITEM_PROTO_EX &vecPileProtoEx);
public:
    //获取指定物品数量
    int64_t GetItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum);
    //获取指定物品绑定和非绑定数量
    int64_t GetPackageItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum);
    //获取背包指定物品绑定和非绑定数量
    int64_t GetPackageItemNum(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas, ORDER_MAP_UINT16_INT64 &mapBindGridHas);

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

    //移除所有指定类型的物品（根据 tem.xlsx 表中 subType 字段 移除物品）
    virtual bool RemoveAllByType(int32_t itemSubType, SCommonSource &sourceParam);
    virtual bool RemoveAllByItemID(uint64_t nItemID, SCommonSource& sourceParam);
public:
    //添加物品
    virtual int AddItem(uint64_t nItemID, int64_t nNum, SCommonSource &sourceParam, int8_t byBind = (int8_t)EBindState::EBindState_no);
    //添加物品 sourceParam : 物品来源（暂时没有）
    virtual int AddItem(const LIST_ITEM &lstItem, SCommonSource &sourceParam, bool update = true, bool tip = true);

    //添加物品 sourceParam : 物品来源（暂时没有）
    virtual bool AddItem(const VEC_ITEM_PROTO &vecProtoItems, SCommonSource &sourceParam, bool update = true, bool tip = true);
    //添加物品 sourceParam : 物品来源（暂时没有）
    virtual bool AddItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam, bool update = true, bool tip = true);
    //添加物品 sourceParam : 物品来源（暂时没有）,这个接口是通过传进来的物品顺序添加前端物品tip提示
    virtual bool AddItemEx(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, SCommonSource &sourceParam);
    //添加物品 sourceParam : 物品来源（暂时没有） vecProtoItemsOut:传出参数，外部需要的物品数据
    virtual bool AddItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, const VEC_ITEM_PROTO_EX &vecProtoItemsOut, SCommonSource &sourceParam, bool update = true, bool tip = true);
public:
    //合并背包物品列表
    void MergePackageItemList(const LIST_ITEM &inlstItem, const VEC_ITEM_PROTO_EX &vecinProtoEx, MAP_LABEL_LIST_ITEM_EX &mapOutLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapOutLabelVecItemProtoEx);
    //合并物品列表
    void MergeItemList(const LIST_ITEM &inlstItem, const VEC_ITEM_PROTO_EX &vecinProtoEx, MAP_LABEL_LIST_ITEM_EX &mapOutLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapOutLabelVecItemProtoEx);

    //是否能添加物品
    virtual bool CanAddItem(LIST_ITEM &lstItem);
    //能否添加物品
    virtual bool CanAddItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx);
    //能否添加进背包
    bool CanPackageAddItem(MAP_LABEL_LIST_ITEM_EX &mapInLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapInLabelVecItemProtoEx, MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx);
    //能否添加到背包  mapOutGridAddNum:可堆叠的格子，每个格子上增加的数量 index - num
    bool CanBagAddItem(MAP_LABEL_LIST_ITEM_EX &mapInLabelItem, MAP_LABEL_VEC_ITEM_PROTO_EX &mapInLabelVecItemProtoEx, MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx);
    //添加背包物品
    bool AddPackageItem(MAP_UINT16_INT64 &mapOutGridAddNum, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, const VEC_ITEM_PROTO_EX &vecProtoTipItemsEx, bool update = true);

    //获取某个物品剩余可叠加的数量
    int64_t GetItemLeftPile(uint64_t nItemID, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas, ORDER_MAP_UINT16_INT64 &mapBindGridHas);
    //获取某个标签内物品剩余可叠加数量
    int64_t GetLabelItemLeftPile(uint8_t byLabel, uint64_t nItemID, int64_t stackLimit, int64_t &nUnBindNum, int64_t &nBindNum, ORDER_MAP_UINT16_INT64 &mapUnbindGridHas, ORDER_MAP_UINT16_INT64 &mapBindGridHas);

public:
    NFGridItem* GetItemByIndex(uint32_t nIndex);
    int SetItemByIndex(uint32_t nIndex, NFGridItem* pItem);
    int SetItemByIndex(uint32_t nIndex, const proto_ff::ItemProtoInfo &protoItem);

    //获取标签页空格子索引列表 nNum:为0表示标签页所有的空格子，大于0时 只返回 nNum 个空格子
    uint32_t GetEmptyGrid(VEC_UINT32 &vecGrid);
    void UpdatePackageInfo(proto_ff::NotifyPackageUpdate &protoUpdate);
    bool AddPackageUpdateInfo(NFGridItem *pItem, proto_ff::NotifyPackageUpdate &ret, bool bDel = false);
    bool SetUpdateItemInfo(NFGridItem *pItem, proto_ff::ItemProtoInfo *protoItemInfo, bool bDel = false);
public:
    //移除物品事件处理
    void OnRemoveItemEvent(MAP_UINT64_INT64 &mapItemNum, SCommonSource &sourceParam);
    //添加收集物品（主要是用于任务收集物品）
    void AddCollectItem(const proto_ff::ItemProtoInfo& itemProto, VEC_ITEM_PROTO_EX& vCollectItems);
    //收集物品事件触发
    void CollectItemEvent(VEC_ITEM_PROTO_EX &vCollectItems, SCommonSource &sourceParam, int32_t nOperateType = EItemOpetateType_None);

    //物品日志
    void ItemLog(MAP_UINT16_INT64 &items, MAP_INDEX_ITEM_PROTO_EX &mapOutNewIdxItemProtoEx, SCommonSource &source);
    void ItemLog(MAP_UINT64_INT64 &items, SCommonSource &source);
public:
    bool SortItem();
    bool BagItemSort();
};
