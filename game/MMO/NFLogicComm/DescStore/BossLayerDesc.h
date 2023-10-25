#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Boss_s.h"

#define MAX_BOSS_LAYER_NUM 64

class BossLayerDesc : public NFIDescStore
{
public:
	BossLayerDesc();
	virtual ~BossLayerDesc();
	int CreateInit();
	int ResumeInit();
public:
	const proto_ff_s::E_BossLayer_s* GetDesc(int64_t id) const;
	proto_ff_s::E_BossLayer_s* GetDesc(int64_t id);
	int GetDescIndex(int id) const;
	const proto_ff_s::E_BossLayer_s* GetDescByIndex(int index) const;
	proto_ff_s::E_BossLayer_s* GetDescByIndex(int index);
public:
private:
IMPL_RES_HASH_DESC(BossLayerDesc, proto_ff_s::E_BossLayer_s, E_BossLayer, MAX_BOSS_LAYER_NUM);
DECLARE_IDCREATE_GLOBAL(BossLayerDesc);
};
