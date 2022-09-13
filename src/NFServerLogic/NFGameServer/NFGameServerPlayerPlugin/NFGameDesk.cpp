// -------------------------------------------------------------------------
//    @FileName         :    NFGameDesk.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameDesk.cpp
//
// -------------------------------------------------------------------------

#include <NFComm/NFMessageDefine/proto_cs.pb.h>
#include <NFServer/NFCommHead/NFCommLogicHead.h>
#include "NFComm/NFMessageDefine/proto_common.pb.h"
#include "NFGameDesk.h"

#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFServer/NFCommHead/NFIGameRoomModule.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFGameSession.h"
#include "NFGameRoom.h"
#include "NFTransQueryCoinBalance.h"
#include "NFGameSessionMgr.h"
#include "NFGameRoomMgr.h"
#include "NFGameRobotMgr.h"
#include "NFRobotMgr.h"
#include "NFPaoMaDengMgr.h"
#include "NFGameLogHandle.h"
#include "proto_error_code.pb.h"
#include "NFGameLogHandle.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGameDesk, EOT_GAME_DESK_ID, NFShmObj)
NFGameDesk::NFGameDesk()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFGameDesk::~NFGameDesk()
{
    NFShmMgr::Instance()->DestroyObj(m_deskHandle);
}

int NFGameDesk::CreateInit()
{
	m_deskHandle = NULL;
    m_roomHandle = NULL;
    m_deskId = INVALID_ID;
    m_gameId = 0;
    m_roomId = 0;
    m_chairCount = 0;
    m_maxUserNum = 0;

    m_arrDeskStationId.SetSize(m_chairCount);

    m_bTableLocked = false; //锁定标志
    m_bGameStarted = false; //开始标志
    m_bGameStatus = GAMES_FREE;                        //游戏状态
    m_dwTimeStart = 0;                        //开始时间
    return 0;
}

int NFGameDesk::ResumeInit()
{
    return 0;
}

int NFGameDesk::Init(uint32_t gameId, uint32_t roomId, int32_t deskIndex, uint32_t sitNum,
                     uint32_t maxUserNum, NFGameRoom* pRoomHandle) 
{
    m_roomHandle = pRoomHandle;
    m_gameId = gameId;
    m_roomId = roomId;
    m_deskId = deskIndex;//index first is 0
    m_chairCount = sitNum;
    m_maxUserNum = maxUserNum;
    m_arrDeskStationId.SetSize(m_chairCount);
    m_bGameStarted = true;
    m_bGameStatus = GAMES_PLAYING;
    m_dwTimeStart = NFTime::Now().UnixSec();
    m_deskHandle = NFIPluginManager::Instance()->FindModule<NFIGameRoomModule>()->CreateGameDeskHandle(gameId);
    CHECK_EXPR(m_deskHandle, -1, "Create Game Desk Handle Failed, gameId:{}, roomId:{}, deskIndex:{}", gameId, roomId, deskIndex);
    m_deskHandle->Init(this, m_gameId, m_roomId, m_deskId, m_chairCount, m_maxUserNum);
    return 0;
}

int NFGameDesk::OnHandleClientMsg(uint64_t playerId, uint16_t nMsgId, const char *msg, uint32_t nLen) {
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    if (m_deskHandle) {
        m_deskHandle->OnHandleClientMsg(playerId, nMsgId, msg, nLen);
    }
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFGameDesk::OnHandleServerMsg(uint64_t playerId, uint32_t nMsgId, const char *msg, uint32_t nLen) {
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    if (m_deskHandle) {
        m_deskHandle->OnHandleServerMsg(playerId, nMsgId, msg, nLen);
    }
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

bool NFGameDesk::AddMessageCallBack(uint16_t subMsgId) {
	return NFIPluginManager::Instance()->FindModule<NFIGameRoomModule>()->AddMessageCallBack(m_gameId, subMsgId);
}

int
NFGameDesk::SendMsgToClient(uint64_t playerId, uint16_t nSubMsgId, const google::protobuf::Message &xData) {
    return NFIPluginManager::Instance()->FindModule<NFIGameRoomModule>()->SendMsgToClientByPlayerId(playerId, m_gameId,
                                                                                                    nSubMsgId, xData);
}

int NFGameDesk::BroadCastMsgToDesk(uint16_t nSubMsgId, const google::protobuf::Message &xData, int32_t chairId)
{
	for (int i = 0; i < m_arrDeskStationId.GetSize(); i++) {
		if (m_arrDeskStationId[i].m_playerId == 0 || i == chairId) {
			continue;
		}

		if (m_arrDeskStationId[i].m_isRobot == true) {
			continue;
		}

		if (m_arrDeskStationId[i].m_onlineFlags <= 0) {
			continue;
		}

		SendMsgToClient(m_arrDeskStationId[i].m_playerId, nSubMsgId, xData);
	}
	return 0;
}

int NFGameDesk::SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
	return NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER, nMsgId,
		xData);
}

int NFGameDesk::SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId)
{
    NFGameSession *pInfo = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
    CHECK_EXPR(pInfo, -1, "playerId:{} not exist, can't find send message!");
    if (pInfo->m_isRobot) return 0;

    CHECK_EXPR(pInfo->m_logicId > 0, -1, "pInfo->m_logicId > 0");

	return NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_GAME_SERVER, pInfo->m_logicId, nMsgId,
		xData, playerId);
}

int NFGameDesk::SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData)
{
	return NFMessageMgr::Instance()->SendMsgToSnsServer(NF_ST_GAME_SERVER, nMsgId,
		xData);
}

int NFGameDesk::ModifyGameMoney(uint64_t playerId, uint32_t changeType, uint64_t moneyChange)
{
	return NFGameRoomMgr::GetInstance()->ModifyGameMoney(m_gameId, m_roomId, m_deskId, playerId, changeType, moneyChange);
}

int NFGameDesk::PaoMaDengNotify(const std::string& playerName, uint64_t winJetton)
{
    return m_roomHandle->PaoMaDengNotify(playerName, winJetton);
}

