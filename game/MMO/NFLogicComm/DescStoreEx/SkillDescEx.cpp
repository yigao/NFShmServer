#include "SkillDescEx.h"
#include "NFLogicCommon/NFSkillDefine.h"
#include "DescStore/SkillSkillDesc.h"
#include "NFComm/NFCore/NFCommonApi.h"
#include "DescStore/SkillBuffDesc.h"
#include "ComDefine.pb.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "DescStore/ConstantConstantDesc.h"
#include "NFLogicCommon/NFCharactorDefine.h"
#include "DescStore/SoulSoulDesc.h"

SkillDescEx::SkillDescEx()
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

SkillDescEx::~SkillDescEx()
{
}

int SkillDescEx::CreateInit()
{
    return 0;
}

int SkillDescEx::ResumeInit()
{
    return 0;
}

int SkillDescEx::Load()
{
    CHECK_EXPR(Process(), -1, "Process Failed");
    return 0;
}

int SkillDescEx::CheckWhenAllDataLoaded()
{
    return 0;
}

bool SkillDescEx::Process()
{
    auto pmap = SkillSkillDesc::Instance()->GetResDescPtr();
    if (nullptr != pmap)
    {
        for (auto& iter : *pmap)
        {
            auto& info = iter.second;
            //
            SkillCfg& cfg = m_cfg[iter.first];
            cfg.m_skillId = iter.first;
            //
            if ((int32_t)ESkillGroup::anger == info.m_group)
            {
                m_angerSkillId = info.m_skillID;
            }
            //
            if (info.m_skillType < (int32_t)ESkillType::none || info.m_skillType >= (int32_t)ESkillType::limit)
            {
                NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....skillType error... skillid:%ld, skillType:%d ", info.m_skillID, info.m_skillType);
                return false;
            }
            if (info.m_type <= (int32_t)ESkillTarget::none || info.m_type >= (int32_t)ESkillTarget::limit)
            {
                NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....type error... skillid:%ld, type:%d ", info.m_skillID, info.m_type);
                return false;
            }
            if (info.m_processTypes < (int32_t)ESkillProcess::none || info.m_processTypes >= (int32_t)ESkillProcess::limit)
            {
                NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....processTypes error... skillid:%ld, processTypes:%d ", info.m_skillID, info.m_processTypes);
                return false;
            }
            if ((int32_t)ESkillProcess::bullet == info.m_processTypes)
            {
                if (info.m_flySpeed <= 0 || info.m_attackDistance <= 0)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....processTypes error...info.flySpeed <= 0 || info.attackDistance <= 0 skillid:%ld, processTypes:%d,flySpeed:%d,attackDistance:%d ", info.m_skillID, info.m_processTypes, info.m_flySpeed, info.m_attackDistance);
                    return false;
                }
            }
            
            if (info.m_damageType < (int32_t)ESkillDam::none || info.m_damageType >= (int32_t)ESkillDam::limit)
            {
                NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....damageType error... skillid:%ld, damageType:%d ", info.m_skillID, info.m_damageType);
                return false;
            }
            if (!IsPassive(&cfg))
            {
                if (info.m_rangeType <= (int32_t)ESkillRange::none || info.m_rangeType >= (int32_t)ESkillRange::limit)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....rangeType error... skillid:%ld, rangeType:%d ", info.m_skillID, info.m_rangeType);
                    return false;
                }
                //
                VEC_INT32 vec;
                NFCommonApi::SplitStrToVecInt(info.m_rangeTypeValue.data(), ";", &vec);
                int32_t isize = (int32_t)vec.size();
                if ((int32_t)ESkillRange::mine_rect == info.m_rangeType
                    || (int32_t)ESkillRange::mine_sector == info.m_rangeType
                    || (int32_t)ESkillRange::target_self_sector == info.m_rangeType
                    )
                {
                    if (isize < 2)
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....rangeTypeValue param size error... skillid:%ld, rangeType:%d, rangeTypeValue:%s ", info.m_skillID, info.m_rangeType, info.m_rangeTypeValue.c_str());
                        return false;
                    }
                    cfg.rangeValue1 = vec[0];
                    cfg.rangeValue2 = vec[1];
                }
                else if ((int32_t)ESkillRange::mine_circle == info.m_rangeType
                         || (int32_t)ESkillRange::target_circle == info.m_rangeType
                         || (int32_t)ESkillRange::target_circle_lock == info.m_rangeType
                         || (int32_t)ESkillRange::bullet_rect == info.m_rangeType
                         || (int32_t)ESkillRange::target_var_rect == info.m_rangeType
                         || (int32_t)ESkillRange::target_pos == info.m_rangeType
                    )
                {
                    if (isize < 1)
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....rangeTypeValue param size error... skillid:%ld, rangeType:%d, rangeTypeValue:%s ", info.m_skillID, info.m_rangeType, info.m_rangeTypeValue.c_str());
                        return false;
                    }
                    cfg.rangeValue1 = vec[0];
                }
                else if ((int32_t)ESkillRange::angle_rect == info.m_rangeType)
                {
                    if (isize < 3)
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....rangeTypeValue param size error... skillid:%ld, rangeType:%d, rangeTypeValue:%s ", info.m_skillID, info.m_rangeType, info.m_rangeTypeValue.c_str());
                        return false;
                    }
                    cfg.rangeValue1 = vec[0];
                    cfg.rangeValue2 = vec[1];
                    cfg.rangeValue3 = vec[2];
                    if (cfg.rangeValue3 <= 0)
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....rangeTypeValue value error...cfg.rangeValue3 <= 0... skillid:%ld, rangeType:%d, rangeTypeValue:%s ", info.m_skillID, info.m_rangeType, info.m_rangeTypeValue.c_str());
                        return false;
                    }
                }
                
                //
                if (info.m_rangeTypeEx > (int32_t)ESkillRange::none && info.m_rangeType < (int32_t)ESkillRange::limit)
                {
                    vec.clear();
                    NFCommonApi::SplitStrToVecInt(info.m_rangeTypeValueEx.data(), ";", &vec);
                    isize = (int32_t)vec.size();
                    if ((int32_t)ESkillRange::mine_rect == info.m_rangeTypeEx
                        || (int32_t)ESkillRange::mine_sector == info.m_rangeTypeEx
                        || (int32_t)ESkillRange::target_self_sector == info.m_rangeTypeEx
                        )
                    {
                        if (isize < 2)
                        {
                            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....rangeTypeEx param size error... skillid:%ld, rangeType:%d, rangeTypeValue:%s ", info.m_skillID, info.m_rangeTypeEx, info.m_rangeTypeValueEx.c_str());
                            return false;
                        }
                        cfg.rangeValueEx1 = vec[0];
                        cfg.rangeValueEx2 = vec[1];
                    }
                    else if ((int32_t)ESkillRange::mine_circle == info.m_rangeTypeEx
                             || (int32_t)ESkillRange::target_circle == info.m_rangeTypeEx
                             || (int32_t)ESkillRange::target_circle_lock == info.m_rangeTypeEx
                             || (int32_t)ESkillRange::bullet_rect == info.m_rangeTypeEx
                             || (int32_t)ESkillRange::target_var_rect == info.m_rangeTypeEx
                             || (int32_t)ESkillRange::target_pos == info.m_rangeTypeEx
                        )
                    {
                        if (isize < 1)
                        {
                            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....rangeTypeEx param size error... skillid:%ld, rangeType:%d, rangeTypeValue:%s ", info.m_skillID, info.m_rangeTypeEx, info.m_rangeTypeValueEx.c_str());
                            return false;
                        }
                        cfg.rangeValueEx1 = vec[0];
                    }
                    else if ((int32_t)ESkillRange::angle_rect == info.m_rangeType)
                    {
                        if (isize < 3)
                        {
                            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....rangeTypeValue param size error... skillid:%ld, rangeType:%d, rangeTypeValue:%s ", info.m_skillID, info.m_rangeType, info.m_rangeTypeValue.c_str());
                            return false;
                        }
                        cfg.rangeValueEx1 = vec[0];
                        cfg.rangeValueEx2 = vec[1];
                        cfg.rangeValueEx3 = vec[2];
                        if (cfg.rangeValueEx3 <= 0)
                        {
                            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....rangeTypeValue value error...cfg.rangeValueEx3 <= 0... skillid:%ld, rangeType:%d, rangeTypeValue:%s ", info.m_skillID, info.m_rangeType, info.m_rangeTypeValue.c_str());
                            return false;
                        }
                    }
                }
            }
            //
            if (info.m_Relation > 0)
            {
                if ((int32_t)ESkillType::normal != info.m_skillType)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....normal skill has relation skill... skillid:%ld, skillType:%d, Relation:%ld ", info.m_skillID, info.m_skillType, info.m_Relation);
                    return false;
                }
                if (info.m_Relation == info.m_skillID)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....normal skill equal to relation skill... skillid:%ld, skillType:%d, Relation:%ld ", info.m_skillID, info.m_skillType, info.m_Relation);
                    return false;
                }
                auto prelationcfg = SkillSkillDesc::Instance()->GetDesc(info.m_Relation);
                if (nullptr == prelationcfg)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....can not find relation skill config... skillid:%ld, skillType:%d, Relation:%ld ", info.m_skillID, info.m_skillType, info.m_Relation);
                    return false;
                }
                //检查关联技能链
                SET_INT64 setrelation;
                setrelation.insert(info.m_skillID);
                setrelation.insert(info.m_Relation);
                //
                cfg.vecRelation.push_back(info.m_Relation);
                //
                int64_t relation_skill = prelationcfg->m_skillID;
                while (relation_skill > 0)
                {
                    if (relation_skill == info.m_skillID)
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....normal skill equal to next layer relation skill... skillid:%ld, skillType:%d, Relation:%ld ", info.m_skillID, info.m_skillType, relation_skill);
                        return false;
                    }
                    auto iterf = setrelation.find(prelationcfg->m_Relation);
                    if (iterf != setrelation.end())
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....same relation skill... skillid:%ld, skillType:%d, Relation:%ld ", info.m_skillID, info.m_skillType, relation_skill);
                        return false;
                    }
                    prelationcfg = SkillSkillDesc::Instance()->GetDesc(relation_skill);
                    if (nullptr == prelationcfg)
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....can not find relation skill config... skillid:%ld, skillType:%d, Relation:%ld ", info.m_skillID, info.m_skillType, relation_skill);
                        return false;
                    }
                    setrelation.insert(relation_skill);
                    cfg.vecRelation.push_back(relation_skill);
                    //
                    relation_skill = prelationcfg->m_Relation;
                }
            }
            for (auto& iterbuff : info.m_buff)
            {
                if (iterbuff.m_ID > 0)
                {
                    auto pbuffcfg = SkillBuffDesc::Instance()->GetDesc(iterbuff.m_ID);
                    if (nullptr == pbuffcfg)
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....can not find skill buff config... skillid:%ld, buffid:%ld ", info.m_skillID, iterbuff.m_ID);
                        return false;
                    }
                }
            }
            for (auto& iterwake : info.m_awakebuff)
            {
                if (iterwake.m_ID > 0)
                {
                    auto pbuffcfg = SkillBuffDesc::Instance()->GetDesc(iterwake.m_ID);
                    if (nullptr == pbuffcfg)
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....can not find skill wakeup buff config... skillid:%ld, buffid:%ld ", info.m_skillID, iterwake.m_ID);
                        return false;
                    }
                }
            }
            for (auto& iteradv1 : info.m_advanceType1buff)
            {
                if (iteradv1.m_ID > 0)
                {
                    auto pbuffcfg = SkillBuffDesc::Instance()->GetDesc(iteradv1.m_ID);
                    if (nullptr == pbuffcfg)
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....can not find skill advance1 buff config... skillid:%ld, buffid:%ld ", info.m_skillID, iteradv1.m_ID);
                        return false;
                    }
                }
            }
            for (auto& iteradv2 : info.m_advanceType2buff)
            {
                if (iteradv2.m_ID > 0)
                {
                    auto pbuffcfg = SkillBuffDesc::Instance()->GetDesc(iteradv2.m_ID);
                    if (nullptr == pbuffcfg)
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....can not find skill advance2 buff config... skillid:%ld, buffid:%ld ", info.m_skillID, iteradv2.m_ID);
                        return false;
                    }
                }
            }
            for (auto& iteradv3 : info.m_advanceType3buff)
            {
                if (iteradv3.m_ID > 0)
                {
                    auto pbuffcfg = SkillBuffDesc::Instance()->GetDesc(iteradv3.m_ID);
                    if (nullptr == pbuffcfg)
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....can not find skill advance3 buff config... skillid:%ld, buffid:%ld ", info.m_skillID, iteradv3.m_ID);
                        return false;
                    }
                }
            }
            if (!info.m_damageTime.empty())
            {
                VEC_INT32 vectime;
                NFCommonApi::SplitStrToVecInt(info.m_damageTime.data(), ";", &vectime);
                for (auto& iter : vectime)
                {
                    if (iter <= 0)
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....damageTime less than or equal zero... skillid:%ld, damageTime:%s ", info.m_skillID, info.m_damageTime.c_str());
                        return false;
                    }
                    cfg.vecDamage.push_back((uint32_t)iter);
                }
            }
            if (!info.m_damageTimeEx.empty())
            {
                VEC_INT32 vectime;
                NFCommonApi::SplitStrToVecInt(info.m_damageTimeEx.data(), ";", &vectime);
                for (auto& iter : vectime)
                {
                    if (iter <= 0)
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....damageTimeEx less than or equal zero... skillid:%ld, damageTime:%s ", info.m_skillID, info.m_damageTime.c_str());
                        return false;
                    }
                    cfg.vecDamageEx.push_back((uint32_t)iter);
                }
            }
            //
            if (info.m_group > 0)
            {
                auto itergroup = m_mapGroup.find(info.m_group);
                if (itergroup != m_mapGroup.end())
                {
                    itergroup->second.insert(info.m_skillID);
                }
                else
                {
                    SET_UINT64 setskill;
                    setskill.insert(info.m_skillID);
                    m_mapGroup[info.m_group] = setskill;
                }
            }
            
            if (!IsPassive(&cfg))
            {
                if (info.m_goalMaxNum > info.m_goalMaxNumMonster)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....info.goalMaxNum > info.goalMaxNumMonster... skillid:%ld, goalMaxNum:%d,goalMaxNumMonster:%d ", info.m_skillID, info.m_goalMaxNum, info.m_goalMaxNumMonster);
                    return false;
                }
                if (info.m_goalMaxNum <= 0 || info.m_goalMaxNumMonster <= 0)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] SkillMgr::Process....info.goalMaxNum <= 0 || info.goalMaxNumMonster <= 0... skillid:%ld, goalMaxNum:%d,goalMaxNumMonster:%d ", info.m_skillID, info.m_goalMaxNum, info.m_goalMaxNumMonster);
                    return false;
                }
            }
            
            auto iterf = m_cfg.find(info.m_skillID);
            if (iterf != m_cfg.end())
            {
                iterf->second = cfg;
            }
            else
            {
                m_cfg[info.m_skillID] = cfg;
            }
        }
        //处理前置关联技能
        for (auto& iter : m_cfg)
        {
            auto pCfg = iter.second.GetCfg();
            if (pCfg == NULL) { continue; }
            
            if (pCfg->m_Relation <= 0) { continue; }
            int64_t skillId = pCfg->m_skillID;
            auto iter_relation = m_cfg.find(pCfg->m_Relation);
            if (iter_relation != m_cfg.end()) { iter_relation->second.preRelation = skillId; }
        }
    }
    return true;
}

