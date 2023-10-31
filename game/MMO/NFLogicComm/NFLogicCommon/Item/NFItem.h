// -------------------------------------------------------------------------
//    @FileName         :    NFItem.h
//    @Author           :    gaoyi
//    @Date             :    23-10-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFItem
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "CommonClass_s.h"
#include "NFGameCommon/NFComTypeDefine.h"
#include "E_Equip_s.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmHashSet.h"
#include "NFLogicCommon/NFPackageDefine.h"
#include "E_Item_s.h"
#include "E_Dragonsoul_s.h"
#include "E_Encyclopedia_s.h"

enum RandAttrType
{
    RandAttrType_rand = 0,    //随机
    RandAttrType_min = 1,    //最小值
    RandAttrType_max = 2    //最大值
};

//蓝星属性
struct stBlueAttr
{
    uint32_t id = 0;    //属性索引id
    int64_t value = 0;    //属性值
    int32_t lv_part = 0; //等级段，每几级加成多少属性
};

//星级属性
struct stStarAttr
{
    uint32_t id = 0;
    int64_t value = 0;
};

using VEC_STAR_ATTR = std::vector<stStarAttr>;
using VEC_BLUE_ATTR = std::vector<stBlueAttr>;
using MAP_BLUE_ATTR = std::map<uint32_t, stBlueAttr>;

typedef NFShmHashMap<int32_t, int32_t, DEFINE_E_EQUIPATTRIBUTE_M_ATTRIBUTE_MAX_NUM> MiscAttrMap;

//EPackageType_DeityEquip = 5;	//天神
struct DeityEquipExt
{
    DeityEquipExt()
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
        m_stronglv = 0;
        m_strongWearQuality = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    uint32_t m_stronglv; //强化等级
    uint32_t m_strongWearQuality; //强化阶级
};

//EPackageType_BeastEquip = 7;	//神兽装备背包
struct BeastEquipExt
{
    BeastEquipExt()
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
        m_stronglv = 0;
        m_strongExp = 0;
        m_strongWearQuality = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    uint32_t m_stronglv; //强化等级
    uint64_t m_strongExp; //强化等级经验
    uint32_t m_strongWearQuality; //强化阶级
    NFShmHashMap<uint32_t, uint32_t, DEFINE_E_ENCYCLOPEDIAEQUIPEXPVALUE_M_BEASTSTAR_MAX_NUM> m_blueAttr; //神兽装备蓝星属性
    NFShmHashMap<uint32_t, uint32_t, DEFINE_E_ENCYCLOPEDIAEQUIPEXPVALUE_M_GOLDSTAR_MAX_NUM> m_godAttr; //神兽装备黄星属性 带★
};

//EPackageType_Longhun = 8;		//龙魂
struct LongHunExt
{
    LongHunExt()
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
        m_stronglv = 0;
        m_strongExp = 0;
        m_strongWearQuality = 0;
        m_strongWearQualityExp = 0;
        m_awaken_lv = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    uint32_t m_stronglv; //强化等级
    uint64_t m_strongExp; //强化等级经验
    uint32_t m_strongWearQuality; //强化阶级
    uint64_t m_strongWearQualityExp; //强化阶级经验
    uint32_t m_awaken_lv;   //觉醒等级
    NFShmHashSet<uint32_t, DEFINE_E_DRAGONSOULFLY_M_FLYATT_MAX_NUM> m_flyAttr; //龙魂飞升属性组ID
};

//EPackageType_shenji_aq = 11;	//神机装备暗器
//EPackageType_shenji_lj = 12;	//神机装备灵甲
struct ShengjiExt
{
    ShengjiExt()
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
        m_makeid = 0;
        m_state = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    uint32_t m_makeid;//打造ID。神机装备用
    uint32_t m_state;//神机装备用0：未装备 1统御 2装备
};

//EPackageType_GodEvil = 13;		//神魔背包
struct GodEvilExt
{
    GodEvilExt()
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
        m_stronglv = 0;
        m_strongExp = 0;
        m_speclv = 0;
        m_savvy = 0;
        m_strongWearQualityExp = 0;
        m_make_time = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    uint32_t m_stronglv; //强化等级
    uint64_t m_strongExp; //强化等级经验
    int32_t m_speclv;   //真炼等级 装备表specAttr表lv字段。
    int32_t m_savvy;        //神品悟性(神魔装备)
    uint64_t m_strongWearQualityExp; //强化阶级经验
    uint64_t m_make_time;            //装备打造时间(神魔装备)
    NFCommonStr m_make_name;        //装备打造者名字(神魔装备
    NFShmHashSet<uint32_t, 10> m_goldStar; //金星 属性ID列表
    NFShmHashSet<uint32_t, 10> m_silverStar; //银星 属性ID列表(神魔装备)
    NFShmHashMap<uint32_t, uint32_t, 10> m_skillMap; //神魔装备被动技能 skillid - level
};

