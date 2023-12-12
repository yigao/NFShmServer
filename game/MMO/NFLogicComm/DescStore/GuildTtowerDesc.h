#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_TTOWER_NUM 128

class GuildTtowerDesc : public NFIDescTemplate<GuildTtowerDesc, proto_ff_s::E_GuildTtower_s, EOT_CONST_GUILD_TTOWER_DESC_ID, MAX_GUILD_TTOWER_NUM>
{
public:
	GuildTtowerDesc();
	virtual ~GuildTtowerDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
