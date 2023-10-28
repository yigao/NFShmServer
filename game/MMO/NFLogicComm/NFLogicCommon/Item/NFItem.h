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
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "CommonClass_s.h"
#include "NFGameCommon/NFComTypeDefine.h"
#include "E_Equip_s.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFLogicCommon/NFPackageDefine.h"
#include "E_Item_s.h"

enum RandAttrType
{
    RandAttrType_rand = 0,    //随机
    RandAttrType_min = 1,    //最小值
    RandAttrType_max = 2    //最大值
};

typedef NFShmHashMap<int32_t, int32_t, DEFINE_E_EQUIPATTRIBUTE_M_ATTRIBUTE_MAX_NUM> BaseAttrMap;
typedef NFShmHashMap<int32_t, int32_t, DEFINE_E_EQUIPATTRIBUTE_M_ATTRIBUTE_MAX_NUM> GodAttrMap;
typedef NFShmHashMap<int32_t, int32_t, DEFINE_E_EQUIPATTRIBUTE_M_ATTRIBUTE_MAX_NUM> MiscAttrMap;
typedef NFShmVector<proto_ff_s::Attr_s, DEFINE_EQUIPEXT_REFINE_MAX_NUM> StarAttrVec;
typedef NFShmHashMap<int32_t, proto_ff_s::BlueStarAttr_s, DEFINE_EQUIPEXT_BLUE_MAX_NUM> BlueAttrMap;

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
    virtual bool Init(uint16_t nIndex, uint64_t nItemID, SItemCond& itemCond, uint64_t nNum = 1, int8_t byBind = (uint8_t)EBindState::EBindState_no);
    virtual void UnInit();
    virtual bool SetItemProto(const proto_ff::ItemProtoInfo &protoItem);
    virtual void GetAllAttr(MAP_INT32_INT32& attrs, int32_t level);
    virtual uint64_t GetBaseScore() {	return 0; }
public:
    const proto_ff_s::E_EquipEquip_s* GetEquipCfg() const;
    const proto_ff_s::E_ItemItem_s* GetItemCfg() const;
    const proto_ff_s::E_EquipAttribute_s* GetEquipAttributeCfg() const;
    bool IsProf(int32_t profId) const;						//是否属于某个职业
public:
    
    virtual BaseAttrMap* GetBaseAttr() { return &m_baseAttr; }
    virtual StarAttrVec* GetStarAttr() { return &m_starAttr; }
    virtual BlueAttrMap* GetBuleAttr() { return &m_blueAttr; }
    virtual GodAttrMap* GetGodAttr() { return &m_godAttr; }
    virtual MiscAttrMap* GetMiscAttr() { return &m_miscAttr; }
    
    virtual int32_t GetStrongLv() const { return m_stronglv; }
    virtual int32_t GetStrongExp() const { return m_strongExp; }
    virtual int32_t GetStrongWearQuality() const { return m_strongWearQuality; }
    virtual int32_t GetStrongWearQualityExp() const  { return m_strongWearQualityExp; }
    virtual int32_t GetAwakenLv() const { return m_awaken_lv; }
    
    virtual void SetStrongLv(uint32_t lv) { m_stronglv = lv; }
    virtual void SetStrongExp(uint32_t exp) { m_strongExp = exp; }
    virtual void SetStrongWearQuality(uint32_t lv) { m_strongWearQuality = lv; }
    virtual void SetStrongWearQualityExp(uint32_t exp) { m_strongWearQualityExp = exp; }
    virtual void SetAwakenLv(int32_t lv) { m_awaken_lv = lv; }
    
private:
    bool genBaseAttr(SItemCond& itemCond);				//生成基础属性
    bool genGodPinAttr(SItemCond& itemCond);			//生成仙品属性(两部分 星级属性和蓝星属性)
    bool genGodZunAttr(SItemCond& itemCond);			//生成仙尊属性
    void GenBaseScore();
