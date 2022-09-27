#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/guild_s.h"

#define MAX_GUILD_GIFT_NUM 40

class GuildGiftDesc : public NFIDescStore
{
public:
	GuildGiftDesc(NFIPluginManager* pPluginManager);
	virtual ~GuildGiftDesc();
	const proto_ff_s::guildgift_s* GetDesc(int id) const;
	proto_ff_s::guildgift_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::guildgift_s, MAX_GUILD_GIFT_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::guildgift_s, MAX_GUILD_GIFT_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::guildgift_s, guildgift, MAX_GUILD_GIFT_NUM);
DECLARE_IDCREATE(GuildGiftDesc);
};
