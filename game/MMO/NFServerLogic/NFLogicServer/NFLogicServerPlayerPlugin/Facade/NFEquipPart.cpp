// -------------------------------------------------------------------------
//    @FileName         :    NFEquipPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFEquipPart
//
// -------------------------------------------------------------------------

#include "NFEquipPart.h"
#include "equip.pb.h"

NFEquipPart::NFEquipPart()
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

NFEquipPart::~NFEquipPart()
{
}

int NFEquipPart::CreateInit()
{
    return 0;
}

int NFEquipPart::ResumeInit()
{
    return 0;
}

int NFEquipPart::Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFEquipPart::UnInit()
{
    return NFPart::UnInit();
}

int NFEquipPart::RegisterMessage()
{
    return NFPart::RegisterMessage();
}

int NFEquipPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleClientMessage(msgId, packet);
}

int NFEquipPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

void NFEquipPart::SendAllEquip()
{
    proto_ff::NotifyEquipInfoRsp rsp;
    rsp.set_type(0);
    for (int32_t i = proto_ff::EEquipPos_none + 1; i < proto_ff::EEquipPos_limit; i++)
    {
        auto pDressEquip = m_equips.GetEquipInfo(i);
        if (pDressEquip)
        {
            pDressEquip->WriteToPB(*rsp.add_infos());
        }
    }
    m_pMaster->SendMsgToClient(proto_ff::NOTIFY_EQUIP_INFO_RSP, rsp);
}

void NFEquipPart::SendLvAttr()
{
    proto_ff::NotifyEquipLvAttrRsp rsp;
    for (auto& e : m_lvAttr)
    {
        auto pProto = rsp.add_lv_attr();
        if (pProto)
        {
            pProto->set_type(e.second.type);
            pProto->set_id(e.second.id);
        }
    }
    
    m_pMaster->SendMsgToClient(proto_ff::NOTIFY_EQUIP_LV_ATTR_RSP, rsp);
}

int NFEquipPart::OnLogin()
{
    SendAllEquip();
    SendLvAttr();
    return 0;
}
