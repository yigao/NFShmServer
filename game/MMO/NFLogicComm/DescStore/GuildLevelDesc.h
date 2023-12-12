#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_LEVEL_NUM 16

class GuildLevelDesc : public NFIDescTemplate<GuildLevelDesc, proto_ff_s::E_GuildLevel_s, EOT_CONST_GUILD_LEVEL_DESC_ID, MAX_GUILD_LEVEL_NUM>
{
public:
	GuildLevelDesc();
	virtual ~GuildLevelDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
