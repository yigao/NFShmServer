// -------------------------------------------------------------------------
//    @FileName         :    NFMofaPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFMofaPart
//
// -------------------------------------------------------------------------

#include "NFMofaPart.h"

#include <Chat/NFChatMgr.h>
#include <NFLogicCommon/NFChatDefine.h>

#include "Mofa.pb.h"
#include "Package/NFPackagePart.h"
#include "DescStore/MofaLvexpDesc.h"
#include "DescStore/MofaDecomposeDesc.h"
#include "DescStore/MofaExchangeDesc.h"

NFMofaPart::NFMofaPart()
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

NFMofaPart::~NFMofaPart()
{
}

int NFMofaPart::CreateInit()
{
    return 0;
}

int NFMofaPart::ResumeInit()
{
    return 0;
}

int NFMofaPart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFMofaPart::UnInit()
{
    return NFPart::UnInit();
}

int NFMofaPart::LoadFromDB(const proto_ff::RoleDBData &data)
{
    auto &mofa = data.mofa();
    if (mofa.data_size() > 0)
    {
        for (int i = 0; i < (int) mofa.data_size(); i++)
        {
            auto &mofaPb = mofa.data(i);
            int slot_pos = mofaPb.slot().slot_pos();
            auto pEquipInfo = m_slotData.GetEquip(slot_pos);
            if (pEquipInfo)
            {
                pEquipInfo->ReadFromPB(mofaPb);
            }
        }
    }
    
    calcAttr(false);
    return 0;
}

int NFMofaPart::InitConfig(const proto_ff::RoleDBData &data)
{
    if (data.mofa().data_size() > 0) { return 0; }
    
    auto pMapCfg = MofaSetupDesc::Instance()->GetResDescPtr();
    for (auto iter = pMapCfg->begin(); iter != pMapCfg->end(); iter++)
    {
        auto pEquipInfo = m_slotData.GetEquip(iter->second.m_PositionID);
        if (pEquipInfo && iter->second.m_Unlock <= 0)
        {
            pEquipInfo->m_status = MoFa_EQUIP_SLOT_STATUS_UNLOCK;
        }
    }
    
    SetNeedSave(true);
    return 0;
}

int NFMofaPart::SaveDB(proto_ff::RoleDBData &dbData)
{
    for(int i = 0; i < (int)m_slotData.m_equips.size(); i++)
    {
        m_slotData.m_equips[i].WriteToPB(dbData.mutable_mofa()->add_data());
    }
    return 0;
}

int NFMofaPart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::CL_MOFA_GET_INFO_REQ);
    RegisterClientMessage(proto_ff::CL_MOFA_DRESS_REQ);
    RegisterClientMessage(proto_ff::CL_MOFA_UNDRESS_REQ);
    RegisterClientMessage(proto_ff::CL_MOFA_SLOT_ZUFU_REQ);
    RegisterClientMessage(proto_ff::CL_MOFA_SLOT_WAKE_REQ);
    RegisterClientMessage(proto_ff::CL_MOFA_EQUIP_LV_REQ);
    RegisterClientMessage(proto_ff::CL_MOFA_EQUIP_WAKE_REQ);
    RegisterClientMessage(proto_ff::CL_MOFA_EQUIP_DECOMPOSE_REQ);
    RegisterClientMessage(proto_ff::CL_MOFA_EXCHANGE_REQ);
    RegisterClientMessage(proto_ff::CL_MOFA_SLOT_UNLOCK_REQ);
    return 0;
}

int NFMofaPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch (msgId)
    {
        case proto_ff::CL_MOFA_GET_INFO_REQ://奇门八卦获取信息
        {
            OnHandleGetInfoReq(msgId, packet);
            break;
        }
        case proto_ff::CL_MOFA_DRESS_REQ://带上装备
        {
            OnHandleDressReq(msgId, packet);
            break;
        }
        case proto_ff::CL_MOFA_UNDRESS_REQ://卸载装备
        {
            OnHandleUnDressReq(msgId, packet);
            break;
        }
        case proto_ff::CL_MOFA_SLOT_ZUFU_REQ://阵眼祝福
        {
            OnHandleSlotZuFuReq(msgId, packet);
            break;
        }
        case proto_ff::CL_MOFA_SLOT_WAKE_REQ://阵眼觉醒
        {
            OnHandleSlotWakeReq(msgId, packet);
            break;
        }
        case proto_ff::CL_MOFA_EQUIP_LV_REQ://装备升级
        {
            OnHandleEquipLvReq(msgId, packet);
            break;
        }
        case proto_ff::CL_MOFA_EQUIP_WAKE_REQ://装备觉醒
        {
            OnHandleEquipWakeReq(msgId, packet);
            break;
        }
        case proto_ff::CL_MOFA_EQUIP_DECOMPOSE_REQ://装备一键分解
        {
            OnHandleDecomposeReq(msgId, packet);
            break;
        }
        case proto_ff::CL_MOFA_EXCHANGE_REQ://兑换
        {
            OnHandleExchangeReq(msgId, packet);
            break;
        }
        case proto_ff::CL_MOFA_SLOT_UNLOCK_REQ://奇门八卦
        {
            OnHandleSlotUnlockReq(msgId, packet);
            break;
        }
    }
    return 0;
}

int NFMofaPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

void NFMofaPart::calcAttr(bool sync)
{
    MAP_INT32_INT64 allAttr;
    MAP_INT32_INT64 partAttr;
    
    calcSlotAttr(partAttr);
    MergeAttr(partAttr, allAttr);
    partAttr.clear();
    
    PrintAttr(allAttr);
    
    for (auto &e: allAttr)
    {
        m_pMaster->SetAttrGroupCache(proto_ff::EAttrGroup_MoFa, e.first, e.second);
    }
    
    if (sync)
    {
        m_pMaster->SynAttrToClient();
    }
}

void NFMofaPart::MergeAttr(const MAP_INT32_INT64 &src, MAP_INT32_INT64 &dst)
{
    for (auto &e: src)
    {
        dst[e.first] += e.second;
    }
}

void NFMofaPart::PrintAttr(const MAP_INT32_INT64 &attr)
{

}

void NFMofaPart::calcSlotAttr(MAP_INT32_INT64 &all)
{
    m_slotData.calcAttr(all);
}

int NFMofaPart::OnHandleGetInfoReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::CLMoFaGetInfoReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::LCMoFaGetInfoRsp xDataRsp;
    for(int i = 0; i < (int)m_slotData.m_equips.size(); i++)
    {
        m_slotData.m_equips[i].WriteToPB(xDataRsp.add_data());
    }
    m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_GET_INFO_RSP, xDataRsp);
    return 0;
}

int NFMofaPart::OnHandleDressReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::CLMoFaDressReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    int32_t equip_pos = xData.equip_pos();
    int32_t bag_pos = xData.bag_pos();
    proto_ff::LCMoFaDressRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    if (pPackagePart == nullptr)
    {
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_DRESS_RSP, xDataRsp);
        return 0;
    }
    
    MoFaEquipSlot *pSlot = m_slotData.GetEquip(xData.slot_pos());
    if (pSlot == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, can't find the slot:%lu", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_DRESS_RSP, xDataRsp);
        return 0;
    }
    
    if (pSlot->m_status != MoFa_EQUIP_SLOT_STATUS_UNLOCK)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu not need unlock", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_DRESS_RSP, xDataRsp);
        return 0;
    }
    
    if (pSlot->m_isZuFu)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu zufu, can't dress", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_UNDRESS_RSP, xDataRsp);
        return 0;
    }
    
    if (!pSlot->ValidPos(equip_pos))
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu equip_pos:%lu is not valid", xData.slot_pos(), xData.equip_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_DRESS_RSP, xDataRsp);
        return 0;
    }
    
    auto pConfig = pSlot->GetConfig();
    if (pConfig == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "config error, the slot:%lu can't find the config", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_DRESS_RSP, xDataRsp);
        return 0;
    }
    
    NFMoFaEquip *pPackageEquip = dynamic_cast<NFMoFaEquip*>(pPackagePart->GetPackageItemByIndex(proto_ff::EPackageType_MoFa, bag_pos));
    if (!pPackageEquip)
    {
        xDataRsp.set_ret_code(proto_ff::RET_EQUIP_NOT_EXIST);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_DRESS_RSP, xDataRsp);
        return 0;
    }
    
    NFMoFaEquip tempEquip = *pPackageEquip;
    
    //已穿戴的装备
    proto_ff::NotifyPackageUpdate bagNotify;
    NFMoFaEquip *pSlotEquip = pSlot->GetEquip(equip_pos);
    if (pSlotEquip)
    {
        pSlotEquip->SetIndex(bag_pos);
        pPackagePart->SetItemByIndex(proto_ff::EPackageType_MoFa, bag_pos, pSlotEquip);
        //通知客户端更新
        pPackagePart->AddPackageUpdateInfo(pSlotEquip, bagNotify, 0);
        
        pSlot->m_slot.m_awaken_lv = 0;
    }
    else
    {
        pPackagePart->AddPackageUpdateInfo(&tempEquip, bagNotify, true); //删除背包装备，通知客户端
        pPackagePart->SetItemByIndex(proto_ff::EPackageType_MoFa, bag_pos, nullptr); //设置背包索引为空
    }
    
    pPackagePart->UpdatePackage(proto_ff::EPackageType_MoFa, bagNotify);
    tempEquip.SetIndex(bag_pos);
    tempEquip.SetBind(NFItemMgr::BindStateByWay(tempEquip.GetItemID(), tempEquip.GetBind()));
    pSlot->SetEquip(equip_pos, tempEquip);
    
    SetNeedSave(true);
    calcAttr(true);
    pSlot->WriteToPB(xDataRsp.mutable_data());
    m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_DRESS_RSP, xDataRsp);
    return 0;
}

