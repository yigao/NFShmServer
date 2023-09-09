// -------------------------------------------------------------------------
//    @FileName         :    NFCGamePlayerModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFCGamePlayerModule
//
// -------------------------------------------------------------------------

#include "NFCGamePlayerModule.h"
#include "Config/NFGameConfig.h"
#include "Room/NFGameRoomMgr.h"
#include "Player/NFGamePlayerMgr.h"

#define GAME_SERVER_REGISTER_ROOM_INFO_TO_WORLD_SERVER "Game Server Register Room Info to World Server"

NFCGamePlayerModule::NFCGamePlayerModule(NFIPluginManager *p) : NFFishDynamicModule(p)
{

}

NFCGamePlayerModule::~NFCGamePlayerModule()
{

}

bool NFCGamePlayerModule::Awake()
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
    NF_ASSERT(pConfig);

    m_pObjPluginManager->RegisterAppTask(NF_ST_GAME_SERVER, APP_INIT_REGISTER_WORLD_SERVER,
                                         NF_FORMAT("{} {}", pConfig->ServerName, GAME_SERVER_REGISTER_ROOM_INFO_TO_WORLD_SERVER),
                                         APP_INIT_TASK_GROUP_SERVER_REGISTER);

    m_pObjPluginManager->RegisterAppTask(NF_ST_GAME_SERVER, APP_INIT_DESC_STORE_LOAD, "GameServer Load Desc Store",
                                         APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE);

    ///////////////////////////////msg////////////////////////////////////////////
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_LTG_PLAYER_RECONNECT_MSG_REQ>(NF_ST_GAME_SERVER, this,
                                                                                             &NFCGamePlayerModule::OnHandlePlayerReconnectReq);
    RegisterServerMessage(NF_ST_GAME_SERVER, proto_ff::NF_WTG_PLAYER_DISCONNECT_MSG);
    ///////////////////////////////msg////////////////////////////////////////////

    Subscribe(NF_ST_GAME_SERVER, proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH, proto_ff::NF_EVENT_SERVER_TYPE,
              APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE, __FUNCTION__);
    Subscribe(NF_ST_GAME_SERVER, proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH, proto_ff::NF_EVENT_SERVER_TYPE,
              APP_INIT_TASK_GROUP_SERVER_CONNECT, __FUNCTION__);
    return true;
}

bool NFCGamePlayerModule::Execute()
{
    return NFIModule::Execute();
}

bool NFCGamePlayerModule::OnDynamicPlugin()
{
    return NFIModule::OnDynamicPlugin();
}

int NFCGamePlayerModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    return NFIDynamicModule::OnHandleClientMessage(msgId, packet, param1, param2);
}

int NFCGamePlayerModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_GAME_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Game Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Game Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (packet.nMsgId)
    {
        case proto_ff::NF_WTG_PLAYER_DISCONNECT_MSG:
        {
            OnHandlePlayerDisconnectMsg(msgId, packet, param1, param2);
            break;
        }
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Server MsgId:{} Register, But Not Handle, Package:{}", packet.nMsgId, packet.ToString());
            break;
        }
    }
    return 0;
}

int
NFCGamePlayerModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage)
{
    if (bySrcType == proto_ff::NF_EVENT_SERVER_TYPE && nEventID == proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH)
    {
        if (nSrcID == APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE)
        {
            NFGameRoomMgr::Instance(m_pObjPluginManager)->CreateAllRoom();
        }

        if (nSrcID == APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE || nSrcID == APP_INIT_TASK_GROUP_SERVER_CONNECT)
        {
            if (m_pObjPluginManager->IsFinishAppTask(NF_ST_GAME_SERVER, APP_INIT_TASK_GROUP_SERVER_CONNECT) &&
                m_pObjPluginManager->IsFinishAppTask(NF_ST_GAME_SERVER, APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE))
            {
                NFGameRoomMgr::Instance(m_pObjPluginManager)->RegisterAllRoomToWorldServer();
            }
        }
    }
    return 0;
}

int
NFCGamePlayerModule::OnHandlePlayerReconnectReq(proto_ff::LTGPlayerReconnectReq &request, proto_ff::GTLPlayerReconnectRsp &respone, uint64_t playerId,
                                                uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    NFGamePlayer *pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(playerId);
    CHECK_NULL(pPlayer);

    //如果是上面重新Create的Player， 成员m_gameId/m_roomId/m_deskId/m_chairId还有用吗？这里也没有赋值!!!
    pPlayer->m_online = true;
    pPlayer->m_proxyId = request.proxy_bus_id();
    pPlayer->m_logicId = request.logic_bus_id();
    pPlayer->SetOfflineTime(0);
    pPlayer->SetLastMsgTime(NFTime::Now().UnixSec());

    NFGameRoom *pRoom = NFGameRoomMgr::GetInstance(m_pObjPluginManager)->GetGameRoom(pPlayer->m_gameId, pPlayer->m_roomId);
    if (pRoom)
    {
        int iRet = pRoom->UserReconDesk(pPlayer->m_playerId, pPlayer->m_deskId);
        if (iRet != 0)
        {
            respone.set_result(iRet);
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "player:{} reconnect game failed", pPlayer->m_playerId);
            return 0;
        }
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "player:{} reconnect game success", pPlayer->m_playerId);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCGamePlayerModule::OnHandlePlayerDisconnectMsg(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    proto_ff::NotifyPlayerDisconnect xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFGamePlayer *pPlayer = NFGamePlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(xMsg.player_id());
    CHECK_NULL(pPlayer);

    pPlayer->m_proxyId = 0;
    pPlayer->m_online = false;
    pPlayer->SetOfflineTime(NFTime::Now().UnixSec());

    NFGameRoom *pRoom = NFGameRoomMgr::GetInstance(m_pObjPluginManager)->GetGameRoom(pPlayer->m_gameId, pPlayer->m_roomId);
    if (pRoom)
    {
        pRoom->UserDisconnect(pPlayer->m_playerId, pPlayer->m_deskId);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

