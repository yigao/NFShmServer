// -------------------------------------------------------------------------
//    @FileName         :    NFBattlePlayer.cpp
//    @Author           :    gaoyi
//    @Date             :    23-2-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFBattlePlayer
//
// -------------------------------------------------------------------------

#include "NFBattlePlayer.h"
#include "Part/NFBattleMovePart.h"
#include "Map/NFMapMgr.h"
#include "Map/NFMap.h"
#include "DescStore/MapMapDesc.h"
#include "NFLogicCommon/NFEventDefine.h"
#include "NFLogicCommon/NFEventDefine2.h"
#include "NFComm/NFCore/NFTime.h"
#include "ClientServerCmd.pb.h"
#include "NFLogicCommon/Attr/NFAttrMgr.h"
#include "DescStoreEx/MapDescEx.h"
#include "NFLogicCommon/NFActivityDefine.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "Scene/NFSceneMgr.h"
#include "proto_svr_event.pb.h"

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
    m_lastDiconnectTime = 0;
    m_lastLogoutTime = 0;
    m_isDisconnect = false;
    
    m_kind = CREATURE_PLAYER;
    m_uid = 0;
    m_cid = 0;
    m_channId = 0;
    m_zid = 0;
    m_proxyId = 0;
    m_logicId = 0;
    m_headFlag = 0;
    m_pPart.resize(m_pPart.max_size());
    
    m_timerId_FightState = INVALID_ID;
    return 0;
}

int NFBattlePlayer::ResumeInit()
{
    return 0;
}

int NFBattlePlayer::Init()
{
    m_pFightAttr = NFAttrMgr::Instance(m_pObjPluginManager)->MakeFightAttrObj(EAttrType::role);
    m_pAttr = NFAttrMgr::Instance(m_pObjPluginManager)->MakeAttrObj(EAttrType::role);
    return 0;
}

int NFBattlePlayer::Init(const proto_ff::RoleEnterSceneData& data)
{
    m_cid = data.cid();
    m_zid = data.zid();
    m_uid = data.uid();
    
    ReadBaseData(data.base());
    ReadViewAttrData(data.attr());
    
    NFCreature::Init();
    ResetCurSeq();
    
    for (uint32_t i = BATTLE_PART_NONE + 1; i < BATTLE_PART_MAX; ++i)
    {
        NFBattlePart* pPart = CreatePart(i, data);
        if (nullptr == pPart)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_cid, "Player Init, Create Part Failed, roleId:{} uid:{} part:{}", m_cid, m_uid, i);
            return -1;
        }
        
        m_pPart[i] = pPart->GetGlobalId();
    }
    
    SetState(proto_ff::state_normal);
    
    Subscribe(NF_ST_GAME_SERVER, EVENT_SYNC_SCENE_FACADE, CREATURE_PLAYER, Cid(), __FUNCTION__);
    Subscribe(NF_ST_GAME_SERVER, EVENT_SYNC_CREATURE_ATTR, CREATURE_PLAYER, Cid(), __FUNCTION__);
    Subscribe(NF_ST_GAME_SERVER, EVENT_SYNC_CREATURE_BROADCAST_ATTR, CREATURE_PLAYER, Cid(), __FUNCTION__);
    
    return 0;
}

int NFBattlePlayer::Init(uint32_t proxyId, uint32_t logicId, uint32_t worldId, uint32_t snsId, const proto_ff::RoleEnterSceneData& data)
{
    ReadBaseData(data.base());
    ReadViewAttrData(data.attr());
    
    m_proxyId = proxyId;
    m_logicId = logicId;
    for (uint32_t i = BATTLE_PART_NONE + 1; i < BATTLE_PART_MAX; ++i)
    {
        NFBattlePart* pPart = GetPart(i);
        if (nullptr == pPart)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_cid, "Player Init, Get Part Failed, roleId:{} uid:{} part:{}", m_cid, m_uid, i);
            return -1;
        }
        
        pPart->Init(data);
    }
    
    return 0;
}

