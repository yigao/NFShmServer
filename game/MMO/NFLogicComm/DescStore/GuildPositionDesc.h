#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_POSITION_NUM 8

class GuildPositionDesc : public NFIDescTemplate<GuildPositionDesc, proto_ff_s::E_GuildPosition_s, EOT_CONST_GUILD_POSITION_DESC_ID, MAX_GUILD_POSITION_NUM>
{
public:
	GuildPositionDesc();
	virtual ~GuildPositionDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
