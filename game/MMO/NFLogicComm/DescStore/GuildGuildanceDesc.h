#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/guild_s.h"

#define MAX_GUILD_GUILDANCE_NUM 20

class GuildGuildanceDesc : public NFIDescStore
{
public:
	GuildGuildanceDesc(NFIPluginManager* pPluginManager);
	virtual ~GuildGuildanceDesc();
	const proto_ff_s::guildguildance_s* GetDesc(int id) const;
	proto_ff_s::guildguildance_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::guildguildance_s, MAX_GUILD_GUILDANCE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::guildguildance_s, MAX_GUILD_GUILDANCE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::guildguildance_s, guildguildance, MAX_GUILD_GUILDANCE_NUM);
DECLARE_IDCREATE(GuildGuildanceDesc);
};
