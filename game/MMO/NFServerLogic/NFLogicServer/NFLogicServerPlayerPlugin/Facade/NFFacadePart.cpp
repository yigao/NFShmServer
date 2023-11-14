// -------------------------------------------------------------------------
//    @FileName         :    NFFacadePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFFacadePart
//
// -------------------------------------------------------------------------

#include "NFFacadePart.h"
#include "DescStore/FacadeChangeDesc.h"
#include "NFComm/NFCore/NFCommonApi.h"
#include "DescStore/FacadeDisplayDesc.h"
#include "Skill/NFSkillPart.h"
#include "DescStore/FacadeSoulactiveDesc.h"
#include "DescStore/FacadeStarupDesc.h"
#include "DescStore/AttributeAttributeDesc.h"
#include "NFGameCommon/NFMath.h"
#include "NFLogicCommon/NFEventDefine.h"
#include "Package/NFPackagePart.h"
#include "proto_svr_event.pb.h"
#include "NFGrowPart.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFLogicCommon/NFRankDefine.h"
#include "Player/NFRankPart.h"

bool FacadeInfo::Init(NFFacadePart *pPart, const proto_ff::RoleDBData &dbData)
{
    InitShmObj(pPart);
    if (dbData.has_facade())
    {
        for (int i = 0; i < (int) dbData.facade().data_size(); i++)
        {
            auto &data = dbData.facade().data(i);
            if (data.facade_type() == m_facadeType)
            {
                LoadFromDB(data);
            }
        }
    }
    return true;
}

bool FacadeInfo::SaveDB(proto_ff::RoleDBData &characterDB)
{
    SaveToDB(characterDB.mutable_facade()->add_data());
    return true;
}

void FacadeInfo::LoadFromDB(const proto_ff::FacadeDataInfo &dbInfo)
{
    m_nFacadeID = dbInfo.facade_id();
    m_nFacadeLev = dbInfo.facade_lev();
    m_nFacadeExp = dbInfo.facade_exp();
    m_bUseSoulItem = dbInfo.use_soul_item();
    m_bUseFacade = dbInfo.use_facade();
    m_nEquipFantasyID = dbInfo.equip_fantasy_id();
    for (int i = 0; i < dbInfo.fantasy_map_size(); i++)
    {
        m_mapFantasyFacade.emplace(dbInfo.fantasy_map(i).fantasy_id(), dbInfo.fantasy_map(i).fantasy_lev());
    }
    
    for (int i = 0; i < dbInfo.fragment_map_size(); i++)
    {
        m_mapFragment.emplace(dbInfo.fragment_map(i).fragment_id(), dbInfo.fragment_map(i).use_times());
    }
    
    for (int i = 0; i < dbInfo.skill_data_size(); i++)
    {
        m_mapSkill.emplace(dbInfo.skill_data(i).skill_id(), dbInfo.skill_data(i).skill_lev());
    }
    
    if (dbInfo.has_soul_data())
    {
        m_soulInfo.LoadFromDB(dbInfo.soul_data());
    }
    else
    {
        m_soulInfo.InitData();
    }
}

void FacadeInfo::SaveToDB(proto_ff::FacadeDataInfo *pInfo)
{
    pInfo->set_facade_type(m_facadeType);
    pInfo->set_facade_id(m_nFacadeID);//= dbInfo.facade_id();
    pInfo->set_facade_lev(m_nFacadeLev);// = dbInfo.facade_lev();
    pInfo->set_facade_exp(m_nFacadeExp); // = dbInfo.facade_exp();
    pInfo->set_use_soul_item(m_bUseSoulItem); // = dbInfo.use_soul_item();
    pInfo->set_use_facade(m_bUseFacade); // = dbInfo.use_facade();
    pInfo->set_equip_fantasy_id(m_nEquipFantasyID); // = dbInfo.equip_fantasy_id();
    
    for (auto iter = m_mapFantasyFacade.begin(); iter != m_mapFantasyFacade.end(); iter++)
    {
        auto pFantasyInfo = pInfo->add_fantasy_map();
        pFantasyInfo->set_fantasy_id(iter->first);
        pFantasyInfo->set_fantasy_lev(iter->second);
    }
    
    for (auto iter = m_mapFragment.begin(); iter != m_mapFragment.end(); iter++)
    {
        auto pFragmentInfo = pInfo->add_fragment_map();
        pFragmentInfo->set_fragment_id(iter->first);
        pFragmentInfo->set_use_times(iter->second);
    }
    
    for (auto iter = m_mapSkill.begin(); iter != m_mapSkill.end(); iter++)
    {
        auto pSkillInfo = pInfo->add_skill_data();
        pSkillInfo->set_skill_id(iter->first);
        pSkillInfo->set_skill_lev(iter->second);
    }
    
    m_soulInfo.SaveToDB(pInfo->mutable_soul_data());
}

void FacadeInfo::GetFacade(proto_ff::RoleFacadeProto &facadeProto)
{
    auto pInfo = facadeProto.add_growfacade();
    pInfo->set_id(m_facadeType + proto_ff::GrowType_WING_TYPE - 1);
    if (m_bUseFacade)
    {
        pInfo->set_value(m_nFacadeID);
    }
    else
    {
        pInfo->set_value(m_nEquipFantasyID);
    }
}

void FacadeInfo::GetFacadeInfo(proto_ff::FacadeInfoRsp &rsp)
{
    rsp.set_facade_type(m_facadeType);
    rsp.set_facade_id(m_nFacadeID);
    rsp.set_facade_lev(m_nFacadeLev);
    rsp.set_facade_exp(m_nFacadeExp);
    rsp.set_use_facade(m_bUseFacade);
    
    rsp.set_use_soul_item(m_bUseSoulItem);
    for (auto iter = m_mapFragment.begin(); iter != m_mapFragment.end(); iter++)
    {
        proto_ff::FacadeFragmentData *pData = rsp.add_fragment_data();
        if (pData)
        {
            pData->set_fragment_id(iter->first);
            pData->set_use_times(iter->second);
        }
    }
    
    for (auto iter = m_mapSkill.begin(); iter != m_mapSkill.end(); iter++)
    {
        proto_ff::FacadeSkillData *pData = rsp.add_skill_data();
        if (pData)
        {
            pData->set_skill_id(iter->first);
            pData->set_skill_lev(iter->second);
        }
    }
    
    rsp.set_fight_value(GetFightValue());
}

void FacadeInfo::GetFacadeFantasyInfo(proto_ff::FacadeFantasyInfoRsp &rsp)
{
    rsp.set_facade_type(m_facadeType);
    rsp.set_equip_fantasy_id(m_nEquipFantasyID);
    for (auto iter = m_mapFantasyFacade.begin(); iter != m_mapFantasyFacade.end(); iter++)
    {
        proto_ff::FacadeFantasyData *pData = rsp.add_fantasy_data();
        if (pData)
        {
            pData->set_fantasy_id(iter->first);
            pData->set_fantasy_lev(iter->second);
        }
    }
}

int FacadeInfo::GetSkillLev(int64_t skillId)
{
    if (m_mapSkill.find(skillId) != m_mapSkill.end())
    {
        return m_mapSkill[skillId];
    }
    return 0;
}

void FacadeInfo::SetSkillInfo(int64_t skillId, uint32_t lev)
{
    m_mapSkill[skillId] = lev;
}

int FacadeInfo::GetFacadeFantasyQualityNum(int quality)
{
    int num = 0;
    for (auto iter = m_mapFantasyFacade.begin(); iter != m_mapFantasyFacade.end(); iter++)
    {
        auto pFantasyInfo = FacadeChangeDesc::Instance()->GetDesc(iter->first);
        if (pFantasyInfo)
        {
            if (pFantasyInfo->m_quality == quality)
            {
                num++;
            }
        }
    }
    return num;
}

void FacadeInfo::ActiveDefaultFacade(bool bSync)
{
    if (m_nFacadeLev == 0)
    {
        auto pDisplayCfgInfo = GetDefaultFacadeDisplay();
        if (pDisplayCfgInfo)
        {
            m_nFacadeExp = 0;
            
            m_nFacadeID = pDisplayCfgInfo->m_id;
            m_nFacadeLev = 1;
            m_bUseFacade = true;
            
            VEC_STRING vecString;
            NFCommonApi::SplitStr(pDisplayCfgInfo->m_skillID.data(), "|", &vecString);
            for (int i = 0; i < (int) vecString.size(); i++)
            {
                std::string skillStr = vecString[i];
                if (!skillStr.empty())
                {
                    VEC_INT64 vecNum;
                    NFCommonApi::SplitStrToVecInt(skillStr, ";", &vecNum);
                    if (vecNum.size() == 2)
                    {
                        m_mapSkill.emplace(vecNum[0], 0);
                    }
                }
            }
        }
    }
}

const proto_ff_s::E_FacadeDisplay_s *FacadeInfo::GetDefaultFacadeDisplay()
{
    auto pMap = FacadeDisplayDesc::Instance()->GetResDescPtr();
    for (auto iter = pMap->begin(); iter != pMap->end(); ++iter)
    {
        if ((uint32_t) iter->second.m_type == m_facadeType)
        {
            if (m_facadeType == proto_ff::FACADE_ARTIFACT_TYPE)
            {
                VEC_INT32 vecNum;
                NFCommonApi::SplitStrToVecInt(iter->second.m_professionID.data(), ";", &vecNum);
                for (int i = 0; i < (int) vecNum.size(); i++)
                {
                    NFPlayer *pPlayer = GetMaster();
                    if (pPlayer && (int) pPlayer->GetAttr(proto_ff::A_PROF) == vecNum[i])
                    {
                        return &iter->second;
                    }
                }
            }
            else
            {
                return &iter->second;
            }
        }
    }
    return NULL;
}

const proto_ff_s::E_FacadeDisplay_s *FacadeInfo::GetCurFacadeDisplay()
{
    return FacadeDisplayDesc::Instance()->GetDesc(m_nFacadeID);
}

int64_t FacadeInfo::GetFightValue()
{
    MAP_INT32_INT64 allAttr;
    calcAttr(allAttr);
    
    double nFightTotal = 0;
    for (auto iter = allAttr.begin(); iter != allAttr.end(); iter++)
    {
        auto pcfg = AttributeAttributeDesc::Instance()->GetDesc(iter->first);
        if (nullptr == pcfg || pcfg->m_power <= EPS) { continue; }
        if (!IsSpecAttr(iter->first))
        {
            nFightTotal += iter->second * pcfg->m_power;
        }
    }
    
    return nFightTotal;
}

const proto_ff_s::E_FacadeStarup_s *FacadeInfo::GetFacadeStarInfo(int64_t attrId, int32_t startId)
{
    return FacadeStarupDesc::Instance()->GetDescByUpattributeidStarid(attrId, startId);
}

