#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_COLLEGE_NUM 16384

class GuildCollegeDesc : public NFIDescTemplate<GuildCollegeDesc, proto_ff_s::E_GuildCollege_s, EOT_CONST_GUILD_COLLEGE_DESC_ID, MAX_GUILD_COLLEGE_NUM>
{
public:
	GuildCollegeDesc();
	virtual ~GuildCollegeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
