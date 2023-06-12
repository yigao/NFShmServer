// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayerIDHashTable.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayerIDHashTable.cpp
//
// -------------------------------------------------------------------------

#include "NFWorldPlayerMgr.h"
#include "NFWorldPlayer.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include <map>
#include <NFComm/NFPluginModule/NFCheck.h>
#include "NFComm/NFCore/NFServerTime.h"
#include "NFWorldSession.h"
#include "NFWorldSessionMgr.h"
#include "CSLogin.pb.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "ClientServerCmd.pb.h"
#include "ServerInternal.pb.h"
#include "ServerInternalCmd.pb.h"
#include "ServerInternal2.pb.h"
#include "ServerInternalCmd2.pb.h"
#include "NFTransWorldGetRoleList.h"
#include "NFLogicCommon/NFRoleDefine.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFWorldPlayerMgr, EOT_WORLD_PLAYER_MGR_ID, NFShmObj)

NFWorldPlayerMgr::NFWorldPlayerMgr() : NFShmObj()
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

NFWorldPlayerMgr::~NFWorldPlayerMgr()
{
    if (m_playerTickTimer != INVALID_ID)
    {
        DeleteTimer(m_playerTickTimer);
        m_playerTickTimer = INVALID_ID;
    }
}

int NFWorldPlayerMgr::CreateInit()
{
    m_currentLoginNum = 0;
    m_maxQueueNum = 2000;    //排队总人数
    m_startQueueNum = 2000; //开始排队人数
    m_playerTickTimer = SetTimer(100, 0, 0, 0, 1, 0);
    return 0;
}

int NFWorldPlayerMgr::ResumeInit()
{
    return 0;
}

int NFWorldPlayerMgr::OnTimer(int timeId, int callcount)
{
    if (m_playerTickTimer == timeId)
    {
        PlayerTick();
        SessionTick();
    }
    return 0;
}

int NFWorldPlayerMgr::PlayerTick()
{
    std::vector<uint64_t> willRemovePlayer;
    NFWorldPlayer* pPlayer = dynamic_cast<NFWorldPlayer *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_WORLD_PLAYER_ID));
    while (pPlayer)
    {
        pPlayer->Tick();
        if (pPlayer->GetStatus() == PLAYER_STATUS_DEAD)
        {
            willRemovePlayer.push_back(pPlayer->GetUid());
        }
        pPlayer = dynamic_cast<NFWorldPlayer *>(FindModule<NFISharedMemModule>()->GetNextObj(EOT_WORLD_PLAYER_ID, pPlayer));
    }

    for(int i = 0; i < (int)willRemovePlayer.size(); i++)
    {
        pPlayer = GetPlayerByUid(willRemovePlayer[i]);
        if (pPlayer)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, pPlayer->GetUid(), "player:{} be erase from memory", pPlayer->GetUid());
            DeletePlayer(pPlayer);
        }
    }

    //处理排队直接进去
    if (!IsNeedLoginQueue() && m_loginQueueMap.size() > 0)
    {
        auto iterQueue = m_loginQueueMap.begin();
        uint32_t uid = iterQueue->first;
        NFWorldPlayer* pQueuePlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(uid);
        if (pQueuePlayer)
        {
            NFWorldSession* pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(pQueuePlayer->GetClientId());
            if (pSession && EAccountState::queue == pSession->GetState())
            {
                pSession->SetState(EAccountState::login);
                pSession->SetStateTick(NFTime::Now().UnixMSec());

                NF_SHARE_PTR<NFServerData> pLogicServer = NULL;
                if (pPlayer->GetLogicId() > 0)
                {
                    pLogicServer = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_WORLD_SERVER, pPlayer->GetLogicId());
                }
                else {
                    pLogicServer = FindModule<NFIMessageModule>()->GetSuitServerByServerType(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER,
                                                                                             pPlayer->GetUid());
                }

                if (pLogicServer == NULL)
                {
                    pLogicServer = FindModule<NFIMessageModule>()->GetRandomServerByServerType(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER);
                }

                if (pLogicServer)
                {
                    pPlayer->SetLogicId(pLogicServer->mServerInfo.bus_id());

                    NFTransWorldGetRoleList* pTrans = dynamic_cast<NFTransWorldGetRoleList *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_NFTransWorldSendGetRoleList_ID));
                    CHECK_EXPR(pTrans, -1, "CreateTrans NFTransCreateRole failed!");
                    pTrans->Init(uid, pSession->GetProxyId(), pSession->GetClientId(), pPlayer->GetLoginZid(), 0);
                    pTrans->SendGetRoleList();
                }
                else
                {
                    NFLogError(NF_LOG_SYSTEMLOG, uid, "can not find suit logic server to player, the all logic server may be dump");
                    pPlayer->SetProxyId(0);
                    pPlayer->SetClientId(0);

                    NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(pSession->GetProxyId(), pSession->GetClientId(), proto_ff::LOGOUT_KICK_OUT);
                }
            }

            m_loginQueueMap.erase(iterQueue);
        }
        else
        {
            //找不到排队的账号信息，直接从排队中移除
            m_loginQueueMap.erase(iterQueue);
        }
    }
    return 0;
}

