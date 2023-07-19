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
    RegisterClientMessage(proto_ff::NF_CS_BANK_SET_PASSWORD_REQ, true);
    RegisterClientMessage(proto_ff::NF_CS_BANK_GIVE_BANK_JETTON_REQ, true);
    RegisterClientMessage(proto_ff::NF_CS_BANK_GET_RECORD_REQ, true);
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
    return NFPart::InitConfig(data);
}

int NFJettonPart::SaveDB(proto_ff::tbFishPlayerData &dbData)
{
    dbData.set_jetton(m_jetton);
    return 0;
}

int NFJettonPart::OnHandleGetBankDataReq(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");

    proto_ff::Proto_CSBankGetDataReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    proto_ff::Proto_LTSBankGetDataReq rspMsg;
    rspMsg.set_jetton(m_jetton);
    rspMsg.set_bank_password(xMsg.bank_password());

    m_pMaster->SendMsgToSnsServer(msgId, xMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFJettonPart::OnHandleBankSaveMoneyReq(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");

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
    int iRet = FindModule<NFIMessageModule>()->GetRpcService<proto_ff::NF_LTS_PLAYER_ADD_BANK_JETTON_RPC>(NF_ST_LOGIC_SERVER, NF_ST_SNS_SERVER, 0, reqRpc, rspRpc);
    if (iRet != 0)
    {
        rspMsg.set_result(iRet);
        m_pMaster->SendMsgToClient(proto_ff::NF_SC_BANK_SAVE_MONEY_RSP, rspMsg);
        return 0;
    }

    if (rspRpc.ret_code() != 0)
    {
        rspMsg.set_result(rspRpc.ret_code());
        m_pMaster->SendMsgToClient(proto_ff::NF_SC_BANK_SAVE_MONEY_RSP, rspMsg);
        return 0;
    }

    m_pMaster->SendMsgToClient(proto_ff::NF_SC_BANK_SAVE_MONEY_RSP, rspMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

