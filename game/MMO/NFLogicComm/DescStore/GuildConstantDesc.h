#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_CONSTANT_NUM 128

class GuildConstantDesc : public NFIDescStore
{
public:
	GuildConstantDesc();
	virtual ~GuildConstantDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GuildConstant_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildConstant_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildConstant_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildConstant_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GuildConstantDesc, proto_ff_s::E_GuildConstant_s, E_GuildConstant, MAX_GUILD_CONSTANT_NUM);
DECLARE_IDCREATE_GLOBAL(GuildConstantDesc);
};
