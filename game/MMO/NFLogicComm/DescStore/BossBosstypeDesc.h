#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Boss_s.h"

#define MAX_BOSS_BOSSTYPE_NUM 16

class BossBosstypeDesc : public NFIDescStore
{
public:
	BossBosstypeDesc();
	virtual ~BossBosstypeDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_BossBosstype_s* GetDesc(int64_t id) const;
	proto_ff_s::E_BossBosstype_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_BossBosstype_s* GetDescByIndex(int index) const;
	proto_ff_s::E_BossBosstype_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(BossBosstypeDesc, proto_ff_s::E_BossBosstype_s, E_BossBosstype, MAX_BOSS_BOSSTYPE_NUM);
DECLARE_IDCREATE(BossBosstypeDesc);
};
