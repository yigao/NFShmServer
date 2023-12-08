// -------------------------------------------------------------------------
//    @FileName         :    NFBestEQPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFBestEQPart
//
// -------------------------------------------------------------------------

#include "NFBestEQPart.h"
#include "BestEQ.pb.h"

NFBestEQPart::NFBestEQPart()
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

NFBestEQPart::~NFBestEQPart()
{
}

int NFBestEQPart::CreateInit()
{
    return 0;
}

int NFBestEQPart::ResumeInit()
{
    return 0;
}

int NFBestEQPart::Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFBestEQPart::UnInit()
{
    return NFPart::UnInit();
}

int NFBestEQPart::OnLogin()
{
    SendAllData();
    return 0;
}

int NFBestEQPart::RegisterMessage()
{
    return NFPart::RegisterMessage();
}

int NFBestEQPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleClientMessage(msgId, packet);
}

int NFBestEQPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

void NFBestEQPart::SendAllData()
{
    proto_ff::NotifyBestEQData nt;
    m_pMaster->SendMsgToClient(proto_ff::NOTIFY_BEST_EQ_DATA, nt);
}