const SkillCfg* SkillDescEx::GetCfg(uint64_t skillid)
{
    auto iter = m_cfg.find(skillid);
    return (iter != m_cfg.end()) ? &iter->second : nullptr;
}

bool SkillDescEx::ValidUnlockType(int32_t type)
{
    return (type > (int32_t)ESkillUnlock::none && type < (int32_t)ESkillUnlock::limit);
}

bool SkillDescEx::IsPassive(uint64_t skillid)
{
    const SkillCfg* pcfg = GetCfg(skillid);
    return IsPassive(pcfg);
}

bool SkillDescEx::IsPassive(const SkillCfg* pcfg)
{
    if (nullptr == pcfg) { return false; }
    auto pCfgCfg = pcfg->GetCfg();
    if (nullptr == pCfgCfg) { return false; }
    return ((int32_t)ESkillTarget::Passive == pCfgCfg->m_type);
}

bool SkillDescEx::ValidRangeType(int32_t rangetype)
{
    return (rangetype > (int32_t)ESkillRange::none && rangetype < (int32_t)ESkillRange::limit);
}

bool SkillDescEx::IsLockRangeType(int32_t rangetype)
{
    return ((int32_t)ESkillRange::target == rangetype || (int32_t)ESkillRange::target_circle == rangetype || (int32_t)ESkillRange::target_circle_lock == rangetype || (int32_t)ESkillRange::target_self_sector == rangetype);
}

