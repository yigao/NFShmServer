#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/skill_s.h"

#define MAX_SKILL_BUFF_NUM 100

class SkillBuffDesc : public NFIDescStore
{
public:
	SkillBuffDesc();
	virtual ~SkillBuffDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::skillbuff_s* GetDesc(int id) const;
	proto_ff_s::skillbuff_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::skillbuff_s, skillbuff, MAX_SKILL_BUFF_NUM);
DECLARE_IDCREATE(SkillBuffDesc);
};
