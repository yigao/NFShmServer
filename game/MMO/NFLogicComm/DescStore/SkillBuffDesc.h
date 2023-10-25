#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Skill_s.h"

#define MAX_SKILL_BUFF_NUM 2048

class SkillBuffDesc : public NFIDescStore
{
public:
	SkillBuffDesc();
	virtual ~SkillBuffDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_SkillBuff_s* GetDesc(int64_t id) const;
	proto_ff_s::E_SkillBuff_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_SkillBuff_s* GetDescByIndex(int index) const;
	proto_ff_s::E_SkillBuff_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(SkillBuffDesc, proto_ff_s::E_SkillBuff_s, E_SkillBuff, MAX_SKILL_BUFF_NUM);
DECLARE_IDCREATE_GLOBAL(SkillBuffDesc);
};
