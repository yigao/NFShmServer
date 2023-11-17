// -------------------------------------------------------------------------
//    @FileName         :    NFPartModule.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFPartModule
//
// -------------------------------------------------------------------------

#include "NFPartModule.h"
#include "ClientServerCmd.pb.h"
#include "Player/NFPlayer.h"
#include "Player/NFPlayerMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFPart.h"

NFPartModule::NFPartModule(NFIPluginManager *p) : NFIDysServiceModule(p)
{

}

NFPartModule::~NFPartModule()
{
}


bool NFPartModule::Awake()
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        auto pPart = dynamic_cast<NFPart*>(FindModule<NFISharedMemModule>()->CreateObj(EOT_LOGIC_PART_ID+i));
        if (pPart)
        {
            pPart->SetPartType(i);
            pPart->RegisterMessage();
            FindModule<NFISharedMemModule>()->DestroyObj(pPart);
        }
    }
    return true;
}

bool NFPartModule::Execute()
{
    return NFIModule::Execute();
}

bool NFPartModule::OnDynamicPlugin()
{
    return NFIModule::OnDynamicPlugin();
}

int NFPartModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t playerId, uint64_t param2)
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

    NFPlayer *pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(playerId);
    if (pPlayer)
    {
        if (msgId < m_clientMsgToServiceMap.size() && m_clientMsgToServiceMap[msgId]  != 0)
        {
            NFPart* pPart = pPlayer->GetPart(m_clientMsgToServiceMap[msgId]);
            if (pPart)
            {
                return pPart->OnHandleClientMessage(msgId, packet);
            }
        }
        else {
            NFLogError(NF_LOG_SYSTEMLOG, playerId, "msgId:{} can't handle, drop the msg", msgId, m_clientMsgToServiceMap[msgId]);
        }
    }
    else {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "can' find the player role:{}", playerId);
    }
    return 0;
}

int NFPartModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t playerId, uint64_t param2)
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

    NFPlayer *pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(playerId);
    if (pPlayer)
    {
        if (msgId < m_serverMsgToServiceMap.size() && m_serverMsgToServiceMap[msgId]  != 0)
        {
            NFPart* pPart = pPlayer->GetPart(m_serverMsgToServiceMap[msgId]);
            if (pPart)
            {
                return pPart->OnHandleServerMessage(msgId, packet);
            }
            else {
                NFLogError(NF_LOG_SYSTEMLOG, playerId, "can't find part, msgId:{} partId:{}, drop the msg", msgId, m_serverMsgToServiceMap[msgId]);
            }
        }
        else {
            NFLogError(NF_LOG_SYSTEMLOG, playerId, "msgId:{} can't handle, drop the msg", msgId);
        }
    }
    return 0;
}

int NFPartModule::OnHandleRpcMessage(uint32_t msgId, google::protobuf::Message& request, google::protobuf::Message& respone, uint64_t playerId,
                                     uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_LOGIC_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "Logic Server not inited, drop client msg:{}", msgId);
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "Logic Server is Stopping, drop client msg:{}", msgId);
        return -1;
    }

    NFPlayer *pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(playerId);
    if (pPlayer)
    {
        if (msgId < m_rpcMsgToServiceMap.size() && m_rpcMsgToServiceMap[msgId].first  != 0)
        {
            NFPart* pPart = pPlayer->GetPart(m_rpcMsgToServiceMap[msgId].first);
            if (pPart && m_rpcMsgToServiceMap[msgId].second)
            {
                return m_rpcMsgToServiceMap[msgId].second->run(pPart, request, respone);
            }
            else {
                NFLogError(NF_LOG_SYSTEMLOG, playerId, "can't find part, msgId:{} partId:{}, drop the msg", msgId, m_rpcMsgToServiceMap[msgId].first);
            }
        }
        else {
            NFLogError(NF_LOG_SYSTEMLOG, playerId, "msgId:{} can't handle, drop the msg", msgId);
        }
    }
    return 0;
}
