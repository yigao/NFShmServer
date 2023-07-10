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
    m_clientMsgToPartMap.resize(10000);
    m_serverMsgToPartMap.resize(10000);
}

NFPartModule::~NFPartModule()
{
}


bool NFPartModule::Awake()
{
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
    }
    else {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "can' find the player role:{}", playerId);
    }
    return 0;
}

int NFPartModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t playerId, uint64_t param2)
{
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
        NFLogWarning(NF_LOG_SYSTEMLOG, 0, "RegisterClientPartMsg nMsgId:{} has be registtered by part:{}, can't be registerd by part:{}", nMsgID, m_clientMsgToPartMap[nMsgID], partType);
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