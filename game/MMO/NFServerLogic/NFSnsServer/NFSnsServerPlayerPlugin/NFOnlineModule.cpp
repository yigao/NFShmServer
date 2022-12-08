// -------------------------------------------------------------------------
//    @FileName         :    NFCOnlineModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCOnlineModule
//
// -------------------------------------------------------------------------

#include "NFOnlineModule.h"

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFLogicCommon/NFICommLogicModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "ServerInternal2.pb.h"
#include "ServerInternalCmd2.pb.h"
#include "Trans/NFTransRoleLogin.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "Cache/NFRoleSimple.h"
#include "Cache/NFCacheMgr.h"

NFCOnlineModule::NFCOnlineModule(NFIPluginManager *p) : NFIDynamicModule(p)
{
}

NFCOnlineModule::~NFCOnlineModule()
{
}

bool NFCOnlineModule::Awake()
{
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////
    //RegisterClientMessage(NF_ST_SNS_SERVER, proto_ff::CLIENT_LOGIN_REQ);

    ///////////world msg//////////////////////////////////////////////////////////
    RegisterServerMessage(NF_ST_SNS_SERVER, proto_ff::WORLD_TO_SNS_LOGIN_REQ);
    RegisterServerMessage(NF_ST_SNS_SERVER, proto_ff::WORLD_TO_OTHER_SERVER_NOTIFY_PLAYER_DISCONNECT);

    ///////////logic msg//////////////////////////////////////////////////////////
    return true;
}

bool NFCOnlineModule::Init()
{
    return true;
}

bool NFCOnlineModule::Execute()
{
    return true;
}

bool NFCOnlineModule::OnDynamicPlugin()
{
    return true;
}

int NFCOnlineModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
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

int NFCOnlineModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
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

int NFCOnlineModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
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

    switch (msgId)
    {
        case proto_ff::WORLD_TO_SNS_LOGIN_REQ:
        {
            OnHandleRoleLogin(msgId, packet, param1, param2);
            break;
        }
        case proto_ff::WORLD_TO_OTHER_SERVER_NOTIFY_PLAYER_DISCONNECT:
        {
            OnHandleRoleDisconnect(msgId, packet, param1, param2);
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

int NFCOnlineModule::OnHandleRoleDisconnect(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2n)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::WorldToOtherServerDisconnectNotify xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    NFRoleSimple* pRoleInfo = NFCacheMgr::GetInstance(m_pObjPluginManager)->GetRoleSimple(xData.roleid());
    if (pRoleInfo)
    {
        pRoleInfo->SetIsOnline(false);
        pRoleInfo->SetProxyId(0);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCOnlineModule::OnHandleRoleReconnect(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    return 0;
}

int NFCOnlineModule::OnHandleRoleLogin(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::WorldToSnsLoginReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    NFTransRoleLogin* pTrans = dynamic_cast<NFTransRoleLogin *>(FindModule<NFISharedMemModule>()->CreateTrans(EOT_SNS_TRANS_ROLE_LOGIN_ID));
    CHECK_EXPR(pTrans, -1, "CreateTrans NFTransRoleLogin failed!");
    int iRetCode = pTrans->OnRoleLogin(xData);
    CHECK_ERR_AND_FIN_TRANS(iRetCode, pTrans, "pTrans->OnRoleLogin failed");

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCOnlineModule::OnHandleRoleLogout(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}