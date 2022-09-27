#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/guild_s.h"

#define MAX_GUILD_CONSTANT_NUM 20

class GuildConstantDesc : public NFIDescStore
{
public:
	GuildConstantDesc(NFIPluginManager* pPluginManager);
	virtual ~GuildConstantDesc();
	const proto_ff_s::guildconstant_s* GetDesc(int id) const;
	proto_ff_s::guildconstant_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::guildconstant_s, MAX_GUILD_CONSTANT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::guildconstant_s, MAX_GUILD_CONSTANT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::guildconstant_s, guildconstant, MAX_GUILD_CONSTANT_NUM);
DECLARE_IDCREATE(GuildConstantDesc);
};
