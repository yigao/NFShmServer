#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_SALARY_NUM 8

class GuildSalaryDesc : public NFIDescTemplate<GuildSalaryDesc, proto_ff_s::E_GuildSalary_s, EOT_CONST_GUILD_SALARY_DESC_ID, MAX_GUILD_SALARY_NUM>
{
public:
	GuildSalaryDesc();
	virtual ~GuildSalaryDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
