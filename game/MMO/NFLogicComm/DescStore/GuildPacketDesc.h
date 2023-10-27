#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_PACKET_NUM 128

class GuildPacketDesc : public NFIDescTemplate<GuildPacketDesc, proto_ff_s::E_GuildPacket_s, EOT_CONST_GUILD_PACKET_DESC_ID, MAX_GUILD_PACKET_NUM>
{
public:
	GuildPacketDesc();
	virtual ~GuildPacketDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
