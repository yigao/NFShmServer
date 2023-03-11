#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/guild_s.h"

#define MAX_GUILD_PRESTIGETASK_NUM 20

class GuildPrestigetaskDesc : public NFIDescStore
{
public:
	GuildPrestigetaskDesc();
	virtual ~GuildPrestigetaskDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GuildPrestigetask_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildPrestigetask_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildPrestigetask_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildPrestigetask_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_GuildPrestigetask_s, E_GuildPrestigetask, MAX_GUILD_PRESTIGETASK_NUM);
DECLARE_IDCREATE(GuildPrestigetaskDesc);
};
