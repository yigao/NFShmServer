// -------------------------------------------------------------------------
//    @FileName         :    NFGameRoom.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameRoom.cpp
//
// -------------------------------------------------------------------------

#include <NFServer/NFCommHead/NFCommLogicHead.h>
#include "NFGameRoom.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFGameDesk.h"
#include "NFServer/NFCommHead/NFIGameRoomModule.h"
#include "NFComm/NFMessageDefine/proto_cs.pb.h"
#include "NFComm/NFMessageDefine/proto_cs_game.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_game.pb.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFGameSession.h"
#include "NFGameSessionMgr.h"
#include "NFGameRobot.h"
#include "NFGameRobotMgr.h"
#include "NFGameRoomMgr.h"
#include "NFPaoMaDengMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGameRoom, EOT_GAME_ROOM_ID, NFShmObj)

NFGameRoom::NFGameRoom() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFGameRoom::~NFGameRoom()
{
    if (m_statTimer != INVALID_ID)
    {
        DeleteTimer(m_statTimer);
        m_statTimer = INVALID_ID;
    }
}

int NFGameRoom::CreateInit() 
{
    m_gameId = 0;
    m_roomId = 0;
    m_statTimer = INVALID_ID;
    m_lastSendTime = 0;

    memset(&m_roomStatInfo, 0, sizeof(m_roomStatInfo));
    return 0;
}

int NFGameRoom::ResumeInit() 
{
    return 0;
}

int NFGameRoom::Init(uint32_t gameId, const std::string& gameName, uint32_t roomId, const std::string& roomName, uint32_t deskCount, uint32_t sitNum, uint32_t maxUserNum)
{
    m_gameId = gameId;
    m_roomId = roomId;
    m_gameName = gameName;
    m_roomName = roomName;

    m_statTimer = SetTimer(1000, 0, 0, 0, 10, 0);
    int iRet = InitGameDesks(deskCount, sitNum, maxUserNum);
    CHECK_EXPR(iRet == 0, -1, "InitGameDesk failed, gameId:{}, roomId:{} deskCount:{}", gameId, roomId, deskCount);
    return 0;
}

int NFGameRoom::InitGameDesks(uint32_t deskCount, uint32_t sitNum, uint32_t maxUserNum) 
{
    CHECK_EXPR(deskCount > 0 && sitNum > 0 && maxUserNum >= sitNum, -1, "param error, deskCount:{} sitNum:{} maxUserNum:{}",
               deskCount, sitNum, maxUserNum);

    m_AryDesks.SetSize(deskCount);

    for (uint32_t iDeskIndex = 0; iDeskIndex < (uint32_t)m_AryDesks.GetSize(); iDeskIndex++) 
	{
        NFGameDesk *pDesk = dynamic_cast<NFGameDesk *>(NFShmMgr::Instance()->CreateObj(EOT_GAME_DESK_ID));
        CHECK_EXPR_CONTINUE(pDesk, "Create Desk Obj Failed!!!!!");

        NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "InitGameDesk() deskId = {}", iDeskIndex);

        int retCode = pDesk->Init(m_gameId, m_roomId, iDeskIndex, sitNum, maxUserNum, this);
        CHECK_EXPR_CONTINUE(retCode == 0, "Desk Init Failed!");

        m_AryDesks[iDeskIndex] = pDesk->GetGlobalID();
    }
    return 0;
}

NFGameDesk* NFGameRoom::GetGameDesk(int32_t iDeskId)
{
    CHECK_EXPR(iDeskId >= 0 && (int)iDeskId < m_AryDesks.GetSize(), NULL, "iDeskId error, iDeskId:{} , iDeskId:{}, GetDeskCount() = {}", iDeskId, iDeskId, GetDeskCount());

    return dynamic_cast<NFGameDesk *>(NFShmMgr::Instance()->GetObjFromGlobalID(m_AryDesks[iDeskId], EOT_GAME_DESK_ID));
}

int NFGameRoom::GetDeskCount()
{
	return m_AryDesks.GetSize();
}

bool NFGameRoom::AddMessageCallBack(uint16_t subMsgId)
{
    return NFIPluginManager::Instance()->FindModule<NFIGameRoomModule>()->AddMessageCallBack(m_gameId, subMsgId);
}

