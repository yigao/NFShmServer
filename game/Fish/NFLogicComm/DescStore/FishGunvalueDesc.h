#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/Fish_s.h"

#define MAX_FISH_GUNVALUE_NUM 64

#define MAX_COM_INDEX_FISH_GUNVALUE_GAMEID_NUM 4

#define ONE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_GAMEID_NUM 64

#define MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM 8

#define ONE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM 16

#define MAX_COM_INDEX_FISH_GUNVALUE_GUNID_NUM 16

#define ONE_KEY_MAX_COM_INDEX_FISH_GUNVALUE_GUNID_NUM 8

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
	const proto_ff_s::E_FishGunvalue_s* GetDescByGameidRoomidGunid(int64_t Gameid, int64_t Roomid, int64_t Gunid);
private:
	NFShmHashMap<int64_t, NFShmHashMap<int64_t, NFShmHashMap<int64_t, uint32_t, MAX_COM_INDEX_FISH_GUNVALUE_GUNID_NUM>, MAX_COM_INDEX_FISH_GUNVALUE_ROOMID_NUM>, MAX_COM_INDEX_FISH_GUNVALUE_GAMEID_NUM> m_GameidRoomidGunidComIndexMap;
IMPL_RES_HASH_DESC(FishGunvalueDesc, proto_ff_s::E_FishGunvalue_s, E_FishGunvalue, MAX_FISH_GUNVALUE_NUM);
DECLARE_IDCREATE(FishGunvalueDesc);
};
