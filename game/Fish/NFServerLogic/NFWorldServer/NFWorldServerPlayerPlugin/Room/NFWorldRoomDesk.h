// -------------------------------------------------------------------------
//    @FileName         :    NFWorldRoomDesk.h
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldRoomDesk
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFWorldRoomDesk
{
public:
    NFWorldRoomDesk();

    virtual ~NFWorldRoomDesk();

    int CreateInit();

    int ResumeInit();
};