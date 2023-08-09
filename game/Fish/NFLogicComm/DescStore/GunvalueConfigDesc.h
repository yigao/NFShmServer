#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/GunValue_s.h"

#define MAX_GUNVALUE_CONFIG_NUM 64

#define MAX_COM_INDEX_GUNVALUE_CONFIG_GAMEID_NUM 2

#define ONE_KEY_MAX_COM_INDEX_GUNVALUE_CONFIG_GAMEID_NUM 64

#define MAX_COM_INDEX_GUNVALUE_CONFIG_ROOMID_NUM 8

#define ONE_KEY_MAX_COM_INDEX_GUNVALUE_CONFIG_ROOMID_NUM 16

#define MAX_COM_INDEX_GUNVALUE_CONFIG_GUNID_NUM 16

#define ONE_KEY_MAX_COM_INDEX_GUNVALUE_CONFIG_GUNID_NUM 8

class GunvalueConfigDesc : public NFIDescStore
{
public:
	GunvalueConfigDesc();
	virtual ~GunvalueConfigDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GunvalueConfig_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GunvalueConfig_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GunvalueConfig_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GunvalueConfig_s* GetDescByIndex(int index);
public:
	const proto_ff_s::E_GunvalueConfig_s* GetDescByGameidRoomidGunid(int64_t Gameid, int64_t Roomid, int64_t Gunid);
private:
	NFShmHashMap<int64_t, NFShmHashMap<int64_t, NFShmHashMap<int64_t, uint32_t, MAX_COM_INDEX_GUNVALUE_CONFIG_GUNID_NUM>, MAX_COM_INDEX_GUNVALUE_CONFIG_ROOMID_NUM>, MAX_COM_INDEX_GUNVALUE_CONFIG_GAMEID_NUM> m_GameidRoomidGunidComIndexMap;
IMPL_RES_HASH_DESC(GunvalueConfigDesc, proto_ff_s::E_GunvalueConfig_s, E_GunvalueConfig, MAX_GUNVALUE_CONFIG_NUM);
DECLARE_IDCREATE(GunvalueConfigDesc);
};
