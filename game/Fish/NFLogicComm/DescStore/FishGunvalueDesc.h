#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/Fish_s.h"

#define MAX_FISH_GUNVALUE_NUM 64

#define MAX_COM_INDEX_FISH_GUNVALUE_GAMEID_NUM 64

#define UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_GAMEID_NUM 2

#define MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM 16

#define UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM 8

#define MAX_COM_INDEX_FISH_GUNVALUE_GAMEID_NUM 64

#define UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_GAMEID_NUM 2

#define MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM 16

#define UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM 8

#define MAX_COM_INDEX_FISH_GUNVALUE_GUNID_NUM 8

#define UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_GUNID_NUM 16

struct FishGunvalueGameidRoomid
{
	FishGunvalueGameidRoomid()
	{
		m_gameId=0;
		m_roomId=0;
	}
	int64_t m_gameId;
	int64_t m_roomId;
	bool operator==(const FishGunvalueGameidRoomid& data) const
	{
		 return m_gameId==data.m_gameId && m_roomId==data.m_roomId;
	}
};

namespace std
{
	template<>
	struct hash<FishGunvalueGameidRoomid>
	{
		size_t operator()(const FishGunvalueGameidRoomid& data) const
		{
			return NFHash::hash_combine(data.m_gameId,data.m_roomId);
		}
	};
}


struct FishGunvalueGameidRoomidGunid
{
	FishGunvalueGameidRoomidGunid()
	{
		m_gameId=0;
		m_roomId=0;
		m_gunId=0;
	}
	int64_t m_gameId;
	int64_t m_roomId;
	int64_t m_gunId;
	bool operator==(const FishGunvalueGameidRoomidGunid& data) const
	{
		 return m_gameId==data.m_gameId && m_roomId==data.m_roomId && m_gunId==data.m_gunId;
	}
};

namespace std
{
	template<>
	struct hash<FishGunvalueGameidRoomidGunid>
	{
		size_t operator()(const FishGunvalueGameidRoomidGunid& data) const
		{
			return NFHash::hash_combine(data.m_gameId,data.m_roomId,data.m_gunId);
		}
	};
}


class FishGunvalueDesc : public NFIDescStore
{
public:
	FishGunvalueDesc();
	virtual ~FishGunvalueDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_FishGunvalue_s* GetDesc(int64_t id) const;
	proto_ff_s::E_FishGunvalue_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_FishGunvalue_s* GetDescByIndex(int index) const;
	proto_ff_s::E_FishGunvalue_s* GetDescByIndex(int index);
public:
	std::vector<const proto_ff_s::E_FishGunvalue_s*> GetDescByGameidRoomid(int64_t Gameid, int64_t Roomid);
	const proto_ff_s::E_FishGunvalue_s* GetDescByGameidRoomidGunid(int64_t Gameid, int64_t Roomid, int64_t Gunid);
private:
	NFShmHashMap<FishGunvalueGameidRoomid ,NFShmVector<uint32_t, MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM>, UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_GAMEID_NUM*UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM> m_GameidRoomidComIndexMap;
	NFShmHashMap<FishGunvalueGameidRoomidGunid ,uint32_t, UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_GAMEID_NUM*UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM*UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_GUNID_NUM> m_GameidRoomidGunidComIndexMap;
IMPL_RES_HASH_DESC(FishGunvalueDesc, proto_ff_s::E_FishGunvalue_s, E_FishGunvalue, MAX_FISH_GUNVALUE_NUM);
DECLARE_IDCREATE(FishGunvalueDesc);
};