int NFGameDesk::ReserveSeat(uint64_t playerId, int iDeskStation) {
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(iDeskStation >= 0 && iDeskStation < (int) m_arrDeskStationId.GetSize(), -1,
               "CGameDesk::ReserveSeat()  iDeskStation:{} is invalid!!! PlayerId:{}", iDeskStation, playerId);

    uint32_t ulNowTime = NFTime::Now().UnixSec();

    m_arrDeskStationId[iDeskStation].m_reservedPlayerId = playerId;
    m_arrDeskStationId[iDeskStation].m_reservedTime = ulNowTime;

    NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, playerId,
              "CGameDesk::ReserveSeat()  playerId:{} reserved the seat: m_nRoomID:{} m_nDeskIndex:{} iDeskStation:{}",
              playerId, m_roomId, m_deskId, iDeskStation);

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFGameDesk::Looking4SeatBySequence(uint64_t playerId, int &iDeskStation)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    //计算出当前座位已坐总人数(包括机器人)
    int i = 0;
    int iTotalCount = 0;
    for (i = 0; i < (int)m_chairCount && i < m_arrDeskStationId.GetSize(); i++) {
        //统计所有人
        if (m_arrDeskStationId[i].m_playerId > 0) {
            iTotalCount++;
        }
    }

    //计算剩余位置数
    int iLeftCount = m_chairCount - iTotalCount;
    if (iLeftCount <= 0) {
        //没有位置了，直接返回false
        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, 0,
                   "CGameDesk::Looking4SeatInRobotsForBrand This RoomID:{} DeskID:{} has not any seat for player:{}!",
                   m_roomId, m_deskId, playerId);
        return -1;
    }

    uint32_t ulNowTime = NFTime::Now().UnixSec();

    //如果该桌子有真人，则顺序找一个位置坐下
    int bResult = -1;
    int iRandDeskStation = NFRandInt(1, (int) iLeftCount);
    int iValidSite = 1;
    for (i = 0; i < (int)m_chairCount && i < m_arrDeskStationId.GetSize(); i++) {
        //没有人在坐，则认为该位置时可用的
        if ((m_arrDeskStationId[i].m_playerId <= 0) && ((ulNowTime - m_arrDeskStationId[i].m_reservedTime) > 15 || m_arrDeskStationId[i].m_reservedPlayerId == playerId)) {
            //先得到对应新的位置
            iDeskStation = i;
            bResult = 0;
            if (iValidSite == iRandDeskStation)
            {
                break;
            }
            iValidSite++;
        }
    }

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return bResult;
}

std::vector<int> NFGameDesk::GetPlayerInfo(int& realPlayerCount, int& robotCount)
{
	std::vector<int> vec;

	int iTotalCount = 0;
	realPlayerCount = 0;
	robotCount = 0;
	for (int i = 0; i < m_arrDeskStationId.GetSize(); i++) {
		//统计所有人
		if (m_arrDeskStationId[i].m_playerId > 0) {
			iTotalCount++;
		} else {
			vec.push_back(i);
		}

		//统计机器人
		if (m_arrDeskStationId[i].m_isRobot == true) {
			robotCount++;
		}
	}

	realPlayerCount = iTotalCount - robotCount;

	//NFLogTraceIf(iTotalCount > 0 || robotCount > 0, NF_LOG_GAME_SERVER_PLUGIN, 0, "NFGameDesk::GetPlayerInfo() iTotalCount = {} , robotCount = {}", iTotalCount, robotCount);

	return vec;
}

std::vector<uint64_t> NFGameDesk::GetRobots(int& realPlayerCount)
{
	std::vector<uint64_t> vec;

	int iTotalCount = 0;
	realPlayerCount = 0;
	int robotCount = 0;
	for (int i = 0; i < m_arrDeskStationId.GetSize(); i++) 
	{
		//统计所有人
		if (m_arrDeskStationId[i].m_playerId > 0) 
		{
			iTotalCount++;

			//统计机器人
			if (m_arrDeskStationId[i].m_isRobot == true) 
			{
				robotCount++;
				vec.push_back(m_arrDeskStationId[i].m_playerId);
			}
		}
	}

	realPlayerCount = iTotalCount - robotCount;

	//NFLogTraceIf(iTotalCount > 0 || robotCount > 0, NF_LOG_GAME_SERVER_PLUGIN, 0, "NFGameDesk::GetPlayerInfo() iTotalCount = {} , robotCount = {}", iTotalCount, robotCount);

	return vec;
}

int NFGameDesk::LookingSuitSeatForPlayer(uint64_t playerId, int &iDeskStation) {
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    //计算出当前座位已坐总人数(包括机器人)
    int i = 0;
    int iTotalCount = 0;
    int iRobotCount = 0;
    for (i = 0; i < m_arrDeskStationId.GetSize(); i++) {
        //统计所有人
        if (m_arrDeskStationId[i].m_playerId > 0) {
            iTotalCount++;
        }

        //统计机器人
        if (m_arrDeskStationId[i].m_isRobot == true) {
            iRobotCount++;
        }
    }

    //计算剩余位置数
    int iLeftCount = m_arrDeskStationId.GetSize() - iTotalCount;
    if (iLeftCount <= 0) {
        //没有位置了，直接返回false
        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, 0,
                   "CGameDesk::Looking4SeatInRobotsForBrand This RoomID:{} DeskID:{} has not any seat for player:{}!",
                   m_roomId, m_deskId, playerId);
        return -1;
    }

    //如果该桌子坐的没有机器人,直接返回false
    //if (iRobotCount <= 0) {
    //    NFLogError(NF_LOG_GAME_SERVER_PLUGIN, 0,
    //               "CGameDesk::Looking4SeatInRobotsForBrand This desk RoomID:{} DeskID:{} has no robots! persons:{} MaxUserNum:{}, so ignore it!",
    //               m_roomId, m_deskId, iTotalCount, m_maxUserNum);
    //    //return -1;
    //}

    uint32_t ulNowTime = NFTime::Now().UnixSec();

    //如果该桌子有真人，则顺序找一个位置坐下
    for (i = 0; i < m_arrDeskStationId.GetSize(); i++) {
        //没有人在坐，则认为该位置时可用的
        if ((m_arrDeskStationId[i].m_playerId <= 0) && ((ulNowTime - m_arrDeskStationId[i].m_reservedTime) > 15 || m_arrDeskStationId[i].m_reservedPlayerId == playerId)) {
            //先得到对应新的位置
            iDeskStation = i;
            NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, playerId,
                       "CGameDesk::LookingSuitSeatForPlayer() Found a new seat RoomID:{} DeskID:{} Station:{} for playerId:{} MaxUserNum:{}. ",
                       m_roomId, m_deskId, iDeskStation, playerId, m_maxUserNum);
            return 0;
        }
    }

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return -1;
}

