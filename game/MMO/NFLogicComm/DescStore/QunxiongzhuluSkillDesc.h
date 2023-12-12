#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Qunxiongzhulu_s.h"

#define MAX_QUNXIONGZHULU_SKILL_NUM 4

class QunxiongzhuluSkillDesc : public NFIDescTemplate<QunxiongzhuluSkillDesc, proto_ff_s::E_QunxiongzhuluSkill_s, EOT_CONST_QUNXIONGZHULU_SKILL_DESC_ID, MAX_QUNXIONGZHULU_SKILL_NUM>
{
public:
	QunxiongzhuluSkillDesc();
	virtual ~QunxiongzhuluSkillDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
