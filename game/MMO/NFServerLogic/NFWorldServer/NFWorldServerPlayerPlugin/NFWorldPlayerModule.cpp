// -------------------------------------------------------------------------
//    @FileName         :    NFWorldLoginModule.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldLoginModule
//
// -------------------------------------------------------------------------

#include "NFWorldPlayerModule.h"
#include "NFWorldSession.h"
#include "NFWorldSessionMgr.h"
#include "NFWorldAccount.h"
#include "NFWorldAccountMgr.h"


NFCWorldPlayerModule::NFCWorldPlayerModule(NFIPluginManager *p) : NFMMODynamicModule(p)
{

}

NFCWorldPlayerModule::~NFCWorldPlayerModule()
{
}

bool NFCWorldPlayerModule::Awake()
{

    ////////////////game room register//////////////////////////////
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////

    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::CLIENT_LOGIN_REQ>(NF_ST_WORLD_SERVER, this,
                                                                                     &NFCWorldPlayerModule::OnRpcServicePlayerLogin, true);

    /////////////////////////////////server msg, player disconnect logout////////////////////////////////////////////

    //////////player enter game////////////////////////////////////


    return true;
}

int NFCWorldPlayerModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID,
                                    const google::protobuf::Message *pMessage)
{
    return 0;
}

bool NFCWorldPlayerModule::Execute()
{
    return true;
}

bool NFCWorldPlayerModule::OnDynamicPlugin()
{
    return true;
}

int NFCWorldPlayerModule::OnHandleClientMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_WORLD_SERVER))
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


int NFCWorldPlayerModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_WORLD_SERVER))
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

int NFCWorldPlayerModule::OnRpcServicePlayerLogin(proto_ff::ClientLoginReq& request, proto_ff::ClientLoginRsp& respone, uint64_t proxyId, uint64_t clientId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    uint64_t uid = request.uid();
    uint32_t loginzid = request.zid();
    uint32_t chanid = request.channel_id();

    NFWorldAccount *pAccountInfo = NFWorldAccountMgr::GetInstance(m_pObjPluginManager)->GetAccount(uid);
    if (pAccountInfo == nullptr)
    {
        pAccountInfo = NFWorldAccountMgr::GetInstance(m_pObjPluginManager)->CreateAccount(uid);
        if (pAccountInfo == NULL)
        {
            respone.set_ret(proto_ff::RET_FAIL);
            NFLogError(NF_LOG_SYSTEMLOG, uid, "CreatePlayer Failed! the account full,  user id:{} Login Failed!", uid);
            return 0;
        }
    }

    uint64_t oldClientId = pAccountInfo->GetClientId();

    NFWorldSession *pOldSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(oldClientId);
    bool isNeedLeaveScene = false;
    if (pOldSession != NULL)
    {
        if (oldClientId == clientId)
        {
            respone.set_ret(proto_ff::RET_FAIL);
            return 0;
        }

        NFLogError(NF_LOG_SYSTEMLOG, uid, "same account login, tick old client, uid:{} cid:{} old proxy id:{} old client id:{}", pAccountInfo->GetUid(), pAccountInfo->GetCid(), pAccountInfo->GetProxyId(), pAccountInfo->GetClientId());

        int ret = NotifyGateLeave(pOldSession->GetProxyId(), pOldSession->GetClientId(), proto_ff::LOGOUT_REPLACE);
        //rpc check
        pAccountInfo = NFWorldAccountMgr::GetInstance(m_pObjPluginManager)->GetAccount(uid);
        CHECK_NULL(pAccountInfo);
        if (ret != 0)
        {
            respone.set_ret(proto_ff::RET_FAIL);
            return 0;
        }

        NFWorldSessionMgr::Instance(m_pObjPluginManager)->DeleteSession(pOldSession);

        //删除 uid和 clientid的映射
        pAccountInfo->SetProxyId(0);
        pAccountInfo->SetClientId(0);

        //handle the role
    }

    NFWorldSession* pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->GetSession(clientId);
    if (pSession == nullptr)
    {
        pSession = NFWorldSessionMgr::Instance(m_pObjPluginManager)->CreateSession(clientId);
        if (pSession == nullptr)
        {
            respone.set_ret(proto_ff::RET_FAIL);
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateSession failed, the link is full");
            return 0;
        }
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "CreateSession Success, proxyId:{} clientId:{}", proxyId, clientId);
    }

    pSession->SetProxyId(proxyId);
    pSession->SetClientId(clientId);
    pSession->SetUid(uid);

    pAccountInfo->SetProxyId(proxyId);
    pAccountInfo->SetClientId(clientId);
    pAccountInfo->SetCid(0);
    pAccountInfo->SetIsDisconnect(false);
    pAccountInfo->SetStatus(proto_ff::PLAYER_STATUS_ONLINE);

    //FindModule<NFIServerMessageModule>()->GetRpcSelectService(NF_ST_WORLD_SERVER, NF_ST_STORE_SERVER, )

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCWorldPlayerModule::NotifyGateLeave(uint32_t proxyId, uint64_t clientId, proto_ff::LOGOUT_TYPE leaveFlag)
{
    proto_ff::NotifyGateLeaveGame2 notify;
    notify.set_clientid(clientId);
    notify.set_leave_flag(leaveFlag);
    proto_ff::EmptyMessage respone;
    return FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NOTIFY_GATE_LEAVE_GAME>(NF_ST_WORLD_SERVER, NF_ST_PROXY_SERVER, proxyId, notify, respone);
}