#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_FUSION_NUM 32

class SoulFusionDesc : public NFIDescTemplate<SoulFusionDesc, proto_ff_s::E_SoulFusion_s, EOT_CONST_SOUL_FUSION_DESC_ID, MAX_SOUL_FUSION_NUM>
{
public:
	SoulFusionDesc();
	virtual ~SoulFusionDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