bool SkillDescEx::IsPosRangeType(int32_t rangetype)
{
    return ((int32_t)ESkillRange::target_pos == rangetype || (int32_t)ESkillRange::target_var_rect == rangetype);
}

const SET_UINT64* SkillDescEx::GetProfSkillList(int8_t prof)
{
    uint32_t group = GetProfSkillGroupId(prof);
    if (group <= 0) { return 0; }
    auto iter = m_mapGroup.find(group);
    return (iter != m_mapGroup.end()) ? &iter->second : nullptr;
}

uint32_t SkillDescEx::GetProfSkillGroupId(int8_t prof)
{
    if (!proto_ff::ERoleProf_IsValid(prof)) { return 0; }
    uint32_t group = 0;
    if (proto_ff::EROLE_PROF_MALE_MASTER == prof) { group = (uint32_t)ESkillGroup::male_master; }
    else if (proto_ff::EROLE_PROF_FEMALE_MASTER == prof) { group = (uint32_t)ESkillGroup::female_master; }
    else if (proto_ff::EROLE_PROF_MALE_SICKLE == prof) { group = (uint32_t)ESkillGroup::male_sickle; }
    else if (proto_ff::EROLE_PROF_FEMALE_SICKLE == prof) { group = (uint32_t)ESkillGroup::female_sickle; }
    else if (proto_ff::EROLE_PROF_MALE_SWORD == prof) { group = (uint32_t)ESkillGroup::male_sword; }
    else if (proto_ff::EROLE_PROF_FEMALE_SWORD == prof) { group = (uint32_t)ESkillGroup::female_sword; }
    else if (proto_ff::EROLE_PROF_MALE_KNIFE == prof) { group = (uint32_t)ESkillGroup::male_knife; }
    else if (proto_ff::EROLE_PROF_FEMALE_KNIFE == prof) { group = (uint32_t)ESkillGroup::female_knife; }
    return group;
}

