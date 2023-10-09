#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/guild_s.h"

#define MAX_GUILD_CONSTANT_NUM 20

class GuildConstantDesc : public NFIDescStore
{
public:
	GuildConstantDesc();
	virtual ~GuildConstantDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GuildConstant_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildConstant_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildConstant_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildConstant_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(GuildConstantDesc, proto_ff_s::E_GuildConstant_s, E_GuildConstant, MAX_GUILD_CONSTANT_NUM);
DECLARE_IDCREATE(GuildConstantDesc);
};