int NFGameRoom::OnHandleClientMsg(int32_t deskId, uint64_t playerId, uint16_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    CHECK_EXPR(deskId >= 0 && (int)deskId < GetDeskCount(), -1, "deskId error, deskId:{} msg:{}", deskId, nMsgId);

    NFGameDesk* pGameDesk = GetGameDesk(deskId);
    CHECK_EXPR(pGameDesk, -1, "GetGameDesk failed!, deskId:{}", deskId);

    int ret = pGameDesk->OnHandleClientMsg(playerId, nMsgId, msg, nLen);
    CHECK_EXPR(ret == 0, -1, "GameDesk OnHandleClientMsg ret != 0, playerId:{} nMsgId:{}", playerId, nMsgId);

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFGameRoom::ClearJiangChi()
{
    for(int i = 0; i < (int)GetDeskCount(); i++)
    {
        NFGameDesk *pDesk = GetGameDesk(i);
        if (pDesk)
        {
            int iRet = pDesk->ClearJiangChi();
            if (iRet != 0)
            {
                return iRet;
            }
        }
    }
    return 0;
}

int NFGameRoom::ChangeJiangChi(int64_t jiangchi)
{
    for(int i = 0; i < (int)GetDeskCount(); i++)
    {
        NFGameDesk *pDesk = GetGameDesk(i);
        if (pDesk)
        {
            int iRet = pDesk->ChangeJiangChi(jiangchi);
            if (iRet != 0)
            {
                return iRet;
            }
        }
    }
    return 0;
}

int NFGameRoom::OnHandleServerMsg(int32_t deskId, uint64_t playerId, uint32_t nMsgId, const char *msg, uint32_t nLen) {
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    CHECK_EXPR(deskId >= 0 && (int)deskId < GetDeskCount(), -1, "deskId error, deskId:{} msg:{}", deskId, nMsgId);

    NFGameDesk *pGameDesk = GetGameDesk(deskId);
    CHECK_EXPR(pGameDesk, -1, "GetGameDesk failed!, deskId:{}", deskId);

    int ret = pGameDesk->OnHandleServerMsg(playerId, nMsgId, msg, nLen);
    CHECK_EXPR(ret == 0, -1, "GameDesk OnHandleClientMsg ret != 0, playerId:{} nMsgId:{}", playerId, nMsgId);

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFGameRoom::SendMsgToClient(uint64_t playerId, uint16_t nSubMsgId, const google::protobuf::Message &xData) 
{
    return NFIPluginManager::Instance()->FindModule<NFIGameRoomModule>()->SendMsgToClientByPlayerId(playerId, m_gameId,
                                                                                                    nSubMsgId, xData);
}

int NFGameRoom::BroadCastMsgToRoom(uint16_t nSubMsgId, const google::protobuf::Message &xData, int32_t chairId)
{
	for (int i = 0; i < (int)GetDeskCount(); i++)
	{
		NFGameDesk* pDesk = GetGameDesk(i);
		if (pDesk != NULL)
		{
			return pDesk->BroadCastMsgToDesk(nSubMsgId, xData, chairId);
		}
	}

	return 0;
}

int NFGameRoom::BroadCastMsgToDesk(int32_t deskId, uint16_t nSubMsgId, const google::protobuf::Message &xData, int32_t chairId)
{
	NFGameDesk* pDesk = GetGameDesk(deskId);
	CHECK_NULL(pDesk);

	return pDesk->BroadCastMsgToDesk(nSubMsgId, xData, chairId);
}

int NFGameRoom::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId)
{
    NFGameRobot* pRobot = NFGameRobotMgr::Instance()->GetRobot(playerId);
    if (!pRobot)
    {
        return NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER,
                                                              nMsgId, xData, playerId);
    }

    return 0;
}

int NFGameRoom::SendMsgToLogicServer(uint32_t nMsgId, uint32_t busId, const google::protobuf::Message &xData)
{
	return NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_GAME_SERVER, busId,
						nMsgId, xData);
}

int NFGameRoom::SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId)
{
    NFGameRobot* pRobot = NFGameRobotMgr::Instance()->GetRobot(playerId);
    if (!pRobot)
    {
        return NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_GAME_SERVER,
                                                            nMsgId, xData, playerId);
    }

    return 0;
}

