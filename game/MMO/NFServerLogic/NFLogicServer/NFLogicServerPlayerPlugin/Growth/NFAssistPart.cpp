// -------------------------------------------------------------------------
//    @FileName         :    NFAssistPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFAssistPart
//
// -------------------------------------------------------------------------

#include "NFAssistPart.h"
#include "Assist.pb.h"

NFAssistPart::NFAssistPart()
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

NFAssistPart::~NFAssistPart()
{
}

int NFAssistPart::CreateInit()
{
    return 0;
}

int NFAssistPart::ResumeInit()
{
    return 0;
}

int NFAssistPart::Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFAssistPart::UnInit()
{
    return NFPart::UnInit();
}

int NFAssistPart::OnLogin()
{
    NotifyData();
    return 0;
}

int NFAssistPart::RegisterMessage()
{
    return NFPart::RegisterMessage();
}

int NFAssistPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleClientMessage(msgId, packet);
}

int NFAssistPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

void NFAssistPart::NotifyData()
{
    proto_ff::NotifyRoleAssist rsp;
    rsp.set_prestige(m_dayPrestige);
    rsp.set_helpnum(m_helpNum);
    rsp.set_sendnum(m_sendNum);
    
    for (auto& e : m_rewardIds)
    {
        rsp.add_rewardids(e);
    }
    m_pMaster->SendMsgToClient(proto_ff::NOTIFY_ROLE_ASSIST, rsp);
}
