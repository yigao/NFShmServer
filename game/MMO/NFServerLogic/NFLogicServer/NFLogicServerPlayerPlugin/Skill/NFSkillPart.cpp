// -------------------------------------------------------------------------
//    @FileName         :    NFSkillPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFSkillPart
//
// -------------------------------------------------------------------------

#include "NFSkillPart.h"
#include "NFBuffPart.h"
#include "Player/NFOccupationPart.h"
#include "Mission/NFMissionPart.h"
#include "Facade/NFPetPart.h"

const uint32_t SKILL_MAX_INDEX = 51;
const float HP_COEF_ADD_ANGER = 0.1f;
const uint32_t MAX_SKILL_ANGER_VALUE = 100;
const float GRAB_SKILL_DISTANCE = 1.0f;
const int32_t DY_MIN_SKILL_ID = 1000;

NFSkillPart::NFSkillPart()
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

NFSkillPart::~NFSkillPart()
{
}

int NFSkillPart::CreateInit()
{
    m_partType = PART_SKILL;
    memset(m_advpos, 0, sizeof(m_advpos[0]) * MAX_ROLE_SKILL_ADVANCE_POS);
    memset(m_advlev, 0, sizeof(m_advlev));
    m_curadvpos = 0;
    m_group = 0;
    m_lastgroup = 0;
    m_startpubcd = 0;
    m_fight = 0;
    m_deityid = 0;
    m_talentcnt = 0;
    m_anger = 0;
    m_first = true;
    return 0;
}

int NFSkillPart::ResumeInit()
{
    return 0;
}

int NFSkillPart::Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFSkillPart::UnInit()
{
    return NFPart::UnInit();
}

int NFSkillPart::LoadFromDB(const proto_ff::RoleDBData& data)
{
    if (data.has_skill())
    {
        uint64_t curmsec = NFTime::Now().UnixMSec();
        const proto_ff::SkillDBData& dbdata = data.skill();
        m_group = dbdata.group();
        m_lastgroup = dbdata.last_group();
        m_anger = dbdata.anger_value();
        uint32_t ninfosize = dbdata.info_lst_size();
        for (uint32_t i = 0; i < ninfosize; ++i)
        {
            const proto_ff::SkillDBInfo& proto = dbdata.info_lst(i);
            SkillInfo info;
            info.skill_id = proto.skill_id();
            info.level = proto.level();
            info.wakeup = proto.wakeup();
            info.use_msc = proto.use_msc();
            if (info.use_msc > curmsec) { info.use_msc = curmsec; }
            AddSkillInfo(info);
        }
        uint32_t ngroupsize = dbdata.group_lst_size();
        for (uint32_t n = 0; n < ngroupsize; ++n)
        {
            const proto_ff::SkillDBGroup& proto = dbdata.group_lst(n);
            SkillGroup sg;
            sg.group = proto.group();
            uint32_t possize = proto.pos_lst_size();
            //
            for (uint32_t m = 0; m < possize; ++m)
            {
                const proto_ff::SkillDBPos& protopos = proto.pos_lst(m);
                if (protopos.skill_id() > 0)
                {
                    sg.pos[protopos.pos()] = protopos.skill_id();
                    sg.autouse[protopos.pos()] = protopos.use();
                }
            }
            m_mapGroup[sg.group] = sg;
        }
        uint32_t possize = dbdata.adv_pos_size();
        for (uint32_t i = 0; i < possize; ++i)
        {
            const proto_ff::SkillDBAdvPos& protopos = dbdata.adv_pos(i);
            SkillAdvPosInfo* pinfo = GetAdvPosInfo(protopos.pos());
            if (nullptr != pinfo)
            {
                pinfo->advance = protopos.advance();
                pinfo->unlock = protopos.unlock();
            }
        }
        uint32_t infosize = dbdata.adv_info_size();
        for (uint32_t i = 0; i < infosize; ++i)
        {
            const proto_ff::SkillDBAdvInfo& protoinfo = dbdata.adv_info(i);
            if (protoinfo.advance() > 0 && protoinfo.level())
            {
                SetAdvLev(protoinfo.advance(), protoinfo.level());
            }
        }
        m_curadvpos = dbdata.cur_advpos();
        //
        uint32_t ncdsize = dbdata.pet_cd_size();
        for (uint32_t i = 0; i < ncdsize; ++i)
        {
            const proto_ff::PetSkillCdDB& protocd = dbdata.pet_cd(i);
            PetSkillCd cd;
            cd.petInstid = protocd.pet_instid();
            cd.usemsec = protocd.use_msec();
            if (cd.usemsec > curmsec) { cd.usemsec = curmsec; }
            m_mapPetSkillCd[protocd.skill_id()] = cd;
        }
        if (dbdata.has_talent())
        {
            const proto_ff::SkillDBTalent& prototalent = dbdata.talent();
            m_talentcnt = prototalent.cnt();
            uint32_t ntalentsize = prototalent.info_size();
            for (uint32_t i = 0; i < ntalentsize; ++i)
            {
                const proto_ff::SkillDBTalentProto& protoinfo = prototalent.info(i);
                TalentInfo info;
                info.id = protoinfo.id();
                info.lev = protoinfo.level();
                AddTalentInfo(info);
            }
        }
    }
    return 0;
}

