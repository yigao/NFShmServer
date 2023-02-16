#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
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
	const proto_ff_s::E_GuildConstant_s* GetDesc(int id) const;
	proto_ff_s::E_GuildConstant_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_GuildConstant_s, E_GuildConstant, MAX_GUILD_CONSTANT_NUM);
DECLARE_IDCREATE(GuildConstantDesc);
};
