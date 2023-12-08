#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFGameCommon/NFComTypeDefine.h"
#include "E_Skill_s.h"
#include "DescStore/SkillSkillDesc.h"
#include "NFLogicCommon/NFSkillDefine.h"

//技能配置
struct SkillCfg
{
    SkillCfg()
    {
    
    }
    
    const proto_ff_s::E_SkillSkill_s* GetCfg() const
    {
        return SkillSkillDesc::Instance()->GetDesc(m_skillId);
    }
    
    uint64_t m_skillId;
    VEC_INT32 vec_unlocktype;                    //解锁类型
    VEC_INT32 vec_unlockvalue;                    //解锁值
    
    int32_t rangeValue1 = 0;                    //范围值1
    int32_t rangeValue2 = 0;                    //范围值2
    int32_t rangeValue3 = 0;                    //范围值3
    int32_t rangeValueEx1 = 0;                    //扩展范围值1
    int32_t rangeValueEx2 = 0;                    //扩展范围值2
    int32_t rangeValueEx3 = 0;                    //扩展范围值3
    
    VEC_INT64 vecRelation;                        //关联技能
    int64_t preRelation = 0;                    //前置关联技能ID
    VEC_UINT32 vecDamage;                        //伤害时间点
    VEC_UINT32 vecDamageEx;                        //扩展伤害时间点
};

class SkillDescEx : public NFShmObjGlobalTemplate<SkillDescEx, EOT_CONST_SKILL_DESC_EX_ID, NFIDescStoreEx>
{
public:
    using MapSkillCfg = std::unordered_map<uint64_t, SkillCfg>;
    using MapSkillUnlock = std::map<int32_t, std::unordered_set<int64_t> >;
public:
    SkillDescEx();
    
    virtual ~SkillDescEx();
    
    int CreateInit();
    
    int ResumeInit();

public:
    virtual int Load() override;
    
    virtual int CheckWhenAllDataLoaded() override;

public:
    bool Process();

public:
    const SkillCfg* GetCfg(uint64_t skillid);
    //是否是有效的技能解锁类型
    bool ValidUnlockType(int32_t type);
    //是否是被动技能
    bool IsPassive(uint64_t skillid);
    //是否是被动技能
    bool IsPassive(const SkillCfg* pcfg);
    //是否是有效的技能范围类型
    bool ValidRangeType(int32_t rangetype);
    //是否是锁定目标的范围类型
    bool IsLockRangeType(int32_t rangetype);
    //是否是需要目标点的技能
    bool IsPosRangeType(int32_t rangetype);
    
    //根据玩家职业获取职业技能列表
    const SET_UINT64* GetProfSkillList(int8_t prof);
    
    //获取职业的技能组ID
    uint32_t GetProfSkillGroupId(int8_t prof);
    
    //是否是天神技能
    bool IsGodSkill(uint64_t skillid);
    
    bool IsGodSkill(const SkillCfg* pcfg);
    //是否是天神技能组
    bool IsGodGroup(uint32_t groupid);
    //是否是角色技能
    bool IsRoleSkill(uint64_t skillid);
    
    bool IsRoleSkill(const SkillCfg* pcfg);
    //是否是宠物技能
    bool IsPetSkill(uint64_t skillid);
    
    bool IsPetSkill(const SkillCfg* pcfg);
    //是否是战魂技能
    bool IsSpiritSkill(uint64_t skillid);
    
    bool IsSpiritSkill(const SkillCfg* pcfg);
    
    //怒气技能组ID
    uint32_t GetAngerSkillGroupId();
    //是否是怒气技能
    bool IsAngerSkill(uint64_t skillid);
    //是否是怒气技能
    bool IsAngerSkill(const SkillCfg* pcfg);
    //是否是普通的连击技能
    bool IsNorContiSkill(const SkillCfg* pcfg);
    
    //怒气技能ID
    uint64_t GetAngerSkillId() { return m_angerSkillId; }
    
    //获取宠物技能组ID
    uint32_t GetPetSkillGroupId();
    
    //获取战魂技能组ID
    uint32_t GetSpiritSkillGroupId();
    
    //获取天神技能组ID
    uint32_t GetGodSkillGroupId();
    //是否是需要计算公共CD的技能
    bool IsPubCdSkill(uint64_t skillid);
    
    bool IsPubCdSkill(const SkillCfg* pcfg);
    
    //获取公共cd
    int64_t GetPubCd(const SkillCfg* pcfg);
    //是否 存在优先攻击的目标
    bool IsPriorityTarget(uint8_t srckind, uint8_t dstkind);
    //是否是有效的玩家技能位置
    bool ValidRoleSkillPos(uint32_t pos) { return pos >= 0 && pos < MAX_ROLE_SKILL_POS; }
    //是否是有效的天神技能位置
    bool ValidGodSkillPos(uint32_t pos) { return pos >= 0 && pos < MAX_ROLE_SKILL_POS; }
    //是否是有效的宠物技能位置
    bool ValidPetSkillPos(uint32_t pos) { return pos >= 1 && pos < MAX_PET_SKILL_POS; }
    //是否是有效的战魂技能位置
    bool ValidSpiritSkillPos(uint32_t pos) { return pos >= 1 && pos < MAX_SPIRIT_SKILL_POS; }
    //是否是有效的怒气技能位置
    bool ValidAngerSkillPos(uint32_t pos) { return pos >= 1 && pos < MAX_ANGER_SKILL_POS; }
    
    //获取技能战力
    int64_t GetSkillFight(uint64_t skillid, int32_t level);
    
    int64_t GetSkillFight(const SkillCfg* pcfg, int32_t level);
    //是否需要计算进阶倍率的技能
    bool IsAdvanceRateSkill(const SkillCfg* pcfg);
    //是否是通过进阶解锁的技能
    bool IsUnlockByAdv(uint64_t skillid);
    
    bool IsUnlockByAdv(const SkillCfg* pcfg);
    
    bool IsUnlockByAdv(int32_t adv, const SkillCfg* pcfg);
    
    //获取技能解锁参数
    void GetSkillUnlockParam(const SkillCfg* pcfg, int32_t& type, int64_t& param1, int64_t& param2);
    //是否是法宝器魂技能
    bool IsMagWeaponSoulSkill(const SkillCfg* pcfg);
    //是否是披风器魂技能
    bool IsCapSoulSkill(const SkillCfg* pcfg);
    //是否是战魂牺牲技能
    bool IsSoulSacrifice(uint64_t skillid);
    
    //获取战魂牺牲技能ID
    int64_t GetSacrificeSkillId();

private:
    MapSkillCfg m_cfg;                                    //技能配置
    int32_t m_maxPowerDiff = 0;                            //最大战力差
    MAP_UINT32_SET_UINT64 m_mapGroup;                    //技能组-技能ID列表
    MAP_UINT64_UINT32 m_mapUpgradeGroup;                //技能ID和所属升级组之间的映射
    uint64_t m_angerSkillId = 0;                        //怒气技能ID
};