int32_t FacadeInfo::GetFantasyTotalLv()
{
    int32_t lv = 0;
    for (auto &e : m_mapFantasyFacade)
    {
        lv += e.second;
    }
    return lv;
}

bool FacadeInfo::ProcessSoulActivity(int32_t type, int32_t param)
{
    auto pMaster = GetMaster();
    CHECK_EXPR(pMaster, false, "");
    
    bool has = false;
    proto_ff::FacadeSoulActivityNotify notify;
    notify.set_facade_type(m_facadeType);
    for (auto iter = m_soulInfo.m_soulActivityInfo.begin(); iter != m_soulInfo.m_soulActivityInfo.end(); iter++)
    {
        if (iter->second == proto_ff::FACADE_SOUL_ACTIVITY_STATUS_NONE)
        {
            auto pCfgInfo = FacadeSoulachievementDesc::Instance()->GetDesc(iter->first);
            if (pCfgInfo->m_type == type)
            {
                if (type == FACADE_SOUL_ACTIVITY_TYPE_LEVEL)
                {
                    if (param >= pCfgInfo->m_parama)
                    {
                        has = true;
                        iter->second = proto_ff::FACADE_SOUL_ACTIVITY_STATUS_CAN_RECV;
                    }
                }
                else if (type == FACADE_SOUL_ACTIVITY_TYPE_FANTASY)
                {
                    if (param == pCfgInfo->m_parama)
                    {
                        has = true;
                        iter->second = proto_ff::FACADE_SOUL_ACTIVITY_STATUS_CAN_RECV;
                    }
                }
            }
        }
    }
    
    if (has)
    {
        m_soulInfo.WriteToProto(notify.mutable_soul_data());
        pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVITY_NOTIFY, notify);
    }
    
    return has;
}

bool FacadeInfo::ProcessSoulSkill()
{
    auto pMaster = GetMaster();
    CHECK_EXPR(pMaster, false, "");
    NFSkillPart *pSkillPart = dynamic_cast<NFSkillPart *>(pMaster->GetPart(PART_SKILL));
    CHECK_EXPR(pSkillPart, false, "");
    
    bool has = false;
    proto_ff::FacadeSoulSkillNotify notify;
    notify.set_facade_type(m_facadeType);
    for (auto iter = m_soulInfo.m_soulSkillInfo.begin(); iter != m_soulInfo.m_soulSkillInfo.end(); iter++)
    {
        if (iter->second == proto_ff::FACADE_SOUL_SKILL_STATUS_NONE)
        {
            auto pCfInfo = FacadeSoulactiveDesc::Instance()->GetDesc(iter->first);
            if (pCfInfo)
            {
                uint32_t finish_num = 0;
                for (int j = 0; j < (int) pCfInfo->m_unlock.size(); j++)
                {
                    int32_t cond = pCfInfo->m_unlock[j].m_condition;
                    std::string param = pCfInfo->m_unlock[j].m_parama.data();
                    switch (cond)
                    {
                        case FACADE_SOUL_SKILL_ACTIVE_TYPE_ACTIVE_WING:
                        case FACADE_SOUL_SKILL_ACTIVE_TYPE_ACTIVE_TREASURE:
                        case FACADE_SOUL_SKILL_ACTIVE_TYPE_ACTIVE_PARTNER:
                        {
                            std::vector<int32_t> paramInt;
                            NFCommonApi::SplitStrToVecInt(param, ";", &paramInt);
                            if (paramInt.size() >= 2)
                            {
                                int32_t quality = paramInt[0];
                                int32_t num = paramInt[1];
                                int32_t curNum = GetFacadeFantasyQualityNum(quality);
                                if (curNum >= num)
                                {
                                    finish_num++;
                                }
                            }
                            break;
                        }
                        case FACADE_SOUL_SKILL_ACTIVE_TYPE_WING_SOUL_LEVEL:
                        case FACADE_SOUL_SKILL_ACTIVE_TYPE_TREASURE_SOUL_LEVEL:
                        case FACADE_SOUL_SKILL_ACTIVE_TYPE_PARTNER_SOUL_LEVEL:
                        {
                            int level = NFCommonApi::StrToInt(param);
                            if ((int) m_soulInfo.m_soulLevel >= level)
                            {
                                finish_num++;
                            }
                            break;
                        }
                        default:break;
                    }
                }
                
                if (finish_num >= (uint32_t) pCfInfo->m_unlock.size())
                {
                    iter->second = proto_ff::FACADE_SOUL_SKILL_STATUS_ACTIVED;
                    has = true;
                    
                    SCommonSource src;
                    pSkillPart->AddSkill(iter->first, 1, src, true);
                }
            }
        }
    }
    
    if (has)
    {
        m_soulInfo.WriteToProto(notify.mutable_soul_data());
        pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_SKILL_INFO_NOTIFY, notify);
    }
    
    return has;
}

bool FacadeInfo::ProcessFantasyLevel(int64_t fantasyId, int32_t level)
{
    auto pMaster = GetMaster();
    CHECK_EXPR(pMaster, false, "");
    
    auto pCfg = FacadeChangeDesc::Instance()->GetDesc(fantasyId);
    if (pCfg == nullptr || level <= 0)
    {
        return false;
    }
    
    if (pCfg->m_upAttributeId <= 0)
    {
        return false;
    }
    
    auto pCfg1 = GetFacadeStarInfo(pCfg->m_upAttributeId, level);
    if (!pCfg1)
    {
        return false;
    }
    
    NFSkillPart *pSkillPart = dynamic_cast<NFSkillPart *>(pMaster->GetPart(PART_SKILL));
    if (pSkillPart && pCfg1->m_skillID > 0 && !pSkillPart->GetSkillInfo(pCfg1->m_skillID))
    {
        SCommonSource src;
        pSkillPart->AddSkill(pCfg1->m_skillID, 1, src, true);
    }
    return true;
}

void FacadeInfo::calcAdvanceAttr(MAP_INT32_INT64 &outAttr)
{
    auto pCfg = FacadeValueDesc::Instance()->GetDesc(m_nFacadeLev);
    if (pCfg == nullptr) { return; }
    
    if (m_facadeType == proto_ff::FACADE_WING_TYPE)
    {
        for (int i = 0; i < (int) pCfg->m_wingAttribute.size(); i++)
        {
            int nAttrId = pCfg->m_wingAttribute.at(i).m_type;
            if (nAttrId > 0)
            {
                int64_t nAttrValue = pCfg->m_wingAttribute.at(i).m_value;
                outAttr[nAttrId] += nAttrValue;
            }
        }
    }
    else if (m_facadeType == proto_ff::FACADE_TREASURE_TYPE)
    {
        for (int i = 0; i < (int) pCfg->m_treasureAttribute.size(); i++)
        {
            int nAttrId = pCfg->m_treasureAttribute.at(i).m_type;
            int64_t nAttrValue = pCfg->m_treasureAttribute.at(i).m_value;
            outAttr[nAttrId] += nAttrValue;
        }
    }
    else if (m_facadeType == proto_ff::FACADE_ARTIFACT_TYPE)
    {
        for (int i = 0; i < (int) pCfg->m_ArtifactAttribute.size(); i++)
        {
            int nAttrId = pCfg->m_ArtifactAttribute.at(i).m_type;
            int64_t nAttrValue = pCfg->m_ArtifactAttribute.at(i).m_value;
            outAttr[nAttrId] += nAttrValue;
        }
    }
    else if (m_facadeType == proto_ff::FACADE_PARTNER_TYPE)
    {
        for (int i = 0; i < (int) pCfg->m_BladeAttribute.size(); i++)
        {
            int nAttrId = pCfg->m_BladeAttribute.at(i).m_type;
            int64_t nAttrValue = pCfg->m_BladeAttribute.at(i).m_value;
            outAttr[nAttrId] += nAttrValue;
        }
    }
}

void FacadeInfo::calcFantasyAttr(MAP_INT32_INT64 &outAttr)
{
    for (auto iter = m_mapFantasyFacade.begin(); iter != m_mapFantasyFacade.end(); iter++)
    {
        calcFantasyAttr(iter->first, iter->second, outAttr);
    }
}

void FacadeInfo::calcFantasyAttr(int64_t fantasyId, int32_t level, MAP_INT32_INT64 &outAttr)
{
    auto pCfg = FacadeChangeDesc::Instance()->GetDesc(fantasyId);
    if (pCfg == nullptr) { return; }
    
    for (int i = 0; i < (int) pCfg->m_ActiveAttribute.size(); i++)
    {
        int nAttrId = pCfg->m_ActiveAttribute.at(i).m_type;
        outAttr[nAttrId] += pCfg->m_ActiveAttribute.at(i).m_value;
    }
    
    if (level > 0)
    {
        for (int i = 0; i < (int) pCfg->m_attribute.size(); i++)
        {
            int nAttrId = pCfg->m_attribute.at(i).m_type;
            outAttr[nAttrId] += pCfg->m_attribute.at(i).m_value * (1 + pCfg->m_starBer / F_TEN_THOUSAND * (level - 1));
        }
    }
    
    if (pCfg->m_upAttributeId > 0)
    {
        for (int32_t i = 0; i <= level; i++)
        {
            auto pCfg1 = GetFacadeStarInfo(pCfg->m_upAttributeId, i);
            if (!pCfg1)
            {
                continue;
            }
            for (const auto &e : pCfg1->m_upAttribute)
            {
                int32_t nAttrId = e.m_type;
                int32_t value = e.m_value;
                outAttr[nAttrId] += value;
            }
        }
    }
}

void FacadeInfo::calcFragmentAttr(MAP_INT32_INT64 &outAttr)
{
    for (auto iter = m_mapFragment.begin(); iter != m_mapFragment.end(); iter++)
    {
        calcFragmentAttr(iter->first, iter->second, outAttr);
    }
}

void FacadeInfo::calcFragmentAttr(int64_t fragmentId, int32_t nTimes, MAP_INT32_INT64 &outAttr)
{
    auto pCfg = FacadeFragmentDesc::Instance()->GetDesc(fragmentId);
    if (pCfg == nullptr || nTimes == 0) { return; }
    
    for (int i = 0; i < (int) pCfg->m_attribute.size(); i++)
    {
        int nAttrId = pCfg->m_attribute[i].m_type;
        outAttr[nAttrId] += nTimes * pCfg->m_attribute[i].m_value;
    }
}

