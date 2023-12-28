// -------------------------------------------------------------------------
//    @FileName         :    NFWorldRoom.h
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldRoom
//
// -------------------------------------------------------------------------

#pragma once

#include <NFLogicCommon/NFLogicShmTypeDefines.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFWorldRoomPlayer.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFLogicCommon/NFRoomDefine.h"
#include "NFWorldRoomDesk.h"
#include "NFLogicCommon/NFLogicCommon.h"

class NFWorldRoom : public NFShmObjTemplate<NFWorldRoom, EOT_NFWorldRoom_ID, NFShmObj>
{
public:
    NFWorldRoom();

    virtual ~NFWorldRoom();

    int CreateInit();

    int ResumeInit();
public:
    uint32_t m_id;
    uint32_t m_gameId;
    uint32_t m_roomId;
public:
    uint32_t m_busId;
public:
    NFShmHashMap<uint64_t, NFWorldRoomPlayer, MAX_ONE_ROOM_PLAYER_NUM> m_roomPlayers;
    NFShmHashMap<uint64_t, NFWorldRoomDesk, MAX_ONE_ROOM_DESK_NUM> m_roomDesks;
};