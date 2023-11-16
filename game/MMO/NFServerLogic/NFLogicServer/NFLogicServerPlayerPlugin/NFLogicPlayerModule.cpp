// -------------------------------------------------------------------------
//    @FileName         :    NFWorldLoginModule.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldLoginModule
//
// -------------------------------------------------------------------------

#include "NFLogicPlayerModule.h"
#include "Player/NFPlayer.h"
#include "Player/NFPlayerMgr.h"
#include "DescStore/ConstantConstantDesc.h"
#include "NFServerComm/NFServerCommon/NFILogicServerModule.h"


NFCLogicPlayerModule::NFCLogicPlayerModule(NFIPluginManager *p) : NFMMODynamicModule(p)
{

}

NFCLogicPlayerModule::~NFCLogicPlayerModule()
{
}

bool NFCLogicPlayerModule::Awake()
{
    FindModule<NFILogicServerModule>()->SetCheckStoreServer(true);
    FindModule<NFILogicServerModule>()->SetCheckCenterServer(true);
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////

    //////////player enter game////////////////////////////////////
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::CLIENT_ENTER_GAME_RSP>(NF_ST_LOGIC_SERVER, this,
                                                                                   &NFCLogicPlayerModule::OnRpcServiceEnterGame, true);

    RegisterAppTask(NF_ST_LOGIC_SERVER, APP_INIT_DESC_STORE_LOAD, "LogicServer Load Desc Store", APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE);
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

int NFCLogicPlayerModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_LOGIC_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Logic Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Logic Server is Stopping, drop client msg:{}", packet.ToString());
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


int NFCLogicPlayerModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_LOGIC_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Logic Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Logic Server is Stopping, drop client msg:{}", packet.ToString());
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

int NFCLogicPlayerModule::OnRpcServiceEnterGame(proto_ff::ClientEnterGameReq& request, proto_ff::ClientEnterGameInternalRsp& respone, uint64_t worldId, uint64_t proxyId)
{
    uint64_t cid = request.cid();
    
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
    CHECK_NULL(pConfig);

    NFPlayer* pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(cid);
    if (pPlayer == NULL)
    {
        proto_ff::RoleDBData dbData;
        dbData.set_cid(cid);
        int iRet = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(NF_ST_LOGIC_SERVER, cid, dbData);
        if (iRet != 0)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, cid, "role:{}, GetRpcSelectObjService err:{} , enter game failed!", cid, GetErrorStr(iRet));
            respone.set_ret_code(proto_ff::RET_FAIL);
            return 0;
        }

        pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->CreatePlayer(cid, dbData);
        if (pPlayer == NULL)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, cid, "CreatePlayer:{} Failed , enter game failed!", cid, GetErrorStr(iRet));
            respone.set_ret_code(proto_ff::RET_FAIL);
            return 0;
        }
    }

    pPlayer->SetProxyId(proxyId);
    pPlayer->SetWorldId(worldId);
    pPlayer->SetSnsId(0);
    
    proto_ff::NotifyPlayerEnterServer notify;
    notify.set_uid(pPlayer->GetUid());
    notify.set_cid(pPlayer->Cid());
    notify.set_logic_id(pConfig->GetBusId());
    notify.set_sns_id(pPlayer->GetSnsId());
    pPlayer->SendMsgToWorldServer(proto_ff::STS_NOTIFY_ROLE_ENTER_SERVER, notify);

    /**
     * 登陆前处理一些计算
     */
    pPlayer->OnPrevLogin();

    /**
     * 登陆处理
     */
    pPlayer->OnLogin();

    /**
     * 登陆sns
     */
    int iRet = pPlayer->LoginSns();
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, cid, "role:{} LoginSns Failed", cid);
        respone.set_ret_code(iRet);
        return 0;
    }

    /**
     * 进入游戏
     */
    iRet = pPlayer->EnterGame();
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, cid, "role:{} Enter Game Failed", cid);
        respone.set_ret_code(iRet);
        return 0;
    }
    
    pPlayer->NotifyPlayerInfo();
    
    respone.set_ret_code(proto_ff::RET_SUCCESS);
    respone.set_game_id(pPlayer->GetGameId());
    respone.set_logic_id(pConfig->GetBusId());
    respone.set_sns_id(pPlayer->GetSnsId());

    return 0;
}