void FacadeInfo::calcSoulAttr(int64_t soulId, int32_t level, MAP_INT32_INT64 &outAttr)
{
    auto pCfg = FacadeSoulDesc::Instance()->GetDesc(soulId);
    if (pCfg == nullptr) { return; }
    
    for (int i = 0; i < (int) pCfg->m_attribute.size(); i++)
    {
        int nAttrId = pCfg->m_attribute[i].m_type;
        if (nAttrId > 0)
        {
            outAttr[nAttrId] += pCfg->m_attribute[i].m_value;
        }
    }
    
    auto pSoulLvCfg = FacadeSoullvDesc::Instance()->GetDescBySoulidSoulllv(soulId, level);
    if (pSoulLvCfg == nullptr) { return; }
    
    for (int i = 0; i < (int) pSoulLvCfg->m_attribute.size(); i++)
    {
        int nAttrId = pSoulLvCfg->m_attribute[i].m_type;
        outAttr[nAttrId] += pSoulLvCfg->m_attribute[i].m_value;
    }
}

void FacadeInfo::calcAttr(MAP_INT32_INT64& allAttr)
{
    MAP_INT32_INT64 partAttr;
    
    calcAdvanceAttr(partAttr);
    MergeAttr(partAttr, allAttr);
    partAttr.clear();
    
    calcFantasyAttr(partAttr);
    MergeAttr(partAttr, allAttr);
    partAttr.clear();
    
    MAP_INT32_FLOAT mapattr;  // 属性ID-属性值
    MAP_INT32_FLOAT mapattradd;  //特殊属性加成 属性ID-加成百分比
    for (auto it = allAttr.begin(); it != allAttr.end(); it++)
    {
        int32_t attrId = it->first;
        int64_t value = it->second;
        mapattr[attrId] += value;
        if (IsSpecAttr(attrId))
        {
            mapattradd[attrId] += value;
        }
    }
    
    calcFragmentAttr(partAttr);
    MergeAttr(partAttr, allAttr);
    partAttr.clear();
    
    calcSoulAttr(m_soulInfo.m_soulId, m_soulInfo.m_soulLevel, partAttr);
    MergeAttr(partAttr, allAttr);
    partAttr.clear();
    
    for (auto it = mapattradd.begin(); it != mapattradd.end(); it++)
    {
        for (auto iter = mapattr.begin(); iter != mapattr.end(); iter++)
        {
            allAttr[iter->first] += iter->second * it->second / F_TEN_THOUSAND;
        }
    }
}

void FacadeInfo::MergeAttr(const MAP_INT32_INT64 &src, MAP_INT32_INT64 &dst)
{
    for (auto &e : src)
    {
        dst[e.first] += e.second;
    }
}

void FacadeInfo::PrintAttr(const MAP_INT32_INT64 &attr)
{

}

void FacadeInfo::OnCalc()
{
    auto pMaster = GetMaster();
    CHECK_EXPR(pMaster, , "");
    if (m_facadeType == proto_ff::FACADE_WING_TYPE)
    {
        //翅膀战力改变事件
        proto_ff::WingFightChgEvent chgEvent;
        chgEvent.set_cid(pMaster->Cid());
        chgEvent.set_fight(GetFightValue());
        if (chgEvent.fight() > 0)
        {
            NFRankPart* pRankPart = dynamic_cast<NFRankPart*>(pMaster->GetPart(PART_RANK));
            if (pRankPart)
            {
                pRankPart->UpdateRank(RANK_TYPE_WING_FIGHT, chgEvent.fight());
            }
            pMaster->FireExecute(NF_ST_LOGIC_SERVER, EVENT_WING_FIGHT_CHANGE, CREATURE_PLAYER, pMaster->Cid(), chgEvent);
        }
    }
    else if (m_facadeType == proto_ff::FACADE_TREASURE_TYPE)
    {
        //战力改变事件
        proto_ff::TreasureFightChgEvent chgEvent;
        chgEvent.set_cid(pMaster->Cid());
        chgEvent.set_fight(GetFightValue());
        if (chgEvent.fight() > 0)
        {
            pMaster->FireExecute(NF_ST_LOGIC_SERVER, EVENT_TREASURE_FIGHT_CHANGE, CREATURE_PLAYER, pMaster->Cid(), chgEvent);
        }
    }
    else if (m_facadeType == proto_ff::FACADE_ARTIFACT_TYPE)
    {
        //战力改变事件
        proto_ff::ArtifactFightChgEvent chgEvent;
        chgEvent.set_cid(pMaster->Cid());
        chgEvent.set_fight(GetFightValue());
        if (chgEvent.fight() > 0)
        {
            pMaster->FireExecute(NF_ST_LOGIC_SERVER, EVENT_ARTIFACT_FIGHT_CHANGE, CREATURE_PLAYER, pMaster->Cid(), chgEvent);
        }
    }
    else if (m_facadeType == proto_ff::FACADE_PARTNER_TYPE)
    {
        //战力改变事件
        proto_ff::PartnerFightChgEvent chgEvent;
        chgEvent.set_cid(pMaster->Cid());
        chgEvent.set_fight(GetFightValue());
        if (chgEvent.fight() > 0)
        {
            pMaster->FireExecute(NF_ST_LOGIC_SERVER, EVENT_PARTNER_FIGHT_CHANGE, CREATURE_PLAYER, pMaster->Cid(), chgEvent);
        }
    }
}

NFFacadePart *FacadeInfo::GetFacadePart()
{
    auto pPart = dynamic_cast<NFFacadePart *>(GetShmObj());
    CHECK_EXPR(pPart, nullptr, "GetShmObj Failed");
    return pPart;
}

NFPlayer *FacadeInfo::GetMaster()
{
    NFFacadePart *pPart = GetFacadePart();
    CHECK_EXPR(pPart, nullptr, "GetFacadePart Failed");
    return pPart->GetMaster();
}

NFFacadePart::NFFacadePart()
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

NFFacadePart::~NFFacadePart()
{
}

int NFFacadePart::CreateInit()
{
    m_facadeInfo.resize(m_facadeInfo.max_size());
    for (int i = 0; i < (int) m_facadeInfo.size(); i++)
    {
        m_facadeInfo[i].m_facadeType = i + 1;
    }
    return 0;
}

int NFFacadePart::ResumeInit()
{
    return 0;
}

int NFFacadePart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData)
{
    NFPart::Init(pMaster, partType, dbData);
    for (int i = 0; i < (int) m_facadeInfo.size(); i++)
    {
        m_facadeInfo[i].Init(this, dbData);
    }
    
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_FUNCTIONUNLOCK, CREATURE_PLAYER, m_pMaster->Cid(), "FacadePart::Init");
    return 0;
}

int NFFacadePart::UnInit()
{
    return NFPart::UnInit();
}

int NFFacadePart::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
{
    switch (nEventID)
    {
        case EVENT_FUNCTIONUNLOCK:
        {
            const proto_ff::FunctionUnlockEvent *pEvent = dynamic_cast<const proto_ff::FunctionUnlockEvent *>(pMessage);
            CHECK_NULL(pEvent);
            
            if (pEvent->functionid() == proto_ff::FunctionUnlock_ID_TYPE_WING)
            {
                ActiveDefaultFacade(proto_ff::FACADE_WING_TYPE);
            }
            else if (pEvent->functionid() == proto_ff::FunctionUnlock_ID_TYPE_TREASURE)
            {
                ActiveDefaultFacade(proto_ff::FACADE_TREASURE_TYPE);
            }
            else if (pEvent->functionid() == proto_ff::FunctionUnlock_ID_TYPE_ARTIFACT)
            {
                ActiveDefaultFacade(proto_ff::FACADE_ARTIFACT_TYPE);
            }
            else if (pEvent->functionid() == proto_ff::FunctionUnlock_ID_TYPE_PARTNER)
            {
                ActiveDefaultFacade(proto_ff::FACADE_PARTNER_TYPE);
            }
            break;
        }
        default:
            break;
    }
    return 0;
}

int NFFacadePart::LoadFromDB(const proto_ff::RoleDBData &data)
{
    return NFPart::LoadFromDB(data);
}

int NFFacadePart::InitConfig(const proto_ff::RoleDBData &data)
{
    return NFPart::InitConfig(data);
}

int NFFacadePart::SaveDB(proto_ff::RoleDBData &dbData)
{
    for (int i = 0; i < (int) m_facadeInfo.size(); i++)
    {
        m_facadeInfo[i].SaveDB(dbData);
    }
    return 0;
}

int NFFacadePart::OnLogin()
{
    return NFPart::OnLogin();
}

int NFFacadePart::OnLogin(proto_ff::PlayerInfoRsp &playerInfo)
{
    return NFPart::OnLogin(playerInfo);
}

int NFFacadePart::DailyZeroUpdate()
{
    return NFPart::DailyZeroUpdate();
}

int NFFacadePart::FillFacadeProto(proto_ff::RoleFacadeProto &outproto)
{
    for (int i = 0; i < (int) m_facadeInfo.size(); i++)
    {
        m_facadeInfo[i].GetFacade(outproto);
    }
    return 0;
}

int NFFacadePart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_INFO_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_LEVUP_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_DRESS_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_UNDRESS_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_FRAGEMNT_USE_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_FANTASY_INFO_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_FANTASY_ACTIVE_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_FANTASY_LEVELUP_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_FANTASY_DRESS_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_FANTASY_UNDRESS_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_SKILL_LEV_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_BUY_SOUL_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_SOUL_INFO_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_SOUL_ACTIVE_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_SOUL_LEVELUP_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_SOUL_ACTIVITY_RECV_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_FACADE_SOUL_RESET_SKILL_REQ);
    return 0;
}

