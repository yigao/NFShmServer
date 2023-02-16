#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/boss_s.h"

#define MAX_BOSS_BOSS_NUM 80

class BossBossDesc : public NFIDescStore
{
public:
	BossBossDesc();
	virtual ~BossBossDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::E_BossBoss_s* GetDesc(int id) const;
	proto_ff_s::E_BossBoss_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::E_BossBoss_s, E_BossBoss, MAX_BOSS_BOSS_NUM);
DECLARE_IDCREATE(BossBossDesc);
};