NFBattlePart* NFBattlePlayer::CreatePart(uint32_t partType, const ::proto_ff::RoleEnterSceneData& data)
{
    NFBattlePart* pPart = dynamic_cast<NFBattlePart*>(FindModule<NFISharedMemModule>()->CreateObj(EOT_NFBattlePart_ID + partType));
    if (pPart)
    {
        pPart->InitBase(this, partType);
        int iRet = pPart->Init(data);
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "{}::Init Failed", pPart->GetClassName());
            FindModule<NFISharedMemModule>()->DestroyObj(pPart);
            return NULL;
        }
    }
    return pPart;
}

int NFBattlePlayer::RecylePart(NFBattlePart* pPart)
{
    CHECK_NULL(pPart);
    pPart->UnInit();
    FindModule<NFISharedMemModule>()->DestroyObj(pPart);
    return 0;
}

NFBattlePart* NFBattlePlayer::GetPart(uint32_t partType)
{
    if (partType <= 0 || partType >= m_pPart.size())
    {
        return nullptr;
    }
    
    return dynamic_cast<NFBattlePart*>(FindModule<NFISharedMemModule>()->GetObjByGlobalId(EOT_NFBattlePart_ID, m_pPart[partType], true));
}

int NFBattlePlayer::OnTimer(int timeId, int callcount)
{
    if (m_timerId_FightState == timeId)
    {
        LeaveFigthState();
    }
    
    return 0;
}

int NFBattlePlayer::SyncFacade(const proto_ff::RoleFacadeProto* pEvent)
{
    CHECK_NULL(pEvent);
    
    m_facade.read_from_pbmsg(*pEvent);
    
    //广播外观
    proto_ff::NotifyRoleFacadeCastRsp rsp;
    rsp.set_roleid(Cid());
    proto_ff::RoleFacadeProto* pProto = rsp.mutable_facade();
    m_facade.write_to_pbmsg(*pProto);
    BroadCast(proto_ff::NOTIFY_FACADE_CAST_RSP, rsp, true);
    
    return 0;
}

int NFBattlePlayer::SyncAttr(const proto_ff::CreatureAttrSyn* pEvent)
{
    CHECK_NULL(pEvent);
    for (int i = 0; i < (int)pEvent->attr_size(); i++)
    {
        const ::proto_ff::Attr64& attr = pEvent->attr(i);
        SetAttr(attr.id(), attr.value());
    }
    return 0;
}

int NFBattlePlayer::SyncBroadAttr(const proto_ff::CreatureAttrBroadRsp* pEvent)
{
    CHECK_NULL(pEvent);
    for (int i = 0; i < (int)pEvent->attr_size(); i++)
    {
        const ::proto_ff::Attr64& attr = pEvent->attr(i);
        SetAttr(attr.id(), attr.value());
    }
    
    BroadCast(proto_ff::CREATURE_ATTR_BROAD, *pEvent, true);
    return 0;
}

int NFBattlePlayer::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
{
    switch (nEventID)
    {
        case EVENT_SYNC_SCENE_FACADE:
        {
            const proto_ff::RoleFacadeProto* pEvent = dynamic_cast<const proto_ff::RoleFacadeProto*>(pMessage);
            if (pEvent)
            {
                SyncFacade(pEvent);
            }
            break;
        }
        case EVENT_SYNC_CREATURE_ATTR:
        {
            const proto_ff::CreatureAttrSyn* pEvent = dynamic_cast<const proto_ff::CreatureAttrSyn*>(pMessage);
            if (pEvent)
            {
                SyncAttr(pEvent);
            }
            break;
        }
        case EVENT_SYNC_CREATURE_BROADCAST_ATTR:
        {
            const proto_ff::CreatureAttrBroadRsp* pEvent = dynamic_cast<const proto_ff::CreatureAttrBroadRsp*>(pMessage);
            if (pEvent)
            {
                SyncBroadAttr(pEvent);
            }
            break;
        }
        default:
        {
            break;
        }
    }
    
    return 0;
}

int NFBattlePlayer::Update(uint64_t tick)
{
    NFCreature::Update(tick);
    Tick();
    return 0;
}

