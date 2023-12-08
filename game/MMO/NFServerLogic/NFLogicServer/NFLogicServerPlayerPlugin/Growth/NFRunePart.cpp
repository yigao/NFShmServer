// -------------------------------------------------------------------------
//    @FileName         :    NFRunePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFRunePart
//
// -------------------------------------------------------------------------

#include "NFRunePart.h"
#include "Rune.pb.h"

NFRunePart::NFRunePart()
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

NFRunePart::~NFRunePart()
{
}

int NFRunePart::CreateInit()
{
    return 0;
}

int NFRunePart::ResumeInit()
{
    return 0;
}

int NFRunePart::Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFRunePart::UnInit()
{
    return NFPart::UnInit();
}

int NFRunePart::RegisterMessage()
{
    return NFPart::RegisterMessage();
}

int NFRunePart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleClientMessage(msgId, packet);
}

int NFRunePart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

void NFRunePart::NFRunePart::SendAllData()
{
    proto_ff::NotifyRuneList nt;
    nt.set_type(1);
    m_pMaster->SendMsgToClient(proto_ff::NOTIFY_RUNE_LIST, nt);
}

int NFRunePart::OnLogin()
{
    SendAllData();
    return 0;
}
