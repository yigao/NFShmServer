#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Skill_s.h"

#define MAX_SKILL_SKILL_NUM 4096

class SkillSkillDesc : public NFIDescStore
{
public:
	SkillSkillDesc();
	virtual ~SkillSkillDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_SkillSkill_s* GetDesc(int64_t id) const;
	proto_ff_s::E_SkillSkill_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_SkillSkill_s* GetDescByIndex(int index) const;
	proto_ff_s::E_SkillSkill_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(SkillSkillDesc, proto_ff_s::E_SkillSkill_s, E_SkillSkill, MAX_SKILL_SKILL_NUM);
DECLARE_IDCREATE_GLOBAL(SkillSkillDesc);
};