//EPackageType_star = 14;		//不灭星辰
struct StarExt
{
    StarExt()
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
        m_stronglv = 0;
        m_strongExp = 0;
        m_strongWearQuality = 0;
        m_strongWearQualityExp = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    uint32_t m_stronglv; //强化等级
    uint64_t m_strongExp; //强化等级经验
    uint32_t m_strongWearQuality; //强化阶级
    uint64_t m_strongWearQualityExp; //强化阶级经验
};

//EPackageType_turn = 15;		//转生装备
struct TurnExt
{
    TurnExt()
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
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
};

//EPackageType_MountKun = 16;		//坐化鲲装备
struct MountKunExt
{
    MountKunExt()
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
        m_stronglv = 0;
        m_strongWearQuality = 0;
        m_awaken_lv = 0;
        m_awaken_exp = 0;
        m_awaken_star = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    uint32_t m_stronglv; //强化等级
    uint32_t m_strongWearQuality; //强化阶级
    uint32_t m_awaken_lv;   //突破等级
    uint32_t m_awaken_exp;   //突破经验
    uint64_t m_awaken_star; //突破星星
};

//EPackageType_YaoHun = 17;	//妖魂装备
struct YaoHunExt
{
    YaoHunExt()
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
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
};

class NFItem
{
public:
    NFItem();
    
    virtual ~NFItem();
    
    int CreateInit();
    int ResumeInit();
public:
    uint16_t GetIndex() const { return m_nIndex; }
    uint64_t GetItemID() const { return m_nItemID; }
    uint64_t GetNum() const { return m_nNum; }
    int8_t GetBind() const { return m_byBind; }
    uint8_t GetType() const { return m_byType; }
    uint32_t GetLevel() const { return m_nLevel; }
    int64_t GetExpireTime() const { return m_nExpiredTime; }
public:
    bool IsExpire() const;
    void SetIndex(uint16_t nIndex) { m_nIndex = nIndex; }
    void SetType(uint8_t type) { m_byType = type; }
    void SetBind(int8_t byBind) { m_byBind = byBind; }
    void SetNum(uint64_t nNum) { m_nNum = nNum; }
    void SetLevel(uint32_t nLevel) { m_nLevel = nLevel; }
    void SetExpireTime(int64_t tick) { m_nExpiredTime = tick; }
    bool AddNum(int64_t nAddNum);
public:
    virtual bool Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum = 1, int8_t byBind = (uint8_t) EBindState::EBindState_no);
    virtual void UnInit();
    virtual bool FromItemProto(const proto_ff::ItemProtoInfo &protoItem);
    virtual bool ToItemProto(proto_ff::ItemProtoInfo &protoItem);
    virtual bool SaveDB(proto_ff::ItemProtoInfo &protoItem);
    virtual void GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level);
    virtual uint64_t GetBaseScore() { return 0; }
public:
    const proto_ff_s::E_EquipEquip_s *GetEquipCfg() const;
    const proto_ff_s::E_ItemItem_s *GetItemCfg() const;
    const proto_ff_s::E_EquipAttribute_s *GetEquipAttributeCfg() const;
    bool IsProf(int32_t profId) const;                        //是否属于某个职业
public:
    virtual MAP_INT32_INT32 GetBaseAttr();
    virtual VEC_STAR_ATTR GetStarAttr();
    virtual MAP_BLUE_ATTR GetBlueAttr();
    virtual MAP_INT32_INT32 GetGodAttr();
protected:
    bool genBaseAttr(SItemCond &itemCond);                //生成基础属性
    bool genGodPinAttr(SItemCond &itemCond);            //生成仙品属性(两部分 星级属性和蓝星属性)
    bool genGodZunAttr(SItemCond &itemCond);            //生成仙尊属性
    void GenBaseScore();
protected:
    uint16_t m_nIndex;              //索引
    uint64_t m_nItemID;             //物品ID
    uint32_t m_nNum;                //物品数量
    int8_t m_byBind;                //绑定状态
    uint8_t m_byType;               //类型
    uint32_t m_nLevel;              //等级 预留(装备里，这个等级是玩家等级)
    uint64_t m_nExpiredTime;        //过期时间,0,永不过期
    //道具也有评分，放在基类里
    
    uint32_t m_baseAttrPercent;     //基础属性
    //仙品属性 = 星级属性(带★) + 蓝星属性(不带★)
    uint32_t m_starAttrPercent;     //星级属性
    uint32_t m_godAttrPercent;      //仙尊属性 (神兽装备黄星属性)
};

class NFDeityItem : public NFItem
{
public:
    NFDeityItem()
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
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    virtual bool Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum = 1, int8_t byBind = (uint8_t) EBindState::EBindState_no);
    virtual void UnInit();
    virtual bool FromItemProto(const proto_ff::ItemProtoInfo &protoItem);
    virtual bool ToItemProto(proto_ff::ItemProtoInfo &protoItem);
    virtual bool SaveDB(proto_ff::ItemProtoInfo &protoItem);
    virtual void GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level);
    
    DeityEquipExt m_deityEquip;       //EPackageType_DeityEquip = 5;	//天神神饰
};

