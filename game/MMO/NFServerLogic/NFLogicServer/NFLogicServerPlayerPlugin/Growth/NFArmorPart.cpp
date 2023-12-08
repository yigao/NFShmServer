// -------------------------------------------------------------------------
//    @FileName         :    NFArmorPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFArmorPart
//
// -------------------------------------------------------------------------

#include "NFArmorPart.h"
#include "Armor.pb.h"

NFArmorPart::NFArmorPart()
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

NFArmorPart::~NFArmorPart()
{
}

int NFArmorPart::CreateInit()
{
    return 0;
}

int NFArmorPart::ResumeInit()
{
    return 0;
}

int NFArmorPart::Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFArmorPart::UnInit()
{
    return NFPart::UnInit();
}

int NFArmorPart::OnLogin()
{
    return NFPart::OnLogin();
}

int NFArmorPart::RegisterMessage()
{
    return NFPart::RegisterMessage();
}

int NFArmorPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleClientMessage(msgId, packet);
}

int NFArmorPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

void NFArmorPart::NotifyAllData()
{
    proto_ff::NotifyArmorRsp rsp;
    rsp.set_type(0);
    m_pMaster->SendMsgToClient(proto_ff::NOTIFY_ARMOR_RSP, rsp);
}
