// -------------------------------------------------------------------------
//    @FileName         :    NFProxyServerModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFProxyServerPlugin
//
// -------------------------------------------------------------------------

#include "NFProxyServerModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFServerComm/NFServerCommon/NFIProxyClientModule.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFServerComm/NFServerMessage/proto_svr_msg.pb.h"
#include "NFServerComm/NFServerMessage/proto_svr_common.pb.h"

#define PROXY_SERVER_CONNECT_MASTER_SERVER "ProxyServer Connect MasterServer"

NFCProxyServerModule::NFCProxyServerModule(NFIPluginManager* p):NFIProxyServerModule(p)
{
    m_otherServerMsgHandle = NULL;
    m_clientMsgToServerMap.resize(NF_NET_MAX_MSG_ID);
}

NFCProxyServerModule::~NFCProxyServerModule()
{
}

bool NFCProxyServerModule::Awake()
{
    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_PROXY_SERVER);

    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER, this,
                                                       &NFCProxyServerModule::OnHandleServerRegisterFromProxyAgentServer);

    ///////////////////test other server send msg to proxy server////////////////////////////////////////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_PROXY_SERVER, proto_ff::NF_TEST_OTHER_SERVER_SEND_MSG_TO_PROXY_SERVER, this,
                                                       &NFCProxyServerModule::OnHandleTestOtherSendMsg);

    BindServer();
	return true;
}

bool NFCProxyServerModule::Init()
{
    ConnectMasterServer();

    return true;
}

int NFCProxyServerModule::OnHandleOtherWorkServerRegister(const proto_ff::ServerInfoReport& xData, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    CHECK_EXPR(xData.server_type() > NF_ST_NONE && xData.server_type() <= NF_ST_MAX, -1, "xData.server_type() > NF_ST_NONE && xData.server_type() <= NF_ST_MAX");
    auto pProxyAgentServer = FindModule<NFIMessageModule>()->GetServerByUnlinkId(NF_ST_PROXY_SERVER, unLinkId);
    CHECK_EXPR(pProxyAgentServer && pProxyAgentServer->mServerInfo.server_type() == NF_ST_PROXY_AGENT_SERVER, -1, "Not From NF_ST_PROXY_AGENT_SERVER");

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_PROXY_SERVER, xData.bus_id());
    if (pServerData == nullptr)
    {
        pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_PROXY_SERVER, xData.bus_id(), (NF_SERVER_TYPES)xData.server_type(), xData);
    }

    pServerData->mUnlinkId = unLinkId;
    pServerData->mServerInfo = xData;

    for(int i = 0; i < (int)xData.msg_id_size(); i++)
    {
        if (xData.msg_id(i) < (uint32_t)m_clientMsgToServerMap.size())
        {
            m_clientMsgToServerMap[xData.msg_id(i)] = xData.server_type();
        }
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "{} Register Proxy Server, serverName:{} busName:{}", xData.server_name(), xData.server_name(),
              xData.server_id());

    //test send msg
    //TestSendProxyMsgToOtherServer(xData.bus_id());
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCProxyServerModule::OnHandleProxyAgentServerRegister(const proto_ff::ServerInfoReport& xData, uint64_t unLinkId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    CHECK_EXPR(xData.server_type() == NF_ST_PROXY_AGENT_SERVER, -1, "xData.server_type() == NF_ST_PROXY_AGENT_SERVER");

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_PROXY_SERVER, xData.bus_id());
    if (pServerData == nullptr)
    {
        pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_PROXY_SERVER, xData.bus_id(), NF_ST_PROXY_AGENT_SERVER, xData);
    }

    pServerData->mUnlinkId = unLinkId;
    pServerData->mServerInfo = xData;
    FindModule<NFIMessageModule>()->CreateLinkToServer(NF_ST_PROXY_SERVER, xData.bus_id(), pServerData->mUnlinkId);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Proxy Agent Server:{} Register Proxy Server, serverName:{} serverId:{}", xData.server_name(), xData.server_name(),
              xData.server_id());

    RegisterProxyAgentServer(unLinkId);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}
bool NFCProxyServerModule::Execute()
{
	return true;
}

bool NFCProxyServerModule::OnDynamicPlugin()
{
	FindModule<NFIMessageModule>()->CloseAllLink(NF_ST_PROXY_SERVER);

	return true;
}

int NFCProxyServerModule::OnHandleServerRegisterFromProxyAgentServer(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    proto_ff::ServerInfoReportList xMsg;
    CLIENT_MSG_PROCESS_NO_PRINTF(packet, xMsg);

    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    CHECK_NULL(pConfig);

    for (int i = 0; i < xMsg.server_list_size(); ++i)
    {
        const proto_ff::ServerInfoReport& xData = xMsg.server_list(i);
        switch (xData.server_type())
        {
            case NF_SERVER_TYPES::NF_ST_PROXY_AGENT_SERVER:
            {
                OnHandleProxyAgentServerRegister(xData, unLinkId);
            }
                break;
            default:
                OnHandleOtherWorkServerRegister(xData, unLinkId);
                break;
        }
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");

    return 0;
}

int NFCProxyServerModule::OnHandleServerOtherMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    uint32_t srcBusId = packet.nSrcId;
    auto pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_PROXY_SERVER, srcBusId);
    if (pServerData)
    {
        if (m_otherServerMsgHandle)
        {
            m_otherServerMsgHandle(unLinkId, packet);
        }
        else {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "packet:{} not handle", packet.ToString());
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Can't find busId:{} busName:{} packet:{}", srcBusId, NFServerIDUtil::GetBusNameFromBusID(srcBusId), packet.ToString());
    }

    return 0;
}

int NFCProxyServerModule::RegisterProxyAgentServer(uint64_t unLinkId)
{
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
	if (pConfig)
	{
		proto_ff::ServerInfoReportList xMsg;
		proto_ff::ServerInfoReport* pData = xMsg.add_server_list();
        NFServerCommon::WriteServerInfo(pData, pConfig);
		pData->set_server_state(proto_ff::EST_NARMAL);

		FindModule<NFIMessageModule>()->Send(unLinkId, proto_ff::NF_SERVER_TO_SERVER_REGISTER, xMsg, 0);
	}
	NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
	return 0;
}

int NFCProxyServerModule::TestSendProxyMsgToOtherServer(uint64_t dstBusId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    CHECK_EXPR(pConfig != NULL, -1, "pConfig = NULL");

    proto_ff::Proto_TestSendProxyMsgToOtherServer xData;
    xData.set_server_id(pConfig->ServerId);
    xData.set_server_name(pConfig->ServerName);
    FindModule<NFIServerMessageModule>()->SendProxyMsgByBusId(NF_ST_PROXY_SERVER, dstBusId, proto_ff::NF_TEST_SEND_PROXY_MSG_TO_OTHER_SERVER_REQ, xData, 1, 2);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCProxyServerModule::OnHandleTestOtherSendMsg(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    proto_ff::Proto_TestOtherServerSendMsgToProxyServer xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

uint32_t NFCProxyServerModule::GetClientMsgServer(uint32_t msgId)
{
    if (msgId < (uint32_t)m_clientMsgToServerMap.size())
    {
        return m_clientMsgToServerMap[msgId];
    }
    return 0;
}
