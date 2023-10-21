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
    /////////////////test other server msg///////////////////////////////////////
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
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    CHECK_EXPR(xData.server_type() == NF_ST_LOGIC_SERVER, -1, "xData.server_type() == NF_ST_LOGIC_SERVER");

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id());
    if (!pServerData)
    {
        pServerData = FindModule<NFIMessageModule>()->CreateServerByServerId(NF_ST_WORLD_SERVER, xData.bus_id(), NF_ST_LOGIC_SERVER, xData);
    }

    pServerData->mServerInfo = xData;
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}