//int NFGameRoom::OnHandleEnterGameAutoJoinMsg(uint64_t playerId, const proto_ff::EnterGameAutoJoinReq xMsg) 
//{
//    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
//
//    //寻找一个桌子，然后走坐桌流程
//    int iDeskIndex = -1;
//    int iDeskStation = -1;
//    NFGameSession *pPlayer = NFIPluginManager::Instance()->FindModule<NFIGameRoomModule>()->GetPlayer(playerId);
//    if (pPlayer) {
//        if (pPlayer->m_gameId == m_gameId && pPlayer->m_roomId == m_roomId)
//        {
//            if (pPlayer->m_tableId > 0)
//            {
//                iDeskIndex = pPlayer->m_tableId;
//                iDeskStation = pPlayer->m_chairId;
//
//                NFGameDesk *pDesk = GetGameDesk(iDeskIndex - 1);
//                CHECK_EXPR(pDesk, -1, "pDesk == null");
//
//                int iRet = pDesk->LoginDesk(playerId, iDeskStation);
//                CHECK_PLAYER_EXPR(playerId, iRet == 0, -1, "Login Desk Failed, ret:{}", iRet);
//                return 0;
//            }
//        }
//    }
//
//    if (LookingSuitSeatForPlayer(playerId, iDeskIndex, iDeskStation) != 0) {
//        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, playerId,
//                   "CGameRoom::HandleMsgAutoJoinDesk Can not find any desk in GameID:{} RoomID:{}.", m_gameId,
//                   m_roomId);
//
//        proto_ff::EnterGameAutoJoinRsp rspMsg;
//        rspMsg.set_result(-1);
//        SendMsgToServer(NF_ST_WORLD_SERVER, proto_ff::NF_CS_MSG_EnterGame_AUTO_JOIN_Rsp, rspMsg, playerId);
//        return -1;
//    }
//
//    CHECK_EXPR(iDeskIndex >= 1 && iDeskIndex <= GetDeskCount(), -1, "iDeskIndex error", iDeskIndex);
//    NFGameDesk *pDesk = GetGameDesk(iDeskIndex);
//    CHECK_EXPR(pDesk, -1, "pDesk == null");
//
//    int iRet = pDesk->LoginDesk(playerId, iDeskStation);
//    CHECK_PLAYER_EXPR(playerId, iRet == 0, -1, "Login Desk Failed, ret:{}", iRet);
//
//    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
//    return 0;
//}

int NFGameRoom::OnHandleReqDeskListFromClient(uint64_t playerId, uint32_t autoChairId)
{
    proto_game::DeskListRsp deskListRsp;
    deskListRsp.set_result(0);
	if (autoChairId == 1)//return deskList
	{
		for (int i = 0; i < GetDeskCount(); i++)
		{
			NFGameDesk* pDesk = GetGameDesk(i);
			if (pDesk != NULL)
			{
				int deskId = pDesk->m_deskId + 1;//actally the same as i+1;

                proto_game::GameDeskInfo* pDeskInfo = deskListRsp.add_desks();
				pDeskInfo->set_desk_id(deskId);
				pDeskInfo->set_desk_name("deskName");
				pDeskInfo->set_desk_status(0);
				pDeskInfo->set_chair_count(pDesk->m_chairCount);

				NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "=============> add desk = {}", deskId);

				for (int j = 0; j < pDesk->m_arrDeskStationId.GetSize(); j++)
				{
					NFGameDeskStation* destStation = pDesk->GetDeskStation(j);

                    proto_game::GameChairInfo* pChairInfo = pDeskInfo->add_chairs();
					if (pChairInfo != NULL)
					{
						int chairId = j + 1;

						pChairInfo->set_chair_id(chairId);

						if (destStation->m_playerId == 0)
						{
							NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "=============> add chair = {} , chair_status = 0", chairId);
							pChairInfo->set_chair_status(0);//idle
						}
						else
						{
							NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "=============> add chair = {} , chair_status = 1", chairId);
							pChairInfo->set_chair_status(1);//有人
						}
					}
				}
			}
		}
	}
	else //autoChairId=0  //auto sel chair
	{
        int iDeskIndex = -1;
        int iDeskStaion = -1;
        if (LookingSuitSeatForPlayer(playerId, iDeskIndex, iDeskStaion) == 0)
        {
            NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
            if (pPlayer)
            {
                pPlayer->m_reservedTime = NFTime::Now().UnixSec();
                pPlayer->m_reservedDeskId = iDeskIndex;
                pPlayer->m_reservedChairId = iDeskStaion;
            }

            int iDeskId = iDeskIndex + 1;
            int iChairId = iDeskStaion + 1;

            proto_game::GameDeskInfo* pDeskInfo = deskListRsp.add_desks();
            pDeskInfo->set_desk_id(iDeskId);
            pDeskInfo->set_desk_name("deskName");
            pDeskInfo->set_desk_status(0);
            pDeskInfo->set_chair_count(1);

            //自动选一个座位并保留 todo

            proto_game::GameChairInfo* pChairInfo = pDeskInfo->add_chairs();
            pChairInfo->set_chair_id(iChairId);
            pChairInfo->set_chair_status(0);

            NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "=============> auto desk ! iDeskId = {}, iChairId = {}", iDeskId, iChairId);
        }
	}

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "SendMsgToWorldServer ==> NF_CS_MSG_DeskList_Rsp playerId = {}", playerId);

	SendMsgToWorldServer(proto_game::NF_SC_MSG_DeskListRsp, deskListRsp, playerId);

	return 0;
}