int NFFacadePart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_TO_LOGIC_FACADE_INFO_REQ:
        {
            OnHandleFacadeInfo(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_FACADE_LEVUP_REQ:
        {
            OnHandleLevelUp(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_FACADE_DRESS_REQ:
        {
            OnHandleDress(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_FACADE_UNDRESS_REQ:
        {
            OnHandleUnDress(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_FACADE_FRAGEMNT_USE_REQ:
        {
            OnHandleFragmentUse(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_FACADE_FANTASY_INFO_REQ:
        {
            OnHandleFacadeFantasyInfo(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_FACADE_FANTASY_ACTIVE_REQ:
        {
            OnHandleFastasyActiveInfo(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_FACADE_FANTASY_LEVELUP_REQ:
        {
            OnHandleFantasyLevelupInfo(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_FACADE_FANTASY_DRESS_REQ:
        {
            OnHandleFantasyDress(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_FACADE_FANTASY_UNDRESS_REQ:
        {
            OnHandleFantasyUnDress(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_FACADE_SKILL_LEV_REQ:
        {
            OnHandleFacadeSkillLev(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_FACADE_BUY_SOUL_REQ:
        {
            OnHandleFacadeBuySoulReq(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_FACADE_SOUL_INFO_REQ:
        {
            OnHandleFacadeSoulInfoReq(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_FACADE_SOUL_ACTIVE_REQ:
        {
            OnHandleSoulActiveReq(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_FACADE_SOUL_LEVELUP_REQ:
        {
            OnHandleSoulLevelupReq(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_FACADE_SOUL_ACTIVITY_RECV_REQ:
        {
            OnHandleSoulActivityRecvReq(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_LOGIC_FACADE_SOUL_RESET_SKILL_REQ:
        {
            OnHandleSoulResetSkillReq(msgId, packet);
            break;
        }
        default:break;
    }
    return 0;
}

int NFFacadePart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

int NFFacadePart::OnHandleFacadeInfo(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeInfoReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    _OnHandleFacadeInfo(xData.facade_type());
    return 0;
}

int NFFacadePart::_OnHandleFacadeInfo(uint32_t facadeType)
{
    proto_ff::FacadeInfoRsp xDataRsp;
    xDataRsp.set_facade_type(facadeType);
    
    auto pInfo = GetFacadeInfo(facadeType);
    if (pInfo)
    {
        pInfo->GetFacadeInfo(xDataRsp);
    }
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_INFO_RSP, xDataRsp);
    return 0;
}

int NFFacadePart::OnHandleLevelUp(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeLevupReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    uint64_t materialId = xData.material_id();
    proto_ff::FacadeLevupRsp xDataRsp;
    xDataRsp.set_facade_type(xData.facade_type());
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    FacadeInfo *pFacadeInfo = GetFacadeInfo(xData.facade_type());
    if (pFacadeInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleLevelUp xData.facade_type():%d error", xData.facade_type());
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_LEVUP_RSP, xDataRsp);
        return 0;
    }
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    CHECK_NULL(pPackagePart);
    
    SCommonSource sourceParam;
    if (xData.facade_type() == proto_ff::FACADE_WING_TYPE)
    {
        sourceParam.src = S_Wing_Levup;
    }
    else if (xData.facade_type() == proto_ff::FACADE_TREASURE_TYPE)
    {
        sourceParam.src = S_Treasure_Levup;
    }
    else if (xData.facade_type() == proto_ff::FACADE_ARTIFACT_TYPE)
    {
        sourceParam.src = S_Artifact_Levup;
    }
    else if (xData.facade_type() == proto_ff::FACADE_PARTNER_TYPE)
    {
        sourceParam.src = S_Partner_Levup;
    }
    
    sourceParam.param1 = pFacadeInfo->m_nFacadeID;
    sourceParam.param2 = pFacadeInfo->m_nFacadeLev;
    
    auto pCurCfg = GetAdvanceFacadeCfgByLevel(pFacadeInfo->m_nFacadeLev);
    if (pCurCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleLevelUp pCurCfg == nullptr,currentLev=%u", pFacadeInfo->m_nFacadeLev);
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_LEVUP_RSP, xDataRsp);
        return 0;
    }
    
    auto pNextCfg = GetAdvanceFacadeCfgByLevel(pFacadeInfo->m_nFacadeLev + 1);
    if (pNextCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleLevelUp pCurCfg == nullptr,currentLev=%u, nextLev=%u", pFacadeInfo->m_nFacadeLev,
                      pFacadeInfo->m_nFacadeLev + 1);
        xDataRsp.set_ret_code(proto_ff::RET_FACADE_MAX_LEVEL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_LEVUP_RSP, xDataRsp);
        return 0;
    }
    
    auto pFacadeCfg = pFacadeInfo->GetCurFacadeDisplay();
    if (pFacadeCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleLevelUp GetCurFacadeDisplay == nullptr,currentLev=%u", pFacadeInfo->m_nFacadeID);
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_LEVUP_RSP, xDataRsp);
        return 0;
    }
    
    bool bSuccess = false;
    for (int i = 0; i < (int) pFacadeCfg->m_material.size(); i++)
    {
        auto& cfg = pFacadeCfg->m_material[i];
        if (materialId != (uint64_t) cfg.m_id)
        {
            continue;
        }
        
        int64_t bindNum = 0;
        int64_t unBindNum = 0;
        uint32_t itemNum = pPackagePart->GetItemNum(materialId, bindNum, unBindNum);
        //最大可使用数量（升级到满级）
        uint32_t needMax = CalNeedItemNum(pFacadeCfg->m_type, pFacadeInfo->m_nFacadeLev, cfg.m_exp);
        if (0 == needMax)
        {
            break;
        }
        
        uint32_t useItemNum = itemNum > needMax ? needMax : itemNum; //实际使用数量
        
        if (useItemNum > 0)
        {
            LIST_ITEM lstItem;
            SItem item;
            item.nItemID = materialId;
            item.nNum = useItemNum;
            item.byBind = EBindState_all;
            lstItem.push_back(item);
            if (!pPackagePart->RemoveItem(lstItem, sourceParam))
            {
                continue;
            }
            int64_t addExp = cfg.m_exp * useItemNum;
            pFacadeInfo->m_nFacadeExp = pFacadeInfo->m_nFacadeExp + addExp;
            bSuccess = true;
            break;
        }
        else
        {
            break;
        }
    }
    
    if (!bSuccess)
    {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_LEVUP_RSP, xDataRsp);
        return 0;
    }
    
    int64_t needExp = 0;
    if (xData.facade_type() == proto_ff::FACADE_WING_TYPE)
    {
        needExp = pCurCfg->m_wingExp;
    }
    else if (xData.facade_type() == proto_ff::FACADE_TREASURE_TYPE)
    {
        needExp = pCurCfg->m_treasureExp;
    }
    else if (xData.facade_type() == proto_ff::FACADE_ARTIFACT_TYPE)
    {
        needExp = pCurCfg->m_ArtifactExp;
    }
    else if (xData.facade_type() == proto_ff::FACADE_PARTNER_TYPE)
    {
        needExp = pCurCfg->m_BladeExp;
    }
    while ((uint64_t) pFacadeInfo->m_nFacadeExp >= (uint64_t) needExp)
    {
        pFacadeInfo->m_nFacadeLev = pFacadeInfo->m_nFacadeLev + 1;
        pFacadeInfo->m_nFacadeExp -= needExp;
        
        pCurCfg = pNextCfg;
        if (xData.facade_type() == proto_ff::FACADE_WING_TYPE)
        {
            needExp = pCurCfg->m_wingExp;
        }
        else if (xData.facade_type() == proto_ff::FACADE_TREASURE_TYPE)
        {
            needExp = pCurCfg->m_treasureExp;
        }
        else if (xData.facade_type() == proto_ff::FACADE_ARTIFACT_TYPE)
        {
            needExp = pCurCfg->m_ArtifactExp;
        }
        else if (xData.facade_type() == proto_ff::FACADE_PARTNER_TYPE)
        {
            needExp = pCurCfg->m_BladeExp;
        }
        pNextCfg = GetAdvanceFacadeCfgByLevel(pFacadeInfo->m_nFacadeLev + 1);
        if (pNextCfg == nullptr)
        {
            break;
        }
    }
    
    VEC_STRING vecString;
    NFCommonApi::SplitStr(pFacadeCfg->m_skillID.data(), "|", &vecString);
    for (int i = 0; i < (int) vecString.size(); i++)
    {
        std::string skillStr = vecString[i];
        if (!skillStr.empty())
        {
            VEC_INT64 vecNum;
            NFCommonApi::SplitStrToVecInt(skillStr, ";", &vecNum);
            if (vecNum.size() == 2)
            {
                int lev = pFacadeInfo->GetSkillLev(vecNum[0]);
                if (lev == 0)
                {
                    if (pFacadeInfo->m_nFacadeLev >= vecNum[1])
                    {
                        pFacadeInfo->SetSkillInfo(vecNum[0], 1);
                        //add skill
                        NFSkillPart *pSkillPart = dynamic_cast<NFSkillPart *>(m_pMaster->GetPart(PART_SKILL));
                        if (pSkillPart)
                        {
                            pSkillPart->AddSkill(vecNum[0], 1, sourceParam, true);
                        }
                        
                        proto_ff::FacadeSkillUnlockNotify notify;
                        notify.set_facade_type(xData.facade_type());
                        auto pSkillInfo = notify.mutable_skill_data();
                        if (pSkillInfo)
                        {
                            pSkillInfo->set_skill_id(vecNum[0]);
                            pSkillInfo->set_skill_lev(1);
                        }
                        m_pMaster->SendMsgToClient(proto_ff::CLIENT_TO_LOGIC_FACADE_SKILL_UNLOCK_NOTIFY, notify);
                    }
                }
            }
        }
    }
    
    SetNeedSave(true);
    calcAttr(true);
    pFacadeInfo->OnCalc();
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    xDataRsp.set_facade_id(pFacadeInfo->m_nFacadeID);
    xDataRsp.set_facade_lev(pFacadeInfo->m_nFacadeLev);
    xDataRsp.set_facade_exp(pFacadeInfo->m_nFacadeExp);
    xDataRsp.set_fight_value(pFacadeInfo->GetFightValue());
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_LEVUP_RSP, xDataRsp);
    
    if (xData.facade_type() == proto_ff::FACADE_WING_TYPE)
    {
        proto_ff::WingAdvance fantasyEvent;
        fantasyEvent.set_nlevel(pFacadeInfo->m_nFacadeLev);
        FireExecute(NF_ST_LOGIC_SERVER, EVENT_WING_ADVANCE, CREATURE_PLAYER, m_pMaster->Cid(), fantasyEvent);
    }
    else if (xData.facade_type() == proto_ff::FACADE_TREASURE_TYPE)
    {
        proto_ff::TreasureAdvance fantasyEvent;
        fantasyEvent.set_nlevel(pFacadeInfo->m_nFacadeLev);
        FireExecute(NF_ST_LOGIC_SERVER, EVENT_TREASURE_ADVANCE, CREATURE_PLAYER, m_pMaster->Cid(), fantasyEvent);
    }
    else if (xData.facade_type() == proto_ff::FACADE_ARTIFACT_TYPE)
    {
        proto_ff::ArtifactAdvance fantasyEvent;
        fantasyEvent.set_nlevel(pFacadeInfo->m_nFacadeLev);
        FireExecute(NF_ST_LOGIC_SERVER, EVENT_ARTIFACT_ADVANCE, CREATURE_PLAYER, m_pMaster->Cid(), fantasyEvent);
    }
    else if (xData.facade_type() == proto_ff::FACADE_PARTNER_TYPE)
    {
        proto_ff::PartnerAdvance fantasyEvent;
        fantasyEvent.set_nlevel(pFacadeInfo->m_nFacadeLev);
        FireExecute(NF_ST_LOGIC_SERVER, EVENT_PARTNER_ADVANCE, CREATURE_PLAYER, m_pMaster->Cid(), fantasyEvent);
    }
    return 0;
}

int NFFacadePart::OnHandleFacadeSkillLev(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeSkillLevReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::FacadeSkillLevRsp xDataRsp;
    xDataRsp.set_facade_type(xData.facade_type());
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    FacadeInfo *pFacadeInfo = GetFacadeInfo(xData.facade_type());
    if (pFacadeInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnHandleFacadeSkillLev xData.facade_type():%d error", xData.facade_type());
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SKILL_LEV_RSP, xDataRsp);
        return 0;
    }
    
    auto pFacadeCfg = pFacadeInfo->GetCurFacadeDisplay();
    if (pFacadeCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnHandleFacadeSkillLev GetCurFacadeDisplay == nullptr,currentLev=%u", pFacadeInfo->m_nFacadeID);
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SKILL_LEV_RSP, xDataRsp);
        return 0;
    }
    
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    int skillLev = pFacadeInfo->GetSkillLev(xData.skill_id());
    if (skillLev == 0)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SKILL_LEV_RSP, xDataRsp);
        return 0;
    }
    
    //add skill
    int ret = 0;
    NFSkillPart* pSkillPart = dynamic_cast<NFSkillPart*>(m_pMaster->GetPart(PART_SKILL));
    if (pSkillPart)
    {
        ret = pSkillPart->SkillUpgrade(xData.skill_id());
        if (ret != proto_ff::RET_SUCCESS)
        {
            xDataRsp.set_ret_code(ret);
            m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SKILL_LEV_RSP, xDataRsp);
            return 0;
        }
    }
    
    skillLev += 1;
    SetNeedSave(true);
    pFacadeInfo->SetSkillInfo(xData.skill_id(), skillLev);
    auto pSkillData = xDataRsp.mutable_skill_data();
    if (pSkillData)
    {
        pSkillData->set_skill_id(xData.skill_id());
        pSkillData->set_skill_lev(skillLev);
    }
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SKILL_LEV_RSP, xDataRsp);
    return 0;
}

int NFFacadePart::OnHandleDress(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeDressReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    OnDress(xData.facade_type());
    return 0;
}

int NFFacadePart::OnDress(uint32_t facadeType)
{
    proto_ff::FacadeDressRsp xDataRsp;
    xDataRsp.set_facade_type(facadeType);
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    FacadeInfo *pFacadeInfo = GetFacadeInfo(facadeType);
    if (pFacadeInfo == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnDress xData.facade_type():%d error", facadeType);
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_DRESS_RSP, xDataRsp);
        return 0;
    }
    
    if (pFacadeInfo->m_nFacadeID == 0 || pFacadeInfo->m_nFacadeLev == 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnDress xData.facade_type():%d error", facadeType);
        xDataRsp.set_ret_code(proto_ff::RET_FACADE_UNACTIVE);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_DRESS_RSP, xDataRsp);
        return 0;
    }
    
    if (pFacadeInfo->m_bUseFacade)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnDress xData.facade_type():%d error", facadeType);
        xDataRsp.set_ret_code(proto_ff::RET_FACADE_HAVE_DRESS);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_DRESS_RSP, xDataRsp);
        return 0;
    }
    
    OnFantasyUnDress(facadeType);
    pFacadeInfo->m_bUseFacade = true;
    SetNeedSave(true);
    xDataRsp.set_use_facade(pFacadeInfo->m_bUseFacade);
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    xDataRsp.set_fight_value(pFacadeInfo->GetFightValue());
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_DRESS_RSP, xDataRsp);
    
    if (facadeType == proto_ff::FACADE_ARTIFACT_TYPE)
    {
        NFGrowPart* pGrowPart = dynamic_cast<NFGrowPart*>(m_pMaster->GetPart(PART_GROW));
        if (pGrowPart)
        {
            pGrowPart->UnDress(proto_ff::GrowType_weapon, true);
        }
    }
    
    //同步外观
    m_pMaster->SyncFacade();
    return 0;
}

int NFFacadePart::OnHandleUnDress(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeUnDressReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    FacadeInfo *pFacadeInfo = GetFacadeInfo(xData.facade_type());
    CHECK_NULL(pFacadeInfo);
    
    proto_ff::FacadeDressRsp xDataRsp;
    xDataRsp.set_facade_type(xData.facade_type());
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    int retCode = OnUnDress(xData.facade_type());
    xDataRsp.set_ret_code(retCode);
    xDataRsp.set_use_facade(pFacadeInfo->m_bUseFacade);
    xDataRsp.set_fight_value(pFacadeInfo->GetFightValue());
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_UNDRESS_RSP, xDataRsp);
    return 0;
}

int NFFacadePart::OnUnDress(uint32_t facadeType)
{
    FacadeInfo *pFacadeInfo = GetFacadeInfo(facadeType);
    CHECK_NULL(pFacadeInfo);
    
    if (pFacadeInfo->m_bUseFacade == false)
    {
        return proto_ff::RET_FAIL;
    }
    
    SetNeedSave(true);
    pFacadeInfo->m_bUseFacade = false;
    
    //同步外观
    m_pMaster->SyncFacade();
    return proto_ff::RET_SUCCESS;
}

int NFFacadePart::OnHandleFragmentUse(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeFragmentUseReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::FacadeFragmentUseRsp xDataRsp;
    xDataRsp.set_facade_type(xData.facade_type());
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    FacadeInfo *pFacadeInfo = GetFacadeInfo(xData.facade_type());
    if (pFacadeInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnDress xData.facade_type():%d error", xData.facade_type());
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FRAGEMNT_USE_RSP, xDataRsp);
        return 0;
    }
    
    auto pFacadeCfg = pFacadeInfo->GetCurFacadeDisplay();
    if (pFacadeCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnHandleFragmentUse GetCurFacadeDisplay == nullptr,currentLev=%u", pFacadeInfo->m_nFacadeID);
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FRAGEMNT_USE_RSP, xDataRsp);
        return 0;
    }
    
    bool has = false;
    for (int i = 0; i < (int) pFacadeCfg->m_fragmentID.size(); i++)
    {
        if ((uint64_t) pFacadeCfg->m_fragmentID[i] == xData.fragment_id())
        {
            has = true;
            break;
        }
    }
    
    if (has == false)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnHandleFragmentUse xData.OnHandleFragmentUse():%d error", xData.fragment_id());
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FRAGEMNT_USE_RSP, xDataRsp);
        return 0;
    }
    
    auto pFragmentCfg = FacadeFragmentDesc::Instance()->GetDesc(xData.fragment_id());
    if (pFragmentCfg == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnHandleFragmentUse GetFacadeFragmentCfgInfo == nullptr,fragment_id=%u", xData.fragment_id());
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FRAGEMNT_USE_RSP, xDataRsp);
        return 0;
    }
    
    if (pFacadeInfo->m_mapFragment.find(xData.fragment_id()) == pFacadeInfo->m_mapFragment.end())
    {
        pFacadeInfo->m_mapFragment[xData.fragment_id()] = 0;
    }
    
    uint32_t useTimes = pFacadeInfo->m_mapFragment[xData.fragment_id()];
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    CHECK_NULL(pPackagePart);
    
    SCommonSource sourceParam;
    if (xData.facade_type() == proto_ff::FACADE_WING_TYPE)
    {
        sourceParam.src = S_Wing_Levup;
    }
    else if (xData.facade_type() == proto_ff::FACADE_TREASURE_TYPE)
    {
        sourceParam.src = S_Treasure_Levup;
    }
    else if (xData.facade_type() == proto_ff::FACADE_ARTIFACT_TYPE)
    {
        sourceParam.src = S_Artifact_Levup;
    }
    else if (xData.facade_type() == proto_ff::FACADE_PARTNER_TYPE)
    {
        sourceParam.src = S_Partner_Levup;
    }
    
    sourceParam.param1 = xData.fragment_id();
    sourceParam.param2 = useTimes;
    int64_t nUnBindNum = 0;
    int64_t nBindNum = 0;
    int32_t allNum = pPackagePart->GetItemNum(pFragmentCfg->m_item, nUnBindNum, nBindNum);
    
    int32_t canCost = ((int32_t) useTimes + allNum > pFragmentCfg->m_itemNum) ? (pFragmentCfg->m_itemNum - (int32_t) useTimes) : allNum;
    if (canCost <= 0)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FRAGEMNT_USE_RSP, xDataRsp);
        return 0;
    }
    
    bool ret = pPackagePart->RemoveItem(pFragmentCfg->m_item, canCost, sourceParam);
    if (ret == false)
    {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FRAGEMNT_USE_RSP, xDataRsp);
        return 0;
    }
    
    pFacadeInfo->m_mapFragment[xData.fragment_id()] = pFacadeInfo->m_mapFragment[xData.fragment_id()] + canCost;
    SetNeedSave(true);
    calcAttr(true);
    pFacadeInfo->OnCalc();
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    for (auto iter = pFacadeInfo->m_mapFragment.begin(); iter != pFacadeInfo->m_mapFragment.end(); iter++)
    {
        auto pFragmentInfo = xDataRsp.add_fragment_data();
        pFragmentInfo->set_fragment_id(iter->first);
        pFragmentInfo->set_use_times(iter->second);
    }
    xDataRsp.set_fight_value(pFacadeInfo->GetFightValue());
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FRAGEMNT_USE_RSP, xDataRsp);
    return 0;
}

int NFFacadePart::OnHandleFacadeFantasyInfo(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeFantasyInfoReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    _OnHandleFacadeFantasyInfo(xData.facade_type());
    return 0;
}

int NFFacadePart::_OnHandleFacadeFantasyInfo(uint32_t facadeType)
{
    proto_ff::FacadeFantasyInfoRsp xDataRsp;
    xDataRsp.set_facade_type(facadeType);
    
    auto pInfo = GetFacadeInfo(facadeType);
    if (pInfo)
    {
        pInfo->GetFacadeFantasyInfo(xDataRsp);
    }
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_INFO_RSP, xDataRsp);
    return 0;
}

int NFFacadePart::OnHandleFastasyActiveInfo(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeFantasyActiveReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::FacadeFastasyActiveRsp xDataRsp;
    xDataRsp.set_facade_type(xData.facade_type());
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    auto pFantasyInfo = FacadeChangeDesc::Instance()->GetDesc(xData.fantasy_id());
    if (pFantasyInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnHandleFastasyActiveInfo GetFacadeChangeCfgInfo == nullptr,fantasy_id=%u", xData.fantasy_id());
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_ACTIVE_RSP, xDataRsp);
        return 0;
    }
    
    FacadeInfo *pFacadeInfo = GetFacadeInfo(xData.facade_type());
    if (pFacadeInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnHandleFastasyActiveInfo xData.facade_type():%d error", xData.facade_type());
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_ACTIVE_RSP, xDataRsp);
        return 0;
    }
    
    if (pFacadeInfo->m_mapFantasyFacade.find(xData.fantasy_id()) != pFacadeInfo->m_mapFantasyFacade.end())
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnHandleFastasyActiveInfo xData.fantasy_id():%d error, has active", xData.fantasy_id());
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_ACTIVE_RSP, xDataRsp);
        return 0;
    }
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    CHECK_NULL(pPackagePart);
    
    SCommonSource sourceParam;
    if (xData.facade_type() == proto_ff::FACADE_WING_TYPE)
    {
        sourceParam.src = S_Wing_Levup;
    }
    else if (xData.facade_type() == proto_ff::FACADE_TREASURE_TYPE)
    {
        sourceParam.src = S_Treasure_Levup;
    }
    else if (xData.facade_type() == proto_ff::FACADE_ARTIFACT_TYPE)
    {
        sourceParam.src = S_Artifact_Levup;
    }
    else if (xData.facade_type() == proto_ff::FACADE_PARTNER_TYPE)
    {
        sourceParam.src = S_Partner_Levup;
    }
    
    sourceParam.param1 = xData.fantasy_id();
    sourceParam.param2 = 1;
    bool ret = pPackagePart->RemoveItem(pFantasyInfo->m_activationItem, pFantasyInfo->m_activationNum, sourceParam);
    if (ret == false)
    {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_ACTIVE_RSP, xDataRsp);
        return 0;
    }
    
    pFacadeInfo->m_mapFantasyFacade.emplace(xData.fantasy_id(), 1);
    pFacadeInfo->ProcessFantasyLevel(xData.fantasy_id(), 1);
    
    pFacadeInfo->ProcessSoulActivity(FACADE_SOUL_ACTIVITY_TYPE_FANTASY, xData.fantasy_id());
    pFacadeInfo->ProcessSoulSkill();
    SetNeedSave(true);
    calcAttr(true);
    pFacadeInfo->OnCalc();
    
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    xDataRsp.mutable_fantasy_data()->set_fantasy_id(xData.fantasy_id());
    xDataRsp.mutable_fantasy_data()->set_fantasy_lev(1);
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_ACTIVE_RSP, xDataRsp);
    
    if (xData.facade_type() == proto_ff::FACADE_WING_TYPE)
    {
        proto_ff::WingFantasy fantasyEvent;
        fantasyEvent.set_nlevel(1);
        fantasyEvent.set_nfantasyid(xData.fantasy_id());
        fantasyEvent.set_ntotallv(pFacadeInfo->GetFantasyTotalLv());
        FireExecute(NF_ST_LOGIC_SERVER, EVENT_WING_FANTASY, CREATURE_PLAYER, m_pMaster->Cid(), fantasyEvent);
    }
    else if (xData.facade_type() == proto_ff::FACADE_TREASURE_TYPE)
    {
        proto_ff::TreasureFantasy fantasyEvent;
        fantasyEvent.set_nlevel(1);
        fantasyEvent.set_nfantasyid(xData.fantasy_id());
        fantasyEvent.set_ntotallv(pFacadeInfo->GetFantasyTotalLv());
        FireExecute(NF_ST_LOGIC_SERVER, EVENT_TREASURE_FANTASY, CREATURE_PLAYER, m_pMaster->Cid(), fantasyEvent);
    }
    else if (xData.facade_type() == proto_ff::FACADE_ARTIFACT_TYPE)
    {
        proto_ff::ArtifactFantasy fantasyEvent;
        fantasyEvent.set_nlevel(1);
        fantasyEvent.set_nfantasyid(xData.fantasy_id());
        fantasyEvent.set_ntotallv(pFacadeInfo->GetFantasyTotalLv());
        FireExecute(NF_ST_LOGIC_SERVER, EVENT_ARTIFACT_FANTASY, CREATURE_PLAYER, m_pMaster->Cid(), fantasyEvent);
    }
    else if (xData.facade_type() == proto_ff::FACADE_PARTNER_TYPE)
    {
        proto_ff::PartnerFantasy fantasyEvent;
        fantasyEvent.set_nlevel(1);
        fantasyEvent.set_nfantasyid(xData.fantasy_id());
        fantasyEvent.set_ntotallv(pFacadeInfo->GetFantasyTotalLv());
        FireExecute(NF_ST_LOGIC_SERVER, EVENT_PARTNER_FANTASY, CREATURE_PLAYER, m_pMaster->Cid(), fantasyEvent);
    }
    return 0;
}