private:
    uint16_t m_nIndex;              //索引
    uint64_t m_nItemID;             //物品ID
    uint32_t m_nNum;                //物品数量
    int8_t m_byBind;                //绑定状态
    uint8_t m_byType;               //类型
    uint32_t m_nLevel;              //等级 预留(装备里，这个等级是玩家等级)
    uint64_t m_nExpiredTime;        //过期时间,0,永不过期
    //道具也有评分，放在基类里
    
    BaseAttrMap m_baseAttr;         //基础属性
    //仙品属性 = 星级属性(带★) + 蓝星属性(不带★)
    StarAttrVec m_starAttr;         //星级属性
    BlueAttrMap m_blueAttr;         //蓝星属性
    
    GodAttrMap m_godAttr;            //仙尊属性 (神兽装备黄星属性)
    MiscAttrMap m_miscAttr;         //闲杂属性 特殊属性 (龙魂飞升属性组ID 坐骑化鲲突破属性组 神兽装备蓝星属性)
    int32_t m_stronglv;                //强化等级(给天神神饰装备 神兽装备 不灭星辰 坐骑化鲲装备用)
    int32_t m_strongExp;            //强化等级经验(神兽装备 不灭星辰用 坐骑化鲲装备当做突破的经验)
    int32_t m_strongWearQuality;    //强化阶级(给天神神饰装备 神兽装备 不灭星辰 坐骑化鲲装备用)
    int32_t m_strongWearQualityExp; //强化阶级经验(给龙魂 不灭星辰用 坐骑化鲲装备当做突破星星的数目)(神魔装备)
    int32_t m_awaken_lv;			//觉醒等级(坐骑化鲲装备里的突破)
};

struct stStoneSlotInfo
{
    int8_t pos = -1; //0-4 索引，发给客户端1-5
    int64_t stone_id = 0;
};

//洗练
struct stWashSlotInfo
{
    int8_t slot = 0;	 //槽位 0 开始
    int8_t quality = 0;  //品质 (随机槽位索引+1)
    int8_t  lock = 0;	 //0未解锁。1解锁
    int32_t id = 0;		 //属性id
    int32_t value = 0;	 //属性值
};

struct stRefineSlotInfo
{
    int32_t refine_lv;
    MAP_INT32_INT32 unlockMap; //解锁的槽位 1 开始 -》加成值，万分比
    int32_t gm_lv = 0;
    SET_INT32 lock_pos;
    stRefineSlotInfo()
    {
        refine_lv = 0;
        gm_lv = 0;
    }
};

struct stEquipSlotInfo
{
    int8_t slot_pos = 0;										//槽位
    int32_t total_score = 0;									//总评分
    int32_t stronglv = 0;										//强化等级
    std::vector<stStoneSlotInfo> vec_stone;						//宝石槽位信息
    int32_t stone_pay_slot_open = 0;							//付费宝石槽位是否开放
    std::vector<stWashSlotInfo> vec_wash;						//洗练槽位信息
    uint8_t suitLv =0;												//套装等级
    stRefineSlotInfo m_refine;									//精炼信息
    int32_t awaken_lv = 0;										//觉醒等级
    int32_t awaken_break_flag = 0;								//觉醒当前等级是否突破
    int32_t soaring_lv = 0;										//飞升等级
    int32_t quality_lv = 0;										//升品等级
    std::map<int32_t, int32_t> seal_slots;						//镶嵌的印记 //slot - itemid
    SET_INT32 active_seal_ids;									//已激活的套装ids.
    
    bool unpack(const proto_ff::EquipSlotInfo& proto);
    void pack(proto_ff::EquipSlotInfo* pProto, bool clientFalg = false);
    void initStone();
    void initWash();
    void initRefine();
    int32_t GetSealSlot(int32_t pos)
    {
        auto iter = seal_slots.find(pos);
        return iter != seal_slots.end() ? iter->second : 0;
    }
    bool HasInlayFull(SET_INT32& unlockPosSet)
    {
        for (auto& e : unlockPosSet)
        {
            if (GetSealSlot(e) == 0)
                return false;
        }
        return true;
    }
    bool HasActiveSealSuilt(int32_t id)
    {
        auto iter = active_seal_ids.find(id);
        return iter != active_seal_ids.end() ? true : false;
    }
    bool hasRefineUnlock(int32_t pos)
    {
        auto iter = m_refine.unlockMap.find(pos);
        return iter != m_refine.unlockMap.end();
    }
    int32_t GetWashReachQulity();
};

//穿戴的装备信息及该槽位的信息
struct stDressEquipInfo
{
    int8_t pos = 0;
    NFItem m_equip;
    stEquipSlotInfo slot;
    
    bool unpack(const proto_ff::EquipInfo& proto);
    void pack(proto_ff::EquipInfo* pProto,bool clientFalg= false);
};

//已穿戴的装备

typedef std::vector< stDressEquipInfo > VecDressEquip;

//proto物品
typedef vector<proto_ff::ItemProtoInfo*> VEC_ITEM_PROTO;
typedef vector<proto_ff::ItemProtoInfo>  VEC_ITEM_PROTO_EX;
typedef map<uint16_t, proto_ff::ItemProtoInfo> MAP_ITEM_PROTO_EX;

int32_t GetEquipType(int64_t itemId);
bool IsComEquip(int32_t pos);
bool IsXQEquip(int32_t pos);
bool IsMarryEquip(int32_t pos);

const VEC_INT32& GetComEquipVecPos();
const VEC_INT32& GetXQEquipVecPos();