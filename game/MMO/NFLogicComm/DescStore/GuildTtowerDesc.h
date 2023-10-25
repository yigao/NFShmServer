#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_TTOWER_NUM 128

class GuildTtowerDesc : public NFIDescStore
{
public:
	GuildTtowerDesc();
	virtual ~GuildTtowerDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GuildTtower_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildTtower_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildTtower_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildTtower_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GuildTtowerDesc, proto_ff_s::E_GuildTtower_s, E_GuildTtower, MAX_GUILD_TTOWER_NUM);
DECLARE_IDCREATE_GLOBAL(GuildTtowerDesc);
};
