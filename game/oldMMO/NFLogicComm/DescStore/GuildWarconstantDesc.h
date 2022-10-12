#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/guild_s.h"

#define MAX_GUILD_WARCONSTANT_NUM 20

class GuildWarconstantDesc : public NFIDescStore
{
public:
	GuildWarconstantDesc(NFIPluginManager* pPluginManager);
	virtual ~GuildWarconstantDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::guildwarconstant_s* GetDesc(int id) const;
	proto_ff_s::guildwarconstant_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::guildwarconstant_s, MAX_GUILD_WARCONSTANT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::guildwarconstant_s, MAX_GUILD_WARCONSTANT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::guildwarconstant_s, guildwarconstant, MAX_GUILD_WARCONSTANT_NUM);
DECLARE_IDCREATE(GuildWarconstantDesc);
};
