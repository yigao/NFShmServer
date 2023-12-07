// -------------------------------------------------------------------------
//    @FileName         :    NFPetPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFPetPart
//
// -------------------------------------------------------------------------

#include "NFPetPart.h"
#include "Pet.pb.h"

NFPetPart::NFPetPart()
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

NFPetPart::~NFPetPart()
{
}

int NFPetPart::CreateInit()
{
    return 0;
}

int NFPetPart::ResumeInit()
{
    return 0;
}

int NFPetPart::Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFPetPart::UnInit()
{
    return NFPart::UnInit();
}

int NFPetPart::RegisterMessage()
{
    return 0;
}

int NFPetPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleClientMessage(msgId, packet);
}

int NFPetPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

int NFPetPart::OnLogin()
{
    SendAllData();
    return 0;
}

void NFPetPart::SendAllData()
{
    proto_ff::NotifyPetModuleRsp nt;
    
    m_pMaster->SendMsgToClient(proto_ff::NOTIFY_PET_MODULE_RSP, nt);
}
