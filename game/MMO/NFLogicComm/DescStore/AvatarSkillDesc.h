#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/avatar_s.h"

#define MAX_AVATAR_SKILL_NUM 20

class AvatarSkillDesc : public NFIDescStore
{
public:
	AvatarSkillDesc();
	virtual ~AvatarSkillDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_AvatarSkill_s* GetDesc(int64_t id) const;
	proto_ff_s::E_AvatarSkill_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_AvatarSkill_s* GetDescByIndex(int index) const;
	proto_ff_s::E_AvatarSkill_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_AvatarSkill_s, E_AvatarSkill, MAX_AVATAR_SKILL_NUM);
DECLARE_IDCREATE(AvatarSkillDesc);
};
