#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/skill_s.h"

#define MAX_SKILL_SKILL_NUM 300

class SkillSkillDesc : public NFIDescStore
{
public:
	SkillSkillDesc();
	virtual ~SkillSkillDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_SkillSkill_s* GetDesc(int64_t id) const;
	proto_ff_s::E_SkillSkill_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_SkillSkill_s* GetDescByIndex(int index) const;
	proto_ff_s::E_SkillSkill_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(SkillSkillDesc, proto_ff_s::E_SkillSkill_s, E_SkillSkill, MAX_SKILL_SKILL_NUM);
DECLARE_IDCREATE(SkillSkillDesc);
};
