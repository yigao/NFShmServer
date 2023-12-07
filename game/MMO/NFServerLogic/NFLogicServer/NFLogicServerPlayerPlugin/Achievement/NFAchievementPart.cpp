// -------------------------------------------------------------------------
//    @FileName         :    NFAchievementPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFAchievementPart
//
// -------------------------------------------------------------------------

#include "NFAchievementPart.h"
#include "ClientServer.pb.h"

NFAchievementPart::NFAchievementPart()
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

NFAchievementPart::~NFAchievementPart()
{
}

int NFAchievementPart::CreateInit()
{
    return 0;
}

int NFAchievementPart::ResumeInit()
{
    return 0;
}

int NFAchievementPart::Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFAchievementPart::UnInit()
{
    return NFPart::UnInit();
}

int NFAchievementPart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_ACHIEVEMENT_INFO_REQ);
    return 0;
}

int NFAchievementPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_TO_LOGIC_ACHIEVEMENT_INFO_REQ:
        {
            OnHandleAchievementInfoReq(msgId, packet);
            break;
        }
        default:break;
    }
    return 0;
}

int NFAchievementPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

int NFAchievementPart::OnHandleAchievementInfoReq(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::CGAchievementInfoReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    SendAchievementInfo();
    return 0;
}

void NFAchievementPart::SendAchievementInfo()
{
    proto_ff::GCAchievementInfoRsp rsp;
    auto pAch = rsp.mutable_data();
    if (pAch == NULL) return;
    
    pAch->set_ach_point(m_pMaster->GetAttr(proto_ff::A_ACH_POINT));
    
    for (auto iter = m_achMap.begin(); iter != m_achMap.end(); iter++)
    {
        pAch->add_ach_data()->CopyFrom(iter->second);
    }
    
    for (auto iter = m_achTotalMap.begin(); iter != m_achTotalMap.end(); iter++)
    {
        pAch->add_ach_total_data()->CopyFrom(iter->second);
    }
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_ACHIEVEMENT_INFO_RSP, rsp);
}
