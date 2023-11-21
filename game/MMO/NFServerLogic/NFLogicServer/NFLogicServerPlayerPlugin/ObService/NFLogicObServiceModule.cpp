// -------------------------------------------------------------------------
//    @FileName         :    NFLogicObServiceModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicObServiceModule
//
// -------------------------------------------------------------------------

#include "NFLogicObServiceModule.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicObService.h"

NFLogicObServiceModule::NFLogicObServiceModule(NFIPluginManager *p):NFIDysServiceModule(p)
{

}

NFLogicObServiceModule::~NFLogicObServiceModule()
{
}

bool NFLogicObServiceModule::Awake()
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
    NF_ASSERT(pConfig);
    
    for (uint32_t i = LOGIC_OB_SERVICE_NONE + 1; i < LOGIC_OB_SERVICE_MAX; ++i)
    {
        auto pService = dynamic_cast<NFLogicObService *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_LOGIC_SERVICE_ID + i));
        if (pService)
        {
            pService->RegisterMessage();
        }
    }
    
    return true;}

bool NFLogicObServiceModule::Execute()
{
    return NFIModule::Execute();
}

bool NFLogicObServiceModule::OnDynamicPlugin()
{
    return NFIModule::OnDynamicPlugin();
}

int NFLogicObServiceModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (msgId < m_clientMsgToServiceMap.size() && m_clientMsgToServiceMap[msgId] != 0)
    {
        auto pService = dynamic_cast<NFLogicObService *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_LOGIC_SERVICE_ID + m_clientMsgToServiceMap[msgId]));
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

int NFLogicObServiceModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (msgId < m_serverMsgToServiceMap.size() && m_serverMsgToServiceMap[msgId] != 0)
    {
        auto pService = dynamic_cast<NFLogicObService *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_LOGIC_SERVICE_ID + m_serverMsgToServiceMap[msgId]));
        if (pService)
        {
            return pService->OnHandleServerMessage(msgId, packet);
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find service, msgId:{} serviceId:{}, drop the msg:{}", msgId, m_serverMsgToServiceMap[msgId], packet.ToString());
        }
    }
    return 0;
}

int NFLogicObServiceModule::OnHandleRpcMessage(uint32_t msgId, google::protobuf::Message &request, google::protobuf::Message &respone, uint64_t param1, uint64_t param2)
{
    if (msgId < m_rpcMsgToServiceMap.size() && m_rpcMsgToServiceMap[msgId].first != 0)
    {
        auto pService = dynamic_cast<NFLogicObService *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_LOGIC_SERVICE_ID + m_rpcMsgToServiceMap[msgId].first));
        if (pService && m_rpcMsgToServiceMap[msgId].second)
        {
            return m_rpcMsgToServiceMap[msgId].second->run(pService, request, respone);
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find service, msgId:{} serviceId:{}, drop the msg", msgId, m_rpcMsgToServiceMap[msgId].first);
        }
    }
    return 0;
}

