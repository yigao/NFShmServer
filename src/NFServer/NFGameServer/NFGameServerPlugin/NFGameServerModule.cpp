// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include <NFServerComm/NFServerCommon/NFServerCommonDefine.h>
#include "NFGameServerModule.h"

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFServerComm/NFServerMessage/proto_svr_msg.pb.h"


NFCGameServerModule::NFCGameServerModule(NFIPluginManager* p):NFIGameServerModule(p)
{
}

NFCGameServerModule::~NFCGameServerModule()
{
}

bool NFCGameServerModule::Awake()
{
    SetCheckWorldServer(true);
    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_GAME_SERVER, 10000);

    ////////////////test other server msg///////////////////////////////////////////////
    RegisterServerMessage(NF_ST_GAME_SERVER, proto_ff::NF_TEST_SEND_PROXY_MSG_TO_OTHER_SERVER_REQ);
    RegisterServerMessage(NF_ST_GAME_SERVER, proto_ff::NF_TEST_WORLD_SERVER_MSG_TO_OTHER_SERVER_REQ);

    BindServer();
	return true;
}

int NFCGameServerModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    int retCode = 0;
    switch (packet.nMsgId)
    {
        /**
         * @brief proxy server msg
         */
        case proto_ff::NF_TEST_SEND_PROXY_MSG_TO_OTHER_SERVER_REQ:
            retCode = OnTestProxyServerMsg(unLinkId, packet);
            break;

        case proto_ff::NF_TEST_WORLD_SERVER_MSG_TO_OTHER_SERVER_REQ:
            retCode = OnHandleTestWorldServerMsg(unLinkId, packet);
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

bool NFCGameServerModule::Init()
{
    ConnectMasterServer();
    return true;
}

bool NFCGameServerModule::Execute()
{
    TestOtherServerToWorldServer();
	return true;
}

bool NFCGameServerModule::OnDynamicPlugin()
{
    FindModule<NFIMessageModule>()->CloseAllLink(NF_ST_GAME_SERVER);
	return true;
}

int NFCGameServerModule::OnTestProxyServerMsg(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    proto_ff::Proto_TestSendProxyMsgToOtherServer xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
    if (pConfig)
    {
        proto_ff::Proto_TestOtherServerSendMsgToProxyServer xData;
        xData.set_server_id(pConfig->ServerId);
        xData.set_server_name(pConfig->ServerName);
        FindModule<NFIServerMessageModule>()->SendMsgToProxyServer(NF_ST_GAME_SERVER, packet.nSrcId, proto_ff::NF_TEST_OTHER_SERVER_SEND_MSG_TO_PROXY_SERVER, xData, 3, 4);
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFCGameServerModule::TestOtherServerToWorldServer()
{
#ifdef TEST_SERVER_SEND_MSG
    if (!m_pObjPluginManager->IsInited())
    {
        return 0;
    }

    static int req = 0;
    for(int i = 0; i < TEST_SERVER_SEND_MSG_FRAME_COUNT; i++)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
        NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
        CHECK_EXPR(pConfig != NULL, -1, "pConfig = NULL");

        proto_ff::Proto_TestOtherServerToWorldServer xData;
        xData.set_server_id(pConfig->ServerId);
        xData.set_server_name(pConfig->ServerName);
        xData.set_seq(++req);
        FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_GAME_SERVER, proto_ff::NF_TEST_OTHER_SERVER_MSG_TO_WORLD_SERVER_REQ, xData, 1, 2);
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    }
#endif

    if (!m_pObjPluginManager->IsInited())
    {
        return 0;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        return 0;
    }

    bool flag = false;
    if (flag == false)
    {
        flag = true;
        FindModule<NFICoroutineModule>()->MakeCoroutine([this](){
            NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
            proto_ff::RpcRequestGetServerInfo request;
            request.set_server_id(pConfig->ServerId);
            proto_ff::ServerInfoReport respone;
            for(int i = 0; i < TEST_SERVER_SEND_MSG_FRAME_COUNT; i++)
            {
                int iRet = FindModule<NFIMessageModule>()->GetRpcService(NF_ST_GAME_SERVER, NF_ST_WORLD_SERVER, 0, proto_ff::NF_RPC_SERVICE_GET_SERVER_INFO_REQ, request, respone);
                if (iRet != 0)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_RPC_SERVICE_GET_SERVER_INFO_REQ Failed!");
                    return;
                }
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcService respone:{}", respone.DebugString());
            }
        });

        for(int i = 0; i < TEST_SERVER_SEND_MSG_FRAME_COUNT; i++)
        {
            NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(m_serverType);
            proto_ff::RpcRequestGetServerInfo request;
            request.set_server_id(pConfig->ServerId);
            FindModule<NFIMessageModule>()->GetRpcService(NF_ST_GAME_SERVER, NF_ST_WORLD_SERVER, 0, proto_ff::NF_RPC_SERVICE_GET_SERVER_INFO_REQ, request, [](int rpcRetCode, proto_ff::ServerInfoReport& respone){
                if (rpcRetCode != 0)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService proto_ff::NF_RPC_SERVICE_GET_SERVER_INFO_REQ Failed!");
                    return;
                }
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GetRpcService respone:{}", respone.DebugString());
            });
        }
        return 0;
    }

    return 0;
}

int NFCGameServerModule::OnHandleTestWorldServerMsg(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");

    static int last_seq = -1;

    proto_ff::Proto_TestSendWorldMsgToOtherServer xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    if (last_seq < 0)
    {
        last_seq = xMsg.seq();
    }
    else {
        NFLogErrorIf(last_seq + 1 != xMsg.seq(), NF_LOG_SYSTEMLOG, 0, "world server send seq error, last_seq:{} seq:{}", last_seq, xMsg.seq());
        last_seq = xMsg.seq();
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}