int NFGameRoom::OnHandleEnterGameMsg(NFGameSession *pPlayer, int deskId, int chairId)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin -- gameId = {} , roomId = {}, deskId = {} , chairId = {}", m_gameId, m_roomId, deskId, chairId);
	CHECK_EXPR(pPlayer, -1, "pPlayer == NULL");

	NFGameDesk *pDesk = GetGameDesk(deskId);
	if (!pDesk)
    {
        proto_game::EnterGameRsp rspMsg;
        rspMsg.set_result(proto_ff::ERR_CODE_DESK_NOT_EXIST);
        rspMsg.set_player_id(pPlayer->m_playerId);
        if (!pPlayer->m_isRobot)
        {
            return NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER,
                                                                  proto_game::NF_SC_MSG_EnterGameRsp, rspMsg, pPlayer->m_playerId);
        }
        CHECK_EXPR(pDesk, 0, "deskId:{} not exist", deskId);
    }

	if (pPlayer->m_isRobot == false)
	{
		pDesk->OnHandleEnterGameMsg(pPlayer, chairId);
	}
	else
	{
        NFGameRobot* pRobot = NFGameRobotMgr::Instance()->GetRobot(pPlayer->m_playerId);
        CHECK_NULL(pRobot);

        const proto_ff_s::GameRoomDesc_s* roomConfig = NFIPluginManager::Instance()->FindModule<NFIGameRoomModule>()->GetRoomConfig(m_gameId, m_roomId);
        if (!roomConfig)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFGameRoomDesc: find room failed! mGameId = {} , mRoomId = {}", m_gameId, m_roomId);
            return 0;
        }

		proto_ff_s::GamePlayerDetailData_s playerDetail;
		playerDetail.player_id = pPlayer->GetPlayerId();
		playerDetail.nick_name = pRobot->m_nickname.GetString();
		playerDetail.face = pRobot->m_face_id;
		playerDetail.sex = pRobot->m_gender;
		playerDetail.cur_money = pRobot->m_jetton;
        if (roomConfig->is_exp_scene > 0)
        {
            playerDetail.cur_money = roomConfig->exp_scene_gold;
        }
        else
        {
            if (playerDetail.cur_money < roomConfig->enter_min)
            {
                if (roomConfig->enter_max > 0)
                {
                    playerDetail.cur_money = NFRandomInt(roomConfig->enter_min, roomConfig->enter_max);//这个从配置读取
                }
                else
                {
                    playerDetail.cur_money = NFRandomInt(roomConfig->enter_min, 1000000000);//这个从配置读取
                }
            }
            else if (roomConfig->enter_max > 0 && playerDetail.cur_money > roomConfig->enter_max)
            {
                playerDetail.cur_money = NFRandomInt(roomConfig->enter_min, roomConfig->enter_max);//这个从配置读取
            }
			else
			{
				playerDetail.cur_money = NFRandomInt(1000000, 3000000);//这个从配置读取
			}
        }
		playerDetail.isRobot = true;

		int iRet = pDesk->LoginDesk(pPlayer, chairId, playerDetail);//没有钱也应该可以进桌子，是不是这样？  进桌子不应该依赖钱
		if (iRet != 0)
        {
            NFGameRoomMgr::GetInstance()->ClearDirtyData(pPlayer->m_playerId);
        }
	}

	//CHECK_PLAYER_EXPR(pPlayer->m_playerId, iRet == 0, -1, "Login Desk Failed, ret:{}", iRet);

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFGameRoom::OnHandleUserReComeMsg(uint64_t playerId)
{
	NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
	CHECK_PLAYER_EXPR(playerId, pPlayer, -1, "Get Player Failed, playerId:{}", playerId);

	int32_t deskId = pPlayer->m_deskId;

	if (deskId==INVALID_ID)//如果已经没有座位信息了，无法断线重连，只能走自动坐桌；
	{
		//todo 

		return -1;
	}

	//如果座位信息还在，
	NFGameDesk *pDesk = GetGameDesk(pPlayer->m_deskId);
	CHECK_EXPR(pDesk, -1, "pDesk == null");

	NFGameDeskStation* pDeskStation = pDesk->GetDeskStationByPlayerId(playerId);
	CHECK_EXPR(pDeskStation, -1, "pDeskStation == NULL");

	pDesk->LoginDesk(pPlayer, pDeskStation->m_chairId, pDeskStation->m_playerDetail);

	return 0;
}