int NFGameDesk::LookingSuitSeatForRobot(uint64_t playerId, int &iDeskStation, int maxRobotPerDesk, bool bIsNeedRealPlayer /*= true*/)
{
	int realPlayerCount = 0;
	int robotCount = 0;
	std::vector<int> vecValidDeskStation =  GetPlayerInfo(realPlayerCount, robotCount);

	//NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "LookingSuitSeatForRobot() ==> robotCount = {} , realPlayerCount = {}", robotCount, realPlayerCount);

	if (vecValidDeskStation.size()>0 
		&& robotCount< maxRobotPerDesk 
		&& ((bIsNeedRealPlayer&&(realPlayerCount > 0))||(bIsNeedRealPlayer==false)))
	{
		int randIdx = NFRandInt(0, (int)vecValidDeskStation.size());

		iDeskStation = vecValidDeskStation[randIdx];

		return 0;
	}
	else
	{
		return -1;
	}
}

void NFGameDesk::GetDeadRobots(std::vector<uint64_t>& vec)
{
	int realPlayerCount = 0;
	std::vector<uint64_t> vecRobots = GetRobots(realPlayerCount);

	if (vecRobots.size() > 0 && realPlayerCount == 0)//dead robot
	{
		std::vector<uint64_t>::iterator iter = vecRobots.begin();
		for (; iter!=vecRobots.end(); iter++)
		{
			vec.push_back(*iter);
		}
	}
}

bool NFGameDesk::IsPlayGame(int iChairIndex) {
    if (!m_deskHandle) 
	{
        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, 0, "NFGameDesk::IsUserPlaying Error, m_deskHandle == NULL, iChairIndex:{}", iChairIndex);
        return false;
    }
    return m_deskHandle->IsPlayGame(iChairIndex);
}

bool NFGameDesk::IsPlayGameCanLeave(int iChairIndex)
{
	if (!m_deskHandle)
	{
		NFLogError(NF_LOG_GAME_SERVER_PLUGIN, 0, "NFGameDesk::IsPlayGameCanLeave Error, m_deskHandle == NULL, iChairIndex:{}", iChairIndex);
		return false;
	}
	return m_deskHandle->IsPlayGameCanLeave(iChairIndex);
}

int NFGameDesk::ClearDirtyData(uint64_t playerId) {
    if (!m_deskHandle) {
        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, playerId, "NFGameDesk::ClearDirtyData Error, m_deskHandle == NULL");
        return -1;
    }

    for (int i = 0; i < (int) m_arrDeskStationId.GetSize(); i++) {
        NFGameDeskStation *pDeskStation = &m_arrDeskStationId[i];
        if (pDeskStation->m_playerId == playerId)
        {
            if (m_deskHandle->IsPlayGame(i) && !m_deskHandle->IsPlayGameCanLeave(i))
            {
                pDeskStation->m_onlineFlags = 0;
                return -1;
            }

            int iRet = m_deskHandle->UserLeftDesk(playerId, pDeskStation->m_chairId, pDeskStation->m_playerDetail);
            if (iRet != 0)
            {
                NFLogError(NF_LOG_GAME_SERVER_PLUGIN, playerId, "UserLeftDesk Failed!");
                return iRet;
            }

			NotifyServerPlayerExitGame(playerId, pDeskStation->m_chairId);

			pDeskStation->ClearData();

            NFGameSession* pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
            if (pPlayer)
            {
                pPlayer->ClearGameData();
            }
        }
    }

    return 0;
}

int NFGameDesk::UserReCome(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) {
    if (!m_deskHandle) {
        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, playerId, "NFGameDesk::UserReCome Error, m_deskHandle == NULL");
        return -1;
    }

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "22222222222222222222222+> iDeskStation = {} , playerId = {}", iDeskStation, playerId);


    return m_deskHandle->UserReCome(playerId, iDeskStation, playerDetail);
}

int NFGameDesk::UserSitDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) {
    if (!m_deskHandle) {
        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, playerId, "NFGameDesk::UserSitDesk Error, m_deskHandle == NULL");
        return -1;
    }
    return m_deskHandle->UserSitDesk(playerId, iDeskStation, playerDetail);
}

int NFGameDesk::UserLeftDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) {
    if (!m_deskHandle) {
        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, playerId, "NFGameDesk::UserLeftDesk Error, m_deskHandle == NULL");
        return -1;
    }

    m_arrDeskStationId[iDeskStation].SaveAchievementData(true);
    m_arrDeskStationId[iDeskStation].WriteBackUserManagerData(true);

	int iRet = m_deskHandle->UserLeftDesk(playerId, iDeskStation, playerDetail);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, playerId, "UserLeftDesk Failed!");
        return iRet;
    }

	NotifyServerPlayerExitGame(playerId, iDeskStation);
	m_arrDeskStationId[iDeskStation].ClearData();

	ClearDirtyData(playerId);

    NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
    if (pPlayer) {
        pPlayer->ClearGameData();
    }

	return 0;
}

int NFGameDesk::UserExitGame(uint64_t playerId)
{
	NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
	CHECK_EXPR(pDeskStation, -1, "pDeskStation == NULL, playerId:{}", playerId);
	UserLeftDesk(playerId, pDeskStation->m_chairId, pDeskStation->m_playerDetail);
    return 0;
}

int NFGameDesk::UserReconDesk(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) {
    if (!m_deskHandle) {
        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, playerId, "NFGameDesk::UserReconDesk Error, m_deskHandle == NULL");
        return -1;
    }
    return m_deskHandle->UserReconDesk(playerId, iDeskStation, playerDetail);
}

int NFGameDesk::UserAgreeGame(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail) {
    if (!m_deskHandle) {
        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, playerId, "NFGameDesk::UserAgreeGame Error, m_deskHandle == NULL");
        return -1;
    }
    return m_deskHandle->UserAgreeGame(playerId, iDeskStation, playerDetail);
}

int NFGameDesk::UserDisconnect(uint64_t playerId, int iDeskStation, proto_ff_s::GamePlayerDetailData_s& playerDetail)
{
    if (!m_deskHandle) {
        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, playerId, "NFGameDesk::UserAgreeGame Error, m_deskHandle == NULL");
        return -1;
    }

    m_arrDeskStationId[iDeskStation].SaveAchievementData(true);
    m_arrDeskStationId[iDeskStation].WriteBackUserManagerData(true);

	m_deskHandle->UserDisconnect(playerId, iDeskStation, playerDetail);

	return 0;
}