int NFFacadePart::OnHandleFantasyLevelupInfo(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeFantasyLevelupReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::FacadeFastasyLevelupRsp xDataRsp;
    xDataRsp.set_facade_type(xData.facade_type());
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    auto pFantasyInfo = FacadeChangeDesc::Instance()->GetDesc(xData.fantasy_id());
    if (pFantasyInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnHandleFantasyLevelupInfo GetFacadeChangeCfgInfo == nullptr,fantasy_id=%u", xData.fantasy_id());
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    FacadeInfo *pFacadeInfo = GetFacadeInfo(xData.facade_type());
    if (pFacadeInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnHandleFantasyLevelupInfo xData.facade_type():%d error", xData.facade_type());
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    if (pFacadeInfo->m_mapFantasyFacade.find(xData.fantasy_id()) == pFacadeInfo->m_mapFantasyFacade.end())
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnHandleFantasyLevelupInfo xData.fantasy_id():%d error, not active", xData.fantasy_id());
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    uint32_t curLevel = pFacadeInfo->m_mapFantasyFacade[xData.fantasy_id()];
    
    if (curLevel >= (uint32_t) pFantasyInfo->m_starUp)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnHandleFantasyLevelupInfo:%d level >= maxLevel:%d error, not active", xData.fantasy_id(), curLevel);
        xDataRsp.set_ret_code(proto_ff::RET_FACADE_MAX_LEVEL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    CHECK_NULL(pPackagePart);
    
    SCommonSource sourceParam;
    if (xData.facade_type() == proto_ff::FACADE_WING_TYPE)
    {
        sourceParam.src = S_Wing_Levup;
    }
    else if (xData.facade_type() == proto_ff::FACADE_TREASURE_TYPE)
    {
        sourceParam.src = S_Treasure_Levup;
    }
    else if (xData.facade_type() == proto_ff::FACADE_ARTIFACT_TYPE)
    {
        sourceParam.src = S_Artifact_Levup;
    }
    else if (xData.facade_type() == proto_ff::FACADE_PARTNER_TYPE)
    {
        sourceParam.src = S_Partner_Levup;
    }
    
    sourceParam.param1 = xData.fantasy_id();
    sourceParam.param2 = curLevel;
    VEC_INT32 vecNum;
    NFCommonApi::SplitStrToVecInt(pFantasyInfo->m_starNum.data(), ";", &vecNum);
    if ((int32_t) vecNum.size() < pFantasyInfo->m_starUp)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnHandleFantasyLevelupInfo strNum.size()<pCfg->starLv, facadeId=%lu", xData.fantasy_id());
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    LIST_ITEM lstItem;
    SItem item;
    item.nItemID = pFantasyInfo->m_starId;
    item.nNum = vecNum[curLevel];
    item.byBind = EBindState_all;
    lstItem.push_back(item);
    
    if (!pPackagePart->RemoveItem(lstItem, sourceParam))
    {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    pFacadeInfo->ProcessFantasyLevel(xData.fantasy_id(), curLevel + 1);
    curLevel = curLevel + 1;
    pFacadeInfo->m_mapFantasyFacade[xData.fantasy_id()] = curLevel;
    calcAttr(true);
    pFacadeInfo->OnCalc();
    SetNeedSave(true);
    
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    xDataRsp.mutable_fantasy_data()->set_fantasy_id(xData.fantasy_id());
    xDataRsp.mutable_fantasy_data()->set_fantasy_lev(curLevel);
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_LEVELUP_RSP, xDataRsp);
    
    if (xData.facade_type() == proto_ff::FACADE_WING_TYPE)
    {
        proto_ff::WingFantasy fantasyEvent;
        fantasyEvent.set_nlevel(curLevel);
        fantasyEvent.set_nfantasyid(xData.fantasy_id());
        fantasyEvent.set_ntotallv(pFacadeInfo->GetFantasyTotalLv());
        FireExecute(NF_ST_LOGIC_SERVER, EVENT_WING_FANTASY, CREATURE_PLAYER, m_pMaster->Cid(), fantasyEvent);
    }
    else if (xData.facade_type() == proto_ff::FACADE_TREASURE_TYPE)
    {
        proto_ff::TreasureFantasy fantasyEvent;
        fantasyEvent.set_nlevel(curLevel);
        fantasyEvent.set_nfantasyid(xData.fantasy_id());
        fantasyEvent.set_ntotallv(pFacadeInfo->GetFantasyTotalLv());
        FireExecute(NF_ST_LOGIC_SERVER, EVENT_TREASURE_FANTASY, CREATURE_PLAYER, m_pMaster->Cid(), fantasyEvent);
    }
    else if (xData.facade_type() == proto_ff::FACADE_ARTIFACT_TYPE)
    {
        proto_ff::ArtifactFantasy fantasyEvent;
        fantasyEvent.set_nlevel(curLevel);
        fantasyEvent.set_nfantasyid(xData.fantasy_id());
        fantasyEvent.set_ntotallv(pFacadeInfo->GetFantasyTotalLv());
        FireExecute(NF_ST_LOGIC_SERVER, EVENT_ARTIFACT_FANTASY, CREATURE_PLAYER, m_pMaster->Cid(), fantasyEvent);
    }
    else if (xData.facade_type() == proto_ff::FACADE_PARTNER_TYPE)
    {
        proto_ff::PartnerFantasy fantasyEvent;
        fantasyEvent.set_nlevel(curLevel);
        fantasyEvent.set_nfantasyid(xData.fantasy_id());
        fantasyEvent.set_ntotallv(pFacadeInfo->GetFantasyTotalLv());
        FireExecute(NF_ST_LOGIC_SERVER, EVENT_PARTNER_FANTASY, CREATURE_PLAYER, m_pMaster->Cid(), fantasyEvent);
    }
    return 0;
}

int NFFacadePart::OnHandleFantasyDress(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeFastasyDressReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    OnFantasyDress(xData.facade_type(), xData.equip_fantasy_id());
    return 0;
}

int NFFacadePart::OnFantasyDress(uint32_t facadeType, uint64_t fantasyId)
{
    proto_ff::FacadeFastasyDressRsp xDataRsp;
    xDataRsp.set_facade_type(facadeType);
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    auto pFantasyInfo = FacadeChangeDesc::Instance()->GetDesc(fantasyId);
    if (pFantasyInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnFantasyDress GetFacadeChangeCfgInfo == nullptr,fantasy_id=%u", fantasyId);
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_DRESS_RSP, xDataRsp);
        return 0;
    }
    
    FacadeInfo *pFacadeInfo = GetFacadeInfo(facadeType);
    if (pFacadeInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnFantasyDress xData.facade_type():%d error", facadeType);
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_DRESS_RSP, xDataRsp);
        return 0;
    }
    
    if (pFacadeInfo->m_mapFantasyFacade.find(fantasyId) == pFacadeInfo->m_mapFantasyFacade.end())
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnFantasyDress xData.fantasy_id():%d error, has active", fantasyId);
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_DRESS_RSP, xDataRsp);
        return 0;
    }
    
    if (facadeType == proto_ff::FACADE_ARTIFACT_TYPE)
    {
        NFGrowPart* pGrowPart = dynamic_cast<NFGrowPart*>(m_pMaster->GetPart(PART_GROW));
        if (pGrowPart)
        {
            pGrowPart->UnDress(proto_ff::GrowType_weapon, true);
        }
    }
    
    OnUnDress(facadeType);
    
    pFacadeInfo->m_nEquipFantasyID = fantasyId;
    SetNeedSave(true);
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    xDataRsp.set_equip_fantasy_id(fantasyId);
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_DRESS_RSP, xDataRsp);
    
    //同步外观
    m_pMaster->SyncFacade();
    return 0;
}

