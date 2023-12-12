#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Skill_s.h"

#define MAX_SKILL_BUFF_NUM 2048

class SkillBuffDesc : public NFIDescTemplate<SkillBuffDesc, proto_ff_s::E_SkillBuff_s, EOT_CONST_SKILL_BUFF_DESC_ID, MAX_SKILL_BUFF_NUM>
{
public:
	SkillBuffDesc();
	virtual ~SkillBuffDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
