// -------------------------------------------------------------------------
//    @FileName         :    NFItemMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFItemMgr
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFLogicCommon/NFPackageDefine.h"
#include "NFGameCommon/NFComTypeDefine.h"
#include "NFItem.h"

class NFItemMgr
{
public:
    //生成新物品对象
    static NFItem *MakeItemObj(uint64_t nItemId);
    //释放物品对象
    static bool FreeItemObj(NFItem *pItemObj);
public:
    //创建物品
    static bool CreateItem(const LIST_ITEM &lstItem, VEC_ITEM_PROTO_EX &vecProtoEx, SItemCond &itemCond, bool bMerge = true);
    //创建物品(背包用的，其他地方不要用)
    static bool CreateItem(const VEC_ITEM_PROTO &vecProtoItems, VEC_PACKAGE_ITEM &vecItems);
    //创建物品(背包用的，其他地方不要用)
    static bool CreateItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_PACKAGE_ITEM &vecItems);
public:
    ///////////////////////////////// 资源类 虚拟物品 接口 /////////////////////////////////////////
    //是否是资源类 虚拟物品
    static bool IsVirItem(uint64_t itemId);
    //是否是资源类 虚拟物品, 如果是，则 attrId 会设置为 虚拟物品对应的属性ID
    static bool IsVirItem(uint64_t itemId, uint32_t &attrId);
    //过滤出虚拟物品的属性
    static void FilterVirItem(const LIST_ITEM &lstItem, LIST_ITEM &lstOutItem, MAP_UINT32_INT64 &mapAttr);
    //过滤出虚拟物品的属性
    static void FilterVirItem(const LIST_ITEM &lstItem, LIST_ITEM &lstOutItem);
    //过滤出虚拟物品的属性
    static void FilterVirItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecOutProtoItemsEx, MAP_UINT32_INT64 &mapAttr);
    //过滤出虚拟物品的属性
    static void FilterVirItem(const VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecOutProtoItemsEx);
    static bool IsDynExpItem(uint64_t itemId);
public:
    /////////////////////////////////////////////////////////////////////////////////////
    //设置物品protobuf信息
    static bool SetItemProtoInfo(NFItem *pItem, proto_ff::ItemProtoInfo *protoItem, int64_t nNum = -1);
    //物品的绑定状态-根据获得途径 bindWay: EItemBindWay 枚举类型
    static int8_t BindStateByWay(uint64_t nItemId, int8_t byBind, int8_t bindWay = EItemBindWay_UnBind);
    static int8_t BindStateByWay(const proto_ff_s::E_ItemItem_s*pItemCfg, int8_t byBind, int8_t bindWay = EItemBindWay_UnBind);
    static int8_t BindStateByWay(const proto_ff_s::E_EquipEquip_s*pEquipCfg, int8_t byBind, int8_t bindWay = EItemBindWay_UnBind);
    //获取物品堆叠数
    static bool ItemMaxPile(uint64_t itemId, int64_t& maxPile);
    static int64_t ItemMaxPile(const proto_ff_s::E_ItemItem_s *pItemCfg);
    static int64_t ItemMaxPile(const proto_ff_s::E_EquipEquip_s *pEquipCfg);
    //是否有效的绑定途径
    static bool ValidBindWay(int8_t bindWay);
    //是否有效的禁止类型
    static bool ValidForbidType(int8_t forbidType);
    //是否有效的物品属性初始化类型
    static bool ValidInitAttrType(int8_t initAttrType);
    //物品是否能交易
    static bool CanTrade(uint64_t itemId,int8_t byInBind);
    //物品能否出售
    static bool CanSell(uint64_t itemId,int8_t byInBind);
    //是否是任务物品
    static bool IsTaskItem(uint64_t itemId);
    //合并物品
    static void MergeItem(const LIST_ITEM &lstItem, LIST_ITEM &lstOutItem);
    //计算物品需要的格子数量-只是初略估算出来，可堆叠的数量是一个大概的值, 不可堆叠的物品占用的格子数量是可以计算出来的
    static uint32_t CalcGridNeed(const LIST_ITEM &lstItem, const VEC_ITEM_PROTO_EX &vecProtoEx,uint32_t &nNoPileNeed, uint32_t &nPileNeed);
    //获得物品类型，绑定类型，最大堆叠数目
    static bool GetItemData(uint32_t itemId, uint8_t bindType, uint8_t& outItemType, uint8_t& outBindType, int64_t& maxPile);
public:
    ////////////////////////////////// 计算战力  /////////////////////////////////
    static uint64_t GetItemFight(NFItem *pItem, int32_t level);
public:
    //创建物品
    static bool CreateItem(const LIST_ITEM &lstItem, VEC_PACKAGE_ITEM &vecItems, SItemCond &itemCond, bool bMerge = true);
    //校验物品
    static bool CheckItem(const VEC_ITEM_PROTO_EX &vecProtoItems);
};