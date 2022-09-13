// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetUserDetail.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransGetUserDetail.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_login.pb.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFTransLogicUserBase.h"

class NFTransGetUserDetail : public NFTransLogicUserBase {
public:
    NFTransGetUserDetail();

    virtual ~NFTransGetUserDetail();

    int CreateInit();

    int ResumeInit();

    virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq);

    virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                               uint32_t seq, uint32_t err_code);

    int ProGetUserDetailReq(const proto_ff::Proto_WTLRegisterUserReq *pLoginReq);
    int ProGetUserDetailReq(const proto_ff::Proto_WorldToLogicLoginReq *pLoginReq);
    int ProGetUserDetailReq(const proto_ff::Proto_NotifyChangeAgent *pJettonReq);
    int ProGetUserDetailReq(const proto_ff::LTLPlayerDeviceChangeNotify* pNotify);
    int ProGetUserDetailReq();
    int ProGetUserDetailReq(uint64_t moneyChange, uint32_t optType, uint32_t optReason, uint32_t changeTime);

    virtual int HandleTransFinished( int iRunLogicRetCode );
public:
    int CreateUserDetail();
private:
	uint32_t m_gameId;
	uint32_t m_roomId;
	uint32_t m_deskId;
	uint32_t m_chairId;
	uint32_t m_gameBusId;
	uint32_t m_proxyBusId;
	uint32_t m_loginBusId;
	uint64_t m_phoneNum;
	uint32_t m_loginReqTransId;
	uint64_t m_moneyChange;
	uint32_t m_accountType;
	uint32_t m_optType;
	uint32_t m_optReason;
	uint32_t m_changeTime;
    NFSizeString<64>  mNickName;
	proto_ff_s::LoginCommonData_s m_loginData;
	uint64_t m_agentId;
	bool m_isLoadDB;
	bool m_add;
DECLARE_IDCREATE(NFTransGetUserDetail)
};