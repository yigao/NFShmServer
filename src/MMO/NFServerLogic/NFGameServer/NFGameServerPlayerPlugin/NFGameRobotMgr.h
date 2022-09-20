#pragma once
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include <NFServer/NFCommHead/NFCommLogicHead.h>
#include <vector>
#include "NFGameRoom.h"
#include "NFGameDesk.h"
#include "NFGameRobot.h"

class NFGameRobotMgr :public NFShmObj
{
public:
	NFGameRobotMgr();
	virtual ~NFGameRobotMgr();

	int CreateInit();
	int ResumeInit();
	
	NFGameRobot* GetRobot(uint64_t playerId);
	NFGameRobot* GetRobot1(uint64_t playerId);
	NFGameRobot* CreateRobot(uint64_t playerId);
	NFGameRobot* GetIdleRobot();
	uint64_t CreateRobotPlayerId();
	bool IsRobotPlayerIdExist(uint64_t playerId);

	int DeleteRobot(NFGameRobot* pRobot);
	std::vector<NFGameRobot*> GetAllRobot();

	int OnHandleServerMsg(uint64_t playerId, uint32_t nMsgId, const google::protobuf::Message& xData);

public:
	TDeskStationNode GetChairInfoForRobot(int& iGameId, int& iRoomId, int maxRobotPerDesk, bool bIsNeedRealPlayer = true);
	void GetDeadRobots(std::vector<uint64_t>& vec);
private:
	DECLARE_IDCREATE(NFGameRobotMgr)
};








