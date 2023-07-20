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
    RegisterServerMessage(proto_ff::NF_CS_BANK_GET_DATA_REQ);
    AddRpcService<proto_ff::NF_LTS_PLAYER_ADD_BANK_JETTON_RPC>(this, &NFSnsJettonPart::AddBankJettonService);
    AddRpcService<proto_ff::NF_LTS_PLAYER_REDUCE_BANK_JETTON_RPC>(this, &NFSnsJettonPart::ReduceBankJettonService);
    return 0;
}

int NFSnsJettonPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFSnsPart::OnHandleClientMessage(msgId, packet);
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

int NFSnsJettonPart::OnHandleRpcMessage(uint32_t msgId, google::protobuf::Message* pRequest, google::protobuf::Message* pRespone)
{
    switch(msgId)
    {
        case proto_ff::NF_LTS_PLAYER_ADD_BANK_JETTON_RPC:
        {
            return AddBankJettonService(dynamic_cast<proto_ff::Proto_LTS_PlayerAddBankJettonReq*>(pRequest), dynamic_cast<proto_ff::Proto_STL_PlayerAddBankJettonRsp*>(pRespone));
        }
        default:
            break;
    }

    return proto_ff::ERR_CODE_RPC_MSG_FUNCTION_UNEXISTED;
}

int NFSnsJettonPart::LoadFromDB(const proto_ff::tbFishSnsPlayerDetailData &data)
{
    m_bankJetton = data.bank_jetton();
    m_bankPassword = data.bank_password();
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

