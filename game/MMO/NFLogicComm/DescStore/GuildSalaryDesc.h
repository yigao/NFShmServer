#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Guild_s.h"

#define MAX_GUILD_SALARY_NUM 8

class GuildSalaryDesc : public NFIDescStore
{
public:
	GuildSalaryDesc();
	virtual ~GuildSalaryDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_GuildSalary_s* GetDesc(int64_t id) const;
	proto_ff_s::E_GuildSalary_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_GuildSalary_s* GetDescByIndex(int index) const;
	proto_ff_s::E_GuildSalary_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(GuildSalaryDesc, proto_ff_s::E_GuildSalary_s, E_GuildSalary, MAX_GUILD_SALARY_NUM);
DECLARE_IDCREATE(GuildSalaryDesc);
};
