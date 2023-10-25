#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_PACKET_NUM 128

class GuildPacketDesc : public NFIDescStore
{
public:
	GuildPacketDesc();
	virtual ~GuildPacketDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GuildPacket_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildPacket_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildPacket_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildPacket_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GuildPacketDesc, proto_ff_s::E_GuildPacket_s, E_GuildPacket, MAX_GUILD_PACKET_NUM);
DECLARE_IDCREATE_GLOBAL(GuildPacketDesc);
};
