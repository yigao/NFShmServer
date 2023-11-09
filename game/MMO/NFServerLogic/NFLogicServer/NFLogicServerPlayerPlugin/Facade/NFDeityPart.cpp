// -------------------------------------------------------------------------
//    @FileName         :    NFDeityPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFDeityPart
//
// -------------------------------------------------------------------------

#include "NFDeityPart.h"
#include "NFLogicCommon/NFEventDefine.h"
#include "Skill/NFSkillPart.h"
#include "DescStore/AvatarSkillDesc.h"
#include "ClientServer.pb.h"
#include "DescStore/AvatarFragmentDesc.h"
#include "Package/NFPackagePart.h"
#include "proto_svr_event.pb.h"
#include "Player/NFFunctionUnlockPart.h"
#include "DescStoreEx/EquipDescEx.h"

NFDeityPart::NFDeityPart()
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

NFDeityPart::~NFDeityPart()
{
}

int NFDeityPart::CreateInit()
{
    m_nDeityID = 0;
    m_nDeityLev = 0;
    m_nDeityExp = 0;
    return 0;
}

int NFDeityPart::ResumeInit()
{
    return 0;
}

int NFDeityPart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData)
{
    NFPart::Init(pMaster, partType, dbData);
    
    ActiveDefaultBattleSlot();
    calcAttr(false);
    
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_FUNCTIONUNLOCK, CREATURE_PLAYER, m_pMaster->Cid(), "DeityPart::Init");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_LEVELUP, CREATURE_PLAYER, m_pMaster->Cid(), "DeityPart::Init");
    return 0;
}

int NFDeityPart::UnInit()
{
    return NFPart::UnInit();
}

int NFDeityPart::LoadFromDB(const proto_ff::RoleDBData &data)
{
    const proto_ff::DeityDataInfo &dbInfo = data.deity();
    m_nDeityID = dbInfo.deity_id();
    m_nDeityLev = dbInfo.deity_lev();
    m_nDeityExp = dbInfo.deity_exp();
    
    
    for (int i = 0; i < dbInfo.fantasy_map_size(); i++)
    {
        m_mapFantasyDeity[dbInfo.fantasy_map(i).fantasy_id()].ReadFromPB(dbInfo.fantasy_map(i));
    }
    
    for (int i = 0; i < dbInfo.fragment_map_size(); i++)
    {
        m_mapFragment.emplace(dbInfo.fragment_map(i).fragment_id(), dbInfo.fragment_map(i).use_times());
    }
    
    for (int i = 0; i < dbInfo.skill_data_size(); i++)
    {
        m_mapSkill.emplace(dbInfo.skill_data(i).skill_id(), dbInfo.skill_data(i).skill_lev());
    }
    
    for (int i = 0; i < (int) dbInfo.battle_data_size(); i++)
    {
        auto pSlotInfo = &m_battleDeityList[dbInfo.battle_data(i).id()];
        if (pSlotInfo)
        {
            pSlotInfo->InitShmObj(this);
            pSlotInfo->ReadFromPB(dbInfo.battle_data(i));
            if (pSlotInfo->m_curState == proto_ff::DEITY_BATTLE_SLOT_STATE_USING && pSlotInfo->m_deityId > 0 && pSlotInfo->m_enterWarTime > 0)
            {
                uint64_t leftTime = pSlotInfo->GetLeftWarTime();
                if (leftTime <= 0)
                {
                    pSlotInfo->m_enterWarTime = 0;
                }
                else
                {
                    pSlotInfo->SetTimer(0, 0, leftTime, 0);
                }
            }
            else
            {
                pSlotInfo->m_enterWarTime = 0;
            }
        }
    }
    return 0;
}

int NFDeityPart::InitConfig(const proto_ff::RoleDBData &data)
{
    return NFPart::InitConfig(data);
}

int NFDeityPart::SaveDB(proto_ff::RoleDBData &dbData)
{
    auto pInfo = dbData.mutable_deity();
    pInfo->set_deity_id(m_nDeityID);
    pInfo->set_deity_lev(m_nDeityLev);
    pInfo->set_deity_exp(m_nDeityExp);
    
    for (auto iter = m_mapFantasyDeity.begin(); iter != m_mapFantasyDeity.end(); iter++)
    {
        auto pFantasyData = pInfo->add_fantasy_map();
        if (pFantasyData)
        {
            iter->second.WriteToPB(m_pMaster, pFantasyData);
        }
    }
    
    for (auto iter = m_mapFragment.begin(); iter != m_mapFragment.end(); iter++)
    {
        auto pFragmentData = pInfo->add_fragment_map();
        if (pFragmentData)
        {
            pFragmentData->set_fragment_id(iter->first);
            pFragmentData->set_use_times(iter->second);
        }
    }
    
    for (auto iter = m_mapSkill.begin(); iter != m_mapSkill.end(); iter++)
    {
        auto pSkillData = pInfo->add_skill_data();
        if (pSkillData)
        {
            pSkillData->set_skill_id(iter->first);
            pSkillData->set_skill_lev(iter->second);
        }
    }
    
    for (auto iter = m_battleDeityList.begin(); iter != m_battleDeityList.end(); iter++)
    {
        auto pBattleData = pInfo->add_battle_data();
        if (pBattleData)
        {
            iter->second.WriteToPB(pBattleData);
        }
    }
    return 0;
}

int NFDeityPart::DailyZeroUpdate()
{
    return NFPart::DailyZeroUpdate();
}

int NFDeityPart::FillFacadeProto(proto_ff::RoleFacadeProto &outproto)
{
    return NFPart::FillFacadeProto(outproto);
}

int NFDeityPart::RegisterMessage()
{
    return NFPart::RegisterMessage();
}

int NFDeityPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleClientMessage(msgId, packet);
}

int NFDeityPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

void NFDeityPart::ActiveDefaultDeity(bool bSync)
{
    if (m_nDeityID == 0)
    {
        auto pDisplayCfgInfo = GetDefaultDeityDisplay();
        if (pDisplayCfgInfo)
        {
            m_nDeityID = pDisplayCfgInfo->m_id;
            m_nDeityLev = 0;
            m_nDeityExp = 0;
            
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
            
            NFSkillPart *pSkillPart = dynamic_cast<NFSkillPart *>(m_pMaster->GetPart(PART_SKILL));
            if (pSkillPart)
            {
                SCommonSource src;
                src.src = S_Deity_SKILL;
                src.param1 = m_nDeityID;
                auto pCfgMap = AvatarSkillDesc().GetResDescPtr();
                for (auto iter = pCfgMap->begin(); iter != pCfgMap->end(); iter++)
                {
                    src.param2 = iter->second.m_skillid;
                    pSkillPart->AddSkill(iter->second.m_skillid, 0, src, bSync);
                }
            }
            
            ActiveDefaultBattleSlot();
            uint32_t nLevel = m_pMaster->GetAttr(proto_ff::A_LEVEL);
            checkBattleSlot(nLevel);
            SetNeedSave(true);
        }
    }
    
    if (m_nDeityID > 0)
    {
        calcAttr(true);
    }
}

const proto_ff_s::E_AvatarDisplay_s* NFDeityPart::GetDefaultDeityDisplay()
{
    auto pMap = AvatarDisplayDesc::Instance()->GetResDescPtr();
    for (auto iter = pMap->begin(); iter != pMap->end(); ++iter)
    {
        return &iter->second;
    }
    return NULL;
}

void NFDeityPart::ActiveDefaultBattleSlot()
{
    if (m_nDeityID > 0)
    {
        auto pSlotMap = AvatarBattleslotDesc::Instance()->GetResDescPtr();
        for (auto iter = pSlotMap->begin(); iter != pSlotMap->end(); iter++)
        {
            if (m_battleDeityList.find(iter->second.m_id) == m_battleDeityList.end())
            {
                DeityBattleSlot& slot = m_battleDeityList[iter->second.m_id];
                slot.InitShmObj(this);
                slot.m_curState = proto_ff::DEITY_BATTLE_SLOT_STATE_LOCK;
                slot.m_deityId = 0;
                slot.m_id = iter->second.m_id;
            }
        }
    }
}

int NFDeityPart::GetSkillLev(int64_t skillId)
{
    if (m_mapSkill.find(skillId) != m_mapSkill.end())
    {
        return m_mapSkill[skillId];
    }
    return 0;
}

void NFDeityPart::SetSkillInfo(int64_t skillId, uint32_t lev)
{
    m_mapSkill[skillId] = lev;
}

void NFDeityPart::checkBattleSlot(uint32_t playerLev)
{
    for (auto iter = m_battleDeityList.begin(); iter != m_battleDeityList.end(); iter++)
    {
        DeityBattleSlot *pSlot = &iter->second;
        if (pSlot && pSlot->m_curState == proto_ff::DEITY_BATTLE_SLOT_STATE_LOCK)
        {
            auto pSlotCfg = AvatarBattleslotDesc::Instance()->GetDesc(pSlot->m_id);
            if (pSlotCfg->m_type == 1 && playerLev >= (uint32_t) NFCommonApi::StrToInt(pSlotCfg->m_arg.data()))
            {
                pSlot->m_curState = proto_ff::DEITY_BATTLE_SLOT_STATE_EMPTY;
                SetNeedSave(true);
                proto_ff::DeityBattleSlotUnlockNotify notify;
                auto pSlotInfo = notify.mutable_battle_data();
                if (pSlotInfo)
                {
                    pSlot->WriteToPB(pSlotInfo);
                }
                m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_BATTLE_SLOT_UNLOCK_NOTIFY, notify);
            }
        }
    }
}

void NFDeityPart::SendDeityInfo()
{
    proto_ff::DeityInfoRsp rsp;
    rsp.set_deity_id(m_nDeityID);
    rsp.set_deity_lev(m_nDeityLev);
    rsp.set_deity_exp(m_nDeityExp);
    
    for (auto iter = m_mapFragment.begin(); iter != m_mapFragment.end(); iter++)
    {
        auto *pData = rsp.add_fragment_data();
        if (pData)
        {
            pData->set_fragment_id(iter->first);
            pData->set_use_times(iter->second);
        }
    }
    
    for (auto iter = m_mapSkill.begin(); iter != m_mapSkill.end(); iter++)
    {
        auto *pData = rsp.add_skill_data();
        if (pData)
        {
            pData->set_skill_id(iter->first);
            pData->set_skill_lev(iter->second);
        }
    }
    
    for (auto iter = m_battleDeityList.begin(); iter != m_battleDeityList.end(); iter++)
    {
        auto *pData = rsp.add_battle_data();
        if (pData)
        {
            iter->second.WriteToPB(pData);
        }
    }
    
    rsp.set_fight_value(GetFightValue());
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_INFO_RSP, rsp);
}

