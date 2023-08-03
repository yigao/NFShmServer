// -------------------------------------------------------------------------
//    @FileName         :    NFJettonPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFJettonPart
//
// -------------------------------------------------------------------------

#include "NFJettonPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "AllProtocol.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "Player/NFPlayer.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFJettonPart, EOT_NFJettonPart_ID, NFPart)

NFJettonPart::NFJettonPart()
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

NFJettonPart::~NFJettonPart()
{
}

int NFJettonPart::CreateInit()
{
    m_jetton = 0;
    return 0;
}

int NFJettonPart::ResumeInit()
{
    return 0;
}

int NFJettonPart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::tbFishPlayerData &dbData, bool bCreatePlayer)
{
    return NFPart::Init(pMaster, partType, dbData, bCreatePlayer);
}

int NFJettonPart::UnInit()
{
    return NFPart::UnInit();
}

int NFJettonPart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::NF_CS_BANK_GET_DATA_REQ);
    RegisterClientMessage(proto_ff::NF_CS_BANK_SAVE_MONEY_REQ, true);
    RegisterClientMessage(proto_ff::NF_CS_BANK_GET_MONEY_REQ, true);
    AddRpcService<proto_ff::NF_GTL_COIN_QUERY_BALANCE_RPC>(this, &NFJettonPart::OnHandleCoinQueryBalanceRpc);
    return 0;
}

int NFJettonPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch(msgId)
    {
        case proto_ff::NF_CS_BANK_GET_DATA_REQ:
        {
            OnHandleGetBankDataReq(msgId, packet);
            break;
        }
        case proto_ff::NF_CS_BANK_SAVE_MONEY_REQ:
        {
            OnHandleBankSaveMoneyReq(msgId, packet);
            break;
        }
        case proto_ff::NF_CS_BANK_GET_MONEY_REQ:
        {
            OnHandleBankGetMoneyReq(msgId, packet);
            break;
        }
    }
    return 0;
}

int NFJettonPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

int NFJettonPart::LoadFromDB(const proto_ff::tbFishPlayerData &data)
{
    m_jetton = data.jetton();
    return 0;
}

int NFJettonPart::InitConfig(const proto_ff::tbFishPlayerData &data)
{
    m_jetton = 1000000;
    MarkDirty();
    return 0;
}

int NFJettonPart::SaveDB(proto_ff::tbFishPlayerData &dbData)
{
    dbData.set_jetton(m_jetton);
    return 0;
}