int NFMofaPart::OnHandleUnDressReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::CLMoFaUnDressReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    int32_t equip_pos = xData.equip_pos();
    proto_ff::LCMoFaUnDressRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    if (pPackagePart == nullptr)
    {
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_UNDRESS_RSP, xDataRsp);
        return 0;
    }
    
    MoFaEquipSlot *pSlot = m_slotData.GetEquip(xData.slot_pos());
    if (pSlot == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, can't find the slot:%lu", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_UNDRESS_RSP, xDataRsp);
        return 0;
    }
    
    if (pSlot->m_status != MoFa_EQUIP_SLOT_STATUS_UNLOCK)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu not need unlock", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_UNDRESS_RSP, xDataRsp);
        return 0;
    }
    
    if (pSlot->m_isZuFu)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu zufu, can't undress", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_UNDRESS_RSP, xDataRsp);
        return 0;
    }
    
    auto pEquip = pSlot->GetEquip(equip_pos);
    if (pEquip == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu equip_pos:%lu no equip", xData.slot_pos(), xData.equip_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_UNDRESS_RSP, xDataRsp);
        return 0;
    }
    
    auto pConfig = pSlot->GetConfig();
    if (pConfig == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "config error, the slot:%lu can't find the config", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_UNDRESS_RSP, xDataRsp);
        return 0;
    }
    
    VEC_ITEM_PROTO_EX vecItemProto;
    proto_ff::ItemProtoInfo itemProto;
    NFItemMgr::SetItemProtoInfo(pEquip, &itemProto, 1);
    vecItemProto.push_back(itemProto);
    SCommonSource ss;
    ss.src = S_MoFa_UnDress_Equip;
    ss.param1 = pEquip->GetItemID();
    if (!pPackagePart->AddItem(vecItemProto, ss))
    {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_COMMON_SPACE_NOT_ENOUGH);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_UNDRESS_RSP, xDataRsp);
        return 0;
    }
    
    pSlot->SetEquip(equip_pos, nullptr);
    pSlot->m_slot.m_awaken_lv = 0;
    
    SetNeedSave(true);
    calcAttr(true);
    pSlot->WriteToPB(xDataRsp.mutable_data());
    m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_UNDRESS_RSP, xDataRsp);
    return 0;
}

