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
#include "Part/NFMovePart.h"
#include "Map/NFMapMgr.h"
#include "Map/NFMap.h"
#include "DescStore/MapMapDesc.h"
#include "NFLogicCommon/NFEventDefine.h"
#include "Event.pb.h"
#include "NFComm/NFCore/NFTime.h"
#include "ClientServerCmd.pb.h"
#include "CSPlayer.pb.h"

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
    m_playerStatus = PLAYER_STATUS_NONE;
    m_lastDiconnectTime = 0;
    m_createTime = NFTime::Now().UnixSec();
    m_lastLogoutTime = 0;
    m_isDisconnect = false;

    m_kind = CREATURE_PLAYER;
    m_isInited = false;
    m_uid = 0;
    m_roleId = 0;
    m_channId = 0;
    m_zid = 0;
    m_proxyId = 0;
    m_clientId = 0;
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

int NFBattlePlayer::Init(const proto_ff::RoleEnterSceneData &data)
{
    m_roleId = data.cid();
    m_cid = m_roleId;
    m_zid = data.zid();
    m_uid = data.uid();

    NFCreature::Init();
    ResetCurSeq();
    m_isInited = true;

    for (uint32_t i = BATTLE_PART_NONE + 1; i < BATTLE_PART_MAX; ++i)
    {
        NFBattlePart *pPart = CreatePart(i, data);
        if (nullptr == pPart)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_cid, "Player Init, Create Part Failed, roleId:{} uid:{} part:{}", m_cid, m_uid, i);
            return -1;
        }

        m_pPart[i] = pPart->GetGlobalID();
    }

    SetState(proto_ff::state_normal);

    Subscribe(NF_ST_GAME_SERVER, EVENT_SYNC_SCENE_FACADE, CREATURE_PLAYER, Cid(), __FUNCTION__);
    Subscribe(NF_ST_GAME_SERVER, EVENT_SYNC_CREATURE_ATTR, CREATURE_PLAYER, Cid(), __FUNCTION__);
    Subscribe(NF_ST_GAME_SERVER, EVENT_SYNC_CREATURE_BROADCAST_ATTR, CREATURE_PLAYER, Cid(), __FUNCTION__);


    return 0;
}

int NFBattlePlayer::Init(uint32_t gateId, uint64_t clientId, uint32_t logicId, const proto_ff::RoleEnterSceneData &data)
{
    ReadBaseData(data.base());
    ReadViewAttrData(data.attr());

    m_proxyId = gateId;
    m_clientId = clientId;
    m_logicId = logicId;
    for (uint32_t i = BATTLE_PART_NONE + 1; i < BATTLE_PART_MAX; ++i)
    {
        NFBattlePart *pPart = GetPart(i);
        if (nullptr == pPart)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_cid, "Player Init, Get Part Failed, roleId:{} uid:{} part:{}", m_cid, m_uid, i);
            return -1;
        }

        pPart->Init(data);
    }

    return 0;
}

NFBattlePart *NFBattlePlayer::CreatePart(uint32_t partType, const ::proto_ff::RoleEnterSceneData &data)
{
    NFBattlePart *pPart = NULL;
    switch (partType)
    {
        case BATTLE_PART_MOVE:
        {
            pPart = dynamic_cast<NFBattlePart *>(FindModule<NFISharedMemModule>()->CreateObj(EOT_NFMovePart_ID));
            break;
        }
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_cid, "Create Part Failed, partType Not Handle:{}", partType);
            break;
        }
    }

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

int NFBattlePlayer::RecylePart(NFBattlePart *pPart)
{
    CHECK_NULL(pPart);
    pPart->UnInit();
    FindModule<NFISharedMemModule>()->DestroyObj(pPart);
    return 0;
}

NFBattlePart *NFBattlePlayer::GetPart(uint32_t partType)
{
    if (partType <= 0 || partType >= m_pPart.size())
    {
        return nullptr;
    }

    return dynamic_cast<NFBattlePart *>(FindModule<NFISharedMemModule>()->GetObjFromGlobalID(m_pPart[partType], EOT_NFBattlePart_ID, 0));
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
    for(int i = 0; i < (int)pEvent->attr_size(); i++)
    {
        const ::proto_ff::Attr64& attr = pEvent->attr(i);
        SetAttr(attr.id(), attr.value());
    }
    return 0;
}

