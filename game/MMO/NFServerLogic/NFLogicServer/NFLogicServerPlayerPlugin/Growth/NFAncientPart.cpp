// -------------------------------------------------------------------------
//    @FileName         :    NFAncientPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFAncientPart
//
// -------------------------------------------------------------------------

#include "NFAncientPart.h"
#include "Ancient.pb.h"

NFAncientPart::NFAncientPart()
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

NFAncientPart::~NFAncientPart()
{
}

int NFAncientPart::CreateInit()
{
    return 0;
}

int NFAncientPart::ResumeInit()
{
    return 0;
}

int NFAncientPart::Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFAncientPart::UnInit()
{
    return NFPart::UnInit();
}

int NFAncientPart::OnLogin()
{
    NotifyAllData();
    return 0;
}

int NFAncientPart::RegisterMessage()
{
    return NFPart::RegisterMessage();
}

int NFAncientPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleClientMessage(msgId, packet);
}

int NFAncientPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

void NFAncientPart::NotifyAllData()
{
    proto_ff::NotifyAncient nt;
    nt.set_type(0);
    nt.set_unlock_star_id(0);
    
    m_pMaster->SendMsgToClient(proto_ff::NOTIFY_ANCIENT, nt);
}
