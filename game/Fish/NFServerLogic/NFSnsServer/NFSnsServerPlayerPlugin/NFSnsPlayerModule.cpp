// -------------------------------------------------------------------------
//    @FileName         :    NFCOnlineModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCOnlineModule
//
// -------------------------------------------------------------------------

#include "NFSnsPlayerModule.h"

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "AllProtocol.h"
#include "NFLogicCommon/NFLogicBindRpcService.h"
#include "Cache/NFPlayerSimple.h"
#include "Cache/NFCacheMgr.h"

NFCSnsPlayerModule::NFCSnsPlayerModule(NFIPluginManager *p) : NFIDynamicModule(p)
{
}

NFCSnsPlayerModule::~NFCSnsPlayerModule()
{
}

bool NFCSnsPlayerModule::Awake()
{
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////

    ///////////world msg//////////////////////////////////////////////////////////
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_WTS_PLAYER_LOGIN_REQ>(NF_ST_SNS_SERVER, this,
                                                                                     &NFCSnsPlayerModule::OnRpcServicePlayerLogin, true);
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_WTS_PLAYER_RECONNECT_MSG_REQ>(NF_ST_SNS_SERVER, this,
                                                                                     &NFCSnsPlayerModule::OnRpcServicePlayerReconnect, true);

    RegisterServerMessage(NF_ST_SNS_SERVER, proto_ff::NF_WTS_PLAYER_DISCONNECT_MSG);
    RegisterServerMessage(NF_ST_SNS_SERVER, proto_ff::NF_WTS_PLAYER_LOGOUT_NOTIFY);
    ///////////logic msg//////////////////////////////////////////////////////////
    return true;
}

bool NFCSnsPlayerModule::Init()
{
    return true;
}

bool NFCSnsPlayerModule::Execute()
{
    return true;
}

bool NFCSnsPlayerModule::OnDynamicPlugin()
{
    return true;
}

int NFCSnsPlayerModule::OnTimer(uint32_t nTimerID)
{
    NFCacheMgr::Instance(m_pObjPluginManager)->QueryPlayerSimple(10000);
    FindModule<NFICoroutineModule>()->MakeCoroutine([this]{
        NFCacheMgr::Instance(m_pObjPluginManager)->QueryPlayerSimpleByRpc(10000);
    });

    return 0;
}

int NFCSnsPlayerModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
{
    if (bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        if (nEventID == proto_ff::NF_EVENT_SERVER_LOAD_DESC_STORE)
        {
        }
        else if (nEventID == proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED)
        {
        }
    }
    return 0;
}

int NFCSnsPlayerModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t playerId, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Sns Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Sns Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (msgId)
    {
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Client MsgId:{} Register, But Not Handle, Package:{}", msgId, packet.ToString());
            break;
        }
    }

    return 0;
}

int NFCSnsPlayerModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Sns Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Sns Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (msgId)
    {
        case proto_ff::NF_WTS_PLAYER_DISCONNECT_MSG:
        {
            OnHandlePlayerDisconnectMsg(msgId, packet, param1, param2);
            break;
        }
        case proto_ff::NF_WTS_PLAYER_LOGOUT_NOTIFY:
        {
            OnHandlePlayerLogoutNotify(msgId, packet, param1, param2);
            break;
        }
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Server Internal MsgId:{} Register, But Not Handle, Package:{}", msgId, packet.ToString());
            break;
        }
    }

    return 0;
}

