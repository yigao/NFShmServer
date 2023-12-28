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
#include "NFLogicCommon/NFLogicBindRpcService.h"
#include "DescStore/FishRoomDesc.h"

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
    m_gameBusId = 0;
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

int NFRoomPart::OnLogin(const proto_ff::Proto_WorldToLogicLoginReq& data, proto_ff::Proto_UserDetailCommonData& detailData, bool isCreatePlayer)
{
    if (isCreatePlayer)
    {
        m_gameId = data.game_id();
        m_roomId = data.room_id();
        m_gameBusId = data.game_bus_id();
    }

    return 0;
}

int NFRoomPart::RegisterMessage()
{
    AddRpcService<proto_ff::NF_CS_MSG_DeskListReq>(this, &NFRoomPart::GetDeskListReq, true);
    AddRpcService<proto_ff::NF_CS_MSG_EnterGameReq>(this, &NFRoomPart::EnterGameReq, true);
    AddRpcService<proto_ff::NF_CS_MSG_ExitGameReq>(this, &NFRoomPart::ExitGameReq, true);
    AddRpcService<proto_ff::NF_CS_MSG_ExitRoomReq>(this, &NFRoomPart::ExitRoomReq, true);
    AddRpcService<proto_ff::NF_STS_PLAYER_CHANGE_GAME_SERVER>(this, &NFRoomPart::ChangeGameReq, true);

    RegisterServerMessage(proto_ff::NF_STS_GAME_PLAYER_LEAVE_GAME);

    return 0;
}

int NFRoomPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

int NFRoomPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch (msgId)
    {
        case proto_ff::NF_STS_GAME_PLAYER_LEAVE_GAME:
        {
            OnHandleNotifyPlayerLeaveGame(msgId, packet);
            break;
        }
        default:
            break;
    }
    return 0;
}

int NFRoomPart::GetDeskListReq(proto_ff::DeskListReq& request, proto_ff::DeskListRsp& respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

    NFJettonPart* pJettonPart = m_pMaster->GetPart<NFJettonPart>(PART_JETTON);
    CHECK_NULL(pJettonPart);

    auto pRoomCfg = FishRoomDesc::Instance()->GetDescByGameidRoomid(request.game_id(), request.room_id());
    CHECK_NULL(pRoomCfg);

    if (pRoomCfg->m_isExpScene <= 0)
    {
        if (pJettonPart->GetJetton() < (uint64_t)pRoomCfg->m_enterMin || (pRoomCfg->m_enterMax > 0 && pJettonPart->GetJetton() > (uint64_t)pRoomCfg->m_enterMax))
        {
            if (pJettonPart->GetJetton() < (uint64_t)pRoomCfg->m_enterMin)
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

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFRoomPart::EnterGameReq(proto_ff::EnterGameReq& request, proto_ff::EnterGameRsp& respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

    auto pRoomCfg = FishRoomDesc::Instance()->GetDescByGameidRoomid(request.game_id(), request.room_id());
    CHECK_NULL(pRoomCfg);

    if (m_gameId > 0 && m_gameId != request.game_id())
    {
        //force exit game
    }

    int iRet = GetRpcService<proto_ff::NF_CS_MSG_EnterGameReq>(NF_ST_GAME_SERVER, request.game_bus_id(), request, respone);
    if (iRet != 0)
    {
        respone.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    if (respone.result() != 0)
    {
        m_gameId = 0;
        m_roomId = 0;
        m_gameBusId = 0;
    }
    else {
        m_gameId = request.game_id();
        m_roomId = request.room_id();
        m_gameBusId = request.game_bus_id();
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFRoomPart::ExitRoomReq(proto_ff::ExitRoomReq& request, proto_ff::ExitRoomRsp& respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

    if (m_gameId == 0 && m_roomId == 0 && m_gameBusId == 0)
    {
        respone.set_result(0);
        return 0;
    }

    int iRet = GetRpcService<proto_ff::NF_CS_MSG_ExitRoomReq>(NF_ST_GAME_SERVER, m_gameBusId, request, respone);
    if (iRet != 0)
    {
        return iRet;
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFRoomPart::ExitGameReq(proto_ff::ExitGameReq& request, proto_ff::ExitGameRsp& respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

    if (m_gameId == 0 && m_roomId == 0 && m_gameBusId == 0)
    {
        respone.set_exit_type(0);
        return 0;
    }

    int iRet = GetRpcService<proto_ff::NF_CS_MSG_ExitGameReq>(NF_ST_GAME_SERVER, m_gameBusId, request, respone);
    if (iRet != 0)
    {
        return iRet;
    }

    if (respone.exit_type() == 0)
    {
        m_gameId = 0;
        m_roomId = 0;
        m_gameBusId = 0;
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFRoomPart::ChangeGameReq(proto_ff::Proto_STS_PlayerChangeGameServerReq& request, proto_ff::Proto_STS_PlayerChangeGameServerRsp& respone)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

    m_gameId = request.game_id();
    m_roomId = request.room_id();
    m_gameBusId = request.game_bus_id();

    respone.set_ret_code(0);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFRoomPart::OnHandleNotifyPlayerLeaveGame(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");

    proto_ff::Proto_NotifyServerPlayerExitGame xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xMsg);

    if (m_gameId == 0 && m_roomId == 0 && m_gameBusId == 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, m_pMaster->GetPlayerId(), "world server notify logic player, player:{} leave game:{} room:{} success", m_pMaster->GetPlayerId(), xMsg.game_id(),
                  xMsg.room_id());
       return 0;
    }

    if (m_gameId == xMsg.game_id() && m_roomId == xMsg.room_id())
    {
        m_gameId = 0;
        m_roomId = 0;
        m_gameBusId = 0;
        NFLogInfo(NF_LOG_SYSTEMLOG, m_pMaster->GetPlayerId(), "world server notify logic player, player:{} leave game:{} room:{} success", m_pMaster->GetPlayerId(), xMsg.game_id(),
                  xMsg.room_id());
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetPlayerId(), "world server notify logic player, but player:{} game:{} room:{} not equal to the game:{} room:{}",
                   m_pMaster->GetPlayerId(), m_gameId, m_roomId, xMsg.game_id(),
                   xMsg.room_id());
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}
