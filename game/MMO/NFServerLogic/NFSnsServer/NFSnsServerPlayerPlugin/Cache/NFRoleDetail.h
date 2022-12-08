// -------------------------------------------------------------------------
//    @FileName         :    NFRoleDetail.h
//    @Author           :    gaoyi
//    @Date             :    22-11-5
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleDetail
//
// -------------------------------------------------------------------------

#pragma once


#include <DBProto2.pb.h>
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFRoleDetail : public NFShmObj
{
public:
    NFRoleDetail();

    virtual ~NFRoleDetail();

    int CreateInit();

    int ResumeInit();

public:
    uint64_t GetRoleId() const;

    void SetRoleId(uint64_t roleId);

public:
    bool IsInited() const;

    void SetIsInited(bool isInited);

public:
    bool CanDelete();

public:
    int Init(const proto_ff::RoleDBSnsDetail &data);

private:
    /**
     * @brief
     */
    bool m_isInited;

    /**
     * @brief
     */
    uint64_t m_roleId;
DECLARE_IDCREATE(NFRoleDetail)
};