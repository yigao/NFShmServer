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

IMPLEMENT_IDCREATE_WITHTYPE(NFJettonPart, EOT_NFJettonPart_ID, NFShmObj)

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
    RegisterClientMessage(proto_ff::NF_CS_BANK_GET_DATA_REQ, true);
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


