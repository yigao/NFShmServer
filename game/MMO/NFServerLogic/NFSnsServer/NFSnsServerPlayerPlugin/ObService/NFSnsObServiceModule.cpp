// -------------------------------------------------------------------------
//    @FileName         :    NFSnsObServiceModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsObServiceModule
//
// -------------------------------------------------------------------------

#include "NFSnsObServiceModule.h"

#include <NFLogicCommon/NFLogicShmTypeDefines.h>
#include <NFServerComm/NFServerCommon/NFDBObjMgr.h>
#include <Team/NFSnsTeamMgr.h>

#include "NFSnsObService.h"

NFSnsObServiceModule::NFSnsObServiceModule(NFIPluginManager* p) : NFIDysServiceModule(p)
{
}

NFSnsObServiceModule::~NFSnsObServiceModule()
{
}

bool NFSnsObServiceModule::Awake()
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_SNS_SERVER);
    NF_ASSERT(pConfig);

    for (uint32_t i = SNS_OB_SERVICE_NONE + 1; i < SNS_OB_SERVICE_MAX; ++i)
    {
        auto pService = dynamic_cast<NFSnsObService *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_SNS_SERVICE_ID + i));
        if (pService)
        {
            pService->RegisterMessage();
        }
    }

    RegisterAppTask(NF_ST_SNS_SERVER, APP_INIT_LOAD_GLOBAL_DATA_DB,
                NF_FORMAT("{} {}", pConfig->ServerName, "Load Sns Global Data From Store Server"), APP_INIT_TASK_GROUP_SERVER_LOAD_OBJ_FROM_DB);

    Subscribe(NF_ST_SNS_SERVER, proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH, proto_ff::NF_EVENT_SERVER_TYPE, APP_INIT_TASK_GROUP_SERVER_CONNECT,
              __FUNCTION__);
    Subscribe(NF_ST_SNS_SERVER, proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH, proto_ff::NF_EVENT_SERVER_TYPE, APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE,
              __FUNCTION__);
    return true;
}

bool NFSnsObServiceModule::Execute()
{
    return NFIDysServiceModule::Execute();
}

bool NFSnsObServiceModule::OnDynamicPlugin()
{
    return NFIDysServiceModule::OnDynamicPlugin();
}

int NFSnsObServiceModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2)
{
    if (msgId < m_clientMsgToServiceMap.size() && m_clientMsgToServiceMap[msgId] != 0)
    {
        auto pService = dynamic_cast<NFSnsObService *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_SNS_SERVICE_ID + m_clientMsgToServiceMap[msgId]));
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

int NFSnsObServiceModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2)
{
    if (msgId < m_serverMsgToServiceMap.size() && m_serverMsgToServiceMap[msgId] != 0)
    {
        auto pService = dynamic_cast<NFSnsObService *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_SNS_SERVICE_ID + m_serverMsgToServiceMap[msgId]));
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

int NFSnsObServiceModule::OnHandleRpcMessage(uint32_t msgId, google::protobuf::Message& request, google::protobuf::Message& respone, uint64_t param1, uint64_t param2)
{
    if (msgId < m_rpcMsgToServiceMap.size() && m_rpcMsgToServiceMap[msgId].first != 0)
    {
        auto pService = dynamic_cast<NFSnsObService *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_SNS_SERVICE_ID + m_rpcMsgToServiceMap[msgId].first));
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

int NFSnsObServiceModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
{
    if (nEventID == proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH && bySrcType == proto_ff::NF_EVENT_SERVER_TYPE &&
    (nSrcID == APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE || nSrcID == APP_INIT_TASK_GROUP_SERVER_CONNECT))
    {
        if (m_pObjPluginManager->IsFinishAppTask(NF_ST_GAME_SERVER, APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE) && m_pObjPluginManager->IsFinishAppTask(NF_ST_GAME_SERVER, APP_INIT_TASK_GROUP_SERVER_CONNECT))
        {
            for (uint32_t i = SNS_OB_SERVICE_NONE + 1; i < SNS_OB_SERVICE_MAX; ++i)
            {
                auto pService = dynamic_cast<NFSnsObService *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_SNS_SERVICE_ID + i));
                if (pService)
                {
                    NFDBObjMgr::Instance(m_pObjPluginManager)->LoadFromDB(pService);
                }
            }
        }
    }
    return 0;
}
