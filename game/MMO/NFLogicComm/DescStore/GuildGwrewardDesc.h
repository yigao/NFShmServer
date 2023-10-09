#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_GWREWARD_NUM 128

class GuildGwrewardDesc : public NFIDescStore
{
public:
	GuildGwrewardDesc();
	virtual ~GuildGwrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GuildGwreward_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildGwreward_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildGwreward_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildGwreward_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GuildGwrewardDesc, proto_ff_s::E_GuildGwreward_s, E_GuildGwreward, MAX_GUILD_GWREWARD_NUM);
DECLARE_IDCREATE(GuildGwrewardDesc);
};