class NFBeastItem : public NFItem
{
public:
    NFBeastItem()
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
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    virtual bool Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum = 1, int8_t byBind = (uint8_t) EBindState::EBindState_no);
    virtual void UnInit();
    virtual bool FromItemProto(const proto_ff::ItemProtoInfo &protoItem);
    virtual bool ToItemProto(proto_ff::ItemProtoInfo &protoItem);
    virtual bool SaveDB(proto_ff::ItemProtoInfo &protoItem);
    virtual void GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level);
    
    BeastEquipExt m_beastEquip;       //EPackageType_BeastEquip = 7;	//神兽装备背包
};

class NFLongHunItem : public NFItem
{
public:
    NFLongHunItem()
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
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    virtual bool Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum = 1, int8_t byBind = (uint8_t) EBindState::EBindState_no);
    virtual void UnInit();
    virtual bool FromItemProto(const proto_ff::ItemProtoInfo &protoItem);
    virtual bool ToItemProto(proto_ff::ItemProtoInfo &protoItem);
    virtual bool SaveDB(proto_ff::ItemProtoInfo &protoItem);
    virtual void GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level);
    
    LongHunExt m_longHun;             //EPackageType_Longhun = 8;		//龙魂
};

//EPackageType_shenji_aq = 11;	//神机装备暗器
//EPackageType_shenji_lj = 12;	//神机装备灵甲
class ShengjiItem : public NFItem
{
public:
    ShengjiItem()
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
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    virtual bool Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum = 1, int8_t byBind = (uint8_t) EBindState::EBindState_no);
    virtual void UnInit();
    virtual bool FromItemProto(const proto_ff::ItemProtoInfo &protoItem);
    virtual bool ToItemProto(proto_ff::ItemProtoInfo &protoItem);
    virtual bool SaveDB(proto_ff::ItemProtoInfo &protoItem);
    virtual void GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level);
    
    ShengjiExt m_shengji;
};

class NFGodEvilItem : public NFItem
{
public:
    NFGodEvilItem()
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
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    virtual bool Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum = 1, int8_t byBind = (uint8_t) EBindState::EBindState_no);
    virtual void UnInit();
    virtual bool FromItemProto(const proto_ff::ItemProtoInfo &protoItem);
    virtual bool ToItemProto(proto_ff::ItemProtoInfo &protoItem);
    virtual bool SaveDB(proto_ff::ItemProtoInfo &protoItem);
    virtual void GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level);
    
    GodEvilExt m_godEvil;             //EPackageType_GodEvil = 13;		//神魔背包
};

class NFStarItem : public NFItem
{
public:
    NFStarItem()
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
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    virtual bool Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum = 1, int8_t byBind = (uint8_t) EBindState::EBindState_no);
    virtual void UnInit();
    virtual bool FromItemProto(const proto_ff::ItemProtoInfo &protoItem);
    virtual bool ToItemProto(proto_ff::ItemProtoInfo &protoItem);
    virtual bool SaveDB(proto_ff::ItemProtoInfo &protoItem);
    virtual void GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level);
    
    StarExt m_star;                   //EPackageType_star = 14;		//不灭星辰
};

class NFMountKunItem : public NFItem
{
public:
    NFMountKunItem()
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
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    virtual bool Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum = 1, int8_t byBind = (uint8_t) EBindState::EBindState_no);
    virtual void UnInit();
    virtual bool FromItemProto(const proto_ff::ItemProtoInfo &protoItem);
    virtual bool ToItemProto(proto_ff::ItemProtoInfo &protoItem);
    virtual bool SaveDB(proto_ff::ItemProtoInfo &protoItem);
    virtual void GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level);
    
    MountKunExt m_mountKun;           //EPackageType_MountKun = 16;		//坐化鲲装备
};

class NFTurnItem : public NFItem
{
public:
    NFTurnItem()
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
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    virtual bool Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum = 1, int8_t byBind = (uint8_t) EBindState::EBindState_no);
    virtual void UnInit();
    virtual bool FromItemProto(const proto_ff::ItemProtoInfo &protoItem);
    virtual bool ToItemProto(proto_ff::ItemProtoInfo &protoItem);
    virtual bool SaveDB(proto_ff::ItemProtoInfo &protoItem);
    virtual void GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level);
    
    TurnExt m_turn;                   //EPackageType_turn = 15;		//转生装备
};

class NFYaoHunItem : public NFItem
{
public:
    NFYaoHunItem()
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
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    virtual bool Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum = 1, int8_t byBind = (uint8_t) EBindState::EBindState_no);
    virtual void UnInit();
    virtual bool FromItemProto(const proto_ff::ItemProtoInfo &protoItem);
    virtual bool ToItemProto(proto_ff::ItemProtoInfo &protoItem);
    virtual bool SaveDB(proto_ff::ItemProtoInfo &protoItem);
    virtual void GetAllAttr(MAP_INT32_INT32 &attrs, int32_t level);
    
    YaoHunExt m_yaoHun;               //EPackageType_YaoHun = 17;	//妖魂装备
};

//proto物品
typedef vector<proto_ff::ItemProtoInfo*> VEC_ITEM_PROTO;
typedef vector<proto_ff::ItemProtoInfo>  VEC_ITEM_PROTO_EX;
typedef map<uint16_t, proto_ff::ItemProtoInfo> MAP_ITEM_PROTO_EX;