#include "NFGameRobotMgr.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFGameRoomMgr.h"


IMPLEMENT_IDCREATE_WITHTYPE(NFGameRobotMgr, EOT_GAME_ROBOT_ID_HASH_TABLE_ID, NFShmObj)

NFGameRobotMgr::NFGameRobotMgr()
{
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

NFGameRobotMgr::~NFGameRobotMgr()
{

}

int NFGameRobotMgr::CreateInit() 
{
	return 0;
}


int NFGameRobotMgr::ResumeInit() 
{
	return 0;
}

NFGameRobot* NFGameRobotMgr::GetRobot(uint64_t playerId)
{
	return dynamic_cast<NFGameRobot*>(NFShmMgr::Instance()->GetObjFromHashKey(playerId, EOT_GAME_ROBOT_ID));
}

NFGameRobot* NFGameRobotMgr::GetRobot1(uint64_t playerId)
{
	std::vector<NFGameRobot*> vec = NFGameRobotMgr::Instance()->GetAllRobot();
	std::vector<NFGameRobot*>::iterator iter = vec.begin();
	for (; iter != vec.end(); iter++)
	{
		if ((*iter)->m_playerId == playerId)
		{
			return (*iter);
		}
	}

	return NULL;
}

NFGameRobot* NFGameRobotMgr::CreateRobot(uint64_t playerId)
{
	NFGameRobot *pRobot = GetRobot(playerId);
	CHECK_EXPR(pRobot == NULL, NULL, "Create robot Failed, player exist, palyerId:{}", playerId);

	pRobot = dynamic_cast<NFGameRobot *>(NFShmMgr::Instance()->CreateObj(playerId, EOT_GAME_ROBOT_ID));
	CHECK_EXPR(pRobot, NULL, "Create pRobot Obj Failed, playerID:{}", playerId);

	pRobot->m_playerId = playerId;
	NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, 0, "Add Robot Success, playerId:{} globalId:{}", playerId, pRobot->GetGlobalID());

	pRobot = GetRobot(playerId);
	CHECK_EXPR(pRobot, NULL, "GetRobot Failed, palyerId:{}", playerId);

	return pRobot;
}

NFGameRobot* NFGameRobotMgr::GetIdleRobot()
{
	NFGameRobot* pRobot = dynamic_cast<NFGameRobot *>(NFShmMgr::Instance()->GetHeadObj(EOT_GAME_ROBOT_ID));
	while (pRobot)
	{
		if (pRobot->m_bIsIdle == true)
		{
			return pRobot;
		}
		pRobot = dynamic_cast<NFGameRobot *>(NFShmMgr::Instance()->GetNextObj(EOT_GAME_ROBOT_ID, pRobot));
	}

	return NULL;
}

uint64_t NFGameRobotMgr::CreateRobotPlayerId()
{
	bool isExist = false;
	int randId = 0;

	do 
	{
		randId = NFRandInt(1, 1000);
		isExist = IsRobotPlayerIdExist(randId);
	} while (isExist);
	
	return randId;
}

bool NFGameRobotMgr::IsRobotPlayerIdExist(uint64_t playerId)
{
	NFGameRobot* pRobot = GetRobot(playerId);
	if (pRobot)
	{
		return true;
	}

	return false;
}

int NFGameRobotMgr::DeleteRobot(NFGameRobot* pRobot)
{
	CHECK_NULL(pRobot);
	NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, 0, "Delete pRobot Info, playerID, gloablId:{}", pRobot->m_playerId, pRobot->GetGlobalID());

	NFShmMgr::Instance()->DestroyObj(pRobot);

	return 0;
}

std::vector<NFGameRobot*> NFGameRobotMgr::GetAllRobot()
{
	std::vector<NFGameRobot*> vec;

	NFGameRobot* pRobot = dynamic_cast<NFGameRobot *>(NFShmMgr::Instance()->GetHeadObj(EOT_GAME_ROBOT_ID));
	while (pRobot)
	{
		vec.push_back(pRobot);
		pRobot = dynamic_cast<NFGameRobot *>(NFShmMgr::Instance()->GetNextObj(EOT_GAME_ROBOT_ID, pRobot));
	}

	return vec;
}

TDeskStationNode NFGameRobotMgr::GetChairInfoForRobot(int& iGameId, int& iRoomId, int maxRobotPerDesk, bool bIsNeedRealPlayer /*= true*/)
{
	TDeskStationNode destStation;
	destStation.m_nDeskIndex   = -1;
	destStation.m_nDeskStation = -1;

	std::vector<NFGameRoom*> vecRooms = NFGameRoomMgr::Instance()->GetAllRoom();
	std::vector<NFGameRoom*>::iterator iter = vecRooms.begin();
	for (; iter!=vecRooms.end(); iter++)
	{
		NFGameRoom* pRoom = *iter;
		if (pRoom == NULL)
		{
			continue;
		}

		int iDeskIndex   = -1;
		int iDeskStation = -1;
		int ret = pRoom->LookingSuitSeatForRobot(0, iDeskIndex, iDeskStation, maxRobotPerDesk, bIsNeedRealPlayer);
		if (ret == 0 && iDeskIndex>=0 && iDeskStation>=0)
		{
			destStation.m_nDeskIndex   = iDeskIndex;
			destStation.m_nDeskStation = iDeskStation;

			iGameId = pRoom->m_gameId;
			iRoomId = pRoom->m_roomId;

			break;
		}
	}

	return destStation;
}

void NFGameRobotMgr::GetDeadRobots(std::vector<uint64_t>& vec)
{
	std::vector<NFGameRoom*> vecRooms = NFGameRoomMgr::Instance()->GetAllRoom();
	std::vector<NFGameRoom*>::iterator iter = vecRooms.begin();
	for (; iter != vecRooms.end(); iter++)
	{
		NFGameRoom* pRoom = *iter;
		if (pRoom == NULL)
		{
			continue;
		}

		pRoom->GetDeadRobots(vec);
	}

}

int NFGameRobotMgr::OnHandleServerMsg(uint64_t playerId, uint32_t nMsgId, const google::protobuf::Message& xData)
{
	//NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "NFGameRobotMgr::OnHandleServerMsg() ============> nMsgId = {}", nMsgId);


	//NFGameRobot* pRobot = GetRobot(playerId);
	NFGameRobot* pRobot = GetRobot1(playerId);
	CHECK_EXPR(pRobot, -1, "Can't find robot, playerID:{}", playerId);

	pRobot->OnHandleServerMsg(nMsgId, xData);

	return 0;
}