int NFGameDesk::ClearJiangChi()
{
    if (!m_deskHandle) {
        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, 0, "NFGameDesk::ClearJiangChi Error, m_deskHandle == NULL");
        return -1;
    }

    return m_deskHandle->ClearJiangChi();
}

int NFGameDesk::ChangeJiangChi(int64_t jiangchi)
{
    if (!m_deskHandle) {
        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, 0, "NFGameDesk::ChangeJiangChi Error, m_deskHandle == NULL");
        return -1;
    }

    return m_deskHandle->ChangeJiangChi(jiangchi);
}


int NFGameDesk::OnHandleEnterGameMsg(NFGameSession *pPlayer, int chairId)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
	CHECK_EXPR(pPlayer, -1, "pPlayer == NULL");
	CHECK_EXPR(m_deskHandle, -1, "param error, m_deskHandle == NULL");
	

	NFTransQueryCoinBalance* pTrans = dynamic_cast<NFTransQueryCoinBalance *>(NFShmMgr::Instance()->CreateTrans(EOT_TRANS_QUERY_COIN_BALANCE_BASE));
	CHECK_EXPR(pTrans, -1, "pTrans createobj failed!");

	pTrans->Init(pPlayer, proto_game::NF_CS_MSG_EnterGameReq);
	pTrans->ProQueryCoinBalanceReq(m_gameId, m_roomId, m_deskId, chairId);

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "chairId = {} , m_playerId = {}", chairId , pPlayer->m_playerId);

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

int NFGameDesk::LoginDesk(NFGameSession *pPlayer, int chairIndex, proto_ff_s::GamePlayerDetailData_s& playerDetail)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(pPlayer, proto_ff::ERR_CODE_SYSTEM_ERROR, "pPlayer == NULL");
    CHECK_EXPR(m_deskHandle, proto_ff::ERR_CODE_SYSTEM_ERROR, "param error, m_deskHandle == NULL");

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "chairIndex = {} , m_playerId = {}", chairIndex, pPlayer->m_playerId);

    if (chairIndex < 0 || chairIndex >= (int) m_arrDeskStationId.GetSize()) 
	{
        NFGameRoomMgr::Instance()->ClearDirtyData(pPlayer->m_playerId);
        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, 0, "param error, chairIndex:{}", chairIndex);
        return proto_ff::ERR_CODE_CHAIR_NOT_RIGHT;
    }

	NFGameDeskStation* pDeskStation = GetDeskStation(chairIndex);
	CHECK_EXPR(pDeskStation, proto_ff::ERR_CODE_SYSTEM_ERROR, "pDeskStation == NULL");

    //判断位置上是否有人,如果是自己，则放行，位置被自己占住，说明自己曾经异常退出，要么需要重新入座，要么先清理数据
    if (pDeskStation->m_playerId > 0 && pDeskStation->m_playerId != pPlayer->m_playerId)
	{
        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, 0,
                   "Error:CGameDesk::LoginDesk() chairIndex:{} is using! Request sit down's playerID:{}, "
                   "Aleady sit down's playerId:{}. OprInfo: m_nRoomID:{} DeskId:{}.",
			chairIndex, pPlayer->m_playerId, pDeskStation->m_playerId, m_roomId, m_deskId);

        NFGameRoomMgr::Instance()->ClearDirtyData(pPlayer->m_playerId);//如果是别人占了这个位子，就不处理；而不应该清除；

        return proto_ff::ERR_CODE_CHAIR_HAS_OTHER_PLAYTER;
    }

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "==============> playerDetail.cur_money = {}", playerDetail.cur_money);

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "111111111111111111+> chairIndex = {} , m_playerId = {}", chairIndex, pPlayer->m_playerId);

	playerDetail.chair_id = chairIndex;
    int iSitResult = -1;
    if (pPlayer->IsInGame() && IsPlayGame(chairIndex) == true)
	{
        iSitResult = UserReCome(pPlayer->m_playerId, chairIndex, playerDetail);
    }
	else 
	{
        iSitResult = UserSitDesk(pPlayer->m_playerId, chairIndex, playerDetail);
    }

    if (iSitResult != 0) //如果没进入成功，则清理
	{
		int iRet = UserLeftDesk(pPlayer->m_playerId, chairIndex, playerDetail);
		if (iRet != 0) 
		{
			NFLogError(NF_LOG_GAME_SERVER_PLUGIN, 0, "playerId:{} Left Desk Failed!", pPlayer->m_playerId);
		}
		////broacast desk////////////////////

		pPlayer->m_gameId = 0;
		pPlayer->m_roomId = 0;
		pPlayer->m_deskId = INVALID_ID;
		pPlayer->m_chairId = INVALID_ID;

        proto_game::EnterGameRsp rspMsg;
		rspMsg.set_result(-1);
        rspMsg.set_player_id(pPlayer->m_playerId);

        if (pPlayer->m_isRobot == false)
        {
            SendMsgToWorldServer(proto_game::NF_SC_MSG_EnterGameRsp, rspMsg);
        }

		return iSitResult;
	}

	pDeskStation->m_isRobot = pPlayer->m_isRobot;
	pDeskStation->m_playerId = pPlayer->m_playerId;
	pDeskStation->m_onlineFlags = 1;
	pDeskStation->m_reservedPlayerId = 0;
	pDeskStation->m_reservedTime = 0;
	pDeskStation->m_chairId = chairIndex;
    pDeskStation->m_iCurUserMoney = playerDetail.cur_money;
    pDeskStation->m_iEnterUserMoney = playerDetail.cur_money;

	pDeskStation->m_playerDetail.player_id = playerDetail.player_id;
	pDeskStation->m_playerDetail.cur_money = playerDetail.cur_money;
	pDeskStation->m_playerDetail.vip_level = playerDetail.vip_level;
	pDeskStation->m_playerDetail.sex = playerDetail.sex;
	pDeskStation->m_playerDetail.chair_id = chairIndex;
	pDeskStation->m_playerDetail.nick_name = playerDetail.nick_name;
	pDeskStation->m_playerDetail.face = playerDetail.face;

	pDeskStation->m_wealthData.player_id = pPlayer->m_playerId;

	pPlayer->m_gameId = m_gameId;
	pPlayer->m_roomId = m_roomId;
	pPlayer->m_deskId = m_deskId;
	pPlayer->m_chairId = chairIndex;

	if (m_deskHandle) 
	{
        if (pPlayer->m_isRobot == false)
        {
            proto_game::EnterGameRsp rspMsg;
            rspMsg.set_result(0);
            rspMsg.set_chair_count(m_chairCount);
            rspMsg.set_my_chair_id(chairIndex+1);
            rspMsg.set_game_id(m_gameId);
            rspMsg.set_room_id(m_roomId);
            rspMsg.set_player_id(pPlayer->m_playerId);
            SendMsgToWorldServer(proto_game::NF_SC_MSG_EnterGameRsp, rspMsg);
        }

		NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "================================> NF_SC_MSG_EnterGameRsp");
		NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "==> m_gameId = {} , m_roomId = {} , m_chairCount = {} , chairId = {}, m_playerId = {}", m_gameId, m_roomId, m_chairCount, chairIndex, pPlayer->m_playerId);
	}

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");

	return 0;
}

