// -------------------------------------------------------------------------
//    @FileName         :    NFItemUtil.h
//    @Author           :    gaoyi
//    @Date             :    22-11-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFItemUtil
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFItemDefine.h"
#include "NFLogicCommon/PackageDefine.h"
#include "NFLogicCommon/NFComTypeDefine.h"
#include "item_s.h"
#include "equip_s.h"
#include "NFComm/NFShmCore/NFShmHashMap.h"

class NFItemMgr : public NFShmObj
{
public:
    NFItemMgr();

    virtual ~NFItemMgr();

    int CreateInit();

    int ResumeInit();

public:
    int ItemFromCSData(NFGridItem &item, const proto_ff::ItemGridCSData *pData);

    ///////////////////////////////// 资源类 虚拟物品 接口 /////////////////////////////////////////
    //是否是资源类 虚拟物品
    bool IsVirItem(uint64_t itemId);

    //是否是资源类 虚拟物品, 如果是，则 attrId 会设置为 虚拟物品对应的属性ID
    bool IsVirItem(uint64_t itemId, uint32_t &attrId);

    //过滤出虚拟物品的属性
    void FilterVirItem(const LIST_ITEM &lstItem, LIST_ITEM &lstOutItem, MAP_UINT32_INT64 &mapAttr);

    //过滤出虚拟物品的属性
    void FilterVirItem(const LIST_ITEM &lstItem, LIST_ITEM &lstOutItem);

    //过滤出虚拟物品的属性
    void FilterVirItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecOutProtoItemsEx, MAP_UINT32_INT64 &mapAttr);

    //过滤出虚拟物品的属性
    void FilterVirItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecOutProtoItemsEx);

public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    //计算物品需要的格子数量-只是初略估算出来，可堆叠的数量是一个大概的值, 不可堆叠的物品占用的格子数量是可以计算出来的
    uint32_t CalcGridNeed(const LIST_ITEM &lstItem, const VEC_ITEM_PROTO_EX &vecProtoEx, uint32_t &nNoPileNeed, uint32_t &nPileNeed);

public:
    //创建物品
    bool CreateItem(const LIST_ITEM &lstItem, VEC_ITEM_PROTO_EX &vecProtoEx, SItemCond &itemCond, bool bMerge = true);

    //创建物品(背包用的，其他地方不要用)
    bool CreateItem(const VEC_ITEM_PROTO &vecProtoItems, VEC_PACKAGE_ITEM &vecItems);

    //创建物品(背包用的，其他地方不要用)
    bool CreateItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_PACKAGE_ITEM &vecItems);

    //创建物品
    bool CreateItem(const LIST_ITEM &lstItem, VEC_PACKAGE_ITEM &vecItems, SItemCond &itemCond, bool bMerge = true);

    //合并物品
    void MergeItem(const LIST_ITEM &lstItem, LIST_ITEM &lstOutItem);

public:
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    //物品的绑定状态-根据获得途径 bindWay: EItemBindWay 枚举类型
    int8_t BindStateByWay(uint64_t nItemId, int8_t byBind, int8_t bindWay = EItemBindWay_UnBind);

    int8_t BindStateByWay(const proto_ff_s::itemitem_s *pItemCfg, int8_t byBind, int8_t bindWay = EItemBindWay_UnBind);

    int8_t BindStateByWay(const proto_ff_s::equipequip_s *pEquipCfg, int8_t byBind, int8_t bindWay = EItemBindWay_UnBind);

    //获取物品堆叠数
    int64_t ItemMaxPile(uint64_t itemId);

    int64_t ItemMaxPile(const proto_ff_s::itemitem_s *pItemCfg);

    int64_t ItemMaxPile(const proto_ff_s::equipequip_s *pEquipCfg);

    //设置物品信息
    bool SetItemProtoInfo(const LIST_ITEM &lstItem, VEC_ITEM_PROTO_EX &vecProto,SItemCond &itemCond);
    //设置物品protobuf信息
    bool SetItemProtoInfo(NFGridItem *pItem, proto_ff::ItemProtoInfo *protoItem, int64_t nNum = -1);
    //校验物品
    bool CheckItem(const VEC_ITEM_PROTO_EX &vecProtoItems);
public:
    //是否有效的绑定途径
    bool ValidBindWay(int8_t bindWay);

    //是否有效的禁止类型
    bool ValidForbidType(int8_t forbidType);

    //是否有效的物品属性初始化类型
    bool ValidInitAttrType(int8_t initAttrType);

    //物品是否能交易
    bool CanTrade(uint64_t itemId, int8_t byInBind);

    //物品能否出售
    bool CanSell(uint64_t itemId, int8_t byInBind);

    //是否是任务物品
    bool IsTaskItem(uint64_t itemId);

    //获取拾取掉落CD
    uint32_t GetPickupDropCd();

    //获取同时拾取掉落的数量
    uint32_t GetPickupNumAtOnce();

    //是否是普通装备部位
    bool IsNormalPos(uint8_t pos);

    //是否是首饰类装备部位
    bool IsJewelryPos(uint8_t pos);

    //是否是仙器 装备部位
    bool IsFairyPos(uint8_t pos);

public:
    //物品排序比较函数
    bool CompareSundryFunc_(const NFGridItem *pItemA, const NFGridItem *pItemB);
    bool CompareMaterialFunc_(const NFGridItem *pItemA, const NFGridItem *pItemB);
    bool CompareTaskFunc_(const NFGridItem *pItemA, const NFGridItem *pItemB);
    bool CompareEquipFunc_(const NFGridItem *pItemA, const NFGridItem *pItemB);
    bool CompareStarFunc_(const NFGridItem *pItemA, const NFGridItem *pItemB);
    bool CompareGodhoodFunc_(const NFGridItem *pItemA, const NFGridItem *pItemB);

    //物品排序比较函数
    bool CompareSundryFunc(const NFGridItem& itemA, const NFGridItem& itemB);
    bool CompareMaterialFunc(const NFGridItem& itemA, const NFGridItem& itemBB);
    bool CompareTaskFunc(const NFGridItem& itemA, const NFGridItem& itemB);
    bool CompareEquipFunc(const NFGridItem& itemA, const NFGridItem& itemB);
    bool CompareStarFunc(const NFGridItem& itemA, const NFGridItem& itemBB);
    bool CompareGodhoodFunc(const NFGridItem& itemA, const NFGridItem& itemB);
private:
    uint32_t m_nPickupMillsec;        //拾取掉落间隔，单位：毫秒
    uint32_t m_nPickupNumLimit;        //每次拾取数量限制
    NFShmHashMap<uint8_t, bool, 100> m_setNormalPos;        //普通装备部位
    NFShmHashMap<uint8_t, bool, 100> m_setJewelryPos;        //首饰部位
    NFShmHashMap<uint8_t, bool, 100> m_setFairyPos;        //仙器部位
DECLARE_IDCREATE(NFItemMgr)
};