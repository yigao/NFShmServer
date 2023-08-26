#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/Fish_s.h"

#define MAX_FISH_ROOM_NUM 8

#define MAX_COM_INDEX_FISH_ROOM_GAMEID_NUM 8

#define UNIQUE_KEY_MAX_COM_INDEX_FISH_ROOM_GAMEID_NUM 2

#define MAX_COM_INDEX_FISH_ROOM_ROOMID_NUM 2

#define UNIQUE_KEY_MAX_COM_INDEX_FISH_ROOM_ROOMID_NUM 8

class FishRoomDesc : public NFIDescStore
{
public:
	FishRoomDesc();
	virtual ~FishRoomDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_FishRoom_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FishRoom_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FishRoom_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FishRoom_s* GetDescByIndex(int index);
public:
	const proto_ff_s::E_FishRoom_s* GetDescByGameidRoomid(int64_t Gameid, int64_t Roomid);
private:
	NFShmHashMap<int64_t, NFShmHashMap<int64_t, uint32_t, UNIQUE_KEY_MAX_COM_INDEX_FISH_ROOM_ROOMID_NUM>, UNIQUE_KEY_MAX_COM_INDEX_FISH_ROOM_GAMEID_NUM> m_GameidRoomidComIndexMap;
IMPL_RES_HASH_DESC(FishRoomDesc, proto_ff_s::E_FishRoom_s, E_FishRoom, MAX_FISH_ROOM_NUM);
DECLARE_IDCREATE(FishRoomDesc);
};