int NFFacadePart::OnHandleFantasyUnDress(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeFastasyUnDressReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::FacadeFastasyUnDressRsp xDataRsp;
    xDataRsp.set_facade_type(xData.facade_type());
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    int ret = OnFantasyUnDress(xData.facade_type());
    xDataRsp.set_ret_code(ret);
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_FANTASY_UNDRESS_RSP, xDataRsp);
    return 0;
}

int NFFacadePart::OnFantasyUnDress(uint32_t facadeType)
{
    FacadeInfo *pFacadeInfo = GetFacadeInfo(facadeType);
    if (pFacadeInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnHandleFantasyDress xData.facade_type():%d error", facadeType);
        return proto_ff::RET_FAIL;
    }
    
    if (pFacadeInfo->m_nEquipFantasyID <= 0)
    {
        return proto_ff::RET_FAIL;
    }
    
    auto pFantasyInfo = FacadeChangeDesc::Instance()->GetDesc(pFacadeInfo->m_nEquipFantasyID);
    if (pFantasyInfo == NULL)
    {
        pFacadeInfo->m_nEquipFantasyID = 0;
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnHandleFantasyDress GetFacadeChangeCfgInfo == nullptr,fantasy_id=%u", pFacadeInfo->m_nEquipFantasyID);
        return proto_ff::RET_FAIL;
    }
    
    if (pFacadeInfo->m_mapFantasyFacade.find(pFacadeInfo->m_nEquipFantasyID) == pFacadeInfo->m_mapFantasyFacade.end())
    {
        pFacadeInfo->m_nEquipFantasyID = 0;
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "[logic] FacadePart::OnHandleFantasyDress xData.fantasy_id():%d error, has active", pFacadeInfo->m_nEquipFantasyID);
        return proto_ff::RET_FAIL;
    }
    
    pFacadeInfo->m_nEquipFantasyID = 0;
    SetNeedSave(true);
    //同步外观
    m_pMaster->SyncFacade();
    return proto_ff::RET_SUCCESS;
}

