// -------------------------------------------------------------------------
//    @FileName         :    NFWorldLoginModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldLoginModule
//
// -------------------------------------------------------------------------

#include <client_to_server.pb.h>
#include <common_msg.pb.h>
#include "NFWorldPlayerModule.h"

#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFWorldPlayer.h"
#include "NFWorldPlayerMgr.h"

NFCWorldPlayerModule::NFCWorldPlayerModule(NFIPluginManager *p) : NFIDynamicModule(p) {

}

NFCWorldPlayerModule::~NFCWorldPlayerModule() {
}

bool NFCWorldPlayerModule::Awake() {
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::CLIENT_TO_CENTER_LOGIN, this, &NFCWorldPlayerModule::OnHandleClientCenterLogin);

    return true;
}

bool NFCWorldPlayerModule::Execute()
{
	return true;
}

bool NFCWorldPlayerModule::OnDynamicPlugin()
{
	return true;
}

int NFCWorldPlayerModule::OnHandleClientCenterLogin(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::ClientLoginGateReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
	return 0;
}
