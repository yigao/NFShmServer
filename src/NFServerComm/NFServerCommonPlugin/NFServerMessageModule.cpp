// -------------------------------------------------------------------------
//    @FileName         :    NFMessageMgr.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFMessageMgr.cpp
//
// -------------------------------------------------------------------------

#include "NFServerMessageModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"

NFServerMessageModule::NFServerMessageModule(NFIPluginManager* pPluginManager):NFIServerMessageModule(pPluginManager)
{

}

NFServerMessageModule::~NFServerMessageModule()
{

}

int NFServerMessageModule::SendMsgToMasterServer(NF_SERVER_TYPES eSendType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1, uint64_t nParam2)
{
    auto pServerData = FindModule<NFIMessageModule>()->GetMasterData(eSendType);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, eType error:{}", (int) eSendType);

    FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, nMsgId, xData, nParam1, nParam2);
    return 0;
}

int NFServerMessageModule::SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1, uint64_t nParam2)
{
    return SendProxyMsgByBusId(eType, nDstId, NF_MODULE_NONE, nMsgId, xData, nParam1, nParam2);
}

int NFServerMessageModule::SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1, uint64_t nParam2)
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(eType);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL");

    NF_SHARE_PTR<NFServerData> pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(eType, nDstId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", nDstId);

    FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, nModuleId, nMsgId, xData, nParam1, nParam2, pConfig->BusId, nDstId);
    return 0;
}

int NFServerMessageModule::SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1, uint64_t nParam2)
{
    return SendMsgToProxyServer(eType, nDstId, NF_MODULE_NONE, nMsgId, xData, nParam1, nParam2);
}

int NFServerMessageModule::SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nDstId, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t nParam1, uint64_t nParam2)
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(eType);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL");

    auto pServerData = FindModule<NFIMessageModule>()->GetRandomServerByServerType(eType, NF_ST_PROXY_AGENT_SERVER);
    if (pServerData)
    {
        FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, nModuleId, nMsgId, xData, nParam1, nParam2, pConfig->BusId, nDstId);
        return 0;
    }

    pServerData = FindModule<NFIMessageModule>()->GetServerByServerId(eType, nDstId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", nDstId);
    FindModule<NFIMessageModule>()->Send(pServerData->mUnlinkId, nModuleId, nMsgId, xData, nParam1, nParam2, pConfig->BusId, nDstId);
    return 0;
}