int NFWorldPlayerMgr::SessionTick()
{
    m_currentLoginNum = NFWorldSession::GetUsedCount(m_pObjPluginManager);

    std::vector<uint64_t> willRemoveSession;
    NFWorldSession* pSession = dynamic_cast<NFWorldSession *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_WORLD_SESSION_ID));
    while (pSession)
    {
        NFWorldPlayer* pPlayer = GetPlayerByUid(pSession->GetUid());
        if (pPlayer == NULL || pPlayer->GetStatus() >= PLAYER_STATUS_OFFLINE || pPlayer->GetClientId() != pSession->GetClientId())
        {
            willRemoveSession.push_back(pSession->GetClientId());
        }
        pSession = dynamic_cast<NFWorldSession *>(FindModule<NFISharedMemModule>()->GetNextObj(EOT_WORLD_SESSION_ID, pSession));
    }

    for(int i = 0; i < (int)willRemoveSession.size(); i++)
    {
        NFWorldSessionMgr::Instance(m_pObjPluginManager)->DeleteSession(willRemoveSession[i]);
    }

    NFWorldPlayer* pPlayer = dynamic_cast<NFWorldPlayer *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_WORLD_PLAYER_ID));
    while (pPlayer)
    {
        if (pPlayer->GetStatus() <= PLAYER_STATUS_ONLINE)
        {
            if (pPlayer->GetClientId() > 0)
            {
                NFWorldSession* pPlayerSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(pPlayer->GetClientId());
                if (pPlayerSession == NULL)
                {
                    pPlayer->SetStatus(PLAYER_STATUS_OFFLINE);
                    pPlayer->SetIsDisconnect(true);
                }
            }
            else {
                pPlayer->SetStatus(PLAYER_STATUS_OFFLINE);
                pPlayer->SetIsDisconnect(true);
            }
        }
        pPlayer = dynamic_cast<NFWorldPlayer *>(FindModule<NFISharedMemModule>()->GetNextObj(EOT_WORLD_PLAYER_ID, pPlayer));
    }

    return 0;
}

NFWorldPlayer *NFWorldPlayerMgr::GetPlayerByUid(uint64_t uid)
{
    return dynamic_cast<NFWorldPlayer *>(FindModule<NFISharedMemModule>()->GetObjByHashKey(uid, EOT_WORLD_PLAYER_ID));
}

NFWorldPlayer *NFWorldPlayerMgr::CreatePlayerByUid(uint64_t uid)
{
    NFWorldPlayer *pPlayer = GetPlayerByUid(uid);
    CHECK_EXPR(pPlayer == NULL, NULL, "Create player Failed, player exist, uid:{}", uid);

    pPlayer = dynamic_cast<NFWorldPlayer *>(FindModule<NFISharedMemModule>()->CreateObjByHashKey(uid, EOT_WORLD_PLAYER_ID));
    CHECK_EXPR(pPlayer, NULL, "Create Player Obj Failed, playerID:{}", uid);

    pPlayer->SetUid(uid);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Add Player Success, uid:{} globalId:{}", uid,
              pPlayer->GetGlobalID());
    return pPlayer;
}

int NFWorldPlayerMgr::DeletePlayer(NFWorldPlayer *pPlayer)
{
    CHECK_NULL(pPlayer);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Player Info, playerID, gloablId:{}", pPlayer->GetUid(), pPlayer->GetGlobalID());

    FindModule<NFISharedMemModule>()->DestroyObj(pPlayer);

    return 0;
}


uint32_t NFWorldPlayerMgr::GetCurrentLoginNum() const
{
    return m_currentLoginNum;
}

void NFWorldPlayerMgr::SetCurrentLoginNum(uint32_t currentLoginNum)
{
    m_currentLoginNum = currentLoginNum;
}

uint32_t NFWorldPlayerMgr::GetMaxQueueNum() const
{
    return m_maxQueueNum;
}

void NFWorldPlayerMgr::SetMaxQueueNum(uint32_t maxQueueNum)
{
    m_maxQueueNum = maxQueueNum;
}

