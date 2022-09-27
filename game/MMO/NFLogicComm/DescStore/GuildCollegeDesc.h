#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/guild_s.h"

#define MAX_GUILD_COLLEGE_NUM 6000

class GuildCollegeDesc : public NFIDescStore
{
public:
	GuildCollegeDesc(NFIPluginManager* pPluginManager);
	virtual ~GuildCollegeDesc();
	const proto_ff_s::guildcollege_s* GetDesc(int id) const;
	proto_ff_s::guildcollege_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::guildcollege_s, MAX_GUILD_COLLEGE_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::guildcollege_s, MAX_GUILD_COLLEGE_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::guildcollege_s, guildcollege, MAX_GUILD_COLLEGE_NUM);
DECLARE_IDCREATE(GuildCollegeDesc);
};