int NFGameRoom::OnHandleExitGameMsg(uint64_t playerId)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

	NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
	CHECK_PLAYER_EXPR(playerId, pPlayer, -1, "Get Player Failed, playerId:{}", playerId);
	
	NFGameDesk *pDesk = GetGameDesk(pPlayer->m_deskId);
	if (pDesk == NULL)
    {
	    if (!pPlayer->m_isRobot)
        {
            proto_game::ExitGameRsp rspMsg;
            rspMsg.set_exit_type(0);
            pPlayer->SendMsgToWorld(proto_game::NF_SC_MSG_ExitGameRsp, rspMsg, playerId);
        }

        pPlayer->ClearGameData();
        return -1;
    }


	int ret = pDesk->LogOutDesk(playerId, false);
	if (ret == 0)
	{
		if (!pPlayer->m_isRobot)
		{
			proto_game::ExitGameRsp rspMsg;
			rspMsg.set_exit_type(0);
			pPlayer->SendMsgToWorld(proto_game::NF_SC_MSG_ExitGameRsp, rspMsg, playerId);
		}
	}
	else
	{
		if (!pPlayer->m_isRobot)
		{
			NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "==============> ret = {}", ret);

			proto_game::ExitGameRsp rspMsg;
			rspMsg.set_exit_type(ret);
			pPlayer->SendMsgToWorld(proto_game::NF_SC_MSG_ExitGameRsp, rspMsg, playerId);
		}
	}

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

//std::string NFGameRoom::Test()
//{
//	NFGameDesk *pDesk = GetGameDesk(1);
//
//	if (pDesk != NULL)
//	{
//		return pDesk->Test();
//	}
//
//	return "";
//}

int NFGameRoom::UpdateUserMoney(int32_t deskId, uint64_t playerId, uint32_t changeType, uint64_t moneyChange)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
	CHECK_EXPR(moneyChange > 0, -1, "moneyChange error:{}", moneyChange);

	NFGameDesk *pDesk = GetGameDesk(deskId);
	CHECK_EXPR(pDesk, -1, "pDesk == null, deskId:{} playerId:{} changeType:{}, moneyChange:{}", deskId, playerId, changeType, moneyChange);

	int iRetCode = pDesk->UpdateUserMoney(playerId, changeType, moneyChange);
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return iRetCode;
}

int NFGameRoom::SetUserManagerInfo(int32_t deskId, uint64_t playerId, const proto_ff_s::tbGameUserManagerData_s* pUserManagerData)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_NULL(pUserManagerData);

    const proto_ff_s::GameRoomDesc_s* roomConfig = GetRoomConfig();
    CHECK_NULL(roomConfig);

    if (roomConfig->is_exp_scene > 0)
    {
        if (pUserManagerData->game_id != (uint32_t)roomConfig->GameID || pUserManagerData->room_id != (uint32_t)roomConfig->RoomID)
        {
            return 0;
        }
    }

    NFGameDesk *pDesk = GetGameDesk(deskId);
    CHECK_EXPR(pDesk, -1, "pDesk == null, deskId:{} playerId:{} ", deskId, playerId);

    int iRetCode = pDesk->SetUserManagerInfo(playerId, pUserManagerData);
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

int NFGameRoom::SetGmCtrlGiveData(int32_t deskId, uint64_t playerId, const proto_ff_s::tbGmCtrlGiveCtrlData_s* pGmCtrlGiveDta)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_NULL(pGmCtrlGiveDta);

    if (pGmCtrlGiveDta->game_id != m_gameId)
    {
        return 0;
    }

    const proto_ff_s::GameRoomDesc_s* roomConfig = GetRoomConfig();
    CHECK_NULL(roomConfig);

    if (roomConfig->is_exp_scene > 0)
    {
        return 0;
    }

    NFGameDesk *pDesk = GetGameDesk(deskId);
    CHECK_EXPR(pDesk, -1, "pDesk == null, deskId:{} playerId:{} ", deskId, playerId);

    int iRetCode = pDesk->SetGmCtrlGiveData(playerId, pGmCtrlGiveDta);
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