void NFDeityPart::SendDeaityFantasyInfo()
{
    proto_ff::DeityFantasyInfoRsp rsp;
    for (auto iter = m_mapFantasyDeity.begin(); iter != m_mapFantasyDeity.end(); iter++)
    {
        auto *pData = rsp.add_fantasy_data();
        if (pData)
        {
            iter->second.WriteToPB(m_pMaster, pData);
        }
    }
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_INFO_RSP, rsp);
}

bool NFDeityPart::ProcessAdvanceAttr(MAP_INT32_FLOAT &outAttr)
{
    auto pDeityCfg = AvatarDisplayDesc::Instance()->GetDesc(m_nDeityID);
    if (pDeityCfg)
    {
        calcValueAttr(pDeityCfg->m_UpLvType, m_nDeityLev, outAttr);
    }
    return true;
}

bool NFDeityPart::calcValueAttr(int32_t upLvType, int32_t level, MAP_INT32_FLOAT &outAttr)
{
    auto pCfg = AvatarValueDesc::Instance()->GetDescByTypeLv(upLvType, level);
    if (pCfg == nullptr)
    {
        return false;
    }
    
    for (int i = 0; i < (int) pCfg->m_Attribute.size(); i++)
    {
        int nAttrId = pCfg->m_Attribute.at(i).m_type;
        if (nAttrId > 0)
        {
            int64_t nAttrValue = pCfg->m_Attribute.at(i).m_value;
            outAttr[nAttrId] += nAttrValue;
        }
    }
    return true;
}

bool NFDeityPart::AddFragmentAttr(MAP_INT32_FLOAT &outAttr)
{
    for (auto iter = m_mapFragment.begin(); iter != m_mapFragment.end(); iter++)
    {
        AddFragmentAttr(iter->first, iter->second, outAttr);
    }
    return true;
}

bool NFDeityPart::AddFragmentAttr(int64_t fragmentId, int32_t nTimes, MAP_INT32_FLOAT &outAttr)
{
    auto pCfg = AvatarFragmentDesc::Instance()->GetDesc(fragmentId);
    if (pCfg == nullptr || nTimes == 0)
    {
        return false;
    }
    
    for (int i = 0; i < (int) pCfg->m_attribute.size(); i++)
    {
        int nAttrId = pCfg->m_attribute[i].m_type;
        if (nAttrId > 0)
        {
            outAttr[nAttrId] += nTimes * pCfg->m_attribute[i].m_value;
        }
    }
    
    return true;
}

int64_t NFDeityPart::GetFightValue()
{
    double nFightTotal = 0;
    MAP_INT32_INT64 allAttr;
    MAP_INT32_INT64 partAttr;
    
    calcDeityAttr(partAttr);
    MergeAttr(partAttr, allAttr);
    partAttr.clear();
    
    //计算身上的装备属性
    MAP_INT32_INT64 advnceAttr;
    calcFantasyAttr(advnceAttr);
    MergeAttr(advnceAttr, allAttr);
    
    PrintAttr(allAttr);
    
    for (auto &e: allAttr)
    {
        auto pCfg = AttributeAttributeDesc::Instance()->GetDesc(e.first);
        if (pCfg)
        {
            nFightTotal += e.second * pCfg->m_power;
        }
    }
    
    return nFightTotal;
}

int32_t NFDeityPart::CalFantasyLevelNeedItemNum(uint32_t type, uint32_t lev, int32_t addExp)
{
    auto pCfgInfo = AvatarValueDesc::Instance()->GetDescByTypeLv(type, lev);
    if (pCfgInfo == nullptr)
    {
        return 0;
    }
    
    int64_t needExp = pCfgInfo->m_Exp;
    
    int32_t needCount = ceil(float(needExp) / float(addExp));
    
    return needCount;
}

void NFDeityPart::calcAttr(bool sync)
{
    MAP_INT32_INT64 allAttr;
    MAP_INT32_INT64 partAttr;
    
    calcDeityAttr(partAttr);
    MergeAttr(partAttr, allAttr);
    partAttr.clear();
    
    //计算身上的装备属性
    MAP_INT32_INT64 advnceAttr;
    calcFantasyAttr(advnceAttr);
    MergeAttr(advnceAttr, allAttr);
    
    PrintAttr(allAttr);
    
    for (auto &e: allAttr)
    {
        m_pMaster->SetAttrGroupCache(proto_ff::EAttrGroup_DEITY, e.first, e.second);
    }
    
    if (sync)
    {
        m_pMaster->SynAttrToClient();
    }
}

void NFDeityPart::calcDeityAttr(MAP_INT32_INT64 &outAttr)
{
    MAP_INT32_FLOAT floatAttr;
    MAP_INT32_FLOAT mapattr;  // 属性ID-属性值
    MAP_INT32_FLOAT mapattradd;  //特殊属性加成 属性ID-加成百分比
    ProcessAdvanceAttr(floatAttr);
    AddFragmentAttr(floatAttr);
    for (auto iter = floatAttr.begin(); iter != floatAttr.end(); iter++)
    {
        int32_t attrId = iter->first;
        int64_t value = iter->second;
        mapattr[attrId] += value;
        if (IsSpecAttr(attrId))
        {
            mapattradd[attrId] += value;
        }
    }
    
    //特殊属性 加成的属性值
    for (auto &iterspec : mapattradd)
    {
        uint32_t attrid = GetComAttrBySpec(iterspec.first);
        auto iterf = mapattr.find(attrid);
        if (iterf != mapattr.end() && iterspec.second > 0)
        {
            floatAttr[attrid] += (iterspec.second / F_TEN_THOUSAND * iterf->second);
        }
    }
    
    //算出每个模块加成属性，向下取整
    for (auto &e: floatAttr)
    {
        outAttr[e.first] = (int32_t) floor(e.second);
    }
    
    PrintAttr(outAttr);
}

void NFDeityPart::MergeAttr(MAP_INT32_INT64 &src, MAP_INT32_INT64 &dst)
{
    for (auto &e: src)
    {
        dst[e.first] += e.second;
    }
}

void NFDeityPart::PrintAttr(MAP_INT32_INT64 &attr)
{

}

void NFDeityPart::calcFantasyAttr(MAP_INT32_INT64 &outAttr)
{
    for(auto iter = m_mapFantasyDeity.begin(); iter != m_mapFantasyDeity.end(); iter++)
    {
        iter->second.calcAdvanceAttr(outAttr);
        iter->second.calcDressAttr(m_pMaster, outAttr);
        iter->second.calcStrongAttr(outAttr);
        iter->second.calcSuitAttr(outAttr);
    }
}

bool NFDeityPart::IsSpecAttr(int32_t spec_attrid)
{
    return (proto_ff::A_NONE != GetComAttrBySpec(spec_attrid));
}

int32_t NFDeityPart::GetComAttrBySpec(int32_t spec_attrid)
{
    switch (spec_attrid)
    {
        case proto_ff::A_DEITY_HP_ADD:
            return proto_ff::A_MAX_HP;
        case proto_ff::A_DEITY_ATK_ADD:
            return proto_ff::A_ATK;
        case proto_ff::A_DEITY_DEF_ADD:
            return proto_ff::A_DEF;
        case proto_ff::A_DEITY_AORMOR_ADD:
            return proto_ff::A_BRK_ARMOR;
        case proto_ff::A_DEITY_SKY_ADD:
            return proto_ff::A_SKY_DAM;
        default:
            break;
    }
    return proto_ff::A_NONE;
}

int32_t NFDeityPart::CalNeedItemNum(int32_t type, uint32_t lev, int32_t addExp)
{
    auto pCfgInfo = AvatarValueDesc::Instance()->GetDescByTypeLv(type, lev);
    if (pCfgInfo == nullptr)
    {
        return 0;
    }
    
    int64_t needExp = pCfgInfo->m_Exp;
    
    int32_t needCount = ceil(float(needExp) / float(addExp));
    
    return needCount;
}

int64_t NFDeityPart::GetCurEnterWarDeity()
{
    for (auto iter = m_battleDeityList.begin(); iter != m_battleDeityList.end(); iter++)
    {
        if (iter->second.m_curState == proto_ff::DEITY_BATTLE_SLOT_STATE_USING && iter->second.m_enterWarTime > 0)
        {
            return iter->second.m_deityId;
        }
    }
    return 0;
}

int NFDeityPart::OnHandleDeityInfoReq(uint32_t msgId, NFDataPackage &packet)
{
    SendDeityInfo();
    return 0;
}

