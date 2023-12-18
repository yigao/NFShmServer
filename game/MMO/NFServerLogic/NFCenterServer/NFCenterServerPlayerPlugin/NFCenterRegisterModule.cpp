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

NFCenterRegisterModule::NFCenterRegisterModule(NFIPluginManager* p) : NFMMODynamicModule(p)
{

}

NFCenterRegisterModule::~NFCenterRegisterModule()
{

}

bool NFCenterRegisterModule::Awake()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_CENTER_SERVER);
    CHECK_NULL(pConfig);
    
    FindModule<NFIMessageModule>()->AddRpcService<proto_ff::STS_MAP_REG_RPC>(NF_ST_CENTER_SERVER, this, &NFCenterRegisterModule::OnRpcServiceMapReg);
    
    if (pConfig->CrossServer == false)
    {
        Subscribe(NF_ST_CENTER_SERVER, proto_ff::NF_EVENT_SERVER_REPORT_EVENT, NF_ST_CENTER_SERVER, pConfig->GetBusId(), __FUNCTION__);
    }
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

int NFCenterRegisterModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
{
    switch (nEventID)
    {
        case proto_ff::NF_EVENT_SERVER_REPORT_EVENT:
        {
            const proto_ff::ServerInfoReport* pEvent = dynamic_cast< const proto_ff::ServerInfoReport*>(pMessage);
            if (pEvent && pEvent->is_cross_server() && pEvent->server_type() == NF_ST_CENTER_SERVER)
            {
                RegisterCrossMap();
            }
            break;
        }
    }
    return 0;
}

int NFCenterRegisterModule::OnHandleClientMessage(uint64_t unLinkId, NFDataPackage& packet)
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

int NFCenterRegisterModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet)
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
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_CENTER_SERVER);
    CHECK_NULL(pConfig);
    
    uint32_t busId = request.bus_id();
    for (int i = 0; i < (int)request.map_id_size(); i++)
    {
        uint32_t mapId = request.map_id(i);
        uint32_t zid = NFServerIDUtil::GetZoneID(busId);
        int iRet = NFServerAddrMgr::Instance(m_pObjPluginManager)->AddMapAddr(mapId, busId, zid, pConfig->CrossServer);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GameServer:{} Register Map:{} To Center Server:{}({}) {}", NFServerIDUtil::GetBusNameFromBusID(busId), mapId, pConfig->ServerName, pConfig->ServerId, iRet == 0 ? "Success" : "Failed");
    }
    
    respone.set_ret_code(proto_ff::RET_SUCCESS);
    
    //RegisterCrossMap();
    return 0;
}

int NFCenterRegisterModule::RegisterCrossMap()
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
    CHECK_NULL(pConfig);
    
    proto_ff::RegisterCrossMapInfoReq  req;
    NFServerAddrMgr::Instance(m_pObjPluginManager)->GetAllMapInfo(req, pConfig->GetZoneId());
    
    int rpcRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::STS_CROSS_MAP_REG_RPC>(NF_ST_CENTER_SERVER, NF_ST_CENTER_SERVER, CROSS_ROUTE, req, [this](int rpcRetCode, proto_ff::ReigsterCrossMapInfoRsp &respone){
        if (rpcRetCode != proto_ff::RET_SUCCESS)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService<proto_ff::STS_CROSS_MAP_REG_RPC> failed, rpcError:{}", GetErrorStr(rpcRetCode));
            return;
        }
        
        if (respone.ret_code() != proto_ff::RET_SUCCESS)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService<proto_ff::STS_CROSS_MAP_REG_RPC> failed:{}, register failed", GetErrorStr(respone.ret_code()));
            return;
        }
    }, 0, 0);
    
    if (rpcRet == INVALID_ID)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetRpcService<proto_ff::STS_MAP_REG_RPC> error");
        return -1;
    }
    return 0;
}