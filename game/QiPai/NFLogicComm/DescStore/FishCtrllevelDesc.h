#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Fish_s.h"

#define MAX_FISH_CTRLLEVEL_NUM 16

class FishCtrllevelDesc : public NFIDescTemplate<FishCtrllevelDesc, proto_ff_s::E_FishCtrllevel_s, EOT_CONST_FISH_CTRLLEVEL_DESC_ID, MAX_FISH_CTRLLEVEL_NUM>
{
public:
	FishCtrllevelDesc();
	virtual ~FishCtrllevelDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
