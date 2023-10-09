#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_LVREWARD_NUM 512

class GuildLvrewardDesc : public NFIDescStore
{
public:
	GuildLvrewardDesc();
	virtual ~GuildLvrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GuildLvreward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildLvreward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildLvreward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildLvreward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GuildLvrewardDesc, proto_ff_s::E_GuildLvreward_s, E_GuildLvreward, MAX_GUILD_LVREWARD_NUM);
DECLARE_IDCREATE(GuildLvrewardDesc);
};
