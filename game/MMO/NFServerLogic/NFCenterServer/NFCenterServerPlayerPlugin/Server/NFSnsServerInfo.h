// -------------------------------------------------------------------------
//    @FileName         :    NFSnsServerInfo.h
//    @Author           :    gaoyi
//    @Date             :    23-10-23
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsServerInfo
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFSnsServerInfo
{
public:
    NFSnsServerInfo();

    virtual ~NFSnsServerInfo();

    int CreateInit();

    int ResumeInit();

public:
    uint32_t m_busId;
};