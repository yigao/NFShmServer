// -------------------------------------------------------------------------
//    @FileName         :    NFTransSnsUserOnline.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransSnsUserOnline.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFUserSimple/NFTransSnsBase.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFMessageDefine/proto_svr_login.pb.h"

class NFTransSnsUserOnline : public NFTransSnsBase {
public:
	NFTransSnsUserOnline();

	virtual ~NFTransSnsUserOnline();

	int CreateInit();

	int ResumeInit();
public:
	int UserLogin(const proto_ff::Proto_LogicToSnsLoginReq& req);
    int UserReconnect(const proto_ff::LTSNotifyPlayerReconnectReq& req);
	int OnUserLogin(int iRunLogicRetCode);
    int OnUserReconnect(int iRunLogicRetCode);
    int UserModifyName(const proto_ff::LTSnsChangeNickNameNotify& req);
    int OnUserModifyName(int iRunLogicRetCode);
    int UserModifyUserId(const proto_ff::LTSnsChangeUserIdNotify& req);
    int OnUserModifyUserId(int iRunLogicRetCode);
    int UserModifyVipLevel(const proto_ff::LTSnsChangeVipLevelNotify& req);
    int OnUserModifyVipLevel(int iRunLogicRetCode);
public:
	virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
		uint32_t seq, uint32_t err_code);

	int ProInsertSimpleDataRes(const storesvr_sqldata::storesvr_ins_res *pRsp, uint32_t err_code);
public:
	virtual int HandleGetRoleRes(int iRunLogicRetCode, uint64_t roleID);

	virtual int QueryRole_CallBack(tagQueryRole& query);
public:
	int OnTransFinished(int iRunLogicRetCode);
	int HandleTransFinished(int iRunLogicRetCode) { return 0; }
	virtual int OnTimeOut() { return 0; }
private:
	uint64_t m_userId;
	int m_cmd;
	int m_logicServerId;
	uint32_t m_lastLoginTime;
	uint32_t m_lastLogoutTime;
	bool m_newPlayer;
	proto_ff_s::UserSimpleData_s m_simpleData;
	DECLARE_IDCREATE(NFTransSnsUserOnline)
};
