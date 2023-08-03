// -------------------------------------------------------------------------
//    @FileName         :    NFIGamePlayer.h
//    @Author           :    gaoyi
//    @Date             :    23-8-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFIGamePlayer
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFIGamePlayer : public NFShmObj
{
public:
    NFIGamePlayer();

    virtual ~NFIGamePlayer();

    int CreateInit();

    int ResumeInit();
};