// -------------------------------------------------------------------------
//    @FileName         :    NFPart.cpp
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFPart
//
// -------------------------------------------------------------------------

#include "NFPart.h"
#include "Player/NFPlayer.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFPartModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFPart, EOT_LOGIC_PART_ID, NFShmObj)

NFPart::NFPart() : NFShmObj()
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

NFPart::~NFPart()
{
}

int NFPart::CreateInit()
{
    m_pMaster = NULL;
    m_partType = 0;
    m_playerId = 0;
    return 0;
}

int NFPart::ResumeInit()
{
    return 0;
}

int NFPart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::tbFishPlayerData &dbData, bool bCreatePlayer)
{
    CHECK_NULL(pMaster);
    m_pMaster = pMaster;
    m_playerId = pMaster->GetPlayerId();
    m_partType = partType;

    if (bCreatePlayer)
    {
        InitConfig(dbData);
    }
    else
    {
        LoadFromDB(dbData);
    }
    return 0;
}

int NFPart::UnInit()
{
    return 0;
}

int NFPart::RegisterClientPartMsg(NFIPluginManager* pPluginManager, uint32_t nMsgID, uint32_t partType, bool createCo)
{
    return pPluginManager->FindModule<NFPartModule>()->RegisterClientPartMsg(nMsgID, partType, createCo);
}

int NFPart::RegisterServerPartMsg(NFIPluginManager* pPluginManager, uint32_t nMsgID, uint32_t partType, bool createCo)
{
    return pPluginManager->FindModule<NFPartModule>()->RegisterServerPartMsg(nMsgID, partType, createCo);
}

int NFPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetPlayerId(), "client part package not handle:{}", packet.ToString());
    return 0;
}

int NFPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetPlayerId(), "server part package not handle:{}", packet.ToString());
    return 0;
}

uint32_t NFPart::GetCurRoleDetailSeq() const
{
    return GetCurSeq();
}
