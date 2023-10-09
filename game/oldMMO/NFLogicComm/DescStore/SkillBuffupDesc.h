#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/skill_s.h"

#define MAX_SKILL_BUFFUP_NUM 60

class SkillBuffupDesc : public NFIDescStore
{
public:
	SkillBuffupDesc();
	virtual ~SkillBuffupDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_SkillBuffup_s* GetDesc(int64_t id) const;
	proto_ff_s::E_SkillBuffup_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_SkillBuffup_s* GetDescByIndex(int index) const;
	proto_ff_s::E_SkillBuffup_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(SkillBuffupDesc, proto_ff_s::E_SkillBuffup_s, E_SkillBuffup, MAX_SKILL_BUFFUP_NUM);
DECLARE_IDCREATE(SkillBuffupDesc);
};
