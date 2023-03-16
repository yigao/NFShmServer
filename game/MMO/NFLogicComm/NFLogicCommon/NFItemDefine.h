// -------------------------------------------------------------------------
//    @FileName         :    NFItemDefine.h
//    @Author           :    gaoyi
//    @Date             :    22-11-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFItemDefine
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "CommonClass_s.h"
#include "Com.pb.h"
#include "Com_s.h"
#include "PackageDefine.h"

class NFGridItem
{
public:
    NFGridItem();
    ~NFGridItem();
    int CreateInit();
    int ResumeInit();

    bool Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum = 1, int8_t byBind = (int8_t)EBindState::EBindState_no);

    int read_from_pbmsg(const proto_ff::ItemProtoInfo &protoItem);

    int write_to_pbmsg(proto_ff::ItemProtoInfo &protoItem);
public:
    uint16_t GetIndex() const;
    uint64_t GetItemID() const;
    uint64_t GetNum() const;
    int8_t GetBind() const;
    uint8_t GetType() const;
    uint32_t GetLevel() const;
    int64_t GetExpireTime() const;

    void SetIndex(uint16_t nIndex);
    void SetType(uint8_t type);
    void SetBind(int8_t byBind);
    void SetNum(uint64_t nNum);
    void SetLevel(uint32_t nLevel);
    void SetExpireTime(int64_t tick);

    bool AddNum(int64_t nAddNum);

    proto_ff_s::GridItemBase_s base;
    proto_ff_s::EquipExt_s equip_ext;
};

//背包物品
typedef vector<NFGridItem> VEC_PACKAGE_ITEM;
//proto物品
typedef vector<proto_ff::ItemProtoInfo*> VEC_ITEM_PROTO;
typedef vector<proto_ff::ItemProtoInfo>  VEC_ITEM_PROTO_EX;
typedef map<uint16_t, proto_ff::ItemProtoInfo> MAP_ITEM_PROTO_EX;