int NFGameDesk::SetUserManagerInfo(uint64_t playerId, const proto_ff_s::tbGameUserManagerData_s* pUserManagerData)
{
    CHECK_NULL(pUserManagerData);

    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, proto_ff::ERR_CODE_SYSTEM_ERROR, "pDeskStation == NULL");

    return pDeskStation->SetUserManagerData(pUserManagerData);
}

int NFGameDesk::SetGmCtrlGiveData(uint64_t playerId, const proto_ff_s::tbGmCtrlGiveCtrlData_s* pGmCtrlGiveDta)
{
    CHECK_NULL(pGmCtrlGiveDta);

    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, proto_ff::ERR_CODE_SYSTEM_ERROR, "pDeskStation == NULL");

    return pDeskStation->SetGmCtrlGiveData(pGmCtrlGiveDta);
}

int NFGameDesk::ProcUserSettlement(NFGameDeskStation* pDeskStation)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    CHECK_NULL(pDeskStation);

    int64_t moneyChange = (int64_t)pDeskStation->m_iCurUserMoney - (int64_t)pDeskStation->m_iEnterUserMoney;
    if (moneyChange == 0)
    {
        return 0;
    }

    uint32_t changeType = proto_ff::E_CHAGEMONEY_GAME_ADD;
    if (moneyChange < 0)
    {
        changeType = proto_ff::E_CHAGEMONEY_GAME_REMOVE;
        moneyChange = -moneyChange;

        NFLogInfo(NF_LOG_SYSTEMLOG, pDeskStation->m_playerId, "ProcUserSettlement playerId:{} reduce money:{} curMoney:{} enterMoney:{} gameId:{} roomId:{} deskId:{}",
                  pDeskStation->m_playerId, moneyChange, pDeskStation->m_iCurUserMoney, pDeskStation->m_iEnterUserMoney, m_gameId, m_roomId, m_deskId);
    }
    else
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, pDeskStation->m_playerId, "ProcUserSettlement playerId:{} add money:{} curMoney:{} enterMoney:{} gameId:{} roomId:{} deskId:{}",
                  pDeskStation->m_playerId, moneyChange, pDeskStation->m_iCurUserMoney, pDeskStation->m_iEnterUserMoney, m_gameId, m_roomId, m_deskId);
    }

    UpdateUserMoney(pDeskStation->m_playerId, changeType, moneyChange);

    pDeskStation->m_iEnterUserMoney = pDeskStation->m_iCurUserMoney;

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFGameDesk::UpdateUserInfo(uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s* pUserDetailInfo)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    if (!m_deskHandle) {
        NFLogError(NF_LOG_GAME_SERVER_PLUGIN, playerId, "NFGameDesk::SetUserManagerInfo Error, m_deskHandle == NULL");
        return -1;
    }

    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, proto_ff::ERR_CODE_SYSTEM_ERROR, "pDeskStation == NULL");

    int64_t moneyChange = pUserDetailInfo->cur_money - pDeskStation->m_iEnterUserMoney;
    if (0 != moneyChange)
    {
        pDeskStation->m_iEnterUserMoney += moneyChange;
        pDeskStation->m_iCurUserMoney   += moneyChange;

        ProcUserSettlement(pDeskStation);
    }

    pDeskStation->m_playerDetail.player_id = playerId;
    pDeskStation->m_playerDetail.cur_money = pUserDetailInfo->cur_money;
    pDeskStation->m_playerDetail.vip_level = pUserDetailInfo->vip_level;
    pDeskStation->m_playerDetail.sex = pUserDetailInfo->sex;
    pDeskStation->m_playerDetail.chair_id = pDeskStation->m_chairId;
    pDeskStation->m_playerDetail.nick_name = pUserDetailInfo->nick_name;
    pDeskStation->m_playerDetail.face = pUserDetailInfo->face;

    pDeskStation->m_wealthData.player_id = playerId;

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return m_deskHandle->UpdateUserInfo(playerId, pUserDetailInfo);
}



