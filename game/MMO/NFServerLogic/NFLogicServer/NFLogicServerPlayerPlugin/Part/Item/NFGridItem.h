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
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "CommonClass_s.h"
#include "Com.pb.h"
#include "Com_s.h"
#include "NFLogicCommon/PackageDefine.h"
#include "equip_s.h"
#include "item_s.h"
#include "NFLogicCommon/NFComTypeDefine.h"

enum RandAttrType
{
    RandAttrType_rand = 0,	//随机
    RandAttrType_min = 1,	//最小值
    RandAttrType_max = 2	//最大值
};

typedef NFShmHashMap<int32_t, int32_t, DEFINE_E_EQUIPATTRIBUTE_M_ATTRIBUTE_MAX_NUM> EquipExtBaseMap;
typedef NFShmVector<proto_ff_s::Attr_s, DEFINE_EQUIPEXT_REFINE_MAX_NUM> EquipExtStarVec;
typedef NFShmHashMap<int32_t, proto_ff_s::BlueStarAttr_s, DEFINE_EQUIPEXT_BLUE_MAX_NUM> EquipExtBlueMap;
typedef NFShmHashMap<int32_t, int32_t, DEFINE_EQUIPEXT_BASE_MAX_NUM> EquipExtGodMap;
typedef NFShmHashMap<int32_t, int32_t, DEFINE_EQUIPEXT_BASE_MAX_NUM> EquipExtSpecialMap;

class NFEquipExt {
public:
    NFEquipExt()
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

    int CreateInit()
    {
        strong_lv = 0;
        strong_wear_quality = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    EquipExtBaseMap base;
    EquipExtStarVec star;
    EquipExtBlueMap blue;
    EquipExtGodMap god;
    EquipExtSpecialMap special;
    int32_t strong_lv;
    int32_t strong_wear_quality;
};

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
public:
    bool IsItem() const;
    bool IsEquip() const;
public:
    virtual EquipExtBaseMap* GetBaseAttr() { return &equip_ext.base; }
    virtual EquipExtStarVec* GetStarAttr() { return &equip_ext.star; }
    virtual EquipExtBlueMap* GetBuleAttr() { return &equip_ext.blue; }
    virtual EquipExtGodMap* GetGodAttr() { return &equip_ext.god; }
    virtual EquipExtSpecialMap* GetSpecialAttr() { return &equip_ext.special; }
    virtual void SetStrongLv(uint32_t lv) { equip_ext.strong_lv = lv; }
    virtual void SetStrongWearQuality(uint32_t lv) { equip_ext.strong_wear_quality = lv; }
    virtual int32_t GetStrongLv() { return equip_ext.strong_lv; }
    virtual int32_t GetStrongWearQuality() { return equip_ext.strong_wear_quality; }
public:
    proto_ff_s::E_ItemItem_s* GetItemCfg();
    proto_ff_s::E_EquipEquip_s* GetEquipCfg();
    proto_ff_s::E_EquipAttribute_s* GetEquipAttrCfg();
    bool IsProf(int32_t profId);						//是否属于某个职业
    void GetAllAttr(MAP_INT32_INT32& attrs, int32_t level);			//获得所有属性
private:
    int genBaseAttr(SItemCond& itemCond);				//生成基础属性
    int genGodPinAttr(SItemCond& itemCond);			//生成仙品属性(两部分 星级属性和蓝星属性)
    int genGodZunAttr(SItemCond& itemCond);			//生成仙尊属性
    int genSpecialAttr(SItemCond& itemCond);			//生成特殊属性
public:
    bool RandAttr(VEC_INT32& vecAttrType, VEC_INT32& vecAttrMinValue, VEC_INT32& vecAttrMaxValue, RandAttrType randType, proto_ff::Attr& finAttr);
public:
    proto_ff_s::GridItemBase_s base;
    NFEquipExt equip_ext;
};

//背包物品
typedef vector<NFGridItem> VEC_PACKAGE_ITEM;
//proto物品
typedef vector<proto_ff::ItemProtoInfo*> VEC_ITEM_PROTO;
typedef vector<proto_ff::ItemProtoInfo>  VEC_ITEM_PROTO_EX;
typedef map<uint16_t, proto_ff::ItemProtoInfo> MAP_ITEM_PROTO_EX;
