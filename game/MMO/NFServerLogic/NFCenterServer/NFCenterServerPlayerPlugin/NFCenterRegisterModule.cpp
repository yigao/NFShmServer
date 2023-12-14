// -------------------------------------------------------------------------
//    @FileName         :    NFMatchPlayerModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFMatchPlayerModule
//
// -------------------------------------------------------------------------

#include "NFCenterRegisterModule.h"

#include <NFServerComm/NFServerCommon/NFICenterServerModule.h>

#include "Server/NFServerAddrMgr.h"

NFCenterRegisterModule::NFCenterRegisterModule(NFIPluginManager *p) : NFMMODynamicModule(p)
{

}

NFCenterRegisterModule::~NFCenterRegisterModule()
{

}

bool NFCenterRegisterModule::Awake()
{
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::STS_MAP_REG_RPC>(NF_ST_CENTER_SERVER, this,
                                                                              &NFCenterRegisterModule::OnRpcServiceMapReg);
    return true;
}

bool NFCenterRegisterModule::Execute()
{
    return NFIModule::Execute();
}

bool NFCenterRegisterModule::OnDynamicPlugin()
{
    return NFIModule::OnDynamicPlugin();
}

int NFCenterRegisterModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage)
{
    return NFIDynamicModule::OnExecute(serverType, nEventID, bySrcType, nSrcID, pMessage);
}

int NFCenterRegisterModule::OnHandleClientMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_CENTER_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Center Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Center Server is Stopping, drop client msg:{}", packet.ToString());
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

int NFCenterRegisterModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_CENTER_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Center Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Center Server is Stopping, drop client msg:{}", packet.ToString());
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

int NFCenterRegisterModule::OnRpcServiceMapReg(proto_ff::RegisterMapInfoReq& request, proto_ff::ReigsterMapInfoRsp& respone)
{
    uint32_t busId = request.bus_id();
    for(int i = 0; i < (int)request.map_id_size(); i++)
    {
        uint32_t mapId = request.map_id(i);
        int iRet = NFServerAddrMgr::Instance(m_pObjPluginManager)->AddMapAddr(mapId, busId);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GameServer:{} Register Map:{} To Center Server {}", NFServerIDUtil::GetBusNameFromBusID(busId), mapId, iRet == 0 ? "Success":"Failed");
    }

    respone.set_ret_code(proto_ff::RET_SUCCESS);
    return 0;
}
