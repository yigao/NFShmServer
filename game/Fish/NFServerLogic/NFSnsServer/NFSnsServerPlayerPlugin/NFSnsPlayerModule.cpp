﻿// -------------------------------------------------------------------------
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

int NFCSnsPlayerModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
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
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
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

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}