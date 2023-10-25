#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_PRESTIGETASK_NUM 8

class GuildPrestigetaskDesc : public NFIDescStore
{
public:
	GuildPrestigetaskDesc();
	virtual ~GuildPrestigetaskDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GuildPrestigetask_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildPrestigetask_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildPrestigetask_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildPrestigetask_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GuildPrestigetaskDesc, proto_ff_s::E_GuildPrestigetask_s, E_GuildPrestigetask, MAX_GUILD_PRESTIGETASK_NUM);
DECLARE_IDCREATE_GLOBAL(GuildPrestigetaskDesc);
};
