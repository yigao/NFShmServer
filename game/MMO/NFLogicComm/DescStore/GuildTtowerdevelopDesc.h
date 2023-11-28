#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_TTOWERDEVELOP_NUM 64

class GuildTtowerdevelopDesc : public NFIDescTemplate<GuildTtowerdevelopDesc, proto_ff_s::E_GuildTtowerdevelop_s, EOT_CONST_GUILD_TTOWERDEVELOP_DESC_ID, MAX_GUILD_TTOWERDEVELOP_NUM>
{
public:
	GuildTtowerdevelopDesc();
	virtual ~GuildTtowerdevelopDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
