#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Fish_s.h"

#define MAX_FISH_ROOM_NUM 32

#define MAX_INDEX_FISH_ROOM_GAMEID_NUM 8

#define UNIQUE_KEY_MAX_INDEX_FISH_ROOM_GAMEID_NUM 8

#define MAX_COM_INDEX_FISH_ROOM_GAMEID_NUM 8

#define UNIQUE_KEY_MAX_COM_INDEX_FISH_ROOM_GAMEID_NUM 8

#define MAX_COM_INDEX_FISH_ROOM_ROOMID_NUM 8

#define UNIQUE_KEY_MAX_COM_INDEX_FISH_ROOM_ROOMID_NUM 8

struct FishRoomGameidRoomid
{
	FishRoomGameidRoomid()
	{
		if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
			CreateInit();
		}
		else {
			ResumeInit();
		}
	}
	int CreateInit()
	{
		m_gameId=0;
		m_roomId=0;
		return 0;
	}
	int ResumeInit()
	{
		return 0;
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


class FishRoomDesc : public NFIDescTemplate<FishRoomDesc, proto_ff_s::E_FishRoom_s, EOT_CONST_FISH_ROOM_DESC_ID, MAX_FISH_ROOM_NUM>
{
public:
	FishRoomDesc();
	virtual ~FishRoomDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	std::vector<const proto_ff_s::E_FishRoom_s*> GetDescByGameid(int64_t Gameid) const;
	const proto_ff_s::E_FishRoom_s* GetDescByGameidRoomid(int64_t Gameid, int64_t Roomid);
private:
	NFShmHashMap<int64_t, NFShmVector<uint32_t, MAX_INDEX_FISH_ROOM_GAMEID_NUM>,UNIQUE_KEY_MAX_INDEX_FISH_ROOM_GAMEID_NUM> m_GameidIndexMap;
	NFShmHashMap<FishRoomGameidRoomid ,uint32_t, UNIQUE_KEY_MAX_COM_INDEX_FISH_ROOM_GAMEID_NUM*UNIQUE_KEY_MAX_COM_INDEX_FISH_ROOM_ROOMID_NUM> m_GameidRoomidComIndexMap;
};
