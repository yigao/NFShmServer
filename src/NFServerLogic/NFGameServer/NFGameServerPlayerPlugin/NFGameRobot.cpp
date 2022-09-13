#include "NFGameRobot.h"
#include "NFServer/NFCommHead/NFIGameRoomModule.h"
#include "NFComm/NFMessageDefine/proto_cs_game.pb.h"
#include "NFGameSession.h"
#include "NFGameSessionMgr.h"
#include "NFGameRoomMgr.h"
#include "NFGameRoom.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGameRobot, EOT_GAME_ROBOT_ID, NFShmObj)

NFGameRobot::NFGameRobot()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

NFGameRobot::~NFGameRobot()
{
	//Destory();
}

int NFGameRobot::CreateInit()
{
	m_playerId = -1;
	m_nGameId  = -1;
	m_nRoomId  = -1;
	m_nDeskId  = -1;
	m_nChairId = -1;
	m_bIsIdle  = true;

	m_robotHandle = NULL;

    m_face_id = 0;
    m_age = 0;
    m_gender = 0;
    m_jetton = 0;

	return 0;
}

int NFGameRobot::ResumeInit()
{
	return 0;
}

int NFGameRobot::InitDetail(proto_ff_s::RobotCommonData_s* pRobotData)
{
    CHECK_NULL(pRobotData);
    CHECK_EXPR(pRobotData->robot_id == m_playerId, -1, "pRobotData->robot_id == m_playerId");
    m_nickname = pRobotData->nickname;
    m_face_id = pRobotData->face_id;
    m_age = pRobotData->age;
    m_gender = pRobotData->gender;
    m_jetton = pRobotData->jetton;
    return 0;
}

int NFGameRobot::Init(uint32_t gameId, uint32_t roomId, int32_t deskId, uint32_t chairId, uint32_t robotShootInterval)
{
	m_nGameId  = gameId;
	m_nRoomId  = roomId;
	m_nDeskId  = deskId;
	m_nChairId = chairId;
	m_bIsIdle = false;
	NFLogTrace(NF_LOG_SUB_GAME_PLUGIN, 0, "NFGameRobot::Init()  ============ playerId = {}, m_nGameId = {}, m_nRoomId = {}, deskId = {}, chairId", m_playerId, m_nGameId, m_nRoomId, deskId, chairId);

	if (m_robotHandle.GetPoint() == NULL)
	{
		m_robotHandle = NFIPluginManager::Instance()->FindModule<NFIGameRoomModule>()->CreateGameRobotHandle(gameId);
		CHECK_EXPR(m_robotHandle, -1, "Create Game Robot Handle Failed, gameId:{}, roomId:{}, deskIndex:{}, m_nChairId:{}", gameId, roomId, m_nDeskId, m_nChairId);
	}
	
	m_robotHandle->Init(this, m_playerId, m_nGameId, m_nRoomId, m_nDeskId, m_nChairId, robotShootInterval);

	return EnterGame();
}

int NFGameRobot::EnterGame()
{
    NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(m_playerId);
    if (!pPlayer)
    {
        NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "============> CreatePlayer();");
        pPlayer = NFGameSessionMgr::GetInstance()->CreatePlayer(m_playerId);

        CHECK_PLAYER_EXPR(m_playerId, pPlayer, -1, "Create Player Failed, playerId:{}", m_playerId);
    }

    pPlayer->SetClearFlag(false);
    pPlayer->SetProxyId(0);
    pPlayer->SetLogicId(0);
    pPlayer->SetOnline(true);
    pPlayer->SetOfflineTime(0);
    pPlayer->SetLastMsgTime(NFTime::Now().UnixSec());

    pPlayer->m_isRobot = true;

    if (pPlayer->m_gameId > 0 && pPlayer->m_roomId > 0)
    {
        if (pPlayer->m_gameId != m_nGameId || pPlayer->m_roomId != m_nRoomId || pPlayer->m_deskId != m_nDeskId || pPlayer->m_chairId != m_nChairId)
        {
            NFGameRoomMgr::GetInstance()->ClearDirtyData(pPlayer->m_playerId);
        }
    }

    NFGameRoom *pRoom = NFGameRoomMgr::GetInstance()->GetGameRoom(m_nGameId, m_nRoomId);
    if (pRoom)
    {
        pPlayer->m_gameId = m_nGameId;
        pPlayer->m_roomId = m_nRoomId;
        pRoom->OnHandleEnterGameMsg(pPlayer, m_nDeskId, m_nChairId);
    }
    else
    {
        NFGameRoomMgr::GetInstance()->ClearDirtyData(pPlayer->m_playerId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "gameId:{} roomId:{} not exist, player:{} enter game failed!", m_nGameId, m_nRoomId, pPlayer->m_playerId);
    }

    return 0;
}

