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

typedef enum
{
	TRANS_SAVEROLEDETAIL_STATE_INIT = 0,
	TRANS_SAVEROLEDETAIL_STATE_SAVING_ROLE = 1,
	TRANS_SAVEROLEDETAIL_FIN_OK,
} TRANS_SAVEROLEDETAIL_STATE;

typedef enum
{
	TRANS_SAVEROLEDETAIL_NORMAL = 1,
	TRANS_SAVEROLEDETAIL_LOGOUT = 2,
} TRANS_SAVEROLEDETAIL_REASON;

class NFTransSaveDB : public NFTransPlayerBase {
public:
	NFTransSaveDB();

	virtual ~NFTransSaveDB();

	int CreateInit();

	int ResumeInit();

	virtual int HandleTransFinished(int iRunLogicRetCode);
public:
	int SaveDB(TRANS_SAVEROLEDETAIL_REASON iReason = TRANS_SAVEROLEDETAIL_NORMAL);
	int ProSaveDBRes(uint32_t err_code, uint32_t seq);
private:
	TRANS_SAVEROLEDETAIL_REASON m_reason;
    uint32_t m_curSeq;
	DECLARE_IDCREATE(NFTransSaveDB)
};
