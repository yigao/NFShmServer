// -------------------------------------------------------------------------
//    @FileName         :    NFRegisterAccount.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFRegisterAccount.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFGetAccountTrans.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFMessageDefine/proto_cs_login.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_login.pb.h"

class NFRegisterAccountTrans : public NFGetAccountTrans
{
public:
    NFRegisterAccountTrans();
    virtual ~NFRegisterAccountTrans();
    int CreateInit();
    int ResumeInit();

    int HandleDispSvrRes(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnTransFinished(int iRunLogicRetCode);
public:
    virtual int HandleGetBaseInfoMsgParam(const google::protobuf::Message *pCSMsgReq);
    virtual int HandleGetBaseInfoRes(NFAccountLogin *pUserLogin);
    virtual int ProRegisterAccountRes();
    virtual int ProRigisterAccountInfoReq(const proto_login::Proto_CSRegisterAccountReq *pRegisterReq);

    virtual int ProGetBaseInfoRes(const storesvr_sqldata::storesvr_selobj_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code);
    virtual int CreateAccountReq();
private:
    bool mCheckAccount;
    NFSizeString<MAX_PLAYER_ACCOUNT_SIZE>  mNickName;
    proto_ff_s::LoginCommonData_s m_data;
DECLARE_IDCREATE(NFRegisterAccountTrans)
};

