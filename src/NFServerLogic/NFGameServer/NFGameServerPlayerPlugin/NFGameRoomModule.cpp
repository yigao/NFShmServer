// -------------------------------------------------------------------------
//    @FileName         :    NFGameRoomModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameRoomModule.cpp
//
// -------------------------------------------------------------------------

#include "NFGameRoomModule.h"
#include "NFGameRoom.h"
#include "NFGameDesk.h"
#include "NFGameRoomMgr.h"
#include "NFComm/NFShmCore/NFSubGameTypeDefines.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFServer/NFCommHead/NFIGameServerModule.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFMessageDefine/proto_cs.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFMessageDefine/proto_event.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_login.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_game.pb.h"
#include "NFGameSession.h"
#include "NFGameSessionMgr.h"
#include "NFServer/NFCommHead/NFISubGameModule.h"
#include "NFGameRobotMgr.h"
#include "NFServer/NFCommHead/NFISubGameModule.h"
#include "NFRobotMgr.h"
#include "NFPaoMaDengMgr.h"

NFCGameRoomModule::NFCGameRoomModule(NFIPluginManager *p) : NFIGameRoomModule(p) {
}

NFCGameRoomModule::~NFCGameRoomModule() {
}

bool NFCGameRoomModule::Awake()
{

    //NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_ff::NF_CS_MSG_EnterGame_AUTO_JOIN_Req,
    //                                                   this,
    //                                                   &NFCGameRoomModule::OnHandleEnterGameAutoJoin);

	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_game::NF_CS_MSG_DeskListReq,
                                                       this,
                                                       &NFCGameRoomModule::OnHandleReqDeskListFromClient);
	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_game::NF_CS_MSG_ChairCheckReq,
                                                       this,
                                                       &NFCGameRoomModule::OnHandleReqChairCheckFromClient);
	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_game::NF_CS_MSG_EnterGameReq,
														this,
														&NFCGameRoomModule::OnHandleEnterGameReqFromClient);

	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_game::NF_CS_MSG_UserRecomeReq,
														this,
														&NFCGameRoomModule::OnHandleReComeReqFromClient);

	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_game::NF_CS_MSG_ExitRoomReq,
                                                       this,
                                                       &NFCGameRoomModule::OnHandleExitRoomReqFromClient);


	NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_game::NF_CS_MSG_ExitGameReq,
                                                       this,
                                                       &NFCGameRoomModule::OnHandleExitGameReqFromClient);


    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_ff::NF_WTG_PLAYER_RECONNECT_MSG, this,
                                                       &NFCGameRoomModule::OnHandleReconnectFromClient);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_ff::NF_WTG_PLAYER_DISCONNECT_MSG, this,
                                                       &NFCGameRoomModule::OnHandlePlayerDisConnect);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_ff::E_STS_CLEAR_ALL_GAME_PLAYER_NOTIFY, this,
                                                 &NFCGameRoomModule::OnHandleClearAllGamePlayerNotify);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_ff::E_SnsTGame_SET_USER_MANAGER_INFO, this,
                                             &NFCGameRoomModule::OnHandleSetUserManagerInfo);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_ff::E_SnsTGame_SET_GM_CTRL_GIVE_DATA, this,
                                                 &NFCGameRoomModule::OnHandleSetGmCtrlGiveData);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_ff::E_LogicTGame_UPDATE_PLAYER_COINBALANCE, this,
                                                 &NFCGameRoomModule::OnHandleUpdateUserInfo);

    /////////////////world server msg///////////////////////////////////////
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_ff::NF_GTW_ROOM_REGISTER_RSP, this, &NFCGameRoomModule::OnHandleRegisterResp);

	Subscribe(proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
    Subscribe(proto_ff::NF_EVENT_SERVER_DEAD_EVENT, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
    Subscribe(proto_ff::NF_EVENT_SERVER_LOAD_DESC_STORE, 0, proto_ff::NF_EVENT_SERVER_TYPE, __FUNCTION__);
	//////////////////////////////////////////////////////////////////////////


	
	


	//////////////////////////////////////////////////////////////////////////


    return true;
}

int NFCGameRoomModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
{
    if (bySrcType == proto_ff::NF_EVENT_SERVER_TYPE)
    {
        if (nEventID == proto_ff::NF_EVENT_SERVER_LOAD_DESC_STORE)
        {
            NFRobotMgr::Instance()->Init();
        }
		if (nEventID == proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED)
		{
			CreateGameRoom();
			SetTimer(NF_TIMER_TYPE_REG_ROOM_INFO, 10000);
			RegisterGameRoom();
            NFPaoMaDengMgr::Instance()->Init();

			NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_GAME_SERVER);
			if (pConfig)
			{
				NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "========> pConfig->mRobotOn = {}", pConfig->mRobotOn);

				if (pConfig->mRobotOn)
				{
					SetTimer(NF_TIMER_TYPE_ROBOT_MGR_START, 5000);
				}
			}
			else
			{
				NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "========> pConfig = NULL");
			}
		}
		else if (nEventID == proto_ff::NF_EVENT_SERVER_DEAD_EVENT)
        {
		    SetTimer(10000, 10000, 0);
        }
    }
    return 0;
}

