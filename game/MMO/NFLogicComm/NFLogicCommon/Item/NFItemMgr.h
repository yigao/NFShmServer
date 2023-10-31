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

class NFItemMgr : public NFShmObjTemplate<NFItemMgr, EOT_SERVER_COMMON_ITEM_MGR_ID, NFShmObj>
{
public:
    NFItemMgr();
    
    virtual ~NFItemMgr();
    
    int CreateInit();
    int ResumeInit();
public:
    ///////////////////////////////// 资源类 虚拟物品 接口 /////////////////////////////////////////
    //是否是资源类 虚拟物品
    bool IsVirItem(uint64_t itemId);
    //是否是资源类 虚拟物品, 如果是，则 attrId 会设置为 虚拟物品对应的属性ID
    bool IsVirItem(uint64_t itemId, uint32_t &attrId);
    //过滤出虚拟物品的属性
    void FilterVirItem(LIST_ITEM &lstItem, LIST_ITEM &lstOutItem, MAP_UINT32_INT64 &mapAttr);
    //过滤出虚拟物品的属性
    void FilterVirItem(LIST_ITEM &lstItem, LIST_ITEM &lstOutItem);
    //过滤出虚拟物品的属性
    void FilterVirItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecOutProtoItemsEx, MAP_UINT32_INT64 &mapAttr);
    //过滤出虚拟物品的属性
    void FilterVirItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecOutProtoItemsEx);
    bool IsDynExpItem(uint64_t itemId);
public:

};