int NFJettonPart::OnHandleGetBankDataReq(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

    proto_ff::Proto_CSBankGetDataReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    proto_ff::Proto_LTSBankGetDataReq rspMsg;
    rspMsg.set_jetton(m_jetton);
    rspMsg.set_bank_password(xMsg.bank_password());

    m_pMaster->SendMsgToSnsServer(msgId, rspMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFJettonPart::OnHandleBankSaveMoneyReq(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

    proto_ff::Proto_CSBankSaveMoneyReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    proto_ff::Proto_SCBankSaveMoneyRsp rspMsg;
    rspMsg.set_result(0);
    if (xMsg.save_jetton() > m_jetton)
    {
        rspMsg.set_result(proto_ff::ERR_CODE_USER_MONEY_NOT_ENOUGH);
        m_pMaster->SendMsgToClient(proto_ff::NF_SC_BANK_SAVE_MONEY_RSP, rspMsg);
        return 0;
    }

    proto_ff::Proto_LTS_PlayerAddBankJettonReq reqRpc;
    reqRpc.set_add_jetton(xMsg.save_jetton());
    proto_ff::Proto_STL_PlayerAddBankJettonRsp rspRpc;
    int iRet = GetRpcService<proto_ff::NF_LTS_PLAYER_ADD_BANK_JETTON_RPC>(NF_ST_SNS_SERVER, 0, reqRpc, rspRpc);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetPlayerId(), "GetRpcService<proto_ff::NF_LTS_PLAYER_ADD_BANK_JETTON_RPC> Failed, iRet:{}", GetErrorStr(iRet));
        rspMsg.set_result(iRet);
        m_pMaster->SendMsgToClient(proto_ff::NF_SC_BANK_SAVE_MONEY_RSP, rspMsg);
        return 0;
    }

    if (rspRpc.ret_code() != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetPlayerId(), "GetRpcService<proto_ff::NF_LTS_PLAYER_ADD_BANK_JETTON_RPC> Failed, rspRpc.ret_code():{}", GetErrorStr(rspRpc.ret_code()));
        rspMsg.set_result(rspRpc.ret_code());
        m_pMaster->SendMsgToClient(proto_ff::NF_SC_BANK_SAVE_MONEY_RSP, rspMsg);
        return 0;
    }

    if (rspRpc.add_jetton() > m_jetton)
    {
        proto_ff::Proto_LTS_PlayerReduceBankJettonReq reduceReqRpc;
        reduceReqRpc.set_reduce_jetton(rspRpc.add_jetton());
        proto_ff::Proto_STL_PlayerReduceBankJettonRsp reduceRspRpc;
        iRet = GetRpcService<proto_ff::NF_LTS_PLAYER_REDUCE_BANK_JETTON_RPC>(NF_ST_SNS_SERVER, 0, reduceReqRpc, reduceRspRpc);
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetPlayerId(), "rspRpc.add_jetton() > m_jetton GetRpcService<proto_ff::NF_LTS_PLAYER_REDUCE_BANK_JETTON_RPC> Failed, iRet:{}", GetErrorStr(iRet));
            rspMsg.set_result(iRet);
            m_pMaster->SendMsgToClient(proto_ff::NF_SC_BANK_SAVE_MONEY_RSP, rspMsg);
            return 0;
        }

        if (reduceRspRpc.ret_code() != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetPlayerId(), "rspRpc.add_jetton() > m_jetton GetRpcService<proto_ff::NF_LTS_PLAYER_REDUCE_BANK_JETTON_RPC> Failed, rspRpc.ret_code():{}", GetErrorStr(rspRpc.ret_code()));
            rspMsg.set_result(reduceRspRpc.ret_code());
            m_pMaster->SendMsgToClient(proto_ff::NF_SC_BANK_SAVE_MONEY_RSP, rspMsg);
            return 0;
        }

        rspMsg.set_result(proto_ff::ERR_CODE_USER_MONEY_NOT_ENOUGH);
        m_pMaster->SendMsgToClient(proto_ff::NF_SC_BANK_SAVE_MONEY_RSP, rspMsg);
        return 0;
    }

    m_jetton -= xMsg.save_jetton();
    MarkDirty();

    rspMsg.set_jetton(m_jetton);
    rspMsg.set_bank_jetton(rspRpc.bank_jetton());

    m_pMaster->SendMsgToClient(proto_ff::NF_SC_BANK_SAVE_MONEY_RSP, rspMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFJettonPart::OnHandleBankGetMoneyReq(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

    proto_ff::Proto_CSBankGetMoneyReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    proto_ff::Proto_SCBankGetMoneyRsp rspMsg;
    rspMsg.set_result(0);

    proto_ff::Proto_LTS_PlayerReduceBankJettonReq reduceReqRpc;
    reduceReqRpc.set_reduce_jetton(xMsg.get_jetton());
    proto_ff::Proto_STL_PlayerReduceBankJettonRsp reduceRspRpc;
    int iRet = GetRpcService<proto_ff::NF_LTS_PLAYER_REDUCE_BANK_JETTON_RPC>(NF_ST_SNS_SERVER, 0, reduceReqRpc, reduceRspRpc);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetPlayerId(), "GetRpcService<proto_ff::NF_LTS_PLAYER_REDUCE_BANK_JETTON_RPC> Failed, iRet:{}", GetErrorStr(iRet));
        rspMsg.set_result(iRet);
        m_pMaster->SendMsgToClient(proto_ff::NF_SC_BANK_GET_MONEY_RSP, rspMsg);
        return 0;
    }

    if (reduceRspRpc.ret_code() != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetPlayerId(), "GetRpcService<proto_ff::NF_LTS_PLAYER_REDUCE_BANK_JETTON_RPC> Failed, rspRpc.ret_code():{}", GetErrorStr(reduceRspRpc.ret_code()));
        rspMsg.set_result(reduceRspRpc.ret_code());
        m_pMaster->SendMsgToClient(proto_ff::NF_SC_BANK_GET_MONEY_RSP, rspMsg);
        return 0;
    }

    m_jetton += reduceRspRpc.reduce_jetton();
    MarkDirty();

    rspMsg.set_jetton(m_jetton);
    rspMsg.set_bank_jetton(reduceRspRpc.bank_jetton());

    m_pMaster->SendMsgToClient(proto_ff::NF_SC_BANK_GET_MONEY_RSP, rspMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFJettonPart::OnHandleCoinQueryBalanceRpc(proto_ff::Proto_QueryCoinBalanceReq& request, proto_ff::Proto_QueryCoinBalanceRsp& respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    respone.set_result(0);
    respone.mutable_player_detail()->set_player_id(m_pMaster->GetPlayerId());
    respone.mutable_player_detail()->set_cur_money(m_jetton);
    respone.mutable_player_detail()->set_nick_name(m_pMaster->GetNickName());
    respone.mutable_player_detail()->set_face(m_pMaster->GetFaceId());
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}