int NFGameDesk::UpdateUserMoney(uint64_t playerId, uint32_t changeType, uint64_t moneyChange)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
	CHECK_EXPR(moneyChange > 0, -1, "moneyChange error:{}", moneyChange);

    const proto_ff_s::GameRoomDesc_s* roomConfig = NFIPluginManager::Instance()->FindModule<NFIGameRoomModule>()->GetRoomConfig(m_gameId, m_roomId);
    if (!roomConfig)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFGameRoomDesc: find room failed! mGameId = {} , mRoomId = {}", m_gameId, m_roomId);
        return proto_ff::ERR_CODE_SYSTEM_ERROR;
    }

    if (roomConfig->is_exp_scene > 0)
    {
        return 0;
    }

	NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
	CHECK_EXPR(pDeskStation, -1, "UpdateUserMoney Error, can't find player:{} station, changeType:{} moneyChange:{}", playerId, changeType, moneyChange);

	uint32_t accountType = 0;
	uint32_t optType = proto_ff::E_USER_JETTON_OPER_TYPE_GAME_BALANCED_WIN;
	uint32_t optReason = 0;

	//根据加币、减币进行操作
	if (changeType == proto_ff::E_CHAGEMONEY_GAME_ADD)
	{
		pDeskStation->m_playerDetail.cur_money += moneyChange;
		pDeskStation->m_wealthData.total_win += moneyChange;
		pDeskStation->m_wealthData.this_game_win += moneyChange;

        accountType = proto_ff::E_ACCOUNT_TYPE_JETTON;
        optType = proto_ff::E_USER_JETTON_OPER_TYPE_GAME_BALANCED_WIN;
        optReason = proto_ff::E_GAME_BALANCE_REASON_PLAY_GAME_WIN;
	}
	else if (changeType == proto_ff::E_CHAGEMONEY_GAME_REMOVE)
	{
		pDeskStation->m_playerDetail.cur_money -= moneyChange;
		pDeskStation->m_wealthData.total_win -= moneyChange;
		pDeskStation->m_wealthData.this_game_win -= moneyChange;

        accountType = proto_ff::E_ACCOUNT_TYPE_JETTON;
        optType = proto_ff::E_USER_JETTON_OPER_TYPE_GAME_BALANCED_LOST;
        optReason = proto_ff::E_GAME_BALANCE_REASON_PLAY_GAME_LOST;
	}
	else
	{
		NFLogError(NF_LOG_GAME_SERVER_PLUGIN, playerId, "NFGameDesk::UpdateUserMoney Error! unknown changeType! playerId:{} changeType:{} moneyChange:{}", playerId, changeType, moneyChange);
		return -1;
	}

    NFGameRobot* pRobot = NFGameRobotMgr::Instance()->GetRobot(playerId);
	if (pRobot)
    {
        if (changeType == proto_ff::E_CHAGEMONEY_GAME_ADD)
        {
            pRobot->m_jetton += moneyChange;
        }
        else if (changeType == proto_ff::E_CHAGEMONEY_GAME_REMOVE)
        {
            if (pRobot->m_jetton > moneyChange)
            {
                pRobot->m_jetton -= moneyChange;
            }
            else
            {
                pRobot->m_jetton = 0;
            }
        }

        NFRobotMgr::Instance()->SetRobotJetton(pRobot->m_nGameId, pRobot->m_nRoomId, playerId, pRobot->m_jetton);
	    return 0;
    }

	proto_ff::Proto_UpdateJettonReq reqMsg;
	if (changeType == proto_ff::E_CHAGEMONEY_GAME_ADD)
	{
		reqMsg.set_add_or_deduce(true);
	}
	else if (changeType == proto_ff::E_CHAGEMONEY_GAME_REMOVE)
	{
		reqMsg.set_add_or_deduce(false);
	}
	else
	{
		return -1;
	}


	reqMsg.set_player_id(playerId);
	reqMsg.set_game_id(m_gameId);
	reqMsg.set_room_id(m_roomId);
	reqMsg.set_desk_id(m_deskId);
	reqMsg.set_chair_id(pDeskStation->m_chairId);
	reqMsg.set_account_type(accountType);
	reqMsg.set_opt_type(optType);
	reqMsg.set_opt_reason(optReason);
	reqMsg.set_change_type(changeType);
	reqMsg.set_money_change(moneyChange);
	reqMsg.set_time(NFTime::Now().UnixSec());

	SendMsgToLogicServer(proto_ff::E_GTL_UPDATE_JETTON_REQ, reqMsg, playerId);

	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
	return 0;
}

NFGameDeskStation* NFGameDesk::GetDeskStation(int iDeskStation)
{
    CHECK_EXPR(iDeskStation >= 0 && iDeskStation < m_arrDeskStationId.GetSize(), NULL, "iDestStation:{} param error", iDeskStation);
    return &m_arrDeskStationId[iDeskStation];
}

NFGameDeskStation* NFGameDesk::GetDeskStationByPlayerId(uint64_t playerId)
{
	for (int i = 0; i < (int)m_arrDeskStationId.GetSize(); i++) {
		NFGameDeskStation *pDeskStation = &m_arrDeskStationId[i];
		if (pDeskStation->m_playerId == playerId) {
			return pDeskStation;
		}
	}
	return NULL;
}

int NFGameDesk::OnGameBegin() {
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "--begin--");
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "--end--");
    return 0;
}

int NFGameDesk::OnGameFinish() {
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "--begin--");
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "--end--");
    return 0;
}

bool NFGameDesk::IsInDesk(uint64_t playerId) {
    for (int i = 0; i < (int) m_arrDeskStationId.GetSize(); i++) {
        NFGameDeskStation *pDeskStation = &m_arrDeskStationId[i];
        if (pDeskStation->m_playerId == playerId) {
            return true;
        }
    }
    return false;
}

int NFGameDesk::ClearTimeOutUser(uint64_t playerId) {
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "--begin--");
    for (int i = 0; i < (int) m_arrDeskStationId.GetSize(); i++) {
        NFGameDeskStation *pDeskStation = &m_arrDeskStationId[i];
        if (pDeskStation->m_playerId == playerId) {
            if (IsPlayGame(i) && !IsPlayGameCanLeave(i)) {
                NFLogError(NF_LOG_GAME_SERVER_PLUGIN, 0,
                           "ClearTimeOutUser() playerId:{} roomId:{} deskId:{} deskStation:{} is still playing!",
                           playerId, m_roomId, m_deskId, i);
                return -1;
            }

            NFLogError(NF_LOG_GAME_SERVER_PLUGIN, 0,
                       "ClearTimeOutUser playerId:{} Left desk! roomId:{} deskId:{} deskStation:{} is still playing!",
                       playerId, m_roomId, m_deskId, i);

            int iRet = UserLeftDesk(playerId, i, pDeskStation->m_playerDetail);
            if (iRet) {
                NFLogError(NF_LOG_GAME_SERVER_PLUGIN, 0,
                           "ClearTimeOutUser, m_deskHandle->UserLeftDesk() Failed! iRet:{}, playerId:{} Left desk! roomId:{} deskId:{} deskStation:{} is still playing!",
                           iRet, playerId, m_roomId, m_deskId, i);
                return iRet;
            }

            pDeskStation->ClearData();
        }
    }
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "--end--");

    return 0;
}

