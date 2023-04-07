// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include <NFServerComm/NFServerCommon/NFServerCommonDefine.h>
#include "NFWorldServerModule.h"

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFServerComm/NFServerMessage/proto_svr_msg.pb.h"

NFCWorldServerModule::NFCWorldServerModule(NFIPluginManager *p) : NFIWorldServerModule(p)
{
}

NFCWorldServerModule::~NFCWorldServerModule()
{
}

bool NFCWorldServerModule::Awake()
{
    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_WORLD_SERVER);

    /////////////////test other server msg///////////////////////////////////////
    RegisterServerMessage(NF_ST_WORLD_SERVER, proto_ff::NF_TEST_OTHER_SERVER_MSG_TO_WORLD_SERVER_REQ);

    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_RPC_SERVICE_GET_SERVER_INFO_REQ>(NF_ST_WORLD_SERVER, this, &NFCWorldServerModule::OnRpcServiceGetServerInfo, true);
    BindServer();
    return true;
}

bool NFCWorldServerModule::Init()
{
    ConnectMasterServer();
    return true;
}

bool NFCWorldServerModule::Execute()
{
    return true;
}

bool NFCWorldServerModule::OnDynamicPlugin()
{
    FindModule<NFIMessageModule>()->CloseAllLink(NF_ST_WORLD_SERVER);
    return true;
}

int NFCWorldServerModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    int retCode = 0;
    switch (packet.nMsgId)
    {
        case proto_ff::NF_TEST_OTHER_SERVER_MSG_TO_WORLD_SERVER_REQ:
            retCode = OnHandleTestOtherServerMsg(unLinkId, packet);
            break;
        default:
            NFLogError(NF_LOG_SYSTEMLOG, 0, "msg:({}) not handle", packet.ToString());
            break;
    }

    if (retCode != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "msg:({}) handle exist error", packet.ToString());
    }
    return 0;
}

int NFCWorldServerModule::OnHandleOtherServerReportFromMasterServer(const proto_ff::ServerInfoReport &xData)
{
    switch (xData.server_type())
    {
        case NF_SERVER_TYPES::NF_ST_LOGIC_SERVER:
        {
            OnHandleLogicReport(xData);
        }
        break;
        default:
            break;
    }
    return 0;
}

int NFCWorldServerModule::OnHandleLogicReport(const proto_ff::ServerInfoReport& xData)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    CHECK_EXPR(xData.server_type() == NF_ST_LOGIC_SERVER, -1, "xData.server_type() == NF_ST_LOGIC_SERVER");

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id());
    if (!pServerData)
    {
        pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id(), NF_ST_LOGIC_SERVER, xData);
    }

    pServerData->mServerInfo = xData;
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCWorldServerModule::OnHandleTestOtherServerMsg(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    proto_ff::Proto_TestOtherServerToWorldServer xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    static std::unordered_map<std::string, int32_t> serverIdMap;
    auto iter = serverIdMap.find(xMsg.server_id());
    if (iter == serverIdMap.end())
    {
        serverIdMap[xMsg.server_id()] = xMsg.seq();
    } else
    {
        NFLogErrorIf(iter->second + 1 != xMsg.seq(), NF_LOG_SYSTEMLOG, 0, "serverId:{} serverName:{} last_seq:{} seq:{} Error", xMsg.server_id(),
                     xMsg.server_name(), iter->second, xMsg.seq());
        iter->second = xMsg.seq();
    }

    NFLogInfoIf(xMsg.seq() % 500000 == 0, NF_LOG_SYSTEMLOG, 0, "serverId:{} serverName:{} send seq:{} msg", xMsg.server_id(), xMsg.server_name(),
                xMsg.seq());

    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    if (pConfig)
    {
        proto_ff::Proto_TestSendWorldMsgToOtherServer xData;
        xData.set_server_id(pConfig->ServerId);
        xData.set_server_name(pConfig->ServerName);
        xData.set_seq(xMsg.seq());
        FindModule<NFIMessageModule>()->SendMsgToServer(NF_ST_WORLD_SERVER, NF_ST_NONE, 0, packet.nSrcId,
                                                        proto_ff::NF_TEST_WORLD_SERVER_MSG_TO_OTHER_SERVER_REQ, xData, 3, 4);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCWorldServerModule::OnRpcServiceGetServerInfo(proto_ff::RpcRequestGetServerInfo& request, proto_ff::ServerInfoReport& respone)
{
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "OnRpcServiceGetServerInfo request:{}", request.DebugString());

    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
    if (pConfig)
    {
        NFServerCommon::WriteServerInfo(&respone, pConfig);
    }
    return 0;
}