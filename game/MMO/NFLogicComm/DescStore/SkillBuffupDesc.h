#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Skill_s.h"

#define MAX_SKILL_BUFFUP_NUM 512

class SkillBuffupDesc : public NFIDescStore
{
public:
	SkillBuffupDesc();
	virtual ~SkillBuffupDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_SkillBuffup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_SkillBuffup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_SkillBuffup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_SkillBuffup_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(SkillBuffupDesc, proto_ff_s::E_SkillBuffup_s, E_SkillBuffup, MAX_SKILL_BUFFUP_NUM);
DECLARE_IDCREATE(SkillBuffupDesc);
};