int NFGameDesk::ClearOfflineUser(uint64_t playerId) {
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "--begin--");
    for (int i = 0; i < (int) m_arrDeskStationId.GetSize(); i++) {
        NFGameDeskStation *pDeskStation = &m_arrDeskStationId[i];
        if (pDeskStation->m_playerId == playerId) {
            if (IsPlayGame(i) && !IsPlayGameCanLeave(i)) {
                NFLogError(NF_LOG_GAME_SERVER_PLUGIN, 0,
                           "ClearOfflineUser() playerId:{} roomId:{} deskId:{} deskStation:{} is still playing!",
                           playerId, m_roomId, m_deskId, i);
                return -1;
            }

            NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, 0,
                       "ClearOfflineUser playerId:{} Left desk! roomId:{} deskId:{} deskStation:{}!",
                       playerId, m_roomId, m_deskId, i);

            int iRet = UserLeftDesk(playerId, i, pDeskStation->m_playerDetail);
            if (iRet) {
                NFLogError(NF_LOG_GAME_SERVER_PLUGIN, 0,
                           "ClearOfflineUser, m_deskHandle->UserLeftDesk() Failed! iRet:{}, playerId:{} Left desk! roomId:{} deskId:{} deskStation:{} is still playing!",
                           iRet, playerId, m_roomId, m_deskId, i);
                return iRet;
            }

			pDeskStation->ClearData();
        }
    }

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "--end--");
    return 0;
}

int NFGameDesk::LogOutDesk(uint64_t playerId, bool bOffline) {
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "--begin--");
	NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
	if (!pPlayer)
	{
        NFGameRoomMgr::GetInstance()->ClearDirtyData(playerId);
		return -1;
	}

	if (m_gameId != pPlayer->m_gameId || m_roomId != pPlayer->m_roomId || m_deskId != pPlayer->m_deskId)
	{
        NFGameRoomMgr::GetInstance()->ClearDirtyData(playerId);
		return -1;
	}

	NFGameDeskStation* pGameDeskStation = GetDeskStation(pPlayer->m_chairId);
	if (pGameDeskStation == NULL)
	{
        NFGameRoomMgr::GetInstance()->ClearDirtyData(playerId);
		return -1;
	}
	else
	{
		if (pGameDeskStation->m_playerId != playerId)
		{
            NFGameRoomMgr::GetInstance()->ClearDirtyData(playerId);
			return -1;
		}

		//获取当前用户是否在游戏中
		bool bUserIsPaying = IsPlayGame(pPlayer->m_chairId);
		if (bOffline)
		{
			if (bUserIsPaying)
			{
				UserDisconnect(playerId, pPlayer->m_chairId, pGameDeskStation->m_playerDetail);
				return 0;
			}
			else
			{
				UserLeftDesk(playerId, pPlayer->m_chairId, pGameDeskStation->m_playerDetail);
			}
		}
		else
		{
			if (bUserIsPaying && !IsPlayGameCanLeave(pPlayer->m_chairId))
			{
				//return -1;
				return proto_ff::ERR_CODE_EXIT_NOT_PERMITED_WHILE_PLAYING;
			}
			else
			{
				UserLeftDesk(playerId, pPlayer->m_chairId, pGameDeskStation->m_playerDetail);
			}
		}

		pGameDeskStation->ClearData();
		pPlayer->ClearGameData();
	}

    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "--end--");
    return 0;
}

int NFGameDesk::GetPlayerCount()
{
    int count = 0;
    for(int i = 0; i < m_arrDeskStationId.GetSize(); i++)
    {
        if (m_arrDeskStationId[i].m_playerId > 0)
        {
            count++;
        }
    }

    return count;
}

void NFGameDesk::NotifyServerPlayerExitGame(uint64_t playerId, int32_t chairId)
{
    NFGameRobot* pRobot = NFGameRobotMgr::Instance()->GetRobot(playerId);
    if (!pRobot)
    {
        proto_ff::Proto_NotifyServerPlayerExitGame msg;
        msg.set_player_id(playerId);
        msg.set_game_id(m_gameId);
        msg.set_room_id(m_roomId);
        msg.set_desk_id(chairId);
        SendMsgToWorldServer(proto_ff::E_STS_GAME_PLAYER_LEAVE_GAME, msg);
    }
}

int NFGameDesk::LogGameRecord(uint64_t recordId, uint64_t playerId, const google::protobuf::Message &betInfo,
                              const google::protobuf::Message &resultInfo) {
    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    if (pDeskStation)
    {
        NFGameLogHandle::Instance()->LogGameRecord(recordId, playerId, pDeskStation->m_playerDetail.nick_name.GetString(), m_gameId, m_roomId, betInfo, resultInfo);
    }
    else
    {
        NFGameLogHandle::Instance()->LogGameRecord(recordId, playerId, "", m_gameId, m_roomId, betInfo, resultInfo);
    }
    return 0;
}

int NFGameDesk::ForceExitGame(uint64_t playerId)
{
	NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "===============> ForceExitGame");

    NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(playerId);
    if (!pPlayer)
    {
        NFGameRoomMgr::GetInstance()->ClearDirtyData(playerId);
        return -1;
    }

    if (m_gameId != pPlayer->m_gameId || m_roomId != pPlayer->m_roomId || m_deskId != pPlayer->m_deskId)
    {
        NFGameRoomMgr::GetInstance()->ClearDirtyData(playerId);
        return -1;
    }

    NFGameDeskStation* pGameDeskStation = GetDeskStation(pPlayer->m_chairId);
    if (pGameDeskStation == NULL)
    {
        NFGameRoomMgr::GetInstance()->ClearDirtyData(playerId);
        return -1;
    }
    else
    {
        if (pGameDeskStation->m_playerId != playerId)
        {
            NFGameRoomMgr::GetInstance()->ClearDirtyData(playerId);
            return -1;
        }

        UserLeftDesk(playerId, pPlayer->m_chairId, pGameDeskStation->m_playerDetail);

        pGameDeskStation->ClearData();
        pPlayer->ClearGameData();
    }

    proto_game::ExitGameRsp rspMsg;
    rspMsg.set_exit_type(0);
    pPlayer->SendMsgToWorld(proto_game::NF_SC_MSG_ExitGameRsp, rspMsg, playerId);

	//////////////////////////////////////////////////////////////////////////
	if (pPlayer->m_isRobot)
	{
		NFGameRobot* pRobot = NFGameRobotMgr::Instance()->GetRobot1(playerId);
		if (pRobot != NULL)
		{
			pRobot->ExitGame();
			pRobot->SetRobotIdle();
		}
	}

    return 0;
}

int NFGameDesk::GameDataCommit(uint64_t cur_fee, uint64_t cur_pour, int64_t cur_win)
{
    if (m_roomHandle)
    {
        return m_roomHandle->GameDataCommit(cur_fee, cur_pour, cur_win);
    }
    return 0;
}