int NFMofaPart::OnHandleSlotZuFuReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::CLMoFaSlotZuFuReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::LCMoFaSlotZuFuRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    NFPackagePart *pNFPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    if (pNFPackagePart == nullptr)
    {
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_ZUFU_RSP, xDataRsp);
        return 0;
    }
    
    MoFaEquipSlot *pSlot = m_slotData.GetEquip(xData.slot_pos());
    if (pSlot == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, can't find the slot:%lu", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_ZUFU_RSP, xDataRsp);
        return 0;
    }
    
    if (pSlot->m_status != MoFa_EQUIP_SLOT_STATUS_UNLOCK)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu not need unlock", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_ZUFU_RSP, xDataRsp);
        return 0;
    }
    
    if (pSlot->m_isZuFu)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu has zufu", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_ZUFU_RSP, xDataRsp);
        return 0;
    }
    
    if (pSlot->IsCanZufu() == false)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu not can zufu", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_ZUFU_RSP, xDataRsp);
        return 0;
    }
    
    auto pConfig = pSlot->GetConfig();
    if (pConfig == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "config error, the slot:%lu can't find the config", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_ZUFU_RSP, xDataRsp);
        return 0;
    }
    
    if (pConfig->m_Bless > 0)
    {
        SCommonSource sourceParam;
        sourceParam.src = S_MoFa_ZuFu;
        sourceParam.param1 = xData.slot_pos();
        if (!pNFPackagePart->RemoveItem(pConfig->m_Bless, 1, sourceParam))
        {
            xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
            m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_ZUFU_RSP, xDataRsp);
            return 0;
        }
    }
    
    pSlot->m_isZuFu = true;
    SetNeedSave(true);
    calcAttr(true);
    pSlot->WriteToPB(xDataRsp.mutable_data());
    m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_ZUFU_RSP, xDataRsp);
    return 0;
}

int NFMofaPart::OnHandleSlotWakeReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::CLMoFaSlotWakeReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::LCMoFaSlotWakeRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    NFPackagePart *pNFPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    if (pNFPackagePart == nullptr)
    {
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_WAKE_RSP, xDataRsp);
        return 0;
    }
    
    MoFaEquipSlot *pSlot = m_slotData.GetEquip(xData.slot_pos());
    if (pSlot == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, can't find the slot:%lu", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_WAKE_RSP, xDataRsp);
        return 0;
    }
    
    if (pSlot->m_status != MoFa_EQUIP_SLOT_STATUS_UNLOCK)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu not need unlock", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_WAKE_RSP, xDataRsp);
        return 0;
    }
    
    if (pSlot->IsCanWake() == false)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu not wake", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_WAKE_RSP, xDataRsp);
        return 0;
    }
    
    pSlot->m_slot.m_awaken_lv++;
    
    SetNeedSave(true);
    calcAttr(true);
    pSlot->WriteToPB(xDataRsp.mutable_data());
    m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_WAKE_RSP, xDataRsp);

    SystemChatMsgData msg;
    msg.text.push_back(m_pMaster->GetName());
    msg.params.push_back(xData.slot_pos());
    NFChatMgr::Instance(m_pObjPluginManager)->SendG2WBroadcast(BT_MOFA_SLOT_STRONG_QUALITY, msg, 0, m_pMaster->GetZid());
    return 0;
}