void NFCGameRoomModule::OnTimer(uint32_t nTimerID)
{
    if (nTimerID == NF_TIMER_TYPE_REG_ROOM_INFO)
    {
        RegisterGameRoom();
    }
    else if (nTimerID == NF_TIMER_TYPE_UPDATE_ROOM_INFO)
    {
        UpdateGameRoom();
    }
	else if (nTimerID == NF_TIMER_TYPE_ROBOT_MGR_START)
	{
		KillTimer(NF_TIMER_TYPE_ROBOT_MGR_START);

		SetTimer(NF_TIMER_TYPE_ROBOT_MGR, 1000);
	}
	else if (nTimerID == NF_TIMER_TYPE_ROBOT_MGR)
	{
		GameRobotMgrPolling();
	}
	else if (nTimerID == 10000)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "kill the exe..................");
        NFSLEEP(1000);
        exit(0);
    }
}

int NFCGameRoomModule::OnHandleRegisterResp(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    KillTimer(NF_TIMER_TYPE_REG_ROOM_INFO);
    SetTimer(NF_TIMER_TYPE_UPDATE_ROOM_INFO, 10000);
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCGameRoomModule::CreateGameRoom()
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_GAME_SERVER);
    if (pConfig)
    {
        for(int i = 0; i < (int)pConfig->mRoomIdList.size(); i++)
        {
            const proto_ff_s::GameRoomDesc_s* roomConfig = GetRoomConfig(pConfig->mGameId, pConfig->mRoomIdList[i]);
            if (!roomConfig)
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFGameRoomDesc: find room failed! mGameId = {} , mRoomId = {}", pConfig->mGameId, pConfig->mRoomIdList[i]);
                return -1;
            }

            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFGameRoomDesc: mGameId = {} , mRoomId = {}", pConfig->mGameId, pConfig->mRoomIdList[i]);

            NFGameRoom* pRoom = NFGameRoomMgr::GetInstance()->GetGameRoom(pConfig->mGameId, pConfig->mRoomIdList[i]);
            if (pRoom)
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Get Game Room Info Success, Not Need Create! gameId:{} roomId:{}", pConfig->mGameId, pConfig->mRoomIdList[i]);
                continue;
            }

            //////////////////////////////////////////////////////////////////////////

            pRoom = NFGameRoomMgr::GetInstance()->CreateGameRoom(pConfig->mGameId, pConfig->mRoomIdList[i]);
            if (!pRoom)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "Create Game Room Info Failed! gameId:{} roomId:{}", pConfig->mGameId, pConfig->mRoomIdList[i]);
                return -1;
            }

            int iRet = pRoom->Init(pConfig->mGameId, roomConfig->GameName.GetString(), pConfig->mRoomIdList[i], roomConfig->RoomName.GetString(), roomConfig->DeskCount, roomConfig->SiteNum, roomConfig->MaxPeople);
            if (iRet != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "Init Game Room Failed! gameId:{} roomId:{}, deskCount:{}", pConfig->mGameId, pConfig->mRoomIdList[i], roomConfig->DeskCount, roomConfig->SiteNum, roomConfig->MaxPeople);
                return iRet;
            }
        }
    }
	return 0;
}

int NFCGameRoomModule::RegisterGameRoom()
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    std::vector<NFGameRoom*> vecRoom = NFGameRoomMgr::GetInstance()->GetAllRoom();
    for(size_t i = 0; i < vecRoom.size(); i++)
    {
        NFGameRoom* pGameRoom = vecRoom[i];
        if (pGameRoom)
        {
            NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_GAME_SERVER);
            if (pConfig)
            {
                proto_ff::GameRoomRegReq xMsg;
                auto pRoomInfo = xMsg.mutable_room_info();
                if (pRoomInfo)
                {
                    pRoomInfo->set_game_id(pGameRoom->m_gameId);
                    pRoomInfo->set_room_id(pGameRoom->m_roomId);
                    pRoomInfo->set_bus_id(pConfig->mBusId);
                    pRoomInfo->set_online_count(NFGameSessionMgr::Instance()->GetPlayerCount());

                    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "Game Server Register Room Info To World Server, gameId:{}, roomId:{}", pRoomInfo->game_id(), pRoomInfo->room_id());
                }


                NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER, proto_ff::NF_GTW_ROOM_REGISTER_REQ, xMsg);
            }
        }
    }
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCGameRoomModule::UpdateGameRoom()
{
    std::vector<NFGameRoom*> vecRoom = NFGameRoomMgr::GetInstance()->GetAllRoom();
    for(size_t i = 0; i < vecRoom.size(); i++)
    {
        NFGameRoom* pGameRoom = vecRoom[i];
        if (pGameRoom)
        {
            NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_GAME_SERVER);
            if (pConfig)
            {
                proto_ff::GameRoomRegReq xMsg;
                auto pRoomInfo = xMsg.mutable_room_info();
                if (pRoomInfo)
                {
                    pRoomInfo->set_game_id(pGameRoom->m_gameId);
                    pRoomInfo->set_room_id(pGameRoom->m_roomId);
                    pRoomInfo->set_bus_id(pConfig->mBusId);
                    pRoomInfo->set_online_count(NFGameSessionMgr::Instance()->GetPlayerCount());
                }

                NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER, proto_ff::NF_GTW_ROOM_UPDATE_ONLINE_COUNT_REQ, xMsg);
            }
        }
    }
    return 0;
}

