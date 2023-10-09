#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Skill_s.h"

#define MAX_SKILL_SKILLADVANCE_NUM 128

class SkillSkilladvanceDesc : public NFIDescStore
{
public:
	SkillSkilladvanceDesc();
	virtual ~SkillSkilladvanceDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_SkillSkilladvance_s* GetDesc(int64_t id) const;
	proto_ff_s::E_SkillSkilladvance_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_SkillSkilladvance_s* GetDescByIndex(int index) const;
	proto_ff_s::E_SkillSkilladvance_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(SkillSkilladvanceDesc, proto_ff_s::E_SkillSkilladvance_s, E_SkillSkilladvance, MAX_SKILL_SKILLADVANCE_NUM);
DECLARE_IDCREATE(SkillSkilladvanceDesc);
};
