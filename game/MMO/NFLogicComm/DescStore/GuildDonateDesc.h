#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_DONATE_NUM 4

class GuildDonateDesc : public NFIDescTemplate<GuildDonateDesc, proto_ff_s::E_GuildDonate_s, EOT_CONST_GUILD_DONATE_DESC_ID, MAX_GUILD_DONATE_NUM>
{
public:
	GuildDonateDesc();
	virtual ~GuildDonateDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
