// -------------------------------------------------------------------------
//    @FileName         :    NFWorldRoomPlayer.h
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldRoomPlayer
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFWorldRoomPlayer
{
public:
    NFWorldRoomPlayer();

    virtual ~NFWorldRoomPlayer();

    int CreateInit();

    int ResumeInit();
public:
    uint64_t m_playerId;
    uint32_t m_deskId;
};