#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_GWWINSTREAK_NUM 32

class GuildGwwinstreakDesc : public NFIDescTemplate<GuildGwwinstreakDesc, proto_ff_s::E_GuildGwwinstreak_s, EOT_CONST_GUILD_GWWINSTREAK_DESC_ID, MAX_GUILD_GWWINSTREAK_NUM>
{
public:
	GuildGwwinstreakDesc();
	virtual ~GuildGwwinstreakDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
