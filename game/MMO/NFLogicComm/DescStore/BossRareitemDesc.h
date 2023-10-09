#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Boss_s.h"

#define MAX_BOSS_RAREITEM_NUM 1024

class BossRareitemDesc : public NFIDescStore
{
public:
	BossRareitemDesc();
	virtual ~BossRareitemDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_BossRareitem_s* GetDesc(int64_t id) const;
	proto_ff_s::E_BossRareitem_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_BossRareitem_s* GetDescByIndex(int index) const;
	proto_ff_s::E_BossRareitem_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(BossRareitemDesc, proto_ff_s::E_BossRareitem_s, E_BossRareitem, MAX_BOSS_RAREITEM_NUM);
DECLARE_IDCREATE(BossRareitemDesc);
};
