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

class NFUserDetail;
class NFTransLogicUserBase : public NFTransBase {
public:
	NFTransLogicUserBase();

	virtual ~NFTransLogicUserBase();

	int CreateInit();

	int ResumeInit();

	int Init(uint64_t userId, uint32_t cmd, uint32_t fromBusId = 0, uint32_t reqTransId = 0);
	int Init(NFUserDetail* pUser, uint32_t cmd, uint32_t fromBusId = 0, uint32_t reqTransId = 0);

	NFUserDetail *UserDetail();

	virtual int OnTimeOut();
	virtual int OnTransFinished(int iRunLogicRetCode);
protected:
	uint32_t m_cmd;
	uint64_t m_userId;
	uint32_t m_fromBusId;
	uint32_t m_reqTransId;
	bool m_bHasIncreasedCount;
	DECLARE_IDCREATE(NFTransLogicUserBase)
};
