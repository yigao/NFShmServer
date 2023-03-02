#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/guild_s.h"

#define MAX_GUILD_POSITION_NUM 20

class GuildPositionDesc : public NFIDescStore
{
public:
	GuildPositionDesc();
	virtual ~GuildPositionDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GuildPosition_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildPosition_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildPosition_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildPosition_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_GuildPosition_s, E_GuildPosition, MAX_GUILD_POSITION_NUM);
DECLARE_IDCREATE(GuildPositionDesc);
};
