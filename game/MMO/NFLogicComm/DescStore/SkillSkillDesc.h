#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Skill_s.h"

#define MAX_SKILL_SKILL_NUM 4096

class SkillSkillDesc : public NFIDescTemplate<SkillSkillDesc, proto_ff_s::E_SkillSkill_s, EOT_CONST_SKILL_SKILL_DESC_ID, MAX_SKILL_SKILL_NUM>
{
public:
	SkillSkillDesc();
	virtual ~SkillSkillDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