bool NFCGameRoomModule::ReadyExecute()
{
    return true;
}

bool NFCGameRoomModule::Execute()
{
    return true;
}

bool NFCGameRoomModule::OnDynamicPlugin()
{
    return true;
}

bool NFCGameRoomModule::AddMessageCallBack(uint16_t gameId, uint16_t subMsgId)
{
    uint32_t msgId = MAKE_UINT32(subMsgId, gameId);
	return NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, msgId, this, &NFCGameRoomModule::OnHandleRoomMsg);
}

int NFCGameRoomModule::OnHandleRoomMsg(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    uint16_t nMainMsgId = HIGH_UINT16(nMsgId);
    uint16_t nSubMsgId = LOW_UINT16(nMsgId);
    NFGameSession* pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
    CHECK_PLAYER_EXPR(playerId, pPlayer, -1, "Get Player Failed, playerId:{}", playerId);

	pPlayer->SetLastMsgTime(NFTime::Now().UnixSec());

    NFGameRoom* pRoom = NFGameRoomMgr::GetInstance()->GetGameRoom(pPlayer->m_gameId, pPlayer->m_roomId);
    CHECK_PLAYER_EXPR(playerId, pRoom, -1, "Get Player Game Room Failed, playerId:{}, gameId:{}, roomId:{}", playerId, pPlayer->m_gameId, pPlayer->m_roomId);

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "nMsgId = {} , nMainMsgId = {} , nSubMsgId = {} , pPlayer->m_gameId = {}", nMsgId, nMainMsgId, nSubMsgId, pPlayer->m_gameId);

    CHECK_PLAYER_EXPR(playerId, nMainMsgId == pPlayer->m_gameId, -1, "the Main Msg Id:{} error, not right the player:{} gameId:{}", nMainMsgId, playerId, pPlayer->m_gameId);


    pRoom->OnHandleClientMsg(pPlayer->m_deskId, pPlayer->m_playerId, nSubMsgId, msg, nLen);

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

//int NFCGameRoomModule::OnHandleEnterGameAutoJoin(uint64_t unLinkId, uint64_t playerId, uint32_t nMsgId, const char *msg,
//                                                 uint32_t nLen) {
//    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
//
//    proto_ff::EnterGameAutoJoinReq xMsg;
//    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);
//
//    CHECK_EXPR(xMsg.game_id() > 0 && xMsg.room_id() > 0, -1, "msg param error");
//
//    NFGameRoom *pRoom = NFGameRoomIDHashTable::GetInstance()->GetGameRoom(xMsg.game_id(), xMsg.room_id());
//    if (!pRoom) {
//        NFLogError(NF_LOG_SYSTEMLOG, 0, "Get Game Room Info Failed! gameId:{} roomId:{}", xMsg.game_id(), xMsg.room_id());
//        proto_ff::EnterGameAutoJoinRsp rspMsg;
//        rspMsg.set_result(-1);
//
//        NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER,
//                                                           proto_ff::NF_CS_MSG_EnterGame_AUTO_JOIN_Rsp, rspMsg, playerId);
//        return 0;
//    }
//
//    NFGameSession *pPlayer = NFIPluginManager::Instance()->FindModule<NFIGameRoomModule>()->GetPlayer(playerId);
//    if (pPlayer)
//    {
//        pPlayer->m_proxyId = xMsg.proxy_id();
//    }
//
//    pRoom->OnHandleEnterGameAutoJoinMsg(playerId, xMsg);
//
//    pPlayer = NFIPluginManager::Instance()->FindModule<NFIGameRoomModule>()->GetPlayer(playerId);
//    if (pPlayer)
//    {
//        pPlayer->m_proxyId = xMsg.proxy_id();
//    }
//
//    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
//    return 0;
//}

