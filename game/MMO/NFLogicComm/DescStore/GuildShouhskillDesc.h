#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_SHOUHSKILL_NUM 8

class GuildShouhskillDesc : public NFIDescTemplate<GuildShouhskillDesc, proto_ff_s::E_GuildShouhskill_s, EOT_CONST_GUILD_SHOUHSKILL_DESC_ID, MAX_GUILD_SHOUHSKILL_NUM>
{
public:
	GuildShouhskillDesc();
	virtual ~GuildShouhskillDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
