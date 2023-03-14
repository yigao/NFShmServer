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
#include "NFLogicCommon/NFRoleDefine.h"
#include "Player/NFPlayer.h"
#include "Player/NFPlayerMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFPackagePart.h"
#include "NFFunctionUnlockPart.h"
#include "NFTitlePart.h"
#include "NFMissionPart.h"

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
    //package msg
    NFPackagePart::RegisterClientMessage(m_pObjPluginManager);
    NFPackagePart::RegisterServerMessage(m_pObjPluginManager);

    //function part msg
    NFFunctionUnlockPart::RegisterClientMessage(m_pObjPluginManager);
    NFFunctionUnlockPart::RegisterServerMessage(m_pObjPluginManager);

    //title part msg
    NFTitlePart::RegisterClientMessage(m_pObjPluginManager);
    NFTitlePart::RegisterServerMessage(m_pObjPluginManager);

    //mission part msg
    NFMissionPart::RegisterClientMessage(m_pObjPluginManager);
    NFMissionPart::RegisterServerMessage(m_pObjPluginManager);
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

int NFPartModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t uid, uint64_t roleId)
{
    NFPlayer *pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(roleId);
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
        NFLogError(NF_LOG_SYSTEMLOG, roleId, "can' find the player role:{}", roleId);
    }
    return 0;
}

int NFPartModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t uid, uint64_t roleId)
{
    NFPlayer *pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(roleId);
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

int NFPartModule::RegisterClientPartMsg(uint32_t nMsgID, uint32_t partType)
{
    CHECK_EXPR_ASSERT(nMsgID < m_clientMsgToPartMap.size(), -1, "");
    RegisterClientMessage(NF_ST_LOGIC_SERVER, nMsgID);
    m_clientMsgToPartMap[nMsgID] = partType;
    return 0;
}

int NFPartModule::RegisterServerPartMsg(uint32_t nMsgID, uint32_t partType)
{
    CHECK_EXPR_ASSERT(nMsgID < m_serverMsgToPartMap.size(), -1, "");
    RegisterServerMessage(NF_ST_LOGIC_SERVER, nMsgID);
    m_serverMsgToPartMap[nMsgID] = partType;
    return 0;
}