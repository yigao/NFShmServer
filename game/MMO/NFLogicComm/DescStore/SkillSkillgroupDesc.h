#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Skill_s.h"

#define MAX_SKILL_SKILLGROUP_NUM 2

class SkillSkillgroupDesc : public NFIDescStore
{
public:
	SkillSkillgroupDesc();
	virtual ~SkillSkillgroupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_SkillSkillgroup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_SkillSkillgroup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_SkillSkillgroup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_SkillSkillgroup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(SkillSkillgroupDesc, proto_ff_s::E_SkillSkillgroup_s, E_SkillSkillgroup, MAX_SKILL_SKILLGROUP_NUM);
DECLARE_IDCREATE(SkillSkillgroupDesc);
};