bool SkillDescEx::IsGodSkill(uint64_t skillid)
{
    const SkillCfg* pcfg = GetCfg(skillid);
    return IsGodSkill(pcfg);
}

bool SkillDescEx::IsGodSkill(const SkillCfg* pcfg)
{
    if (nullptr == pcfg) { return false; }
    auto pCfgCfg = pcfg->GetCfg();
    if (nullptr == pCfgCfg) { return false; }
    return (pCfgCfg->m_group == (int32_t)GetGodSkillGroupId());
}

bool SkillDescEx::IsGodGroup(uint32_t groupid)
{
    return false;
}

bool SkillDescEx::IsRoleSkill(uint64_t skillid)
{
    const SkillCfg* pcfg = GetCfg(skillid);
    return IsRoleSkill(pcfg);
}

bool SkillDescEx::IsRoleSkill(const SkillCfg* pcfg)
{
    if (nullptr == pcfg) { return false; }
    auto pCfgCfg = pcfg->GetCfg();
    if (nullptr == pCfgCfg) { return false; }
    if (((int32_t)ESkillGroup::male_master == pCfgCfg->m_group)
        || ((int32_t)ESkillGroup::female_master == pCfgCfg->m_group)
        || ((int32_t)ESkillGroup::male_sickle == pCfgCfg->m_group)
        || ((int32_t)ESkillGroup::female_sickle == pCfgCfg->m_group)
        || ((int32_t)ESkillGroup::male_sword == pCfgCfg->m_group)
        || ((int32_t)ESkillGroup::female_sword == pCfgCfg->m_group)
        || ((int32_t)ESkillGroup::male_knife == pCfgCfg->m_group)
        || ((int32_t)ESkillGroup::female_knife == pCfgCfg->m_group)
        )
    {
        return true;
    }
    return false;
}

