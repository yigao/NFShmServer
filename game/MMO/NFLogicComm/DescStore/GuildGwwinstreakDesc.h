#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_GWWINSTREAK_NUM 32

class GuildGwwinstreakDesc : public NFIDescStore
{
public:
	GuildGwwinstreakDesc();
	virtual ~GuildGwwinstreakDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GuildGwwinstreak_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildGwwinstreak_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildGwwinstreak_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildGwwinstreak_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GuildGwwinstreakDesc, proto_ff_s::E_GuildGwwinstreak_s, E_GuildGwwinstreak, MAX_GUILD_GWWINSTREAK_NUM);
DECLARE_IDCREATE(GuildGwwinstreakDesc);
};
