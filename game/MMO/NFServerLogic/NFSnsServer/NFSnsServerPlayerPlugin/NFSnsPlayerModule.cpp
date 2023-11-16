// -------------------------------------------------------------------------
//    @FileName         :    NFCOnlineModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCOnlineModule
//
// -------------------------------------------------------------------------

#include "NFSnsPlayerModule.h"
#include "Cache/NFPlayerSimple.h"
#include "Cache/NFCacheMgr.h"
#include "NFServerComm/NFServerCommon/NFISnsServerModule.h"

NFCSnsPlayerModule::NFCSnsPlayerModule(NFIPluginManager *p) : NFMMODynamicModule(p)
{
}

NFCSnsPlayerModule::~NFCSnsPlayerModule()
{
}

bool NFCSnsPlayerModule::Awake()
{
    FindModule<NFISnsServerModule>()->SetCheckStoreServer(true);
    FindModule<NFISnsServerModule>()->SetCheckCenterServer(true);
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////

    ///////////world msg//////////////////////////////////////////////////////////

    ///////////logic msg//////////////////////////////////////////////////////////
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::LTS_LOGIN_RPC>(NF_ST_SNS_SERVER, this,
                                                                                   &NFCSnsPlayerModule::OnRpcServiceLogin, true);

    RegisterAppTask(NF_ST_SNS_SERVER, APP_INIT_DESC_STORE_LOAD, "SnsServer Load Desc Store", APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE);
    return true;
}

int
NFCSnsPlayerModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage)
{
    return 0;
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

int NFCSnsPlayerModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t playerId, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_SNS_SERVER))
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
    if (!m_pObjPluginManager->IsInited(NF_ST_SNS_SERVER))
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

int NFCSnsPlayerModule::OnRpcServiceLogin(proto_ff::LTSLoginReq& request, proto_ff::STLLoginRsp& respone)
{
    respone.set_ret(proto_ff::RET_SUCCESS);

    uint64_t cid = request.cid();

    NFPlayerSimple* pPlayerSimple = NFCacheMgr::Instance(m_pObjPluginManager)->QueryPlayerSimpleByRpc(cid);
    if (pPlayerSimple == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, cid, "QueryPlayerSimpleByRpc Failed, cid:{}", cid);
        respone.set_ret(proto_ff::RET_FAIL);
        return 0;
    }

    pPlayerSimple->SetProxyId(request.proxy_id());
    pPlayerSimple->SetLogicId(request.logic_id());
    pPlayerSimple->SetGameId(request.game_id());
    pPlayerSimple->SetIsOnline(true);

    NFPlayerDetail* pPlayerDetail = NFCacheMgr::Instance(m_pObjPluginManager)->QueryPlayerDetailByRpc(cid);
    if (pPlayerDetail == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, cid, "QueryPlayerDetailByRpc Failed, cid:{}", cid);
        respone.set_ret(proto_ff::RET_FAIL);
        return 0;
    }

    pPlayerDetail->SetUid(request.uid());
    pPlayerDetail->SetZid(request.zid());
    pPlayerDetail->SetProxyId(request.proxy_id());
    pPlayerDetail->SetLogicId(request.logic_id());
    pPlayerDetail->SetGameId(request.game_id());
    pPlayerDetail->SetIsOnline(true);
    pPlayerDetail->MarkDirty();

    int iRet = pPlayerSimple->OnLogin();
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "pPlayerSimple:{} OnLogin:{} Failed", cid, GetErrorStr(iRet));
        respone.set_ret(proto_ff::RET_FAIL);
        return 0;
    }

    iRet = pPlayerDetail->OnLogin();
    if (iRet != 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "pPlayerDetail:{} OnLogin:{} Failed", cid, GetErrorStr(iRet));
        respone.set_ret(proto_ff::RET_FAIL);
        return 0;
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}
