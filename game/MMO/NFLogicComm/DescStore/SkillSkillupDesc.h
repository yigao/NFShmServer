#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/skill_s.h"

#define MAX_SKILL_SKILLUP_NUM 140

class SkillSkillupDesc : public NFIDescStore
{
public:
	SkillSkillupDesc();
	virtual ~SkillSkillupDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_SkillSkillup_s* GetDesc(int id) const;
	proto_ff_s::E_SkillSkillup_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_SkillSkillup_s, skillskillUp, MAX_SKILL_SKILLUP_NUM);
DECLARE_IDCREATE(SkillSkillupDesc);
};
