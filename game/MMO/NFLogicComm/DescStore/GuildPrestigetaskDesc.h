#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_PRESTIGETASK_NUM 16

class GuildPrestigetaskDesc : public NFIDescTemplate<GuildPrestigetaskDesc, proto_ff_s::E_GuildPrestigetask_s, EOT_CONST_GUILD_PRESTIGETASK_DESC_ID, MAX_GUILD_PRESTIGETASK_NUM>
{
public:
	GuildPrestigetaskDesc();
	virtual ~GuildPrestigetaskDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
