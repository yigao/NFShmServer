#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Skill_s.h"

#define MAX_SKILL_BUFFUP_NUM 512

class SkillBuffupDesc : public NFIDescTemplate<SkillBuffupDesc, proto_ff_s::E_SkillBuffup_s, EOT_CONST_SKILL_BUFFUP_DESC_ID, MAX_SKILL_BUFFUP_NUM>
{
public:
	SkillBuffupDesc();
	virtual ~SkillBuffupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