int NFDeityPart::OnHandleDeityLevelUpReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::DeityLevupReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    uint64_t materialId = xData.material_id();
    proto_ff::DeityLevupRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    CHECK_NULL(pPackagePart);
    
    auto pDeityCfg = AvatarDisplayDesc::Instance()->GetDesc(m_nDeityID);
    if (pDeityCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleDeityLevelUpReq g_GetAvatarDisplayCfgTable()->GetAvatarDisplayCfgInfo == nullptr, deity_id=%u",
                       m_nDeityID);
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_LEVUP_RSP, xDataRsp);
        return 0;
    }
    
    SCommonSource sourceParam;
    sourceParam.src = S_DEITY_LV;
    
    auto pCurCfg = AvatarValueDesc::Instance()->GetDescByTypeLv(pDeityCfg->m_UpLvType, m_nDeityLev);
    if (pCurCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleDeityLevelUpReq pCurCfg == nullptr,currentLev=%u", m_nDeityLev);
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_LEVUP_RSP, xDataRsp);
        return 0;
    }
    
    auto pNextCfg = AvatarValueDesc::Instance()->GetDescByTypeLv(pDeityCfg->m_UpLvType, m_nDeityLev + 1);
    if (pNextCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleDeityLevelUpReq pCurCfg == nullptr,currentLev=%u, nextLev=%u", m_nDeityLev,
                       m_nDeityLev + 1);
        xDataRsp.set_ret_code(proto_ff::RET_FACADE_MAX_LEVEL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_LEVUP_RSP, xDataRsp);
        return 0;
    }
    
    bool bSuccess = false;
    for (int i = 0; i < (int) pDeityCfg->m_material.size(); i++)
    {
        if (materialId != (uint64_t) pDeityCfg->m_material[i].m_id)
        {
            continue;
        }
        
        int64_t bindNum = 0;
        int64_t unBindNum = 0;
        uint32_t itemNum = pPackagePart->GetItemNum(materialId, bindNum, unBindNum);
        //最大可使用数量（升级到满级）
        uint32_t needMax = CalNeedItemNum(pDeityCfg->m_UpLvType, m_nDeityLev, pDeityCfg->m_material[i].m_exp);
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
            int64_t addExp = pDeityCfg->m_material[i].m_exp * useItemNum;
            m_nDeityExp = m_nDeityExp + addExp;
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
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_LEVUP_RSP, xDataRsp);
        return 0;
    }
    
    int64_t needExp = pCurCfg->m_Exp;
    while ((uint64_t) m_nDeityExp >= (uint64_t) needExp)
    {
        m_nDeityLev = m_nDeityLev + 1;
        m_nDeityExp -= needExp;
        
        pCurCfg = pNextCfg;
        needExp = pCurCfg->m_Exp;
        pNextCfg = AvatarValueDesc::Instance()->GetDescByTypeLv(pDeityCfg->m_UpLvType, m_nDeityLev + 1);
        if (pNextCfg == nullptr)
        {
            break;
        }
    }
    
    VEC_STRING vecString;
    NFCommonApi::SplitStr(pDeityCfg->m_skillID.data(), "|", &vecString);
    for (int i = 0; i < (int) vecString.size(); i++)
    {
        std::string skillStr = vecString[i];
        if (!skillStr.empty())
        {
            VEC_INT64 vecNum;
            NFCommonApi::SplitStrToVecInt(skillStr, ";", &vecNum);
            if (vecNum.size() == 2)
            {
                int lev = GetSkillLev(vecNum[0]);
                if (lev == 0)
                {
                    if (m_nDeityLev >= vecNum[1])
                    {
                        SetSkillInfo(vecNum[0], 1);
                        //add skill
                        NFSkillPart *pSkillPart = dynamic_cast<NFSkillPart *>(m_pMaster->GetPart(PART_SKILL));
                        if (pSkillPart)
                        {
                            pSkillPart->AddSkill(vecNum[0], 1, sourceParam, true);
                        }
                        
                        proto_ff::DeitySkillUnlockNotify notify;
                        auto pSkillInfo = notify.mutable_skill_data();
                        if (pSkillInfo)
                        {
                            pSkillInfo->set_skill_id(vecNum[0]);
                            pSkillInfo->set_skill_lev(1);
                        }
                        m_pMaster->SendMsgToClient(proto_ff::CLIENT_TO_LOGIC_DEITY_SKILL_UNLOCK_NOTIFY, notify);
                    }
                }
            }
        }
    }
    
    calcAttr(true);
    SetNeedSave(true);
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    xDataRsp.set_deity_id(m_nDeityID);
    xDataRsp.set_deity_lev(m_nDeityLev);
    xDataRsp.set_deity_exp(m_nDeityExp);
    xDataRsp.set_fight_value(GetFightValue());
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_LEVUP_RSP, xDataRsp);
    return 0;
}

int NFDeityPart::OnHandleDeityFantasyBattleReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::DeityFantasyBattleReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    DeityFantasyBattle(xData.deity_fantasy_id(), xData.battle_slot());
    return 0;
}

int NFDeityPart::DeityFantasyBattle(uint32_t fantasyId, uint32_t battleSlot)
{
    proto_ff::DeityFantasyBattleRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    auto pSlotInfo = GetDeityBattleSlot(battleSlot);
    if (pSlotInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyBattleReq xData.battle_slot():%d error, not active", battleSlot);
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_BATTLE_RSP, xDataRsp);
        return proto_ff::RET_FAIL;
    }
    
    auto pFantasyInfo = GetFantasyData(fantasyId);
    if (pFantasyInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyBattleReq xData.deity_fantasy_id():%d error, not active", fantasyId);
        xDataRsp.set_ret_code(proto_ff::RET_DEITY_NOT_EXITST);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_BATTLE_RSP, xDataRsp);
        return proto_ff::RET_FAIL;
    }
    
    if (pSlotInfo->m_curState != proto_ff::DEITY_BATTLE_SLOT_STATE_EMPTY)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyBattleReq xData.battle_slot():%d error", battleSlot);
        if (pSlotInfo->m_curState == proto_ff::DEITY_BATTLE_SLOT_STATE_LOCK)
            xDataRsp.set_ret_code(proto_ff::RET_BATTLE_SLOT_NOT_UNLOCK);
        else
            xDataRsp.set_ret_code(proto_ff::RET_BATTLE_SLOT_HAS_DEITY);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_BATTLE_RSP, xDataRsp);
        return proto_ff::RET_FAIL;
    }
    
    pSlotInfo->m_curState = proto_ff::DEITY_BATTLE_SLOT_STATE_USING;
    pSlotInfo->m_deityId = fantasyId;
    calcAttr(true);
    SetNeedSave(true);
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    xDataRsp.set_fight_value(GetFightValue());
    pSlotInfo->WriteToPB(xDataRsp.mutable_battle_data());
    
    proto_ff::DeityFantasyBattleEvent event;
    int num = 0;
    for (auto iter = m_battleDeityList.begin(); iter != m_battleDeityList.end(); iter++)
    {
        if (iter->second.m_curState == proto_ff::DEITY_BATTLE_SLOT_STATE_USING)
        {
            num++;
        }
    }
    event.set_num(num);
    FireExecute(NF_ST_LOGIC_SERVER, EVENT_DEITY_FANTASY_BATTLE, CREATURE_PLAYER, m_pMaster->Cid(), event);
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_BATTLE_RSP, xDataRsp);
    return 0;
}

int NFDeityPart::OnHandleDeityFantasyQuitBattleReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::DeityFantasyQuitBattleReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::DeityFantasyQuitBattleRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    auto pSlotInfo = GetDeityBattleSlot(xData.battle_slot());
    if (pSlotInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityUnlockBattleSlotReq xData.battle_slot():%d error, not active", xData.battle_slot());
        xDataRsp.set_ret_code(proto_ff::RET_BATTLE_SLOT_NOT_EXIST);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_QUIT_BATTLE_RSP, xDataRsp);
        return 0;
    }
    
    if (pSlotInfo->m_curState != proto_ff::DEITY_BATTLE_SLOT_STATE_USING)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityUnlockBattleSlotReq xData.battle_slot():%d error, not active", xData.battle_slot());
        xDataRsp.set_ret_code(proto_ff::RET_BATTLE_SLOT_NO_DEITY);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_QUIT_BATTLE_RSP, xDataRsp);
        return 0;
    }
    
    if (pSlotInfo->GetLeftWarTime() > 0)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityUnlockBattleSlotReq GetLeftWarTime > 0 xData.battle_slot():%d error, not active",
                       xData.battle_slot());
        xDataRsp.set_ret_code(proto_ff::RET_BATTLE_SLOT_CD_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_QUIT_BATTLE_RSP, xDataRsp);
        return 0;
    }
    
    pSlotInfo->m_curState = proto_ff::DEITY_BATTLE_SLOT_STATE_EMPTY;
    pSlotInfo->m_deityId = 0;
    calcAttr(true);
    xDataRsp.set_fight_value(GetFightValue());
    pSlotInfo->WriteToPB(xDataRsp.mutable_battle_data());
    xDataRsp.set_ret_code(proto_ff::RET_BATTLE_SLOT_CD_ERROR);
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_QUIT_BATTLE_RSP, xDataRsp);
    return 0;
}

int NFDeityPart::OnHandleDeityFragmentUseReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::DeityFragmentUseReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::DeityFragmentUseRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    auto pDeityCfg = AvatarDisplayDesc::Instance()->GetDesc(m_nDeityID);
    if (pDeityCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityLevelUpReq g_GetAvatarDisplayCfgTable()->GetAvatarDisplayCfgInfo == nullptr, deity_id=%u",
                       m_nDeityID);
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FRAGEMNT_USE_RSP, xDataRsp);
        return 0;
    }
    
    bool has = false;
    for (int i = 0; i < (int) pDeityCfg->m_fragmentID.size(); i++)
    {
        if ((uint64_t) pDeityCfg->m_fragmentID[i] == xData.fragment_id())
        {
            has = true;
            break;
        }
    }
    
    if (has == false)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityLevelUpReq xData.OnHandleFragmentUse():%d error", xData.fragment_id());
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FRAGEMNT_USE_RSP, xDataRsp);
        return 0;
    }
    
    auto pFragmentInfo = AvatarFragmentDesc::Instance()->GetDesc(xData.fragment_id());
    if (pFragmentInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityLevelUpReq GetAvatarFragmentCfgInfo == nullptr,fragment_id=%u", xData.fragment_id());
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FRAGEMNT_USE_RSP, xDataRsp);
        return 0;
    }
    
    if (m_mapFragment.find(xData.fragment_id()) == m_mapFragment.end())
    {
        m_mapFragment[xData.fragment_id()] = 0;
    }
    
    uint32_t useTimes = m_mapFragment[xData.fragment_id()];
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    CHECK_NULL(pPackagePart);
    
    SCommonSource sourceParam;
    sourceParam.src = S_DEITY_RRAGMENT;
    sourceParam.param1 = xData.fragment_id();
    sourceParam.param2 = useTimes;
    int64_t nUnBindNum = 0;
    int64_t nBindNum = 0;
    int32_t allNum = pPackagePart->GetItemNum(pFragmentInfo->m_item, nUnBindNum, nBindNum);
    
    int32_t canCost = ((int32_t) useTimes + allNum > pFragmentInfo->m_itemNum) ? (pFragmentInfo->m_itemNum - (int32_t) useTimes) : allNum;
    if (canCost <= 0)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FRAGEMNT_USE_RSP, xDataRsp);
        return 0;
    }
    
    bool ret = pPackagePart->RemoveItem(pFragmentInfo->m_item, canCost, sourceParam);
    if (ret == false)
    {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FRAGEMNT_USE_RSP, xDataRsp);
        return 0;
    }
    
    m_mapFragment[xData.fragment_id()] = m_mapFragment[xData.fragment_id()] + canCost;
    calcAttr(true);
    SetNeedSave(true);
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    for (auto iter = m_mapFragment.begin(); iter != m_mapFragment.end(); iter++)
    {
        auto pAddFragmentInfo = xDataRsp.add_fragment_data();
        pAddFragmentInfo->set_fragment_id(iter->first);
        pAddFragmentInfo->set_use_times(iter->second);
    }
    xDataRsp.set_fight_value(GetFightValue());
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FRAGEMNT_USE_RSP, xDataRsp);
    return 0;
}

