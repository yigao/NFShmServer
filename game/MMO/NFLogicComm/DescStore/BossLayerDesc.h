#pragma once

#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/boss_s.h"

#define MAX_BOSS_LAYER_NUM 20

class BossLayerDesc : public NFIDescStore
{
public:
	BossLayerDesc();
	virtual ~BossLayerDesc();
	int CreateInit();
	int ResumeInit();
	const proto_ff_s::bosslayer_s* GetDesc(int id) const;
	proto_ff_s::bosslayer_s* GetDesc(int id);
public:
IMPL_RES_HASH_DESC(proto_ff_s::bosslayer_s, bosslayer, MAX_BOSS_LAYER_NUM);
DECLARE_IDCREATE(BossLayerDesc);
};