int NFCGameRoomModule::OnHandleReqDeskListFromClient(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    proto_game::DeskListReq xMsg;
	CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);
	
    const proto_ff_s::GameRoomDesc_s* roomConfig = GetRoomConfig(xMsg.game_id(), xMsg.room_id());
    if (!roomConfig)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFGameRoomDesc: find room failed! mGameId = {} , mRoomId = {}", xMsg.game_id(), xMsg.room_id());
        proto_game::DeskListRsp deskListRsp;
        deskListRsp.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        NFGameRobot* pRobot = NFGameRobotMgr::Instance()->GetRobot(playerId);
        if (!pRobot)
        {
            return NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER,
                                                              proto_game::NF_SC_MSG_DeskListRsp, deskListRsp, playerId);
        }
        return 0;
    }

    if (roomConfig->is_exp_scene <= 0 && (int64_t)xMsg.cur_money() < roomConfig->enter_min)
    {
        proto_game::DeskListRsp deskListRsp;
        deskListRsp.set_result(proto_ff::ERR_CODE_USER_MONEY_NOT_ENOUGH);

        NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER, proto_game::NF_SC_MSG_DeskListRsp, deskListRsp, playerId);
        return 0;
    }

	uint32_t autoChairId = roomConfig->auto_chair;// 1;// 1-显示桌子列表  0-不显示桌子列表


	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "======> playerId = {} , autoChairId = {}", playerId, autoChairId);

	NFGameRoom *pRoom = NFGameRoomMgr::GetInstance()->GetGameRoom(xMsg.game_id(), xMsg.room_id());
	CHECK_EXPR(pRoom, -1, "pRoom == NULL for game_id = {} , room_id = {}", xMsg.game_id() , xMsg.room_id());

    NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
    if (pPlayer)
    {
        if (pPlayer->GetGameId() == xMsg.game_id() && pPlayer->GetRoomId() == xMsg.room_id() && pPlayer->GetDeskId() >= 0 && pPlayer->GetChairId() >= 0)
        {
            proto_game::DeskListRsp deskListRsp;
            deskListRsp.set_result(0);

            proto_game::GameDeskInfo* pDeskInfo = deskListRsp.add_desks();
            pDeskInfo->set_desk_id(pPlayer->GetDeskId()+1);
            pDeskInfo->set_desk_name("deskName");
            pDeskInfo->set_desk_status(0);
            pDeskInfo->set_chair_count(1);

            //自动选一个座位并保留 todo

            proto_game::GameChairInfo* pChairInfo = pDeskInfo->add_chairs();
            pChairInfo->set_chair_id(pPlayer->GetChairId()+1);
            pChairInfo->set_chair_status(0);

            pRoom->SendMsgToWorldServer(proto_game::NF_SC_MSG_DeskListRsp, deskListRsp, playerId);
            return 0;
        }
    }
    else
    {
        pPlayer = NFGameSessionMgr::GetInstance()->CreatePlayer(playerId);
        CHECK_PLAYER_EXPR(playerId, pPlayer, -1, "Create Player Failed, playerId:{}", playerId);

        pPlayer->SetClearFlag(false);
        pPlayer->SetOnline(true);
        pPlayer->SetOfflineTime(0);
        pPlayer->SetLastMsgTime(NFTime::Now().UnixSec());
    }

	pRoom->OnHandleReqDeskListFromClient(playerId, autoChairId);


	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCGameRoomModule::OnHandleReqChairCheckFromClient(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    proto_game::ChairCheckReq xMsg;
	CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

//	uint32_t roomId = xMsg.room_id();
//	uint32_t deskId = xMsg.desk_id();
//	uint32_t chairId = xMsg.chair_id();

	//把桌子坐位号保留 to do


    proto_game::ChairCheckRsp chairCheckRsp;

	chairCheckRsp.set_result(0);
	

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "SendMsgToWorldServer ==> NF_CS_MSG_ChairCheckRsp playerId = {}", playerId);

	NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER,
                                                         proto_game::NF_SC_MSG_ChairCheckRsp, chairCheckRsp, playerId);



	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCGameRoomModule::OnHandleEnterGameReqFromClient(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    proto_game::EnterGameReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

    uint32_t gameId = xMsg.game_id();
    uint32_t roomId = xMsg.room_id();
    int32_t deskId  = (int32_t) xMsg.desk_id()  /*- 1*/; //客户端传来时就是从1开始
    int32_t chairId = (int32_t) xMsg.chair_id() /*- 1*/; //客户端传来时就是从1开始

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "ReqFromClient =====> gameId = {} , roomId = {} , deskId = {} , chairId = {}", gameId, roomId, deskId, chairId);

	//这里传过来的deskId是0，应该是1才对
	//deskId += 1;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!这个要客户端年看看

    CHECK_PLAYER_EXPR(playerId, gameId > 0 && roomId > 0 && deskId > 0 && chairId > 0, -1, "param error:{}", xMsg.DebugString());

	//从客户端发来的roomId/deskId/chairId都是从1开始，这里把deskId/chairId减1，
	//从这里以后，后台的deskId/chairId所有处理都是从0开始，只是在发给客户端时，会加1；
	int32_t deskIndex  = deskId - 1;
	int32_t chairIndex = chairId - 1;

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "ReqFromClient =====> deskId = {} , deskIndex = {} , chairId = {}, chairIndex = {}", deskId, deskIndex, chairId, chairIndex);


    NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
	if (!pPlayer)
	{
		NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "============> CreatePlayer();");
		pPlayer = NFGameSessionMgr::GetInstance()->CreatePlayer(playerId);

		CHECK_PLAYER_EXPR(playerId, pPlayer, -1, "Create Player Failed, playerId:{}", playerId);
	}

	pPlayer->SetClearFlag(false);
	pPlayer->SetProxyId(xMsg.proxy_id());
	pPlayer->SetLogicId(xMsg.logic_id());
	pPlayer->SetOnline(true);
	pPlayer->SetOfflineTime(0);
	pPlayer->SetLastMsgTime(NFTime::Now().UnixSec());

    pPlayer->m_reservedTime = 0;
    pPlayer->m_reservedDeskId = 0;
    pPlayer->m_reservedChairId = 0;

	if (pPlayer->m_gameId > 0 && pPlayer->m_roomId > 0)
	{
		if (pPlayer->m_gameId != gameId || pPlayer->m_roomId != roomId || pPlayer->m_deskId != deskIndex || pPlayer->m_chairId != chairIndex)
		{
            if (pPlayer->m_gameId == gameId && pPlayer->m_roomId == roomId && pPlayer->m_deskId == deskIndex)
            {
                if (pPlayer->m_chairId != chairIndex)
                {
                    chairIndex = pPlayer->m_chairId;
                }
            }
            else
            {
                int iRet = NFGameRoomMgr::GetInstance()->ClearDirtyData(pPlayer->m_playerId);
                if (iRet != 0)
                {
                    proto_game::EnterGameRsp rspMsg;
                    rspMsg.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
                    rspMsg.set_player_id(pPlayer->m_playerId);
                    if (!pPlayer->m_isRobot)
                    {
                        return NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER,
                                                                              proto_game::NF_SC_MSG_EnterGameRsp, rspMsg, pPlayer->m_playerId);
                    }
                    return 0;
                }
            }
		}
	}

    NFGameRoom *pRoom = NFGameRoomMgr::GetInstance()->GetGameRoom(gameId, roomId);
    if (pRoom)
	{
        pPlayer->m_gameId = gameId;
        pPlayer->m_roomId = roomId;
		pRoom->OnHandleEnterGameMsg(pPlayer, deskIndex, chairIndex);
	}
    else
    {
        NFGameRoomMgr::GetInstance()->ClearDirtyData(pPlayer->m_playerId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "gameId:{} roomId:{} not exist, player:{} enter game failed!", gameId, roomId, pPlayer->m_playerId);

        proto_game::EnterGameRsp rspMsg;
        rspMsg.set_result(proto_ff::ERR_CODE_SYSTEM_ERROR);
        rspMsg.set_player_id(pPlayer->m_playerId);
        if (!pPlayer->m_isRobot)
        {
            return NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER,
                                                                  proto_game::NF_SC_MSG_EnterGameRsp, rspMsg, pPlayer->m_playerId);
        }
    }

	//////////////////////////////////////////////////////////////////////////

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCGameRoomModule::OnHandleReComeReqFromClient(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    proto_game::UserRecomeReq xMsg;
	CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

	NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
	CHECK_PLAYER_EXPR(playerId, pPlayer, -1, "Get Player Failed, playerId:{}", playerId);

	NFGameRoom *pRoom = NFGameRoomMgr::GetInstance()->GetGameRoom(pPlayer->m_gameId, pPlayer->m_roomId);
	if (pRoom == NULL)
	{
        proto_game::UserRecomeRsp rspMsg;
		rspMsg.set_result(-1);

		NFIPluginManager::Instance()->FindModule<NFIGameRoomModule>()->SendMsgToClientByPlayerId(playerId,
			pPlayer->m_gameId, proto_game::NF_SC_MSG_UserRecomeRsp, rspMsg);

		return -1;
	}

    pPlayer->SetOnline(true);
    pPlayer->SetOfflineTime(0);
    pPlayer->SetLastMsgTime(NFTime::Now().UnixSec());

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "player:{} Recome Game, gameId:{}, roomId:{}", pPlayer->GetPlayerId(), pPlayer->GetGameId(), pPlayer->GetRoomId());

	pRoom->OnHandleUserReComeMsg(playerId);

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCGameRoomModule::OnHandleExitRoomReqFromClient(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    proto_game::ExitRoomReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

    NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
    if (!pPlayer)
    {
        NFGameRoomMgr::Instance()->ClearDirtyData(playerId);

        proto_game::ExitRoomRsp xMsgRet;
        xMsgRet.set_result(0);
        NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER, proto_game::NF_SC_MSG_ExitRoomRsp, xMsgRet, playerId);

        return 0;
    }

    if (pPlayer->m_gameId > 0 || pPlayer->m_roomId > 0)
    {
        NFGameRoom *pRoom = NFGameRoomMgr::GetInstance()->GetGameRoom(pPlayer->m_gameId, pPlayer->m_roomId);
        if (pRoom == NULL)
        {
            NFGameRoomMgr::Instance()->ClearDirtyData(playerId);

            proto_game::ExitRoomRsp xMsgRet;
            xMsgRet.set_result(0);
            pPlayer->SendMsgToWorld(proto_game::NF_SC_MSG_ExitRoomRsp, xMsgRet, playerId);

            return 0;
        }
    }

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCGameRoomModule::OnHandleExitGameReqFromClient(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    proto_game::ExitGameReq xMsg;
	CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, playerId, msg, nLen, xMsg);

	NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
	CHECK_PLAYER_EXPR(playerId, pPlayer, -1, "Get Player Failed, playerId:{}", playerId);

    if (pPlayer->m_gameId > 0 || pPlayer->m_roomId > 0)
    {
        NFGameRoom *pRoom = NFGameRoomMgr::GetInstance()->GetGameRoom(pPlayer->m_gameId, pPlayer->m_roomId);
        if (pRoom == NULL)
        {
            proto_game::ExitGameRsp rspMsg;
            rspMsg.set_exit_type(0);
            pPlayer->SendMsgToWorld(proto_game::NF_SC_MSG_ExitGameRsp, rspMsg, playerId);

            return 0;
        }

        pRoom->OnHandleExitGameMsg(playerId);


    }

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return 0;
	
}

