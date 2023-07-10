// -------------------------------------------------------------------------
//    @FileName         :    NFWorldLoginModule.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldLoginModule
//
// -------------------------------------------------------------------------

#include "NFLogicPlayerModule.h"

#include "NFLogicPlayer.h"
#include "NFLogicPlayerMgr.h"
#include "ServerInternalCmd.pb.h"
#include "NFLogicCommon/NFLogicBindRpcService.h"

NFCLogicPlayerModule::NFCLogicPlayerModule(NFIPluginManager *p) : NFIDynamicModule(p) {

}

NFCLogicPlayerModule::~NFCLogicPlayerModule() {
}

bool NFCLogicPlayerModule::Awake() {
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////

    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::NF_WTL_PLAYER_LOGIN_REQ>(NF_ST_LOGIC_SERVER, this,
                                                                                     &NFCLogicPlayerModule::OnRpcServicePlayerLogin, true);
    //////////player enter game////////////////////////////////////
    return true;
}

bool NFCLogicPlayerModule::Execute()
{
	return true;
}

bool NFCLogicPlayerModule::OnDynamicPlugin()
{
	return true;
}

int NFCLogicPlayerModule::OnHandleClientMessage(uint64_t unLinkId, NFDataPackage &packet)
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

    switch (packet.nMsgId)
    {
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Client MsgId:{} Register, But Not Handle, Package:{}", packet.nMsgId, packet.ToString());
            break;
        }
    }
    return 0;
}


int NFCLogicPlayerModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage &packet)
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

    switch (packet.nMsgId)
    {
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Server MsgId:{} Register, But Not Handle, Package:{}", packet.nMsgId, packet.ToString());
            break;
        }
    }
    return 0;
}

int NFCLogicPlayerModule::OnRpcServicePlayerLogin(proto_ff::Proto_WorldToLogicLoginReq& request, proto_ff::Proto_LogicToWorldLoginRsp& respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}


