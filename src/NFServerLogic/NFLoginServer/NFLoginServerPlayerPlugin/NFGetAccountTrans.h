// -------------------------------------------------------------------------
//    @FileName         :    NFGetAccountTrans.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGetAccountTrans.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFComm/NFMessageDefine/proto_common.pb.h"
#include "NFComm/NFMessageDefine/proto_cs_login.pb.h"

class NFAccountLogin;
class NFGetAccountTrans : public NFTransBase
{
public:
    enum {
        CHECK_ACCOUNT_EXIST,
        CREATE_ACCOUNT,
    };
    NFGetAccountTrans();
    virtual ~NFGetAccountTrans();
    int CreateInit();
    int ResumeInit();

    int Init(uint32_t busId, uint64_t clientLinkId, uint32_t cmd);

    virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq);
    virtual int
    HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id, uint32_t seq,
                   uint32_t err_code);

    int HandleDispSvrRes(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen);

    virtual bool IsTimeOut();
    virtual int OnTimeOut();
    int OnTransFinished(int iRunLogicRetCode);
    int HandleTransFinished(int iRunLogicRetCode) { return 0; }
public:
    virtual int HandleGetBaseInfoMsgParam(const google::protobuf::Message *pCSMsgReq);
    virtual int HandleGetBaseInfoRes(NFAccountLogin *pUserLogin);
    virtual int ProGetAccountInfoReq(const proto_login::Proto_CSAccountLoginReq *pLoginReq);
    virtual int ProGetAccountInfoReq(const proto_login::Proto_CS_ChangePasswordReq *pLoginReq);
    virtual int ProGetAccountInfoRes();
    virtual int ProGetBaseInfoReq();
    virtual int CreateAccountReq();
    virtual int ProChangePasswordRes();
public:
    virtual int ProGetBaseInfoRes(const storesvr_sqldata::storesvr_selobj_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code);
    virtual int ProBaseCreateRes(const storesvr_sqldata::storesvr_ins_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code);
    virtual int ProBaseChangePassowrdRes(const storesvr_sqldata::storesvr_modobj_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code);
protected:
    NFSizeString<MAX_PLAYER_ACCOUNT_SIZE>  mAccount;
    NFSizeString<MAX_PLAYER_ACCOUNT_SIZE>  mPassword;
    NFSizeString<MAX_PLAYER_ACCOUNT_SIZE>  mDeviecId;
    uint32_t mProxyBusId;
    uint64_t mClientLinkId;
	uint32_t mLoginType;
	uint32_t mCmd;
	bool mCreateAccount;
DECLARE_IDCREATE(NFGetAccountTrans)
};