int NFCGameRoomModule::OnHandleReconnectFromClient(uint64_t unLinkId, uint64_t sendLinkId, uint64_t value2, uint32_t nMsgId, const char *msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::WTGNotifyPlayerReconnectReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, sendLinkId, msg, nLen, xMsg);

    NFGameSession* pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(xMsg.player_id());
    if (!pPlayer)
    {
		return -1;
    }

	//如果是上面重新Create的Player， 成员m_gameId/m_roomId/m_deskId/m_chairId还有用吗？这里也没有赋值!!!
    pPlayer->m_online = true;
    pPlayer->m_proxyId = xMsg.proxy_bus_id();
    pPlayer->m_logicId = xMsg.logic_bus_id();
	pPlayer->SetOfflineTime(0);
	pPlayer->SetLastMsgTime(NFTime::Now().UnixSec());

	NFLogInfo(NF_LOG_SYSTEMLOG, 0, "player:{} reconnect game", pPlayer->m_playerId);

    NFGameRoom *pRoom = NFGameRoomMgr::GetInstance()->GetGameRoom(pPlayer->m_gameId, pPlayer->m_roomId);
    if (pRoom) 
	{
		//pRoom->OnHandleUserReComeMsg(pPlayer->m_playerId);
		pRoom->UserReconDesk(pPlayer->m_playerId, pPlayer->m_deskId);
    }

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCGameRoomModule::OnHandlePlayerDisConnect(uint64_t unLinkId, uint64_t sendLinkId, uint64_t value2, uint32_t nMsgId, const char *msg,
                                                 uint32_t nLen) {
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::NotifyPlayerDisconnect xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, sendLinkId, msg, nLen, xMsg);

    NFGameSession* pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(xMsg.player_id());
    CHECK_PLAYER_EXPR(xMsg.player_id(), pPlayer, -1, "Create Player Failed, playerId:{}", xMsg.player_id());

    pPlayer->m_proxyId = 0;
    pPlayer->m_online = false;
	pPlayer->SetOfflineTime(NFTime::Now().UnixSec());

    NFGameRoom *pRoom = NFGameRoomMgr::GetInstance()->GetGameRoom(pPlayer->m_gameId, pPlayer->m_roomId);
    if (pRoom) {
        pRoom->UserDisconnect(pPlayer->m_playerId, pPlayer->m_deskId);
    }

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCGameRoomModule::OnHandleClearAllGamePlayerNotify(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    NFGameSessionMgr::GetInstance()->ClearAllGamePlayer();

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCGameRoomModule::SendMsgToClientByPlayerId(uint64_t playerId, uint32_t nMsgId,
                                                  const google::protobuf::Message &xData) {
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    NFGameSession* pPlayerInfo = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
    CHECK_EXPR(pPlayerInfo, -1, "playerId:{} not exist, can't find send message!");
    CHECK_EXPR(pPlayerInfo->m_proxyId > 0, -1, "pInfo->GetProxyId() > 0");
    NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_GAME_SERVER, pPlayerInfo->m_proxyId, nMsgId, xData, playerId);

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCGameRoomModule::SendMsgToClientByPlayerId(uint64_t playerId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                                                  const google::protobuf::Message &xData) {
    //NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    NFGameSession *pInfo = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
    CHECK_EXPR(pInfo, -1, "playerId:{} not exist, can't find send message!");
    //CHECK_EXPR(pInfo->m_proxyId > 0, -1, "pInfo->GetProxyId() > 0");

	if (pInfo->m_playerId > 0)
	{
		//NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "=====> pInfo->m_isRobot = {} , playerId = {}", pInfo->m_isRobot?1:0, playerId);
		if (pInfo->m_isRobot)
		{
			NFGameRobotMgr::Instance()->OnHandleServerMsg(playerId, nSubMsgId, xData);
		}
		else
		{
			NFMessageMgr::Instance()->SendMsgToProxyServer(NF_ST_GAME_SERVER, pInfo->m_proxyId, nMainMsgId, nSubMsgId, xData, playerId);
		}
	}

    //NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCGameRoomModule::SendRobotMsgToServer(uint64_t playerId, uint32_t nMsgId, const google::protobuf::Message &xData)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "NFCGameRoomModule::SendRobotMsgToServer() =============> nMsgId = {}", nMsgId);

	std::string strData;
	if (!xData.SerializeToString(&strData))
	{
		NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "NFCGameRoomModule::SendRobotMsgToServer() =============> SerializeToString fail !");

		return -1;
	}

	SendRobotMsgToServer(playerId, nMsgId, (char*)strData.c_str(), strData.length());

	return 0;
}

