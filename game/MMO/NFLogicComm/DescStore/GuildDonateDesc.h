#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/guild_s.h"

#define MAX_GUILD_DONATE_NUM 20

class GuildDonateDesc : public NFIDescStore
{
public:
	GuildDonateDesc();
	virtual ~GuildDonateDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GuildDonate_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildDonate_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildDonate_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildDonate_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(GuildDonateDesc, proto_ff_s::E_GuildDonate_s, E_GuildDonate, MAX_GUILD_DONATE_NUM);
DECLARE_IDCREATE(GuildDonateDesc);
};
