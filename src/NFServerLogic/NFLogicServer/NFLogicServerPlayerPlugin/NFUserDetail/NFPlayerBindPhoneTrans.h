// -------------------------------------------------------------------------
//    @FileName         :    NFPlayerBindPhoneTrans.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPlayerBindPhoneTrans.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFComm/NFMessageDefine/proto_cs_login.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_login.pb.h"
#include "NFTransLogicUserBase.h"

class NFPlayerBindPhoneTrans: public NFTransLogicUserBase
{
public:
    NFPlayerBindPhoneTrans();
    virtual ~NFPlayerBindPhoneTrans();
    int CreateInit();
    int ResumeInit();

    virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq);
    virtual int
    HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id, uint32_t seq,
                   uint32_t err_code);

    int HandleDispSvrRes(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnTransFinished(int iRunLogicRetCode);
public:
    virtual int HandleGetBaseInfoMsgParam(const google::protobuf::Message *pCSMsgReq);
    virtual int ProPhoneAutoCodeInfoReq(const proto_login::Proto_CS_Player_PhoneAutoCodeReq *pCSMsgReq);
    virtual int ProPhoneCheckCodeInfoReq(const proto_login::Proto_CS_Player_CheckPhoneCodeReq *pCSMsgReq);
    virtual int ProBindPhoneReq(const proto_login::Proto_CS_Player_BindPhoneReq *pCSMsgReq);
    virtual int ProPhoneAutoCodeRes();
    virtual int ProGetBaseInfoReq();
    virtual int HandleGetBaseInfoRes(NFUserDetail *pUserDetail);
    virtual int ProGetBaseInfoRes(const storesvr_sqldata::storesvr_selobj_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code);
    virtual int ProInsertBaseInfoRes(const storesvr_sqldata::storesvr_ins_res* pSelRsp, uint32_t cmd, uint32_t table_id, uint32_t err_code);
private:
    uint64_t m_phoneNum;
    uint32_t m_codeType;
    NFSizeString<64> m_nickname;
    DECLARE_IDCREATE(NFPlayerBindPhoneTrans)
};