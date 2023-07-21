// -------------------------------------------------------------------------
//    @FileName         :    NFSnsJettonPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsJettonPart
//
// -------------------------------------------------------------------------

#include "NFSnsJettonPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

#include "Cache/NFCacheMgr.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFSnsJettonPart, EOT_NFSnsJettonPart_ID, NFSnsPart)

NFSnsJettonPart::NFSnsJettonPart()
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

NFSnsJettonPart::~NFSnsJettonPart()
{
}

int NFSnsJettonPart::CreateInit()
{
    m_isCanUseBank = false;
    return 0;
}

int NFSnsJettonPart::ResumeInit()
{
    return 0;
}

int NFSnsJettonPart::Init(NFPlayerDetail *pMaster, uint32_t partType, const proto_ff::tbFishSnsPlayerDetailData &data, bool bCreatePlayer)
{
    return NFSnsPart::Init(pMaster, partType, data, bCreatePlayer);
}

int NFSnsJettonPart::UnInit()
{
    return NFSnsPart::UnInit();
}

int NFSnsJettonPart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::NF_CS_BANK_SET_PASSWORD_REQ);
    RegisterClientMessage(proto_ff::NF_CS_BANK_GIVE_BANK_JETTON_REQ, true);
    RegisterClientMessage(proto_ff::NF_CS_BANK_GET_RECORD_REQ);

    RegisterServerMessage(proto_ff::NF_CS_BANK_GET_DATA_REQ);
    AddRpcService<proto_ff::NF_LTS_PLAYER_ADD_BANK_JETTON_RPC>(this, &NFSnsJettonPart::AddBankJettonService);
    AddRpcService<proto_ff::NF_LTS_PLAYER_REDUCE_BANK_JETTON_RPC>(this, &NFSnsJettonPart::ReduceBankJettonService);
    return 0;
}

int NFSnsJettonPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch(msgId)
    {
        case proto_ff::NF_CS_BANK_SET_PASSWORD_REQ:
        {
            OnHandleBankSetPasswordReq(msgId, packet);
            break;
        }
        case proto_ff::NF_CS_BANK_GIVE_BANK_JETTON_REQ:
        {
            OnHandleBankGiveBankJettonReq(msgId, packet);
            break;
        }
        case proto_ff::NF_CS_BANK_GET_RECORD_REQ:
        {
            OnHandleBankGetRecordReq(msgId, packet);
            break;
        }
        default:
            break;
    }
    return 0;
}

int NFSnsJettonPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch(msgId)
    {
        case proto_ff::NF_CS_BANK_GET_DATA_REQ:
        {
            OnHandleGetBankDataReq(msgId, packet);
        }
    }

    return 0;
}

int NFSnsJettonPart::LoadFromDB(const proto_ff::tbFishSnsPlayerDetailData &data)
{
    m_bankJetton = data.bank_jetton();
    m_bankPassword = data.bank_password();
    for(int i = 0; i < (int)data.record().record_size(); i++)
    {
        if (m_recordList.full())
        {
            m_recordList.pop_front();
        }

        m_recordList.push_back();
        m_recordList.back().read_from_pbmsg(data.record().record(i));
    }
    return 0;
}

int NFSnsJettonPart::InitConfig(const proto_ff::tbFishSnsPlayerDetailData &data)
{
    m_bankJetton = 0;
    m_bankPassword = "888888";
    MarkDirty();
    return 0;
}

int NFSnsJettonPart::SaveDB(proto_ff::tbFishSnsPlayerDetailData &dbData)
{
    dbData.set_bank_jetton(m_bankJetton);
    dbData.set_bank_password(m_bankPassword.ToString());
    for(auto iter = m_recordList.begin(); iter != m_recordList.end(); iter++)
    {
        iter->write_to_pbmsg(*dbData.mutable_record()->add_record());
    }
    return 0;
}