uint32_t NFWorldPlayerMgr::GetStartQueueNum() const
{
    return m_startQueueNum;
}

void NFWorldPlayerMgr::SetStartQueueNum(uint32_t startQueueNum)
{
    m_startQueueNum = startQueueNum;
}

bool NFWorldPlayerMgr::IsNeedLoginQueue() const
{
    if (m_currentLoginNum >= m_startQueueNum)
    {
        return true;
    }

    return false;
}

bool NFWorldPlayerMgr::IsLoginQueueFull() const
{
    if ((uint32_t) m_loginQueueMap.size() >= m_maxQueueNum)
    {
        return true;
    }

    return false;
}

/**
 * @brief 是否在排队队列中
 * @param playerId
 * @return
 */
bool NFWorldPlayerMgr::IsInLoginQueue(uint64_t playerId) const
{
    auto iter = m_loginQueueMap.find(playerId);
    if (iter != m_loginQueueMap.end())
    {
        return true;
    }
    return false;
}

/**
 * @brief 加入到登陆排队中
 * @param playerId
 * @return
 */
bool NFWorldPlayerMgr::InsertLoginQueue(uint64_t playerId)
{
    auto iter = m_loginQueueMap.emplace_hint(playerId, NFLoginQueue());
    if (iter != m_loginQueueMap.end())
    {
        iter->second.SetUid(playerId);
        iter->second.SetLastReqTime(NFServerTime::Instance()->UnixSec());
        return true;
    }
    return false;
}

NFLoginQueue *NFWorldPlayerMgr::GetLoginQueue(uint64_t playerId)
{
    auto iter = m_loginQueueMap.find(playerId);
    if (iter != m_loginQueueMap.end())
    {
        return &iter->second;
    }
    return nullptr;
}

/**
 * @brief 获得当前排队人数
 * @return
 */
uint32_t NFWorldPlayerMgr::GetLoginQueueNum() const
{
    return (uint32_t) m_loginQueueMap.size();
}

/**
 * @brief 删除玩家的排队信息
 * @param playerId
 * @return
 */
int NFWorldPlayerMgr::DeleteLoginQueue(uint64_t playerId)
{
    return m_loginQueueMap.erase(playerId);
}

int NFWorldPlayerMgr::CharDBToCharSimpleDB(const proto_ff::RoleDBData &dbproto, proto_ff::LoginRoleProto &outproto)
{
    outproto.set_cid(dbproto.cid());
    outproto.set_name(dbproto.base().name());
    outproto.set_prof(dbproto.base().prof());
    outproto.set_level(dbproto.base().level());
    outproto.set_fight(dbproto.base().fight());
    outproto.set_createtime(dbproto.base().createtime());
    outproto.mutable_facade()->CopyFrom(dbproto.base().facade());

    return 0;
}

int NFWorldPlayerMgr::NotifyGateLeave(uint64_t proxyId, uint64_t clientId, proto_ff::LOGOUT_TYPE flag)
{
    NFWorldSession *pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(clientId);
    if (pSession)
    {
        NFWorldSessionMgr::Instance(m_pObjPluginManager)->DeleteSession(pSession);
    }


    //通知客户端强制断线
    //路由管理器移除对应的标识
    proto_ff::NotifyGateLeaveGame2 notify;
    notify.set_clientid(clientId);
    notify.set_leave_flag(flag);

    FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_WORLD_SERVER, proxyId, NF_MODULE_SERVER,
                                                               proto_ff::NOTIFY_GATE_LEAVE_GAME, notify, clientId);

    return 0;
}

int NFWorldPlayerMgr::NotifyLogicLeave(NFWorldPlayer* pPlayer, NFWorldSession* pSession, proto_ff::LOGOUT_TYPE type, int reqTransId/* = 0*/)
{
    //强制断开之前的客户端session
    if (pSession)
    {
        NotifyGateLeave(pSession->GetProxyId(), pSession->GetClientId(), type);
    }

    if (pPlayer)
    {
        OnHandlePlayerDisconnect(pPlayer, ROLE_DISCONN_FROM_SERVER);
        if (pPlayer->GetRoleId() > 0)
        {
            proto_ff::NotifyLogicLeaveGameReq2 req;
            req.set_cid(pPlayer->GetRoleId());
            req.set_uid(pPlayer->GetUid());
            req.set_type(type);
            pPlayer->SendTransToLogicServer(proto_ff::NOTIFY_LOGIC_LEAVE_GAME_REQ, req, reqTransId);
            return 0;
        }
    }

    return -1;
}

