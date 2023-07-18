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
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
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

int NFSnsJettonPart::LoadFromDB(const proto_ff::tbFishSnsPlayerDetailData &data)
{
    m_bankJetton = data.bank_jetton();
    m_bankPassword = data.bank_password();
    return 0;
}

int NFSnsJettonPart::InitConfig(const proto_ff::tbFishSnsPlayerDetailData &data)
{
    m_bankJetton = 0;
    m_bankPassword = "8888";
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
    rspMsg.set_jetton(xMsg.jetton());
    rspMsg.set_bank_jetton(m_bankJetton);
    pPlayerOnline->SendMsgToClient(proto_ff::NF_SC_BANK_GET_DATA_RSP, rspMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}


