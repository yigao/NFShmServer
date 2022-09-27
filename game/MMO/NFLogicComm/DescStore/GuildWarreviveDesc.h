#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/guild_s.h"

#define MAX_GUILD_WARREVIVE_NUM 20

class GuildWarreviveDesc : public NFIDescStore
{
public:
	GuildWarreviveDesc(NFIPluginManager* pPluginManager);
	virtual ~GuildWarreviveDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::guildwarrevive_s* GetDesc(int id) const;
	proto_ff_s::guildwarrevive_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::guildwarrevive_s, MAX_GUILD_WARREVIVE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::guildwarrevive_s, MAX_GUILD_WARREVIVE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::guildwarrevive_s, guildwarrevive, MAX_GUILD_WARREVIVE_NUM);
DECLARE_IDCREATE(GuildWarreviveDesc);
};
