#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/boss_s.h"

#define MAX_BOSS_BOSSTYPE_NUM 20

class BossBosstypeDesc : public NFIDescStore
{
public:
	BossBosstypeDesc();
	virtual ~BossBosstypeDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_BossBosstype_s* GetDesc(int64_t id) const;
	proto_ff_s::E_BossBosstype_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_BossBosstype_s* GetDescByIndex(int index) const;
	proto_ff_s::E_BossBosstype_s* GetDescByIndex(int index);
public:
IMPL_RES_HASH_DESC(BossBosstypeDesc, proto_ff_s::E_BossBosstype_s, E_BossBosstype, MAX_BOSS_BOSSTYPE_NUM);
DECLARE_IDCREATE(BossBosstypeDesc);
};
