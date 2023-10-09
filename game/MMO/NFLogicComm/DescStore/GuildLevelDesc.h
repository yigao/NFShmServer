#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_LEVEL_NUM 16

class GuildLevelDesc : public NFIDescStore
{
public:
	GuildLevelDesc();
	virtual ~GuildLevelDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GuildLevel_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildLevel_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildLevel_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildLevel_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GuildLevelDesc, proto_ff_s::E_GuildLevel_s, E_GuildLevel, MAX_GUILD_LEVEL_NUM);
DECLARE_IDCREATE(GuildLevelDesc);
};
