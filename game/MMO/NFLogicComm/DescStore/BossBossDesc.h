#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Boss_s.h"

#define MAX_BOSS_BOSS_NUM 1024

class BossBossDesc : public NFIDescStore
{
public:
	BossBossDesc();
	virtual ~BossBossDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_BossBoss_s* GetDesc(int64_t id) const;
	proto_ff_s::E_BossBoss_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_BossBoss_s* GetDescByIndex(int index) const;
	proto_ff_s::E_BossBoss_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(BossBossDesc, proto_ff_s::E_BossBoss_s, E_BossBoss, MAX_BOSS_BOSS_NUM);
DECLARE_IDCREATE(BossBossDesc);
};
