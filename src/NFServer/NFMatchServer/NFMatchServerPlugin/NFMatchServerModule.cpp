// -------------------------------------------------------------------------
//    @FileName         :    NFCMatchServerModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2023-10-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFCMatchServerModule
//
// -------------------------------------------------------------------------

#include <NFServerComm/NFServerCommon/NFServerCommonDefine.h>
#include "NFMatchServerModule.h"

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "NFComm/NFPluginModule/NFIMonitorModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFServerComm/NFServerMessage/proto_svr_msg.pb.h"

NFCMatchServerModule::NFCMatchServerModule(NFIPluginManager* p): NFIMatchServerModule(p)
{
}

NFCMatchServerModule::~NFCMatchServerModule()
{
}

bool NFCMatchServerModule::Awake()
{
    BindServer();
	return true;
}

bool NFCMatchServerModule::Init()
{
    ConnectMasterServer();
    return true;
}

bool NFCMatchServerModule::Execute()
{
	return true;
}

bool NFCMatchServerModule::OnDynamicPlugin()
{
    FindModule<NFIMessageModule>()->CloseAllLink(NF_ST_MATCH_SERVER);
	return true;
}

int NFCMatchServerModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet)
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