int NFSnsJettonPart::OnHandleGetBankDataReq(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");

    proto_ff::Proto_LTSBankGetDataReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFPlayerOnline* pPlayerOnline = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerOnline(m_pMaster->GetPlayerId());
    CHECK_NULL(pPlayerOnline);

    proto_ff::Proto_SCBankGetDataRsp rspMsg;
    rspMsg.set_result(0);
    if (m_isCanUseBank == false)
    {
        if (xMsg.bank_password() != m_bankPassword.ToString())
        {
            rspMsg.set_result(proto_ff::ERR_CODE_BANK_PASSWORD_NOT_RIGHT);
            pPlayerOnline->SendMsgToClient(proto_ff::NF_SC_BANK_GET_DATA_RSP, rspMsg);
            return 0;
        }
    }

    m_isCanUseBank = true;
    rspMsg.set_jetton(xMsg.jetton());
    rspMsg.set_bank_jetton(m_bankJetton);
    pPlayerOnline->SendMsgToClient(proto_ff::NF_SC_BANK_GET_DATA_RSP, rspMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFSnsJettonPart::AddBankJettonService(proto_ff::Proto_LTS_PlayerAddBankJettonReq* pRequest, proto_ff::Proto_STL_PlayerAddBankJettonRsp* pResponse)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    CHECK_NULL(pRequest);
    CHECK_NULL(pResponse);

    m_bankJetton += pRequest->add_jetton();
    MarkDirty();

    pResponse->set_ret_code(0);
    pResponse->set_add_jetton(pRequest->add_jetton());
    pResponse->set_bank_jetton(m_bankJetton);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFSnsJettonPart::ReduceBankJettonService(proto_ff::Proto_LTS_PlayerReduceBankJettonReq* pRequest, proto_ff::Proto_STL_PlayerReduceBankJettonRsp* pResponse)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    CHECK_NULL(pRequest);
    CHECK_NULL(pResponse);

    uint32_t reduceJetton = 0;
    if (m_bankJetton > pRequest->reduce_jetton())
    {
        m_bankJetton -= pRequest->reduce_jetton();
        reduceJetton = pRequest->reduce_jetton();
    }
    else {
        reduceJetton = m_bankJetton;
        m_bankJetton = 0;
    }

    MarkDirty();

    pResponse->set_ret_code(0);
    pResponse->set_reduce_jetton(reduceJetton);
    pResponse->set_bank_jetton(m_bankJetton);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFSnsJettonPart::OnHandleBankSetPasswordReq(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");

    proto_ff::Proto_CSBankSetPasswordReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);
    NFPlayerOnline* pOnline = GetPlayerOnline();
    CHECK_NULL(pOnline);

    proto_ff::Proto_SCBankSetPasswordRsp rspMsg;
    rspMsg.set_result(0);
    if (m_bankPassword.ToString() == xMsg.old_password())
    {
        m_bankPassword = xMsg.new_password();
        MarkDirty();
    }
    else {
        rspMsg.set_result(proto_ff::ERR_CODE_BANK_PASSWORD_NOT_RIGHT);
    }

    pOnline->SendMsgToClient(proto_ff::NF_SC_BANK_SET_PASSWORD_RSP, rspMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFSnsJettonPart::OnHandleBankGiveBankJettonReq(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");

    proto_ff::Proto_CSBankGiveMoneyReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    NFPlayerOnline* pOnline = GetPlayerOnline();
    CHECK_NULL(pOnline);

    proto_ff::Proto_CSBankGiveMoneyRsp rspMsg;
    rspMsg.set_result(0);

    if (xMsg.give_user_id() == m_pMaster->GetPlayerId())
    {
        rspMsg.set_result(proto_ff::ERR_CODE_BANK_GIVE_MONEY_NOT_TO_MYSELF);
        pOnline->SendMsgToClient(proto_ff::NF_SC_BANK_GIVE_BANK_JETTON_RSP, rspMsg);
        return 0;
    }

    if (m_bankJetton < xMsg.give_jetton())
    {
        rspMsg.set_result(proto_ff::ERR_CODE_USER_MONEY_TOO_MUCH);
        pOnline->SendMsgToClient(proto_ff::NF_SC_BANK_GIVE_BANK_JETTON_RSP, rspMsg);
        return 0;
    }

    uint64_t playerId = m_pMaster->GetPlayerId();
    auto otherData = NFCacheMgr::Instance(m_pObjPluginManager)->QueryPlayerByRpc(playerId, xMsg.give_user_id());
    NFPlayerSimple* pOtherSimple = otherData.first;
    NFPlayerDetail* pOtherDetail = otherData.second;
    pOnline = GetPlayerOnline(); //需要重新获取，可能被释放了
    CHECK_NULL(pOnline);
    NFPlayerSimple* pSimple = GetPlayerSimple();
    CHECK_NULL(pSimple);
    if (pOtherDetail == NULL || pOtherSimple == NULL)
    {
        rspMsg.set_result(proto_ff::ERR_CODE_PLAYER_NOT_EXIST);
        pOnline->SendMsgToClient(proto_ff::NF_SC_BANK_GIVE_BANK_JETTON_RSP, rspMsg);
        return 0;
    }

    NFSnsJettonPart* pOtherPart = pOtherDetail->GetPart<NFSnsJettonPart>(SNS_JETTON_PART);
    if (pOtherPart == NULL)
    {
        rspMsg.set_result(proto_ff::ERR_CODE_PLAYER_NOT_EXIST);
        pOnline->SendMsgToClient(proto_ff::NF_SC_BANK_GIVE_BANK_JETTON_RSP, rspMsg);
        return 0;
    }

    if (m_bankJetton < xMsg.give_jetton())
    {
        rspMsg.set_result(proto_ff::ERR_CODE_USER_MONEY_TOO_MUCH);
        pOnline->SendMsgToClient(proto_ff::NF_SC_BANK_GIVE_BANK_JETTON_RSP, rspMsg);
        return 0;
    }

    m_bankJetton -= xMsg.give_jetton();
    MarkDirty();

    pOtherPart->m_bankJetton += xMsg.give_jetton();
    pOtherPart->MarkDirty();

    rspMsg.set_bank_jetton(m_bankJetton);
    pOnline->SendMsgToClient(proto_ff::NF_SC_BANK_GIVE_BANK_JETTON_RSP, rspMsg);

    if (m_recordList.full())
    {
        m_recordList.pop_front();
    }

    proto_ff_s::tbGiveBankJetton_s record;
    record.id = FindModule<NFIKernelModule>()->Get64UUID();
    record.user_id = m_pMaster->GetPlayerId();
    record.user_name = pSimple->GetBaseData().nickname;
    record.give_user_id = xMsg.give_user_id();
    record.give_user_name = pOtherSimple->GetBaseData().nickname;
    record.give_jetton = xMsg.give_jetton();
    record.create_time = NFTime::Now().UnixSec();

    m_recordList.push_back(record);
    MarkDirty();

    if (pOtherPart->m_recordList.full())
    {
        pOtherPart->m_recordList.pop_front();
    }

    pOtherPart->m_recordList.push_back(record);
    pOtherPart->MarkDirty();

    NFPlayerOnline* pOtherOnline = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerOnline(xMsg.give_user_id());
    if (pOtherOnline)
    {
        proto_ff::Proto_SCBankGiveJettonAutoPushRsp notify;
        record.write_to_pbmsg(*notify.mutable_record());
        notify.set_bank_jetton(pOtherPart->m_bankJetton);
        pOtherOnline->SendMsgToClient(proto_ff::NF_SC_BANK_GIVE_BANK_JETTON_AUTO_PUSH_RSP, notify);
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFSnsJettonPart::OnHandleBankGetRecordReq(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");

    proto_ff::Proto_CSBankGetRecordReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);
    NFPlayerOnline* pOnline = GetPlayerOnline();
    CHECK_NULL(pOnline);

    proto_ff::Proto_SCBankGetRecordRsp rspMsg;
    rspMsg.set_result(0);

    uint32_t count = 1;
    for(auto iter = m_recordList.begin(); iter != m_recordList.end(); iter++)
    {
        if (count >= xMsg.begin() && count <= xMsg.end())
        {
            iter->write_to_pbmsg(*rspMsg.add_record());
        }
        count++;
    }
    pOnline->SendMsgToClient(proto_ff::NF_SC_BANK_GET_RECORD_RSP, rspMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}
