#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFShmCore/NFArray.h"
#include "NFServer/NFCommHead/NFIGameRobot.h"
#include "NFComm/NFMessageDefine/proto_cs.pb.h"


class NFIGameRobot : public NFShmObj
{
public:
	NFIGameRobot()
	{
		if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
			CreateInit();
		}
		else {
			ResumeInit();
		}
	}

	virtual ~NFIGameRobot()
	{

	}

	int CreateInit() {
		return 0;
	}

	int ResumeInit() {
		return 0;
	}

	virtual void SendMsgToServer(uint64_t playerId, uint32_t nMsgId, const google::protobuf::Message& xData) = 0;
	virtual void SendMsgToServer(uint64_t playerId, uint32_t nMsgId, const char *msg, uint32_t nLen) = 0;



};