int NFCGameRoomModule::SendRobotMsgToServer(uint64_t playerId, uint32_t nMsgId, const char *msg, uint32_t nLen)
{
    OnHandleRoomMsg(0, playerId, 0, nMsgId, msg, nLen);

	return 0;
}

NFIGameDeskHandle *NFCGameRoomModule::CreateGameDeskHandle(uint32_t gameId) {
    auto iter = m_createDeskMaps.find(gameId);
    CHECK_EXPR(iter != m_createDeskMaps.end(), NULL, "Create Game Desk Handle Failed, can't find by gameId:{}", gameId);

    NFISubGameModule *pSubGameModule = iter->second;
    CHECK_EXPR(pSubGameModule, NULL,
               "Create Game Desk Handle failed, pSubGameModule == NULL, gameId:{}", gameId);

    return pSubGameModule->CreateGameDeskHandle();
}

const proto_ff_s::GameRoomDesc_s*  NFCGameRoomModule::GetRoomConfig(uint32_t gameId, uint32_t roomId)
{
	auto iter = m_createDeskMaps.find(gameId);
	CHECK_EXPR(iter != m_createDeskMaps.end(), NULL, "GetRoomConfig Failed, can't find by gameId:{}", gameId);

	NFISubGameModule *pSubGameModule = iter->second;
	CHECK_EXPR(pSubGameModule, NULL,
		"GetRoomConfig failed, pSubGameModule == NULL, gameId:{}", gameId);

	return pSubGameModule->GetRoomConfig(roomId);
}

