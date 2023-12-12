#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Skill_s.h"

#define MAX_SKILL_SKILLADVANCE_NUM 128

class SkillSkilladvanceDesc : public NFIDescTemplate<SkillSkilladvanceDesc, proto_ff_s::E_SkillSkilladvance_s, EOT_CONST_SKILL_SKILLADVANCE_DESC_ID, MAX_SKILL_SKILLADVANCE_NUM>
{
public:
	SkillSkilladvanceDesc();
	virtual ~SkillSkilladvanceDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