int NFWorldPlayerMgr::NotifyGateChangeServerBusId(NFWorldPlayer *pPlayer, uint32_t serverType, uint32_t busId)
{
    proto_ff::WroldToProxyChangeServerBusId xMsg;
    auto pServerInfo = xMsg.add_server_info();
    pServerInfo->set_server_type(serverType);
    pServerInfo->set_bus_id(busId);

    if (pPlayer)
    {
        pPlayer->SendMsgToProxyServer(proto_ff::WORLD_TO_PROXY_SERVER_BUS_ID_CHANGE_NOTIFY, xMsg);
    }
    return 0;
}

int NFWorldPlayerMgr::OnHandlePlayerDisconnect(NFWorldPlayer* pPlayer, uint32_t reason)
{
    CHECK_NULL(pPlayer);

    pPlayer->OnDisconnect();

    NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyOtherServerPlayerDisconnect(pPlayer, reason);
    return 0;
}

int NFWorldPlayerMgr::NotifyOtherServerPlayerDisconnect(NFWorldPlayer *pPlayer, uint32_t reason)
{
    CHECK_NULL(pPlayer);

    if (pPlayer->GetRoleId() > 0)
    {
        proto_ff::WorldToOtherServerDisconnectNotify xMsg;
        xMsg.set_roleid(pPlayer->GetRoleId());
        xMsg.set_reason(reason);

        pPlayer->SendMsgToLogicServer(proto_ff::WORLD_TO_OTHER_SERVER_NOTIFY_PLAYER_DISCONNECT, xMsg);
        pPlayer->SendMsgToSnsServer(proto_ff::WORLD_TO_OTHER_SERVER_NOTIFY_PLAYER_DISCONNECT, xMsg);
        if (pPlayer->GetRoleId() > 0 && pPlayer->GetGameId() > 0)
        {
            pPlayer->SendMsgToGameServer(proto_ff::WORLD_TO_OTHER_SERVER_NOTIFY_PLAYER_DISCONNECT, xMsg);
        }
    }

    return 0;
}

int NFWorldPlayerMgr::NotifyOtherServerPlayerDisconnect(uint64_t uid, uint64_t roleId, uint32_t logicId, uint32_t reason)
{
    if (uid > 0 && roleId > 0)
    {
        proto_ff::WorldToOtherServerDisconnectNotify xMsg;
        xMsg.set_roleid(roleId);
        xMsg.set_reason(reason);

        if (logicId > 0)
        {
            FindModule<NFIServerMessageModule>()->SendMsgToLogicServer(NF_ST_WORLD_SERVER, logicId, proto_ff::WORLD_TO_OTHER_SERVER_NOTIFY_PLAYER_DISCONNECT, xMsg, uid, logicId);
        }
        FindModule<NFIServerMessageModule>()->SendMsgToSnsServer(NF_ST_WORLD_SERVER, proto_ff::WORLD_TO_OTHER_SERVER_NOTIFY_PLAYER_DISCONNECT, xMsg, uid, logicId);
    }

    return 0;
}

int NFWorldPlayerMgr::HandleLoginQueue(NFWorldPlayer* pPlayer)
{
    CHECK_NULL(pPlayer);

    //如果到了排队为数，直接加进排队人数列表，返回排队消息
    if (IsNeedLoginQueue())
    {
        proto_ff::ClientQueuePosRsp xQueueRsp;

        //超过排队人数，则直接通知不能排队，返回消息
        if (IsLoginQueueFull())
        {
            xQueueRsp.set_ret(proto_ff::RET_LOGIN_QUEUE_ENOUGHT_NUM);
            pPlayer->SendMsgToClient(proto_ff::CLIENT_QUEUE_POS_RSP, xQueueRsp);

            NFWorldPlayerMgr::Instance(m_pObjPluginManager)->NotifyGateLeave(pPlayer->GetProxyId(), pPlayer->GetClientId(), proto_ff::LOGOUT_LOGOUT);

            pPlayer->SetProxyId(0);
            pPlayer->SetClientId(0);
        }
        else
        {
            //如果不在排队列表中，加入到排队列表中
            if (!NFWorldPlayerMgr::Instance(m_pObjPluginManager)->IsInLoginQueue(pPlayer->GetUid()))
            {
                bool ret = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->InsertLoginQueue(pPlayer->GetUid());
                CHECK_EXPR(ret, -1, "NFWorldPlayerMgr::Instance(m_pObjPluginManager)->InsertLoginQueue(uid) Failed");
            }

            xQueueRsp.set_ret(proto_ff::RET_SUCCESS);
            xQueueRsp.set_num(NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetLoginQueueNum());

            pPlayer->SendMsgToProxyServer(proto_ff::CLIENT_QUEUE_POS_RSP, xQueueRsp);
        }

        return 0;
    }

    return -1;
}