#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/guild_s.h"

#define MAX_GUILD_WARMORALE_NUM 20

class GuildWarmoraleDesc : public NFIDescStore
{
public:
	GuildWarmoraleDesc(NFIPluginManager* pPluginManager);
	virtual ~GuildWarmoraleDesc();
	const proto_ff_s::guildwarmorale_s* GetDesc(int id) const;
	proto_ff_s::guildwarmorale_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::guildwarmorale_s, MAX_GUILD_WARMORALE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::guildwarmorale_s, MAX_GUILD_WARMORALE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::guildwarmorale_s, guildwarmorale, MAX_GUILD_WARMORALE_NUM);
DECLARE_IDCREATE(GuildWarmoraleDesc);
};
