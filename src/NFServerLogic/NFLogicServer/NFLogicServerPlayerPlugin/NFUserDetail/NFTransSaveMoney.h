// -------------------------------------------------------------------------
//    @FileName         :    NFTransLogicUserBase.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransLogicUserBase.h
//
// -------------------------------------------------------------------------


#pragma once

#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFTransLogicUserBase.h"

class NFTransSaveMoney : public NFTransLogicUserBase {
public:
	NFTransSaveMoney();

	virtual ~NFTransSaveMoney();

	int CreateInit();

	int ResumeInit();

	virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq);

	virtual int HandleDispSvrRes(const google::protobuf::Message *pSSMsgRes);

	virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
		uint32_t seq, uint32_t err_code);

	virtual int HandleTransFinished(int iRunLogicRetCode);
public:
	int ProHandleSaveMoney();
private:
	DECLARE_IDCREATE(NFTransSaveMoney)
};
