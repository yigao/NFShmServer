// -------------------------------------------------------------------------
//    @FileName         :    NFLogicRoomModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicRoomModule
//
// -------------------------------------------------------------------------

#include "NFLogicRoomModule.h"

NFLogicRoomModule::NFLogicRoomModule(NFIPluginManager* p):NFFishDynamicModule(p)
{

}

NFLogicRoomModule::~NFLogicRoomModule()
{
}

bool NFLogicRoomModule::Awake()
{
    return true;
}

bool NFLogicRoomModule::Execute()
{
    return NFIModule::Execute();
}

bool NFLogicRoomModule::OnDynamicPlugin()
{
    return NFIModule::OnDynamicPlugin();
}

int NFLogicRoomModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_LOGIC_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Logic Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Logic Server is Stopping, drop client msg:{}", packet.ToString());
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

int NFLogicRoomModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_LOGIC_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Logic Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Logic Server is Stopping, drop client msg:{}", packet.ToString());
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


