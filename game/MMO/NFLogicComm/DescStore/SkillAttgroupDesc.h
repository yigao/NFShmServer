#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Skill_s.h"

#define MAX_SKILL_ATTGROUP_NUM 2

class SkillAttgroupDesc : public NFIDescTemplate<SkillAttgroupDesc, proto_ff_s::E_SkillAttgroup_s, EOT_CONST_SKILL_ATTGROUP_DESC_ID, MAX_SKILL_ATTGROUP_NUM>
{
public:
	SkillAttgroupDesc();
	virtual ~SkillAttgroupDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
