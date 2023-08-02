// -------------------------------------------------------------------------
//    @FileName         :    NFRoomPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoomPart
//
// -------------------------------------------------------------------------

#include "NFRoomPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Jetton/NFJettonPart.h"
#include "DescStoreEx/GameRoomDescEx.h"
#include "NFLogicCommon/NFLogicBindRpcService.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFRoomPart, EOT_NFRoomPart_ID, NFShmObj
)

NFRoomPart::NFRoomPart()
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

NFRoomPart::~NFRoomPart()
{
}

int NFRoomPart::CreateInit()
{
    m_gameId = 0;
    m_roomId = 0;
    return 0;
}

int NFRoomPart::ResumeInit()
{
    return 0;
}

int NFRoomPart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::tbFishPlayerData &dbData, bool bCreatePlayer)
{
    return NFPart::Init(pMaster, partType, dbData, bCreatePlayer);
}

int NFRoomPart::UnInit()
{
    return NFPart::UnInit();
}

int NFRoomPart::LoadFromDB(const proto_ff::tbFishPlayerData &data)
{
    return NFPart::LoadFromDB(data);
}

int NFRoomPart::InitConfig(const proto_ff::tbFishPlayerData &data)
{
    return NFPart::InitConfig(data);
}

int NFRoomPart::SaveDB(proto_ff::tbFishPlayerData &dbData)
{
    return NFPart::SaveDB(dbData);
}

int NFRoomPart::RegisterMessage()
{
    AddRpcService<proto_ff::NF_CS_MSG_DeskListReq>(this, &NFRoomPart::GetDeskListReq, true);
    return 0;
}

int NFRoomPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleClientMessage(msgId, packet);
}

int NFRoomPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

int NFRoomPart::GetDeskListReq(proto_ff::DeskListReq *pRequest, proto_ff::DeskListRsp *pResponse)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    CHECK_NULL(pRequest);
    CHECK_NULL(pResponse);

    NFJettonPart* pJettonPart = m_pMaster->GetPart<NFJettonPart>(PART_JETTON);
    CHECK_NULL(pJettonPart);

    auto pRoomCfg = GameRoomDescEx::Instance(m_pObjPluginManager)->GetDesc(pRequest->game_id(), pRequest->room_id());
    CHECK_NULL(pRoomCfg);

    if (pJettonPart->GetJetton() < (uint64_t)pRoomCfg->m_enter_min || pJettonPart->GetJetton() > (uint64_t)pRoomCfg->m_enter_max)
    {
        if (pJettonPart->GetJetton() < (uint64_t)pRoomCfg->m_enter_min)
        {
            pResponse->set_result(proto_ff::ERR_CODE_USER_MONEY_NOT_ENOUGH);
        }
        else {
            pResponse->set_result(proto_ff::ERR_CODE_USER_MONEY_TOO_MUCH);
        }
        return 0;
    }

    pRequest->set_cur_money(pJettonPart->GetJetton());
    int iRet = GetRpcService<proto_ff::NF_CS_MSG_DeskListReq>(NF_ST_GAME_SERVER, pRequest->game_bus_id(), *pRequest, *pResponse);
    if (iRet != 0)
    {
        pResponse->set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    if (pResponse->result() != 0)
    {
        return 0;
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}
