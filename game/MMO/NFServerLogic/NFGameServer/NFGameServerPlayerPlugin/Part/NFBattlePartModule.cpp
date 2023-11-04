// -------------------------------------------------------------------------
//    @FileName         :    NFPartModule.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFPartModule
//
// -------------------------------------------------------------------------

#include "NFBattlePartModule.h"
#include "ClientServerCmd.pb.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFBattlePart.h"
#include "Creature/NFBattlePlayer.h"
#include "Creature/NFCreatureMgr.h"

NFBattlePartModule::NFBattlePartModule(NFIPluginManager *p) : NFIDynamicModule(p)
{
    m_clientMsgToPartMap.resize(10000);
    m_serverMsgToPartMap.resize(10000);
}

NFBattlePartModule::~NFBattlePartModule()
{
}


bool NFBattlePartModule::Awake()
{
    for (uint32_t i = BATTLE_PART_NONE + 1; i < BATTLE_PART_MAX; ++i)
    {
        auto pPart = dynamic_cast<NFBattlePart*>(FindModule<NFISharedMemModule>()->CreateObj(EOT_NFBattlePart_ID+i));
        if (pPart)
        {
            pPart->SetPartType(i);
            pPart->RegisterMessage();
            FindModule<NFISharedMemModule>()->DestroyObj(pPart);
        }
    }
    return true;
}

bool NFBattlePartModule::Execute()
{
    return NFIModule::Execute();
}

bool NFBattlePartModule::OnDynamicPlugin()
{
    return NFIModule::OnDynamicPlugin();
}

int NFBattlePartModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t roleId, uint64_t param2)
{
    NFBattlePlayer *pPlayer = NFCreatureMgr::Instance(m_pObjPluginManager)->GetBattlePlayer(roleId);
    if (pPlayer)
    {
        if (msgId < m_clientMsgToPartMap.size() && m_clientMsgToPartMap[msgId]  != 0)
        {
            NFBattlePart* pPart = pPlayer->GetPart(m_clientMsgToPartMap[msgId]);
            if (pPart)
            {
                return pPart->OnHandleClientMessage(msgId, packet);
            }
        }
        else {
            NFLogError(NF_LOG_SYSTEMLOG, roleId, "can't find msg register, roleId:{}, drop the msg:{}", roleId, packet.ToString());
        }
    }
    else {
        NFLogError(NF_LOG_SYSTEMLOG, roleId, "can't find player by roleId:{}, drop the msg:{}", roleId, packet.ToString());
    }
    return 0;
}

int NFBattlePartModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t roleId, uint64_t param2)
{
    NFBattlePlayer *pPlayer = NFCreatureMgr::Instance(m_pObjPluginManager)->GetBattlePlayer(roleId);
    if (pPlayer)
    {
        if (msgId < m_serverMsgToPartMap.size() && m_serverMsgToPartMap[msgId]  != 0)
        {
            NFBattlePart* pPart = pPlayer->GetPart(m_serverMsgToPartMap[msgId]);
            if (pPart)
            {
                return pPart->OnHandleServerMessage(msgId, packet);
            }
        }
    }
    else {
        NFLogError(NF_LOG_SYSTEMLOG, roleId, "can't find player by roleId:{}, drop the msg:{}", roleId, packet.ToString());
    }
    return 0;
}

int NFBattlePartModule::RegisterClientPartMsg(uint32_t nMsgID, uint32_t partType, bool createCo)
{
    CHECK_EXPR_ASSERT(nMsgID < m_clientMsgToPartMap.size(), -1, "");
    RegisterClientMessage(NF_ST_GAME_SERVER, nMsgID, createCo);
    if (m_clientMsgToPartMap[nMsgID] != 0)
    {
        NFLogWarning(NF_LOG_SYSTEMLOG, 0, "RegisterClientMsg nMsgId:{} has be registtered by part:{}, can't be registerd by part:{}", nMsgID, m_clientMsgToPartMap[nMsgID], partType);
        return 0;
    }
    m_clientMsgToPartMap[nMsgID] = partType;
    return 0;
}

int NFBattlePartModule::RegisterServerPartMsg(uint32_t nMsgID, uint32_t partType, bool createCo)
{
    CHECK_EXPR_ASSERT(nMsgID < m_serverMsgToPartMap.size(), -1, "");
    RegisterServerMessage(NF_ST_GAME_SERVER, nMsgID, createCo);
    if (m_serverMsgToPartMap[nMsgID] != 0)
    {
        NFLogWarning(NF_LOG_SYSTEMLOG, 0, "RegisterServerPartMsg nMsgId:{} has be registtered by part:{}, can't be registerd by part:{}", nMsgID, m_serverMsgToPartMap[nMsgID], partType);
        return 0;
    }
    m_serverMsgToPartMap[nMsgID] = partType;
    return 0;
}