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

class NFPlayer;
class NFTransPlayerBase : public NFTransBase {
public:
	NFTransPlayerBase();

	virtual ~NFTransPlayerBase();

	int CreateInit();

	int ResumeInit();

	int Init(uint64_t cid, uint32_t cmd, uint32_t fromBusId = 0, uint32_t reqTransId = 0);
	int Init(NFPlayer* pUser, uint32_t cmd, uint32_t fromBusId = 0, uint32_t reqTransId = 0);

    NFPlayer *GetPlayer();

	virtual int OnTimeOut();
	virtual int OnTransFinished(int iRunLogicRetCode);
protected:
	uint32_t m_cmd;
	uint64_t m_cid;
	uint32_t m_fromBusId;
	uint32_t m_reqTransId;
	bool m_bHasIncreasedCount;
	DECLARE_IDCREATE(NFTransPlayerBase)
};
