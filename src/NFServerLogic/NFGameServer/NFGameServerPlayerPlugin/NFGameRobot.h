#pragma once
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include <NFServer/NFCommHead/NFCommLogicHead.h>
#include "NFServer/NFCommHead/NFIGameRobot.h"
#include "NFServer/NFCommHead/NFIGameRobotHandle.h"

class NFGameRoom;
class NFGameRobot :public NFIGameRobot
{
public:
	NFGameRobot();
	virtual ~NFGameRobot();

	int CreateInit();
	int ResumeInit();

	int InitDetail(proto_ff_s::RobotCommonData_s* pRobotData);
	int Init(uint32_t gameId, uint32_t roomId, int32_t deskId, uint32_t chairId, uint32_t robotShootInterval);
	int EnterGame();
	int ExitGame();
	//void Destory();
	void SetRobotIdle();


	virtual void SendMsgToServer(uint64_t playerId, uint32_t nMsgId, const google::protobuf::Message& xData);
	virtual void SendMsgToServer(uint64_t playerId, uint32_t nMsgId, const char *msg, uint32_t nLen);

	virtual int OnHandleServerMsg(uint32_t nMsgId, const google::protobuf::Message& xData);



public:
	uint64_t m_playerId;
	uint32_t m_nGameId;
	uint32_t m_nRoomId;
	int32_t m_nDeskId;
	int32_t m_nChairId;

	bool m_bIsIdle;

	NFRawShmPtr<NFIGameRobotHandle> m_robotHandle;
public:
    NFSizeString<64> m_nickname;
    uint32_t m_face_id;
    uint32_t m_age;
    uint32_t m_gender;
    uint64_t m_jetton;

	DECLARE_IDCREATE(NFGameRobot)
};