int64_t NFGameDesk::CommissionCount(uint64_t userid, int64_t CountByFee, int64_t pourJetton)
{
    if (CountByFee <= 0)
    {
        return CountByFee;
    }

    const proto_ff_s::GameRoomDesc_s* roomConfig = m_roomHandle->GetRoomConfig();
    if (!roomConfig)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFGameRoomDesc: find room failed! mGameId = {} , mRoomId = {}", m_gameId, m_roomId);
        return CountByFee;
    }

    uint32_t tax = roomConfig->Tax;

    std::string strTaxMode = FindModule<NFICommLogicModule>()->GetConstValue(proto_ff::EN_CONST_USER_FEE_WITH_POUR);
    uint32_t tax_mode = NFCommon::strto<uint32_t>(strTaxMode);

    CHECK_EXPR(tax > 0 && tax <= 100, CountByFee, "tax param error,tax:{}", tax);
    int64_t tmpCount = CountByFee;
    //不加本金抽水
    if (tax_mode == 0)
    {
        tmpCount = CountByFee - pourJetton;
        if (tmpCount <= 0)
        {
            return CountByFee;
        }
    }

    uint64_t commission = std::ceil(tmpCount * tax / (double)100);
    uint64_t realCount = CountByFee - commission;

    return realCount;
}

int NFGameDesk::AchievementCount(uint64_t userid, uint64_t ach, uint64_t fee)
{
    if (ach == 0 && fee == 0) return 0;

    const proto_ff_s::GameRoomDesc_s* roomConfig = m_roomHandle->GetRoomConfig();
    if (!roomConfig)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "NFGameRoomDesc: find room failed! mGameId = {} , mRoomId = {}", m_gameId, m_roomId);
        return 0;
    }

    if (roomConfig->is_exp_scene > 0)
    {
        return 0;
    }

    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(userid);
    CHECK_EXPR(pDeskStation, -1, "AchievementCount Error, can't find player:{} station, Count:{} fee:{}", userid, ach, fee);

    if (ach > 0)
    {
        std::string strAchMode = FindModule<NFICommLogicModule>()->GetConstValue(proto_ff::EN_CONST_USER_ACH_WITH_FEE);
        uint32_t ach_mode = NFCommon::strto<uint32_t>(strAchMode);

        if (ach_mode == 0)
        {
            pDeskStation->m_achievementData.cur_ach += ach - (int64_t)fee;
        }
        else
        {
            pDeskStation->m_achievementData.cur_ach += ach;
        }

        pDeskStation->m_achievementData.MarkDirty();
    }

    if (fee > 0)
    {
        pDeskStation->m_achievementData.cur_fee += fee;
        pDeskStation->m_achievementData.MarkDirty();
    }
    return 0;
}

int NFGameDesk::Tick()
{
    for (int i = 0; i < (int) m_arrDeskStationId.GetSize(); i++) {
        NFGameDeskStation *pDeskStation = &m_arrDeskStationId[i];
        if (pDeskStation->m_playerId > 0) {
            pDeskStation->Tick();
        }
    }
    return 0;
}

int NFGameDesk::DeduceGameMoney(uint64_t playerId, uint64_t moneyChange, bool procUserSettlement)
{
    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, -1, "DeduceGameMoney Error, can't find player:{} station", playerId);

    if (moneyChange > 0)
    {
        if (pDeskStation->m_iCurUserMoney >= moneyChange)
        {
            pDeskStation->m_iCurUserMoney -= moneyChange;
        }
        else
        {
            pDeskStation->m_iCurUserMoney = 0;
        }
        pDeskStation->UpdateUserManagerAddMoney(-1 * (int64_t)moneyChange);
        if (procUserSettlement)
        {
            ProcUserSettlement(pDeskStation);
        }
    }
    return 0;
}

int NFGameDesk::AddGameMoney(uint64_t playerId, uint64_t moneyChange, bool procUserSettlement)
{
    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, -1, "AddGameMoney Error, can't find player:{} station", playerId);

    if (moneyChange > 0)
    {
        pDeskStation->m_iCurUserMoney += moneyChange;
        pDeskStation->UpdateUserManagerAddMoney((int64_t)moneyChange);
        if (procUserSettlement)
        {
            ProcUserSettlement(pDeskStation);
        }
    }
    return 0;
}

int NFGameDesk::ProcUserSettlement(uint64_t playerId)
{
    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, -1, "ProcUserSettlement Error, can't find player:{} station", playerId);

    return ProcUserSettlement(pDeskStation);
}

uint64_t NFGameDesk::GetPlayerCurMoney(uint64_t playerId)
{
    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, 0, "GetPlayerCurMoney Error, can't find player:{} station", playerId);

    return pDeskStation->m_iCurUserMoney;
}

bool NFGameDesk::GetOperateCtrlVal(uint64_t playerId, int *iOperateCtrlRate, int *iOperateCtrlLevel, uint64_t *iOperateMaxWinJetton)
{
    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, false, "GetPlayerCurMoney Error, can't find player:{} station", playerId);

    return pDeskStation->GetOperateCtrlVal(iOperateCtrlRate, iOperateCtrlLevel, iOperateMaxWinJetton);
}

proto_ff_s::tbGameUserManagerData_s *NFGameDesk::GetUserManagerData(uint64_t playerId)
{
    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, NULL, "GetPlayerCurMoney Error, can't find player:{} station", playerId);

    return pDeskStation->GetUserManagerData();
}

uint64_t NFGameDesk::GetMaxWinJetton(uint64_t playerId)
{
    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, 0, "GetPlayerCurMoney Error, can't find player:{} station", playerId);

    return pDeskStation->GetMaxWinJetton();
}

proto_ff_s::tbGmCtrlGiveCtrlData_s *NFGameDesk::GetGmCtrlGiveData(uint64_t playerId)
{
    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, 0, "GetPlayerCurMoney Error, can't find player:{} station", playerId);

    return pDeskStation->GetGmCtrlGiveData();
}

int NFGameDesk::FinishGmCtrlGiveData(uint64_t playerId)
{
    NFGameDeskStation* pDeskStation = GetDeskStationByPlayerId(playerId);
    CHECK_EXPR(pDeskStation, 0, "GetPlayerCurMoney Error, can't find player:{} station", playerId);

    return pDeskStation->FinishGmCtrlGiveData();
}