bool SkillDescEx::IsPetSkill(uint64_t skillid)
{
    const SkillCfg* pcfg = GetCfg(skillid);
    return IsPetSkill(pcfg);
}

bool SkillDescEx::IsPetSkill(const SkillCfg* pcfg)
{
    if (nullptr == pcfg) { return false; }
    auto pCfgCfg = pcfg->GetCfg();
    if (nullptr == pCfgCfg) { return false; }
    return (pCfgCfg->m_group == (int32_t)GetPetSkillGroupId());
}

bool SkillDescEx::IsSpiritSkill(uint64_t skillid)
{
    const SkillCfg* pcfg = GetCfg(skillid);
    return IsSpiritSkill(pcfg);
}

bool SkillDescEx::IsSpiritSkill(const SkillCfg* pcfg)
{
    if (nullptr == pcfg) { return false; }
    auto pCfgCfg = pcfg->GetCfg();
    if (nullptr == pCfgCfg) { return false; }
    return (pCfgCfg->m_group == (int32_t)GetSpiritSkillGroupId());
}

uint32_t SkillDescEx::GetAngerSkillGroupId()
{
    return (uint32_t)ESkillGroup::anger;
}

bool SkillDescEx::IsAngerSkill(uint64_t skillid)
{
    return (skillid == m_angerSkillId);
}