int NFBattlePlayer::SyncBroadAttr(const proto_ff::CreatureAttrBroadRsp* pEvent)
{
    CHECK_NULL(pEvent);
    for(int i = 0; i < (int)pEvent->attr_size(); i++)
    {
        const ::proto_ff::Attr64& attr = pEvent->attr(i);
        SetAttr(attr.id(), attr.value());
    }

    BroadCast(proto_ff::CREATURE_ATTR_BROAD, *pEvent);
    return 0;
}

int NFBattlePlayer::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
{
    switch(nEventID)
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
    switch (m_playerStatus)
    {
        case PLAYER_STATUS_NONE:
        {
            if ((uint64_t) NFTime::Now().UnixSec() - m_createTime < WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;

            SetPlayerStatus(PLAYER_STATUS_LOGOUT);
            SetLastLogoutTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, GetUid(), "player:{} status:PLAYER_STATUS_NONE change to PLAYER_STATUS_LOGOUT", GetUid());
            OnLogout();
        }
            break;
        case PLAYER_STATUS_ONLINE:
        {
        }
            break;
        case PLAYER_STATUS_OFFLINE:
        {
            if ((uint64_t) NFTime::Now().UnixSec() - GetLastDiconnectTime() < GAME_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;

            SetPlayerStatus(PLAYER_STATUS_LOGOUT);
            SetLastLogoutTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, GetUid(), "uid:{}, cid:{} status:PLAYER_STATUS_OFFLINE change to PLAYER_STATUS_LOGOUT", GetUid(),
                      GetRoleId());
            OnLogout();
        }
            break;
        case PLAYER_STATUS_LOGOUT:
        default:
        {
            if (GetScene() == NULL)
            {
                SetPlayerStatus(PLAYER_STATUS_DEAD);
                NFLogInfo(NF_LOG_SYSTEMLOG, GetUid(), "player:{}, cid:{} status change to PLAYER_STATUS_DEAD, will be erase from memory", GetUid(),
                          GetRoleId());
            }
        }
            break;
    }

    return 0;
}

int NFBattlePlayer::ReadBaseData(const ::proto_ff::RoleDBBaseData &dbData)
{
    m_name = dbData.name();
    m_facade.read_from_pbmsg(dbData.facade());
    SetState((proto_ff::ECState)dbData.state());
    return 0;
}

int NFBattlePlayer::ReadViewAttrData(const ::proto_ff::AttrDBData &dbData)
{
    for(int i = 0; i < (int)dbData.attr_lst_size(); i++)
    {
        const ::proto_ff::Attr64& attr = dbData.attr_lst(i);
        SetAttr(attr.id(), attr.value());
    }
    return 0;
}