int NFBattlePlayer::ReadBaseData(const ::proto_ff::RoleDBBaseData& dbData)
{
    m_name = dbData.name();
    m_pAttr->SetAttr(proto_ff::A_PROF, dbData.prof());
    m_pAttr->SetAttr(proto_ff::A_LEVEL, dbData.level());
    m_pAttr->SetAttr(proto_ff::A_EXP, dbData.exp());
    m_pAttr->SetAttr(proto_ff::A_CUR_HP, dbData.hp());
    m_pAttr->SetAttr(proto_ff::A_FIGHT, dbData.fight());
    m_pAttr->SetAttr(proto_ff::A_VIP_LEVEL, dbData.vip_level());
    m_facade.read_from_pbmsg(dbData.facade());
    SetState((proto_ff::ECState)dbData.state());
    return 0;
}

int NFBattlePlayer::ReadViewAttrData(const ::proto_ff::AttrDBData& dbData)
{
    for (int i = 0; i < (int)dbData.attr_lst_size(); i++)
    {
        const ::proto_ff::Attr64& attr = dbData.attr_lst(i);
        SetAttr(attr.id(), attr.value());
    }
    return 0;
}

//视野数据
void NFBattlePlayer::GetVisibleDataToClient(proto_ff::CreatureCreateData& cvData)
{
    proto_ff::CreatureCreateData::Player* pPlayerVinfo = cvData.add_players();
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
    auto& setAttr = NFAttrMgr::Instance(m_pObjPluginManager)->PlayerViewAttr();
    for (auto iter = setAttr.begin(); iter != setAttr.end(); ++iter)
    {
        uint32_t attrid = (*iter);
        proto_ff::Attr64* pAttr = pPlayerVinfo->add_attr();
        if (nullptr != pAttr)
        {
            pAttr->set_id(attrid);
            pAttr->set_value(GetAttr(attrid));
        }
    }
    //外观
    proto_ff::RoleFacadeProto* protofacade = pPlayerVinfo->mutable_facade();
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

int NFBattlePlayer::TransScene(uint64_t scenceId, const NFPoint3<float>& dstPos, uint64_t mapId, const proto_ff::SceneTransParam& transParam)
{
    NFBattleMovePart* pMove = dynamic_cast<NFBattleMovePart*>(GetPart(BATTLE_PART_MOVE));
    CHECK_NULL(pMove);
    return pMove->TransScene(scenceId, dstPos, mapId, transParam);
}

int NFBattlePlayer::CanTrans(uint64_t dstSceneId, uint64_t dstMapId, const NFPoint3<float>& dstPos, NFPoint3<float>& outPos, const proto_ff::SceneTransParam& transParam,
                             bool checkPosFlag)
{
    NFMap* pMap = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(dstMapId);
    if (nullptr == pMap)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, Cid(), "[logic] Player::CanTrans... nullptr == pMap..cid:%lu,dstscene:%lu,dstmap:%lu,pos:%f,%f,%f,transtype:%d,p1:%ld,p2:%ld,p3:%ld ", Cid(),
                      dstSceneId, dstMapId, dstPos.x, dstPos.y, dstPos.z, transParam.trans_type(), transParam.param1(), transParam.param2(), transParam.param3());
        return proto_ff::RET_FAIL;
    }
    
    if (checkPosFlag)
    {
        if (!pMap->FindNearestPos(dstPos.x, dstPos.z, dstPos.y, &outPos.x, &outPos.z, &outPos.y, nullptr))
        {
            //坐标无效
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, Cid(), "[logic] Player::CanTrans FindNearestPos failed..cid:%lu,dstscene:%lu,dstmap:%lu,pos:%f,%f,%f,transtype:%d,p1:%ld,p2:%ld,p3:%ld ", Cid(), dstSceneId, dstMapId, dstPos.x, dstPos.y, dstPos.z, transParam.trans_type(), transParam.param1(), transParam.param2(), transParam.param3());
            return proto_ff::RET_SCENE_INVALID_DST_POS;
        }
    }
    
    //青云之巅，战斗中也可以传送走。
    if (IsPVPState() &&
        !(MapDescEx::Instance()->IsQyActMap(dstMapId) ||
          MapDescEx::Instance()->Is3v3WaitMap(dstMapId) ||
          MapDescEx::Instance()->Is3v3Map(dstMapId))
        )
    {
        return proto_ff::RET_PLAYER_IN_PVP_STATE;
    }
    
    auto pMapCfgInfo = MapMapDesc::Instance()->GetDesc(dstMapId);
    if (nullptr == pMapCfgInfo)
    {
        return proto_ff::RET_CONFIG_ERROR;
    }
    
    if (GetAttr(proto_ff::A_LEVEL) < (int64_t)pMapCfgInfo->m_levelLimit)
    {
        return proto_ff::RET_LEVEL_LACK;
    }
    
    if (dstMapId != m_mapId && IsDead() && IsTired())
    {
        return proto_ff::RET_PLAYER_TIRED_STATE;
    }
    
    if (MapDescEx::Instance()->IsMainCity(pMapCfgInfo))
    {
        uint64_t dstSceneId = NFSceneMgr::Instance(m_pObjPluginManager)->MainCitySceneId(dstMapId, GetZid());
        if (dstSceneId <= 0)
        {
            return proto_ff::RET_SCENE_DST_NOT_EXIST;
        }
    }
    
    return proto_ff::RET_SUCCESS;
}