int NFDeityPart::OnHandleDeityFantasyInfoReq(uint32_t msgId, NFDataPackage &packet)
{
    SendDeaityFantasyInfo();
    return 0;
}

int NFDeityPart::OnHandleDeityFantasyActiveReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::DeityFantasyActiveReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    ActiveDeityFantasy(xData.fantasy_id());
    return 0;
}

int NFDeityPart::ActiveDeityFantasy(uint32_t fantasyId)
{
    proto_ff::DeityFastasyActiveRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    auto pFantasyInfo = AvatarChangeDesc::Instance()->GetDesc(fantasyId);
    if (pFantasyInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyActiveReq GetAvatarChangeCfgInfo == nullptr,fantasy_id=%u", fantasyId);
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_ACTIVE_RSP, xDataRsp);
        return proto_ff::RET_FAIL;
    }
    
    if (m_mapFantasyDeity.find(fantasyId) != m_mapFantasyDeity.end())
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyActiveReq xData.fantasy_id():%d error, has active", fantasyId);
        xDataRsp.set_ret_code(proto_ff::RET_DEITY_NOT_EXITST);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_ACTIVE_RSP, xDataRsp);
        return proto_ff::RET_FAIL;
    }
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    CHECK_NULL(pPackagePart);
    
    NFSkillPart *pSkillPart = dynamic_cast<NFSkillPart *>(m_pMaster->GetPart(PART_SKILL));
    CHECK_NULL(pSkillPart);
    
    SCommonSource sourceParam;
    sourceParam.src = S_DEITY_ACTIVE_FANTASY;
    sourceParam.param1 = fantasyId;
    bool ret = pPackagePart->RemoveItem(pFantasyInfo->m_activationItem, pFantasyInfo->m_activationNum, sourceParam);
    if (ret == false)
    {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_ACTIVE_RSP, xDataRsp);
        return proto_ff::RET_FAIL;
    }
    
    auto pFantasy = &m_mapFantasyDeity[fantasyId];
    pFantasy->m_id = fantasyId;
    pFantasy->m_level = 0;
    pFantasy->m_star = 0;
    auto pEqiupSuitMap = AvatarEquipsuitDesc::Instance()->GetResDescPtr();
    for(auto iter = pEqiupSuitMap->begin(); iter != pEqiupSuitMap->end(); iter++)
    {
        pFantasy->m_equipSuit.emplace(iter->second.m_id, proto_ff::EDeityEquipSuitStatus_NONE);
    }
    
    VEC_STRING vecString;
    NFCommonApi::SplitStr(pFantasyInfo->m_skillID.data(), "|", &vecString);
    for (int i = 0; i < (int) vecString.size(); i++)
    {
        std::string skillStr = vecString[i];
        if (!skillStr.empty())
        {
            VEC_INT64 vecNum;
            NFCommonApi::SplitStrToVecInt(skillStr, ";", &vecNum);
            if (vecNum.size() == 2)
            {
                pFantasy->m_mapSkill.emplace(vecNum[0], 0);
            }
        }
    }
    
    for (int i = 0; i < (int) pFantasyInfo->m_InitiativeSkill.size(); i++)
    {
        int64_t skillId = pFantasyInfo->m_InitiativeSkill[i];
        if (skillId > 0)
        {
            pSkillPart->AddSkill(skillId, 1, sourceParam, true);
        }
    }
    
    SetNeedSave(true);
    calcAttr(true);
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    m_mapFantasyDeity[fantasyId].WriteToPB(m_pMaster, xDataRsp.mutable_fantasy_data());
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_ACTIVE_RSP, xDataRsp);
    
    SendDeityShowFantasyList();
    
    proto_ff::DeityActiveEvent event;
    event.set_id(pFantasy->m_id);
    FireExecute(NF_ST_LOGIC_SERVER, EVENT_DEITY_FANTASY_ACTIVE, CREATURE_PLAYER, m_pMaster->Cid(), event);
    return 0;
}

int NFDeityPart::OnHandleDeityFantasyLevelUpReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::DeityFantasyLevelupReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    NFSkillPart *pSkillPart = dynamic_cast<NFSkillPart *>(m_pMaster->GetPart(PART_SKILL));
    CHECK_NULL(pSkillPart);
    
    uint64_t materialId = xData.material_id();
    proto_ff::DeityFastasyLevelupRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    auto pFantasyInfo = AvatarChangeDesc::Instance()->GetDesc(xData.fantasy_id());
    if (pFantasyInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyLevelUpReq GetAvatarChangeCfgInfo == nullptr,fantasy_id=%u", xData.fantasy_id());
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    auto pFantasyData = GetFantasyData(xData.fantasy_id());
    if (pFantasyData == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyLevelUpReq xData.fantasy_id():%d error, not active", xData.fantasy_id());
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    if (pFantasyData->m_level >= (uint32_t) pFantasyInfo->m_LvMax)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyLevelUpReq:%d level >= maxLevel:%d error, not active", xData.fantasy_id(),
                      pFantasyData->m_level);
        xDataRsp.set_ret_code(proto_ff::RET_DEITY_MAX_LEVEL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    CHECK_NULL(pPackagePart);
    
    auto pCurCfg = AvatarValueDesc::Instance()->GetDescByTypeLv(pFantasyInfo->m_UpLvType, pFantasyData->m_level);
    if (pCurCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyLevelUpReq pCurCfg == nullptr,currentLev=%u", pFantasyData->m_level);
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    auto pNextCfg = AvatarValueDesc::Instance()->GetDescByTypeLv(pFantasyInfo->m_UpLvType, pFantasyData->m_level + 1);
    if (pNextCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyLevelUpReq pCurCfg == nullptr,currentLev=%u, nextLev=%u", pFantasyData->m_level,
                      pFantasyData->m_level + 1);
        xDataRsp.set_ret_code(proto_ff::RET_FACADE_MAX_LEVEL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    SCommonSource sourceParam;
    sourceParam.src = S_DEITY_FANTASY_LV;
    sourceParam.param1 = xData.fantasy_id();
    sourceParam.param2 = pFantasyData->m_level;
    bool bSuccess = false;
    for (int i = 0; i < (int) pFantasyInfo->m_material.size(); i++)
    {
        if (materialId != (uint64_t) pFantasyInfo->m_material[i].m_id)
        {
            continue;
        }
        
        int64_t bindNum = 0;
        int64_t unBindNum = 0;
        uint32_t itemNum = pPackagePart->GetItemNum(materialId, bindNum, unBindNum);
        //最大可使用数量（升级到满级）
        uint32_t needMax = CalFantasyLevelNeedItemNum(pFantasyInfo->m_UpLvType, pFantasyData->m_level, pFantasyInfo->m_material[i].m_exp);
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
            int64_t addExp = pFantasyInfo->m_material[i].m_exp * useItemNum;
            pFantasyData->m_exp = pFantasyData->m_exp + addExp;
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
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_LEVELUP_RSP, xDataRsp);
        return 0;
    }
    
    int64_t needExp = pCurCfg->m_Exp;
    while ((uint64_t) pFantasyData->m_exp >= (uint64_t) needExp)
    {
        pFantasyData->m_level = pFantasyData->m_level + 1;
        pFantasyData->m_exp -= needExp;
        
        pCurCfg = pNextCfg;
        needExp = pCurCfg->m_Exp;
        pNextCfg = AvatarValueDesc::Instance()->GetDescByTypeLv(pFantasyInfo->m_UpLvType, pFantasyData->m_level + 1);
        if (pNextCfg == nullptr)
        {
            break;
        }
    }
    
    VEC_STRING vecString;
    NFCommonApi::SplitStr(pFantasyInfo->m_skillID.data(), "|", &vecString);
    for (int i = 0; i < (int) vecString.size(); i++)
    {
        std::string skillStr = vecString[i];
        if (!skillStr.empty())
        {
            VEC_INT64 vecNum;
            NFCommonApi::SplitStrToVecInt(skillStr, ";", &vecNum);
            if (vecNum.size() == 2 && pFantasyData->m_level >= vecNum[1])
            {
                auto iter = pFantasyData->m_mapSkill.find(vecNum[0]);
                if (iter != pFantasyData->m_mapSkill.end() && iter->second == 0)
                {
                    iter->second = 1;
                    pSkillPart->AddSkill(vecNum[0], 1, sourceParam, true);
                }
            }
        }
    }
    
    SetNeedSave(true);
    calcAttr(true);
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    pFantasyData->WriteToPB(m_pMaster, xDataRsp.mutable_fantasy_data());
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_LEVELUP_RSP, xDataRsp);
    return 0;
}

int NFDeityPart::OnHandleDeityFantasyStarupReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::DeityFantasyStarUpReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::DeityFastasyStarUpRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    auto pFantasyInfo = AvatarChangeDesc::Instance()->GetDesc(xData.fantasy_id());
    if (pFantasyInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyStarupReq GetAvatarChangeCfgInfo == nullptr,fantasy_id=%u", xData.fantasy_id());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_STARUP_RSP, xDataRsp);
        return 0;
    }
    
    auto pFantasyData = GetFantasyData(xData.fantasy_id());
    if (pFantasyData == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyStarupReq xData.fantasy_id():%d error, not active", xData.fantasy_id());
        xDataRsp.set_ret_code(proto_ff::RET_DEITY_NOT_EXITST);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_STARUP_RSP, xDataRsp);
        return 0;
    }
    
    uint32_t curStar = pFantasyData->m_star;
    
    if (curStar >= (uint32_t) pFantasyInfo->m_starMax)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] FacadePart::OnHandleFantasyLevelupInfo:%d level >= maxLevel:%d error, not active", xData.fantasy_id(), curStar);
        xDataRsp.set_ret_code(proto_ff::RET_DEITY_MAX_STAR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_STARUP_RSP, xDataRsp);
        return 0;
    }
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    if (pPackagePart == nullptr)
    {
        xDataRsp.set_ret_code(proto_ff::RET_DEITY_MAX_STAR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_STARUP_RSP, xDataRsp);
        return 0;
    }
    
    auto pStarCfgInfo = AvatarValueDesc::Instance()->GetDescByTypeLv(pFantasyInfo->m_starUpAttributeId, curStar);
    if (pStarCfgInfo == nullptr)
    {
        xDataRsp.set_ret_code(proto_ff::RET_DEITY_MAX_STAR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_STARUP_RSP, xDataRsp);
        return 0;
    }
    
    auto pNextStarCfgInfo = AvatarValueDesc::Instance()->GetDescByTypeLv(pFantasyInfo->m_starUpAttributeId, curStar + 1);
    if (pNextStarCfgInfo == nullptr)
    {
        xDataRsp.set_ret_code(proto_ff::RET_DEITY_MAX_STAR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_STARUP_RSP, xDataRsp);
        return 0;
    }
    
    SCommonSource sourceParam;
    sourceParam.src = S_DEITY_FANTASY_STAR;
    sourceParam.param1 = xData.fantasy_id();
    sourceParam.param2 = curStar;
    
    LIST_ITEM lstItem;
    SItem item;
    item.nItemID = pFantasyInfo->m_starId;
    item.nNum = pStarCfgInfo->m_cost;
    item.byBind = EBindState_all;
    lstItem.push_back(item);
    
    if (item.nItemID == 0 || item.nNum == 0)
    {
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_STARUP_RSP, xDataRsp);
        return 0;
    }
    
    if (!pPackagePart->RemoveItem(lstItem, sourceParam))
    {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_STARUP_RSP, xDataRsp);
        return 0;
    }
    
    curStar = curStar + 1;
    pFantasyData->m_star = curStar;
    SetNeedSave(true);
    calcAttr(true);
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    pFantasyData->WriteToPB(m_pMaster, xDataRsp.mutable_fantasy_data());
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_STARUP_RSP, xDataRsp);
    return 0;
}

