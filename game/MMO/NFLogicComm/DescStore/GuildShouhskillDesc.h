#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_SHOUHSKILL_NUM 8

class GuildShouhskillDesc : public NFIDescStore
{
public:
	GuildShouhskillDesc();
	virtual ~GuildShouhskillDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GuildShouhskill_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildShouhskill_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildShouhskill_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildShouhskill_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GuildShouhskillDesc, proto_ff_s::E_GuildShouhskill_s, E_GuildShouhskill, MAX_GUILD_SHOUHSKILL_NUM);
DECLARE_IDCREATE(GuildShouhskillDesc);
};
