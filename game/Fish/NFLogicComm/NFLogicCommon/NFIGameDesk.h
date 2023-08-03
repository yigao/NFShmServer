// -------------------------------------------------------------------------
//    @FileName         :    NFIGameDesk.h
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFIGameDesk
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFIGameDesk : public NFShmObj
{
public:
    NFIGameDesk();

    virtual ~NFIGameDesk();

    int CreateInit();

    int ResumeInit();
};