//视野数据
void NFBattlePlayer::GetVisibleDataToClient(proto_ff::CreatureCreateData &cvData)
{
    proto_ff::CreatureCreateData::Player *pPlayerVinfo = cvData.add_players();
    if (nullptr == pPlayerVinfo)
    {
        return;
    }

    pPlayerVinfo->set_cid(m_cid);
    pPlayerVinfo->set_name(m_name.ToString());
    proto_ff::Vector3PB *protopos = pPlayerVinfo->mutable_pos();
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

int NFBattlePlayer::TransScene(uint64_t scenceId, const NFPoint3<float> &dstPos, uint64_t mapId, STransParam &transParam)
{
    NFMovePart *pMove = dynamic_cast<NFMovePart *>(GetPart(BATTLE_PART_MOVE));
    CHECK_NULL(pMove);
    return pMove->TransScene(scenceId, dstPos, mapId, transParam);
}

int NFBattlePlayer::CanTrans(uint64_t dstSceneId, uint64_t dstMapId, const NFPoint3<float> &dstPos, NFPoint3<float> &outPos, STransParam &transParam,
                             bool checkPosFlag)
{
    NFMap *pMap = NFMapMgr::Instance(m_pObjPluginManager)->GetMap(dstMapId);
    if (nullptr == pMap)
    {
        NFLogError(NF_LOG_SYSTEMLOG, Cid(), "CanTrans... nullptr == pMap..cid:{}, dstscene:{}, dstmap:{}, pos:{},{},{}, transtype:{}, transval:{} ",
                   Cid(), dstSceneId, dstMapId, dstPos.x, dstPos.y, dstPos.z, transParam.transType, transParam.transVal);
        return proto_ff::RET_FAIL;
    }
    if (checkPosFlag)
    {
        if (!pMap->FindNearestPos(dstPos.x, dstPos.z, dstPos.y, &outPos.x, &outPos.z, &outPos.y, nullptr))
        {
            //坐标无效
            NFLogError(NF_LOG_SYSTEMLOG, Cid(),
                       "CanTrans FindNearestPos failed..cid:{}, dstscene:{}, dstmap:{}, pos:{},{},{}, transtype:{}, transval:{} ", Cid(), dstSceneId,
                       dstMapId, dstPos.x, dstPos.y, dstPos.z, transParam.transType, transParam.transVal);
            return proto_ff::RET_SCENE_INVALID_DST_POS;
        }
    }

    auto pMapCfgInfo = MapMapDesc::Instance(m_pObjPluginManager)->GetDesc(dstMapId);
    if (nullptr == pMapCfgInfo)
    {
        NFLogError(NF_LOG_SYSTEMLOG, Cid(), "CanTrans Find Map Cfg failed..cid:{}, dstscene:{}, dstmap:{}, pos:{},{},{}, transtype:{}, transval:{} ",
                   Cid(), dstSceneId, dstMapId, dstPos.x, dstPos.y, dstPos.z, transParam.transType, transParam.transVal);
        return proto_ff::RET_CONFIG_ERROR;
    }

    if (GetAttr(proto_ff::A_LEVEL) < (int64_t) pMapCfgInfo->m_levellimit)
    {
        return proto_ff::RET_LEVEL_LACK;
    }

    if (dstMapId != m_mapId && IsTired())
    {
        return proto_ff::RET_PLAYER_TIRED_STATE;
    }

    return proto_ff::RET_SUCCESS;
}

bool NFBattlePlayer::EnterFightState()
{
    if (BState(proto_ff::state_seat)) LeaveSeatState();
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

uint64_t NFBattlePlayer::GetCreateTime() const
{
    return m_createTime;
}

void NFBattlePlayer::SetCreateTime(uint64_t createTime)
{
    m_createTime = createTime;
}

uint64_t NFBattlePlayer::GetLastDiconnectTime() const
{
    return m_lastDiconnectTime;
}

void NFBattlePlayer::SetLastDiconnectTime(uint64_t lastDiconnectTime)
{
    m_lastDiconnectTime = lastDiconnectTime;
}

uint64_t NFBattlePlayer::GetLastLogoutTime() const
{
    return m_lastLogoutTime;
}

void NFBattlePlayer::SetLastLogoutTime(uint64_t lastLogoutTime)
{
    m_lastLogoutTime = lastLogoutTime;
}

bool NFBattlePlayer::IsDisconnect() const
{
    return m_isDisconnect;
}

void NFBattlePlayer::SetIsDisconnect(bool isDisConnect)
{
    m_isDisconnect = isDisConnect;
}

int NFBattlePlayer::OnDisconnect()
{
    m_proxyId = 0;
    m_clientId = 0;
    SetPlayerStatus(PLAYER_STATUS_OFFLINE);
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
    NFMovePart *pMove = dynamic_cast<NFMovePart *>(GetPart(BATTLE_PART_MOVE));
    CHECK_NULL(pMove);
    return pMove->MoveTo(dstPos);
}

//停止当前移动
int NFBattlePlayer::StopMove()
{
    NFMovePart *pMove = dynamic_cast<NFMovePart *>(GetPart(BATTLE_PART_MOVE));
    CHECK_NULL(pMove);
    return pMove->StopMove();
}

//瞬间移动
int NFBattlePlayer::Teleporting(const NFPoint3<float>& dstPos, int32_t type/* = proto_ff::MoveTeleportRsp_Type_common*/)
{
    NFMovePart *pMove = dynamic_cast<NFMovePart *>(GetPart(BATTLE_PART_MOVE));
    CHECK_NULL(pMove);
    return pMove->Teleporting(dstPos, type);
}