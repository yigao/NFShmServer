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
#include "NFTransPlayerBase.h"
#include "NFLogicCommon/NFCharactorDefine.h"


class NFTransSaveDB : public NFTransPlayerBase {
public:
	NFTransSaveDB();

	virtual ~NFTransSaveDB();

	int CreateInit();

	int ResumeInit();

	virtual int HandleTransFinished(int iRunLogicRetCode);
public:
	int SaveDB(TRANS_SAVEROLEDETAIL_REASON iReason = TRANS_SAVEROLEDETAIL_NORMAL);
private:
	TRANS_SAVEROLEDETAIL_REASON m_reason;
    uint32_t m_curSeq;
	DECLARE_IDCREATE(NFTransSaveDB)
};
