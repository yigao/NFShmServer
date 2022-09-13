// -------------------------------------------------------------------------
//    @FileName         :    NFTransCreateUserDetail.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransCreateUserDetail.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFTransLogicUserBase.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"

class NFTransCreateUserDetail : public NFTransLogicUserBase {
public:
    NFTransCreateUserDetail();

    virtual ~NFTransCreateUserDetail();

    int CreateInit();

    int ResumeInit();

    virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq);

    virtual int HandleDispSvrRes(const google::protobuf::Message *pSSMsgRes);

    virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                               uint32_t seq, uint32_t err_code);

    virtual int OnTransFinished( int iRunLogicRetCode );
public:
    int CreateUserDetail();
    int CreateUserDetail(const std::string& nickName, uint64_t phoneNum, const proto_ff_s::LoginCommonData_s& loginData);
private:
DECLARE_IDCREATE(NFTransCreateUserDetail)
};
