// -------------------------------------------------------------------------
//    @FileName         :    NFBattlePlayer.cpp
//    @Author           :    gaoyi
//    @Date             :    23-2-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFBattlePlayer
//
// -------------------------------------------------------------------------

#include "NFBattlePlayer.h"
#include "NFLogicCommon/NFAttrMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFBattlePlayer, EOT_GAME_NFBattlePlayer_ID, NFCreature)

NFBattlePlayer::NFBattlePlayer()
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

NFBattlePlayer::~NFBattlePlayer()
{
}

int NFBattlePlayer::CreateInit()
{
    m_kind = CREATURE_PLAYER;
    m_isInited = false;
    m_uid = 0;
    m_roleId = 0;
    m_channId = 0;
    m_zid = 0;
    m_gateId = 0;
    m_logicId = 0;
    m_headFlag = 0;
    return 0;
}

int NFBattlePlayer::ResumeInit()
{
    return 0;
}

int NFBattlePlayer::Init(uint32_t gateId, uint32_t logicId, const proto_ff::RoleEnterSceneData& dbData)
{
    m_isInited = true;
    m_pFightAttr = NFAttrMgr::Instance(m_pObjPluginManager)->MakeFightAttrObj(EAttrType::role);
    m_pAttr = NFAttrMgr::Instance(m_pObjPluginManager)->MakeAttrObj(EAttrType::role);
    ReadBaseData(dbData.base());
    m_roleId = dbData.cid();
    m_zid = dbData.zid();
    m_uid = dbData.uid();
    m_gateId = gateId;
    m_logicId = logicId;
    ResetCurSeq();
    return 0;
}

int NFBattlePlayer::ReadBaseData(const ::proto_ff::RoleDBBaseData &dbData)
{
    m_name = dbData.name();
    m_pAttr->SetAttr(proto_ff::A_PROF, dbData.prof());
    m_pAttr->SetAttr(proto_ff::A_LEVEL, dbData.level());
    m_pAttr->SetAttr(proto_ff::A_EXP, dbData.exp());
    m_pAttr->SetAttr(proto_ff::A_CUR_HP, dbData.hp());
    m_pAttr->SetAttr(proto_ff::A_FIGHT, dbData.fight());
    m_pAttr->SetAttr(proto_ff::A_VIP_LEVEL, dbData.vip_level());
    m_pAttr->SetAttr(proto_ff::A_HANGUP_TIME, dbData.hanguptime());
    //
    m_sceneId = dbData.enter_scene_id();
    m_mapId = dbData.enter_map_id();
    m_pos.x = dbData.enterposx();
    m_pos.y = dbData.enterposy();
    m_pos.z = dbData.enterposz();

    m_facade.read_from_pbmsg(dbData.facade());
    return 0;
}

//视野数据
void NFBattlePlayer::GetVisibleDataToClient(proto_ff::CreatureCreateData& cvData)
{
    proto_ff::CreatureCreateData::Player *pPlayerVinfo = cvData.add_players();
    if (nullptr == pPlayerVinfo)
    {
        return;
    }

    pPlayerVinfo->set_cid(m_cid);
    pPlayerVinfo->set_name(m_name.ToString());
    proto_ff::Vector3PB* protopos = pPlayerVinfo->mutable_pos();
    if (nullptr != protopos)
    {
        protopos->set_x(m_pos.x);
        protopos->set_y(m_pos.y);
        protopos->set_z(m_pos.z);
    }
    pPlayerVinfo->set_curstate(GetState());
    pPlayerVinfo->set_zid(GetZid());
    pPlayerVinfo->set_titlename("");
    //pPlayerVinfo->set_head(HeadFlag());
    //pPlayerVinfo->set_faction_name(FactionName());
    auto &setAttr = NFAttrMgr::Instance(m_pObjPluginManager)->PlayerViewAttr();
    for (auto iter = setAttr.begin(); iter != setAttr.end(); ++iter)
    {
        uint32_t attrid = (*iter);
        proto_ff::Attr64 *pAttr = pPlayerVinfo->add_attr();
        if (nullptr != pAttr)
        {
            pAttr->set_id(attrid);
            pAttr->set_value(GetAttr(attrid));
        }
    }
    //外观
    proto_ff::RoleFacadeProto *protofacade = pPlayerVinfo->mutable_facade();
    if (nullptr != protofacade)
    {
        m_facade.write_to_pbmsg(*protofacade);
    }

    //buff列表
/*    BuffPart * pBuffPart = dynamic_cast<BuffPart*>(m_pPart[PART_BUFF]);
    if (pBuffPart)
    {
        BuffListProto *protolst = pPlayerVinfo->mutable_bufflst();
        if (nullptr != protolst)
        {
            pBuffPart->SetViewBuffListProto(*protolst);
        }
    }*/
}

bool NFBattlePlayer::TransScene(uint64_t scenceId, const NFPoint3<float> &dstPos, uint64_t mapId, STransParam &transParam)
{

    return true;
}