bool SkillDescEx::IsAngerSkill(const SkillCfg* pcfg)
{
    if (nullptr == pcfg) { return false; }
    return IsAngerSkill(pcfg->m_skillId);
}

bool SkillDescEx::IsNorContiSkill(const SkillCfg* pcfg)
{
    return false;
}

uint32_t SkillDescEx::GetPetSkillGroupId()
{
    return (uint32_t)ESkillGroup::pet;
}

uint32_t SkillDescEx::GetSpiritSkillGroupId()
{
    return (uint32_t)ESkillGroup::spirit;
}

uint32_t SkillDescEx::GetGodSkillGroupId()
{
    return (uint32_t)ESkillGroup::god;
}

bool SkillDescEx::IsPubCdSkill(uint64_t skillid)
{
    const SkillCfg* pcfg = GetCfg(skillid);
    return IsPubCdSkill(pcfg);
}

bool SkillDescEx::IsPubCdSkill(const SkillCfg* pcfg)
{
    if (nullptr == pcfg) { return false; }
    auto pCfgCfg = pcfg->GetCfg();
    if (nullptr == pCfgCfg) { return false; }
    return ((int32_t)ESkillType::none != pCfgCfg->m_skillType);
}

int64_t SkillDescEx::GetPubCd(const SkillCfg* pcfg)
{
    if (nullptr == pcfg) { return 0; }
    int64_t constid = 0;
    if (IsRoleSkill(pcfg)) { constid = proto_ff::EConst_RoleSkillPubCd; }
    else if (IsGodSkill(pcfg)) { constid = proto_ff::EConst_GodSkillPubCd; }
    else if (IsPetSkill(pcfg)) { constid = proto_ff::EConst_PetSkillPubCd; }
    else { return 0; }
    auto pInfo = ConstantConstantDesc::Instance()->GetDesc(constid);
    if (nullptr == pInfo) { return 0; }
    return pInfo->m_constantdata;
}

bool SkillDescEx::IsPriorityTarget(uint8_t srckind, uint8_t dstkind)
{
    return ((CREATURE_PLAYER == srckind || CREATURE_REBOT == srckind) && (CREATURE_PLAYER == dstkind));
}

int64_t SkillDescEx::GetSkillFight(uint64_t skillid, int32_t level)
{
    const SkillCfg* pcfg = GetCfg(skillid);
    return GetSkillFight(pcfg, level);
}