int NFDeityPart::OnHandleDeityUnlockBattleSlotReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::DeityUnlockBattleSlotReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::DeityUnlockBattleSlotRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    auto pSlotInfo = GetDeityBattleSlot(xData.id());
    if (m_battleDeityList.find(xData.id()) == m_battleDeityList.end())
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityUnlockBattleSlotReq xData.fantasy_id():%d error, not active", xData.id());
        xDataRsp.set_ret_code(proto_ff::RET_BATTLE_SLOT_NOT_EXIST);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_UNLOCK_BATTLE_SLOT_RSP, xDataRsp);
        return 0;
    }
    
    if (pSlotInfo->m_curState != proto_ff::DEITY_BATTLE_SLOT_STATE_LOCK)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityUnlockBattleSlotReq xData.fantasy_id():%d error, not active", xData.id());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_UNLOCK_BATTLE_SLOT_RSP, xDataRsp);
        return 0;
    }
    
    auto pSlotCfg = AvatarBattleslotDesc::Instance()->GetDesc(pSlotInfo->m_id);
    if (pSlotCfg == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityUnlockBattleSlotReq xData.fantasy_id():%d error, not active", xData.id());
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_UNLOCK_BATTLE_SLOT_RSP, xDataRsp);
        return 0;
    }
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    if (pPackagePart == nullptr)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_UNLOCK_BATTLE_SLOT_RSP, xDataRsp);
        return 0;
    }
    
    if (pSlotCfg->m_type == 2)
    {
        std::vector<int64_t> vec;
        NFCommonApi::SplitStrToVecInt(pSlotCfg->m_arg.data(), ";", &vec);
        if (vec.size() != 2)
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityUnlockBattleSlotReq xData.fantasy_id():%d error, not active", xData.id());
            xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
            m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_UNLOCK_BATTLE_SLOT_RSP, xDataRsp);
            return 0;
        }
        
        SCommonSource sourceParam;
        sourceParam.src = S_DEITY_UNLOCK_BATTLE_SLOT;
        sourceParam.param1 = pSlotCfg->m_id;
        
        LIST_ITEM lstItem;
        SItem item;
        item.nItemID = vec[0];
        item.nNum = vec[1];
        item.byBind = EBindState_all;
        lstItem.push_back(item);
        
        if (!pPackagePart->RemoveItem(lstItem, sourceParam))
        {
            xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
            m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_UNLOCK_BATTLE_SLOT_RSP, xDataRsp);
            return 0;
        }
        
        pSlotInfo->m_curState = proto_ff::DEITY_BATTLE_SLOT_STATE_EMPTY;
        xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
        SetNeedSave(true);
    }
    
    pSlotInfo->WriteToPB(xDataRsp.mutable_battle_data());
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_UNLOCK_BATTLE_SLOT_RSP, xDataRsp);
    return 0;
}

int NFDeityPart::OnHandleDeityFantasyEnterWarReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::DeityFantasyEnterWarReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::DeityFantasyEnterWarRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_FAIL);
    
    auto pSlotInfo = GetDeityBattleSlot(xData.id());
    if (pSlotInfo == NULL || pSlotInfo->m_curState != proto_ff::DEITY_BATTLE_SLOT_STATE_USING || pSlotInfo->m_deityId <= 0 || pSlotInfo->m_enterWarTime > 0)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyEnterWarReq xData.fantasy_id():%d error, not active", xData.id());
        xDataRsp.set_ret_code(proto_ff::RET_BATTLE_SLOT_NO_DEITY);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_ENTER_WAR_RSP, xDataRsp);
        return 0;
    }
    
    auto pSlotCfg = AvatarBattleslotDesc::Instance()->GetDesc(pSlotInfo->m_id);
    if (pSlotCfg == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyEnterWarReq xData.fantasy_id():%d error, not active", xData.id());
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_ENTER_WAR_RSP, xDataRsp);
        return 0;
    }
    
    auto pFantasyCfg = AvatarChangeDesc::Instance()->GetDesc(pSlotInfo->m_deityId);
    if (pFantasyCfg == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyEnterWarReq GetAvatarChangeCfgInfo == nullptr,fantasy_id=%u", pSlotInfo->m_deityId);
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_ENTER_WAR_RSP, xDataRsp);
        return 0;
    }
    
    NFSkillPart* pSkillPart = dynamic_cast<NFSkillPart*>(m_pMaster->GetPart(PART_SKILL));
    if (pSkillPart == nullptr)
    {
        xDataRsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_ENTER_WAR_RSP, xDataRsp);
        return 0;
    }
    int32_t ret = pSkillPart->OnDeityChgFacade(pSlotInfo->m_deityId);
    if (proto_ff::RET_SUCCESS != ret)
    {
        xDataRsp.set_ret_code(ret);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_ENTER_WAR_RSP, xDataRsp);
        return 0;
    }
    return 0;
}

int NFDeityPart::OnDeityWarSuccess(int64_t deityId)
{
    DeityBattleSlot* pslot = nullptr;
    for (auto &iter : m_battleDeityList)
    {
        if (iter.second.m_deityId == deityId)
        {
            pslot = &iter.second;
            break;
        }
    }
    CHECK_EXPR(nullptr != pslot, -1, "[logic] DeityPart::OnDeityWarSuccess....can not find battle deity...cid:%lu,deityid:%ld", m_pMaster->Cid(), deityId);
    if (pslot->m_curState != proto_ff::DEITY_BATTLE_SLOT_STATE_USING || pslot->m_deityId <= 0 || pslot->m_enterWarTime > 0)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnDeityWarSuccess  state or wartime error...cid:%lu,deityId:%ld, state:%d, deityid:%ld,wartime:%lu ",m_pMaster->Cid(), deityId, pslot->m_curState, pslot->m_deityId, pslot->m_enterWarTime);
        return 0;
    }
    auto pSlotCfg = AvatarBattleslotDesc::Instance()->GetDesc(pslot->m_id);
    CHECK_EXPR(nullptr != pSlotCfg, -1, "[logic] DeityPart::OnDeityWarSuccess...can not find deity battleslot cfg...cid:%lu,deityid:%ld, id:%u", m_pMaster->Cid(), deityId, pslot->m_id);
    //
    auto pFantasyCfg = AvatarChangeDesc::Instance()->GetDesc(deityId);
    CHECK_EXPR(nullptr != pFantasyCfg, -1, "[logic] DeityPart::OnDeityWarSuccess...can not find deity avatarchange cfg...cid:%lu,deityid:%ld, id:%u", m_pMaster->Cid(), deityId, pslot->m_id);
    //
    pslot->m_enterWarTime = NFTime::Now().UnixSec();
    SetNeedSave(true);
    pslot->DeleteAllTimer();
    pslot->SetTimer(0, 0, pFantasyCfg->m_avatarCD, 0);
    //
    NFLogDebugFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnDeityWarSuccess....cid:%lu, id:%u, deityid:%lu, wartime:%lu,state:%d ", m_pMaster->Cid(), pslot->m_id, pslot->m_deityId, pslot->m_enterWarTime,pslot->m_curState);;
    //
    proto_ff::DeityFantasyEnterWarRsp rsp;
    rsp.set_ret_code(proto_ff::RET_SUCCESS);
    pslot->WriteToPB(rsp.mutable_battle_data());
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_FANTASY_ENTER_WAR_RSP, rsp);
    return 0;
}

int NFDeityPart::OnHandleDeityShowFantasyListReq(uint32_t msgId, NFDataPackage &packet)
{
    SendDeityShowFantasyList();
    return 0;
}