int NFSkillPart::InitConfig(const proto_ff::RoleDBData& data)
{
    if (m_group <= 0)
    {
        m_group = SkillDescEx::Instance()->GetProfSkillGroupId(m_pMaster->GetAttr(proto_ff::A_PROF));
        SetNeedSave(true);
    }
    //
    if (m_curadvpos <= 0)
    {
        m_curadvpos = 1; //默认选中第一个位置
        SetNeedSave(true);
    }
    if (!IsAdvposUnlock(m_curadvpos))
    {
        UnlockAdvpos(m_curadvpos); //第一个位置默认是解锁的
        SetNeedSave(true);
    }
    CalcSkillFight();
    
    //检查宠物技能
    NFPetPart* ppetpart = dynamic_cast<NFPetPart*>(m_pMaster->GetPart(PART_PET));
    if (nullptr != ppetpart)
    {
        auto iter = m_mapPetSkillCd.begin();
        while (iter != m_mapPetSkillCd.end())
        {
            if (nullptr == ppetpart->GetPet(iter->second.petInstid))
            {
                iter = m_mapPetSkillCd.erase(iter);
                SetNeedSave(true);
                continue;
            }
            ++iter;
        }
    }
    //检查天神变身
    NFBuffPart* buffpart = dynamic_cast<NFBuffPart*>(m_pMaster->GetPart(PART_BUFF));
    if (nullptr != buffpart && buffpart->GetFacadeDeityId() <= 0)
    {
        OnDeityEndFacade();
    }
    //检查战魂复活
    auto pinfo = GetSoulSkillInfo(SkillDescEx::Instance()->GetSacrificeSkillId());
    if (nullptr != pinfo)
    {
        int64_t curmsec = NFTime::Now().UnixMSec();
        auto pInfoCfg = pinfo->GetDescCfg();
        if (pInfoCfg)
        {
            int64_t leftcd = SoulLeftCd(pinfo->skill_id, pInfoCfg->m_cd, curmsec);
            if (leftcd > 0)
            {
                NFLogInfoFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] SkillPart::OnInit....soul pet in cd...cid:%lu,leftcd:%ld", m_pMaster->Cid(), leftcd);
                if (leftcd < 1000) leftcd = 1000;
                //g_GetTimerAxis()->KillTimer(ETimerId_SoulSkillRelive, this);
                //g_GetTimerAxis()->SetTimer(ETimerId_SoulSkillRelive,leftcd,this,1);
            }
        }
    }
    return 0;
}

int NFSkillPart::SaveDB(proto_ff::RoleDBData& dbData)
{
    proto_ff::SkillDBData* protoskill = dbData.mutable_skill();
    protoskill->set_group(m_group);
    protoskill->set_last_group(m_lastgroup);
    protoskill->set_anger_value(m_anger);
    for (auto& iterinfo : m_mapskill)
    {
        proto_ff::SkillDBInfo* protoinfo = protoskill->add_info_lst();
        if (nullptr != protoinfo)
        {
            protoinfo->set_skill_id(iterinfo.second.skill_id);
            protoinfo->set_level(iterinfo.second.level);
            protoinfo->set_wakeup(iterinfo.second.wakeup);
            protoinfo->set_use_msc(iterinfo.second.use_msc);
        }
    }
    for (auto& iterg : m_mapGroup)
    {
        proto_ff::SkillDBGroup* protogroup = protoskill->add_group_lst();
        if (nullptr != protogroup)
        {
            protogroup->set_group(iterg.second.group);
            for (uint32_t i = 0; i < MAX_ROLE_SKILL_POS; ++i)
            {
                if (iterg.second.pos[i] <= 0) { continue; }
                proto_ff::SkillDBPos* protopos = protogroup->add_pos_lst();
                if (nullptr != protopos)
                {
                    protopos->set_skill_id(iterg.second.pos[i]);
                    protopos->set_pos(i);
                    protopos->set_use(iterg.second.autouse[i]);
                }
            }
        }
    }
    protoskill->set_cur_advpos(m_curadvpos);
    for (uint32_t i = 1; i <= MAX_ROLE_SKILL_ADVANCE_POS; ++i)
    {
        SkillAdvPosInfo* pinfo = GetAdvPosInfo(i);
        if (nullptr != pinfo)
        {
            proto_ff::SkillDBAdvPos* protopos = protoskill->add_adv_pos();
            if (nullptr != protopos)
            {
                protopos->set_pos(i);
                protopos->set_advance(pinfo->advance);
                protopos->set_unlock(pinfo->unlock);
            }
        }
    }
    for (uint32_t i = (uint32_t)ESkillAdvance::none + 1; i < (uint32_t)ESkillAdvance::limit; ++i)
    {
        uint8_t lev = GetAdvLev(i);
        if (lev > 0)
        {
            proto_ff::SkillDBAdvInfo* protoinfo = protoskill->add_adv_info();
            if (nullptr != protoinfo)
            {
                protoinfo->set_advance(i);
                protoinfo->set_level(lev);
            }
        }
    }
    for (auto& itercd : m_mapPetSkillCd)
    {
        proto_ff::PetSkillCdDB* protocd = protoskill->add_pet_cd();
        if (nullptr != protocd)
        {
            protocd->set_skill_id(itercd.first);
            protocd->set_pet_instid(itercd.second.petInstid);
            protocd->set_use_msec(itercd.second.usemsec);
        }
    }
    proto_ff::SkillDBTalent* prototalent = protoskill->mutable_talent();
    if (nullptr != prototalent)
    {
        prototalent->set_cnt(m_talentcnt);
        for (auto& iter : m_talent)
        {
            proto_ff::SkillDBTalentProto* protoinfo = prototalent->add_info();
            if (nullptr != protoinfo)
            {
                protoinfo->set_id(iter.second.id);
                protoinfo->set_level(iter.second.lev);
            }
        }
    }
    
    return 0;
}

