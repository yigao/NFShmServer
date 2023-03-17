#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/guild_s.h"

#define MAX_GUILD_SALARY_NUM 20

class GuildSalaryDesc : public NFIDescStore
{
public:
	GuildSalaryDesc();
	virtual ~GuildSalaryDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_GuildSalary_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildSalary_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildSalary_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildSalary_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(GuildSalaryDesc, proto_ff_s::E_GuildSalary_s, E_GuildSalary, MAX_GUILD_SALARY_NUM);
DECLARE_IDCREATE(GuildSalaryDesc);
};
