// -------------------------------------------------------------------------
//    @FileName         :    NFMountPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMountPart
//
// -------------------------------------------------------------------------

#include "NFMountPart.h"
#include "ClientServer.pb.h"
#include "DescStore/AttributeAttributeDesc.h"

NFMountPart::NFMountPart()
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

NFMountPart::~NFMountPart()
{
}

int NFMountPart::CreateInit()
{
    return 0;
}

int NFMountPart::ResumeInit()
{
    return 0;
}

int NFMountPart::Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFMountPart::UnInit()
{
    return NFPart::UnInit();
}

int NFMountPart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_MOUNT_INFO_REQ);
    return 0;
}

int NFMountPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_TO_LOGIC_MOUNT_INFO_REQ:
        {
            OnHandleMountInfoReq(msgId, packet);
            break;
        }
        default:break;
    }
    return 0;
}

int NFMountPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

int NFMountPart::OnHandleMountInfoReq(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::MountInfoRsp rsp;
    rsp.set_mount_id(m_nMountID);
    rsp.set_mount_lev(m_nMountLev);
    rsp.set_mount_exp(m_nMountExp);
    rsp.set_mount_model_id(m_nMountModelId);
    
    for (auto iter = m_mapFragment.begin(); iter != m_mapFragment.end(); iter++)
    {
        proto_ff::MountFragmentData *pData = rsp.add_fragment_data();
        if (pData)
        {
            pData->set_fragment_id(iter->first);
            pData->set_use_times(iter->second);
        }
    }
    
    for (auto iter = m_mapSkill.begin(); iter != m_mapSkill.end(); iter++)
    {
        proto_ff::MountSkillData *pData = rsp.add_skill_data();
        if (pData)
        {
            pData->set_skill_id(iter->first);
            pData->set_skill_lev(iter->second);
        }
    }
    
    rsp.set_fight_value(GetFightValue());
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_MOUNT_INFO_RSP, rsp);
    return 0;
}

int64_t NFMountPart::GetFightValue()
{
    MAP_UINT32_INT64 mapAttr;
    m_pMaster->GetAttrGroup(proto_ff::EAttrGroup_MOUNT, mapAttr);
    
    double nFightTotal = 0;
    for (auto iterAttr = mapAttr.begin(); iterAttr != mapAttr.end(); iterAttr++)
    {
        auto pCfg = AttributeAttributeDesc::Instance()->GetDesc(iterAttr->first);
        if (pCfg)
        {
            nFightTotal += iterAttr->second * pCfg->m_power;
        }
    }
    
    return nFightTotal;
}
