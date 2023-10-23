// -------------------------------------------------------------------------
//    @FileName         :    NFLogicServerInfo.h
//    @Author           :    gaoyi
//    @Date             :    23-10-23
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicServerInfo
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFLogicServerInfo
{
public:
    NFLogicServerInfo();

    virtual ~NFLogicServerInfo();

    int CreateInit();

    int ResumeInit();

public:
    uint32_t m_busId;
    uint32_t m_roleNum;
};