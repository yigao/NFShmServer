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
    return true;
}

bool NFCWebServerModule::OnDynamicPlugin()
{
    FindModule<NFIMessageModule>()->CloseAllLink(NF_ST_WEB_SERVER);
    return true;
}

int NFCWebServerModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet)
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