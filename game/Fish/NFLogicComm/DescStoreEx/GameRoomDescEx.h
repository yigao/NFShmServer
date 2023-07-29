// -------------------------------------------------------------------------
//    @FileName         :    GameRoomDescEx.h
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    GameRoomDescEx
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "room_s.h"
#include "NFLogicCommon/NFRoomDefine.h"

class GameRoomDescEx : public NFIDescStore
{
public:
    GameRoomDescEx();

    virtual ~GameRoomDescEx();

    int CreateInit();

    int ResumeInit();

    virtual bool IsNeedReload();

    virtual int PrepareReload();
public:
    uint32_t GetDescId(uint32_t gameId, uint32_t roomId);
    const proto_ff_s::E_RoomRoom_s* GetDesc(uint32_t gameId, uint32_t roomId);
private:
    NFShmHashMap<uint32_t, NFShmHashMap<uint32_t, uint32_t, MAX_GAME_ROOM_NUM>, MAX_GAME_TYPE_NUM> m_roomIdMap;
IMPL_RES_SIMPLE_DESC(GameRoomDescEx);
DECLARE_IDCREATE(GameRoomDescEx)
};