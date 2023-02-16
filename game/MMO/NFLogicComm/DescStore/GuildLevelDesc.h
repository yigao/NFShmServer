#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/guild_s.h"

#define MAX_GUILD_LEVEL_NUM 20

class GuildLevelDesc : public NFIDescStore
{
public:
	GuildLevelDesc();
	virtual ~GuildLevelDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GuildLevel_s* GetDesc(int id) const;
	proto_ff_s::E_GuildLevel_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_GuildLevel_s, E_GuildLevel, MAX_GUILD_LEVEL_NUM);
DECLARE_IDCREATE(GuildLevelDesc);
};
