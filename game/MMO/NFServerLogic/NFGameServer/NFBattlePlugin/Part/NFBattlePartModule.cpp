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
#include "NFLogicCommon/NFRoleDefine.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFBattlePart.h"
#include "Creature/NFBattlePlayer.h"
#include "Creature/NFCreatureMgr.h"
#include "NFMovePart.h"

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
    //move part
    NFMovePart::RegisterClientMessage(m_pObjPluginManager);
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

int NFBattlePartModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t uid, uint64_t roleId)
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
    }
    else {
        NFLogError(NF_LOG_SYSTEMLOG, roleId, "can't find player by roleId:{}, drop the msg:{}", roleId, packet.ToString());
    }
    return 0;
}

int NFBattlePartModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t uid, uint64_t roleId)
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

int NFBattlePartModule::RegisterClientPartMsg(uint32_t nMsgID, uint32_t partType)
{
    CHECK_EXPR_ASSERT(nMsgID < m_clientMsgToPartMap.size(), -1, "");
    RegisterClientMessage(NF_ST_GAME_SERVER, nMsgID);
    m_clientMsgToPartMap[nMsgID] = partType;
    return 0;
}

int NFBattlePartModule::RegisterServerPartMsg(uint32_t nMsgID, uint32_t partType)
{
    CHECK_EXPR_ASSERT(nMsgID < m_serverMsgToPartMap.size(), -1, "");
    RegisterServerMessage(NF_ST_GAME_SERVER, nMsgID);
    m_serverMsgToPartMap[nMsgID] = partType;
    return 0;
}