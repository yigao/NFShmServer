#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/skill_s.h"

#define MAX_SKILL_BUFF_NUM 200

class SkillBuffDesc : public NFIDescStore
{
public:
	SkillBuffDesc();
	virtual ~SkillBuffDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_SkillBuff_s* GetDesc(int64_t id) const;
	proto_ff_s::E_SkillBuff_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_SkillBuff_s* GetDescByIndex(int index) const;
	proto_ff_s::E_SkillBuff_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_SkillBuff_s, E_SkillBuff, MAX_SKILL_BUFF_NUM);
DECLARE_IDCREATE(SkillBuffDesc);
};
