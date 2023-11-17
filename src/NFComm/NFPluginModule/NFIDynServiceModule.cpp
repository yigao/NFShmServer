// -------------------------------------------------------------------------
//    @FileName         :    NFIDynServiceModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFIDynServiceModule
//
// -------------------------------------------------------------------------

#include "NFIDynServiceModule.h"

NFIDysServiceModule::NFIDysServiceModule(NFIPluginManager* p):NFIDynamicModule(p)
{
    m_clientMsgToServiceMap.resize(NF_NET_MAX_MSG_ID);
    m_serverMsgToServiceMap.resize(NF_NET_MAX_MSG_ID);
    m_rpcMsgToServiceMap.resize(NF_NET_MAX_MSG_ID);
}

NFIDysServiceModule::~NFIDysServiceModule()
{
}

int NFIDysServiceModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2)
{
    return NFIDynamicModule::OnHandleClientMessage(msgId, packet, param1, param2);
}

int NFIDysServiceModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2)
{
    return NFIDynamicModule::OnHandleServerMessage(msgId, packet, param1, param2);
}

int NFIDysServiceModule::OnHandleRpcMessage(uint32_t msgId, google::protobuf::Message& request, google::protobuf::Message& respone, uint64_t param1, uint64_t param2)
{
    return NFIDynamicModule::OnHandleRpcMessage(msgId, request, respone, param1, param2);
}

int NFIDysServiceModule::RegisterClientMessage(NF_SERVER_TYPES serverType, uint32_t nMsgID, uint32_t serviceId, bool createCo)
{
    CHECK_EXPR_ASSERT(nMsgID < m_clientMsgToServiceMap.size(), -1, "");
    NFIDynamicModule::RegisterClientMessage(serverType, nMsgID, createCo);
    m_clientMsgToServiceMap[nMsgID] = serviceId;
    return 0;
}

int NFIDysServiceModule::RegisterServerMessage(NF_SERVER_TYPES serverType, uint32_t nMsgID, uint32_t serviceId, bool createCo)
{
    CHECK_EXPR_ASSERT(nMsgID < m_serverMsgToServiceMap.size(), -1, "");
    NFIDynamicModule::RegisterServerMessage(serverType, nMsgID, createCo);
    m_serverMsgToServiceMap[nMsgID] = serviceId;
    return 0;
}