int NFDeityPart::OnHandleDeityEquipDressReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::DeityEquipDressReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
    
    int32_t bag_pos = req.bag_pos();
    
    proto_ff::DeityEquipDressRsp rsp;
    rsp.set_fantasy_id(req.fantasy_id());
    rsp.set_bag_pos(bag_pos);
    rsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    auto pFantasyInfo = AvatarChangeDesc::Instance()->GetDesc(req.fantasy_id());
    if (pFantasyInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityEquipDressReq GetAvatarChangeCfgInfo == nullptr,fantasy_id=%u", req.fantasy_id());
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DRESS_RSP, rsp);
        return 0;
    }
    
    auto pFantasyData = GetFantasyData(req.fantasy_id());
    if (pFantasyData == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyLevelUpReq xData.fantasy_id():%d error, not active", req.fantasy_id());
        rsp.set_ret_code(proto_ff::RET_DEITY_NOT_EXITST);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DRESS_RSP, rsp);
        return 0;
    }
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    CHECK_NULL(pPackagePart);
    
    NFDeityEquip* pEquip = dynamic_cast<NFDeityEquip*>(pPackagePart->GetPackageItemByIndex(proto_ff::EPackageType_DeityEquip, bag_pos));
    if (!pEquip || !pEquip->GetEquipCfg())
    {
        rsp.set_ret_code(proto_ff::RET_EQUIP_NOT_EXIST);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DRESS_RSP, rsp);
        return 0;
    }
    
    auto pEquipCfg = pEquip->GetEquipCfg();
    CHECK_NULL(pEquipCfg);
    
    if (pEquipCfg->m_quality > pFantasyInfo->m_maxEquip)
    {
        rsp.set_ret_code(proto_ff::RET_DEITY_EQUP_QUALITY_max);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DRESS_RSP, rsp);
        return 0;
    }
    
    uint8_t slotPos = pEquipCfg->m_position;
    if (!ValidPos(slotPos))
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DRESS_RSP, rsp);
        return 0;
    }
    
    int32_t level = m_pMaster->GetAttr(proto_ff::A_LEVEL);
    if (level < pEquipCfg->m_level)
    {
        rsp.set_ret_code(proto_ff::RET_LEVEL_LACK);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DRESS_RSP, rsp);
        return 0;
    }
    
    if (!pEquip->IsProf(m_pMaster->GetAttr(proto_ff::A_PROF)))
    {
        rsp.set_ret_code(proto_ff::RET_PROF_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DRESS_RSP, rsp);
        return 0;
    }
    
    auto pDressEquipInfo = pFantasyData->m_equips.GetEquip(slotPos);
    CHECK_NULL(pDressEquipInfo);
    
    //已穿戴的装备
    proto_ff::NotifyPackageUpdate bagNotify;
    NFDeityEquip *pSlotEquip = &pDressEquipInfo->m_equip;
    if (pSlotEquip)
    {
        int32_t oldStrongLv = pSlotEquip->m_deityEquip.m_stronglv;
        int32_t oldStrongWearQualiy = pSlotEquip->m_deityEquip.m_strongWearQuality;
        pSlotEquip->m_deityEquip.m_stronglv = pEquip->m_deityEquip.m_stronglv;
        pSlotEquip->m_deityEquip.m_strongWearQuality = pEquip->m_deityEquip.m_strongWearQuality;
        pEquip->m_deityEquip.m_stronglv = oldStrongLv;
        pEquip->m_deityEquip.m_strongWearQuality = oldStrongWearQualiy;
        //这里把身上的装备设置到背包中去了
        pSlotEquip->SetIndex(bag_pos);
        pPackagePart->SetItemByIndex(proto_ff::EPackageType_DeityEquip, bag_pos, *pSlotEquip);
        //通知客户端更新
        pPackagePart->AddPackageUpdateInfo(pSlotEquip, bagNotify, 0);
    }
    else
    {
        pPackagePart->AddPackageUpdateInfo(pEquip, bagNotify, true); //删除背包装备，通知客户端
        pPackagePart->SetItemByIndex(proto_ff::EPackageType_DeityEquip, bag_pos, nullptr); //设置背包索引为空
    }
    
    pPackagePart->UpdatePackage(proto_ff::EPackageType_DeityEquip, bagNotify);
    pDressEquipInfo->m_equip = *pEquip;
    pEquip->SetIndex(slotPos);
    pEquip->SetBind(NFItemMgr::BindStateByWay(pEquip->GetItemID(), pEquip->GetBind()));
    
    calcEquipScore(*pFantasyData, slotPos);
    SetNeedSave(true);
    
    SendEquip(*pFantasyData, slotPos);
    m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DRESS_RSP, rsp);
    
    CheckEquipSuit(*pFantasyData);
    
    calcAttr(true);
    return 0;
}

int NFDeityPart::OnHandleDeityEquipUndressReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::DeityEquipUnDressReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
    int32_t slot_pos = req.slot_pos();
    
    proto_ff::DeityEquipUnDressRsp rsp;
    rsp.set_fantasy_id(req.fantasy_id());
    rsp.set_slot_pos(slot_pos);
    rsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    auto pFantasyInfo = AvatarChangeDesc::Instance()->GetDesc(req.fantasy_id());
    if (pFantasyInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityEquipDressReq GetAvatarChangeCfgInfo == nullptr,fantasy_id=%u", req.fantasy_id());
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_UNDRESS_RSP, rsp);
        return 0;
    }
    
    auto pFantasyData = GetFantasyData(req.fantasy_id());
    if (pFantasyData == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyLevelUpReq xData.fantasy_id():%d error, not active", req.fantasy_id());
        rsp.set_ret_code(proto_ff::RET_DEITY_NOT_EXITST);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_UNDRESS_RSP, rsp);
        return 0;
    }
    
    if (!ValidPos(slot_pos))
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_UNDRESS_RSP, rsp);
        return 0;
    }
    
    auto *pDressInfo = pFantasyData->m_equips.GetEquip(slot_pos);
    if (nullptr == pDressInfo || pDressInfo->m_equip.GetItemID() == 0)
    {
        rsp.set_ret_code(proto_ff::RET_EQUIP_POS_NOT_EXIT_EQUIP);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_UNDRESS_RSP, rsp);
        return 0;
    }
    
    int64_t equipId = pDressInfo->m_equip.GetItemID();
    
    auto pUndressEquipCfg = EquipEquipDesc::Instance()->GetDesc(equipId);
    CHECK_NULL(pUndressEquipCfg);
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    CHECK_NULL(pPackagePart);
    
    VEC_ITEM_PROTO_EX vecItemProto;
    proto_ff::ItemProtoInfo itemProto;
    NFItemMgr::SetItemProtoInfo(&pDressInfo->m_equip, &itemProto, 1);
    vecItemProto.push_back(itemProto);
    SCommonSource ss;
    ss.src = S_DEITY_FANTASY_EQUIP_UNDRESS;
    ss.param1 = equipId;
    if (!pPackagePart->AddItem(vecItemProto, ss))
    {
        rsp.set_ret_code(proto_ff::RET_PACKAGE_COMMON_SPACE_NOT_ENOUGH);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_UNDRESS_RSP, rsp);
        return 0;
    }
    
    pDressInfo->m_equip.Clear();
    calcEquipScore(*pFantasyData, slot_pos);
    SetNeedSave(true);
    SendEquip(*pFantasyData, slot_pos);
    m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_UNDRESS_RSP, rsp);
    
    calcAttr(true);
    
    CheckEquipSuit(*pFantasyData, false);
    return 0;
}

int NFDeityPart::OnHandleDeityEquipStrongReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::DeityEquipStrongReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
    int32_t slot_pos = req.slot_pos();
    
    auto pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    CHECK_NULL(pPackagePart);
    
    proto_ff::DeityEquipStrongRsp rsp;
    rsp.set_fantasy_id(req.fantasy_id());
    rsp.set_slot_pos(slot_pos);
    rsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    auto pFantasyInfo = AvatarChangeDesc::Instance()->GetDesc(req.fantasy_id());
    if (pFantasyInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityEquipDressReq GetAvatarChangeCfgInfo == nullptr,fantasy_id=%u", req.fantasy_id());
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_STRONG_RSP, rsp);
        return 0;
    }
    
    auto pFantasyData = GetFantasyData(req.fantasy_id());
    if (pFantasyData == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyLevelUpReq xData.fantasy_id():%d error, not active", req.fantasy_id());
        rsp.set_ret_code(proto_ff::RET_DEITY_NOT_EXITST);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_STRONG_RSP, rsp);
        return 0;
    }
    
    do
    {
        auto pDressInfo = pFantasyData->m_equips.GetEquip(slot_pos);
        if (!pDressInfo || !pDressInfo->m_equip.GetItemID() == 0)
        {
            rsp.set_ret_code(proto_ff::RET_EQUIP_POS_NOT_EXIT_EQUIP);
            break;
        }
        
        auto pDressEquipCfg = pDressInfo->m_equip.GetEquipCfg();
        if (pDressEquipCfg == NULL)
        {
            rsp.set_ret_code(proto_ff::RET_EQUIP_POS_NOT_EXIT_EQUIP);
            break;
        }
        
        int32_t equipType = NFItemMgr::GetEquipType(pDressInfo->m_equip.GetItemID());
        if (equipType != EEquipType_deity)
        {
            rsp.set_ret_code(proto_ff::RET_FAIL);
            break;
        }
        
        int32_t pos = pDressEquipCfg->m_position;
        int32_t wearQuality = pDressInfo->m_equip.m_deityEquip.m_strongWearQuality;
        
        stEquipStrongCfg *pStrongCfg = EquipDescEx::Instance()->GetStrongCfg(EQUIP_STRONG_ID(pos, wearQuality));
        if (!pStrongCfg)
        {
            rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
            break;
        }
        
        auto pStrongCfgCfg = pStrongCfg->GetConfig();
        if (!pStrongCfgCfg)
        {
            rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
            break;
        }
        
        int32_t curStrongLv = pDressInfo->m_equip.m_deityEquip.m_stronglv;
        if (curStrongLv >= pStrongCfgCfg->m_srtongUp)
        {
            rsp.set_ret_code(proto_ff::RET_EQUIP_STRONG_MAX);
            break;
        }
        
        stEquipLvCfg *pStrongLvCfg = EquipDescEx::Instance()->GetStrongLvCfg(curStrongLv + 1);
        if (!pStrongLvCfg)
        {
            rsp.set_ret_code(proto_ff::RET_EQUIP_STRONG_MAX);
            break;
        }
        
        auto iter_c = pStrongLvCfg->m_costItem.find(equipType);
        if (iter_c == pStrongLvCfg->m_costItem.end())
        {
            rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
            break;
        }
        
        SCommonSource s;
        s.src = S_DEITY_FANTASY_EQUIP_STRONG;
        s.param1 = slot_pos;
        if (!pPackagePart->RemoveItem(iter_c->second.key, iter_c->second.value, s))
        {
            rsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
            break;
        }
        
        pDressInfo->m_equip.m_deityEquip.m_stronglv++;
        
        SetNeedSave(true);
    } while (false);
    
    SendEquip(*pFantasyData, slot_pos);
    m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_STRONG_RSP, rsp);
    
    if (rsp.ret_code() == proto_ff::RET_SUCCESS)
    {
        calcAttr(true);
    }
    return 0;
}

