// -------------------------------------------------------------------------
//    @FileName         :    NFTransLogicUserBase.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransLogicUserBase.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFShmCore/NFSizeString.h"

class NFGameSession;
class NFTransGamePlayerBase : public NFTransBase {
public:
	NFTransGamePlayerBase();

	virtual ~NFTransGamePlayerBase();

	int CreateInit();

	int ResumeInit();

	int Init(uint64_t userId, uint32_t cmd, uint32_t fromBusId = 0);
	int Init(NFGameSession* pUser, uint32_t cmd, uint32_t fromBusId = 0);

	NFGameSession *GamePlayer();

	virtual int OnTimeOut();
	virtual int OnTransFinished(int iRunLogicRetCode);
	virtual int HandleTransFinished(int iRunLogicRetCode);
protected:
	uint32_t m_cmd;
	uint64_t m_playerId;
	uint32_t m_fromBusId;
	bool m_bHasIncreasedCount;
	DECLARE_IDCREATE(NFTransGamePlayerBase)
};