int NFCSnsPlayerModule::OnRpcServicePlayerLogin(proto_ff::Proto_WTSLoginReq& request, proto_ff::Proto_STWLoginRsp& respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    respone.set_user_id(request.user_id());
    respone.set_result(0);

    NFPlayerOnline* pPlayerOnline = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerOnline(request.user_id());
    if (pPlayerOnline == NULL)
    {
        pPlayerOnline = NFCacheMgr::Instance(m_pObjPluginManager)->CreatePlayerOnline(request.user_id());
        if (pPlayerOnline == NULL)
        {
            respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
            return 0;
        }
    }

    pPlayerOnline->SetProxyId(request.proxy_bus_id());
    pPlayerOnline->SetLogicId(request.logic_bus_id());
    pPlayerOnline->SetGameId(request.game_id());
    pPlayerOnline->SetIsOnline(true);

    NFPlayerSimple* pPlayerSimple = NFCacheMgr::Instance(m_pObjPluginManager)->QueryPlayerSimpleByRpc(request.user_id());
    if (pPlayerSimple == NULL)
    {
        if (request.sns_sync().create_player_db_data())
        {
            proto_ff::tbFishSnsPlayerSimpleData dbSimpleData;
            dbSimpleData.set_player_id(request.user_id());
            dbSimpleData.set_nickname(request.sns_sync().nick_name());
            dbSimpleData.set_faceid(request.sns_sync().face_id());
            pPlayerSimple = NFCacheMgr::Instance(m_pObjPluginManager)->CreatePlayerSimpleDBDataByRpc(dbSimpleData);
            if (pPlayerSimple == NULL)
            {
                respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
                return 0;
            }
        }
        else {
            respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
            return 0;
        }
    }

    NFPlayerDetail* pPlayerDetail = NFCacheMgr::Instance(m_pObjPluginManager)->QueryPlayerDetailByRpc(request.user_id());
    if (pPlayerDetail == NULL)
    {
        if (request.sns_sync().create_player_db_data())
        {
            proto_ff::tbFishSnsPlayerDetailData dbDetailData;
            dbDetailData.set_player_id(request.user_id());
            pPlayerDetail = NFCacheMgr::Instance(m_pObjPluginManager)->CreatePlayerDetailDBDataByRpc(dbDetailData);
            if (pPlayerDetail == NULL)
            {
                respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
                return 0;
            }
        }
        else {
            respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
            return 0;
        }
    }

    int iRet = pPlayerOnline->OnLogin();
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "pPlayerOnline:{} OnLogin:{} Failed", request.user_id(), GetErrorStr(iRet));
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    iRet = pPlayerSimple->OnLogin();
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "pPlayerSimple:{} OnLogin:{} Failed", request.user_id(), GetErrorStr(iRet));
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    iRet = pPlayerDetail->OnLogin();
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "pPlayerDetail:{} OnLogin:{} Failed", request.user_id(), GetErrorStr(iRet));
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFCSnsPlayerModule::OnRpcServicePlayerReconnect(proto_ff::WTSPlayerReconnectReq& request, proto_ff::STWPlayerReconnectRsp& respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    respone.set_result(0);

    NFPlayerOnline* pPlayerOnline = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerOnline(request.player_id());
    if (pPlayerOnline == NULL)
    {
        pPlayerOnline = NFCacheMgr::Instance(m_pObjPluginManager)->CreatePlayerOnline(request.player_id());
        if (pPlayerOnline == NULL)
        {
            respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
            return 0;
        }
    }

    pPlayerOnline->SetProxyId(request.proxy_bus_id());
    pPlayerOnline->SetLogicId(request.logic_bus_id());
    pPlayerOnline->SetIsOnline(true);

    NFPlayerSimple* pPlayerSimple = NFCacheMgr::Instance(m_pObjPluginManager)->QueryPlayerSimpleByRpc(request.player_id());
    if (pPlayerSimple == NULL)
    {
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    NFPlayerDetail* pPlayerDetail = NFCacheMgr::Instance(m_pObjPluginManager)->QueryPlayerDetailByRpc(request.player_id());
    if (pPlayerDetail == NULL)
    {
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    int iRet = pPlayerOnline->OnReconnect();
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "pPlayerOnline:{} OnReconnect:{} Failed", request.player_id(), GetErrorStr(iRet));
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    iRet = pPlayerSimple->OnReconnect();
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "pPlayerSimple:{} OnReconnect:{} Failed", request.player_id(), GetErrorStr(iRet));
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    iRet = pPlayerDetail->OnReconnect();
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "pPlayerDetail:{} OnReconnect:{} Failed", request.player_id(), GetErrorStr(iRet));
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, pPlayerDetail->GetPlayerId(), "player:{} reconnect success", pPlayerDetail->GetPlayerId());

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFCSnsPlayerModule::OnHandlePlayerDisconnectMsg(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");

    proto_ff::NotifyPlayerDisconnect xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFPlayerOnline* pPlayerOnline = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerOnline(xMsg.player_id());
    if (pPlayerOnline)
    {
        pPlayerOnline->SetProxyId(0);
        pPlayerOnline->SetIsOnline(false);
        pPlayerOnline->OnDisconnect();
    }

    NFPlayerSimple* pPlayerSimple = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerSimple(xMsg.player_id());
    if (pPlayerSimple)
    {
        pPlayerSimple->OnDisconnect();
    }

    NFPlayerDetail* pPlayerDetail = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerDetail(xMsg.player_id());
    if (pPlayerDetail)
    {
        pPlayerDetail->OnDisconnect();
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, xMsg.player_id(), "player:{} disconnect..............", xMsg.player_id());

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFCSnsPlayerModule::OnHandlePlayerLogoutNotify(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");

    proto_ff::Proto_WTSLogoutNotify xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFPlayerOnline* pPlayerOnline = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerOnline(xMsg.player_id());
    if (pPlayerOnline)
    {
        pPlayerOnline->OnLogout();
        NFPlayerSimple* pPlayerSimple = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerSimple(xMsg.player_id());
        if (pPlayerSimple)
        {
            pPlayerSimple->OnLogout();
        }

        NFPlayerDetail* pPlayerDetail = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerDetail(xMsg.player_id());
        if (pPlayerDetail)
        {
            pPlayerDetail->OnLogout();
        }

        NFCacheMgr::Instance(m_pObjPluginManager)->DeletePlayerOnline(pPlayerOnline);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, xMsg.player_id(), "player:{} logout..............", xMsg.player_id());

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}