int NFGameRobot::ExitGame()
{
	NFLogTrace(NF_LOG_SUB_GAME_PLUGIN, 0, "NFGameRobot::ExitGame()  ============ playerId = {}, m_nGameId = {}, m_nRoomId = {}, deskId = {}, chairId", m_playerId, m_nGameId, m_nRoomId, m_nDeskId, m_nChairId);

    NFGameSession *pPlayer = NFGameSessionMgr::GetInstance()->GetPlayer(m_playerId);
    CHECK_PLAYER_EXPR(m_playerId, pPlayer, -1, "Get Player Failed, playerId:{}", m_playerId);

    NFGameRoom *pRoom = NFGameRoomMgr::GetInstance()->GetGameRoom(pPlayer->m_gameId, pPlayer->m_roomId);
    if (pRoom)
    {
        pRoom->OnHandleExitGameMsg(m_playerId);
    }
    else
    {
        NFGameRoomMgr::GetInstance()->ClearDirtyData(pPlayer->m_playerId);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "gameId:{} roomId:{} not exist, player:{} enter game failed!", m_nGameId, m_nRoomId, pPlayer->m_playerId);
        return -1;
    }

	return 0;
}

//void NFGameRobot::Destory()
//{
//	if (m_robotHandle)
//	{
//		m_robotHandle->Destroy();
//		NFShmMgr::Instance()->DestroyObj(m_robotHandle);
//
//		m_robotHandle = NULL;
//	}
//}

void NFGameRobot::SetRobotIdle()
{
	m_bIsIdle = true;
	if (m_robotHandle)
	{
		m_robotHandle->SetRobotIdle();
	}
}


void NFGameRobot::SendMsgToServer(uint64_t playerId, uint32_t nMsgId, const google::protobuf::Message& xData)
{
	NFLogTrace(NF_LOG_SUB_GAME_PLUGIN, 0, "NFGameRobot::SendMsgToServer()  ============ playerId = {} ,nMsgId = {}", playerId, nMsgId);

	NFIPluginManager::Instance()->FindModule<NFIGameRoomModule>()->SendRobotMsgToServer(playerId, nMsgId, xData);
}

void NFGameRobot::SendMsgToServer(uint64_t playerId, uint32_t nMsgId, const char *msg, uint32_t nLen)
{
	NFIPluginManager::Instance()->FindModule<NFIGameRoomModule>()->SendRobotMsgToServer(playerId, nMsgId, msg, nLen);
}

int NFGameRobot::OnHandleServerMsg(uint32_t nMsgId, const google::protobuf::Message& xData)
{
	std::string strData;
	if (!xData.SerializeToString(&strData))
	{
		NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "NFGameRobot::OnHandleServerMsg() =============> SerializeToString fail !");
		return -1;
	}
	
	CHECK_EXPR(m_robotHandle, -1, "m_robotHandle == NULL for playerId = {}", m_playerId);

	m_robotHandle->OnHandleServerMsg(nMsgId, (char*)strData.c_str(), strData.length());

	return 0;
}