int NFMofaPart::OnHandleEquipLvReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::CLMoFaEquipLvReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::LCMoFaEquipLvRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    NFPackagePart *pNFPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    if (pNFPackagePart == nullptr)
    {
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_LV_RSP, xDataRsp);
        return 0;
    }
    
    MoFaEquipSlot *pSlot = m_slotData.GetEquip(xData.slot_pos());
    if (pSlot == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, can't find the slot:%lu", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_LV_RSP, xDataRsp);
        return 0;
    }
    
    if (pSlot->m_status != MoFa_EQUIP_SLOT_STATUS_UNLOCK)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu not need unlock", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_LV_RSP, xDataRsp);
        return 0;
    }
    
    auto pEquip = pSlot->GetEquip(xData.equip_pos());
    if (pEquip == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu equip pos:%lu no equip", xData.slot_pos(), xData.equip_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_LV_RSP, xDataRsp);
        return 0;
    }
    
    auto pEquipCfg = MofaYuansuDesc::Instance()->GetDesc(pEquip->GetItemID());
    if (pEquipCfg == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu equip pos:%lu equip:%lu cfg error", xData.slot_pos(), xData.equip_pos(), pEquip->GetItemID());
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_LV_RSP, xDataRsp);
        return 0;
    }
    
    int64_t nUnBindNum = 0;
    int64_t nBindNum = 0;
    int64_t itemNum = pNFPackagePart->GetItemNum(pEquipCfg->m_LvItem, nUnBindNum, nBindNum);
    
    if (itemNum > 0)
    {
        auto pCurCfg = MofaLvexpDesc::Instance()->GetDesc(pEquip->m_mofa.m_stronglv);
        if (pCurCfg == NULL)
        {
            xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
            m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_LV_RSP, xDataRsp);
            return 0;
        }
        
        auto pNextCfg = MofaLvexpDesc::Instance()->GetDesc(pEquip->m_mofa.m_stronglv+1);
        if (pNextCfg == NULL)
        {
            xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
            m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_LV_RSP, xDataRsp);
            return 0;
        }
        
        if (itemNum < pCurCfg->m_exp)
        {
            xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
            m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_LV_RSP, xDataRsp);
            return 0;
        }
    }
    else {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_LV_RSP, xDataRsp);
        return 0;
    }
    
    uint32_t strongLv = pEquip->m_mofa.m_stronglv;
    uint32_t needNum = 0;
    do
    {
        auto pCurCfg = MofaLvexpDesc::Instance()->GetDesc(strongLv);
        if (pCurCfg == NULL)
        {
            break;
        }
        
        auto pNextCfg = MofaLvexpDesc::Instance()->GetDesc(strongLv+1);
        if (pNextCfg == NULL)
        {
            break;
        }
        
        if (needNum + pCurCfg->m_exp > itemNum)
        {
            break;
        }
        
        needNum += pCurCfg->m_exp;
        strongLv++;
        break;
    } while(true);
    
    SCommonSource sourceParam;
    sourceParam.src = S_MoFa_Equip_LV;
    sourceParam.param1 = xData.slot_pos();
    sourceParam.param2 = xData.equip_pos();
    sourceParam.param3 = pEquip->GetItemID();
    if (!pNFPackagePart->RemoveItem(pEquipCfg->m_LvItem, needNum, sourceParam))
    {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_LV_RSP, xDataRsp);
        return 0;
    }
    
    pEquip->m_mofa.m_stronglv = strongLv;
    
    SetNeedSave(true);
    calcAttr(true);
    pSlot->WriteToPB(xDataRsp.mutable_data());
    m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_LV_RSP, xDataRsp);
    return 0;
}

