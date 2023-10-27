#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_GWREWARD_NUM 128

class GuildGwrewardDesc : public NFIDescTemplate<GuildGwrewardDesc, proto_ff_s::E_GuildGwreward_s, EOT_CONST_GUILD_GWREWARD_DESC_ID, MAX_GUILD_GWREWARD_NUM>
{
public:
	GuildGwrewardDesc();
	virtual ~GuildGwrewardDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
