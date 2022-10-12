#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/guild_s.h"

#define MAX_GUILD_HOUSE_NUM 200

class GuildHouseDesc : public NFIDescStore
{
public:
	GuildHouseDesc(NFIPluginManager* pPluginManager);
	virtual ~GuildHouseDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::guildhouse_s* GetDesc(int id) const;
	proto_ff_s::guildhouse_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::guildhouse_s, MAX_GUILD_HOUSE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::guildhouse_s, MAX_GUILD_HOUSE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::guildhouse_s, guildhouse, MAX_GUILD_HOUSE_NUM);
DECLARE_IDCREATE(GuildHouseDesc);
};
