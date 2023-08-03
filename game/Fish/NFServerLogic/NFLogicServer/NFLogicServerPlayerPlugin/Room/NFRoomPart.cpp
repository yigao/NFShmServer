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

int NFRoomPart::GetDeskListReq(proto_ff::DeskListReq& request, proto_ff::DeskListRsp& respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");

    NFJettonPart* pJettonPart = m_pMaster->GetPart<NFJettonPart>(PART_JETTON);
    CHECK_NULL(pJettonPart);

    auto pRoomCfg = GameRoomDescEx::Instance(m_pObjPluginManager)->GetDesc(request.game_id(), request.room_id());
    CHECK_NULL(pRoomCfg);

    if (pRoomCfg->m_is_exp_scene <= 0)
    {
        if (pJettonPart->GetJetton() < (uint64_t)pRoomCfg->m_enter_min || pJettonPart->GetJetton() > (uint64_t)pRoomCfg->m_enter_max)
        {
            if (pJettonPart->GetJetton() < (uint64_t)pRoomCfg->m_enter_min)
            {
                respone.set_result(proto_ff::ERR_CODE_USER_MONEY_NOT_ENOUGH);
            }
            else {
                respone.set_result(proto_ff::ERR_CODE_USER_MONEY_TOO_MUCH);
            }
            return 0;
        }
    }


    request.set_cur_money(pJettonPart->GetJetton());
    int iRet = GetRpcService<proto_ff::NF_CS_MSG_DeskListReq>(NF_ST_GAME_SERVER, request.game_bus_id(), request, respone);
    if (iRet != 0)
    {
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    if (respone.result() != 0)
    {
        return 0;
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}
