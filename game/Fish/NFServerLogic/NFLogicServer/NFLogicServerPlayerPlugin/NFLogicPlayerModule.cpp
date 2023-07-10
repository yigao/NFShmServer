// -------------------------------------------------------------------------
//    @FileName         :    NFWorldLoginModule.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldLoginModule
//
// -------------------------------------------------------------------------

#include "NFLogicPlayerModule.h"

#include "NFLogicPlayer.h"
#include "NFLogicPlayerMgr.h"
#include "ServerInternalCmd.pb.h"
#include "NFLogicCommon/NFLogicBindRpcService.h"

NFCLogicPlayerModule::NFCLogicPlayerModule(NFIPluginManager *p) : NFIDynamicModule(p) {

}

NFCLogicPlayerModule::~NFCLogicPlayerModule() {
}

bool NFCLogicPlayerModule::Awake() {
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////

    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_PTW_PLAYER_LOGIN_REQ>(NF_ST_WORLD_SERVER, this,
                                                                                     &NFCLogicPlayerModule::OnRpcServicePlayerLogin, true);
    //////////player enter game////////////////////////////////////
    return true;
}

bool NFCLogicPlayerModule::Execute()
{
	return true;
}

bool NFCLogicPlayerModule::OnDynamicPlugin()
{
	return true;
}

int NFCLogicPlayerModule::OnHandleClientMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (packet.nMsgId)
    {
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Client MsgId:{} Register, But Not Handle, Package:{}", packet.nMsgId, packet.ToString());
            break;
        }
    }
    return 0;
}


int NFCLogicPlayerModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (packet.nMsgId)
    {
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Server MsgId:{} Register, But Not Handle, Package:{}", packet.nMsgId, packet.ToString());
            break;
        }
    }
    return 0;
}

int NFCLogicPlayerModule::OnRpcServicePlayerLogin(proto_ff::Proto_PTWUserLoginReq& request, proto_ff::Proto_WTPPlayerLoginRsp& respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NFLogicPlayer *pPlayerInfo = NFLogicPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(request.user_id());
    if (pPlayerInfo == nullptr) {
        if (NFLogicPlayer::GetFreeCount(m_pObjPluginManager) > 0)
        {
            pPlayerInfo = NFLogicPlayerMgr::GetInstance(m_pObjPluginManager)->CreatePlayer(request.user_id());
            if (pPlayerInfo == NULL)
            {
                respone.set_result(proto_ff::ERR_CODE_WORLD_MAX_PLAYER_COUNT);
                NFLogError(NF_LOG_SYSTEMLOG, request.user_id(), "CreatePlayer Failed!, user id:{} Login Failed!", respone.user_id());
                return 0;
            }
        }
        else
        {
            respone.set_result(proto_ff::ERR_CODE_WORLD_MAX_PLAYER_COUNT);

            NFLogError(NF_LOG_SYSTEMLOG, request.user_id(), "player online count than max player count, user id:{} Login Failed!", request.user_id());
            return 0;
        }
    }
    CHECK_NULL(pPlayerInfo);

    pPlayerInfo->SetPlayerId(request.user_id());
    pPlayerInfo->SetProxyId(request.proxy_bus_id());
    pPlayerInfo->SetStatus(proto_ff::PLAYER_STATUS_OFFLINE);
    pPlayerInfo->SetLastDisconnectTime(NFTime::Now().UnixSec());

    if (pPlayerInfo->GetLogicId() <= 0)
    {
        NF_SHARE_PTR<NFServerData> pLogicData = FindModule<NFIMessageModule>()->GetSuitServerByServerType(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER, pPlayerInfo->GetPlayerId());
        if (pLogicData)
        {
            pPlayerInfo->SetLogicId(pLogicData->mServerInfo.bus_id());
        }
        else {
            respone.set_result(proto_ff::ERR_CODE_SYSTEM_TIMEOUT);

            NFLogError(NF_LOG_SYSTEMLOG, request.user_id(), "can't find the logic server, user id:{} Login Failed! ", request.user_id());
            return 0;
        }
    }

    if (pPlayerInfo->GetLogicId() <= 0 || FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_WORLD_SERVER, pPlayerInfo->GetLogicId()) == NULL)
    {
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_TIMEOUT);

        NFLogError(NF_LOG_SYSTEMLOG, request.user_id(), "can't find the logic server, user id:{} Login Failed! ", request.user_id());
        return 0;
    }

    //notify logic server player login
    proto_ff::Proto_WorldToLogicLoginReq reqLogicMsg;
    reqLogicMsg.set_user_id(pPlayerInfo->GetPlayerId());
    reqLogicMsg.set_game_id(pPlayerInfo->m_gameId);
    reqLogicMsg.set_room_id(pPlayerInfo->m_roomId);
    reqLogicMsg.set_proxy_bus_id(pPlayerInfo->GetProxyId());
    reqLogicMsg.mutable_ext_data()->CopyFrom(request.ext_data());
    reqLogicMsg.set_client_ip(request.client_ip());

    proto_ff::Proto_LogicToWorldLoginRsp rspLogicMsg;
    int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_WTL_PLAYER_LOGIN_REQ>(NF_ST_WORLD_SERVER, NF_ST_LOGIC_SERVER, pPlayerInfo->GetLogicId(), reqLogicMsg, rspLogicMsg);
    if (iRet != 0)
    {
        respone.set_result(iRet);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_WTL_PLAYER_LOGIN_REQ Failed! iRet:{}", GetErrorStr(iRet));
        return 0;
    }

    /**
     * @brief must find playerInfo again, the playerinfo maybe not exist
     */
    pPlayerInfo = NFLogicPlayerMgr::GetInstance(m_pObjPluginManager)->GetPlayer(request.user_id());
    if (pPlayerInfo == NULL)
    {
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_TIMEOUT);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find the player after the rpc");
        return 0;
    }

    if (rspLogicMsg.result() == 0)
    {
        pPlayerInfo->SetStatus(proto_ff::PLAYER_STATUS_ONLINE);

        respone.set_result(0);
        respone.set_user_id(pPlayerInfo->GetPlayerId());
        respone.set_game_id(pPlayerInfo->m_gameId);
        respone.set_room_id(pPlayerInfo->m_roomId);
        respone.set_logic_bus_id(pPlayerInfo->GetLogicId());
        respone.mutable_detail_data()->CopyFrom(rspLogicMsg.detail_data());
    }
    else
    {
        pPlayerInfo->SetStatus(proto_ff::PLAYER_STATUS_OFFLINE);
        pPlayerInfo->SetLastDisconnectTime(NFTime::Now().UnixSec());
        respone.set_user_id(pPlayerInfo->GetPlayerId());
        respone.set_result(rspLogicMsg.result());
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}