NFIGameRobotHandle* NFCGameRoomModule::CreateGameRobotHandle(uint32_t gameId)
{
	auto iter = m_createDeskMaps.find(gameId);
	CHECK_EXPR(iter != m_createDeskMaps.end(), NULL, "Create Game robot Handle Failed, can't find by gameId:{}", gameId);

	NFISubGameModule *pSubGameModule = iter->second;
	CHECK_EXPR(pSubGameModule, NULL,
		"Create Game Desk Handle failed, pSubGameModule == NULL, gameId:{}", gameId);

	return pSubGameModule->CreateGameRobotHandle();
}

int NFCGameRoomModule::RegisterGameDeskCreator(uint32_t gameId, NFISubGameModule *pGameModule) 
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "RegisterGameDeskCreator() gameId = {}", gameId);

    CHECK_EXPR(pGameModule, -1, "Register GameDesk Creator Failed, pGameModule == NULL, gameId:{}", gameId);
    auto iter = m_createDeskMaps.find(gameId);
    CHECK_EXPR(iter == m_createDeskMaps.end(), -1, "Register GameDesk Creator Failed, gameKind:{} has exist!", gameId);

    m_createDeskMaps[gameId] = pGameModule;
    return 0;
}

void NFCGameRoomModule::ClearGameDeskCreator(NFISubGameModule *pGameModule) {
    for (auto iter = m_createDeskMaps.begin(); iter != m_createDeskMaps.end();) {
        if (iter->second == pGameModule) {
            iter = m_createDeskMaps.erase(iter);
        } else {
            iter++;
        }
    }
}


