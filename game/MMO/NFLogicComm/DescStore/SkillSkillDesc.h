#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/skill_s.h"

#define MAX_SKILL_SKILL_NUM 180

class SkillSkillDesc : public NFIDescStore
{
public:
	SkillSkillDesc();
	virtual ~SkillSkillDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::skillskill_s* GetDesc(int id) const;
	proto_ff_s::skillskill_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::skillskill_s, skillskill, MAX_SKILL_SKILL_NUM);
DECLARE_IDCREATE(SkillSkillDesc);
};