int NFSkillPart::OnLogin()
{
    return NFPart::OnLogin();
}

int NFSkillPart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::SKILL_INFO_REQ);
    return 0;
}

int NFSkillPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    switch (msgId)
    {
        case proto_ff::SKILL_INFO_REQ:
        {
            OnDetail(msgId, packet);
            break;
        }
        default:break;
    }
    return 0;
}

int NFSkillPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

bool NFSkillPart::AddSkill(uint64_t skillid, int32_t level, const SCommonSource& src, bool sync, uint64_t use_msec)
{
    const SkillCfg* pcfg = SkillDescEx::Instance()->GetCfg(skillid);
    if (nullptr == pcfg)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] SkillPart::AddSkill...nullptr == pcfg....cid:%lu, skillid:%lu, lev:%d, src:%d,p1:%ld,p2:%ld,p3:%ld,use_msec:%lu", m_pMaster->Cid(), skillid, level, src.src, src.param1, src.param2, src.param3, use_msec);
        return false;
    }
    //
    return AddSkill(pcfg, level, src, sync, use_msec);
}

bool NFSkillPart::AddSkill(const SkillCfg* pcfg, int32_t level, const SCommonSource& src, bool sync, uint64_t use_msec)
{
    if (nullptr == pcfg)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] SkillPart::AddSkill...nullptr == pcfg....cid:%lu, lev:%d, src:%d,p1:%ld,p2:%ld,p3:%ld, use_msec:%lu", m_pMaster->Cid(), level, src.src, src.param1, src.param2, src.param3, use_msec);
        return false;
    }
    auto pCfgCfg = pcfg->GetCfg();
    CHECK_EXPR(pCfgCfg, false, "skillId:{}", pcfg->m_skillId);
    uint64_t skillid = pcfg->m_skillId;
    SkillInfo* pinfo = GetSkillData(skillid);
    if (nullptr != pinfo)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] SkillPart::AddSkill...skill already exist....cid:%lu,skillid:%lu, lev:%d, src:%d,p1:%ld,p2:%ld,p3:%ld,use_msec:%lu", m_pMaster->Cid(), skillid, level, src.src, src.param1, src.param2, src.param3, use_msec);
        return false;
    }
    SkillInfo info;
    info.skill_id = skillid;
    info.level = level;
    info.use_msc = use_msec;
    AddSkillInfo(info);
    //等级为0的技能，表示不加对应的buff
    if (level > 0 && SkillDescEx::Instance()->IsPassive(pcfg))
    {
        if (!OnAddPassiveSkill(pcfg, level, src, sync))
        {
            DelSkillInfo(skillid);
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] SkillPart::AddSkill...OnAddPassiveSkill failed....cid:%lu,skillid:%lu, lev:%d, src:%d,p1:%ld,p2:%ld,p3:%ld,use_msec:%lu", m_pMaster->Cid(), skillid, level, src.src, src.param1, src.param2, src.param3, use_msec);
            return false;
        }
    }
    //
    if (sync)
    {
        proto_ff::SkillInfoUpdateRsp rsp;
        proto_ff::SkillInfoListProto* protolst = rsp.mutable_info();
        if (nullptr != protolst)
        {
            proto_ff::SkillInfoProto* proto = protolst->add_lst();
            if (nullptr != proto)
            {
                SetSkillProto(&info, *proto);
            }
        }
        m_pMaster->SendMsgToClient(proto_ff::SKILL_INFO_UPDATE_RSP, rsp);
    }
    
    OnAddSkill(pcfg, level);
    OnAddSkillGroup(pcfg, sync);
    //
    if (SkillDescEx::Instance()->IsAngerSkill(skillid))
    {
        m_anger = MAX_SKILL_ANGER_VALUE;
        if (sync) { OnAngerUpdateRsp(); }
    }
    SetNeedSave(true);
    return true;
}

bool NFSkillPart::RemoveSkill(uint64_t skillid, const SCommonSource& src, bool sync)
{
    return false;
}

