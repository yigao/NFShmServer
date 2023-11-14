// -------------------------------------------------------------------------
//    @FileName         :    NFMiniPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFMiniPart
//
// -------------------------------------------------------------------------

#include "NFMiniPart.h"
#include "ClientServer.pb.h"
#include "NFVipPart.h"

NFMiniPart::NFMiniPart()
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

NFMiniPart::~NFMiniPart()
{
}

int NFMiniPart::CreateInit()
{
    return 0;
}

int NFMiniPart::ResumeInit()
{
    return 0;
}

int NFMiniPart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFMiniPart::UnInit()
{
    return NFPart::UnInit();
}

int NFMiniPart::LoadFromDB(const proto_ff::RoleDBData &data)
{
    return NFPart::LoadFromDB(data);
}

int NFMiniPart::SaveDB(proto_ff::RoleDBData &dbData)
{
    return NFPart::SaveDB(dbData);
}

int NFMiniPart::OnLogin()
{
    return NFPart::OnLogin();
}

int NFMiniPart::OnLogin(proto_ff::PlayerInfoRsp &playerInfo)
{
    return NFPart::OnLogin(playerInfo);
}

int NFMiniPart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_LOGIN_HANGUP_DATA_REQ);
    return 0;
}

int NFMiniPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_TO_LOGIC_LOGIN_HANGUP_DATA_REQ:
        {
            OnHandleLoginHangUpDataReq(msgId, packet);
            break;
        }
        default:
            break;
    }
    return 0;
}

int NFMiniPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

int NFMiniPart::OnHandleLoginHangUpDataReq(uint32_t msgId, NFDataPackage &packet)
{
    SendHangupData();
    return 0;
}

void NFMiniPart::SendHangupData()
{
    proto_ff::PlayerLoginHangUpDataRsp rsp;
    rsp.set_hangup_time(m_hangUpData.m_hangup_time);
    rsp.set_hangup_surplus_time(m_hangUpData.m_login_surplus_hangup_time);
    rsp.set_add_exp(m_hangUpData.m_add_hangup_exp);
    rsp.set_before_lv(m_hangUpData.m_hangup_before_lv);
    rsp.set_after_lv(m_hangUpData.m_hangup_after_lv);
    rsp.set_before_fight(m_hangUpData.m_hangup_before_fight);
    rsp.set_after_fight(m_hangUpData.m_hangup_after_fight);
    
    for (auto &e : this->m_hangUpData.m_dropItem)
    {
        proto_ff::ComPair64 *pProto = rsp.add_items();
        if (pProto)
        {
            pProto->set_key(e.first);
            pProto->set_value(e.second);
        }
    }
    
    //vip¼Ó³É
    int32_t vipAdd = 0;
    NFVipPart* pVipPart = dynamic_cast<NFVipPart*>(m_pMaster->GetPart(PART_VIP));
    if (pVipPart)
    {
        vipAdd = pVipPart->PrivilegeVal(proto_ff::VIP_PRIVILEGE_OFFLINE_EXP_ADD);
    }
    
    rsp.add_add_value(vipAdd);
    
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_LOGIN_HANGUP_DATA_RSP, rsp);
}
