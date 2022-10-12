#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/skill_s.h"

#define MAX_SKILL_BUFF_NUM 400

class SkillBuffDesc : public NFIDescStore
{
public:
	SkillBuffDesc(NFIPluginManager* pPluginManager);
	virtual ~SkillBuffDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::skillbuff_s* GetDesc(int id) const;
	proto_ff_s::skillbuff_s* GetDesc(int id);
	const NFShmHashMap<uint64_t, proto_ff_s::skillbuff_s, MAX_SKILL_BUFF_NUM>* GetAllDesc() const { return &m_astDesc; }
	NFShmHashMap<uint64_t, proto_ff_s::skillbuff_s, MAX_SKILL_BUFF_NUM>* GetAllDesc() { return &m_astDesc; }
public:
IMPL_RES_HASH_DESC(proto_ff_s::skillbuff_s, skillbuff, MAX_SKILL_BUFF_NUM);
DECLARE_IDCREATE(SkillBuffDesc);
};
