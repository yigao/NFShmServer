// -------------------------------------------------------------------------
//    @FileName         :    NFLoadCacheDataInfo.h
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoadCacheDataInfo
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFLoadCacheDataInfo
{
public:
    NFLoadCacheDataInfo();

    virtual ~NFLoadCacheDataInfo();

    int CreateInit();

    int ResumeInit();
public:
    uint32_t m_transId;
    uint64_t m_loadTime;
};