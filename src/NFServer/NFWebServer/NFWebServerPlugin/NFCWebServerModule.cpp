// -------------------------------------------------------------------------
//    @FileName         :    NFCWebServerModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCWebServerModule.cpp
//
// -------------------------------------------------------------------------

#include <NFServerComm/NFServerCommon/NFServerCommonDefine.h>
#include "NFCWebServerModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFServerComm/NFServerMessage/proto_svr_msg.pb.h"

NFCWebServerModule::NFCWebServerModule(NFIPluginManager* p):NFIWebServerModule(p)
{
}

NFCWebServerModule::~NFCWebServerModule()
{
}

bool NFCWebServerModule::Awake() {
    SetCheckStoreServer(false);

    ////////////////test other server msg///////////////////////////////////////////////
    RegisterServerMessage(NF_ST_WEB_SERVER, proto_ff::NF_TEST_WORLD_SERVER_MSG_TO_OTHER_SERVER_REQ);

    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WEB_SERVER);
    if (pConfig) {
        std::string httpUrl = NF_FORMAT("http://{}:{}", pConfig->ServerIp, pConfig->HttpPort);
        uint64_t ret = FindModule<NFIMessageModule>()->BindServer(NF_ST_WEB_SERVER, httpUrl, pConfig->NetThreadNum, pConfig->MaxConnectNum, PACKET_PARSE_TYPE_INTERNAL);
        if (ret == 0)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "web server listen http failed!, serverId:{}, ip:{}, httpport:{}", pConfig->ServerId, pConfig->ServerIp, pConfig->HttpPort);
            return false;
        }

        BindServer();
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "I Can't get the web Server config!");
        return false;
    }

    return true;
}

bool NFCWebServerModule::Init()
{
    ConnectMasterServer();
    return true;
}

bool NFCWebServerModule::Execute()
{
    TestOtherServerToWorldServer();
    return true;
}

bool NFCWebServerModule::OnDynamicPlugin()
{
    FindModule<NFIMessageModule>()->CloseAllLink(NF_ST_WEB_SERVER);
    return true;
}

int NFCWebServerModule::TestOtherServerToWorldServer()
{
#ifdef TEST_SERVER_SEND_MSG
    if (!m_pObjPluginManager->IsInited())
    {
        return 0;
    }

    static int req = 0;
    for(int i = 0; i < TEST_SERVER_SEND_MSG_FRAME_COUNT; i++)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
        NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WEB_SERVER);
        CHECK_EXPR(pConfig != NULL, -1, "pConfig = NULL");

        proto_ff::Proto_TestOtherServerToWorldServer xData;
        xData.set_server_id(pConfig->ServerId);
        xData.set_server_name(pConfig->ServerName);
        xData.set_seq(++req);
        FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_WEB_SERVER, proto_ff::NF_TEST_OTHER_SERVER_MSG_TO_WORLD_SERVER_REQ, xData, 1, 2);
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    }
#endif

    return 0;
}

int NFCWebServerModule::OnHandleTestWorldServerMsg(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

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

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCWebServerModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    int retCode = 0;
    switch (packet.nMsgId)
    {
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