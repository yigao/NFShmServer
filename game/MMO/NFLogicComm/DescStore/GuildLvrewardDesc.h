#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_LVREWARD_NUM 512

class GuildLvrewardDesc : public NFIDescTemplate<GuildLvrewardDesc, proto_ff_s::E_GuildLvreward_s, EOT_CONST_GUILD_LVREWARD_DESC_ID, MAX_GUILD_LVREWARD_NUM>
{
public:
	GuildLvrewardDesc();
	virtual ~GuildLvrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
