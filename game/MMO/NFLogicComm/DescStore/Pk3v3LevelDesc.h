#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Pk3v3_s.h"

#define MAX_PK3V3_LEVEL_NUM 32

class Pk3v3LevelDesc : public NFIDescStore
{
public:
	Pk3v3LevelDesc();
	virtual ~Pk3v3LevelDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_Pk3v3Level_s* GetDesc(int64_t id) const;
	proto_ff_s::E_Pk3v3Level_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_Pk3v3Level_s* GetDescByIndex(int index) const;
	proto_ff_s::E_Pk3v3Level_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(Pk3v3LevelDesc, proto_ff_s::E_Pk3v3Level_s, E_Pk3v3Level, MAX_PK3V3_LEVEL_NUM);
DECLARE_IDCREATE(Pk3v3LevelDesc);
};
