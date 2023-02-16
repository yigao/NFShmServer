#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/skill_s.h"

#define MAX_SKILL_SKILLAWAKE_NUM 20

class SkillSkillawakeDesc : public NFIDescStore
{
public:
	SkillSkillawakeDesc();
	virtual ~SkillSkillawakeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_SkillSkillawake_s* GetDesc(int id) const;
	proto_ff_s::E_SkillSkillawake_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_SkillSkillawake_s, skillskillAwake, MAX_SKILL_SKILLAWAKE_NUM);
DECLARE_IDCREATE(SkillSkillawakeDesc);
};
