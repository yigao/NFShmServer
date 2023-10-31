#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Fish_s.h"

#define MAX_FISH_GUNVALUE_NUM 256

#define MAX_COM_INDEX_FISH_GUNVALUE_GAMEID_NUM 64

#define UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_GAMEID_NUM 8

#define MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM 64

#define UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM 8

#define MAX_COM_INDEX_FISH_GUNVALUE_GAMEID_NUM 64

#define UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_GAMEID_NUM 8

#define MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM 64

#define UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM 8

#define MAX_COM_INDEX_FISH_GUNVALUE_GUNID_NUM 32

#define UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_GUNID_NUM 16

struct FishGunvalueGameidRoomid
{
	FishGunvalueGameidRoomid()
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
		m_gunId=0;
		return 0;
	}
	int ResumeInit()
	{
		return 0;
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


class FishGunvalueDesc : public NFIDescTemplate<FishGunvalueDesc, proto_ff_s::E_FishGunvalue_s, EOT_CONST_FISH_GUNVALUE_DESC_ID, MAX_FISH_GUNVALUE_NUM>
{
public:
	FishGunvalueDesc();
	virtual ~FishGunvalueDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
	std::vector<const proto_ff_s::E_FishGunvalue_s*> GetDescByGameidRoomid(int64_t Gameid, int64_t Roomid);
	const proto_ff_s::E_FishGunvalue_s* GetDescByGameidRoomidGunid(int64_t Gameid, int64_t Roomid, int64_t Gunid);
private:
	NFShmHashMap<FishGunvalueGameidRoomid ,NFShmVector<uint32_t, MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM>, UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_GAMEID_NUM*UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM> m_GameidRoomidComIndexMap;
	NFShmHashMap<FishGunvalueGameidRoomidGunid ,uint32_t, UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_GAMEID_NUM*UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM*UNIQUE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_GUNID_NUM> m_GameidRoomidGunidComIndexMap;
};
