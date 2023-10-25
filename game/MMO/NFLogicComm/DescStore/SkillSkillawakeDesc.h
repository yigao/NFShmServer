#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Skill_s.h"

#define MAX_SKILL_SKILLAWAKE_NUM 128

class SkillSkillawakeDesc : public NFIDescStore
{
public:
	SkillSkillawakeDesc();
	virtual ~SkillSkillawakeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_SkillSkillawake_s* GetDesc(int64_t id) const;
	proto_ff_s::E_SkillSkillawake_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_SkillSkillawake_s* GetDescByIndex(int index) const;
	proto_ff_s::E_SkillSkillawake_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(SkillSkillawakeDesc, proto_ff_s::E_SkillSkillawake_s, E_SkillSkillawake, MAX_SKILL_SKILLAWAKE_NUM);
DECLARE_IDCREATE_GLOBAL(SkillSkillawakeDesc);
};