int NFGameRoom::UpdateUserInfo(int32_t deskId, uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s* pUserManagerData)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    const proto_ff_s::GameRoomDesc_s* roomConfig = GetRoomConfig();
    CHECK_NULL(roomConfig);

    if (roomConfig->is_exp_scene > 0)
    {
        return 0;
    }

    NFGameDesk *pDesk = GetGameDesk(deskId);
    CHECK_EXPR(pDesk, -1, "pDesk == null, deskId:{} playerId:{} ", deskId, playerId);

    int iRetCode = pDesk->UpdateUserInfo(playerId, pUserManagerData);
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return iRetCode;
}

int NFGameRoom::PaoMaDengNotify(const std::string& playerName, uint64_t winJetton)
{
    proto_game::OnePaoMaDengInfo notify;
    notify.set_user_name(playerName);
    notify.set_game_id(m_gameId);
    notify.set_room_id(m_roomId);
    notify.set_game_name(m_gameName.GetString());
    notify.set_room_name(m_roomName.GetString());
    notify.set_win_jetton(winJetton);
    return NFPaoMaDengMgr::Instance()->AddPaoMaDeng(notify);
}

int NFGameRoom::LookingSuitSeatForPlayer(uint64_t playerId, int &iDeskIndex, int &iDeskStation) {
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    uint64_t ulNowTime = NFTime::Now().UnixSec();
    NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
    if (pPlayer && ulNowTime - pPlayer->m_reservedTime <= 15)
    {
        NFGameDesk *pDesk = GetGameDesk(pPlayer->m_reservedDeskId);
        if (pDesk)
        {
            auto pDeskStation = pDesk->GetDeskStation(pPlayer->m_reservedChairId);
            if (pDeskStation && pDeskStation->m_playerId <= 0) {
                iDeskIndex = pPlayer->m_reservedDeskId;
                iDeskStation = pPlayer->m_reservedChairId;

                NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, playerId,
                          "GameRoom::LookingSuitSeatForPlayer PlayerId:{} find a seat in desk. DeskIndex:{}, DeskStation:{}.",
                          playerId, iDeskIndex, iDeskStation);

                ReserveSeat(playerId, iDeskIndex, iDeskStation);
                return 0;
            }
        }
    }

    std::vector<TDeskStationNode> vtSeatsList;
    for (int i = 0; i < GetDeskCount(); i++) {
        NFGameDesk *pDesk = GetGameDesk(i);
        if (pDesk) {
            if (pDesk->LookingSuitSeatForPlayer(playerId, iDeskStation) == 0) {
                iDeskIndex = pDesk->m_deskId;
                TDeskStationNode tmpDeskStationNode;
                tmpDeskStationNode.m_nDeskIndex = iDeskIndex;
                tmpDeskStationNode.m_nDeskStation = iDeskStation;
                vtSeatsList.push_back(tmpDeskStationNode);
                //从性能考虑，找到10个桌子，就可以了
                if (vtSeatsList.size() >= 10) {
                    break;
                }
            }
        }
    }

    //找到对应位置，做一次随机取值
    if (vtSeatsList.size() > 0) {
        int unIndex = NFRandInt(0, (int) vtSeatsList.size());
        iDeskIndex = vtSeatsList[unIndex].m_nDeskIndex;
        iDeskStation = vtSeatsList[unIndex].m_nDeskStation;
        NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, playerId,
                  "GameRoom::LookingSuitSeatForPlayer PlayerId:{} find a seat in desk. DeskIndex:{}, DeskStation:{}.",
                  playerId, iDeskIndex, iDeskStation);
        //预定该位置
        ReserveSeat(playerId, iDeskIndex, iDeskStation);
        return 0;
    }

    //顺序找一个位置
    for (int iDeskId = 0; iDeskId < GetDeskCount(); iDeskId++) {
        NFGameDesk *pDesk = GetGameDesk(iDeskId);
        if (pDesk == NULL) continue;

        if (pDesk->Looking4SeatBySequence(playerId, iDeskStation) == 0) {
            iDeskIndex = pDesk->m_deskId;
            NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, playerId,
                      "CGameRoom::LookingSuitSeatForPlayer() playerId:{} find a seat 4 sequence. DeskIndex:{}, DeskStation:{}.",
                      playerId, iDeskIndex, iDeskStation);
            //预定该位置
            ReserveSeat(playerId, iDeskIndex, iDeskStation);
            return 0;
        }
    }

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return -1;
}