int NFMofaPart::OnHandleEquipWakeReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::CLMoFaEquipWakeReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::LCMoFaEquipWakeRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    NFPackagePart *pNFPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    if (pNFPackagePart == nullptr)
    {
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_WAKE_RSP, xDataRsp);
        return 0;
    }
    
    MoFaEquipSlot *pSlot = m_slotData.GetEquip(xData.slot_pos());
    if (pSlot == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, can't find the slot:%lu", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_WAKE_RSP, xDataRsp);
        return 0;
    }
    
    if (pSlot->m_status != MoFa_EQUIP_SLOT_STATUS_UNLOCK)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu not need unlock", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_WAKE_RSP, xDataRsp);
        return 0;
    }
    
    auto pEquip = pSlot->GetEquip(xData.equip_pos());
    if (pEquip == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu equip pos:%lu no equip", xData.slot_pos(), xData.equip_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_WAKE_RSP, xDataRsp);
        return 0;
    }
    
    auto pEquipCfg = MofaYuansuDesc::Instance()->GetDesc(pEquip->GetItemID());
    if (pEquipCfg == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu equip pos:%lu equip:%lu cfg error", xData.slot_pos(), xData.equip_pos(), pEquip->GetItemID());
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_WAKE_RSP, xDataRsp);
        return 0;
    }
    
    if (pEquipCfg->m_awaken_can <= 0)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu equip pos:%lu equip:%lu not can awake", xData.slot_pos(), xData.equip_pos(), pEquip->GetItemID());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_WAKE_RSP, xDataRsp);
        return 0;
    }
    
    int32_t wakeLv = pEquip->m_mofa.m_awaken_lv;
    
    if ((int)wakeLv >= (int)pEquipCfg->m_awaken_Lvmax || (int)wakeLv >= (int)pEquipCfg->m_awaken.size())
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu equip pos:%lu equip:%lu awake than max", xData.slot_pos(), xData.equip_pos(), pEquip->GetItemID());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_WAKE_RSP, xDataRsp);
        return 0;
    }
    
    int needMax = 0;
    for(int i = wakeLv; i < (int)pEquipCfg->m_awaken.size(); i++)
    {
        needMax += pEquipCfg->m_awaken[i].m_num;
    }
    
    MAP_UINT16_INT64 mapIndexItem;
    int points = pEquip->m_mofa.m_awaken_exp;
    if (points < needMax)
    {
        for(int i = 0; i < (int)xData.grid_list_size(); i++)
        {
            int gridIndex = xData.grid_list(i);
            NFMoFaEquip *pCostEquip = dynamic_cast<NFMoFaEquip *>(pNFPackagePart->GetPackageItemByIndex(proto_ff::EPackageType_MoFa, gridIndex));
            if (!pCostEquip)
            {
                xDataRsp.set_ret_code(proto_ff::RET_EQUIP_NOT_EXIST);
                m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_WAKE_RSP, xDataRsp);
                return 0;
            }
            
            if (pEquipCfg->m_awaken_item != (int)pCostEquip->GetItemID()) continue;
            
            points += 1;
            points += pCostEquip->m_mofa.m_awaken_exp;
            for(int x = 0; x < (int)pCostEquip->m_mofa.m_awaken_lv && x < (int)pEquipCfg->m_awaken.size(); x++)
            {
                points += pEquipCfg->m_awaken[x].m_num;
            }
            
            mapIndexItem[gridIndex] = 1;
            
            if (points >= needMax)
            {
                break;
            }
        }
    }
    
    SCommonSource sourceParam;
    sourceParam.src = S_MoFa_Equip_WAKE;
    sourceParam.param1 = xData.slot_pos();
    sourceParam.param2 = xData.equip_pos();
    sourceParam.param3 = pEquip->GetItemID();
    if (!pNFPackagePart->RemoveItem(proto_ff::EPackageType_MoFa, mapIndexItem, sourceParam))
    {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_WAKE_RSP, xDataRsp);
        return 0;
    }
    
    int needExp = pEquipCfg->m_awaken[wakeLv].m_num;
    while(points >= needExp)
    {
        points -= needExp;
        wakeLv++;
        
        if ((int)wakeLv < (int)pEquipCfg->m_awaken_Lvmax && (int)wakeLv < (int)pEquipCfg->m_awaken.size())
        {
            needExp = pEquipCfg->m_awaken[wakeLv].m_num;
        }
        else
        {
            break;
        }
    }
    
    pEquip->m_mofa.m_awaken_lv = wakeLv;
    pEquip->m_mofa.m_awaken_exp = points;
    
    SetNeedSave(true);
    calcAttr(true);
    pSlot->WriteToPB(xDataRsp.mutable_data());
    m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_WAKE_RSP, xDataRsp);
    return 0;
}

int NFMofaPart::OnHandleDecomposeReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::CLMoFaEquipDecomposeReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::LCMoFaEquipDecomposeRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    NFPackagePart *pPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    if (pPackagePart == nullptr)
    {
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_DECOMPOSE_RSP, xDataRsp);
        return 0;
    }
    
    MAP_UINT16_INT64 mapIndexItem;
    SCommonSource sourceParam;
    sourceParam.src = S_MoFa_Decompose;
    list<SItem> itemList;
    for(int i = 0; i < (int)xData.grid_list_size(); i++)
    {
        int gridIndex = xData.grid_list(i);
        NFMoFaEquip* pEquip = dynamic_cast<NFMoFaEquip *>(pPackagePart->GetPackageItemByIndex(proto_ff::EPackageType_MoFa, gridIndex));
        if (!pEquip)
        {
            xDataRsp.set_ret_code(proto_ff::RET_EQUIP_NOT_EXIST);
            m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_DECOMPOSE_RSP, xDataRsp);
            return 0;
        }
        
        auto pEquipCfg = pEquip->GetEquipCfg();
        if (!pEquipCfg)
        {
            xDataRsp.set_ret_code(proto_ff::RET_EQUIP_NOT_EXIST);
            m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_DECOMPOSE_RSP, xDataRsp);
            return 0;
        }
        
        auto pDecomposeCfg = MofaDecomposeDesc::Instance()->GetDesc(pEquipCfg->m_quality);
        if (!pDecomposeCfg)
        {
            continue;
        }
        
        if (pDecomposeCfg->m_DpItem > 0 && pDecomposeCfg->m_DpEss > 0)
        {
            itemList.push_back(SItem(pDecomposeCfg->m_DpItem, pDecomposeCfg->m_DpEss));
        }
        
        mapIndexItem[gridIndex] = 1;
    }
    
    if (!pPackagePart->CanAddItem(itemList))
    {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_COMMON_SPACE_NOT_ENOUGH);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_DECOMPOSE_RSP, xDataRsp);
        return 0;
    }
    
    if (!pPackagePart->RemoveItem(proto_ff::EPackageType_MoFa, mapIndexItem, sourceParam))
    {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_DECOMPOSE_RSP, xDataRsp);
        return 0;
    }
    
    pPackagePart->AddItem(itemList, sourceParam, true, true);
    
    m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EQUIP_DECOMPOSE_RSP, xDataRsp);
    return 0;
}

