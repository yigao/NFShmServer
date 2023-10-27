#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Skill_s.h"

#define MAX_SKILL_SKILLUP_NUM 4096

class SkillSkillupDesc : public NFIDescTemplate<SkillSkillupDesc, proto_ff_s::E_SkillSkillup_s, EOT_CONST_SKILL_SKILLUP_DESC_ID, MAX_SKILL_SKILLUP_NUM>
{
public:
	SkillSkillupDesc();
	virtual ~SkillSkillupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
