#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/skill_s.h"

#define MAX_SKILL_SKILLADVANCE_NUM 20

class SkillSkilladvanceDesc : public NFIDescStore
{
public:
	SkillSkilladvanceDesc();
	virtual ~SkillSkilladvanceDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_SkillSkilladvance_s* GetDesc(int id) const;
	proto_ff_s::E_SkillSkilladvance_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_SkillSkilladvance_s, E_SkillSkilladvance, MAX_SKILL_SKILLADVANCE_NUM);
DECLARE_IDCREATE(SkillSkilladvanceDesc);
};
