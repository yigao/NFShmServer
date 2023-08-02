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

NFPartModule::NFPartModule(NFIPluginManager *p) : NFIDynamicModule(p)
{
    m_clientMsgToPartMap.resize(NF_NET_MAX_MSG_ID);
    m_serverMsgToPartMap.resize(NF_NET_MAX_MSG_ID);
    m_rpcMsgToPartMap.resize(NF_NET_MAX_MSG_ID);
}

NFPartModule::~NFPartModule()
{
}


bool NFPartModule::Awake()
{
    for (uint32_t i = PART_NONE + 1; i < PART_MAX; ++i)
    {
        auto pPart = NFPlayer::CreatePart(m_pObjPluginManager, i);
        if (pPart)
        {
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
        if (msgId < m_clientMsgToPartMap.size() && m_clientMsgToPartMap[msgId]  != 0)
        {
            NFPart* pPart = pPlayer->GetPart(m_clientMsgToPartMap[msgId]);
            if (pPart)
            {
                return pPart->OnHandleClientMessage(msgId, packet);
            }
        }
        else {
            NFLogError(NF_LOG_SYSTEMLOG, playerId, "msgId:{} can't handle, drop the msg", msgId, m_clientMsgToPartMap[msgId]);
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
        if (msgId < m_serverMsgToPartMap.size() && m_serverMsgToPartMap[msgId]  != 0)
        {
            NFPart* pPart = pPlayer->GetPart(m_serverMsgToPartMap[msgId]);
            if (pPart)
            {
                return pPart->OnHandleServerMessage(msgId, packet);
            }
            else {
                NFLogError(NF_LOG_SYSTEMLOG, playerId, "can't find part, msgId:{} partId:{}, drop the msg", msgId, m_serverMsgToPartMap[msgId]);
            }
        }
        else {
            NFLogError(NF_LOG_SYSTEMLOG, playerId, "msgId:{} can't handle, drop the msg", msgId);
        }
    }
    return 0;
}

int NFPartModule::RegisterClientPartMsg(uint32_t nMsgID, uint32_t partType, bool createCo)
{
    CHECK_EXPR_ASSERT(nMsgID < m_clientMsgToPartMap.size(), -1, "");
    RegisterClientMessage(NF_ST_LOGIC_SERVER, nMsgID, createCo);
    if (m_clientMsgToPartMap[nMsgID] != 0)
    {
        NFLogWarning(NF_LOG_SYSTEMLOG, 0, "RegisterClientMsg nMsgId:{} has be registtered by part:{}, can't be registerd by part:{}", nMsgID, m_clientMsgToPartMap[nMsgID], partType);
        return 0;
    }
    m_clientMsgToPartMap[nMsgID] = partType;
    return 0;
}

int NFPartModule::RegisterServerPartMsg(uint32_t nMsgID, uint32_t partType, bool createCo)
{
    CHECK_EXPR_ASSERT(nMsgID < m_serverMsgToPartMap.size(), -1, "");
    RegisterServerMessage(NF_ST_LOGIC_SERVER, nMsgID, createCo);
    if (m_clientMsgToPartMap[nMsgID] != 0)
    {
        NFLogWarning(NF_LOG_SYSTEMLOG, 0, "RegisterServerPartMsg nMsgId:{} has be registtered by part:{}, can't be registerd by part:{}", nMsgID, m_clientMsgToPartMap[nMsgID], partType);
        return 0;
    }
    m_serverMsgToPartMap[nMsgID] = partType;
    return 0;
}

int NFPartModule::OnHandleRpcMessage(uint32_t msgId, google::protobuf::Message *pRequest, google::protobuf::Message *pRespone, uint64_t playerId,
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
        if (msgId < m_rpcMsgToPartMap.size() && m_rpcMsgToPartMap[msgId].first  != 0)
        {
            NFPart* pPart = pPlayer->GetPart(m_rpcMsgToPartMap[msgId].first);
            if (pPart && m_rpcMsgToPartMap[msgId].second)
            {
                return m_rpcMsgToPartMap[msgId].second->run(pPart, pRequest, pRespone);
            }
            else {
                NFLogError(NF_LOG_SYSTEMLOG, playerId, "can't find part, msgId:{} partId:{}, drop the msg", msgId, m_rpcMsgToPartMap[msgId].first);
            }
        }
        else {
            NFLogError(NF_LOG_SYSTEMLOG, playerId, "msgId:{} can't handle, drop the msg", msgId);
        }
    }
    return 0;
}
