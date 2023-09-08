#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Fish_s.h"

#define MAX_FISH_ROOM_NUM 8

#define MAX_INDEX_FISH_ROOM_GAMEID_NUM 8

#define UNIQUE_KEY_MAX_INDEX_FISH_ROOM_GAMEID_NUM 2

#define MAX_COM_INDEX_FISH_ROOM_GAMEID_NUM 8

#define UNIQUE_KEY_MAX_COM_INDEX_FISH_ROOM_GAMEID_NUM 2

#define MAX_COM_INDEX_FISH_ROOM_ROOMID_NUM 2

#define UNIQUE_KEY_MAX_COM_INDEX_FISH_ROOM_ROOMID_NUM 8

struct FishRoomGameidRoomid
{
	FishRoomGameidRoomid()
	{
		m_gameId=0;
		m_roomId=0;
	}
	int64_t m_gameId;
	int64_t m_roomId;
	bool operator==(const FishRoomGameidRoomid& data) const
	{
		 return m_gameId==data.m_gameId && m_roomId==data.m_roomId;
	}
};

namespace std
{
	template<>
	struct hash<FishRoomGameidRoomid>
	{
		size_t operator()(const FishRoomGameidRoomid& data) const
		{
			return NFHash::hash_combine(data.m_gameId,data.m_roomId);
		}
	};
}


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
	std::vector<const proto_ff_s::E_FishRoom_s*> GetDescByGameid(int64_t Gameid) const;
	const proto_ff_s::E_FishRoom_s* GetDescByGameidRoomid(int64_t Gameid, int64_t Roomid);
private:
	NFShmHashMap<int64_t, NFShmVector<uint32_t, UNIQUE_KEY_MAX_INDEX_FISH_ROOM_GAMEID_NUM>,MAX_INDEX_FISH_ROOM_GAMEID_NUM> m_GameidIndexMap;
	NFShmHashMap<FishRoomGameidRoomid ,uint32_t, UNIQUE_KEY_MAX_COM_INDEX_FISH_ROOM_GAMEID_NUM*UNIQUE_KEY_MAX_COM_INDEX_FISH_ROOM_ROOMID_NUM> m_GameidRoomidComIndexMap;
IMPL_RES_HASH_DESC(FishRoomDesc, proto_ff_s::E_FishRoom_s, E_FishRoom, MAX_FISH_ROOM_NUM);
DECLARE_IDCREATE(FishRoomDesc);
};