int NFFacadePart::OnHandleFacadeBuySoulReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeBuySoulReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::FacadeBuySoulRsp xDataRsp;
    xDataRsp.set_facade_type(xData.facade_type());
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    FacadeInfo *pFacadeInfo = GetFacadeInfo(xData.facade_type());
    if (pFacadeInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleFacadeBuySoulReq xData.facade_type():%d error", xData.facade_type());
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_BUG_SOUL_RSP, xDataRsp);
        return 0;
    }
    
    auto pFacadeCfg = pFacadeInfo->GetCurFacadeDisplay();
    if (pFacadeCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleFacadeBuySoulReq GetCurFacadeDisplay == nullptr,currentLev=%u", pFacadeInfo->m_nFacadeID);
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_BUG_SOUL_RSP, xDataRsp);
        return 0;
    }
    
    auto pSoulCfg = FacadeSoulDesc::Instance()->GetDesc(pFacadeCfg->m_soulIID);
    if (pSoulCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleFacadeBuySoulReq g_GetFacadeSoulCfgTable()->GetFacadeSoulCfgInfo == nullptr,currentLesoulIIDv=%u",
                       pFacadeCfg->m_soulIID);
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_BUG_SOUL_RSP, xDataRsp);
        return 0;
    }
    
    pFacadeInfo->m_bUseSoulItem = true;
    pFacadeInfo->m_soulInfo.BuySoul(pFacadeCfg->m_soulIID);
    SetNeedSave(true);
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    pFacadeInfo->m_soulInfo.WriteToProto(xDataRsp.mutable_soul_data());
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_BUG_SOUL_RSP, xDataRsp);
    return 0;
}

int NFFacadePart::OnHandleFacadeSoulInfoReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeSoulInfoReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::FacadeSoulInfoRsp xDataRsp;
    xDataRsp.set_facade_type(xData.facade_type());
    
    FacadeInfo *pFacadeInfo = GetFacadeInfo(xData.facade_type());
    if (pFacadeInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleFacadeBuySoulReq xData.facade_type():%d error", xData.facade_type());
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_INFO_RSP, xDataRsp);
        return 0;
    }
    
    pFacadeInfo->m_soulInfo.WriteToProto(xDataRsp.mutable_soul_data());
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_INFO_RSP, xDataRsp);
    return 0;
}

int NFFacadePart::OnHandleSoulActiveReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeSoulActiveReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    proto_ff::FacadeSoulActiveRsp xDataRsp;
    xDataRsp.set_facade_type(xData.facade_type());
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    FacadeInfo *pFacadeInfo = GetFacadeInfo(xData.facade_type());
    if (pFacadeInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleSoulActiveReq xData.facade_type():%d error", xData.facade_type());
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVE_RSP, xDataRsp);
        return 0;
    }
    
    if (pFacadeInfo->m_bUseSoulItem == false)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVE_RSP, xDataRsp);
        return 0;
    }
    
    auto pSoulCfg = FacadeSoulDesc::Instance()->GetDesc(pFacadeInfo->m_soulInfo.m_soulId);
    if (pSoulCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleSoulActiveReq g_GetFacadeSoulCfgTable()->GetFacadeSoulCfgInfo == nullptr,currentLesoulIIDv=%u",
                       pFacadeInfo->m_soulInfo.m_soulId);
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVE_RSP, xDataRsp);
        return 0;
    }
    
    auto pSoulLev = FacadeSoullvDesc::Instance()->GetDesc(1);
    if (pSoulLev == nullptr)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVE_RSP, xDataRsp);
        return 0;
    }
    
    NFPackagePart* pPart = dynamic_cast<NFPackagePart*>(m_pMaster->GetPart(PART_PACKAGE));
    if (pPart == NULL)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVE_RSP, xDataRsp);
        return 0;
    }
    
    SCommonSource sourceParam;
    if (xData.facade_type() == proto_ff::FACADE_WING_TYPE)
    {
        sourceParam.src = S_Wing_ActiveSoul;
    }
    else if (xData.facade_type() == proto_ff::FACADE_TREASURE_TYPE)
    {
        sourceParam.src = S_Treasure_ActiveSoul;
    }
    else if (xData.facade_type() == proto_ff::FACADE_ARTIFACT_TYPE)
    {
        sourceParam.src = S_Artifact_ActiveSoul;
    }
    else if (xData.facade_type() == proto_ff::FACADE_PARTNER_TYPE)
    {
        sourceParam.src = S_Partner_ActiveSoul;
    }
    if (pPart->RemoveItem(pSoulLev->m_itemID, pSoulLev->m_num, sourceParam) == false)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVE_RSP, xDataRsp);
        return 0;
    }
    
    pFacadeInfo->m_soulInfo.ActiveSoul();
    calcAttr(true);
    pFacadeInfo->OnCalc();
    SetNeedSave(true);
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    pFacadeInfo->m_soulInfo.WriteToProto(xDataRsp.mutable_soul_data());
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVE_RSP, xDataRsp);
    return 0;
}

int NFFacadePart::OnHandleSoulLevelupReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeSoulLevelUpReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::FacadeSoulLevelUpRsp xDataRsp;
    xDataRsp.set_facade_type(xData.facade_type());
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    FacadeInfo *pFacadeInfo = GetFacadeInfo(xData.facade_type());
    if (pFacadeInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleSoulLevelupReq xData.facade_type():%d error", xData.facade_type());
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    if (pFacadeInfo->m_bUseSoulItem == false)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    auto pSoulCfg = FacadeSoulDesc::Instance()->GetDesc(pFacadeInfo->m_soulInfo.m_soulId);
    if (pSoulCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleSoulLevelupReq g_GetFacadeSoulCfgTable()->GetFacadeSoulCfgInfo == nullptr,currentLesoulIIDv=%u",
                       pFacadeInfo->m_soulInfo.m_soulId);
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    auto pSoulLev = FacadeSoullvDesc::Instance()->GetDesc(pFacadeInfo->m_soulInfo.m_soulLevel+1);
    if (pSoulLev == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleSoulLevelupReq g_GetFacadeSoullvCfgTable()->GetFacadeSoullvCfgInfo == nullptr,pFacadeInfo->m_soulInfo.m_soulLevel + 1=%u",
                       pFacadeInfo->m_soulInfo.m_soulLevel+1);
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    NFPackagePart* pPart = dynamic_cast<NFPackagePart*>(m_pMaster->GetPart(PART_PACKAGE));
    if (pPart == NULL)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    SCommonSource sourceParam;
    if (xData.facade_type() == proto_ff::FACADE_WING_TYPE)
    {
        sourceParam.src = S_Wing_SoulLv;
    }
    else if (xData.facade_type() == proto_ff::FACADE_TREASURE_TYPE)
    {
        sourceParam.src = S_Treasure_SoulLv;
    }
    else if (xData.facade_type() == proto_ff::FACADE_ARTIFACT_TYPE)
    {
        sourceParam.src = S_Artifact_SoulLv;
    }
    else if (xData.facade_type() == proto_ff::FACADE_PARTNER_TYPE)
    {
        sourceParam.src = S_Partner_SoulLv;
    }
    if (pPart->RemoveItem(pSoulLev->m_itemID, pSoulLev->m_num, sourceParam) == false)
    {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    int32_t oldSoulLevel = pFacadeInfo->m_soulInfo.m_soulLevel;
    int32_t rand = NFRandInt(0, 10000);
    bool success = true;
    if (rand >= pSoulLev->m_successRate)
    {
        success = false;
    }
    
    if (success)
    {
        xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
        pFacadeInfo->m_soulInfo.m_soulLevel++;
        pFacadeInfo->ProcessSoulActivity(FACADE_SOUL_ACTIVITY_TYPE_LEVEL, pFacadeInfo->m_soulInfo.m_soulLevel);
    }
    else {
        xDataRsp.set_ret_code(proto_ff::RET_FACADE_SOUL_LEVELUP_FAIL);
        if (pSoulLev->m_downLv > 0)
        {
            if (pFacadeInfo->m_soulInfo.m_soulLevel > 1)
            {
                xDataRsp.set_ret_code(proto_ff::RET_FACADE_SOUL_LEVELUP_FAIL_LEVEL_RAIL);
                pFacadeInfo->m_soulInfo.m_soulLevel--;
            }
        }
    }
    pFacadeInfo->ProcessSoulSkill();
    
    calcAttr(true);
    pFacadeInfo->OnCalc();
    SetNeedSave(true);
    xDataRsp.set_old_soul_level(oldSoulLevel);
    xDataRsp.set_soul_level(pFacadeInfo->m_soulInfo.m_soulLevel);
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_LEVELUP_RSP, xDataRsp);
    return 0;
}

