// -------------------------------------------------------------------------
//    @FileName         :    NFSkillPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFSkillPart
//
// -------------------------------------------------------------------------

#include "NFSkillPart.h"

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

int NFSkillPart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFSkillPart::UnInit()
{
    return NFPart::UnInit();
}

int NFSkillPart::LoadFromDB(const proto_ff::RoleDBData &data)
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
            const proto_ff::SkillDBInfo&proto = dbdata.info_lst(i);
            SkillInfo info;
            info.skill_id = proto.skill_id();
            info.level = proto.level();
            info.wakeup = proto.wakeup();
            info.use_msc = proto.use_msc();
            if (info.use_msc > curmsec) info.use_msc = curmsec;
            AddSkillInfo(info);
        }
        uint32_t ngroupsize = dbdata.group_lst_size();
        for (uint32_t n = 0; n < ngroupsize; ++n)
        {
            const proto_ff::SkillDBGroup &proto = dbdata.group_lst(n);
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
            const proto_ff::SkillDBAdvPos &protopos = dbdata.adv_pos(i);
            SkillAdvPosInfo *pinfo = GetAdvPosInfo(protopos.pos());
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
            if (cd.usemsec > curmsec) cd.usemsec = curmsec;
            m_mapPetSkillCd[protocd.skill_id()] = cd;
        }
        if (dbdata.has_talent())
        {
            const proto_ff::SkillDBTalent &prototalent = dbdata.talent();
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

int NFSkillPart::InitConfig(const proto_ff::RoleDBData &data)
{
    return NFPart::InitConfig(data);
}

int NFSkillPart::SaveDB(proto_ff::RoleDBData &dbData)
{
    proto_ff::SkillDBData *protoskill = dbData.mutable_skill();
    protoskill->set_group(m_group);
    protoskill->set_last_group(m_lastgroup);
    protoskill->set_anger_value(m_anger);
    for (auto &iterinfo : m_mapskill)
    {
        proto_ff::SkillDBInfo *protoinfo = protoskill->add_info_lst();
        if (nullptr != protoinfo)
        {
            protoinfo->set_skill_id(iterinfo.second.skill_id);
            protoinfo->set_level(iterinfo.second.level);
            protoinfo->set_wakeup(iterinfo.second.wakeup);
            protoinfo->set_use_msc(iterinfo.second.use_msc);
        }
    }
    for (auto &iterg : m_mapGroup)
    {
        proto_ff::SkillDBGroup*protogroup = protoskill->add_group_lst();
        if (nullptr != protogroup)
        {
            protogroup->set_group(iterg.second.group);
            for (uint32_t i = 0; i < MAX_ROLE_SKILL_POS; ++i)
            {
                if (iterg.second.pos[i] <= 0) continue;
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
            proto_ff::SkillDBAdvPos *protopos =  protoskill->add_adv_pos();
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
            proto_ff::SkillDBAdvInfo *protoinfo = protoskill->add_adv_info();
            if (nullptr != protoinfo)
            {
                protoinfo->set_advance(i);
                protoinfo->set_level(lev);
            }
        }
    }
    for (auto &itercd : m_mapPetSkillCd)
    {
        proto_ff::PetSkillCdDB *protocd = protoskill->add_pet_cd();
        if (nullptr != protocd)
        {
            protocd->set_skill_id(itercd.first);
            protocd->set_pet_instid(itercd.second.petInstid);
            protocd->set_use_msec(itercd.second.usemsec);
        }
    }
    proto_ff::SkillDBTalent *prototalent = protoskill->mutable_talent();
    if (nullptr != prototalent)
    {
        prototalent->set_cnt(m_talentcnt);
        for (auto &iter : m_talent)
        {
            proto_ff::SkillDBTalentProto *protoinfo = prototalent->add_info();
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

int NFSkillPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch(msgId)
    {
        case proto_ff::SKILL_INFO_REQ:
        {
            OnDetail(msgId, packet);
            break;
        }
        default:
            break;
    }
    return 0;
}

int NFSkillPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

bool NFSkillPart::AddSkill(uint64_t skillid, int32_t level, const SCommonSource &src, bool sync, uint64_t use_msec)
{
    return false;
}

bool NFSkillPart::AddSkill(const SkillCfg *pcfg, int32_t level, const SCommonSource &src, bool sync, uint64_t use_msec)
{
    return false;
}

bool NFSkillPart::RemoveSkill(uint64_t skillid, const SCommonSource &src, bool sync)
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

bool NFSkillPart::CreatureRemoveSkill(const SkillCfg *pcfg, bool sync)
{
    return false;
}

bool NFSkillPart::CreatureRemoveSingleSkill(uint64_t skillid, bool sync)
{
    return false;
}

bool NFSkillPart::CreatureRemoveSingleSkill(const SkillCfg *pcfg, bool sync)
{
    return false;
}

void NFSkillPart::ResetSkillCd()
{
}

bool NFSkillPart::OnSkillUpgrade(uint64_t skillid, int32_t level, SCommonSource &src)
{
    return false;
}

void NFSkillPart::AdvanceInfo(int32_t &advancetype, int32_t &advancelev)
{
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

const SkillInfo *NFSkillPart::GetSkillInfo(uint64_t skillid)
{
    return nullptr;
}

void NFSkillPart::OnUpdateAdvance()
{
}

void NFSkillPart::OnUpdateSkillGroup()
{
}

int NFSkillPart::OnTalentInfo(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

int NFSkillPart::OnTalentUsePoint(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

int NFSkillPart::OnTalentReset(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

void NFSkillPart::OnAngerUpdateRsp()
{
}

void NFSkillPart::AddSkillInfo(const SkillInfo &info)
{
}

void NFSkillPart::DelSkillInfo(uint64_t skillid)
{
}

SkillInfo *NFSkillPart::GetSkillData(uint64_t skillid)
{
    return nullptr;
}

int32_t NFSkillPart::LeftCd(uint64_t curmsc, uint32_t cd, const SkillInfo *pinfo)
{
    return 0;
}

void NFSkillPart::SetSkillProto(const SkillInfo *pinfo, proto_ff::SkillInfoProto &proto)
{
    if (nullptr == pinfo) return;
    proto.set_skill_id(pinfo->skill_id);
    proto.set_level(pinfo->level);
    proto.set_wakeup(pinfo->wakeup);
}

void NFSkillPart::SetAllSkillProto(proto_ff::SkillInfoListProto &proto)
{
    for (auto &iter : m_mapskill)
    {
        proto_ff::SkillInfoProto *protoinfo =  proto.add_lst();
        if (nullptr == protoinfo) continue;
        SetSkillProto(&iter.second,*protoinfo);
    }
}

void NFSkillPart::SetAdvanceListProto(proto_ff::SkillAdvanceListProto &proto)
{
    proto.set_curpos(CurAdvpos());
    for (uint8_t i = 1; i <= MAX_ROLE_SKILL_ADVANCE_POS; ++i)
    {
        SkillAdvPosInfo *pinfo = GetAdvPosInfo(i);
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

SkillGroup *NFSkillPart::GetSkillGroup(uint32_t groupid)
{
    return nullptr;
}

void NFSkillPart::AddSkillGroup(SkillGroup &info)
{
}

void NFSkillPart::DelSkillGroup(uint32_t groupid)
{
}

bool NFSkillPart::IsDySkill(int64_t skillid)
{
    return false;
}

void NFSkillPart::SetSkillGroupProto(SkillGroup *pgroup, proto_ff::SkillGroupProto &proto)
{
}

void NFSkillPart::SetAllSkillGroupProto(proto_ff::SkillGroupListProto &proto)
{
}

int32_t NFSkillPart::SkillUpgrade(const SkillCfg *pcfg, SkillInfo *pinfo, bool sync)
{
    return 0;
}

void NFSkillPart::CalcSkillFight()
{
}

void NFSkillPart::OnSkillUpgrade(const SkillCfg *pcfg, SkillInfo *pinfo, int32_t oldlev)
{
}

void NFSkillPart::OnAddSkill(const SkillCfg *pcfg, int32_t level)
{
}

void NFSkillPart::OnRemoveSkill(const SkillCfg *pcfg, int32_t level)
{
}

void NFSkillPart::OnAddSkillGroup(const SkillCfg *pcfg, bool sync)
{
}

void NFSkillPart::OnRemoveSkillGroup(const SkillCfg *pcfg, bool sync)
{
}

int NFSkillPart::OnUseSkill(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

int NFSkillPart::OnSyncTarget(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

int NFSkillPart::OnCancelUse(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

int NFSkillPart::OnBreakSkill(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

int NFSkillPart::OnDetail(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::SkillInfoRsp rsp;
    proto_ff::SkillInfoListProto*proto =  rsp.mutable_info();
    if (nullptr != proto)
    {
        SetAllSkillProto(*proto);
    }
    proto_ff::SkillAdvanceListProto *protoadv = rsp.mutable_advance_info();
    if (nullptr != protoadv)
    {
        SetAdvanceListProto(*protoadv);
    }
    m_pMaster->SendMsgToClient(proto_ff::SKILL_INFO_RSP, rsp);
    return 0;
}

int NFSkillPart::OnWakeup(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

int NFSkillPart::OnChgPos(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

int NFSkillPart::OnUpgrade(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

int NFSkillPart::OnSetAutoUse(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

int NFSkillPart::OnAdvance(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

int NFSkillPart::OnAdvanceChgPos(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

int NFSkillPart::OnAdvanceReset(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

int NFSkillPart::OnAdvanceUnlockpos(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

void NFSkillPart::OnShrinkSkillGroup(uint32_t groupid, bool sync)
{
}

bool NFSkillPart::OnAddPassiveSkill(string strpre, const SkillCfg *pcfg, int32_t level, const SCommonSource &src, bool sync)
{
    return false;
}

PetSkillCd *NFSkillPart::GetPetSkillCd(uint64_t skillid)
{
    return nullptr;
}

void NFSkillPart::AddPetSkillCd(uint64_t skillid, PetSkillCd &cd)
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

SkillAdvPosInfo *NFSkillPart::GetAdvPosInfo(uint8_t pos)
{
    if (pos > 0 && pos <= MAX_ROLE_SKILL_ADVANCE_POS) return &m_advpos[pos - 1];
    return nullptr;
}

uint8_t NFSkillPart::GetAdvLockPos()
{
    return 0;
}

uint8_t NFSkillPart::GetNoAdvPos()
{
    return 0;
}

bool NFSkillPart::IsAdvposUnlock(uint8_t pos)
{
    return false;
}

void NFSkillPart::UnlockAdvpos(uint8_t pos)
{
}

void NFSkillPart::SetAdvPosInfo(uint8_t pos, uint8_t advtype)
{
}

uint8_t NFSkillPart::GetAdvLev(uint8_t advtype)
{
    if (advtype > (uint8_t)ESkillAdvance::none && advtype < (uint8_t)ESkillAdvance::limit) return m_advlev[advtype];
    return 0;
}

void NFSkillPart::SetAdvLev(uint8_t advtype, uint8_t advlev)
{
}

bool NFSkillPart::OnAdvanceBuff(uint8_t advance, uint8_t advancelev, bool rmvflag)
{
    return false;
}

NFSkillPart::TalentInfo *NFSkillPart::GetTalentInfo(int32_t id)
{
    return nullptr;
}

void NFSkillPart::AddTalentInfo(NFSkillPart::TalentInfo &info)
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
