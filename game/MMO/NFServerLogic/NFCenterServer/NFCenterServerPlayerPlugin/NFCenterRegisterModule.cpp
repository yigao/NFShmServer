// -------------------------------------------------------------------------
//    @FileName         :    NFMatchPlayerModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFMatchPlayerModule
//
// -------------------------------------------------------------------------

#include "NFCenterRegisterModule.h"

NFCenterRegisterModule::NFCenterRegisterModule(NFIPluginManager *p) : NFMMODynamicModule(p)
{

}

NFCenterRegisterModule::~NFCenterRegisterModule()
{

}

bool NFCenterRegisterModule::Awake()
{
    return NFIModule::Awake();
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
    if (!m_pObjPluginManager->IsInited(NF_ST_WORLD_SERVER))
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

int NFCenterRegisterModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_WORLD_SERVER))
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
