// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetRoleDetail.h
//    @Author           :    gaoyi
//    @Date             :    22-11-5
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransGetRoleDetail
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "storesvr_sqldata.pb.h"
#include "NFComm/NFShmCore/NFTransBase.h"

class NFTransGetPlayerDetail : public NFTransBase
{
public:
    NFTransGetPlayerDetail();

    virtual ~NFTransGetPlayerDetail();

    int CreateInit();

    int ResumeInit();
public:
    int QueryRole(uint64_t playerId);

    int OnTransFinished(int iRunLogicRetCode);
private:
    uint64_t m_cid;
DECLARE_IDCREATE(NFTransGetPlayerDetail)
};