int NFFacadePart::OnHandleSoulActivityRecvReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeSoulActivityRecvReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::FacadeSoulActivityRecvRsp xDataRsp;
    xDataRsp.set_facade_type(xData.facade_type());
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    FacadeInfo *pFacadeInfo = GetFacadeInfo(xData.facade_type());
    if (pFacadeInfo == NULL)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVITY_RECV_RSP, xDataRsp);
        return 0;
    }
    
    if (!pFacadeInfo->m_soulInfo.IsActivityExist(xData.activity_id()))
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVITY_RECV_RSP, xDataRsp);
        return 0;
    }
    
    if (pFacadeInfo->m_bUseSoulItem == false)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVITY_RECV_RSP, xDataRsp);
        return 0;
    }
    
    auto pActivityCfg = FacadeSoulachievementDesc::Instance()->GetDesc(xData.activity_id());
    if (pActivityCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleSoulActivityRecvReq g_GetFacadeSoulachievementCfgTable()->GetFacadeSoulachievementCfgInfo == nullptr,xData.activity_id()=%u",
                       xData.activity_id());
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVITY_RECV_RSP, xDataRsp);
        return 0;
    }
    
    auto status = pFacadeInfo->m_soulInfo.GetActivityStatus(xData.activity_id());
    if (status != proto_ff::FACADE_SOUL_ACTIVITY_STATUS_CAN_RECV)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVITY_RECV_RSP, xDataRsp);
        return 0;
    }
    
    NFPackagePart* pPackagePart = dynamic_cast<NFPackagePart*>(m_pMaster->GetPart(PART_PACKAGE));
    if (pPackagePart)
    {
        SCommonSource sourceParam;
        if (xData.facade_type() == proto_ff::FACADE_WING_TYPE)
        {
            sourceParam.src = S_Wing_SoulRecv;
        }
        else if (xData.facade_type() == proto_ff::FACADE_TREASURE_TYPE)
        {
            sourceParam.src = S_Treasure_SoulRecv;
        }
        else if (xData.facade_type() == proto_ff::FACADE_ARTIFACT_TYPE)
        {
            sourceParam.src = S_Artifact_SoulRecv;
        }
        else if (xData.facade_type() == proto_ff::FACADE_PARTNER_TYPE)
        {
            sourceParam.src = S_Partner_SoulRecv;
        }
        if (!pPackagePart->AddItem(pActivityCfg->m_itemID, pActivityCfg->m_num, sourceParam))
        {
            xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_COMMON_SPACE_NOT_ENOUGH);
            m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVITY_RECV_RSP, xDataRsp);
            return 0;
        }
    }
    
    pFacadeInfo->m_soulInfo.SetActivityStatus(xData.activity_id(), proto_ff::FACADE_SOUL_ACTIVITY_STATUS_RECVed);
    SetNeedSave(true);
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    xDataRsp.mutable_activity_data()->set_activity_id(xData.activity_id());
    xDataRsp.mutable_activity_data()->set_status(proto_ff::FACADE_SOUL_ACTIVITY_STATUS_RECVed);
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_ACTIVITY_RECV_RSP, xDataRsp);
    return 0;
}

int NFFacadePart::OnHandleSoulResetSkillReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::FacadeSoulResetSkilLReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::FacadeSoulResetSkillRsp xDataRsp;
    xDataRsp.set_facade_type(xData.facade_type());
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    FacadeInfo *pFacadeInfo = GetFacadeInfo(xData.facade_type());
    if (pFacadeInfo == NULL)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_RESET_SKILL_RSP, xDataRsp);
        return 0;
    }
    
    if (pFacadeInfo->m_bUseSoulItem == false)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_RESET_SKILL_RSP, xDataRsp);
        return 0;
    }
    
    NFPackagePart* pPackagePart = dynamic_cast<NFPackagePart*>(m_pMaster->GetPart(PART_PACKAGE));
    if (pPackagePart == NULL)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_RESET_SKILL_RSP, xDataRsp);
        return 0;
    }
    
    NFSkillPart* pSkillPart = dynamic_cast<NFSkillPart*>(m_pMaster->GetPart(PART_SKILL));
    if (pSkillPart == NULL)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_RESET_SKILL_RSP, xDataRsp);
        return 0;
    }
    
    list<SItem> itemList;
    bool has = false;
    for(auto iter = pFacadeInfo->m_soulInfo.m_soulSkillInfo.begin(); iter != pFacadeInfo->m_soulInfo.m_soulSkillInfo.end(); iter++)
    {
        if (iter->second == proto_ff::FACADE_SOUL_SKILL_STATUS_ACTIVED)
        {
            int64_t skillId = iter->first;
            const SkillInfo* pInfo = pSkillPart->GetSkillInfo(skillId);
            if (pInfo && pInfo->level > 1)
            {
                int32_t level = pInfo->level;
                while(level > 1)
                {
/*                    auto pLevCfg = g_GetSkillMgr()->GetUpgradeCfg(skillId, level);
                    if (nullptr == pLevCfg)
                    {
                        break;
                    }
                    if (pLevCfg->costItemId > 0 && pLevCfg->costNum > 0)
                    {
                        has = true;
                        SItem item(pLevCfg->costItemId, pLevCfg->costNum, EBindState::EBindState_no);
                        itemList.push_back(item);
                    }*/
                    --level;
                }
            }
        }
    }
    
    int retCode = proto_ff::RET_SUCCESS;
    if (has)
    {
        SCommonSource sourceParam;
        if (xData.facade_type() == proto_ff::FACADE_WING_TYPE)
        {
            sourceParam.src = S_Wing_SoulResetSkill;
        }
        else if (xData.facade_type() == proto_ff::FACADE_TREASURE_TYPE)
        {
            sourceParam.src = S_Treasure_SoulResetSkill;
        }
        else if (xData.facade_type() == proto_ff::FACADE_ARTIFACT_TYPE)
        {
            sourceParam.src = S_Artifact_SoulResetSkill;
        }
        else if (xData.facade_type() == proto_ff::FACADE_PARTNER_TYPE)
        {
            sourceParam.src = S_Partner_SoulResetSkill;
        }
        if (pPackagePart->AddItem(itemList, sourceParam, true, true))
        {
            for(auto iter = pFacadeInfo->m_soulInfo.m_soulSkillInfo.begin(); iter != pFacadeInfo->m_soulInfo.m_soulSkillInfo.end(); iter++)
            {
                if (iter->second == proto_ff::FACADE_SOUL_SKILL_STATUS_ACTIVED)
                {
                    pSkillPart->RemoveSkill(iter->first, sourceParam, true);
                    pSkillPart->AddSkill(iter->first, 1, sourceParam, true);
                }
            }
        }
        else {
            retCode = proto_ff::RET_PACKAGE_COMMON_SPACE_NOT_ENOUGH;
        }
    }
    else {
        retCode = proto_ff::RET_FACADE_SOUL_NO_SKILL_RESET;
    }
    
    SetNeedSave(true);
    xDataRsp.set_ret_code(retCode);
    pFacadeInfo->m_soulInfo.WriteToProto(xDataRsp.mutable_soul_data());
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_FACADE_SOUL_RESET_SKILL_RSP, xDataRsp);
    return 0;
}

int32_t NFFacadePart::CalNeedItemNum(uint32_t type, uint32_t lev, int32_t addExp)
{
    auto pCfgInfo = FacadeValueDesc::Instance()->GetDesc(lev);
    if (pCfgInfo == nullptr)
    {
        return 0;
    }
    
    int64_t needExp = 0;
    if (type == proto_ff::FACADE_WING_TYPE)
    {
        needExp = pCfgInfo->m_wingExp;
    }
    else if (type == proto_ff::FACADE_TREASURE_TYPE)
    {
        needExp = pCfgInfo->m_treasureExp;
    }
    else if (type == proto_ff::FACADE_ARTIFACT_TYPE)
    {
        needExp = pCfgInfo->m_ArtifactExp;
    }
    else if (type == proto_ff::FACADE_PARTNER_TYPE)
    {
        needExp = pCfgInfo->m_BladeExp;
    }
    
    int32_t needCount = ceil(float(needExp) / float(addExp));
    
    return needCount;
}

const proto_ff_s::E_FacadeValue_s *NFFacadePart::GetAdvanceFacadeCfgByLevel(int32_t level)
{
    return FacadeValueDesc::Instance()->GetDesc(level);
}

void NFFacadePart::ActiveDefaultFacade(uint32_t facadeType)
{
    FacadeInfo *pFacadeInfo = GetFacadeInfo(facadeType);
    if (pFacadeInfo)
    {
        pFacadeInfo->ActiveDefaultFacade(false);
    }
}

void NFFacadePart::calcAttr(bool sync)
{
    MAP_INT32_INT64 allAttr;
    MAP_INT32_INT64 partAttr;
    
    for (int i = 1; i < proto_ff::FACADE_TYPE_MAX; i++)
    {
        calcAttr(i, partAttr);
        MergeAttr(partAttr, allAttr);
        partAttr.clear();
    }
    PrintAttr(0, allAttr);
    
    for (auto &e : allAttr)
    {
        m_pMaster->SetAttrGroupCache(proto_ff::EAttrGroup_Facade, e.first, e.second);
    }
    
    if (sync)
    {
        m_pMaster->SynAttrToClient();
    }
}

void NFFacadePart::calcAttr(int32_t type, MAP_INT32_INT64 &outAttr)
{
    auto pFacade = GetFacadeInfo(type);
    if (pFacade)
    {
        pFacade->calcAttr(outAttr);
    }
}

void NFFacadePart::MergeAttr(const MAP_INT32_INT64 &src, MAP_INT32_INT64 &dst)
{
    for (auto &e : src)
    {
        dst[e.first] += e.second;
    }
}

void NFFacadePart::PrintAttr(int32_t type, const MAP_INT32_INT64 &attr)
{

}

FacadeInfo *NFFacadePart::GetFacadeInfo(uint32_t facadeType)
{
    if (facadeType >= 1 && facadeType < proto_ff::FACADE_TYPE_MAX)
    {
        return &m_facadeInfo[facadeType - 1];
    }
    return NULL;
}
