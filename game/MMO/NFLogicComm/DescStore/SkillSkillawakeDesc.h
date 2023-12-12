#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Skill_s.h"

#define MAX_SKILL_SKILLAWAKE_NUM 128

class SkillSkillawakeDesc : public NFIDescTemplate<SkillSkillawakeDesc, proto_ff_s::E_SkillSkillawake_s, EOT_CONST_SKILL_SKILLAWAKE_DESC_ID, MAX_SKILL_SKILLAWAKE_NUM>
{
public:
	SkillSkillawakeDesc();
	virtual ~SkillSkillawakeDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
