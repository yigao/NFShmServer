#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_SKILL_NUM 256

class SoulSkillDesc : public NFIDescTemplate<SoulSkillDesc, proto_ff_s::E_SoulSkill_s, EOT_CONST_SOUL_SKILL_DESC_ID, MAX_SOUL_SKILL_NUM>
{
public:
	SoulSkillDesc();
	virtual ~SoulSkillDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
