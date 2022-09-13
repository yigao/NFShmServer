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
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFTransLogicUserBase.h"

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

class NFTransSaveDB : public NFTransLogicUserBase {
public:
	NFTransSaveDB();

	virtual ~NFTransSaveDB();

	int CreateInit();

	int ResumeInit();

	virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq);

	virtual int HandleDispSvrRes(const google::protobuf::Message *pSSMsgRes);

	virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
		uint32_t seq, uint32_t err_code);

	virtual int HandleTransFinished(int iRunLogicRetCode);
public:
	int ProHandleSaveDB(TRANS_SAVEROLEDETAIL_REASON iReason = TRANS_SAVEROLEDETAIL_NORMAL);
	int ProSaveDBRes(uint32_t err_code, uint32_t seq);
private:
	TRANS_SAVEROLEDETAIL_STATE m_enState;
	TRANS_SAVEROLEDETAIL_REASON m_reason;
	DECLARE_IDCREATE(NFTransSaveDB)
};
