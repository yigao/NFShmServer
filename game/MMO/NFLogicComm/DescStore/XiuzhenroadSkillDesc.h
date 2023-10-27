#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Xiuzhenroad_s.h"

#define MAX_XIUZHENROAD_SKILL_NUM 32

class XiuzhenroadSkillDesc : public NFIDescTemplate<XiuzhenroadSkillDesc, proto_ff_s::E_XiuzhenroadSkill_s, EOT_CONST_XIUZHENROAD_SKILL_DESC_ID, MAX_XIUZHENROAD_SKILL_NUM>
{
public:
	XiuzhenroadSkillDesc();
	virtual ~XiuzhenroadSkillDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
