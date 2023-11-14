#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFServerLogicMessage/E_Soul_s.h"

#define MAX_SOUL_BONESKILL_NUM 32

class SoulBoneskillDesc : public NFIDescTemplate<SoulBoneskillDesc, proto_ff_s::E_SoulBoneskill_s, EOT_CONST_SOUL_BONESKILL_DESC_ID, MAX_SOUL_BONESKILL_NUM>
{
public:
	SoulBoneskillDesc();
	virtual ~SoulBoneskillDesc();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load(NFResDB *pDB) override;
	virtual int CheckWhenAllDataLoaded() override;
};
