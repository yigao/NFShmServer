// -------------------------------------------------------------------------
//    @FileName         :    NFConvoyPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFConvoyPart
//
// -------------------------------------------------------------------------

#include "NFConvoyPart.h"
#include "Convoy.pb.h"

NFConvoyPart::NFConvoyPart()
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

NFConvoyPart::~NFConvoyPart()
{
}

int NFConvoyPart::CreateInit()
{
    return 0;
}

int NFConvoyPart::ResumeInit()
{
    return 0;
}

int NFConvoyPart::Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFConvoyPart::UnInit()
{
    return NFPart::UnInit();
}

int NFConvoyPart::OnLogin()
{
    SendAllData();
    return 0;
}

int NFConvoyPart::RegisterMessage()
{
    return NFPart::RegisterMessage();
}

int NFConvoyPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleClientMessage(msgId, packet);
}

int NFConvoyPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

void NFConvoyPart::SendAllData()
{
    proto_ff::NotifyConvoyInfo nt;
    nt.set_daynum(m_dayNum);
    nt.set_endtime(m_endTime);
    nt.set_genescortid(m_genEscortId);
    nt.set_freenum(m_freeNum);
    m_pMaster->SendMsgToClient(proto_ff::NOTIFY_CONVOY_INFO, nt);
}
