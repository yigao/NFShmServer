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
#include "Creature/NFCreatureMgr.h"
#include "NFBattlePartModule.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "DBProxy2.pb.h"

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
    return 0;
}

int NFBattlePart::ResumeInit()
{
    return 0;
}

int NFBattlePart::InitBase(NFCreature *pMaster, uint32_t partType)
{
    CHECK_EXPR(pMaster, -1, "pMaster == NULL");
    m_pMaster = pMaster;
    m_partType = partType;
    return 0;
}

int NFBattlePart::Init(const proto_ff::RoleEnterSceneData &data)
{
    return 0;
}

int NFBattlePart::UnInit()
{
    return 0;
}

int NFBattlePart::RegisterMessage()
{
    return 0;
}

uint32_t NFBattlePart::GetCurRoleDetailSeq() const
{
    return GetCurSeq();
}

int NFBattlePart::RegisterClientMessage(uint32_t nMsgID, bool createCo)
{
    return FindModule<NFBattlePartModule>()->RegisterClientPartMsg(nMsgID, m_partType, createCo);
}

int NFBattlePart::RegisterServerMessage(uint32_t nMsgID, bool createCo)
{
    return FindModule<NFBattlePartModule>()->RegisterServerPartMsg(nMsgID, m_partType, createCo);
}

int NFBattlePart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "client part package not handle:{}", packet.ToString());
    return 0;
}

int NFBattlePart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "server part package not handle:{}", packet.ToString());
    return 0;
}

int NFBattlePart::BroadCast(uint32_t nMsgId, const google::protobuf::Message &xData, bool IncludeMyself)
{
    return m_pMaster->BroadCast(nMsgId, xData, IncludeMyself);
}

int NFBattlePart::SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    return m_pMaster->SendMsgToClient(nMsgId, xData);
}

int NFBattlePart::SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    return m_pMaster->SendMsgToSnsServer(nMsgId, xData);
}

int NFBattlePart::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    return m_pMaster->SendMsgToWorldServer(nMsgId, xData);
}

int NFBattlePart::SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
    return m_pMaster->SendMsgToLogicServer(nMsgId, xData);
}