bool NFSkillPart::ReduceSkillCd(uint64_t skillid, uint32_t cd)
{
    return false;
}

bool NFSkillPart::CreatureRemoveSkill(uint64_t skillid, bool sync)
{
    return false;
}

bool NFSkillPart::CreatureRemoveSkill(const SkillCfg* pcfg, bool sync)
{
    return false;
}

bool NFSkillPart::CreatureRemoveSingleSkill(uint64_t skillid, bool sync)
{
    return false;
}

bool NFSkillPart::CreatureRemoveSingleSkill(const SkillCfg* pcfg, bool sync)
{
    return false;
}

void NFSkillPart::ResetSkillCd()
{
}

bool NFSkillPart::OnSkillUpgrade(uint64_t skillid, int32_t level, SCommonSource& src)
{
    return false;
}

void NFSkillPart::AdvanceInfo(int32_t& advancetype, int32_t& advancelev)
{
    SkillAdvPosInfo *pinfo = GetAdvPosInfo(CurAdvpos());
    if (nullptr != pinfo)
    {
        advancetype = pinfo->advance;
        advancelev = GetAdvLev(advancetype);
    }
}

int32_t NFSkillPart::OnDeityChgFacade(int64_t deityId)
{
    return 0;
}

void NFSkillPart::OnDeityStartFacade(int64_t deityId, bool sync)
{
}

void NFSkillPart::OnDeityEndFacade(bool sync)
{
}

void NFSkillPart::OnAddTalent(int32_t cnt)
{
}

void NFSkillPart::OnEnterFightState()
{
}

void NFSkillPart::OnLeaveFightState()
{
}

void NFSkillPart::OnHpChange(int64_t oldHp, int64_t curHp, int64_t maxHp)
{
}

void NFSkillPart::AddAnger(int32_t anger)
{
}

bool NFSkillPart::AddSkillGroup(int32_t skillGroupid, bool chg, bool sync)
{
    return false;
}

bool NFSkillPart::RmvSkillGroup(int32_t skillGroupid, bool sync)
{
    return false;
}

int32_t NFSkillPart::OnPetWar(int64_t petInstid)
{
    return 0;
}

void NFSkillPart::OnPetRest(int64_t petInstid)
{
}

void NFSkillPart::OnPetSkillUpgrade(uint64_t skillid, int32_t level)
{
}

void NFSkillPart::OnGoBack()
{
}

bool NFSkillPart::IsFirst(uint64_t skillid)
{
    return false;
}

void NFSkillPart::FirstUse(uint64_t skillid)
{
}

void NFSkillPart::OnLevelUp(int32_t oldlev, bool sync)
{
}

int32_t NFSkillPart::SkillUpgrade(uint64_t skillid)
{
    return 0;
}

const SkillInfo* NFSkillPart::GetSkillInfo(uint64_t skillid)
{
    return nullptr;
}

void NFSkillPart::OnUpdateAdvance()
{
}

void NFSkillPart::OnUpdateSkillGroup(int32_t group)
{
    proto_ff::SkillGroupUpdateRsp rsp;
    if (group <= 0)
    {
        //rsp.set_all(1);
        proto_ff::SkillGroupListProto* protolst = rsp.mutable_skill_group();
        if (nullptr != protolst) SetAllSkillGroupProto(*protolst);
    }
    else
    {
        //rsp.set_all(0);
        proto_ff::SkillGroupListProto* protolst = rsp.mutable_skill_group();
        if (nullptr != protolst)
        {
            protolst->set_cur_skill_group(m_group);
            auto pgroup = GetSkillGroup((uint32_t)group);
            if (nullptr != pgroup)
            {
                proto_ff::SkillGroupProto* protoinfo = protolst->add_info();
                if (nullptr != protoinfo)  SetSkillGroupProto(pgroup, *protoinfo);
            }
        }
    }

    m_pMaster->SendMsgToClient(proto_ff::SKILL_GROUP_UPDATE_RSP, rsp);
}

