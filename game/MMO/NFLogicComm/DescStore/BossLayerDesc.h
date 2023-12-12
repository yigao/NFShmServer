#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Boss_s.h"

#define MAX_BOSS_LAYER_NUM 256

class BossLayerDesc : public NFIDescTemplate<BossLayerDesc, proto_ff_s::E_BossLayer_s, EOT_CONST_BOSS_LAYER_DESC_ID, MAX_BOSS_LAYER_NUM>
{
public:
	BossLayerDesc();
	virtual ~BossLayerDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
