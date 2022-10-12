#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/skill_s.h"

#define MAX_SKILL_SKILL_NUM 2000

class SkillSkillDesc : public NFIDescStore
{
public:
	SkillSkillDesc(NFIPluginManager* pPluginManager);
	virtual ~SkillSkillDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::skillskill_s* GetDesc(int id) const;
	proto_ff_s::skillskill_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::skillskill_s, MAX_SKILL_SKILL_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::skillskill_s, MAX_SKILL_SKILL_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::skillskill_s, skillskill, MAX_SKILL_SKILL_NUM);
DECLARE_IDCREATE(SkillSkillDesc);
};