int NFMofaPart::OnHandleExchangeReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::CLMoFaExchangeReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::LCMoFaExchangeRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    auto pCfg = MofaExchangeDesc::Instance()->GetDesc(xData.exchange_id());
    if (pCfg == NULL)
    {
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EXCHANGE_RSP, xDataRsp);
        return 0;
    }
    
    NFPackagePart *pNFPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    if (pNFPackagePart == nullptr)
    {
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EXCHANGE_RSP, xDataRsp);
        return 0;
    }
    
    LIST_ITEM lstItem;
    lstItem.push_back(SItem(pCfg->m_EquipID, 1));
    if (!pNFPackagePart->CanAddItem(lstItem))
    {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_COMMON_SPACE_NOT_ENOUGH);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EXCHANGE_RSP, xDataRsp);
        return 0;
    }
    
    SCommonSource sourceParam;
    sourceParam.src = S_MoFa_Exchange;
    sourceParam.param1 = xData.exchange_id();
    if (!pNFPackagePart->RemoveItem(pCfg->m_EcItem, pCfg->m_EcNum, sourceParam))
    {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EXCHANGE_RSP, xDataRsp);
        return 0;
    }
    
    if (!pNFPackagePart->AddItem(lstItem, sourceParam))
    {
        xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_COMMON_SPACE_NOT_ENOUGH);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EXCHANGE_RSP, xDataRsp);
        return 0;
    }
    
    m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_EXCHANGE_RSP, xDataRsp);
    return 0;
}

int NFMofaPart::OnHandleSlotUnlockReq(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::CLMoFaSlotUnlockReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);
    
    proto_ff::CLMoFaSlotUnlockRsp xDataRsp;
    xDataRsp.set_ret_code(proto_ff::RET_SUCCESS);
    
    MoFaEquipSlot *pSlot = m_slotData.GetEquip(xData.slot_pos());
    if (pSlot == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, can't find the slot:%lu", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_UNLOCK_RSP, xDataRsp);
        return 0;
    }
    
    if (pSlot->m_status != MoFa_EQUIP_SLOT_STATUS_NONE)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "client param error, the slot:%lu not need unlock", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_UNLOCK_RSP, xDataRsp);
        return 0;
    }
    
    NFPackagePart *pNFPackagePart = dynamic_cast<NFPackagePart *>(m_pMaster->GetPart(PART_PACKAGE));
    if (pNFPackagePart == nullptr)
    {
        xDataRsp.set_ret_code(proto_ff::RET_PARMAR_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_UNLOCK_RSP, xDataRsp);
        return 0;
    }
    
    auto pConfig = pSlot->GetConfig();
    if (pConfig == NULL)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), 0, "config error, the slot:%lu can't find the config", xData.slot_pos());
        xDataRsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_UNLOCK_RSP, xDataRsp);
        return 0;
    }
    
    SCommonSource sourceParam;
    if (pConfig->m_Unlock > 0)
    {
        if (!pNFPackagePart->RemoveItem(pConfig->m_Unlock, 1, sourceParam))
        {
            xDataRsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
            m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_UNLOCK_RSP, xDataRsp);
            return 0;
        }
    }
    
    pSlot->m_status = MoFa_EQUIP_SLOT_STATUS_UNLOCK;
    SetNeedSave(true);
    calcAttr(true);
    pSlot->WriteToPB(xDataRsp.mutable_data());
    m_pMaster->SendMsgToClient(proto_ff::LC_MOFA_SLOT_UNLOCK_RSP, xDataRsp);
    return 0;
}
