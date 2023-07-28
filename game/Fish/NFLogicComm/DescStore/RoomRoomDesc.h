#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/room_s.h"

#define MAX_ROOM_ROOM_NUM 20

class RoomRoomDesc : public NFIDescStore
{
public:
	RoomRoomDesc();
	virtual ~RoomRoomDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_RoomRoom_s* GetDesc(int64_t id) const;
	proto_ff_s::E_RoomRoom_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_RoomRoom_s* GetDescByIndex(int index) const;
	proto_ff_s::E_RoomRoom_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(RoomRoomDesc, proto_ff_s::E_RoomRoom_s, E_RoomRoom, MAX_ROOM_ROOM_NUM);
DECLARE_IDCREATE(RoomRoomDesc);
};
