#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Skill_s.h"

#define MAX_SKILL_SKILLGROUP_NUM 2

class SkillSkillgroupDesc : public NFIDescTemplate<SkillSkillgroupDesc, proto_ff_s::E_SkillSkillgroup_s, EOT_CONST_SKILL_SKILLGROUP_DESC_ID, MAX_SKILL_SKILLGROUP_NUM>
{
public:
	SkillSkillgroupDesc();
	virtual ~SkillSkillgroupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
