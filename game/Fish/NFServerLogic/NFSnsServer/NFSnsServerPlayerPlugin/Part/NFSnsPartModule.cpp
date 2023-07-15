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

NFSnsPartModule::NFSnsPartModule(NFIPluginManager *p) : NFIDynamicModule(p)
{
    m_clientMsgToPartMap.resize(10000);
    m_serverMsgToPartMap.resize(10000);
}

NFSnsPartModule::~NFSnsPartModule()
{
}

bool NFSnsPartModule::Awake()
{
    for (uint32_t i = SNS_PART_NONE + 1; i < SNS_PART_MAX; ++i)
    {
        auto pPart = NFPlayerDetail::CreatePart(m_pObjPluginManager, i);
        if (pPart)
        {
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

int NFSnsPartModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t playerId, uint64_t param2)
{
    NFPlayerDetail *pPlayer = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerDetail(playerId);
    if (pPlayer)
    {
        if (msgId < m_clientMsgToPartMap.size() && m_clientMsgToPartMap[msgId]  != 0)
        {
            NFSnsPart* pPart = pPlayer->GetPart(m_clientMsgToPartMap[msgId]);
            if (pPart)
            {
                return pPart->OnHandleClientMessage(msgId, packet);
            }
            else {
                NFLogError(NF_LOG_SYSTEMLOG, playerId, "can't find part, msgId:{} partId:{}, drop the msg:{}", msgId, m_clientMsgToPartMap[msgId], packet.ToString());
            }
        }
    }
    else {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "can't find player by roleId:{}, drop the msg:{}", playerId, packet.ToString());
    }
    return 0;
}

int NFSnsPartModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t playerId, uint64_t param2)
{
    NFPlayerDetail *pPlayer = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerDetail(playerId);
    if (pPlayer)
    {
        if (msgId < m_serverMsgToPartMap.size() && m_serverMsgToPartMap[msgId]  != 0)
        {
            NFSnsPart* pPart = pPlayer->GetPart(m_serverMsgToPartMap[msgId]);
            if (pPart)
            {
                return pPart->OnHandleServerMessage(msgId, packet);
            }
        }
    }
    else {
        NFLogError(NF_LOG_SYSTEMLOG, playerId, "can't find player by roleId:{}, drop the msg:{}", playerId, packet.ToString());
    }
    return 0;
}

int NFSnsPartModule::RegisterClientPartMsg(uint32_t nMsgID, uint32_t partType, bool createCo)
{
    CHECK_EXPR_ASSERT(nMsgID < m_clientMsgToPartMap.size(), -1, "");
    RegisterClientMessage(NF_ST_SNS_SERVER, nMsgID, createCo);
    m_clientMsgToPartMap[nMsgID] = partType;
    return 0;
}

int NFSnsPartModule::RegisterServerPartMsg(uint32_t nMsgID, uint32_t partType, bool createCo)
{
    CHECK_EXPR_ASSERT(nMsgID < m_serverMsgToPartMap.size(), -1, "");
    RegisterServerMessage(NF_ST_SNS_SERVER, nMsgID, createCo);
    m_serverMsgToPartMap[nMsgID] = partType;
    return 0;
}

