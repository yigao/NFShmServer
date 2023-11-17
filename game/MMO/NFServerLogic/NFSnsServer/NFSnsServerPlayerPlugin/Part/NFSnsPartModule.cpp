// -------------------------------------------------------------------------
//    @FileName         :    NFSnsPartModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsPartModule
//
// -------------------------------------------------------------------------

#include "NFSnsPartModule.h"
#include "Cache/NFCacheMgr.h"
#include "NFSnsPart.h"
#include "NFLogicCommon/NFCharactorDefine.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

NFSnsPartModule::NFSnsPartModule(NFIPluginManager* p) : NFIDysServiceModule(p)
{

}

NFSnsPartModule::~NFSnsPartModule()
{
}

bool NFSnsPartModule::Awake()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        auto pPart = dynamic_cast<NFSnsPart *>(FindModule<NFISharedMemModule>()->CreateObj(EOT_SNS_PART_ID + i));
        if (pPart)
        {
            pPart->SetPartType(i);
            pPart->RegisterMessage();
            FindModule<NFISharedMemModule>()->DestroyObj(pPart);
        }
    }
    return true;
}

bool NFSnsPartModule::Execute()
{
    return NFIModule::Execute();
}

bool NFSnsPartModule::OnDynamicPlugin()
{
    return NFIModule::OnDynamicPlugin();
}

int NFSnsPartModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet, uint64_t playerId, uint64_t param2)
{
    NFPlayerDetail* pPlayer = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerDetail(playerId);
    if (pPlayer)
    {
        if (msgId < m_clientMsgToServiceMap.size() && m_clientMsgToServiceMap[msgId] != 0)
        {
            NFSnsPart* pPart = pPlayer->GetPart(m_clientMsgToServiceMap[msgId]);
            if (pPart)
            {
                return pPart->OnHandleClientMessage(msgId, packet);
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, playerId, "can't find part, msgId:{} partId:{}, drop the msg:{}", msgId, m_clientMsgToServiceMap[msgId], packet.ToString());
            }
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "can't find player by playerId:{}, drop the msg:{}", playerId, packet.ToString());
    }
    return 0;
}

int NFSnsPartModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet, uint64_t playerId, uint64_t param2)
{
    NFPlayerDetail* pPlayer = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerDetail(playerId);
    if (pPlayer)
    {
        if (msgId < m_serverMsgToServiceMap.size() && m_serverMsgToServiceMap[msgId] != 0)
        {
            NFSnsPart* pPart = pPlayer->GetPart(m_serverMsgToServiceMap[msgId]);
            if (pPart)
            {
                return pPart->OnHandleServerMessage(msgId, packet);
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, playerId, "can't find part, msgId:{} partId:{}, drop the msg:{}", msgId, m_serverMsgToServiceMap[msgId], packet.ToString());
            }
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "can't find player by playerId:{}, drop the msg:{}", playerId, packet.ToString());
    }
    return 0;
}

int NFSnsPartModule::OnHandleRpcMessage(uint32_t msgId, google::protobuf::Message& request, google::protobuf::Message& respone, uint64_t playerId, uint64_t param2)
{
    NFPlayerDetail* pPlayer = NFCacheMgr::Instance(m_pObjPluginManager)->QueryPlayerDetailByRpc(playerId);
    if (pPlayer)
    {
        if (msgId < m_rpcMsgToServiceMap.size() && m_rpcMsgToServiceMap[msgId].first != 0)
        {
            NFSnsPart* pPart = pPlayer->GetPart(m_rpcMsgToServiceMap[msgId].first);
            if (pPart && m_rpcMsgToServiceMap[msgId].second)
            {
                return m_rpcMsgToServiceMap[msgId].second->run(pPart, request, respone);
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, playerId, "can't find part, msgId:{} partId:{}, drop the msg", msgId, m_rpcMsgToServiceMap[msgId].first);
            }
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "can't find player by playerId:{}, drop the msg:{}", playerId, msgId);
    }
    return proto_ff::ERR_CODE_RPC_MSG_FUNCTION_UNEXISTED;
}

