// -------------------------------------------------------------------------
//    @FileName         :    NFCLogicServerModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCLogicServerModule
//
// -------------------------------------------------------------------------

#include <NFServerComm/NFServerCommon/NFServerCommonDefine.h>
#include "NFLogicServerModule.h"

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFServerComm/NFServerMessage/proto_svr_msg.pb.h"


#define LOGIC_SERVER_CONNECT_MASTER_SERVER "LogicServer Connect MasterServer"
#define LOGIC_SERVER_CONNECT_ROUTEAGENT_SERVER "LogicServer Connect RouteAgentServer"
#define LOGIC_SERVER_CHECK_STORE_SERVER "LogicServer CHECK StoreServer"

#define LOGIC_SERVER_REPORT_TO_MASTER_SERVER_TIMER_ID 1
#define LOGIC_SERVER_TEST_WORLD_SERVER_TIMER_ID 2
#define LOGIC_SERVER_SERVER_DEAD_TIMER_ID 3

NFCLogicServerModule::NFCLogicServerModule(NFIPluginManager* p):NFILogicServerModule(p)
{
}

NFCLogicServerModule::~NFCLogicServerModule()
{
}

bool NFCLogicServerModule::Awake()
{
    FindModule<NFINamingModule>()->InitAppInfo(NF_ST_LOGIC_SERVER);

    ////////////////test other server msg///////////////////////////////////////////////
    RegisterServerMessage(NF_ST_LOGIC_SERVER, proto_ff::NF_TEST_WORLD_SERVER_MSG_TO_OTHER_SERVER_REQ);

    BindServer();
    return true;
}

int NFCLogicServerModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet)
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

bool NFCLogicServerModule::Init()
{
    ConnectMasterServer();
    return true;
}

bool NFCLogicServerModule::Execute()
{
    TestOtherServerToWorldServer();
    return true;
}

bool NFCLogicServerModule::OnDynamicPlugin()
{
    FindModule<NFIMessageModule>()->CloseAllLink(NF_ST_LOGIC_SERVER);
    return true;
}

int NFCLogicServerModule::TestOtherServerToWorldServer()
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
        NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
        CHECK_EXPR(pConfig != NULL, -1, "pConfig = NULL");

        proto_ff::Proto_TestOtherServerToWorldServer xData;
        xData.set_server_id(pConfig->ServerId);
        xData.set_server_name(pConfig->ServerName);
        xData.set_seq(++req);
        FindModule<NFIServerMessageModule>()->SendMsgToWorldServer(NF_ST_LOGIC_SERVER, proto_ff::NF_TEST_OTHER_SERVER_MSG_TO_WORLD_SERVER_REQ, xData, 1, 2);
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    }
#endif

    return 0;
}

int NFCLogicServerModule::OnHandleTestWorldServerMsg(uint64_t unLinkId, NFDataPackage& packet)
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
