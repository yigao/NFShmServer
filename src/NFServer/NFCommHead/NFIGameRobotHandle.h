#pragma once
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFServer/NFCommHead/NFIGameRoomModule.h"
#include "NFServer/NFCommHead/NFIGameRobot.h"

class NFIGameRobotHandle : public NFShmObj
{
public:
	NFIGameRobotHandle()
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

	virtual ~NFIGameRobotHandle() {}

	int CreateInit()
	{
		return 0;
	}
	
	int ResumeInit()
	{
		return 0;
	}

	virtual int Init(NFIGameRobot* pGameRobot, uint64_t playerId, uint32_t gameId, uint32_t roomId, int32_t deskId, uint32_t chairId, uint32_t robotShootInterval) = 0;
	//virtual int Destroy() = 0;
	virtual int SetRobotIdle() { return 0; };
	virtual int OnHandleServerMsg(uint32_t nMsgId, const char *msg, uint32_t nLen) = 0;
protected:
};