int NFCGameRoomModule::GameRobotMgrPolling()
{
	//NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "NFCGameRoomModule::GameRobotMgrPolling() ");

	int robotNumPerDesk = 2;
	uint32_t robotShootInterval = 500;
	bool isRobotNeedRealPlayer = true;
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_GAME_SERVER);
	if (pConfig)
	{
		robotNumPerDesk = pConfig->mRobotNumPerDesk;
		robotShootInterval = pConfig->mRobotShootInterval;
		isRobotNeedRealPlayer = pConfig->mIsRobotNeedRealPlayer==1;

		//NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "pConfig->mIsRobotNeedRealPlayer = {} , isRobotNeedRealPlayer = {}", pConfig->mIsRobotNeedRealPlayer, isRobotNeedRealPlayer);
	}

	int iGameId = -1;
	int iRoomId = -1;
	TDeskStationNode deskStation = NFGameRobotMgr::Instance()->GetChairInfoForRobot(iGameId, iRoomId, robotNumPerDesk, isRobotNeedRealPlayer); //Test for 1
	
	//test for desk 1
	if (deskStation.m_nDeskIndex!=-1/*deskStation.m_nDeskIndex==0*/ && deskStation.m_nDeskStation!=-1)
	{
		NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "GetChairInfoForRobot ==> m_nDeskIndex = {} , m_nDeskStation = {}", deskStation.m_nDeskIndex, deskStation.m_nDeskStation);
		
		NFGameRobot* pRobot = NFGameRobotMgr::Instance()->GetIdleRobot();
		if (pRobot == NULL)
		{
			uint64_t robotPlayerId = NFRobotMgr::Instance()->GetFreeRobot(iGameId, iRoomId);
			if (robotPlayerId <= 0)
            {
                NFRobotMgr::Instance()->CreateRobot(iGameId, iRoomId);
                return 0;
            }
			else
            {
                proto_ff_s::RobotCommonData_s* pRobotData = NFRobotMgr::Instance()->GetRobotData(iGameId, iRoomId, robotPlayerId);
                CHECK_EXPR(pRobotData, -1, "NFRobotMgr::Instance()->GetRobotData Failed,  robotPlayerId: {}", robotPlayerId);

                pRobot = NFGameRobotMgr::Instance()->CreateRobot(robotPlayerId);
                CHECK_EXPR(pRobot, -1, "CreateRobot Failed ,  robotPlayerId: {}", robotPlayerId);

                pRobot->InitDetail(pRobotData);
            }
		}

		pRobot->Init(iGameId, iRoomId, deskStation.m_nDeskIndex, deskStation.m_nDeskStation, robotShootInterval);
	}
	else
	{
		//NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "GetChairInfoForRobot ==> Not find valid chair for robot !");
	}
	
	//////////////////////////////////////////////////////////////////////////
	//没有真人，机器人也不退出
	if (!isRobotNeedRealPlayer)
	{
		return 0;
	}
	
	//////////////////////////////////////////////////////////////////////////
	//delete dead robots
	std::vector<uint64_t> vecDeadRobots;
	NFGameRobotMgr::Instance()->GetDeadRobots(vecDeadRobots);

	NFLogTraceIf(vecDeadRobots.size() > 0, NF_LOG_GAME_SERVER_PLUGIN, 0, "NFCGameRoomModule::GameRobotMgrPolling() Find deadrobot count = {}", vecDeadRobots.size());

	std::vector<uint64_t>::iterator iter = vecDeadRobots.begin();
	for (; iter!=vecDeadRobots.end(); iter++)
	{
		uint64_t playerId = *iter;

		NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "NFCGameRoomModule::GameRobotMgrPolling() m_playerId = {}", playerId);

		NFGameRobot* pRobot = NFGameRobotMgr::Instance()->GetRobot(playerId);
		if (pRobot != NULL)
		{
			NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "NFCGameRoomModule::GameRobotMgrPolling() ExitGame() 00000 ! = {}", playerId);

			pRobot->ExitGame();
			pRobot->SetRobotIdle();

			//NFGameRobotMgr::Instance()->DeleteRobot(pRobot);
		}
		else
		{
			NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "NFCGameRoomModule::GameRobotMgrPolling() pRobot == NULL !");

			pRobot = NFGameRobotMgr::Instance()->GetRobot1(playerId);
			if (pRobot != NULL)
			{
				NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "NFCGameRoomModule::GameRobotMgrPolling() ExitGame() 11111 ! = {}", playerId);

				pRobot->ExitGame();
				pRobot->SetRobotIdle();
			}
		}
	}
	
	return 0;
}

int NFCGameRoomModule::OnHandleSetUserManagerInfo(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::Proto_SnsTGame_SetUserManagerInfo xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NFGameSession* pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(xMsg.player_id());
    CHECK_PLAYER_EXPR(xMsg.player_id(), pPlayer, -1, "Create Player Failed, playerId:{}", xMsg.player_id());

    proto_ff_s::tbGameUserManagerData_s desc;
    proto_ff_s::tbGameUserManagerData_s::read_from_pbmsg(xMsg.user_manager_data(), desc);
    NFGameRoomMgr::GetInstance()->SetUserManagerInfo(pPlayer->m_gameId, pPlayer->m_roomId, pPlayer->m_deskId, xMsg.player_id(), &desc);

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCGameRoomModule::OnHandleSetGmCtrlGiveData(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::Proto_SnsTGame_SetGmCtrlGiveData xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NFGameSession* pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(xMsg.player_id());
    CHECK_PLAYER_EXPR(xMsg.player_id(), pPlayer, -1, "Create Player Failed, playerId:{}", xMsg.player_id());

    proto_ff_s::tbGmCtrlGiveCtrlData_s desc;
    proto_ff_s::tbGmCtrlGiveCtrlData_s::read_from_pbmsg(xMsg.gm_ctrl_data(), desc);
    NFGameRoomMgr::GetInstance()->SetGmCtrlGiveData(pPlayer->m_gameId, pPlayer->m_roomId, pPlayer->m_deskId, xMsg.player_id(), &desc);

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCGameRoomModule::OnHandleUpdateUserInfo(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::Proto_UpdateCoinBalanceNotify xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NFGameSession* pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(xMsg.player_detail().player_id());
    CHECK_PLAYER_EXPR(xMsg.player_detail().player_id(), pPlayer, -1, "Create Player Failed, playerId:{}", xMsg.player_detail().player_id());

    proto_ff_s::GamePlayerDetailData_s playerDetail;
    proto_ff_s::GamePlayerDetailData_s::read_from_pbmsg(xMsg.player_detail(), playerDetail);
    NFGameRoomMgr::GetInstance()->UpdateUserInfo(pPlayer->m_gameId, pPlayer->m_roomId, pPlayer->m_deskId, xMsg.player_detail().player_id(), &playerDetail);

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}
