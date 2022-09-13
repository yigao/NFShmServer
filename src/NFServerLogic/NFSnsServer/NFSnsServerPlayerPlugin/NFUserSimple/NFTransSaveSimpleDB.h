// -------------------------------------------------------------------------
//    @FileName         :    NFTransSaveSimpleDB.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransSaveSimpleDB.h
//
// -------------------------------------------------------------------------


#pragma once

#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"

class NFSnsUserSimple;
class NFTransSaveSimpleDB : public NFTransBase {
public:
	NFTransSaveSimpleDB();

	virtual ~NFTransSaveSimpleDB();

	int CreateInit();

	int ResumeInit();

	int Init(NFSnsUserSimple* pUser);
	NFSnsUserSimple* UserSimple();

	virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq);

	virtual int HandleDispSvrRes(const google::protobuf::Message *pSSMsgRes);

	virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
		uint32_t seq, uint32_t err_code);

	virtual int HandleTransFinished(int iRunLogicRetCode);
public:
	int ProHandleSaveDB();
	int ProSaveDBRes(uint32_t err_code, uint32_t seq);
private:
	uint64_t m_userId;
	DECLARE_IDCREATE(NFTransSaveSimpleDB)
};