bool NFBattlePlayer::EnterFightState()
{
    if (BState(proto_ff::state_seat)) { LeaveSeatState(); }
    NFCreature::EnterFightState();
    if (BState(proto_ff::state_fight))
    {
        if (m_timerId_FightState != INVALID_ID)
        {
            DeleteTimer(m_timerId_FightState);
        }
        
        m_timerId_FightState = SetTimer(5000, 1, 0, 0, 0, 0);
        return true;
    }
    return false;
}

int NFBattlePlayer::ChangeLogic(uint64_t dstSceneId, uint64_t dstMapId, const NFPoint3<float>& dstPos, proto_ff::CreatureTransParam& creatureParam)
{
    uint64_t curMapId = GetMapId();
    uint64_t curSceneId = GetSceneId();
    proto_ff::SceneTransParam param;
    if (creatureParam.has_trans_param())
    {
        const proto_ff::SceneTransParam& protoTransParam = creatureParam.trans_param();
        param.CopyFrom(protoTransParam);
    }
    //
    proto_ff::PlayerTransParam* protoPlayer = creatureParam.mutable_player_param();
    for (uint32_t i = BATTLE_PART_NONE + 1; i < BATTLE_PART_MAX; ++i)
    {
        NFBattlePart* pPart = GetPart(i);
        if (pPart)
        {
            pPart->PrepareChangeLogic();
        }
    }
    
    //停止移动
    StopMove();
    //设置为切逻辑服状态
    SetAccountState(ACCOUNT_GAME_STATE_SWITCH);
    SetCanBeSeenFlag(false);
    
    //填充切换逻辑服需要带过去的数据
    uint32_t gateId = GetProxyId();
    protoPlayer->set_uid(GetUid());
    protoPlayer->set_channid(GetChannId());
    protoPlayer->set_gateid(gateId);
    protoPlayer->set_zid(GetZid());
    protoPlayer->set_last_state(GetState());
    protoPlayer->set_head_flag(m_headFlag);
    
    //
    NFPoint3<float> lastpos = GetPos();
    uint64_t lastSceneId = GetSceneId();
    uint64_t lastMapId = GetMapId();
    protoPlayer->set_last_map_id(lastMapId);
    protoPlayer->set_last_scene_id(lastSceneId);
    protoPlayer->set_lastposx(lastpos.x);
    protoPlayer->set_lastposy(lastpos.y);
    protoPlayer->set_lastposz(lastpos.z);
    protoPlayer->set_prof(GetAttr(proto_ff::A_PROF));
    //
    NFPoint3<float> pos = GetPos();
    //当前地图不是动态地图,把上一个场景参数设置为当前场景参数
    if (!MapDescEx::Instance()->IsDynamic(curMapId))
    {
        protoPlayer->set_last_map_id(curMapId);
        protoPlayer->set_last_scene_id(curSceneId);
        protoPlayer->set_lastposx(pos.x);
        protoPlayer->set_lastposy(pos.y);
        protoPlayer->set_lastposz(pos.z);
    }
    //设置目标场景和目标地图以及坐标
    protoPlayer->set_enter_scene_id(dstSceneId);
    protoPlayer->set_enter_map_id(dstMapId);
    protoPlayer->set_enterposx(dstPos.x);
    protoPlayer->set_enterposy(dstPos.y);
    protoPlayer->set_enterposz(dstPos.z);
    //protoPlayer->set_enter_param(creatureParam.trans_param().param1());
    return 0;
}

