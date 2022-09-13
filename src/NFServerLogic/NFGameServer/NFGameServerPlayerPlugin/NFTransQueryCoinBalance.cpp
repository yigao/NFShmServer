// -------------------------------------------------------------------------
//    @FileName         :    NFTransQueryCoinBalance.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransQueryCoinBalance.cpp
//
// -------------------------------------------------------------------------

#include "NFTransQueryCoinBalance.h"

#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_game.pb.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"

#include "NFGameSession.h"
#include "NFGameSessionMgr.h"
#include "NFGameRoom.h"
#include "NFGameRoomMgr.h"
#include "NFGameDesk.h"
#include "NFGameRobotMgr.h"
#include "NFGameRobot.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransQueryCoinBalance, EOT_TRANS_QUERY_COIN_BALANCE_BASE, NFTransGamePlayerBase)

NFTransQueryCoinBalance::NFTransQueryCoinBalance() {
	if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

NFTransQueryCoinBalance::~NFTransQueryCoinBalance() {

}

int NFTransQueryCoinBalance::CreateInit() {
	m_gameId = 0;
	m_roomId = 0;
	m_deskId = INVALID_ID;
	m_stationId = INVALID_ID;
	return 0;
}

int NFTransQueryCoinBalance::ResumeInit() {
	return 0;
}

int NFTransQueryCoinBalance::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFTransQueryCoinBalance::HandleDispSvrRes(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
	switch (nMsgId)
	{
	case proto_ff::E_GTL_COIN_QUERY_BALANCE_RPS:
	{
		proto_ff::Proto_QueryCoinBalanceRsp xMsg;
		CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, destLinkId, msg, nLen, xMsg);
		CHECK_EXPR(xMsg.player_detail().player_id() == m_playerId, - 1, "Proto_QueryCoinBalanceRsp Failed!");

		return HandleQueryCoinBalanceRsp(xMsg);
	}
	break;
	default:
		break;
	}
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFTransQueryCoinBalance::HandleQueryCoinBalanceRsp(const proto_ff::Proto_QueryCoinBalanceRsp& xMsg)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
	CHECK_EXPR(xMsg.player_detail().player_id() == m_playerId, -1, "xMsg Error:{}", xMsg.DebugString());

	NFGameSession* pPlayer = GamePlayer();
	CHECK_EXPR(pPlayer, -1, "Can't find player:{}", m_playerId);

	NFGameRoom *pRoom = NFGameRoomMgr::GetInstance()->GetGameRoom(m_gameId, m_roomId);
	CHECK_EXPR(pRoom, -1, "can't find gameroom, gameId:{}, roomId:{} playerId:{}", m_gameId, m_roomId, m_playerId);

	NFGameDesk *pDesk = pRoom->GetGameDesk(m_deskId);
	CHECK_EXPR(pDesk, -1, "pDesk == null, gameId:{} roomId:{} deskId:{} playerId:{}", m_gameId, m_roomId, m_deskId, m_playerId);

	proto_ff_s::GamePlayerDetailData_s playerDetail;
	proto_ff_s::GamePlayerDetailData_s::read_from_pbmsg(xMsg.player_detail(), playerDetail);

    const proto_ff_s::GameRoomDesc_s* roomConfig = NFIPluginManager::Instance()->FindModule<NFIGameRoomModule>()->GetRoomConfig(m_gameId, m_roomId);
    if (!roomConfig)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFGameRoomDesc: find room failed! mGameId = {} , mRoomId = {}", m_gameId, m_roomId);
        NFGameRoomMgr::GetInstance()->ClearDirtyData(pPlayer->m_playerId);
        SetFinished(proto_ff::ERR_CODE_SYSTEM_ERROR);
        return 0;
    }

    if (roomConfig->enter_min > 0)
    {
        if (playerDetail.cur_money < roomConfig->enter_min)
        {
            NFGameRoomMgr::GetInstance()->ClearDirtyData(pPlayer->m_playerId);
            SetFinished(proto_ff::ERR_CODE_USER_MONEY_NOT_ENOUGH);
            return 0;
        }
    }

    if (roomConfig->enter_max > 0)
    {
        if (playerDetail.cur_money > roomConfig->enter_max)
        {
            NFGameRoomMgr::GetInstance()->ClearDirtyData(pPlayer->m_playerId);
            SetFinished(proto_ff::ERR_CODE_USER_MONEY_TOO_MUCH);
            return 0;
        }
    }

    if (roomConfig->is_exp_scene > 0)
    {
        playerDetail.cur_money = roomConfig->exp_scene_gold;
    }

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "m_stationId = {} , m_playerId = {}", m_stationId, pPlayer->m_playerId);

	int iRet = pDesk->LoginDesk(pPlayer, m_stationId, playerDetail);
	if (iRet != 0)
    {
        NFGameRoomMgr::GetInstance()->ClearDirtyData(pPlayer->m_playerId);
        SetFinished(iRet);
        return 0;
    }
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");

	SetFinished(0);
	return 0;
}

int NFTransQueryCoinBalance::ProQueryCoinBalanceReq(uint32_t gameId, uint32_t roomId, int32_t deskId, int32_t stationId)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
	m_gameId = gameId;
	m_roomId = roomId;
	m_deskId = deskId;
	m_stationId = stationId;
	ProQueryCoinBalanceReq();
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFTransQueryCoinBalance::ProQueryCoinBalanceReq()
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
	NFGameSession* pPlayer = GamePlayer();
	CHECK_NULL(pPlayer);

	proto_ff::Proto_QueryCoinBalanceReq xMsg;
	xMsg.set_player_id(pPlayer->GetPlayerId());

	pPlayer->SendTransToLogic(proto_ff::E_GTL_COIN_QUERY_BALANCE_REQ, xMsg, GetGlobalID());

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFTransQueryCoinBalance::HandleTransFinished(int iRunLogicRetCode)
{
    if (iRunLogicRetCode != 0)
    {
        NFGameRoomMgr::GetInstance()->ClearDirtyData(m_playerId);
        proto_game::EnterGameRsp rspMsg;
        rspMsg.set_result(iRunLogicRetCode);
        rspMsg.set_player_id(m_playerId);
        NFGameRobot* pRobot = NFGameRobotMgr::Instance()->GetRobot(m_playerId);
        if (!pRobot)
        {
            return NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER,
                                                                  proto_game::NF_SC_MSG_EnterGameRsp, rspMsg, m_playerId);
        }
    }
	return 0;
}