int NFGameRoom::LookingSuitSeatForRobot(uint64_t playerId, int &iDeskIndex, int &iDeskStation, int maxRobotPerDesk, bool bIsNeedRealPlayer /*= true*/)
{
	for (int i = 0; i < GetDeskCount(); i++)
	{
		NFGameDesk *pDesk = GetGameDesk(i);
		if (pDesk) 
		{
			int deskIndex = i;
			int deskStation = 0;
			if (pDesk->LookingSuitSeatForRobot(playerId, deskStation, maxRobotPerDesk, bIsNeedRealPlayer) == 0)
			{
				iDeskIndex   = deskIndex;
				iDeskStation = deskStation;

				return 0;
			}
		}
	}

	return -1;
}

void NFGameRoom::GetDeadRobots(std::vector<uint64_t>& vec)
{
	for (int i = 0; i < GetDeskCount(); i++)
	{
		NFGameDesk *pDesk = GetGameDesk(i);
		if (pDesk)
		{			
			pDesk->GetDeadRobots(vec);
		}
	}
}

//预定座位
int NFGameRoom::ReserveSeat(uint64_t playerId, int iDeskId, int iDeskStation) {
    CHECK_EXPR(iDeskId >= 0 && iDeskId < GetDeskCount(), -1, "iDeskId error:{}", iDeskId);

    NFGameDesk *pDesk = GetGameDesk(iDeskId);
    CHECK_EXPR(pDesk, -1, "GetGameDesk Failed:{}", iDeskId);

    return pDesk->ReserveSeat(playerId, iDeskStation);
}

int NFGameRoom::UserReconDesk(uint64_t playerId, int iDeskId)
{
	CHECK_EXPR(iDeskId >= 0 && iDeskId < GetDeskCount(), -1, "deskIndex error:{}", iDeskId);

    NFGameDesk *pDesk = GetGameDesk(iDeskId);
    CHECK_EXPR(pDesk, -1, "GetGameDesk Failed:{}", iDeskId);

	NFGameDeskStation* pDeskStation = pDesk->GetDeskStationByPlayerId(playerId);
	CHECK_EXPR(pDeskStation, -1, "pDeskStation == NULL");
    return pDesk->UserReconDesk(playerId, pDeskStation->m_chairId, pDeskStation->m_playerDetail);
}

int NFGameRoom::UserDisconnect(uint64_t playerId, int iDeskId)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "UserDisconnect");

    CHECK_EXPR(iDeskId >= 0 && iDeskId < GetDeskCount(), -1, "deskIndex error:{}", iDeskId);

    NFGameDesk *pDesk = GetGameDesk(iDeskId);
    CHECK_EXPR(pDesk, -1, "GetGameDesk Failed : iDeskId ={}", iDeskId);

    return pDesk->LogOutDesk(playerId, true);
}

int NFGameRoom::OnGameBegin(int iDeskId) {
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "--begin--");
    NFGameDesk *pDesk = GetGameDesk(iDeskId);
    CHECK_EXPR(pDesk, -1, "GetGameDesk Failed:{}", iDeskId);

    int iRetCode = pDesk->OnGameBegin();

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "--end--iRetCode={}", iRetCode);
    return iRetCode;
}

int NFGameRoom::OnGameFinish(int iDeskId) {
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "--begin--");
    NFGameDesk *pDesk = GetGameDesk(iDeskId);
    CHECK_EXPR(pDesk, -1, "GetGameDesk Failed:{}", iDeskId);

    int iRetCode = pDesk->OnGameFinish();

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "--end--iRetCode={}", iRetCode);
    return iRetCode;
}

bool NFGameRoom::IsPlayGame(int iDeskId, int iDeskStation) {
    NFGameDesk *pDesk = GetGameDesk(iDeskId);
    CHECK_EXPR(pDesk, false, "GetGameDesk Failed:{}", iDeskId);

    bool iRetCode = pDesk->IsPlayGame(iDeskStation);

    return iRetCode;
}