int64_t SkillDescEx::GetSkillFight(const SkillCfg* pcfg, int32_t level)
{
    if (nullptr == pcfg || level <= 0) { return 0; }
    auto pCfgCfg = pcfg->GetCfg();
    if (nullptr == pCfgCfg) { return 0; }
    /*
    初始战力+(系数+int(技能等级/10)*3)*(技能等级-1)
    */
    int64_t fight = pCfgCfg->m_fighting;
    if (level > 1) { fight += ((pCfgCfg->m_fightingParama + level / 10) * (level - 1)); }
    return fight;
}

bool SkillDescEx::IsAdvanceRateSkill(const SkillCfg* pcfg)
{
    if (nullptr == pcfg) { return false; }
    auto pCfgCfg = pcfg->GetCfg();
    if (nullptr == pCfgCfg) { return false; }
    if (!IsRoleSkill(pcfg)) { return false; }
    return (pCfgCfg->m_position > 0 && pCfgCfg->m_position < (int32_t)MAX_ROLE_SKILL_POS);
}

bool SkillDescEx::IsUnlockByAdv(uint64_t skillid)
{
    const SkillCfg* pcfg = GetCfg(skillid);
    return IsUnlockByAdv(pcfg);
}

bool SkillDescEx::IsUnlockByAdv(const SkillCfg* pcfg)
{
    if (nullptr == pcfg) { return false; }
    int32_t type = 0;
    int64_t p1 = 0;
    int64_t p2 = 0;
    GetSkillUnlockParam(pcfg, type, p1, p2);
    return ((int32_t)ESkillUnlock::advance == type);
}

bool SkillDescEx::IsUnlockByAdv(int32_t adv, const SkillCfg* pcfg)
{
    if (nullptr == pcfg) { return false; }
    int32_t type = 0;
    int64_t p1 = 0;
    int64_t p2 = 0;
    GetSkillUnlockParam(pcfg, type, p1, p2);
    return ((int32_t)ESkillUnlock::advance == type && p1 == (int64_t)adv);
}

void SkillDescEx::GetSkillUnlockParam(const SkillCfg* pcfg, int32_t& type, int64_t& param1, int64_t& param2)
{
    if (nullptr == pcfg) { return; }
    auto pCfgCfg = pcfg->GetCfg();
    if (nullptr == pCfgCfg) { return; }
    
    VEC_INT64 veccond;
    NFCommonApi::SplitStrToVecInt(pCfgCfg->m_unlockCondition.data(), ";", &veccond);
    uint32_t nsize = (uint32_t)veccond.size();
    if (nsize < 2) { return; }
    //条件4，进阶方向，进阶等级（如4;1;3表示进阶火等级3解锁，4;2;3表示进阶雷等级3解锁，4;3;3表示进阶冰等级3解锁
    type = veccond.at(0);
    param1 = veccond.at(1);
    if (nsize > 2) { param2 = veccond.at(2); }
}

bool SkillDescEx::IsMagWeaponSoulSkill(const SkillCfg* pcfg)
{
    if (nullptr == pcfg) { return false; }
    auto pCfgCfg = pcfg->GetCfg();
    if (nullptr == pCfgCfg) { return false; }
    return ((int32_t)ESkillType::magweapon == pCfgCfg->m_skillType);
}

bool SkillDescEx::IsCapSoulSkill(const SkillCfg* pcfg)
{
    if (nullptr == pcfg) { return false; }
    auto pCfgCfg = pcfg->GetCfg();
    if (nullptr == pCfgCfg) { return false; }
    return ((int32_t)ESkillType::cape == pCfgCfg->m_skillType);
}

bool SkillDescEx::IsSoulSacrifice(uint64_t skillid)
{
    auto pcfg = SoulSoulDesc::Instance()->GetDesc(1);
    if (nullptr == pcfg) { return false; }
    return (pcfg->m_sacrificeSkill == (int64_t)skillid);
}

int64_t SkillDescEx::GetSacrificeSkillId()
{
    auto pcfg = SoulSoulDesc::Instance()->GetDesc(1);
    return (nullptr != pcfg) ? pcfg->m_sacrificeSkill : 0;
}
