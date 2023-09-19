#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/guild_s.h"

#define MAX_GUILD_PACKET_NUM 80

class GuildPacketDesc : public NFIDescStore
{
public:
	GuildPacketDesc();
	virtual ~GuildPacketDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GuildPacket_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildPacket_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildPacket_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildPacket_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(GuildPacketDesc, proto_ff_s::E_GuildPacket_s, E_GuildPacket, MAX_GUILD_PACKET_NUM);
DECLARE_IDCREATE(GuildPacketDesc);
};
