// -------------------------------------------------------------------------
//    @FileName         :    NFBattlePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-2-25
//    @Email			:    445267987@qq.com
//    @Module           :    NFBattlePart
//
// -------------------------------------------------------------------------

#include "NFBattlePart.h"
#include "Creature/NFCreature.h"
#include "NFBattlePartModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFBattlePart, EOT_NFBattlePart_ID, NFShmObj)

NFBattlePart::NFBattlePart()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFBattlePart::~NFBattlePart()
{
}

int NFBattlePart::CreateInit()
{
    m_masterCid = -1;
    return 0;
}

int NFBattlePart::ResumeInit()
{
    return 0;
}

int NFBattlePart::Init(NFCreature *pMaster, uint32_t partType, const proto_ff::RoleEnterSceneData &data)
{
    CHECK_EXPR(pMaster, -1, "pMaster == NULL");
    m_masterCid = pMaster->Cid();
    m_partType = partType;
    return 0;
}

int NFBattlePart::UnInit()
{
    return 0;
}

uint32_t NFBattlePart::GetCurRoleDetailSeq() const
{
    return GetCurSeq();
}

int NFBattlePart::RetisterClientPartMsg(NFIPluginManager *pPluginManager, uint32_t nMsgID, uint32_t partType)
{
    return pPluginManager->FindModule<NFBattlePartModule>()->RetisterClientPartMsg(nMsgID, partType);
}

int NFBattlePart::RetisterServerPartMsg(NFIPluginManager *pPluginManager, uint32_t nMsgID, uint32_t partType)
{
    return pPluginManager->FindModule<NFBattlePartModule>()->RetisterServerPartMsg(nMsgID, partType);
}

int NFBattlePart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, m_masterCid, "client part package not handle:{}", packet.ToString());
    return 0;
}

int NFBattlePart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, m_masterCid, "server part package not handle:{}", packet.ToString());
    return 0;
}

NFCreature *NFBattlePart::GetMaster()
{
    return dynamic_cast<NFCreature *>(FindModule<NFISharedMemModule>()->GetObjFromGlobalID(m_masterCid, EOT_GAME_CREATURE_ID, 0));
}
