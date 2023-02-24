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
    NFPackagePart::RetisterClientMessage(m_pObjPluginManager);
    NFPackagePart::RetisterServerMessage(m_pObjPluginManager);

    //function part msg
    NFFunctionUnlockPart::RetisterClientMessage(m_pObjPluginManager);
    NFFunctionUnlockPart::RetisterServerMessage(m_pObjPluginManager);

    //title part msg
    NFTitlePart::RetisterClientMessage(m_pObjPluginManager);
    NFTitlePart::RetisterServerMessage(m_pObjPluginManager);

    //mission part msg
    NFMissionPart::RetisterClientMessage(m_pObjPluginManager);
    NFMissionPart::RetisterServerMessage(m_pObjPluginManager);
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

int NFPartModule::RetisterClientPartMsg(uint32_t nMsgID, uint32_t partType)
{
    CHECK_EXPR_ASSERT(nMsgID < m_clientMsgToPartMap.size(), -1, "");
    RegisterClientMessage(NF_ST_LOGIC_SERVER, nMsgID);
    m_clientMsgToPartMap[nMsgID] = partType;
    return 0;
}

int NFPartModule::RetisterServerPartMsg(uint32_t nMsgID, uint32_t partType)
{
    CHECK_EXPR_ASSERT(nMsgID < m_serverMsgToPartMap.size(), -1, "");
    RegisterServerMessage(NF_ST_LOGIC_SERVER, nMsgID);
    m_serverMsgToPartMap[nMsgID] = partType;
    return 0;
}