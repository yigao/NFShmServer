// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetSnsUserSimple.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransGetSnsUserSimple.h
//
// -------------------------------------------------------------------------

#pragma once

#include <NFComm/NFKernelMessage/storesvr_sqldata.pb.h>
#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFShmCore/NFSizeString.h"

class NFTransGetSnsUserSimple : public NFTransBase {
public:
    NFTransGetSnsUserSimple();

    virtual ~NFTransGetSnsUserSimple();

    int CreateInit();

    int ResumeInit();

    int Init(uint64_t userId);

    virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq);

    virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id,
                               uint32_t seq, uint32_t err_code);

    int ProQueryRoleRes(const storesvr_sqldata::storesvr_selobj_res* pSelectRsp, uint32_t err_code, int iTransID);
public:
    int QueryUser(uint64_t userId);

    int OnTransFinished(int iRunLogicRetCode);
private:
    uint64_t m_userId;
DECLARE_IDCREATE(NFTransGetSnsUserSimple)
};