int NFDeityPart::OnHandleDeityEquipStrongLvReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::DeityEquipStrongLvReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
    int32_t slot_pos = req.slot_pos();
    
    auto pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    CHECK_NULL(pPackagePart);
    
    proto_ff::DeityEquipStrongLvRsp rsp;
    rsp.set_fantasy_id(req.fantasy_id());
    rsp.set_slot_pos(slot_pos);
    rsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    auto pFantasyInfo = AvatarChangeDesc::Instance()->GetDesc(req.fantasy_id());
    if (pFantasyInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityEquipDressReq GetAvatarChangeCfgInfo == nullptr,fantasy_id=%u", req.fantasy_id());
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_STRONG_LV_RSP, rsp);
        return 0;
    }
    
    if (m_mapFantasyDeity.find(req.fantasy_id()) == m_mapFantasyDeity.end())
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyLevelUpReq xData.fantasy_id():%d error, not active", req.fantasy_id());
        rsp.set_ret_code(proto_ff::RET_DEITY_NOT_EXITST);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_STRONG_LV_RSP, rsp);
        return 0;
    }
    
    FantasyDeityData &fantasyData = m_mapFantasyDeity[req.fantasy_id()];
    
    do
    {
        auto pDressInfo = fantasyData.m_equips.GetEquip(slot_pos);
        if (!pDressInfo || !pDressInfo->m_equip.GetItemID() == 0)
        {
            rsp.set_ret_code(proto_ff::RET_EQUIP_POS_NOT_EXIT_EQUIP);
            break;
        }
        
        int32_t equipType = NFItemMgr::GetEquipType(pDressInfo->m_equip.GetItemID());
        if (equipType != EEquipType_deity)
        {
            rsp.set_ret_code(proto_ff::RET_FAIL);
            break;
        }
        
        auto pEquipCfg = pDressInfo->m_equip.GetEquipCfg();
        if (!pEquipCfg)
        {
            rsp.set_ret_code(proto_ff::RET_FAIL);
            break;
        }
        
        int32_t pos = pEquipCfg->m_position;
        int32_t wearQuality = pDressInfo->m_equip.m_deityEquip.m_strongWearQuality;
        
        stEquipStrongCfg *pStrongCfg = EquipDescEx::Instance()->GetStrongCfg(EQUIP_STRONG_ID(pos, wearQuality));
        if (!pStrongCfg)
        {
            rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
            break;
        }
        
        auto pStrongCfgCfg = pStrongCfg->GetConfig();
        if (!pStrongCfg)
        {
            rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
            break;
        }
        
        int32_t curStrongLv = pDressInfo->m_equip.m_deityEquip.m_stronglv;
        if (curStrongLv < pStrongCfgCfg->m_srtongUp)
        {
            rsp.set_ret_code(proto_ff::RET_EQUIP_STRONG_MAX);
            break;
        }
        
        auto pBreakCfgInfo = EquipDescEx::Instance()->GetBreakCfgInfo(pos, wearQuality);
        if (!pBreakCfgInfo)
        {
            rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
            break;
        }
        
        list<SItem> itemList;
        for(int i = 0; i < (int)pBreakCfgInfo->m_break.size(); i++)
        {
            SItem item;
            if (pBreakCfgInfo->m_break[i].m_Item > 0 && pBreakCfgInfo->m_break[i].m_Num > 0)
            {
                item.nItemID = pBreakCfgInfo->m_break[i].m_Item;
                item.nNum = pBreakCfgInfo->m_break[i].m_Num;
                itemList.push_back(item);
            }
        }
        
        SCommonSource s;
        s.src = S_DEITY_FANTASY_EQUIP_STRONG_QUALITY;
        s.param1 = slot_pos;
        if (!pPackagePart->RemoveItem(itemList, s))
        {
            rsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
            break;
        }
        
        pDressInfo->m_equip.m_deityEquip.m_strongWearQuality++;
        SetNeedSave(true);
    } while (false);
    
    SendEquip(fantasyData, slot_pos);
    m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_STRONG_LV_RSP, rsp);
    
    if (rsp.ret_code() == proto_ff::RET_SUCCESS)
    {
        calcAttr(true);
    }
    return 0;
}

int NFDeityPart::OnHandleDeityEquipSuitActive(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::DeityEquipSuitActiveReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
    
    auto pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    CHECK_NULL(pPackagePart);
    
    proto_ff::DeityEquipSuitActiveRsp rsp;
    rsp.set_ret_code(proto_ff::RET_SUCCESS);
    rsp.set_fantasy_id(req.fantasy_id());
    
    auto pFantasyInfo = AvatarChangeDesc::Instance()->GetDesc(req.fantasy_id());
    if (pFantasyInfo == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityEquipDressReq GetAvatarChangeCfgInfo == nullptr,fantasy_id=%u", req.fantasy_id());
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_STRONG_LV_RSP, rsp);
        return 0;
    }
    
    auto pFantasyData = GetFantasyData(req.fantasy_id());
    if (pFantasyData == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityFantasyLevelUpReq xData.fantasy_id():%d error, not active", req.fantasy_id());
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_STRONG_LV_RSP, rsp);
        return 0;
    }
    
    auto iter = pFantasyData->m_equipSuit.find(req.equip_suit());
    if (iter == pFantasyData->m_equipSuit.end())
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_STRONG_LV_RSP, rsp);
        return 0;
    }
    
    if (iter->second != proto_ff::EDeityEquipSuitStatus_NOT_ACTIVE)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_STRONG_LV_RSP, rsp);
        return 0;
    }
    
    iter->second = proto_ff::EDeityEquipSuitStatus_ACTIVE;
    
    auto pSuit = rsp.add_equip_suit_data();
    pSuit->set_id(iter->first);
    pSuit->set_state(iter->second);
    
    m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_SUIT_ACTIVE_RSP, rsp);
    
    if (rsp.ret_code() == proto_ff::RET_SUCCESS)
    {
        calcAttr(true);
        SetNeedSave(true);
    }
    return 0;
}

int NFDeityPart::OnHandleDeityEquipDecomposeReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::DeityEquipDecomposeReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart*>(m_pMaster->GetPart(PART_PACKAGE));
    CHECK_NULL(pPackagePart);
    
    
    proto_ff::DeityEquipDecomposeRsp rsp;
    rsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    if (req.gridlist_size() == 0)
    {
        rsp.set_ret_code(proto_ff::RET_FAIL);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DECOMPOSE_RSP, rsp);
        return 0;
    }
    
    MAP_UINT16_INT64 mapIndexItem;
    SCommonSource sourceParam;
    sourceParam.src = S_DEITY_FANTASY_EQUIP_DECOMPOSE;
    list<SItem> itemList;
    for (int i = 0; i < (int)req.gridlist_size(); i++)
    {
        NFItem* pItem = pPackagePart->GetPackageItemByIndex(proto_ff::EPackageType_DeityEquip, req.gridlist(i));
        if (pItem == nullptr)
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityEquipDecomposeReq failed, pItemBase == nullptr....,grid[%u] is empty", req.gridlist(i));
            rsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
            m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DECOMPOSE_RSP, rsp);
            return 0;
        }
        
        auto pEquipCfg = EquipEquipDesc::Instance()->GetDesc(pItem->GetItemID());
        if (pEquipCfg == nullptr)
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleDeityEquipDecomposeReq failed, pEquipCfg == nullptr....,equipID:%lu", pItem->GetItemID());
            rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
            m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DECOMPOSE_RSP, rsp);
            return 0;
        }
        
        auto pItemMap = ItemDescEx::Instance()->GetSmeltMaterialCfg(pItem->GetItemID());
        if (pItemMap)
        {
            for(auto iter = pItemMap->begin(); iter != pItemMap->end(); iter++)
            {
                SItem item;
                item.nItemID = iter->first;
                item.nNum = iter->second;
                itemList.push_back(item);
            }
        }
        
        mapIndexItem[req.gridlist(i)] = 1;
    }
    
    if (!pPackagePart->CanAddItem(itemList))
    {
        rsp.set_ret_code(proto_ff::RET_PACKAGE_COMMON_SPACE_NOT_ENOUGH);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DECOMPOSE_RSP, rsp);
        return 0;
    }
    
    sourceParam.src = S_EQUIP_STOVE;
    if (!pPackagePart->RemoveItem(proto_ff::EPackageType_DeityEquip, mapIndexItem, sourceParam))
    {
        rsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DECOMPOSE_RSP, rsp);
        return 0;
    }
    
    pPackagePart->AddItem(itemList, sourceParam, true, true);
    m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DECOMPOSE_RSP, rsp);
    return 0;
}

