// -------------------------------------------------------------------------
//    @FileName         :    NFObServiceModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFObServiceModule
//
// -------------------------------------------------------------------------

#include "NFObServiceModule.h"

#include <NFLogicCommon/NFLogicShmTypeDefines.h>

#include "NFObService.h"

NFObServiceModule::NFObServiceModule(NFIPluginManager* p) : NFIDysServiceModule(p)
{
}

NFObServiceModule::~NFObServiceModule()
{
}

bool NFObServiceModule::Awake()
{
    for (uint32_t i = SNS_OB_SERVICE_NONE + 1; i < SNS_OB_SERVICE_MAX; ++i)
    {
        auto pPart = dynamic_cast<NFObService *>(FindModule<NFISharedMemModule>()->CreateObj(EOT_SNS_SERVICE_ID + i));
        if (pPart)
        {
            pPart->SetServiceId(i);
            pPart->RegisterMessage();
        }
    }
    return true;
}

bool NFObServiceModule::Execute()
{
    return NFIDysServiceModule::Execute();
}

bool NFObServiceModule::OnDynamicPlugin()
{
    return NFIDysServiceModule::OnDynamicPlugin();
}

int NFObServiceModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2)
{
    if (msgId < m_clientMsgToServiceMap.size() && m_clientMsgToServiceMap[msgId] != 0)
    {
        auto pService = dynamic_cast<NFObService *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_SNS_SERVICE_ID + m_clientMsgToServiceMap[msgId]));
        if (pService)
        {
            return pService->OnHandleClientMessage(msgId, packet);
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find service, msgId:{} serviceId:{}, drop the msg:{}", msgId, m_clientMsgToServiceMap[msgId], packet.ToString());
        }
    }
    return 0;
}

int NFObServiceModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2)
{
    if (msgId < m_serverMsgToServiceMap.size() && m_serverMsgToServiceMap[msgId] != 0)
    {
        auto pService = dynamic_cast<NFObService *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_SNS_SERVICE_ID + m_serverMsgToServiceMap[msgId]));
        if (pService)
        {
            return pService->OnHandleClientMessage(msgId, packet);
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find service, msgId:{} serviceId:{}, drop the msg:{}", msgId, m_serverMsgToServiceMap[msgId], packet.ToString());
        }
    }
    return 0;
}

int NFObServiceModule::OnHandleRpcMessage(uint32_t msgId, google::protobuf::Message& request, google::protobuf::Message& respone, uint64_t param1, uint64_t param2)
{
    if (msgId < m_rpcMsgToServiceMap.size() && m_rpcMsgToServiceMap[msgId].first != 0)
    {
        auto pService = dynamic_cast<NFObService *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_SNS_SERVICE_ID + m_rpcMsgToServiceMap[msgId].first));
        if (pService && m_rpcMsgToServiceMap[msgId].second)
        {
            return m_rpcMsgToServiceMap[msgId].second->run(pService, request, respone);
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find service, msgId:{} serviceId:{}, drop the msg", msgId, m_rpcMsgToServiceMap[msgId].first);
        }
    }
}