int NFBattlePlayer::ChangeLogicFail()
{
    SetAccountState(ACCOUNT_GAME_STATE_GAMING);
    SetCanBeSeenFlag(true);
    return 0;
}

void NFBattlePlayer::OnTransSceneSuccess(const proto_ff::SceneTransParam& param)
{
    for (uint32_t i = BATTLE_PART_NONE + 1; i < BATTLE_PART_MAX; ++i)
    {
        NFBattlePart* pPart = GetPart(i);
        if (pPart)
        {
            pPart->OnTransSuccess(param);
        }
    }
}

bool NFBattlePlayer::LeaveFigthState()
{
    return NFCreature::LeaveFigthState();
}

bool NFBattlePlayer::EnterSeatState()
{
    if (BState(proto_ff::state_normal))
    {
        NFCreature::EnterSeatState();
    }
    else
    {
        return false;
    }
    return true;
}

bool NFBattlePlayer::LeaveSeatState()
{
    if (BState(proto_ff::state_seat))
    {
        return NFCreature::LeaveSeatState();
    }
    else
    {
        return false;
    }
}

void NFBattlePlayer::OnChangeState(uint8_t curstate, uint8_t laststate)
{
    NFCreature::OnChangeState(curstate, laststate);
    proto_ff::SyncSceneState syncState;
    syncState.set_cur_state(curstate);
    syncState.set_last_state(laststate);
    FireLogic(EVENT_SYNC_SCENE_STATE, Kind(), Cid(), syncState, false);
}

bool NFBattlePlayer::IsCanSendMessage()
{
    if (GetPlayerStatus() == proto_ff::PLAYER_STATUS_ONLINE)
    {
        return true;
    }
    return false;
}

int NFBattlePlayer::OnDisconnect()
{
    m_proxyId = 0;
    SetPlayerStatus(proto_ff::PLAYER_STATUS_OFFLINE);
    SetLastDiconnectTime(NFTime::Now().UnixSec());
    
    StopMove();
    return 0;
}

int NFBattlePlayer::OnLogout()
{
    SetCanBeSeenFlag(false);
    UpdateSeeLst();
    return 0;
}

//移动到目标坐标
int NFBattlePlayer::MoveTo(const NFPoint3<float>& dstPos)
{
    NFBattleMovePart* pMove = dynamic_cast<NFBattleMovePart*>(GetPart(BATTLE_PART_MOVE));
    CHECK_NULL(pMove);
    return pMove->MoveTo(dstPos);
}

//停止当前移动
int NFBattlePlayer::StopMove()
{
    NFBattleMovePart* pMove = dynamic_cast<NFBattleMovePart*>(GetPart(BATTLE_PART_MOVE));
    CHECK_NULL(pMove);
    return pMove->StopMove();
}

//瞬间移动
int NFBattlePlayer::Teleporting(const NFPoint3<float>& dstPos, int32_t type/* = proto_ff::MoveTeleportRsp_Type_common*/)
{
    NFBattleMovePart* pMove = dynamic_cast<NFBattleMovePart*>(GetPart(BATTLE_PART_MOVE));
    CHECK_NULL(pMove);
    return pMove->Teleporting(dstPos, type);
}

bool NFBattlePlayer::SetAccountState(AccountGameState state)
{
    m_accountState = state;
    return true;
}