bool NFGameRoom::IsPlayGameCanLeave(int iDeskId, int iDeskStation)
{
	NFGameDesk *pDesk = GetGameDesk(iDeskId);
	CHECK_EXPR(pDesk, false, "GetGameDesk Failed:{}", iDeskId);

	bool iRetCode = pDesk->IsPlayGameCanLeave(iDeskStation);

	return iRetCode;
}

int NFGameRoom::ClearIdleUser(uint64_t playerId) {
    return ClearDirtyData(playerId);
}

int NFGameRoom::ClearDirtyData(uint64_t playerId) {
    for(int i = 0; i < (int)GetDeskCount(); i++)
    {
        NFGameDesk *pDesk = GetGameDesk(i);
        if (pDesk)
        {
            int iRet = pDesk->ClearDirtyData(playerId);
            if (iRet != 0)
            {
                return iRet;
            }
        }
    }

    return 0;
}

int NFGameRoom::ClearTimeOutUser(uint64_t playerId) {
    for(int i = 0; i < (int)GetDeskCount(); i++)
    {
        NFGameDesk *pDesk = GetGameDesk(i);
        if (pDesk)
        {
            if (pDesk->IsInDesk(playerId))
            {
                int iRet = pDesk->ClearTimeOutUser(playerId);
                if (iRet != 0)
                {
                    return iRet;
                }
            }
        }
    }

    return 0;
}

int NFGameRoom::ClearOfflineUser(uint64_t playerId) {
    for(int i = 0; i < (int)GetDeskCount(); i++)
    {
        NFGameDesk *pDesk = GetGameDesk(i);
        if (pDesk)
        {
            if (pDesk->IsInDesk(playerId))
            {
                int iRet = pDesk->ClearOfflineUser(playerId);
                if (iRet != 0)
                {
                    return iRet;
                }
            }
        }
    }
    return 0;
}

void NFGameRoom::KickUser(uint64_t playerId, int nReasonCode) {
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "--begin--");

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "--end--");
}

void NFGameRoom::OnTimer(int timeId, int callcount)
{
    if (m_statTimer == timeId)
    {
        if (m_roomStatInfo.IsUrgentNeedSave())
        {
            if (NFTime::Now().UnixSec() - m_lastSendTime > 60)
            {
                SendGameRoomStatInfo();
                ClearGameRoomStatInfo();
                m_roomStatInfo.ClearUrgent();

                m_lastSendTime = NFTime::Now().UnixSec();
            }
        }

        for(int i = 0; i < (int)GetDeskCount(); i++)
        {
            NFGameDesk *pDesk = GetGameDesk(i);
            if (pDesk)
            {
                pDesk->Tick();
            }
        }
    }
}

int NFGameRoom::SendGameRoomStatInfo()
{
    const proto_ff_s::GameRoomDesc_s* roomConfig = FindModule<NFIGameRoomModule>()->GetRoomConfig(m_gameId, m_roomId);
    if (!roomConfig)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "SendGameRoomStatInfo: find room failed! mGameId = {} , mRoomId = {}", m_gameId, m_roomId);
        return -1;
    }

    proto_ff::Proto_GameTSns_GameRoomStatInfoReq req;
    req.set_game_id(m_gameId);
    req.set_room_id(m_roomId);
    req.set_is_exe_scene(roomConfig->is_exp_scene > 0 ? true:false);
    proto_ff_s::GameRoomStat_s::write_to_pbmsg(m_roomStatInfo, *req.mutable_stat_info());

    NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_GAME_SERVER, proto_ff::E_GameTSns_GAME_ROOM_STAT_INFO_SEND, req);
    return 0;
}

int NFGameRoom::ClearGameRoomStatInfo()
{
    m_roomStatInfo.cur_pour = 0;
    m_roomStatInfo.cur_fee = 0;
    m_roomStatInfo.cur_win = 0;
    return 0;
}

int NFGameRoom::GameDataCommit(uint64_t cur_fee, uint64_t cur_pour, int64_t cur_win)
{
    m_roomStatInfo.cur_pour += cur_pour;
    m_roomStatInfo.cur_fee += cur_fee;
    m_roomStatInfo.cur_win += cur_win;
    m_roomStatInfo.MarkDirty();

    return 0;
}

const proto_ff_s::GameRoomDesc_s* NFGameRoom::GetRoomConfig()
{
    return FindModule<NFIGameRoomModule>()->GetRoomConfig(m_gameId, m_roomId);
}