int NFDeityPart::OnHandleEquipDisassmbleReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::DeityEquipDisassembleReq req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart*>(m_pMaster->GetPart(PART_PACKAGE));
    if (pPackagePart == nullptr)
    {
        return 0;
    }
    
    proto_ff::DeityEquipDisassembleRsp rsp;
    rsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    MAP_UINT16_INT64 mapIndexItem;
    SCommonSource sourceParam;
    
    NFDeityEquip *pEquip = dynamic_cast<NFDeityEquip *>(pPackagePart->GetPackageItemByIndex(proto_ff::EPackageType_DeityEquip, req.grid()));
    if (pEquip == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleEquipDisassmbleReq failed, pItemBase == nullptr....,grid[%u] is empty", req.grid());
        rsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DISASSEMBLE_RSP, rsp);
        return 0;
    }
    
    auto pEquipCfg = pEquip->GetEquipCfg();
    if (pEquipCfg == nullptr)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] DeityPart::OnHandleEquipDisassmbleReq failed, pEquipCfg == nullptr....,equipID:%lu", pEquip->GetItemID());
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DISASSEMBLE_RSP, rsp);
        return 0;
    }
    
    if (pEquip->m_deityEquip.m_stronglv == 0 || pEquip->m_deityEquip.m_strongWearQuality <= (uint32_t)pEquipCfg->m_wearQuality)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DISASSEMBLE_RSP, rsp);
        return 0;
    }
    
    int strongLv = pEquip->m_deityEquip.m_stronglv;
    int strongWearQuality = pEquip->m_deityEquip.m_strongWearQuality;
    int32_t equipType = NFItemMgr::GetEquipType(pEquip->GetItemID());
    int32_t pos = pEquipCfg->m_position;
    
    int curLv = 0;
    int curWearQuality = pEquipCfg->m_wearQuality;
    list<SItem> itemList;
    bool error = false;
    while(true)
    {
        if (curLv >= strongLv && curWearQuality >= strongWearQuality)
        {
            break;
        }
        
        stEquipStrongCfg *pStrongCfg = EquipDescEx::Instance()->GetStrongCfg(EQUIP_STRONG_ID(pos, curWearQuality));
        if (!pStrongCfg)
        {
            rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
            error = true;
            break;
        }
        
        auto pStrongCfgCfg = pStrongCfg->GetConfig();
        if (!pStrongCfgCfg)
        {
            rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
            error = true;
            break;
        }
        
        if (curLv >= pStrongCfgCfg->m_srtongUp)
        {
            auto pBreakCfgInfo = EquipDescEx::Instance()->GetBreakCfgInfo(pEquipCfg->m_position, curWearQuality);
            if (!pBreakCfgInfo)
            {
                rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
                error = true;
                break;
            }
            
            for(int i = 0; i < (int)pBreakCfgInfo->m_break.size(); i++)
            {
                SItem item;
                item.nItemID = pBreakCfgInfo->m_break[i].m_Item;
                item.nNum = pBreakCfgInfo->m_break[i].m_Num;
                itemList.push_back(item);
            }
            
            curWearQuality++;
        }
        else {
            stEquipLvCfg *pStrongLvCfg = EquipDescEx::Instance()->GetStrongLvCfg(curLv + 1);
            if (!pStrongLvCfg)
            {
                rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
                error = true;
                break;
            }
            
            auto iter_c = pStrongLvCfg->m_costItem.find(equipType);
            if (iter_c == pStrongLvCfg->m_costItem.end())
            {
                rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
                error = true;
                break;
            }
            
            SItem item;
            item.nItemID = iter_c->second.key;
            item.nNum = iter_c->second.value;
            itemList.push_back(item);
            curLv++;
        }
    }
    
    if (error)
    {
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DISASSEMBLE_RSP, rsp);
        return 0;
    }
    
    if (!pPackagePart->AddItem(itemList, sourceParam, true, true))
    {
        rsp.set_ret_code(proto_ff::RET_PACKAGE_COMMON_SPACE_NOT_ENOUGH);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DISASSEMBLE_RSP, rsp);
        return 0;
    }
    
    pEquip->m_deityEquip.m_stronglv = 0;
    pEquip->m_deityEquip.m_strongWearQuality = pEquipCfg->m_wearQuality;
    //已穿戴的装备
    proto_ff::NotifyPackageUpdate bagNotify;
    pPackagePart->AddPackageUpdateInfo(pEquip, bagNotify, 0);
    pPackagePart->UpdatePackage(proto_ff::EPackageType_DeityEquip, bagNotify);
    
    m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_DISASSEMBLE_RSP, rsp);
    return 0;
}

int NFDeityPart::ActiveFantasyAndEnterBattle(uint32_t deityId, uint32_t battleSlot)
{
    ActiveDeityFantasy(deityId);
    DeityFantasyBattle(deityId, battleSlot);
    SendDeityInfo();
    return 0;
}

bool NFDeityPart::ValidPos(int32_t pos)
{
    if (pos >= proto_ff::EDeityEquipPos_start && pos < proto_ff::EDeityEquipPos_start + proto_ff::EDeityEquipPos_limit)
    {
        return true;
    }
    return false;
}

int NFDeityPart::calcEquipScore(FantasyDeityData &fantasyData, int32_t pos)
{
    auto pDressEquip = fantasyData.m_equips.GetEquip(pos);
    CHECK_NULL(pDressEquip);
    
    if (pDressEquip->m_equip.GetItemID() == 0)
    {
        pDressEquip->m_slot.m_total_score = 0;
        SetNeedSave(true);
        return 0;
    }
    
    MAP_INT32_INT32 atts;
    pDressEquip->m_equip.GetAllAttr(atts, m_pMaster->GetAttr(proto_ff::A_LEVEL));
    
    float floatTotalScore = 0;
    for (auto &e: atts)
    {
        auto pAttrCfg = AttributeAttributeDesc::Instance()->GetDesc(e.first);
        if (pAttrCfg)
        {
            floatTotalScore += pAttrCfg->m_power * e.second;
        }
    }
    
    uint32_t intTotalScore = floor(floatTotalScore);
    
    if (pDressEquip->m_slot.m_total_score != intTotalScore)
    {
        pDressEquip->m_slot.m_total_score = intTotalScore;
        SetNeedSave(true);
    }
    return 0;
}

void NFDeityPart::SendEquip(FantasyDeityData &fantasyData, int32_t pos)
{
    SendDeaityFantasyInfo();
}

int NFDeityPart::SendDeityShowFantasyList()
{
    NFFunctionUnlockPart *pFunction = dynamic_cast<NFFunctionUnlockPart *>(m_pMaster->GetPart(PART_FUNCTIONUNLOCK));
    CHECK_NULL(pFunction);
    
    proto_ff::DeityShowFantasyListRsp rsp;
    auto pFantasyMap = AvatarChangeDesc::Instance()->GetResDescPtr();
    for (auto iter = pFantasyMap->begin(); iter != pFantasyMap->end(); iter++)
    {
        if (m_mapFantasyDeity.find(iter->second.m_id) != m_mapFantasyDeity.end())
        {
            auto pAdd = rsp.add_fantasy_data();
            pAdd->set_fantasy_id(iter->second.m_id);
            pAdd->set_active(true);
        }
        else
        {
            if (iter->second.m_funUnlock > 0)
            {
                if (pFunction->isFunctionUnlock(iter->second.m_funUnlock))
                {
                    auto pAdd = rsp.add_fantasy_data();
                    pAdd->set_fantasy_id(iter->second.m_id);
                    pAdd->set_active(false);
                }
            }
            else
            {
                auto pAdd = rsp.add_fantasy_data();
                pAdd->set_fantasy_id(iter->second.m_id);
                pAdd->set_active(false);
            }
        }
    }
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_DEITY_SHOW_FANTASY_LIST_RSP, rsp);
    return 0;
}

int NFDeityPart::CheckEquipSuit(FantasyDeityData &fantasyData, bool dress)
{
    int quality = -1;
    int star = -1;
    bool flag = false;
    for (int32_t i = proto_ff::EDeityEquipPos_ring; i < proto_ff::EDeityEquipPos_limit; i++)
    {
        // Exit if the current position is empty.
        auto pEquip = &fantasyData.m_equips.m_equips[i].m_equip;
        auto pEquipCfg = pEquip->GetEquipCfg();
        if (pEquip->GetItemID() == 0 || pEquipCfg == NULL)
        {
            flag = true;
            break;
        }
        // Set the quality
        if (quality == -1)
        {
            // Get the quality of the equipment
            quality = pEquipCfg->m_quality;
        }
        else
        {
            // Check if all the qualities are the same
            if (pEquipCfg->m_quality < quality)
            {
                quality = pEquipCfg->m_quality;
            }
        }
        // Set the star
        if (star == -1)
        {
            // Get the star of the equipment
            star = pEquipCfg->m_star;
        }
        else
        {
            // Check if all the stars are the same
            if (pEquipCfg->m_star < star)
            {
                star = pEquipCfg->m_star;
            }
        }
    }
    
    // Create response
    proto_ff::DeityEquipSuitActiveRsp rsp;
    rsp.set_ret_code(proto_ff::RET_SUCCESS);
    rsp.set_fantasy_id(fantasyData.m_id);
    
    if (dress && flag)
    {
        return 0;
    }
    
    if (!dress && flag)
    {
        for(auto iter = fantasyData.m_equipSuit.begin(); iter != fantasyData.m_equipSuit.end(); iter++)
        {
            // Continue if the status is NONE
            if (iter->second != proto_ff::EDeityEquipSuitStatus_NONE)
            {
                iter->second = proto_ff::EDeityEquipSuitStatus_NONE;
                auto pData = rsp.add_equip_suit_data();
                pData->set_id(iter->first);
                pData->set_state(iter->second);
            }
        }
    }
    else {
        // Iterate over all the suits
        for(auto iter = fantasyData.m_equipSuit.begin(); iter != fantasyData.m_equipSuit.end(); iter++)
        {
            // Continue if the status is NONE
            {
                // Get the config info for the current suit
                auto pCfgInfo = AvatarEquipsuitDesc::Instance()->GetDesc(iter->first);
                if (pCfgInfo)
                {
                    // Check if the quality and star of the suit are greater than or equal to that of the equipment
                    if (quality >= pCfgInfo->m_quality && star >= pCfgInfo->m_star)
                    {
                        // Set the status to NOT ACTIVE
                        if (iter->second == proto_ff::EDeityEquipSuitStatus_NONE)
                        {
                            iter->second = proto_ff::EDeityEquipSuitStatus_NOT_ACTIVE;
                            auto pData = rsp.add_equip_suit_data();
                            pData->set_id(iter->first);
                            pData->set_state(iter->second);
                        }
                    }
                    else {
                        iter->second = proto_ff::EDeityEquipSuitStatus_NONE;
                        auto pData = rsp.add_equip_suit_data();
                        pData->set_id(iter->first);
                        pData->set_state(iter->second);
                    }
                }
            }
        }
    }
    
    // If there is data in the response, set the need save flag to true, send the client the response, and recalculate the attributes
    if (rsp.equip_suit_data_size() > 0)
    {
        SetNeedSave(true);
        m_pMaster->SendMsgToClient(proto_ff::CLIENT_DEITY_EQUIP_SUIT_ACTIVE_RSP, rsp);
        calcAttr(true);
    }
    return 0;
}

bool NFDeityPart::IsActiveDeity(int64_t id)
{
    return m_mapFantasyDeity.find(id) != m_mapFantasyDeity.end();
}

FantasyDeityData* NFDeityPart::GetFantasyData(uint64_t fantasyId)
{
    auto iter = m_mapFantasyDeity.find(fantasyId);
    if (iter != m_mapFantasyDeity.end())
    {
        return &iter->second;
    }
    return nullptr;
}

DeityBattleSlot* NFDeityPart::GetDeityBattleSlot(uint64_t battleSlot)
{
    auto iter = m_battleDeityList.find(battleSlot);
    if (iter != m_battleDeityList.end())
    {
        return &iter->second;
    }
    return nullptr;
}