int NFSkillPart::OnTalentInfo(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFSkillPart::OnTalentUsePoint(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFSkillPart::OnTalentReset(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

void NFSkillPart::OnAngerUpdateRsp()
{
}

int NFSkillPart::AddSkillInfo(const SkillInfo& info)
{
    CHECK_EXPR(m_mapskill.size() < m_mapskill.max_size(), -1, "m_mapskill Space Not Enough");
    CHECK_EXPR(m_mapskill.find(info.skill_id) == m_mapskill.end(), -1, "m_mapskill Space Not Enough");
    
    m_mapskill[info.skill_id] = info;
    return 0;
}

void NFSkillPart::DelSkillInfo(uint64_t skillid)
{
    m_mapskill.erase(skillid);
}

SkillInfo* NFSkillPart::GetSkillData(uint64_t skillid)
{
    return nullptr;
}

int32_t NFSkillPart::LeftCd(uint64_t curmsc, uint32_t cd, const SkillInfo* pinfo)
{
    return 0;
}

void NFSkillPart::SetSkillProto(const SkillInfo* pinfo, proto_ff::SkillInfoProto& proto)
{
    if (nullptr == pinfo) { return; }
    proto.set_skill_id(pinfo->skill_id);
    proto.set_level(pinfo->level);
    proto.set_wakeup(pinfo->wakeup);
}

void NFSkillPart::SetAllSkillProto(proto_ff::SkillInfoListProto& proto)
{
    for (auto& iter : m_mapskill)
    {
        proto_ff::SkillInfoProto* protoinfo = proto.add_lst();
        if (nullptr == protoinfo) { continue; }
        SetSkillProto(&iter.second, *protoinfo);
    }
}

void NFSkillPart::SetAdvanceListProto(proto_ff::SkillAdvanceListProto& proto)
{
    proto.set_curpos(CurAdvpos());
    for (uint8_t i = 1; i <= MAX_ROLE_SKILL_ADVANCE_POS; ++i)
    {
        SkillAdvPosInfo* pinfo = GetAdvPosInfo(i);
        if (nullptr != pinfo)
        {
            proto_ff::SkillAdvancePosProto* protopos = proto.add_pos_lst();
            if (nullptr != protopos)
            {
                protopos->set_pos(i);
                protopos->set_advance(pinfo->advance);
                protopos->set_unlock(pinfo->unlock);
            }
        }
    }
    for (uint8_t i = (uint8_t)ESkillAdvance::none + 1; i < (uint8_t)ESkillAdvance::limit; ++i)
    {
        uint8_t lev = GetAdvLev(i);
        if (lev > 0)
        {
            proto_ff::SkillAdvanceProto* protoadv = proto.add_lst();
            if (nullptr != protoadv)
            {
                protoadv->set_advance(i);
                protoadv->set_level(lev);
            }
        }
    }
}

SkillGroup* NFSkillPart::GetSkillGroup(uint32_t groupid)
{
    auto iter = m_mapGroup.find(groupid);
    return (iter != m_mapGroup.end()) ? &iter->second : nullptr;
}

void NFSkillPart::AddSkillGroup(SkillGroup& info)
{
    m_mapGroup[info.group] = info;
}

void NFSkillPart::DelSkillGroup(uint32_t groupid)
{
    m_mapGroup.erase(groupid);
}

bool NFSkillPart::IsDySkill(int64_t skillid)
{
    for (auto &iter : m_mapGroup)
    {
        if(iter.first < DY_MIN_SKILL_ID) continue;
        for (uint32_t i = 0; i < MAX_ROLE_SKILL_POS; ++i)
        {
            if (skillid == (int64_t)iter.second.pos[i]) return true;
        }
    }
    return false;
}

void NFSkillPart::SetSkillGroupProto(SkillGroup* pgroup, proto_ff::SkillGroupProto& proto)
{
    if (nullptr == pgroup)return;
    uint64_t curmsec = NFTime::Now().UnixMSec();
    proto.set_group(pgroup->group);
    for (uint32_t i = 0; i < MAX_ROLE_SKILL_POS; ++i)
    {
        if (pgroup->pos[i] > 0)
        {
            proto_ff::SkillPosProto *protopos = proto.add_lst();
            if (nullptr != protopos)
            {
                protopos->set_pos(i);
                protopos->set_skill_id(pgroup->pos[i]);
                protopos->set_use(pgroup->autouse[i]);
                protopos->set_cd(0);
                const SkillCfg* pcfg = SkillDescEx::Instance()->GetCfg(pgroup->pos[i]);
                if (nullptr == pcfg) continue;
                auto pCfgCfg = pcfg->GetCfg();
                if (nullptr == pCfgCfg) continue;
                if (SkillDescEx::Instance()->IsSpiritSkill(pcfg))
                {
                    protopos->set_cd(SoulLeftCd(pgroup->pos[i], pCfgCfg->m_cd, curmsec));
                    //LogDebugFmtPrint("[logic] SkillPart::SetSkillGroupProto....cid:%lu, skillid:%lu, cd:%d",m_pMaster->Cid(), pgroup->pos[i], protopos->cd());
                }
                else
                {
                    SkillInfo* pinfo = GetSkillData(pgroup->pos[i]);
                    if (nullptr != pinfo) protopos->set_cd(LeftCd(curmsec, pCfgCfg->m_cd, pinfo));
                }
            }
        }
    }
}

void NFSkillPart::SetAllSkillGroupProto(proto_ff::SkillGroupListProto& proto)
{
    proto.set_cur_skill_group(m_group);
    for (auto &iter: m_mapGroup)
    {
        proto_ff::SkillGroupProto* protoinfo = proto.add_info();
        if (nullptr != protoinfo)  SetSkillGroupProto(&iter.second, *protoinfo);
    }
}

int32_t NFSkillPart::SkillUpgrade(const SkillCfg* pcfg, SkillInfo* pinfo, bool sync)
{
    return 0;
}

void NFSkillPart::CalcSkillFight()
{
    for (auto &iter : m_mapskill)
    {
        if (iter.second.level <= 0) continue;
        const SkillCfg* pcfg = SkillDescEx::Instance()->GetCfg(iter.first);
        m_fight += SkillDescEx::Instance()->GetSkillFight(pcfg, iter.second.level);
    }
}

void NFSkillPart::OnSkillUpgrade(const SkillCfg* pcfg, SkillInfo* pinfo, int32_t oldlev)
{
}

void NFSkillPart::OnAddSkill(const SkillCfg* pcfg, int32_t level)
{
    if (level <= 0) { return; }
    if (nullptr == pcfg) { return; }
    int64_t val = SkillDescEx::Instance()->GetSkillFight(pcfg, level);
    if (val <= 0) { return; }
    m_fight += val;
    m_pMaster->SetCalcFight(true);
}

void NFSkillPart::OnRemoveSkill(const SkillCfg* pcfg, int32_t level)
{
    if (nullptr == pcfg) { return; }
    int64_t val = SkillDescEx::Instance()->GetSkillFight(pcfg, level);
    if (val <= 0) { return; }
    m_fight -= val;
    if (m_fight < 0) { m_fight = 0; }
    m_pMaster->SetCalcFight(true);
}

void NFSkillPart::OnAddSkillGroup(const SkillCfg* pcfg, bool sync)
{
    if (nullptr == pcfg) { return; }
    auto pCfgCfg = pcfg->GetCfg();
    if (nullptr == pCfgCfg) { return; }
    uint64_t skillid = (uint64_t)pCfgCfg->m_skillID;
    //技能组
    if ((SkillDescEx::Instance()->IsRoleSkill(pcfg) && SkillDescEx::Instance()->ValidRoleSkillPos(pCfgCfg->m_position))
        || (SkillDescEx::Instance()->IsSpiritSkill(pcfg) && SkillDescEx::Instance()->ValidSpiritSkillPos(pCfgCfg->m_position))
        || (SkillDescEx::Instance()->IsPetSkill(pcfg) && SkillDescEx::Instance()->ValidPetSkillPos(pCfgCfg->m_position))
        || (SkillDescEx::Instance()->IsAngerSkill(pcfg) && SkillDescEx::Instance()->ValidAngerSkillPos(pCfgCfg->m_position))
        )
    {
        uint32_t maxpos = MAX_ROLE_SKILL_POS;
        if (SkillDescEx::Instance()->IsPetSkill(pcfg)) { maxpos = MAX_PET_SKILL_POS; }
        else if (SkillDescEx::Instance()->IsSpiritSkill(pcfg)) { maxpos = MAX_SPIRIT_SKILL_POS; }
        else if (SkillDescEx::Instance()->IsAngerSkill(pcfg)) { maxpos = MAX_ANGER_SKILL_POS; }
        //
        uint32_t groupid = pCfgCfg->m_group;
        if (SkillDescEx::Instance()->IsRoleSkill(pcfg))
        {
            groupid = SkillDescEx::Instance()->GetProfSkillGroupId(m_pMaster->GetAttr(proto_ff::A_PROF));
        }
        SkillGroup* pgroup = GetSkillGroup(groupid);
        if (nullptr != pgroup)
        {
            bool findflag = false;
            for (uint32_t n = 0; n < maxpos; ++n)
            {
                if (skillid == pgroup->pos[n])
                {
                    findflag = true;
                    break;
                }
            }
            if (findflag)
            {
                return;
            }
            
            if (pgroup->pos[pCfgCfg->m_position] > 0)
            {
                bool posflag = false;
                string strlog;
                uint32_t n = 0;
                if (SkillDescEx::Instance()->IsPetSkill(pcfg)
                    || SkillDescEx::Instance()->IsSpiritSkill(pcfg)
                    || SkillDescEx::Instance()->IsAngerSkill(pcfg)
                    )
                {
                    n = 1; //这些技能位置从1开始
                }
                for (; n < maxpos; ++n)
                {
                    if (pgroup->pos[n] <= 0)
                    {
                        pgroup->pos[n] = skillid;
                        if (SkillDescEx::Instance()->IsSoulSacrifice(skillid)) { pgroup->autouse[n] = 0; }
                        else { pgroup->autouse[n] = 1; }
                        posflag = true;
                        SetNeedSave(true);
                        break;
                    }
                    strlog += std::to_string(pgroup->pos[n]);
                    strlog += ",";
                }
                if (!posflag)
                {
                    //找不到合适的位置
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] SkillPart::OnAddSkillGroup....can not find skill postion...cid:%lu,skillid:%lu,groupid:%u,prof:%ld,maxpos:%d,pos:%s", m_pMaster->Cid(), skillid, groupid, m_pMaster->GetAttr(proto_ff::A_PROF), maxpos, strlog.c_str());
                }
            }
            else
            {
                pgroup->pos[pCfgCfg->m_position] = skillid;
                if (SkillDescEx::Instance()->IsSoulSacrifice(skillid)) { pgroup->autouse[pCfgCfg->m_position] = 0; }
                else { pgroup->autouse[pCfgCfg->m_position] = 1; }
                SetNeedSave(true);
            }
        }
        else
        {
            SkillGroup sg;
            sg.group = groupid;
            sg.pos[pCfgCfg->m_position] = skillid;
            if (SkillDescEx::Instance()->IsSoulSacrifice(skillid)) { sg.autouse[pCfgCfg->m_position] = 0; }
            else { sg.autouse[pCfgCfg->m_position] = 1; }
            AddSkillGroup(sg);
            SetNeedSave(true);
        }
        //
        if (sync)
        {
            OnUpdateSkillGroup();
        }
    }
}

void NFSkillPart::OnRemoveSkillGroup(const SkillCfg* pcfg, bool sync)
{
}

int NFSkillPart::OnUseSkill(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFSkillPart::OnSyncTarget(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFSkillPart::OnCancelUse(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFSkillPart::OnBreakSkill(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFSkillPart::OnDetail(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::SkillInfoRsp rsp;
    proto_ff::SkillInfoListProto* proto = rsp.mutable_info();
    if (nullptr != proto)
    {
        SetAllSkillProto(*proto);
    }
    proto_ff::SkillAdvanceListProto* protoadv = rsp.mutable_advance_info();
    if (nullptr != protoadv)
    {
        SetAdvanceListProto(*protoadv);
    }
    m_pMaster->SendMsgToClient(proto_ff::SKILL_INFO_RSP, rsp);
    return 0;
}

int NFSkillPart::OnWakeup(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFSkillPart::OnChgPos(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFSkillPart::OnUpgrade(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFSkillPart::OnSetAutoUse(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFSkillPart::OnAdvance(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFSkillPart::OnAdvanceChgPos(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFSkillPart::OnAdvanceReset(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFSkillPart::OnAdvanceUnlockpos(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

void NFSkillPart::OnShrinkSkillGroup(uint32_t groupid, bool sync)
{
}

bool NFSkillPart::OnAddPassiveSkill(const SkillCfg* pcfg, int32_t level, const SCommonSource& src, bool sync)
{
    return true;
}

PetSkillCd* NFSkillPart::GetPetSkillCd(uint64_t skillid)
{
    return nullptr;
}

void NFSkillPart::AddPetSkillCd(uint64_t skillid, PetSkillCd& cd)
{
}

void NFSkillPart::DelPetSkillCd(uint64_t skillid)
{
}

bool NFSkillPart::ValidUseSkillIndex(uint32_t index)
{
    return false;
}

uint32_t NFSkillPart::NewIndex()
{
    return 0;
}

SkillAdvPosInfo* NFSkillPart::GetAdvPosInfo(uint8_t pos)
{
    if (pos > 0 && pos <= MAX_ROLE_SKILL_ADVANCE_POS) { return &m_advpos[pos - 1]; }
    return nullptr;
}

uint8_t NFSkillPart::GetAdvLockPos()
{
    for (uint8_t i = 1; i <= MAX_ROLE_SKILL_ADVANCE_POS; ++i)
    {
        SkillAdvPosInfo* pinfo = GetAdvPosInfo(i);
        if (nullptr == pinfo) continue;
        if(pinfo->unlock) continue;
        return i;
    }
    return 0;
}

uint8_t NFSkillPart::GetNoAdvPos()
{
    for (uint8_t i = 1; i <= MAX_ROLE_SKILL_ADVANCE_POS; ++i)
    {
        SkillAdvPosInfo* pinfo = GetAdvPosInfo(i);
        if (nullptr == pinfo) continue;
        if (pinfo->advance > 0) continue;
        return i;
    }
    return 0;
}

bool NFSkillPart::IsAdvposUnlock(uint8_t pos)
{
    SkillAdvPosInfo* pinfo = GetAdvPosInfo(pos);
    return (nullptr != pinfo) ? pinfo->unlock : false;
}

void NFSkillPart::UnlockAdvpos(uint8_t pos)
{
    SkillAdvPosInfo* pinfo = GetAdvPosInfo(pos);
    if (nullptr != pinfo) pinfo->unlock = 1;
}

void NFSkillPart::SetAdvPosInfo(uint8_t pos, uint8_t advtype)
{
    SkillAdvPosInfo* pinfo = GetAdvPosInfo(pos);
    if (nullptr != pinfo) pinfo->advance = advtype;
}

uint8_t NFSkillPart::GetAdvLev(uint8_t advtype)
{
    if (advtype > (uint8_t)ESkillAdvance::none && advtype < (uint8_t)ESkillAdvance::limit) { return m_advlev[advtype]; }
    return 0;
}

void NFSkillPart::SetAdvLev(uint8_t advtype, uint8_t advlev)
{
    if (advtype > (uint8_t)ESkillAdvance::none && advtype < (uint8_t)ESkillAdvance::limit)
    {
        m_advlev[advtype] = advlev;
    }
}

bool NFSkillPart::OnAdvanceBuff(uint8_t advance, uint8_t advancelev, bool rmvflag)
{
    return false;
}

NFSkillPart::TalentInfo* NFSkillPart::GetTalentInfo(int32_t id)
{
    return nullptr;
}

void NFSkillPart::AddTalentInfo(NFSkillPart::TalentInfo& info)
{
}

void NFSkillPart::DelTalentInfo(int32_t id)
{
}

void NFSkillPart::ClearTalentInfo()
{
}

void NFSkillPart::OnTalentCntNotify()
{
}

bool NFSkillPart::IsAngerFull()
{
    return false;
}

int NFSkillPart::OnLogin(proto_ff::PlayerInfoRsp& playerInfo)
{
    auto pskillList = SkillDescEx::Instance()->GetProfSkillList(m_pMaster->GetAttr(proto_ff::A_PROF));
    if (nullptr != pskillList)
    {
        for (auto& iter : *pskillList)
        {
            const SkillCfg* pcfg = SkillDescEx::Instance()->GetCfg(iter);
            if (nullptr == pcfg)
            {
                continue;
            }
            auto pCfgCfg = pcfg->GetCfg();
            if (nullptr == pCfgCfg)
            {
                continue;
            }
            if (!CanOpen(pcfg))
            {
                continue;
            }
            if (nullptr != GetSkillData(iter))
            {
                continue;
            }
            SCommonSource src;
            src.src = S_SkillInit;
            if (!AddSkill(pcfg,1,src))
            {
                NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] SkillPart::OnLogin....AddSkill failed...cid:%lu, skillid:%lu ",m_pMaster->Cid(),iter);
                continue;
            }
            NFLogDebugFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] SkillPart::OnLogin....cid:%lu, skillid:%lu, pos:%d,group:%d, cur_group:%u ", m_pMaster->Cid(), iter, pCfgCfg->m_position, pCfgCfg->m_group, m_group);
        }
    }
    //检查动态加的技能组
/*    SET_UINT32 setgroup;
    SET_UINT32 setdelgroup;
    NFBuffPart* pbuff = dynamic_cast<NFBuffPart*>(m_pMaster->GetPart(PART_BUFF));
    if (nullptr != pbuff) pbuff->GetSkillGroupList(setgroup);
    for (auto &iterg : m_mapGroup)
    {
        const SkillSkillgroupCfgInfo* pcfg = g_GetSkillSkillgroupCfgTable()->GetSkillSkillgroupCfgInfo(iterg.first);
        if (nullptr == pcfg) continue;
        auto iterf = setgroup.find(iterg.first);
        if (iterf == setgroup.end())
        {
            setdelgroup.insert(iterg.first);
        }
    }
    for (auto &iterdel : setdelgroup)
    {
        RmvSkillGroup(iterdel,false);
    }*/
    
    //
    proto_ff::SkillGroupListProto *protolst = playerInfo.mutable_skill_group();
    if (nullptr != protolst)
    {
        SetAllSkillGroupProto(*protolst);
    }
    playerInfo.set_anger_value(m_anger);
    return 0;
}

bool NFSkillPart::CanOpen(uint64_t skillid)
{
    const SkillCfg* pcfg = SkillDescEx::Instance()->GetCfg(skillid);
    return CanOpen(pcfg);
}

bool NFSkillPart::CanOpen(const SkillCfg* pcfg)
{
    int32_t type = 0;
    int64_t value = 0;
    int64_t value2 = 0;
    SkillDescEx::Instance()->GetSkillUnlockParam(pcfg,type, value, value2);
    if ((int32_t)ESkillUnlock::level == type)
    {
        return (m_pMaster->GetAttr(proto_ff::A_LEVEL) >= value);
    }
    else if ((int32_t)ESkillUnlock::trans == type)
    {
        NFOccupationPart* poccupa = dynamic_cast<NFOccupationPart*>(m_pMaster->GetPart(PART_OCCUPATION));
        if (nullptr != poccupa)
        {
            return (poccupa->GetCurGrade() >= value);
        }
    }
    else if ((int32_t)ESkillUnlock::task == type)
    {
        NFMissionPart* pMission = dynamic_cast<NFMissionPart*>(m_pMaster->GetPart(PART_MISSION));
        if (nullptr != pMission)
        {
            return pMission->HaveSubmited(value);
        }
    }
    else if ((int32_t)ESkillUnlock::advance == type)
    {
        int32_t advance_type = 0;
        int32_t advance_value = 0;
        AdvanceInfo(advance_type,advance_value);
        return ((int32_t)value == advance_type && advance_value >= (int32_t)value2);
    }
    return true;
}

//战魂技能剩余CD
int64_t NFSkillPart::SoulLeftCd(uint64_t skillid,int32_t cd, int64_t cur_msec)
{
    if (cd <= 0) return 0;
    auto pinfo = GetSoulSkillInfo(skillid);
    if (nullptr == pinfo) return 0;
    if ((int64_t)pinfo->use_msc + cd > cur_msec)
    {
        return (pinfo->use_msc + cd - cur_msec);
    }
    return 0;
}

//获取战魂技能信息
SkillInfo* NFSkillPart::GetSoulSkillInfo(uint64_t skillid)
{
    auto iter = m_mapSoulSkill.find(skillid);
    return (iter != m_mapSoulSkill.end()) ? &iter->second : nullptr;
}